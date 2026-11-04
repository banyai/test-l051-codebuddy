/************************************************************************************************/
/**
* @file               ciu32l051_std_vrefbuf.h
* @author             MCU Ecosystem Development Team
* @brief              VREFBUF STD库驱动头文件。
*                     提供VREFBUF相关的STD库操作函数声明、数据类型以及常量的定义。                      
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_VREFBUF_H
#define CIU32L051_STD_VREFBUF_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup VREFBUF VREFBUF
* @brief    参考电压源的STD库驱动
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
* @defgroup VREFBUF_Constants VRFEBUF Constants
* @brief    VREFBUF常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* VRFEBUF 外设支持输出的电压值: 用于输出电压配置 */
#define VREFBUF_VOLTAGE_2048                  VREFBUF_CSR_VRS_2048            /**< VRFEBUF 输出2.048V */                
#define VREFBUF_VOLTAGE_2500                  VREFBUF_CSR_VRS_2500            /**< VRFEBUF 输出2.5V   */
#define VREFBUF_VOLTAGE_3000                  VREFBUF_CSR_VRS_3000            /**< VRFEBUF 输出3.0V   */ 

/* VRFEBUF 电压校准值 */
#define VREFBUF_CAL_VALUE_2048                *((uint32_t*)(VREFBUF_CAL_20))  /**< VREFBUF校准值地址：2.048V */
#define VREFBUF_CAL_VALUE_2500                *((uint32_t*)(VREFBUF_CAL_25))  /**< VREFBUF校准值地址：2.5V   */
#define VREFBUF_CAL_VALUE_3000                *((uint32_t*)(VREFBUF_CAL_30))  /**< VREFBUF校准值地址：3.0V   */
 
/* VRFEBUF 外设支持输出的电压值：作为ADC参考电压时，用于转换电压计算 */
#define VREFBUF_VOLTAGE_2048_REF               (2048U)                        /**< VRFEBUF 输出2.048V 参考电压计算值 */                
#define VREFBUF_VOLTAGE_2500_REF               (2500U)                        /**< VRFEBUF 输出2.048V 参考电压计算值 */   
#define VREFBUF_VOLTAGE_3000_REF               (3000U)                        /**< VRFEBUF 输出2.048V 参考电压计算值 */   


/**
* @}
*/
/*------------------------------------------ functions -----------------------------------------*/
/************************************************************************************************/
/**
* @defgroup VREFBUF_Exported_Functions VREFBUF Exported Functions
* @brief    VREFBUF对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  VREFBUF 使能
* @retval 无
*/
__STATIC_INLINE void std_vrefbuf_enable(void)
{
    VREFBUF->CSR |= (VREFBUF_CSR_EN);
}


/**
* @brief  VREFBUF 禁止
* @retval 无
*/
__STATIC_INLINE void std_vrefbuf_disable(void)
{
     VREFBUF->CSR &= (~VREFBUF_CSR_EN);
}


/**
* @brief  VREFBUF 获取ready位状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示VREFBUF输出达到预期值
*             @arg false：表示VREFBUF未输出输出未稳定
*/
__STATIC_INLINE bool std_vrefbuf_get_ready_status(void)
{   
    return ((VREFBUF->CSR & VREFBUF_CSR_RDY) == (VREFBUF_CSR_RDY));
}


/**
* @brief VREFBUF 外设输出电压值配置
* @param voltage_scale VREFBUF输出电压值
*             @arg VREFBUF_VOLTAGE_2048
*             @arg VREFBUF_VOLTAGE_2500
*             @arg VREFBUF_VOLTAGE_3000
*/
__STATIC_INLINE void std_vrefbuf_output_config(uint32_t voltage_scale)
{
    MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_VRS, voltage_scale);
}


/** 
* @} 
*/

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

#endif /* CIU32L051_STD_VREFBUF_H */
