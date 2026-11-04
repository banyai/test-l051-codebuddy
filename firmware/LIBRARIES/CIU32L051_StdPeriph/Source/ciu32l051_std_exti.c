/************************************************************************************************/
/**
* @file               ciu32l051_std_exti.c
* @author             MCU Ecosystem Development Team
* @brief              EXTI STD库驱动
*                     实现了EXTI模块的信号线初始化、去初始化等API。
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
* @addtogroup EXTI 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_EXTI_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup EXTI_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  EXTI初始化
* @param  exti_init_param EXTI初始化参数结构体
* @retval 无
*/
void std_exti_init(std_exti_init_t* exti_init_param)
{
    uint32_t trigger;
    uint32_t exti_mode;

    /* 配置GPIO EXTI通道 */
    if ((exti_init_param->line_id & EXTI_GPIO) != 0x00U)
    {
        trigger = exti_init_param->trigger & EXTI_TRIGGER_MASK;

        /* 禁止EXTI通道上升沿/下降沿触发 */
        std_exti_falling_trigger_disable(exti_init_param->line_id);
        std_exti_rising_trigger_disable (exti_init_param->line_id);

        /* 使能EXTI通道上升沿触发 */
        if ((trigger & EXTI_TRIGGER_RISING) == EXTI_TRIGGER_RISING)
        {
            std_exti_rising_trigger_enable (exti_init_param->line_id);
        }

        /* 使能EXTI通道下降沿触发 */
        if ((trigger & EXTI_TRIGGER_FALLING) == EXTI_TRIGGER_FALLING)
        {
            std_exti_falling_trigger_enable(exti_init_param->line_id);
        }

        /* 设置EXTI通道所对应GPIO端口 */
        if ((exti_init_param->line_id & EXTI_GPIO) == EXTI_GPIO)
        {
            std_exti_set_gpio(exti_init_param->gpio_id, exti_init_param->line_id);
        }
    }

    /* 配置EXTI通道中断/事件唤醒 */
    exti_mode = exti_init_param->mode & EXTI_MODE_INTERRUPT_EVENT;

    /* 禁止EXTI通道中断/事件唤醒 */
    std_exti_interrupt_disable(exti_init_param->line_id);
    std_exti_event_disable(exti_init_param->line_id);

    /* 使能EXTI通道中断唤醒 */
    if ((exti_mode & EXTI_MODE_INTERRUPT) == EXTI_MODE_INTERRUPT)
    {
        std_exti_interrupt_enable(exti_init_param->line_id);
    }

    /* 使能EXTI通道事件唤醒 */
    if ((exti_mode & EXTI_MODE_EVENT) == EXTI_MODE_EVENT)
    {
        std_exti_event_enable (exti_init_param->line_id);
    }
}


/**
* @brief  EXTI去初始化
* @retval 无
*/
void std_exti_deinit(void)
{
    EXTI->RTSR = 0x00000000U;
    EXTI->FTSR = 0x00000000U;
    EXTI->PIR = 0x3FFFFU;
    EXTI->EXTICR[0] = 0x00000000U;
    EXTI->EXTICR[1] = 0x00000000U;
    EXTI->IMR = 0xEFC00000U;
    EXTI->EMR = 0x00000000U;
}

/**
* @brief  EXTI初始化结构体初始化
* @param  exti_init_struct EXTI初始化参数结构体
* @retval 无
*/
void std_exti_struct_init(std_exti_init_t* exti_init_struct)
{
    exti_init_struct->line_id = EXTI_LINE_GPIO_PIN0;
    exti_init_struct->mode = EXTI_MODE_NONE;
    exti_init_struct->trigger = EXTI_TRIGGER_NONE;
    exti_init_struct->gpio_id = EXTI_GPIOA;
}

/** 
* @} 
*/

#endif /* STD_EXTI_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
