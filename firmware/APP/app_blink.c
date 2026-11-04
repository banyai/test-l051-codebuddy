/*
 * app_blink.c - 闪灯应用
 *
 * LED 状态由系统时间直接换算，不做翻转累加：
 * 这样即使主循环偶发阻塞、调度器合并了若干次触发，亮灭相位也不会漂移。
 */

#include <stdbool.h>
#include <stdint.h>

#include "app_blink.h"
#include "led.h"
#include "sch.h"

/**
 * @brief  启动时同步 LED 初始状态
 */
void app_blink_init(void)
{
    led_write(false);
}

/**
 * @brief  周期任务：按已运行时间计算 LED 相位并刷新输出
 * @note   调度器以 SCH_MODE_COOP_COALESCE 方式注册，本函数只做状态刷新，
 *         不累加计数、不发报文、不写 Flash。
 */
void app_blink_task(void)
{
    bool on = ((sch_time_ms() / APP_BLINK_HALF_PERIOD_MS) & 1u) != 0u;

    led_write(on);
}
