/************************************************************************************************/
/**
* @file               ciu32l051_std_iwdg.h
* @author             MCU Ecosystem Development Team
* @brief              IWDG STD库驱动头文件。
*                     提供IWDG相关的STD库操作函数声明、数据类型以及常量的定义。 
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_IWDG_H
#define CIU32L051_STD_IWDG_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup IWDG IWDG
* @brief 独立看门狗的STD库驱动
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
* @defgroup IWDG_Constants IWDG Constants
* @brief IWDG常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* IWDG控制值定义 */
#define IWDG_RELOAD                      (0x0000AAAAUL)                 /**< IWDG 喂狗             */
#define IWDG_ENABLE                      (0x0000CCCCUL)                 /**< IWDG 使能             */
#define IWDG_WRITE_ACCESS_ENABLE         (0x00005555UL)                 /**< IWDG 写权限使能       */
#define IWDG_WRITE_ACCESS_DISABLE        (0x00000000UL)                 /**< IWDG 写权限关闭       */

/* IWDG计数溢出时间定义 */
#define IWDG_OVERFLOW_PERIOD_128         IWDG_CFG_OVP_128               /**< IWDG溢出时间为128ms   */
#define IWDG_OVERFLOW_PERIOD_256         IWDG_CFG_OVP_256               /**< IWDG溢出时间为256ms   */
#define IWDG_OVERFLOW_PERIOD_512         IWDG_CFG_OVP_512               /**< IWDG溢出时间为512ms   */
#define IWDG_OVERFLOW_PERIOD_1024        IWDG_CFG_OVP_1024              /**< IWDG溢出时间为1.024s  */
#define IWDG_OVERFLOW_PERIOD_2048        IWDG_CFG_OVP_2048              /**< IWDG溢出时间为2.048s  */
#define IWDG_OVERFLOW_PERIOD_4096        IWDG_CFG_OVP_4096              /**< IWDG溢出时间为4.096s  */
#define IWDG_OVERFLOW_PERIOD_8192        IWDG_CFG_OVP_8192              /**< IWDG溢出时间为8.192s  */
#define IWDG_OVERFLOW_PERIOD_16384       IWDG_CFG_OVP_16384             /**< IWDG溢出时间为16.384s */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup IWDG_External_Functions IWDG External Functions
* @brief    IWDG对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  启动IWDG计数
* @note   使能IWDG后,IWDG无法停止
* @retval 无
*/
__STATIC_INLINE void std_iwdg_start(void)
{
    IWDG->CR = IWDG_ENABLE;
}

/** 
* @brief  使能IWDG_CFG,IWDG_WINR寄存器写权限
* @retval 无
*/
__STATIC_INLINE void std_iwdg_write_access_enable(void)
{
    IWDG->CR = IWDG_WRITE_ACCESS_ENABLE;
}

/** 
* @brief  禁止IWDG_CFG、IWDG_WINR寄存器写权限
* @note   当写权限被禁止后，向IWDG_CFG、IWDG_WINR写入数据无效
* @retval 无
*/
__STATIC_INLINE void std_iwdg_write_access_disable(void)
{
    IWDG->CR = IWDG_WRITE_ACCESS_DISABLE;
}

/** 
* @brief  IWDG喂狗
* @retval 无
*/
__STATIC_INLINE void std_iwdg_refresh(void)
{
    IWDG->CR = IWDG_RELOAD;
}

/**
* @brief  配置溢出时间
* @param  overflow_period IWDG的溢出时间：
*             @arg IWDG_OVERFLOW_PERIOD_128
*             @arg IWDG_OVERFLOW_PERIOD_256
*             @arg IWDG_OVERFLOW_PERIOD_512
*             @arg IWDG_OVERFLOW_PERIOD_1024
*             @arg IWDG_OVERFLOW_PERIOD_2048
*             @arg IWDG_OVERFLOW_PERIOD_4096
*             @arg IWDG_OVERFLOW_PERIOD_8192
*             @arg IWDG_OVERFLOW_PERIOD_16384
* @retval 无
*/
__STATIC_INLINE void std_iwdg_set_overflow_period(uint32_t overflow_period)
{
    IWDG->CFG = overflow_period;
}

/**
* @brief  获取溢出时间
* @retval uint32_t IWDG的溢出时间：
*             @arg IWDG_OVERFLOW_PERIOD_128
*             @arg IWDG_OVERFLOW_PERIOD_256
*             @arg IWDG_OVERFLOW_PERIOD_512
*             @arg IWDG_OVERFLOW_PERIOD_1024
*             @arg IWDG_OVERFLOW_PERIOD_2048
*             @arg IWDG_OVERFLOW_PERIOD_4096
*             @arg IWDG_OVERFLOW_PERIOD_8192
*             @arg IWDG_OVERFLOW_PERIOD_16384
*/
__STATIC_INLINE uint32_t std_iwdg_get_overflow_period(void)
{
    return(IWDG->CFG);
}

/**
* @brief  配置窗口值
* @param  window IWDG的窗口值
* @retval 无
*/
__STATIC_INLINE void std_iwdg_set_window(uint32_t window)
{
    IWDG->WINR = window;
}

/**
* @brief  获取窗口值
* @retval uint32_t IWDG的窗口值
*/
__STATIC_INLINE uint32_t std_iwdg_get_window(void)
{
    return(IWDG->WINR);
}

/**
* @brief 获取计数值
* @retval uint32_t IWDG的计数值
*/
__STATIC_INLINE uint32_t std_iwdg_get_counter(void)
{
    return(IWDG->CNT);
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

#endif /* CIU32L051_STD_IWDG_H */
