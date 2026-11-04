/*
 * board_config.h - LITE-64 核心板板级配置
 *
 * 引脚依据 UM1008 Rev1.2 表 3-1 与硬件原理图 MCU.SchDoc：
 *   引脚 34 = PB14 = 用户 LED1
 *   电路：VDD -> R14(510R) -> LED1 阳极 -> 阴极 -> PB14，低电平点亮。
 */

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>

#include "ciu32l051_std.h"

/* 用户 LED1：PB14，低电平点亮 */
#define BOARD_LED_PORT          GPIOB
#define BOARD_LED_PIN           GPIO_PIN_14
#define BOARD_LED_LEVEL_ON      (0u)

/* 调度器节拍，必须与 SysTick 实际中断周期一致（firmware/SYSTEM/sys.c） */
#define BOARD_TICK_MS           (1u)

#endif /* BOARD_CONFIG_H */
