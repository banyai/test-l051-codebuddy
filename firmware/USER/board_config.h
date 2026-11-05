/*
 * board_config.h - LITE-64 核心板板级配置
 *
 * 引脚依据 UM1008 Rev1.2 表 3-1 与硬件原理图 MCU.SchDoc：
 *   引脚 34 = PB14 = 用户 LED1
 *   电路：VDD -> R14(510R) -> LED1 阳极 -> 阴极 -> PB14，低电平点亮。
 *   LCD 的 COM/SEG 引脚见下方 BOARD_LCD_* 定义。
 */

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>

#include "ciu32l051_std.h"

/* 用户 LED1：PB14，低电平点亮 */
#define BOARD_LED_PORT          GPIOB
#define BOARD_LED_PIN           GPIO_PIN_14
#define BOARD_LED_LEVEL_ON      (0u)

/*
 * 板载 LCD：YR1213C，4COM×8SEG、1/4 duty、1/3 bias、3.3V（UM1008 Rev1.2 §2.5）。
 * 引脚依据原理图 MCU.SchDoc、UM1008 表 3-1 与 SDK LCD_ChargePump_4COM/readme.txt，
 * 全部为 GPIO_MODE_ALTERNATE + GPIO_AF3_LCD、无上下拉、推挽；
 * 安全初态由 LCD 控制器 SCOC=GND 保证（firmware/HARDWARE/lcd.c）。
 * PB0/PB1/PB2/PF2 的 V1/V2/V3/VLCD 电容脚与 PD0/PD1 电荷泵脚由控制器内部连接，
 * 不配置为 GPIO；屏的 COM4~7 经 0Ω 电阻接 PA3~PA7/扩展口，1/4 duty 下不驱动，
 * 这些脚保持复位输入态；SEG8 未使用。
 */
#define BOARD_LCD_GPIO_CLK      (RCC_PERIPH_CLK_GPIOA | RCC_PERIPH_CLK_GPIOB | \
                                 RCC_PERIPH_CLK_GPIOC)
#define BOARD_LCD_AF            GPIO_AF3_LCD
#define BOARD_LCD_PORTA_PINS    (GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_15)
#define BOARD_LCD_PORTB_PINS    (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | \
                                 GPIO_PIN_7)
#define BOARD_LCD_PORTC_PINS    (GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11)

/* 调度器节拍，必须与 SysTick 实际中断周期一致（firmware/SYSTEM/sys.c） */
#define BOARD_TICK_MS           (1u)

#endif /* BOARD_CONFIG_H */
