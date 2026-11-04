/************************************************************************************************/
/**
* @file               ciu32l051_std_dbg.h
* @author             MCU Ecosystem Development Team
* @brief              DBG STD库驱动头文件。
*                     提供DBG相关的STD库操作函数声明、数据类型以及常量的定义。                         
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_DBG_H
#define CIU32L051_STD_DBG_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup DBG DBG
* @brief 调试接口的STD库驱动
* @{
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
* @defgroup DBG_Constants DBG Constants 
* @brief  DBG常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* 外设的计数控制选择 */
#define DBG_PERIPH_TIM3                DBG_APB1_FZ_DBG_TIM3_HOLD                /**< TIM3   计数控制位 */
#define DBG_PERIPH_TIM4                DBG_APB1_FZ_DBG_TIM4_HOLD                /**< TIM4   计数控制位 */
#define DBG_PERIPH_TIM5                DBG_APB1_FZ_DBG_TIM5_HOLD                /**< TIM5   计数控制位 */
#define DBG_PERIPH_TIM8                DBG_APB1_FZ_DBG_TIM8_HOLD                /**< TIM8   计数控制位 */
#define DBG_PERIPH_RTC                 DBG_APB1_FZ_DBG_RTC_HOLD                 /**< RTC    计数控制位 */
#define DBG_PERIPH_WWDG                DBG_APB1_FZ_DBG_WWDG_HOLD                /**< WWDG   计数控制位 */
#define DBG_PERIPH_IWDG                DBG_APB1_FZ_DBG_IWDG_HOLD                /**< IWDG   计数控制位 */
#define DBG_PERIPH_LPTIM1              DBG_APB1_FZ_DBG_LPTIM1_HOLD              /**< LPTIM1 计数控制位 */
#define DBG_PERIPH_LPTIM2              DBG_APB1_FZ_DBG_LPTIM2_HOLD              /**< LPTIM2 计数控制位 */

/**
* @}
*/

/*------------------------------------functions-------------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup DBG_External_Functions DBG External Functions
* @brief    DBG对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  使能Stop模式调试功能
* @note   只能通过POR复位
* @retval 无
*/
__STATIC_INLINE void std_dbg_stop_enable(void)
{
    DBG->CR |= DBG_CR_DBG_STOP;
}

/**
* @brief  禁止Stop模式调试功能
* @note   只能通过POR复位
* @retval 无
*/
__STATIC_INLINE void std_dbg_stop_disable(void)
{
    DBG->CR &= (~DBG_CR_DBG_STOP);
}

/**
* @brief  内核停止时停止计数
* @param  periph_hold 指定停止的计数控制
*             @arg DBG_PERIPH_TIM3
*             @arg DBG_PERIPH_TIM4
*             @arg DBG_PERIPH_TIM5
*             @arg DBG_PERIPH_TIM8
*             @arg DBG_PERIPH_RTC
*             @arg DBG_PERIPH_WWDG
*             @arg DBG_PERIPH_IWDG
*             @arg DBG_PERIPH_LPTIM1
*             @arg DBG_PERIPH_LPTIM2
* @note   只能通过POR复位
* @retval 无
*/
__STATIC_INLINE void std_dbg_apb1_hold_enable(uint32_t periph_hold)
{
    DBG->APB1_FZ |= periph_hold;
}

/**
* @brief  内核停止时正常计数
* @param  periph_hold 指定正常的计数控制
*             @arg DBG_PERIPH_TIM3
*             @arg DBG_PERIPH_TIM4
*             @arg DBG_PERIPH_TIM5
*             @arg DBG_PERIPH_TIM8
*             @arg DBG_PERIPH_RTC
*             @arg DBG_PERIPH_WWDG
*             @arg DBG_PERIPH_IWDG
*             @arg DBG_PERIPH_LPTIM1
*             @arg DBG_PERIPH_LPTIM2
* @note   只能通过POR复位
* @retval 无
*/
__STATIC_INLINE void std_dbg_apb1_hold_disable(uint32_t periph_hold)
{
    DBG->APB1_FZ &= (~periph_hold);
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
#endif /* CIU32L051_STD_DBG_H */
