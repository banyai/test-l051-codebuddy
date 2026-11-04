/*
 * sch.c - 时间触发调度器实现
 *
 * 与具体芯片无关：所有寄存器操作集中在 sch_port.h。
 * 时间参数单位为毫秒，内部换算成节拍。
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "sch.h"
#include "sch_port.h"

_Static_assert(SCH_TICK_MS > 0u, "SCH_TICK_MS must be greater than 0");
_Static_assert(SCH_MAX_TASKS > 0u, "SCH_MAX_TASKS must be greater than 0");
_Static_assert(SCH_MAX_TASKS <= 32767u, "SCH_MAX_TASKS too large for int16_t handle");

/* delay 取该值时表示任务已触发、等待执行，不再参与节拍递减 */
#define SCH_DELAY_FROZEN    (UINT32_MAX)

typedef struct {
    sch_task_fn fn;         /* NULL 表示该槽位空闲 */
    uint32_t    delay;      /* 距下次触发的剩余节拍 */
    uint32_t    period;     /* 周期节拍数，0 表示单次任务 */
    sch_mode_t  mode;
    uint8_t     runme;      /* 合作式任务的待执行次数 */
} sch_task_t;

static sch_task_t           s_tasks[SCH_MAX_TASKS];
static volatile uint32_t    s_time_ms;
static volatile uint32_t    s_ticks;
static volatile uint16_t    s_overrun;
static volatile uint16_t    s_merged;
static volatile uint8_t     s_initialized;


static uint32_t ms_to_ticks(uint32_t ms)
{
    const uint32_t tick = (uint32_t)SCH_TICK_MS;

    if (ms == 0u) {
        return 0u;
    }

    /* 防止 ms + tick - 1 上溢 */
    if (ms > (UINT32_MAX - tick)) {
        return UINT32_MAX / tick;
    }

    /* 向上取整：宁可晚一个节拍，不提前触发 */
    return (ms + tick - 1u) / tick;
}


sch_err_t sch_init(uint32_t tick_ms)
{
    uint32_t i = 0u;
    sch_irq_state_t irq = 0u;

    /* 让编译期配置和实际节拍在启动时就对齐，避免毫秒换算整体偏移 */
    if (tick_ms != (uint32_t)SCH_TICK_MS) {
        return SCH_ERR_PARAM;
    }

    irq = SCH_IRQ_SAVE();
    SCH_IRQ_DISABLE();

    for (i = 0u; i < (uint32_t)SCH_MAX_TASKS; i++) {
        s_tasks[i].fn     = NULL;
        s_tasks[i].delay  = 0u;
        s_tasks[i].period = 0u;
        s_tasks[i].mode   = SCH_MODE_COOP;
        s_tasks[i].runme  = 0u;
    }

    s_time_ms     = 0u;
    s_ticks       = 0u;
    s_overrun     = 0u;
    s_merged      = 0u;
    s_initialized = 1u;

    SCH_IRQ_RESTORE(irq);

    return SCH_OK;
}


int16_t sch_add_task(sch_task_fn fn, uint32_t delay_ms, uint32_t period_ms, sch_mode_t mode)
{
    uint32_t i = 0u;
    sch_irq_state_t irq = 0u;

    if (fn == NULL) {
        return (int16_t)SCH_ERR_PARAM;
    }

    if (mode != SCH_MODE_COOP && mode != SCH_MODE_ISR && mode != SCH_MODE_COOP_COALESCE) {
        return (int16_t)SCH_ERR_PARAM;
    }

    /* 抢占任务必须是周期任务：中断里无法安全地摘表和重入 */
    if (mode == SCH_MODE_ISR && period_ms == 0u) {
        return (int16_t)SCH_ERR_PARAM;
    }

    /* 合并只对周期任务有意义：单次任务本来就只跑一次，没有可合并的对象 */
    if (mode == SCH_MODE_COOP_COALESCE && period_ms == 0u) {
        return (int16_t)SCH_ERR_PARAM;
    }

    const uint32_t delay_ticks  = ms_to_ticks(delay_ms);
    const uint32_t period_ticks = ms_to_ticks(period_ms);

    irq = SCH_IRQ_SAVE();
    SCH_IRQ_DISABLE();

    for (i = 0u; i < (uint32_t)SCH_MAX_TASKS; i++) {
        if (s_tasks[i].fn == NULL) {
            break;
        }
    }

    if (i == (uint32_t)SCH_MAX_TASKS) {
        SCH_IRQ_RESTORE(irq);
        return (int16_t)SCH_ERR_FULL;
    }

    s_tasks[i].fn     = fn;
    s_tasks[i].delay  = delay_ticks;
    s_tasks[i].period = period_ticks;
    s_tasks[i].mode   = mode;
    s_tasks[i].runme  = 0u;

    SCH_IRQ_RESTORE(irq);

    return (int16_t)i;
}


sch_err_t sch_delete_task(uint8_t idx)
{
    sch_irq_state_t irq = 0u;

    if ((uint32_t)idx >= (uint32_t)SCH_MAX_TASKS) {
        return SCH_ERR_INDEX;
    }

    irq = SCH_IRQ_SAVE();
    SCH_IRQ_DISABLE();

    if (s_tasks[idx].fn == NULL) {
        SCH_IRQ_RESTORE(irq);
        return SCH_ERR_EMPTY;
    }

    s_tasks[idx].fn     = NULL;
    s_tasks[idx].delay  = 0u;
    s_tasks[idx].period = 0u;
    s_tasks[idx].mode   = SCH_MODE_COOP;
    s_tasks[idx].runme  = 0u;

    SCH_IRQ_RESTORE(irq);

    return SCH_OK;
}


void sch_update(void)
{
    uint32_t i = 0u;

    s_ticks++;
    s_time_ms += (uint32_t)SCH_TICK_MS;

    for (i = 0u; i < (uint32_t)SCH_MAX_TASKS; i++) {
        sch_task_t *task = &s_tasks[i];
        sch_task_fn fn = NULL;

        if (task->fn == NULL) {
            continue;
        }

        if (task->delay > 0u) {
            task->delay--;
            continue;
        }

        if (task->mode != SCH_MODE_ISR) {
            if (task->mode == SCH_MODE_COOP_COALESCE && task->runme > 0u) {
                /* 已挂起未执行：本次触发并入，仍然只跑一次，不补跑 */
                s_merged++;
            } else if (task->runme < UINT8_MAX) {
                task->runme++;
            } else {
                /* 主循环来不及执行：丢弃本次节拍并计数，不静默堆积 */
                s_overrun++;
            }

            if (task->period == 0u) {
                /* 单次任务：冻结，等 dispatch 执行时摘表 */
                task->delay = SCH_DELAY_FROZEN;
            } else {
                /* 从本次触发重新计时，错过的时间不再追补 */
                task->delay = task->period - 1u;
            }

            continue;
        }

        /* 抢占任务：先重装周期再执行，任务耗时不累积成周期漂移 */
        task->delay = task->period - 1u;
        fn = task->fn;

        if (fn != NULL) {
            fn();
        }
    }
}


void sch_dispatch(void)
{
    uint32_t i = 0u;

    /* 每轮只遍历一遍，积压留到下一轮，避免单个任务饿死其它服务 */
    for (i = 0u; i < (uint32_t)SCH_MAX_TASKS; i++) {
        sch_task_fn fn = NULL;
        sch_irq_state_t irq = SCH_IRQ_SAVE();

        SCH_IRQ_DISABLE();

        if (s_tasks[i].fn != NULL && s_tasks[i].mode != SCH_MODE_ISR && s_tasks[i].runme > 0u) {
            fn = s_tasks[i].fn;

            if (s_tasks[i].period == 0u) {
                /* 单次任务：先摘表再调用，任务内可安全重新注册 */
                s_tasks[i].fn     = NULL;
                s_tasks[i].delay  = 0u;
                s_tasks[i].period = 0u;
                s_tasks[i].runme  = 0u;
            } else {
                s_tasks[i].runme--;
            }
        }

        SCH_IRQ_RESTORE(irq);

        if (fn != NULL) {
            fn();
        }
    }
}


void sch_idle(void)
{
    SCH_IDLE();
}


uint32_t sch_time_ms(void)
{
    return s_time_ms;
}


uint32_t sch_tick_count(void)
{
    return s_ticks;
}


uint16_t sch_overrun_count(void)
{
    return s_overrun;
}


uint16_t sch_merged_count(void)
{
    return s_merged;
}
