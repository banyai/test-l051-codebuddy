/*
 * sch.h - 时间触发调度器（裸机，无 OS）
 *
 * 三种模式：
 *   SCH_MODE_COOP           合作式，只在主循环 sch_dispatch() 里执行，可长可短
 *                           错过的周期会累积，dispatch 逐次补跑（计数、收包、Flash 记录）
 *   SCH_MODE_COOP_COALESCE  合作式合并，只在主循环执行；错过的多个周期只跑一次
 *                           不补跑，用于"状态刷新"类任务（显示、LED、状态上报）
 *   SCH_MODE_ISR            抢占式，直接在嘀嗒中断里执行，只允许极短任务
 *
 * 补跑与合并的区别（period 10ms，主循环被阻塞 35ms）：
 *   COOP       → 补跑 3 次（每次都要跑，一个周期都不能少）
 *   COALESCE   → 只跑 1 次（只关心"现在是什么状态"，中间过程无意义）
 *
 * 使用要点：
 *   1. 嘀嗒中断周期必须等于 SCH_TICK_MS，且中断里只调 sch_update()，不要加别的事
 *   2. 时间参数一律用毫秒，内部按 tick 向上取整（12ms 在 5ms 节拍下实际 15ms）
 *   3. 抢占任务禁止阻塞、禁止写 Flash、禁止等待外设，最坏执行时间须记入 irq-map.md
 *   4. 各任务起始时刻尽量错开，避免多个任务落在同一节拍
 *   5. 主循环空闲时调 sch_idle() 进 WFI，不要自己写空转
 *   6. 会写 Flash、发报文、累计计数这类"一次都不能漏"的任务必须用 COOP，
 *      不能图省事用 COALESCE，否则阻塞一次就丢数据
 *
 * 使用示例：
 *   void SysTick_Handler(void)
 *   {
 *       sch_update();
 *   }
 *
 *   int main(void)
 *   {
 *       board_init();
 *       (void)sch_init(SCH_TICK_MS);
 *
 *       (void)sch_add_task(task_loop_rx,  0u,   2u, SCH_MODE_COOP);
 *       (void)sch_add_task(task_buzzer,   1u,  10u, SCH_MODE_COOP);
 *       (void)sch_add_task(task_display,  2u,  50u, SCH_MODE_COOP_COALESCE);
 *       (void)sch_add_task(task_snapshot, 3u, 100u, SCH_MODE_ISR);
 *
 *       for (;;) {
 *           sch_dispatch();
 *           sch_idle();
 *       }
 *   }
 */

#ifndef SCH_H
#define SCH_H

#include <stdint.h>
#include <stdbool.h>

/* 编译期配置，可在 CMake 里用 -D 覆盖，也可在 sch_config.h 里改 */
#ifndef SCH_MAX_TASKS
#define SCH_MAX_TASKS       12u
#endif

#ifndef SCH_TICK_MS
#define SCH_TICK_MS         5u
#endif

/* 版本号：母本（references/sch_firmware）与工程内副本（src/common/sch）据此核对
 * 行为有任何改动都必须更新这里，复制进工程后禁止手改本段 */
#define SCH_VERSION_MAJOR   1
#define SCH_VERSION_MINOR   1
#define SCH_VERSION_PATCH   0
#define SCH_VERSION_STRING  "1.1.0"

/* 任务模式 */
typedef enum {
    SCH_MODE_COOP = 0,              /* 合作式：主循环调度，错过的周期逐次补跑 */
    SCH_MODE_ISR  = 1,              /* 抢占式：嘀嗒中断内执行 */
    SCH_MODE_COOP_COALESCE = 2,     /* 合作式合并：主循环调度，错过的周期只跑一次 */
} sch_mode_t;

/* 错误码：负值为错误，sch_add_task 的非负返回值是任务句柄 */
typedef enum {
    SCH_OK          =  0,
    SCH_ERR_PARAM   = -1,   /* 参数非法，或 tick 配置与实际不一致 */
    SCH_ERR_FULL    = -2,   /* 任务表已满 */
    SCH_ERR_INDEX   = -3,   /* 句柄越界 */
    SCH_ERR_EMPTY   = -4,   /* 该位置没有任务 */
} sch_err_t;

typedef void (*sch_task_fn)(void);

/* 初始化并校验嘀嗒周期；tick_ms 必须等于 SCH_TICK_MS，否则返回 SCH_ERR_PARAM */
sch_err_t sch_init(uint32_t tick_ms);

/* 注册任务，成功返回句柄（>= 0），失败返回负的错误码
 * COOP_COALESCE 只对周期任务有意义，period_ms 为 0 时返回 SCH_ERR_PARAM */
int16_t sch_add_task(sch_task_fn fn, uint32_t delay_ms, uint32_t period_ms, sch_mode_t mode);

/* 删除任务，句柄来自 sch_add_task 的返回值 */
sch_err_t sch_delete_task(uint8_t idx);

/* 嘀嗒中断内调用，唯一允许放进 tick ISR 的调度器函数 */
void sch_update(void);

/* 主循环内调用，执行所有到期的合作式任务 */
void sch_dispatch(void);

/* 主循环空闲时调用，进低功耗等待 */
void sch_idle(void);

/* 系统运行毫秒数，ISR 写主循环读，32 位对齐访问在 Cortex-M 上原子 */
uint32_t sch_time_ms(void);

/* 累计节拍数，用于超时判断时避免毫秒乘法溢出 */
uint32_t sch_tick_count(void);

/* 合作式任务积压次数，非 0 说明主循环负载过重或某个任务超时 */
uint16_t sch_overrun_count(void);

/* 合并模式被丢弃的触发次数，非 0 说明该任务周期相对主循环负载偏短 */
uint16_t sch_merged_count(void);

#endif /* SCH_H */
