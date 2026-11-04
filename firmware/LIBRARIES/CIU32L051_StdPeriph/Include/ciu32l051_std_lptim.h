/************************************************************************************************/
/**
* @file               ciu32l051_std_lptim.h
* @author             MCU Ecosystem Development Team
* @brief              LPTIM STD库驱动头文件。
*                     提供LPTIM相关的STD库操作函数声明、数据类型以及常量的定义。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_LPTIM_H
#define CIU32L051_STD_LPTIM_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup LPTIM LPTIM
* @brief 低功耗定时器的STD库驱动
* @{
*/
/************************************************************************************************/



#ifdef __cplusplus
 extern "C" {
#endif
     
/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"


/*------------------------------------type define-----------------------------------------------*/
     
/************************************************************************************************/
/**
* @defgroup LPTIM_Types LPTIM Types
* @brief    LPTIM数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  LPTIM初始化结构体定义
*/
typedef struct
{
    uint32_t clock_source;               /**< LPTIM时钟源选择                              
                                                    @arg LPTIM_CLK_SRC_INT...                       */
    
    uint32_t prescaler;                  /**< LPTIM预分频器系数选择                                  
                                                    @arg LPTIM_PRESCALER_DIV1...                    */
    
    uint32_t count_source;               /**< LPTIM计数时钟源选择                                   
                                                    @arg LPTIM_COUNTER_CLK_INT...                   */
    
    uint32_t out_polarity;               /**< LPTIM输出极性配置                                      
                                                    @arg LPTIM_OUTPUT_POLARITY_REGULAR...           */
}std_lptim_init_t;

/** 
* @} 
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup LPTIM_Constants LPTIM Constants
* @brief    LPTIM常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* 计数器计数模式 */
#define LPTIM_COUNT_CONTINUOUS          LPTIM_CR_CNTSTRT            /**< PWM模式计数       */
#define LPTIM_COUNT_SINGLE              LPTIM_CR_SNGSTRT            /**< 单脉冲模式计数    */

/* 计数器时钟源选择 */
#define LPTIM_COUNTER_CLK_INT           (0x00000000U)               /**< 内部时钟源计数     */
#define LPTIM_COUNTER_CLK_EXT           LPTIM_CFG_COUNT_MODE        /**< 外部时钟源计数     */

/* 输出极性选择 */
#define LPTIM_OUTPUT_POLARITY_REGULAR   (0x00000000U)               /**< CNT小于CMP输出低电平，否则输出高有效 */
#define LPTIM_OUTPUT_POLARITY_REVERSE   LPTIM_CFG_WAVPOL            /**< CNT小于CMP输出高电平，否则输出低电平 */

/* LPTIM PSC预分频器分频系数选择 */
#define LPTIM_PRESCALER_DIV1            LPTIM_CFG_PRESC_1           /**< PSC预分频器1分频   */
#define LPTIM_PRESCALER_DIV2            LPTIM_CFG_PRESC_2           /**< PSC预分频器2分频   */
#define LPTIM_PRESCALER_DIV4            LPTIM_CFG_PRESC_4           /**< PSC预分频器4分频   */
#define LPTIM_PRESCALER_DIV8            LPTIM_CFG_PRESC_8           /**< PSC预分频器8分频   */
#define LPTIM_PRESCALER_DIV16           LPTIM_CFG_PRESC_16          /**< PSC预分频器16分频  */
#define LPTIM_PRESCALER_DIV32           LPTIM_CFG_PRESC_32          /**< PSC预分频器32分频  */
#define LPTIM_PRESCALER_DIV64           LPTIM_CFG_PRESC_64          /**< PSC预分频器64分频  */
#define LPTIM_PRESCALER_DIV128          LPTIM_CFG_PRESC_128         /**< PSC预分频器128分频 */

/* LPTIM_IN1信号源选择 */
#define LPTIM_IN1_SRC_GPIO              LPTIM_CFG2_IN1_SEL_IN1              /**< GPIO输入       */
#define LPTIM_IN1_SRC_COMP1             LPTIM_CFG2_IN1_SEL_COMP1            /**< COMP1输出信号  */

/* LPTIM_IN2信号源选择 */
#define LPTIM_IN2_SRC_GPIO              LPTIM_CFG2_IN2_SEL_IN2              /**< GPIO输入       */
#define LPTIM_IN2_SRC_COMP2             LPTIM_CFG2_IN2_SEL_COMP2            /**< COMP2输出信号  */

/* LPTIM外部触发源选择 */
#define LPTIM_TRIG_SRC_GPIO             LPTIM_CFG_TRIG_SEL_ETR              /**< 外部GPIO触发      */
#define LPTIM_TRIG_SRC_RTCALARM         LPTIM_CFG_TRIG_SEL_RTCALARM         /**< RTC_ALARM触发     */
#define LPTIM_TRIG_SRC_COMP1            LPTIM_CFG_TRIG_SEL_COMP1            /**< COMP1输出信号触发 */
#define LPTIM_TRIG_SRC_COMP2            LPTIM_CFG_TRIG_SEL_COMP2            /**< COMP2输出信号触发 */

/* LPTIM外部触发源极性选择 */
#define LPTIM_TRIG_EDGE_RISING          LPTIM_CFG_TRIG_EN_RISING            /**< 外部触发上升沿有效 */
#define LPTIM_TRIG_EDGE_FALLING         LPTIM_CFG_TRIG_EN_FALLING           /**< 外部触发下降沿有效 */
#define LPTIM_TRIG_EDGE_BOTH            LPTIM_CFG_TRIG_EN_RISING_FALLING    /**< 外部触发双沿有效   */

/* LPTIM外部触发滤波配置 */
#define LPTIM_TRIG_SAMPLETIME_NOFLT     LPTIM_CFG_TRIG_FLT_NONE             /**< 任何触发信号的有效电平变化均认为有效触发 */
#define LPTIM_TRIG_SAMPLETIME_2         LPTIM_CFG_TRIG_FLT_2                /**< 2个采样周期均采到有效电平视为有效触发    */
#define LPTIM_TRIG_SAMPLETIME_4         LPTIM_CFG_TRIG_FLT_4                /**< 4个采样周期均采到有效电平视为有效触发    */
#define LPTIM_TRIG_SAMPLETIME_8         LPTIM_CFG_TRIG_FLT_8                /**< 8个采样周期均采到有效电平视为有效触发    */

/* LPTIM时钟源选择 */
#define LPTIM_CLK_SRC_INT               (0x00000000U)                       /**< LPTIM时钟源选择内部时钟     */
#define LPTIM_CLK_SRC_EXT               LPTIM_CFG_CKSEL                     /**< LPTIM时钟源选择外部时钟     */

/* LPTIM外部时钟有效极性 */
#define LPTIM_EXTCLK_POL_RISING         (0x00000000U)                       /**< LPTIM外部时钟上升沿有效   */
#define LPTIM_EXTCLK_POL_FALLING        LPTIM_CFG_CKPOL_FALLING             /**< LPTIM外部时钟上升沿有效   */
#define LPTIM_EXTCLK_POL_BOTH           LPTIM_CFG_CKPOL_RISING_FALLING      /**< LPTIM外部时钟任意边沿有效 */

/* LPTIM外部时钟滤波器配置 */
#define LPTIM_EXTCLK_SAMPLETIME_NOFLT   LPTIM_CFG_CKFLT_NONE                /**< 任何触发信号的有效电平变化均认为有效触发 */
#define LPTIM_EXTCLK_SAMPLETIME_2       LPTIM_CFG_CKFLT_2                   /**< 2个采样周期均采到有效电平视为有效触发    */
#define LPTIM_EXTCLK_SAMPLETIME_4       LPTIM_CFG_CKFLT_4                   /**< 4个采样周期均采到有效电平视为有效触发    */
#define LPTIM_EXTCLK_SAMPLETIME_8       LPTIM_CFG_CKFLT_8                   /**< 8个采样周期均采到有效电平视为有效触发    */

/* LPTIM正交编码模式设置 */
#define LPTIM_ENCODER_MODE1             (0x00000000U)                       /**< 编码器模式1，上升沿有效 */
#define LPTIM_ENCODER_MODE2             LPTIM_CFG_CKPOL_FALLING             /**< 编码器模式2，上升沿有效 */
#define LPTIM_ENCODER_MODE3             LPTIM_CFG_CKPOL_RISING_FALLING      /**< 编码器模式3，上升沿有效 */

/* LPTIM DMA请求源 */
#define LPTIM_DMA_REQUEST_ARR           LPTIM_IER_ARR_DMAEN                 /**< 自动重载匹配DMA请求     */
#define LPTIM_DMA_REQUEST_CMP           LPTIM_IER_CMP_DMAEN                 /**< 比较匹配DMA请求         */

/* LPTIM中断源 */
#define LPTIM_INTERRUPT_CMPM            LPTIM_IER_CMPM_IE                   /**< 比较匹配中断使能                     */
#define LPTIM_INTERRUPT_ARRM            LPTIM_IER_ARRM_IE                   /**< 自动重载匹配中断使能                 */
#define LPTIM_INTERRUPT_EXTTRIG         LPTIM_IER_EXTTRIG_IE                /**< 外部触发有效边沿中断使能             */
#define LPTIM_INTERRUPT_UP              LPTIM_IER_UP_IE                     /**< 计数方向变为递增中断使能             */
#define LPTIM_INTERRUPT_DOWN            LPTIM_IER_DOWN_IE                   /**< 计数方向变为递减中断使能             */

/* LPTIM中断状态标志 */
#define LPTIM_FLAG_CMPM                 LPTIM_ISR_CMPM                      /**< 比较匹配标志                 */
#define LPTIM_FLAG_ARRM                 LPTIM_ISR_ARRM                      /**< 自动重载匹配标志             */
#define LPTIM_FLAG_EXTTRIG              LPTIM_ISR_EXTTRIG                   /**< 外部触发标志                 */
#define LPTIM_FLAG_UP                   LPTIM_ISR_UP                        /**< 正交编码，递增计数方向标志   */
#define LPTIM_FLAG_DOWN                 LPTIM_ISR_DOWN                      /**< 正交编码，递减计数方向标志   */

/* LPTIM中断清除标志 */
#define LPTIM_CLEAR_CMPM                LPTIM_ICR_CMPM_CF                   /**< 比较匹配标志清零                     */
#define LPTIM_CLEAR_ARRM                LPTIM_ICR_ARRM_CF                   /**< 自动重载匹配标志清零                 */
#define LPTIM_CLEAR_EXTTRIG             LPTIM_ICR_EXTTRIG_CF                /**< 外部触发有效边沿标志清零             */
#define LPTIM_CLEAR_UP                  LPTIM_ICR_UP_CF                     /**< 计数方向变为递增标志清零             */
#define LPTIM_CLEAR_DOWN                LPTIM_ICR_DOWN_CF                   /**< 计数方向变为递减标志清零             */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup LPTIM_External_Functions LPTIM External Functions
* @brief    LPTIM对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  使能LPTIM
* @param  lptimx LPTIM外设
* @note   在LPTIM使能位置位后，需要两个计数器周期后才能生效
* @retval 无
*/
__STATIC_INLINE void std_lptim_enable(LPTIM_t *lptimx)
{
    lptimx->CR |= LPTIM_CR_ENABLE;
}

/** 
* @brief  禁止LPTIM
* @param  lptimx LPTIM外设
* @retval 无
*/
__STATIC_INLINE void std_lptim_disable(LPTIM_t *lptimx)
{
    lptimx->CR &= (~LPTIM_CR_ENABLE);
}

/** 
* @brief  配置LPTIM计数器按照预期模式开始计数
* @param  lptimx LPTIM外设
* @param  operate_mode 计数模式选择
*             @arg LPTIM_COUNT_CONTINUOUS:    PWM模式计数
*             @arg LPTIM_COUNT_SINGLE:        单脉冲模式计数
* @note   必须使能LPTIM后才能启动计数器计数
* @retval 无
*/
__STATIC_INLINE void std_lptim_start_counter(LPTIM_t *lptimx, uint32_t operate_mode)
{
    MODIFY_REG(lptimx->CR, (LPTIM_CR_CNTSTRT | LPTIM_CR_SNGSTRT), operate_mode);
}

/** 
* @brief  设置LPTIM自动重装载值
* @param  lptimx LPTIM外设
* @param  auto_reload 自动重装载值（该变量的范围为0x0~0xFFFF）
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_auto_reload(LPTIM_t *lptimx, uint32_t auto_reload)
{
    lptimx->ARR = auto_reload;
}

/** 
* @brief  获取LPTIM自动重装载值
* @param  lptimx LPTIM外设
* @retval uint32_t 自动重装载值（该变量的范围为0x0~0xFFFF）
*/
__STATIC_INLINE uint32_t std_lptim_get_auto_reload(LPTIM_t *lptimx)
{
    return (lptimx->ARR);
}

/** 
* @brief  设置LPTIM比较值
* @param  lptimx LPTIM外设
* @param  compare_Value 比较值（该变量的范围为0x0~0xFFFF）
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_compare(LPTIM_t *lptimx, uint32_t compare_Value)
{
    lptimx->CMP = compare_Value;
}

/** 
* @brief  获取LPTIM比较值
* @param  lptimx LPTIM外设
* @retval uint32_t 比较值（该变量的范围为0x0~0xFFFF）
*/
__STATIC_INLINE uint32_t std_lptim_get_compare(LPTIM_t *lptimx)
{
    return (lptimx->CMP);
}

/** 
* @brief  获取LPTIM计数值
* @param  lptimx LPTIM外设
* @note   当LPTIM为异步时钟计数时，为确保获取正确的计数值，需要确保两次读取的计数值一致。
* @retval uint32_t LPTIM计数值（该变量的范围为0x0~0xFFFF）
*/
__STATIC_INLINE uint32_t std_lptim_get_count(LPTIM_t *lptimx)
{
    return (lptimx->CNT);
}

/** 
* @brief  设置LPTIM计数器时钟源
* @param  lptimx LPTIM外设
* @param  counter_clk_src 计数器时钟来源
*             @arg LPTIM_COUNTER_CLK_INT: 计数器在内部时钟每个有效边沿递增
*             @arg LPTIM_COUNTER_CLK_EXT: 计数器在LPTIMx_IN1上输入的外部时钟每个有效边沿递增
* @note   LPTIM工作时钟选择内部时钟时，该函数配置有效
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_counter_clk_source(LPTIM_t *lptimx, uint32_t counter_clk_src)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_COUNT_MODE, counter_clk_src);
}

/** 
* @brief  获取LPTIM计数器时钟源
* @param  lptimx LPTIM外设
* @retval uint32_t 计数器时钟来源
*             @arg LPTIM_COUNTER_CLK_INT: 计数器在内部时钟每个有效边沿递增
*             @arg LPTIM_COUNTER_CLK_EXT: 计数器在LPTIMx_IN1上输入的外部时钟每个有效边沿递增
*/
__STATIC_INLINE uint32_t std_lptim_get_counter_clk_source(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_COUNT_MODE);
}

/** 
* @brief  设置LPTIM输出波形极性（LPTIMx_OUT）
* @param  lptimx LPTIM外设
* @param  polarity 输出波形极性
*             @arg LPTIM_OUTPUT_POLARITY_REGULAR: 当CNT < CMP输出低电平，否则输出高电平
*             @arg LPTIM_OUTPUT_POLARITY_REVERSE: 当CNT < CMP输出高电平，否则输出低电平
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_wave_polarity(LPTIM_t *lptimx, uint32_t polarity)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_WAVPOL, polarity);
}

/** 
* @brief  获取LPTIM输出波形极性（LPTIMx_OUT）
* @param  lptimx LPTIM外设               
* @retval uint32_t 输出波形极性
*             @arg LPTIM_OUTPUT_POLARITY_REGULAR: 当CNT < CMP输出低电平，当CNT > CMP且CNT < ARR时输出高电平
*             @arg LPTIM_OUTPUT_POLARITY_REVERSE: 当CNT < CMP输出高电平，当CNT > CMP且CNT < ARR时输出低电平
*/
__STATIC_INLINE uint32_t std_lptim_get_wave_polarity(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_WAVPOL);
}

/** 
* @brief  设置LPTIM预分频器分频系数
* @param  lptimx LPTIM外设 
* @param  prescaler 预分频系数选择
*             @arg LPTIM_PRESCALER_DIV1
*             @arg LPTIM_PRESCALER_DIV2
*             @arg LPTIM_PRESCALER_DIV4
*             @arg ...
*             @arg LPTIM_PRESCALER_DIV128
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_prescaler(LPTIM_t *lptimx, uint32_t prescaler)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_PRESC, prescaler);
}

/** 
* @brief  获取LPTIM预分频器分频系数
* @param  lptimx LPTIM外设
* @retval uint32_t 预分频系数选择
*             @arg LPTIM_PRESCALER_DIV1
*             @arg LPTIM_PRESCALER_DIV2
*             @arg LPTIM_PRESCALER_DIV4
*             @arg ...
*             @arg LPTIM_PRESCALER_DIV128
*/
__STATIC_INLINE uint32_t std_lptim_get_prescaler(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_PRESC);
}

/** 
* @brief  设置LPTIMx_IN1信号源
* @param  lptimx LPTIM外设
* @param  in1_source LPTIMx_IN1信号源选择
*             @arg LPTIM_IN1_SRC_GPIO
*             @arg LPTIM_IN1_SRC_COMP1
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_input1_source(LPTIM_t *lptimx, uint32_t in1_source)
{
    MODIFY_REG(lptimx->CFG2, LPTIM_CFG2_IN1_SEL, in1_source);
}

/** 
* @brief  设置LPTIMx_IN2信号源
* @param  lptimx LPTIM外设 
* @param  in2_source LPTIMx_IN2信号源选择
*             @arg LPTIM_IN2_SRC_GPIO
*             @arg LPTIM_IN2_SRC_COMP2
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_input2_source(LPTIM_t *lptimx, uint32_t in2_source)
{
    MODIFY_REG(lptimx->CFG2, LPTIM_CFG2_IN2_SEL, in2_source);
}

/** 
* @brief  使能LPTIM超时功能
* @param  lptimx LPTIM外设 
* @retval 无
*/
__STATIC_INLINE void std_lptim_timeout_enable(LPTIM_t *lptimx)
{
    lptimx->CFG |= LPTIM_CFG_TIMOUT;
}

/** 
* @brief  禁止LPTIM超时功能
* @param  lptimx LPTIM外设
* @retval 无
*/
__STATIC_INLINE void std_lptim_timeout_disable(LPTIM_t *lptimx)
{
    lptimx->CFG &= (~LPTIM_CFG_TIMOUT);
}

/** 
* @brief  设置软件触发计数
* @param  lptimx LPTIM外设
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_software_trig(LPTIM_t *lptimx)
{
    lptimx->CFG &= (~LPTIM_CFG_TRIG_EN);
}

/** 
* @brief  设置外部触发源
* @param  lptimx LPTIM外设
* @param  trig_source 外部触发源
*             @arg LPTIM_TRIG_SRC_GPIO
*             @arg LPTIM_TRIG_SRC_RTCALARM
*             @arg ...
*             @arg LPTIM_TRIG_SRC_COMP2
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_external_trig_source(LPTIM_t *lptimx, uint32_t trig_source)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_TRIG_SEL, trig_source);
}

/** 
* @brief  获取外部触发源
* @param  lptimx LPTIM外设
* @retval uint32_t 外部触发源
*             @arg LPTIM_TRIG_SRC_GPIO
*             @arg LPTIM_TRIG_SRC_RTCALARM
*             @arg ...
*             @arg LPTIM_TRIG_SRC_COMP2
*/
__STATIC_INLINE uint32_t std_lptim_get_external_trig_source(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_TRIG_SEL);
}

/** 
* @brief  设置外部触发源极性
* @param  lptimx LPTIM外设   
* @param  trig_polarity 外部触发源极性
*             @arg LPTIM_TRIG_EDGE_RISING
*             @arg LPTIM_TRIG_EDGE_FALLING
*             @arg LPTIM_TRIG_EDGE_BOTH
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_external_trig_polarity(LPTIM_t *lptimx, uint32_t trig_polarity)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_TRIG_EN, trig_polarity);
}

/** 
* @brief  获取外部触发源极性
* @param  lptimx LPTIM外设
* @retval uint32_t 外部触发源极性
*             @arg LPTIM_TRIG_EDGE_RISING
*             @arg LPTIM_TRIG_EDGE_FALLING
*             @arg LPTIM_TRIG_EDGE_BOTH      
*/
__STATIC_INLINE uint32_t std_lptim_get_external_trig_polarity(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_TRIG_EN);
}

/** 
* @brief  设置外部触发信号滤波配置
* @param  lptimx LPTIM外设   
* @param  trig_filter 触发滤波配置
*             @arg LPTIM_TRIG_SAMPLETIME_NOFLT
*             @arg LPTIM_TRIG_SAMPLETIME_2
*             @arg LPTIM_TRIG_SAMPLETIME_4
*             @arg LPTIM_TRIG_SAMPLETIME_8
* @note   触发信号滤波宽度为N时，连续N个采样周期均采到有效电平才视为有效触发
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_external_trig_filter(LPTIM_t *lptimx, uint32_t trig_filter)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_TRIG_FLT, trig_filter);
}

/** 
* @brief  获取外部触发源滤波器配置
* @param  lptimx LPTIM外设
* @retval uint32_t 触发滤波配置
*             @arg LPTIM_TRIG_SAMPLETIME_NOFLT
*             @arg LPTIM_TRIG_SAMPLETIME_2
*             @arg LPTIM_TRIG_SAMPLETIME_4    
*             @arg LPTIM_TRIG_SAMPLETIME_8
*/
__STATIC_INLINE uint32_t std_lptim_get_external_trig_filter(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_TRIG_FLT);
}

/** 
* @brief  选择LPTIM时钟源
* @param  lptimx LPTIM外设
* @param  clock_source LPTIM时钟源选择
*             @arg LPTIM_CLK_SRC_INT: 选择内部时钟源
*             @arg LPTIM_CLK_SRC_EXT: 选择外部时钟源
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_clock_source(LPTIM_t *lptimx, uint32_t clock_source)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_CKSEL, clock_source);
}

/** 
* @brief  获取LPTIM时钟源
* @param  lptimx LPTIM外设   
* @retval uint32_t LPTIM时钟源选择
*             @arg LPTIM_CLK_SRC_INT: 选择内部时钟源
*             @arg LPTIM_CLK_SRC_EXT: 选择外部时钟源
*/
__STATIC_INLINE uint32_t std_lptim_get_clock_source(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_CKSEL);
}

/** 
* @brief  配置外部时钟源极性
* @param  lptimx LPTIM外设
* @param  polarity 外部时钟有效极性
*             @arg LPTIM_EXTCLK_POL_RISING:   外部时钟源上升沿有效
*             @arg LPTIM_EXTCLK_POL_FALLING:  外部时钟源下降沿有效
*             @arg LPTIM_EXTCLK_POL_BOTH:     外部时钟源任意边沿有效
* @note   当选择任意边沿有效时，LPTIMx必须选择内部时钟源，且内部时钟频率大于等于外部时钟频率的4倍
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_external_clk_polarity(LPTIM_t *lptimx, uint32_t polarity)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_CKPOL, polarity);
}

/** 
* @brief  获取外部时钟源极性
* @param  lptimx LPTIM外设
* @retval uint32_t LPTIM时钟源极性
*             @arg LPTIM_EXTCLK_POL_RISING:   外部时钟源上升沿有效
*             @arg LPTIM_EXTCLK_POL_FALLING:  外部时钟源下降沿有效
*             @arg LPTIM_EXTCLK_POL_BOTH:     外部时钟源任意边沿有效
*/
__STATIC_INLINE uint32_t std_lptim_get_external_clk_polarity(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_CKPOL);
}

/** 
* @brief  配置外部输入信号数字滤波器
* @param  lptimx LPTIM外设
* @param  clk_filter 外部时钟数字滤波器配置
*             @arg LPTIM_EXTCLK_SAMPLETIME_NOFLT: 无滤波
*             @arg LPTIM_EXTCLK_SAMPLETIME_2:     2个滤波周期    
*             @arg LPTIM_EXTCLK_SAMPLETIME_4:     4个滤波周期
*             @arg LPTIM_EXTCLK_SAMPLETIME_8:     8个滤波周期
* @note   外部时钟信号滤波宽度为N时，连续N个采样周期均采到有效电平才视为有效切换
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_extern_clk_filter(LPTIM_t *lptimx, uint32_t clk_filter)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_CKFLT, clk_filter);
}

/** 
* @brief  获取外部时钟数字滤波器配置
* @param  lptimx LPTIM外设
* @retval uint32_t 外部时钟数字滤波器配置
*             @arg LPTIM_EXTCLK_SAMPLETIME_NOFLT: 无滤波
*             @arg LPTIM_EXTCLK_SAMPLETIME_2:     2个滤波周期    
*             @arg LPTIM_EXTCLK_SAMPLETIME_4:     4个滤波周期
*             @arg LPTIM_EXTCLK_SAMPLETIME_8:     8个滤波周期
*/
__STATIC_INLINE uint32_t std_lptim_get_external_clk_filter(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_CKFLT);
}

/** 
* @brief  使能正交编码器模式
* @param  lptimx LPTIM外设 
* @retval 无
*/
__STATIC_INLINE void std_lptim_encoder_enable(LPTIM_t *lptimx)
{
    lptimx->CFG |= LPTIM_CFG_ENC;
}

/** 
* @brief  禁止正交编码器模式
* @param  lptimx LPTIM外设 
* @retval 无
*/
__STATIC_INLINE void std_lptim_encoder_disable(LPTIM_t *lptimx)
{
    lptimx->CFG &= (~LPTIM_CFG_ENC);
}

/** 
* @brief  设置正交编码器模式
* @param  lptimx LPTIM外设
* @param  encoder_mode 正交编码器编码模式
*             @arg LPTIM_ENCODER_MODE1:    编码器模式1，上升沿有效
*             @arg LPTIM_ENCODER_MODE2:    编码器模式2，下降沿有效
*             @arg LPTIM_ENCODER_MODE3:    编码器模式3，上升沿和下降沿有效
* @retval 无
*/
__STATIC_INLINE void std_lptim_set_encoder_mode(LPTIM_t *lptimx, uint32_t encoder_mode)
{
    MODIFY_REG(lptimx->CFG, LPTIM_CFG_CKPOL, encoder_mode);
}

/** 
* @brief  获取正交编码器模式
* @param  lptimx LPTIM外设
* @retval uint32_t 正交编码器编码模式
*             @arg LPTIM_ENCODER_MODE1
*             @arg LPTIM_ENCODER_MODE2
*             @arg LPTIM_ENCODER_MODE3
*/
__STATIC_INLINE uint32_t std_lptim_get_encoder_mode(LPTIM_t *lptimx)
{
    return (lptimx->CFG & LPTIM_CFG_CKPOL);
}    

/** 
* @brief  使能LPTIMx DMA请求
* @param  lptimx LPTIM外设  
* @param  dma_req LPTIM DMA请求源
*             @arg LPTIM_DMA_REQUEST_ARR:     自动重载匹配DMA请求
*             @arg LPTIM_DMA_REQUEST_CMP:     比较匹配DMA请求
* @retval 无
*/
__STATIC_INLINE void std_lptim_dma_request_enable(LPTIM_t *lptimx, uint32_t dma_req)
{
    lptimx->IER |= dma_req;
}

/** 
* @brief  禁止LPTIMx DMA请求
* @param  lptimx LPTIM外设  
* @param  dma_req LPTIM DMA请求源
*             @arg LPTIM_DMA_REQUEST_ARR:     自动重载匹配DMA请求
*             @arg LPTIM_DMA_REQUEST_CMP:     比较匹配DMA请求
* @retval 无
*/
__STATIC_INLINE void std_lptim_dma_request_disable(LPTIM_t *lptimx, uint32_t dma_req)
{
    lptimx->IER &= (~dma_req);
}

/** 
* @brief  获取LPTIMx DMA请求使能状态
* @param  lptimx LPTIM外设  
* @param  dma_req LPTIM DMA请求源
*             @arg LPTIM_DMA_REQUEST_ARR:     自动重载匹配DMA请求
*             @arg LPTIM_DMA_REQUEST_CMP:     比较匹配DMA请求
* @retval bool DMA请求源使能状态
*             @arg true:  DMA请求源使能
*             @arg false: DMA请求源禁止
*/
__STATIC_INLINE uint32_t std_lptim_get_dma_request_status(LPTIM_t *lptimx, uint32_t dma_req)
{
    return ((lptimx->IER & dma_req) == dma_req);
}

/** 
* @brief  使能LPTIMx中断
* @param  lptimx LPTIM外设  
* @param  interrupt LPTIM中断源
*             @arg LPTIM_INTERRUPT_CMPM:      比较匹配中断
*             @arg LPTIM_INTERRUPT_ARRM:      自动重载匹配中断
*             @arg LPTIM_INTERRUPT_EXTTRIG:   外部触发边沿事件中断
*             @arg LPTIM_INTERRUPT_UP:        计数方向由递减变为递增中断
*             @arg LPTIM_INTERRUPT_DOWN:      计数方向由递增变为递减中断
* @retval 无
*/
__STATIC_INLINE void std_lptim_interrupt_enable(LPTIM_t *lptimx, uint32_t interrupt)
{
    lptimx->IER |= interrupt;
}

/** 
* @brief  禁止LPTIMx中断
* @param  lptimx LPTIM外设   
* @param  interrupt LPTIM中断源
*             @arg LPTIM_INTERRUPT_CMPM:      比较匹配中断
*             @arg LPTIM_INTERRUPT_ARRM:      自动重载匹配中断
*             @arg LPTIM_INTERRUPT_EXTTRIG:   外部触发边沿事件中断
*             @arg LPTIM_INTERRUPT_UP:        计数方向由递减变为递增中断
*             @arg LPTIM_INTERRUPT_DOWN:      计数方向由递增变为递减中断
* @retval 无
*/
__STATIC_INLINE void std_lptim_interrupt_disable(LPTIM_t *lptimx, uint32_t interrupt)
{
    lptimx->IER &= (~interrupt);
}

/** 
* @brief  获取LPTIMx中断状态
* @param  lptimx LPTIM外设  
* @param  interrupt LPTIM中断源
*             @arg LPTIM_INTERRUPT_CMPM:      比较匹配中断
*             @arg LPTIM_INTERRUPT_ARRM:      自动重载匹配中断
*             @arg LPTIM_INTERRUPT_EXTTRIG:   外部触发边沿事件中断
*             @arg LPTIM_INTERRUPT_UP:        计数方向由递减变为递增中断
*             @arg LPTIM_INTERRUPT_DOWN:      计数方向由递增变为递减中断
* @retval bool LPTIM中断源使能状态
*             @arg true:中断使能
*             @arg false:中断禁止
*           
*/
__STATIC_INLINE bool std_lptim_get_interrupt_status(LPTIM_t *lptimx, uint32_t interrupt)
{
    return ((lptimx->IER & interrupt) == interrupt);
}

/** 
* @brief  获取LPTIMx状态标志位
* @param  lptimx LPTIM外设
* @param  flag LPTIM状态标志位
*             @arg LPTIM_FLAG_CMPM:        比较匹配标志
*             @arg LPTIM_FLAG_ARRM:        自动重载匹配标志
*             @arg LPTIM_FLAG_EXTTRIG:     外部触发边沿事件标志
*             @arg LPTIM_FLAG_UP:          计数方向由递减变为递增标志
*             @arg LPTIM_FLAG_DOWN:        计数方向由递增变为递减标志
*/
__STATIC_INLINE bool std_lptim_get_flag(LPTIM_t *lptimx, uint32_t flag)
{
    return ((lptimx->ISR & flag) == flag);
}

/** 
* @brief  清除LPTIMx状态标志位
* @param  lptimx LPTIM外设
* @param  flag LPTIM状态标志位
*             @arg LPTIM_CLEAR_CMPM:        比较匹配标志
*             @arg LPTIM_CLEAR_ARRM:        自动重载匹配标志
*             @arg LPTIM_CLEAR_EXTTRIG:     外部触发边沿事件标志
*             @arg LPTIM_CLEAR_UP:          计数方向由递减变为递增标志
*             @arg LPTIM_CLEAR_DOWN:        计数方向由递增变为递减标志
* @retval 无
*/
__STATIC_INLINE void std_lptim_clear_flag(LPTIM_t *lptimx, uint32_t flag)
{
    lptimx->ICR |= flag;
}



/* LPTIM初始化相关函数 */
void std_lptim_deinit(LPTIM_t *lptimx);
void std_lptim_init(LPTIM_t *lptimx, std_lptim_init_t *lptim_init_param);

/* LPTIM结构体初始化相关函数 */
void std_lptim_struct_init(std_lptim_init_t *lptim_init_struct);

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
     
#endif /* CIU32L051_STD_LPTIM_H */
