/************************************************************************************************/
/**
* @file               ciu32l051_std_trng.h  
* @author             MCU Ecosystem Development Team
* @brief              TRNG STD库驱动头文件。
*                     提供TRNG相关的STD库操作函数声明、数据类型以及常量的定义。 
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_TRNG_H
#define CIU32L051_STD_TRNG_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/** 
* @defgroup TRNG TRNG
* @brief 随机数发生器的STD库驱动
* @{
*/
/************************************************************************************************/

#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------includes--------------------------------------------------*/
#include "ciu32l051_std_common.h"

/*------------------------------------define----------------------------------------------------*/

/************************************************************************************************/
/** 
* @defgroup TRNG_Constants TRNG Constants
* @brief TRNG常量定义及宏定义
* @{
*/
/************************************************************************************************/

/* 随机数生成类型选择 */
#define TRNG_TRUE_RANDOM                    TRNG_CR1_TYPE_SEL_TRUE                 /**< 真随机数 */
#define TRNG_PSEUDO_RANDOM                  TRNG_CR1_TYPE_SEL_PSEUDO               /**< 伪随机数 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup TRNG_External_Functions TRNG External Functions
* @brief    TRNG对外函数
* @{
*/
/************************************************************************************************/
/**
* @brief  配置随机数生成类型
* @param  mode 随机数生成类型
*             @arg TRNG_TRUE_RANDOM：  真随机数
*             @arg TRNG_PSEUDO_RANDOM: 伪随机数
* @retval 无
*/
__STATIC_INLINE void std_trng_set_mode(uint32_t mode)
{
    MODIFY_REG(TRNG->CR1, TRNG_CR1_TYPE_SEL, mode);
}

/**
* @brief  获取TRNG生成完成标志状态
* @retval bool 返回TRNG生成完成标志状态
*             @arg true： 标志为置起状态
*             @arg false：标志为清除状态
*/
__STATIC_INLINE bool std_trng_get_flag_ready(void)
{
    return ((TRNG ->SR & TRNG_SR_RDY) == TRNG_SR_RDY);
}

/**
* @brief  使能TRNG中断
* @retval 无
*/
__STATIC_INLINE void std_trng_interrupt_enable(void)
{ 
   TRNG->CR1 |= TRNG_CR1_RDYIE;
}

/**
* @brief  禁止TRNG中断
* @retval 无
*/
__STATIC_INLINE void std_trng_interrupt_disable(void)
{
    TRNG->CR1 &= (~TRNG_CR1_RDYIE);
}

/**
* @brief  读取TRNG中断使能状态
* @retval bool TRNG中断使能状态
*             @arg true  表示中断已使能
*             @arg false 表示中断未使能
*/
__STATIC_INLINE bool std_trng_get_interrupt_enable(void)
{
    return ((TRNG->CR1 & TRNG_CR1_RDYIE) == TRNG_CR1_RDYIE);
}

/**
* @brief  读取32位随机数
* @retval uint32_t 32位随机数
*/
__STATIC_INLINE uint32_t std_trng_read_data(void)
{
    return (TRNG->DR);
}

void std_trng_deinit(void);
std_status_t std_trng_get_random_number(uint32_t *rng_data32);

/**
* @}
*/

#ifdef __cplusplus
}
#endif

/**
* @}
*/

/**
* @}
*/

#endif /* CIU32L051_STD_TRNG_H */
