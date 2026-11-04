/************************************************************************************************/
/**
* @file               ciu32l051_std_wwdg.h
* @author             MCU Ecosystem Development Team
* @brief              WWDG STD库驱动头文件。
*                     提供WWDG相关的STD库操作函数声明、数据类型以及常量的定义。 
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_WWDG_H
#define CIU32L051_STD_WWDG_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup WWDG WWDG
* @brief 窗口看门狗模块的STD库驱动
* @{
*
*/
/************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup WWDG_Constants WWDG Constants
* @brief WWDG常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* WWDG预分频寄存器定义 */
#define WWDG_PRESCALER_1                 WWDG_CFG_WDGPR_DIV1                  /**< WWDG计数器频率=(PCLK1/4096)/1   */
#define WWDG_PRESCALER_2                 WWDG_CFG_WDGPR_DIV2                  /**< WWDG计数器频率=(PCLK1/4096)/2   */
#define WWDG_PRESCALER_4                 WWDG_CFG_WDGPR_DIV4                  /**< WWDG计数器频率=(PCLK1/4096)/4   */
#define WWDG_PRESCALER_8                 WWDG_CFG_WDGPR_DIV8                  /**< WWDG计数器频率=(PCLK1/4096)/8   */
#define WWDG_PRESCALER_16                WWDG_CFG_WDGPR_DIV16                 /**< WWDG计数器频率=(PCLK1/4096)/16  */
#define WWDG_PRESCALER_32                WWDG_CFG_WDGPR_DIV32                 /**< WWDG计数器频率=(PCLK1/4096)/32  */
#define WWDG_PRESCALER_64                WWDG_CFG_WDGPR_DIV64                 /**< WWDG计数器频率=(PCLK1/4096)/64  */
#define WWDG_PRESCALER_128               WWDG_CFG_WDGPR_DIV128                /**< WWDG计数器频率=(PCLK1/4096)/128 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup WWDG_External_Functions WWDG External Functions
* @brief    WWDG对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  启动WWDG计数
* @retval 无
*/
__STATIC_INLINE void std_wwdg_start(void)
{
    WWDG->CR |= WWDG_CR_WDGEN;
}

/**
* @brief  配置计数值
* @param  counter WWDG的计数值，范围为：0x00-0x3F
* @retval 无
*/
__STATIC_INLINE void std_wwdg_refresh_counter(uint32_t counter)
{
    MODIFY_REG(WWDG->CR, WWDG_CR_CNT, counter);
}

/**
* @brief  获取计数值
* @retval uint32_t WWDG的计数值，范围为：0x00-0x3F
*/
__STATIC_INLINE uint32_t std_wwdg_get_counter(void)
{
    return(WWDG->CR & WWDG_CR_CNT);
}

/**
* @brief  配置预分频值
* @param  prescaler WWDG的预分频值：
*             @arg WWDG_PRESCALER_1
*             @arg WWDG_PRESCALER_2
*             @arg WWDG_PRESCALER_4
*             @arg WWDG_PRESCALER_8
*             @arg WWDG_PRESCALER_16
*             @arg WWDG_PRESCALER_32
*             @arg WWDG_PRESCALER_64
*             @arg WWDG_PRESCALER_128
* @retval 无
*/
__STATIC_INLINE void std_wwdg_set_prescaler(uint32_t prescaler)
{
    MODIFY_REG(WWDG->CFG, WWDG_CFG_WDGPR, prescaler);
}

/**
* @brief  获取预分频值
* @retval uint32_t WWDG的预分频值：
*             @arg WWDG_PRESCALER_1
*             @arg WWDG_PRESCALER_2
*             @arg WWDG_PRESCALER_4
*             @arg WWDG_PRESCALER_8
*             @arg WWDG_PRESCALER_16
*             @arg WWDG_PRESCALER_32
*             @arg WWDG_PRESCALER_64
*             @arg WWDG_PRESCALER_128
*/
__STATIC_INLINE uint32_t std_wwdg_get_prescaler(void)
{
    return(WWDG->CFG & WWDG_CFG_WDGPR);
}

/**
* @brief  配置窗口值
* @param  window WWDG的窗口值，范围为：0x00-0x3F
* @retval 无
*/
__STATIC_INLINE void std_wwdg_set_window(uint32_t window)
{
    MODIFY_REG(WWDG->CFG, WWDG_CFG_WIN, window);
}

/**
* @brief  获取窗口值
* @retval uint32_t WWDG的窗口值，范围为：0x00-0x3F
*/
__STATIC_INLINE uint32_t std_wwdg_get_window(void)
{
    return(WWDG->CFG & WWDG_CFG_WIN);
}

/**
* @brief  WWDG提前唤醒中断使能
* @retval 无
*/
__STATIC_INLINE void std_wwdg_interrupt_enable(void)
{
    WWDG->CFG |= WWDG_CFG_EWI;
}

/**
* @brief  获取WWDG的提前唤醒中断使能状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示使能提前唤醒中断
*             @arg false：表示未使能提前唤醒中断
*/
__STATIC_INLINE bool std_wwdg_get_interrupt_enable(void)
{
    return((WWDG->CFG & WWDG_CFG_EWI) == WWDG_CFG_EWI);
}

/**
* @brief  获取WWDG的提前唤醒标志状态
* @note   不使能EWI中断，此位也会被置1
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示提前唤醒标志被置起
*             @arg false：表示提前唤醒标志未置起
*/
__STATIC_INLINE bool std_wwdg_get_early_wakeup_flag(void)
{
    return(WWDG->SR == WWDG_SR_EWIF);
}

/**
* @brief  清除WWDG提前唤醒标志
* @retval 无
*/
__STATIC_INLINE void std_wwdg_clear_early_wakeup_flag(void)
{
    WWDG->SR &= (~ WWDG_SR_EWIF);
}

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

#endif /* CIU32L051_STD_WWDG_H */
