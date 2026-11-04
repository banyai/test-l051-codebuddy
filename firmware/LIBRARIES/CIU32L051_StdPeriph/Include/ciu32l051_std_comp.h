/************************************************************************************************/
/**
* @file               ciu32l051_std_comp.h
* @author             MCU Ecosystem Development Team
* @brief              COMP STD库驱动头文件。
*                     提供COMP相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_COMP_H
#define CIU32L051_STD_COMP_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup COMP COMP
* @brief 比较器的STD库驱动
* @{
*/
/************************************************************************************************/

#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"

/*-----------------------------------------type define------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup COMP_Types  COMP Types 
* @brief    COMP数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  COMP参数配置结构体定义
*/
typedef struct
{
    uint32_t inpsel;             /**< COMP正相输入                   
                                          @arg COMP_INPSEL_IO1 ... */

    uint32_t inmsel;             /**< COMP反相输入                   
                                          @arg COMP_INMSEL_VBGR ... */ 

    uint32_t speed;              /**< COMP响应速度，响应速度越快，功耗越大。可设置为超低速、低速、中速、高速四种模式。
                                          @arg COMP_VERYLOWSPEED ... */

    uint32_t hyst;               /**< COMP迟滞模式，可以禁止迟滞，或者设置迟滞电压为10mV、20mV、30mV。
                                          @arg COMP_HYST_NONE ... */

    uint32_t outpol;             /**< COMP输出极性，可设置输出状态”反相”。
                                          @arg COMP_OUTPOL_INVERTED ... */
} std_comp_init_t;

/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup COMP_Constants COMP Constants 
* @brief  COMP常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* 比较器正相输入 */
#define COMP_INPSEL_IO1                   COMP_CSR_INP_IO1            /**< 正相输入 COMP1 = PC4, COMP2 = PA1 */
#define COMP_INPSEL_IO2                   COMP_CSR_INP_IO2            /**< 正相输入 COMP1 = PA5, COMP2 = PD5 */
#define COMP_INPSEL_IO3                   COMP_CSR_INP_IO3            /**< 正相输入 COMP1 = PB2              */
#define COMP_INPSEL_IO4                   COMP_CSR_INP_IO4            /**< 正相输入 COMP1 = PA8              */

/* 比较器反相输入 */
#define COMP_INMSEL_VBGR                  COMP_CSR_INM_VBGR           /**< 反相输入 VBGR                     */
#define COMP_INMSEL_6BIT_DAC              COMP_CSR_INM_6BIT_DAC       /**< 反相输入 6BIT_DAC                 */                      
#define COMP_INMSEL_IO1                   COMP_CSR_INM_IO1            /**< 反相输入 COMP1 = PC3, COMP2 = PA2 */
#define COMP_INMSEL_IO2                   COMP_CSR_INM_IO2            /**< 反相输入 COMP1 = PA4, COMP2 = PD4 */
#define COMP_INMSEL_IO3                   COMP_CSR_INM_IO3            /**< 反相输入 COMP1 = PB1              */
#define COMP_INMSEL_IO4                   COMP_CSR_INM_IO4            /**< 反相输入 COMP1 = PA9              */

/* 比较器正相输入模式选择，可用于选择窗口比较器功能 */
#define COMP_INPMODE_EACH_INPUT           (0x00000000U)               /**< 正相输入各自独立，由各自inpsel决定 */
#define COMP_INPMODE_COMMON_INPUT         COMP_CSR_INPMOD             /**< 正相输入相互连接，即窗口比较器模式 */

/* 比较器响应速度 */
#define COMP_VERYLOWSPEED                 COMP_CSR_VERY_LOW_SPEED     /**< 响应速度模式 超低速 */
#define COMP_LOWSPEED                     COMP_CSR_LOW_SPEED          /**< 响应速度模式 低速   */
#define COMP_MEDIUMSPEED                  COMP_CSR_MEDIUM_SPEED       /**< 响应速度模式 中速   */
#define COMP_HIGHSPEED                    COMP_CSR_HIGH_SPEED         /**< 响应速度模式 高速   */

/* 比较器迟滞模式 */
#define COMP_HYST_NONE                    COMP_CSR_HYST_NONE          /**< 迟滞模式：无迟滞 */
#define COMP_HYST_LOW                     COMP_CSR_HYST_LOW           /**< 迟滞模式：10mV   */
#define COMP_HYST_MEDIUM                  COMP_CSR_HYST_MEDIUM        /**< 迟滞模式：20mV   */
#define COMP_HYST_HIGH                    COMP_CSR_HYST_HIGH          /**< 迟滞模式：30mV   */

/* 比较器滤波使能 */
#define COMP_FILTER_DISABLE               (0x00000000U)               /**< 比较器滤波禁止 */
#define COMP_FILTER_ENABLE                COMP_CSR_FLTEN              /**< 比较器滤波使能 */

/* 比较器滤波时间 */
#define COMP_FLTIME_2CYCLE                COMP_CSR_FLTIME_2CYCLE      /**< 滤波时间 2个CYCLE   */
#define COMP_FLTIME_4CYCLE                COMP_CSR_FLTIME_4CYCLE      /**< 滤波时间 4个CYCLE   */
#define COMP_FLTIME_8CYCLE                COMP_CSR_FLTIME_8CYCLE      /**< 滤波时间 8个CYCLE   */
#define COMP_FLTIME_16CYCLE               COMP_CSR_FLTIME_16CYCLE     /**< 滤波时间 16个CYCLE  */
#define COMP_FLTIME_32CYCLE               COMP_CSR_FLTIME_32CYCLE     /**< 滤波时间 32个CYCLE  */
#define COMP_FLTIME_64CYCLE               COMP_CSR_FLTIME_64CYCLE     /**< 滤波时间 64个CYCLE  */
#define COMP_FLTIME_128CYCLE              COMP_CSR_FLTIME_128CYCLE    /**< 滤波时间 128个CYCLE */
#define COMP_FLTIME_256CYCLE              COMP_CSR_FLTIME_256CYCLE    /**< 滤波时间 256个CYCLE */

/* 比较器输出极性 */
#define COMP_OUTPOL_NON_INVERTED          (0x00000000U)               /**< 输出状态不反相 */
#define COMP_OUTPOL_INVERTED              COMP_CSR_POL                /**< 输出状态反相   */

/* 比较器输出选择 */
#define COMP_OUTMODE_EACH_OUT             (0x00000000U)               /**< 输出为其原始电压比较结果         */
#define COMP_OUTMODE_COMMON_XOR_OUT       COMP_CSR_OUTMOD             /**< 输出为比较器1、2电压比较结果异或 */

/* 比较器输出结果 */
#define COMP_OUTPUT_LEVEL_LOW             (0x00000000UL)              /**< 比较器输出电平低 */
#define COMP_OUTPUT_LEVEL_HIGH            (0x00000001UL)              /**< 比较器输出电平高 */

/* 等待COMP1使能启动时间 
   响应速度模式为高  速  使能启动时间23US
   响应速度模式为中  速  使能启动时间24US
   响应速度模式为低  速  使能启动时间30US
   响应速度模式为超低速  使能启动时间39US
*/
#define COMP_EN_DELAY                     (30U)                       /**< COMP使能启动时间 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup COMP_External_Functions COMP External Functions
* @brief    COMP对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  使能COMP
* @param  compx COMP外设
* @retval 无
*/
__STATIC_INLINE void std_comp_enable(COMP_t *compx)
{
    compx->CSR |= (COMP_CSR_EN);
}

/** 
* @brief  禁止COMP
* @param  compx COMP外设
* @retval 无
*/
__STATIC_INLINE void std_comp_disable(COMP_t *compx)
{
    compx->CSR &= (~COMP_CSR_EN);
}

/** 
* @brief  设置COMP反相输入
* @param  compx COMP外设
* @param  input_minus 反相输入选择
*             @arg COMP_INMSEL_VBGR
*             @arg COMP_INMSEL_6BIT_DAC
*             @arg COMP_INMSEL_IO1
*             @arg COMP_INMSEL_IO2
*             @arg COMP_INMSEL_IO3
*             @arg COMP_INMSEL_IO4
* @retval 无
*/
__STATIC_INLINE void std_comp_set_input_minus(COMP_t *compx, uint32_t input_minus)
{
    MODIFY_REG(compx->CSR, COMP_CSR_INM, input_minus);
}

/** 
* @brief  获取COMP反相输入
* @param  compx COMP外设
* @retval uint32_t 返回反相输入
*             @arg COMP_INMSEL_VBGR
*             @arg COMP_INMSEL_6BIT_DAC
*             @arg COMP_INMSEL_IO1
*             @arg COMP_INMSEL_IO2
*             @arg COMP_INMSEL_IO3
*             @arg COMP_INMSEL_IO4
*/
__STATIC_INLINE uint32_t std_comp_get_input_minus(COMP_t *compx)
{
    return(compx->CSR & COMP_CSR_INM);
}

/** 
* @brief  设置COMP正相输入
* @param  compx COMP外设
* @param  input_plus 正相输入选择
*             @arg COMP_INPSEL_IO1
*             @arg COMP_INPSEL_IO2
*             @arg COMP_INPSEL_IO3
*             @arg COMP_INPSEL_IO4
* @retval 无
*/
__STATIC_INLINE void std_comp_set_input_plus(COMP_t *compx, uint32_t input_plus)
{
    MODIFY_REG(compx->CSR, COMP_CSR_INP, input_plus);
}

/** 
* @brief  获取COMP正相输入
* @param  compx COMP外设
* @retval uint32_t 返回正相输入
*             @arg COMP_INPSEL_IO1
*             @arg COMP_INPSEL_IO2
*             @arg COMP_INPSEL_IO3
*             @arg COMP_INPSEL_IO4
*/
__STATIC_INLINE uint32_t std_comp_get_input_plus(COMP_t *compx)
{
    return(compx->CSR & COMP_CSR_INP);
}

/** 
* @brief  设置COMP正相输入模式
* @param  compx COMP外设
* @param  input_mode 正相输入模式选择
*             @arg COMP_INPMODE_EACH_INPUT
*             @arg COMP_INPMODE_COMMON_INPUT
* @retval 无
*/
__STATIC_INLINE void std_comp_set_input_plus_mode(COMP_t *compx, uint32_t input_mode)
{
    MODIFY_REG(compx->CSR, COMP_CSR_INPMOD, input_mode);
}

/** 
* @brief  设置COMP输出模式
* @param  compx COMP外设
* @param  output_mode 输出模式选择
*             @arg COMP_OUTMODE_EACH_OUT
*             @arg COMP_OUTMODE_COMMON_XOR_OUT
* @retval 无
*/
__STATIC_INLINE void std_comp_set_output_mode(COMP_t *compx, uint32_t output_mode)
{
    MODIFY_REG(compx->CSR, COMP_CSR_OUTMOD, output_mode);
}

/** 
* @brief  设置COMP输出极性
* @param  compx COMP外设
* @param  output_polarity 输出极性选择
*             @arg COMP_OUTPOL_NON_INVERTED
*             @arg COMP_OUTPOL_INVERTED
* @retval 无
*/
__STATIC_INLINE void std_comp_set_output_polarity(COMP_t *compx, uint32_t output_polarity)
{
    MODIFY_REG(compx->CSR, COMP_CSR_POL, output_polarity);
}

/** 
* @brief  获取COMP输出极性
* @param  compx COMP外设
* @retval uint32_t 返回输出极性
*             @arg COMP_OUTPOL_NON_INVERTED
*             @arg COMP_OUTPOL_INVERTED
*/
__STATIC_INLINE uint32_t std_comp_get_output_polarity(COMP_t *compx)
{
    return(compx->CSR & COMP_CSR_POL);
}

/** 
* @brief  设置COMP迟滞模式
* @param  compx COMP外设
* @param  input_hysteresis 迟滞模式选择
*             @arg COMP_HYST_NONE
*             @arg COMP_HYST_LOW
*             @arg COMP_HYST_MEDIUM
*             @arg COMP_HYST_HIGH
* @retval 无
*/
__STATIC_INLINE void std_comp_set_input_hysteresis(COMP_t *compx, uint32_t input_hysteresis)
{
    MODIFY_REG(compx->CSR, COMP_CSR_HYST, input_hysteresis);
}

/** 
* @brief  设置COMP响应速度模式
* @param  compx COMP外设
* @param  speed_mode 响应速度
*             @arg COMP_VERYLOWSPEED
*             @arg COMP_LOWSPEED
*             @arg COMP_MEDIUMSPEED
*             @arg COMP_HIGHSPEED
* @retval 无
*/
__STATIC_INLINE void std_comp_set_speed_mode(COMP_t *compx, uint32_t speed_mode)
{
    MODIFY_REG(compx->CSR, COMP_CSR_SPEED, speed_mode);
}

/** 
* @brief  设置COMP输出滤波时间
* @param  compx COMP外设
* @param  filter_time 滤波时间选择
*             @arg COMP_FLTIME_2CYCLE
*             @arg COMP_FLTIME_4CYCLE
*             @arg ...
*             @arg COMP_FLTIME_256CYCLE
* @retval 无
*/
__STATIC_INLINE void std_comp_set_output_filter_time(COMP_t *compx, uint32_t filter_time)
{
    MODIFY_REG(compx->CSR, COMP_CSR_FLTIME, filter_time);
}

/** 
* @brief  COMP输出滤波使能
* @param  compx COMP外设
* @retval 无
*/
__STATIC_INLINE void std_comp_output_filter_enable(COMP_t *compx)
{
    compx->CSR |= (COMP_CSR_FLTEN);
}

/** 
* @brief  COMP输出滤波禁止
* @param  compx COMP外设
* @retval 无
*/
__STATIC_INLINE void std_comp_output_filter_disable(COMP_t *compx)
{
    compx->CSR &= (~COMP_CSR_FLTEN);
}

/** 
* @brief  获取COMP使能状态
* @param  compx COMP外设
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示COMP已使能
*             @arg false：表示COMP未使能
*/
__STATIC_INLINE bool std_comp_get_enable_status(COMP_t *compx)
{
    return ((compx->CSR & COMP_CSR_EN) == COMP_CSR_EN);
}

/** 
* @brief  COMP寄存器锁定
* @param  compx COMP外设
* @note   只能通过复位来清除锁定功能
* @retval 无
*/
__STATIC_INLINE void std_comp_lock(COMP_t *compx)
{
    compx->CSR |= (COMP_CSR_LOCK);
}

/** 
* @brief  获取COMP输出结果
* @param  compx COMP外设
* @retval uint32_t 返回COMP输出结果
*             @arg COMP_OUTPUT_LEVEL_LOW
*             @arg COMP_OUTPUT_LEVEL_HIGH
*/
__STATIC_INLINE uint32_t std_comp_get_output_result(COMP_t *compx)
{
    return ((compx->CSR & COMP_CSR_VAL) >> COMP_CSR_VAL_POS);
}

/* COMP初始化函数 */
void std_comp_init(COMP_t *compx, std_comp_init_t *comp_init_param);
/* COMP结构体初始化函数 */
void std_comp_struct_init(std_comp_init_t *comp_init_struct);
/* COMP去初始化函数 */
void std_comp_deinit(COMP_t *compx);

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

#endif /* CIU32L051_STD_COMP_H */
