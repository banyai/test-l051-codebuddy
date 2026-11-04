/*
 * led.c - 用户 LED 驱动（PB14，低电平点亮）
 */

#include <stdbool.h>

#include "board_config.h"
#include "led.h"

/**
 * @brief  初始化用户 LED
 * @note   先使能 GPIOB 时钟并写入熄灭电平，再切换为输出模式，
 *         避免配置过程中出现一次误点亮。
 */
void led_init(void)
{
    std_gpio_init_t led_param = {0};

    std_rcc_gpio_clk_enable(RCC_PERIPH_CLK_GPIOB);

    /* 输出寄存器先置为熄灭电平（高电平） */
    std_gpio_set_pin(BOARD_LED_PORT, BOARD_LED_PIN);

    led_param.pin         = BOARD_LED_PIN;
    led_param.mode        = GPIO_MODE_OUTPUT;
    led_param.pull        = GPIO_NOPULL;
    led_param.output_type = GPIO_OUTPUT_PUSHPULL;

    std_gpio_init(BOARD_LED_PORT, &led_param);
}

/**
 * @brief  设置 LED 亮灭
 * @param  on true 点亮，false 熄灭；低电平点亮，故逻辑与电平相反
 */
void led_write(bool on)
{
    if (on) {
        std_gpio_reset_pin(BOARD_LED_PORT, BOARD_LED_PIN);
    } else {
        std_gpio_set_pin(BOARD_LED_PORT, BOARD_LED_PIN);
    }
}

/**
 * @brief  翻转 LED 输出电平
 */
void led_toggle(void)
{
    std_gpio_toggle_pin(BOARD_LED_PORT, BOARD_LED_PIN);
}
