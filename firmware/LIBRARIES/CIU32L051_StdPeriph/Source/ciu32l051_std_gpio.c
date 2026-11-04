/************************************************************************************************/
/**
* @file               ciu32l051_std_gpio.c
* @author             MCU Ecosystem Development Team
* @brief              GPIO STD库驱动。
*                     实现GPIO初始化、去初始化等API。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @addtogroup GPIO
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_GPIO_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup GPIO_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  GPIO初始化
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  gpio_init_param GPIO初始化参数结构体
* @retval 无
*/
void std_gpio_init(GPIO_t* gpiox, std_gpio_init_t* gpio_init_param)
{
    uint32_t offset = 0;
    uint32_t current_pin = 0;

    /* 遍历配置GPIO引脚 */
    for (; ((gpio_init_param->pin) >> offset) != 0x00U; offset++)
    {
        /* 获取当前所遍历引脚 */
        current_pin = (gpio_init_param->pin) & (0x00000001UL << offset);

        if (current_pin != 0x00U)
        {
            /* 配置模式 */
            std_gpio_set_pin_mode(gpiox, current_pin, gpio_init_param->mode);

            /* 配置上下拉 */
            std_gpio_set_pin_pull(gpiox, current_pin, gpio_init_param->pull);

            if (gpio_init_param->mode == GPIO_MODE_ALTERNATE)
            {
                /* 配置复用功能 */
                if (current_pin < GPIO_PIN_8)
                {
                    /* 设置GPIO引脚（0~7）复用功能 */
                    std_gpio_set_afpin_0_7 (gpiox, current_pin, gpio_init_param->alternate);
                }
                else
                {
                    /* 设置GPIO引脚（8~15）复用功能 */
                    std_gpio_set_afpin_8_15(gpiox, current_pin, gpio_init_param->alternate);
                }
            }
        }
    }

    if ((gpio_init_param->mode == GPIO_MODE_OUTPUT) || (gpio_init_param->mode == GPIO_MODE_ALTERNATE))
    {
        /* 配置输出类型 */
        std_gpio_set_pin_output_type(gpiox, gpio_init_param->pin, gpio_init_param->output_type);
    }
}

/**
* @brief  GPIO去初始化
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin_mask GPIO引脚组合
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_ALL
* @retval 无
*/
void std_gpio_deinit(GPIO_t* gpiox, uint32_t pin_mask)
{
    uint32_t offset = 0;
    uint32_t current_pin = 0;

    /* 恢复寄存器值为默认值 */
    for (; ((pin_mask) >>offset) != 0x00000000U; offset++)
    {
        /* 获取当前所遍历引脚 */
        current_pin = (pin_mask) & (0x00000001U << offset);
        if (current_pin)
        {
            /* 配置模式 */
            std_gpio_set_pin_mode(gpiox, current_pin, GPIO_MODE_ANALOG);

            /* 配置上下拉 */
            std_gpio_set_pin_pull(gpiox, current_pin, GPIO_NOPULL);

            /* 配置复用功能 */
            if (current_pin < GPIO_PIN_8)
            {
                /* 设置GPIO引脚（0~7）复用功能 */
                std_gpio_set_afpin_0_7 (gpiox, current_pin, 0U);
            }
            else
            {
                /* 设置GPIO引脚（8~15）复用功能 */
                std_gpio_set_afpin_8_15(gpiox, current_pin, 0U);
            }
        }
    }
    
    /* 配置输出类型 */
    std_gpio_set_pin_output_type(gpiox, pin_mask, GPIO_OUTPUT_PUSHPULL);
}

/**
* @brief  GPIO初始化结构体初始化
* @param  gpio_init_struct GPIO初始化参数结构体
* @retval 无
*/
void std_gpio_struct_init(std_gpio_init_t* gpio_init_struct)
{
    gpio_init_struct->pin = GPIO_PIN_0;
    gpio_init_struct->mode = GPIO_MODE_ANALOG;
    gpio_init_struct->pull = GPIO_NOPULL;
    gpio_init_struct->output_type = GPIO_OUTPUT_PUSHPULL;
    gpio_init_struct->alternate = 0U;
}

/** 
* @} 
*/

#endif /* STD_GPIO_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
