/*
 * ciu32l051_it.c - 中断服务入口
 *
 * ISR 函数名必须与 firmware/STARTUP/startup_ciu32l051.s 向量表一致。
 */

#include "sch.h"

/**
 * @brief  SysTick 中断，周期 BOARD_TICK_MS
 * @note   只推进调度器节拍，不在此处做业务处理。
 */
void SysTick_Handler(void)
{
    sch_update();
}
