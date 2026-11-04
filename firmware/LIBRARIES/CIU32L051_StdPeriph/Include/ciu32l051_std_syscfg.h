/************************************************************************************************/
/**
* @file               ciu32l051_std_syscfg.h
* @author             MCU Ecosystem Development Team
* @brief              SYSCFG STD库驱动头文件。
*                     提供SYSCFG相关的STD库操作函数声明、数据类型以及常量的定义。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_SYSCFG_H
#define CIU32L051_STD_SYSCFG_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup SYSCFG SYSCFG
* @brief 系统配置控制器的STD库驱动 
* @{
*
*/
/************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------includes--------------------------------------------------*/
#include "ciu32l051_std_common.h"

/*-------------------------------------define---------------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup SYSCFG_Constants SYSCFG Constants
* @brief SYSCFG常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* IRTIM调制信号选择 */
#define SYSCFG_IRMODE_TIM5_OC1                               SYSCFG_CR_IR_MODE_TIM5_OC1       /**< 调制信号源于TIM5_OC1  */
#define SYSCFG_IRMODE_USART1_TX                              SYSCFG_CR_IR_MODE_USART1_TX      /**< 调制信号源于USART1_TX */
#define SYSCFG_IRMODE_UART4_TX                               SYSCFG_CR_IR_MODE_UART4_TX       /**< 调制信号源于UART4_TX  */

/* IR_OUT输出信号极性选择 */
#define SYSCFG_IRPOLARITY_DIRECT                             (0x00000000U)                    /**< IRTIM 输出信号未反相  */
#define SYSCFG_IRPOLARITY_INVERSE                            SYSCFG_CR_IR_POL                 /**< IRTIM 输出信号反相    */

/* 存储器映射选择位 */
#define SYSCFG_MEM_MODE_USER_FLASH                           SYSCFG_CR_MEM_MODE_USER_FLASH    /**< 将User flash映射到地址0x0000 0000    */
#define SYSCFG_MEM_MODE_SYS_MEM                              SYSCFG_CR_MEM_MODE_SYS_MEM       /**< 将System memory映射到地址0x0000 0000 */
#define SYSCFG_MEM_MODE_SRAM                                 SYSCFG_CR_MEM_MODE_SRAM          /**< 将SRAM映射到地址0x0000 0000          */

/* 6bit DAC输入参考电压源 */
#define SYSCFG_6BIT_DAC_VREFBUF                              (0x00000000U)                    /**< 选择VREFBUF作为输入电压源            */
#define SYSCFG_6BIT_DAC_VREFP                                (0x00000000U)                    /**< 选择VREF+引脚输入作为输入电压源      */
#define SYSCFG_6BIT_DAC_VDDA                                 SYSCFG_CR_6BIT_DAC_REF           /**< 选择内部VDDA电压作为输入电压源       */

/* 6bit DAC输出稳定时间 */
#define SYSCFG_6BIT_DAC_EN_DELAY                             (16U)                            /**<  6bit DAC输出稳定时间                */

/* PVD锁定控制位 */
#define SYSCFG_PVD_LOCK_ENABLE                               SYSCFG_SECCR_PVD_LOCK            /**< 写保护锁定PMU_CR2寄存器              */

/** 
* @}
*/

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup SYSCFG_External_Functions SYSCFG External Functions
* @brief    SYSCFG对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  配置IRTIM调制信号源
* @param  ir_source 调制信号源选择
*             @arg SYSCFG_IRMODE_TIM5_OC1： 调制信号源为TIM5的0C1
*             @arg SYSCFG_IRMODE_USART1_TX：调制信号源为USART1
*             @arg SYSCFG_IRMODE_UART4_TX： 调制信号源为UART4
* @retval 无
*/
__STATIC_INLINE void std_syscfg_set_ir_signal_source(uint32_t ir_source)
{
    MODIFY_REG(SYSCFG->CR, SYSCFG_CR_IR_MODE, ir_source);
}

/**
* @brief  获取IRTIM调制信号源
* @retval uint32_t 调制信号源
*             @arg SYSCFG_IRMODE_TIM5_OC1： 调制信号源为TIM5的0C1
*             @arg SYSCFG_IRMODE_USART1_TX：调制信号源为USART1
*             @arg SYSCFG_IRMODE_UART4_TX： 调制信号源为UART4
*/
__STATIC_INLINE uint32_t std_syscfg_get_ir_signal_source(void)
{
    return(SYSCFG->CR & SYSCFG_CR_IR_MODE);
}

/**
* @brief  IR_OUT输出信号极性选择
* @param  irpolarity 输出信号极性
*             @arg SYSCFG_IRPOLARITY_DIRECT:  输出信号未反相
*             @arg SYSCFG_IRPOLARITY_INVERSE: 输出信号反相
* @retval 无
*/
__STATIC_INLINE void std_syscfg_set_ir_polarity(uint32_t irpolarity)
{
    MODIFY_REG(SYSCFG->CR, SYSCFG_CR_IR_POL, irpolarity);
}

/**
* @brief  获取IR_OUT输出信号极性状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示IRTIM输出信号反相
*             @arg false：表示IRTIM输出信号未相反
*/
__STATIC_INLINE bool std_syscfg_get_ir_polarity(void)
{
    return((SYSCFG->CR & SYSCFG_CR_IR_POL) == SYSCFG_CR_IR_POL);
}

/** 
* @brief  配置存储器映射
* @param  memory_mapping 存储器映射选择
*             @arg SYSCFG_MEM_MODE_USER_FLASH：存储器映射到USER FLASH
*             @arg SYSCFG_MEM_MODE_SYS_MEM：存储器映射到SYSTEM MEMORY
*             @arg SYSCFG_MEM_MODE_SRAM：存储器映射到SRAM
* @retval 无
*/
__STATIC_INLINE void std_syscfg_set_memory_mapping(uint32_t memory_mapping)
{
    MODIFY_REG(SYSCFG->CR, SYSCFG_CR_MEM_MODE, memory_mapping);
}

/**
* @brief  获取存储器映射
* @retval uint32_t 存储器映射选择
*             @arg SYSCFG_MEM_MODE_USER_FLASH：存储器映射到USER FLASH
*             @arg SYSCFG_MEM_MODE_SYS_MEM：存储器映射到SYSTEM MEMORY
*             @arg SYSCFG_MEM_MODE_SRAM：存储器映射到SRAM
*/
__STATIC_INLINE uint32_t std_syscfg_get_memory_mapping(void)
{
    return(SYSCFG->CR & SYSCFG_CR_MEM_MODE);
}

/**
* @brief  使能6bit DAC
* @retval 无
*/
__STATIC_INLINE void std_syscfg_6bit_dac_enable(void)
{
    SYSCFG->CR |= SYSCFG_CR_6BIT_DAC_EN;
}

/**
* @brief  禁止6bit DAC
* @retval 无
*/
__STATIC_INLINE void std_syscfg_6bit_dac_disable(void)
{
    SYSCFG->CR &= (~SYSCFG_CR_6BIT_DAC_EN);
}

/**
* @brief  获取6bit DAC使能状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示使能6bit DAC
*             @arg false：表示未使能6bit DAC
*/
__STATIC_INLINE bool std_syscfg_get_6bit_dac_enable(void)
{
    return((SYSCFG->CR & SYSCFG_CR_6BIT_DAC_EN) == SYSCFG_CR_6BIT_DAC_EN);
}

/**
* @brief  配置6bit DAC输入参考电压源分压
* @param  divide_voltage 输入参考电压源分压，范围为：0x00-0x3F
* @retval 无
*/
__STATIC_INLINE void std_syscfg_set_6bit_dac_divide_voltage (uint32_t divide_voltage)
{
    MODIFY_REG(SYSCFG->CR, SYSCFG_CR_6BIT_DAC_DIV, divide_voltage << SYSCFG_CR_6BIT_DAC_DIV_POS);
}

/**
* @brief  获取6bit DAC输入参考电压源分压
* @retval uint32_t 输入参考电压源分压，范围为：0x00-0x3F
*/
__STATIC_INLINE uint32_t std_syscfg_get_6bit_dac_divide_voltage (void)
{
    return((SYSCFG->CR & SYSCFG_CR_6BIT_DAC_DIV) >> SYSCFG_CR_6BIT_DAC_DIV_POS);
}

/**
* @brief  配置6bit DAC输入参考电压源
* @param  source 输入参考电压源选择
*             @arg SYSCFG_6BIT_DAC_VREFBUF: 选择VREFBUF作为输入电压源
*             @arg SYSCFG_6BIT_DAC_VREFP: 选择VREF+引脚输入作为输入电压源
*             @arg SYSCFG_6BIT_DAC_VDDA: 选择VDDA电压
* @retval 无
*/
__STATIC_INLINE void std_syscfg_set_6bit_dac_reference_voltage(uint32_t source)
{
    MODIFY_REG(SYSCFG->CR, SYSCFG_CR_6BIT_DAC_REF, source);
}

/**
* @brief  获取6bit DAC输入参考电压源
* @retval uint32_t 输入参考电压源选择
*             @arg SYSCFG_6BIT_DAC_VREFBUF: 选择VREFBUF作为输入电压源
*             @arg SYSCFG_6BIT_DAC_VREFP: 选择VREF+引脚输入作为输入电压源
*             @arg SYSCFG_6BIT_DAC_VDDA: 选择VDDA电压
*/
__STATIC_INLINE uint32_t std_syscfg_get_6bit_dac_reference_voltage(void)
{
    return(SYSCFG->CR & SYSCFG_CR_6BIT_DAC_REF);
}

/**
* @brief  使能PVD锁定
* @retval 无
*/
__STATIC_INLINE void std_syscfg_pvd_lock_enable(void)
{
    SYSCFG->SECCR |= SYSCFG_SECCR_PVD_LOCK;
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

#endif /* CIU32L051_STD_SYSCFG_H */
