/*
** CIU32L051 LITE-64 核心板 闪灯例程
** MCU: CIU32L051x8(64KB FLASH, 16KB RAM)
** 时钟: HCLK = 48MHz，PCLK1 = 48MHz，PCLK2 = 48MHz，嘀嗒 = 1ms(SysTick)
** 编译器: arm-none-eabi-gcc 14.3.1 (GNU Tools for STM32 14.3.rel1)
** 支持库: CIU32L051_STDLib V1.0.11
** 创建日期: 2026.11.4  V0.1
** 修改记录: 2026.11.4
*/

#include "app_blink.h"
#include "board_config.h"
#include "led.h"
#include "sch.h"
#include "sys.h"

_Static_assert(BOARD_TICK_MS == SCH_TICK_MS, "BOARD_TICK_MS 必须与 SCH_TICK_MS 一致");

static volatile uint32_t s_fault_code;

static void main_fault(uint32_t code);

/**
 * @brief  启动失败时的最终状态：LED 常亮并停在死循环
 * @param  code 失败原因编号，调试时可在 s_fault_code 观察
 * @note   该路径只在时钟或调度器初始化失败时进入，属异常分支。
 */
static void main_fault(uint32_t code)
{
    s_fault_code = code;

    led_write(true);

    for (;;) {
    }
}

/**
 * @brief  程序入口
 * @return 不返回
 */
int main(void)
{
    /* LED 先建立安全输出状态，再切换时钟 */
    led_init();

    if (sys_clock_init() != SYS_OK) {
        main_fault(1u);
    }

    if (sys_tick_init() != SYS_OK) {
        main_fault(2u);
    }

    if (sch_init(SCH_TICK_MS) != SCH_OK) {
        main_fault(3u);
    }

    app_blink_init();

    /* 周期任务集中注册在此处 */
    if (sch_add_task(app_blink_task, APP_BLINK_REFRESH_MS, APP_BLINK_REFRESH_MS,
                     SCH_MODE_COOP_COALESCE) < 0) {
        main_fault(4u);
    }

    for (;;) {
        sch_dispatch();
        sch_idle();
    }
}
