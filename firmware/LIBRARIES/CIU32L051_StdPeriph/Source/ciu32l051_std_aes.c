/************************************************************************************************/
/**
* @file               ciu32l051_std_aes.c
* @author             MCU Ecosystem Development Team
* @brief              AES STD库驱动。
*                     实现AES初始化配置等功能API。
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
* @addtogroup AES
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_AES_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup AES_External_Functions 
* @{
*
*/
/************************************************************************************************/
/**
* @brief  AES初始化
* @param  aes_init_param AES的配置信息
* @retval 无
*/
void std_aes_init(std_aes_init_t *aes_init_param)
{
    /* 初始化加解密模式、数据交换类型 */
    MODIFY_REG(AES->CR, (AES_CR_MOD_SEL | AES_CR_DATA_TYPE), 
              (aes_init_param->mode | aes_init_param->swapped_data_type));
}

/**
* @brief  AES去初始化
* @retval 无
*/
void std_aes_deinit(void)
{
    /* 复位AES */
    std_rcc_ahb_reset(RCC_PERIPH_RESET_AES);
    
    /* 关闭AES时钟 */
    std_rcc_ahb_clk_disable(RCC_PERIPH_CLK_AES);
}

/**
* @brief  设置AES结构体为默认值
* @param  aes_init_struct AES的配置信息
* @retval 无
*/
void std_aes_struct_init(std_aes_init_t *aes_init_struct)
{
    /* 初始化解密模式、无数据交换，支持的输入输出数据为小端模式 */
    aes_init_struct->mode = AES_MODE_ENC;
    aes_init_struct->swapped_data_type = AES_SWAPPED_DATA_NONE;
}

/**
* @}
*/

#endif /* STD_AES_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
