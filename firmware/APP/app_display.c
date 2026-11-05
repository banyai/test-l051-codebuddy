/*
 * app_display.c - 板载段码液晶显示应用
 *
 * 显示内容由 sch_time_ms() 直接换算成运行秒数，不在任务里累加计数：
 * 调度器以 SCH_MODE_COOP_COALESCE 合并触发时也不会丢计数或漂移相位。
 */

#include <stdbool.h>
#include <stdint.h>

#include "app_display.h"
#include "lcd.h"
#include "sch.h"

#define APP_DISPLAY_MS_PER_SECOND (1000u)
#define APP_DISPLAY_VALUE_LIMIT  (10000u) /* 4 位七段屏的显示容量 */

static uint32_t s_start_ms;  /* 电荷泵开始建立的时刻 */
static bool s_output_on;     /* 波形输出是否已开放 */

/**
 * @brief  启动时同步显示状态
 * @note   lcd_init() 已把 RAM 清零；这里写入上电画面 "0000"，
 *         并记录起始时间供 LCD_STABLE_MS 稳定等待使用。
 */
void app_display_init(void)
{
    s_start_ms = sch_time_ms();
    s_output_on = false;
    if (lcd_display_text("0000") != LCD_OK) {
        lcd_clear(); /* 恒定有效的参数，此分支只作防御：清成全灭安全态 */
    }
}

/**
 * @brief  周期任务：开放波形输出后刷新运行秒数
 * @note   合并任务只做状态刷新；启动后的一次性 LCD_STABLE_MS 等待是电荷泵硬件时序，
 *         不是另建一套周期相位。无符号毫秒差值在 32 位回绕后仍正确。
 *         显示失败时清成全灭安全态，不静默保留错误画面。
 */
void app_display_task(void)
{
    uint32_t elapsed_ms = sch_time_ms() - s_start_ms;

    if (!s_output_on) {
        if (elapsed_ms >= LCD_STABLE_MS) {
            lcd_start_output();
            s_output_on = true;
        }
        return;
    }
    if (lcd_display_number((elapsed_ms / APP_DISPLAY_MS_PER_SECOND) % APP_DISPLAY_VALUE_LIMIT)
        != LCD_OK) {
        lcd_clear();
    }
}
