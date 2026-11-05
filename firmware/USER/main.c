/*
** CIU32L051 LITE-64 核心板 闪灯 + LCD 显示例程
** MCU: CIU32L051x8(64KB FLASH, 16KB RAM)
** 时钟: HCLK = 48MHz，PCLK1 = 48MHz，PCLK2 = 48MHz，嘀嗒 = 1ms(SysTick)
** 显示: 片内 LCD 控制器 = 板载 YR1213C 4COM×8SEG（电荷泵，时钟源 LXTAL）
** 编译器: arm-none-eabi-gcc 14.3.1 (GNU Tools for STM32 14.3.rel1)
** 支持库: CIU32L051_STDLib V1.0.11
** 创建日期: 2026.11.4  V0.1
** 修改记录: 2026.11.5 增加板载 LCD 显示
*/

#include "app_blink.h"
#include "app_display.h"
#include "board_config.h"
#include "lcd.h"
#include "led.h"
#include "sch.h"
#include "sys.h"

_Static_assert(BOARD_TICK_MS == SCH_TICK_MS, "BOARD_TICK_MS 必须与 SCH_TICK_MS 一致");

static volatile uint32_t s_fault_code;

static void main_fault(uint32_t code);

/**
 * @brief  启动失败时的最终状态：LED 常亮并停在死循环
 * @param  code 失败原因编号，调试时可在 s_fault_code 观察
 * @note   1=时钟、2=SysTick、3=调度器、4=闪灯任务、5=LCD 时钟、6=显示任务。
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

    /* LCD 起振超时判断依赖 SysTick 毫秒时间，故放在调度器初始化之后 */
    if (lcd_init() != LCD_OK) {
        main_fault(5u);
    }

    app_blink_init();
    app_display_init();

    /* 周期任务集中注册在此处 */
    if (sch_add_task(app_blink_task, APP_BLINK_REFRESH_MS, APP_BLINK_REFRESH_MS,
                     SCH_MODE_COOP_COALESCE) < 0) {
        main_fault(4u);
    }
    if (sch_add_task(app_display_task, APP_DISPLAY_REFRESH_MS, APP_DISPLAY_REFRESH_MS,
                     SCH_MODE_COOP_COALESCE) < 0) {
        main_fault(6u);
    }

    for (;;) {
        sch_dispatch();
        sch_idle();
    }
}
