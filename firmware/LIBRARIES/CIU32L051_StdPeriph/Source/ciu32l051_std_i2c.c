/************************************************************************************************/
/**
* @file               ciu32l051_std_i2c.c
* @author             MCU Ecosystem Development Team
* @brief              I2C STD库驱动。
*                     实现I2C初始化等API。
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
* @addtogroup I2C
* @{
*
*/
/************************************************************************************************/



/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_I2C_PERIPHERAL_USED
/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup I2C_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  I2C初始化函数
* @param  i2cx I2C外设
* @param  i2c_init_param I2C初始化结构体指针
* @retval 无
*/
void std_i2c_init(I2C_t *i2cx, std_i2c_init_t *i2c_init_param)
{
    /* I2C时钟配置寄存器配置 */
    std_i2c_set_timing(i2cx, i2c_init_param->timing);
    
    /* 配置I2C设备地址1 */
    std_i2c_device_address1_disable(i2cx);
    std_i2c_device_address1_config(i2cx, i2c_init_param->address1_length, i2c_init_param->address1);
    std_i2c_device_address1_enable(i2cx);
    
    /* 数字滤波器配置 */
    std_i2c_digital_filter_config(i2cx, i2c_init_param->digital_filter);
    
    /* 配置I2C从模式下的应答方式 */
    std_i2c_set_next_data_ack(i2cx, i2c_init_param->acknowledge_type);
    
    /* 使能I2C接口 */
    std_i2c_enable(i2cx);
}

/**
* @brief  I2C去初始化函数
* @param  i2cx I2C外设
* @retval 无
*/
void std_i2c_deinit(I2C_t *i2cx)
{
    /* I2C复位，并关闭I2C的时钟 */
    std_rcc_apb1_reset(RCC_PERIPH_RESET_I2C1);
    std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_I2C1);
}

/**
* @brief  I2C初始化结构体初始化
* @param  i2c_init_struct I2C初始化结构体指针
* @retval 无
*/
void std_i2c_struct_init(std_i2c_init_t *i2c_init_struct)
{
    i2c_init_struct->timing = 0U;
    i2c_init_struct->digital_filter = I2C_DIGITALFILTER_DISABLE;
    i2c_init_struct->address1_length = I2C_ADDRESS1MODE_7BIT;
    i2c_init_struct->address1 = 0U;
    i2c_init_struct->acknowledge_type = I2C_DATA_NACK;
}


/** 
* @} 
*/

#endif /* STD_I2C_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
