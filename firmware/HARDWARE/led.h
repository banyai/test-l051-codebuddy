/*
 * led.h - 用户 LED 驱动
 */

#ifndef LED_H
#define LED_H

#include <stdbool.h>

/* 配置 LED 引脚为推挽输出，初始为熄灭状态 */
void led_init(void);

/* 点亮 / 熄灭，入参超出 0/1 时按亮处理 */
void led_write(bool on);

/* 翻转当前输出电平 */
void led_toggle(void);

#endif /* LED_H */
