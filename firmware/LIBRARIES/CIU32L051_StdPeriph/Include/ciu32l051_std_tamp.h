/************************************************************************************************/
/**
* @file               ciu32l051_std_tamp.h
* @author             MCU Ecosystem Development Team
* @brief              TAMP STD库驱动头文件。
*                     提供TAMP相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_TAMP_H
#define CIU32L051_STD_TAMP_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup TAMP TAMP
* @brief 入侵检测和备份寄存器的STD库驱动
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
* @defgroup TAMP_Constants TAMP Constants 
* @brief  TAMP常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* TAMP入侵检测源 */        
#define TAMP_SOURCE_TAMP_IN                       TAMP_ENR_TAMPEN                        /**< 外部入侵检测（外部引脚）  */

/* 外部入侵检测触发方式 */  
#define TAMP_TRIGGER_RISING_EDGE                  (0x00000000U)                          /**< 上升沿触发 */                                   
#define TAMP_TRIGGER_FALLING_EDGE                 (0x00000001U)                          /**< 下降沿触发 */ 
#define TAMP_TRIGGER_LOW_LEVEL                    TAMP_TRIGGER_RISING_EDGE               /**< 低电平触发 */ 
#define TAMP_TRIGGER_HIGH_LEVEL                   TAMP_TRIGGER_FALLING_EDGE              /**< 高电平触发 */ 

/* 外部入侵检测的数字滤波配置 */        
#define TAMP_FILTER_DISABLE                       (0x00000000U)                          /**< 数字滤波关闭，采用边沿触发 */
#define TAMP_FILTER_2SAMPLE                       TAMP_FLTCR_2SAMPLE                     /**< 连续采样2个有效电平后触发  */
#define TAMP_FILTER_4SAMPLE                       TAMP_FLTCR_4SAMPLE                     /**< 连续采样4个有效电平后触发  */
#define TAMP_FILTER_8SAMPLE                       TAMP_FLTCR_8SAMPLE                     /**< 连续采样8个有效电平后触发  */

/* TAMP入侵检测中断使能控制 */ 
#define TAMP_INTERRUPT_TAMP_IN                    TAMP_IER_TAMPIE                        /**< 外部入侵检测（外部引脚）中断使能      */

/* 入侵检测标志 */
#define TAMP_FLAG_TAMP_IN                         TAMP_SR_TAMPF                          /**< 外部入侵检测（外部引脚）的标志        */

/* TAMP入侵检测中断状态标志 */ 
#define TAMP_INTERRUPT_FLAG_TAMP_IN               TAMP_ISR_TAMPIF                        /**< 外部入侵检测（外部引脚）中断状态标志  */

/* 清除入侵检测标志 */
#define TAMP_CLEAR_FLAG_TAMP_IN                   TAMP_CLR_CTAMPF                        /**< 清除外部入侵检测（外部引脚）的标志    */


/* 备份寄存器数量 */
#define TAMP_BACKUP_NUMBER                        (0x00000005U)

/* 备份寄存器编号 */
#define TAMP_BACKUP_DR0                           (TAMP->BKP0R)
#define TAMP_BACKUP_DR1                           (TAMP->BKP1R)
#define TAMP_BACKUP_DR2                           (TAMP->BKP2R)
#define TAMP_BACKUP_DR3                           (TAMP->BKP3R)
#define TAMP_BACKUP_DR4                           (TAMP->BKP4R)

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup TAMP_External_Functions TAMP External Functions
* @brief    TAMP对外函数
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  使能入侵检测
* @param  source 入侵检测源
*             @arg TAMP_SOURCE_TAMP_IN
* @retval 无
*/
__STATIC_INLINE void std_tamp_enable(uint32_t source)
{
    TAMP->ENR |= source;
}

/** 
* @brief  禁止入侵检测
* @param  source 入侵检测源
*             @arg TAMP_SOURCE_TAMP_IN
* @retval 无
*/
__STATIC_INLINE void std_tamp_disable(uint32_t source)
{
    TAMP->ENR &= (~source);
}

/** 
* @brief  读取入侵检测源
* @param  source 入侵检测源
*             @arg TAMP_SOURCE_TAMP_IN
* @retval uint32_t 入侵检测源使能情况
*             @arg TAMP_SOURCE_TAMP_IN  外部入侵检测已使能
*/
__STATIC_INLINE bool std_tamp_get_source(uint32_t source)
{
    return (TAMP->ENR & source);
}

/** 
* @brief  使能入侵检测引脚上拉电阻
* @retval 无
*/
__STATIC_INLINE void std_tamp_pullup_enable(void)
{
    TAMP->FLTCR |= TAMP_FLTCR_TAMPPUEN;
}

/** 
* @brief  禁止入侵检测引脚上拉电阻
* @retval 无
*/
__STATIC_INLINE void std_tamp_pullup_disable(void)
{
    TAMP->FLTCR &= (~TAMP_FLTCR_TAMPPUEN);
}

/** 
* @brief  设置入侵检测触发方式
* @param  trigger 触发方式
*             @arg TAMP_TRIGGER_RISING_EDGE
*             @arg TAMP_TRIGGER_FALLING_EDGE
*             @arg TAMP_TRIGGER_LOW_LEVEL
*             @arg TAMP_TRIGGER_HIGH_LEVEL
* @note   当滤波参数为0时，  入侵检测将采用边沿检测模式
*         当滤波参数不为0时，入侵检测将采用电平检测模式
* @retval 无
*/
__STATIC_INLINE void std_tamp_set_trigger(uint32_t trigger)
{
    MODIFY_REG(TAMP->CR, TAMP_CR_TAMPTRIG, (trigger << TAMP_CR_TAMPTRIG_POS));
}

/** 
* @brief  设置入侵检测数字滤波参数
* @param  filter 入侵检测数字滤波参数
*             @arg TAMP_FILTER_DISABLE
*             @arg TAMP_FILTER_2SAMPLE
*             @arg TAMP_FILTER_4SAMPLE
*             @arg TAMP_FILTER_8SAMPLE
* @note   当滤波参数为0时，  入侵检测将采用边沿检测模式
*         当滤波参数不为0时，入侵检测将采用电平检测模式
* @retval 无
*/
__STATIC_INLINE void std_tamp_set_filter(uint32_t filter)
{
    MODIFY_REG(TAMP->FLTCR, TAMP_FLTCR_TAMPFLT, filter);
}

/** 
* @brief  使能备份寄存器擦除
* @retval 无
*/
__STATIC_INLINE void std_tamp_bkp_erase_enable(void)
{
    TAMP->CR &= (~TAMP_CR_TAMPNOER);
}

/** 
* @brief  禁止备份寄存器擦除
* @retval 无
*/
__STATIC_INLINE void std_tamp_bkp_erase_disable(void)
{
    TAMP->CR |= TAMP_CR_TAMPNOER;
}

/** 
* @brief  使能入侵检测中断
* @param  tamp_interrupt 入侵检测源中断
*             @arg TAMP_INTERRUPT_TAMP_IN
* @retval 无
*/
__STATIC_INLINE void std_tamp_interrupt_enable(uint32_t tamp_interrupt)
{
    TAMP->IER |= tamp_interrupt;
}

/** 
* @brief  禁止入侵检测中断
* @param  tamp_interrupt 入侵检测源中断
*             @arg TAMP_INTERRUPT_TAMP_IN
* @retval 无
*/
__STATIC_INLINE void std_tamp_interrupt_disable(uint32_t tamp_interrupt)
{
    TAMP->IER &= (~tamp_interrupt);
}

/** 
* @brief  读取入侵检测中断使能状态
* @param  tamp_interrupt 入侵检测源中断
*             @arg TAMP_INTERRUPT_TAMP_IN
* @retval bool 入侵检测中断使能状态
*             @arg true  表示中断已使能
*             @arg false 表示中断未使能
*/
__STATIC_INLINE bool std_tamp_get_interrupt_enable(uint32_t tamp_interrupt)
{
    return ((TAMP->IER & tamp_interrupt) == tamp_interrupt);
}

/** 
* @brief  读取入侵检测标志状态
* @param  tamp_flag 入侵检测标志
*             @arg TAMP_FLAG_TAMP_IN
* @retval bool 入侵检测标志状态
*             @arg true  表示入侵检测已发生
*             @arg false 表示入侵检测未发生
*/
__STATIC_INLINE uint32_t std_tamp_get_flag(uint32_t tamp_flag)
{
    return ((TAMP->SR & tamp_flag) == tamp_flag);
}

/** 
* @brief  清除入侵检测标志状态
* @param  tamp_flag 入侵检测标志
*             @arg TAMP_CLEAR_FLAG_IN_TAMP
* @retval 无
*/
__STATIC_INLINE void std_tamp_clear_flag(uint32_t tamp_flag)
{
    TAMP->CLR = tamp_flag;
}

/** 
* @brief  读取入侵检测中断状态
* @param  interrupt_flag 入侵检测源中断标志
*             @arg TAMP_INTERRUPT_FLAG_TAMP_IN
* @retval bool 入侵检测中断状态
*             @arg true  表示中断已发生
*             @arg false 表示中断未发生
*/
__STATIC_INLINE bool std_tamp_get_interrupt_flag(uint32_t interrupt_flag)
{
    return ((TAMP->ISR & interrupt_flag) == interrupt_flag);
}

void std_tamp_deinit(void);

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

#endif /* CIU32L051_STD_TAMP_H */


