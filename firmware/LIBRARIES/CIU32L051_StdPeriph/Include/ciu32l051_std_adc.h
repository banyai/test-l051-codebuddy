/************************************************************************************************/
/**
* @file               ciu32l051_std_adc.h
* @author             MCU Ecosystem Development Team
* @brief              ADC STD库驱动头文件。
*                     提供ADC相关的STD库操作函数声明、数据类型以及常量的定义。                         
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_ADC_H
#define CIU32L051_STD_ADC_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup ADC ADC
* @brief 模数转换器的STD库驱动
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
* @defgroup ADC_Types  ADC Types 
* @brief    ADC数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  ADC初始化结构体定义
*/
typedef struct
{
    uint32_t clock_src;            /**< 时钟源：同步时钟PCLK、异步时钟RCH16、SYSCLK及分频
                                             @arg ADC_SYNC_CLK_PCLK_DIV1 ... */

    uint32_t clock_presc;          /**< 异步时钟分频配置
                                             @arg ADC_ASYNC_CLK_DIV1 ... */
   
    uint32_t trigger_edge;         /**< 触发方式和极性配置
                                             @arg ADC_TRIG_SW ... */

    uint32_t trigger_source;       /**< 转换触发源选择，当选择软件触发时，外部触发禁止
                                             @arg ADC_EXTRIG_EXTI11 ... */
    
    uint32_t sampt1;               /**< 采样时间参数1，ADC外设具有两组采样时间参数，每个通道可选择其一
                                             @arg ADC_SAMPTIME_3CYCLES ... */

    uint32_t sampt2;               /**< 采样时间参数2，ADC外设具有两组采样时间参数，每个通道可选择其一
                                             @arg ADC_SAMPTIME_3CYCLES ... */

    uint32_t overrun_mode;         /**< 转换溢出后ADC_DR寄存器的数据存储方式，保留原数据或被新转换结果覆盖
                                             @arg ADC_OVRN_MODE_PRESERVED ... */

    uint32_t conver_mode;          /**< 转换模式选择，可设置为单次扫描、循环扫描、循环间断转换模式 
                                             @arg ADC_SINGLE_CONVER_MODE ... */
                                             
    uint32_t scan_dir;             /**< 通道序列扫描方向配置
                                             @arg ADC_SCAN_DIR_FORWARD ... */

} std_adc_init_t;

/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup ADC_Constants  ADC Constants
* @brief    ADC常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* ADC时钟源及分频系数 */
#define ADC_SYNC_CLK_PCLK_DIV1               ADC_CFG2_CKSRC_PCLK                            /**< ADC同步时钟: PCLK不分频 */
#define ADC_SYNC_CLK_PCLK_DIV2               ADC_CFG2_CKSRC_PCLK_DIV2                       /**< ADC同步时钟: PCLK/2分频 */
#define ADC_SYNC_CLK_PCLK_DIV4               ADC_CFG2_CKSRC_PCLK_DIV4                       /**< ADC同步时钟: PCLK/4分频 */
#define ADC_ASYNC_CLK_KCLK                   ADC_CFG2_CKSRC_KCLK                            /**< ADC异步时钟: KCLK       */

/* ADC异步时钟分频系数 */
#define ADC_ASYNC_CLK_DIV1                   ADC_CFG2_PRESC_DIV1                            /**< ADC异步时钟: 不分频  */
#define ADC_ASYNC_CLK_DIV2                   ADC_CFG2_PRESC_DIV2                            /**< ADC异步时钟: 2分频   */
#define ADC_ASYNC_CLK_DIV4                   ADC_CFG2_PRESC_DIV4                            /**< ADC异步时钟: 4分频   */
#define ADC_ASYNC_CLK_DIV6                   ADC_CFG2_PRESC_DIV6                            /**< ADC异步时钟: 6分频   */
#define ADC_ASYNC_CLK_DIV8                   ADC_CFG2_PRESC_DIV8                            /**< ADC异步时钟: 8分频   */
#define ADC_ASYNC_CLK_DIV10                  ADC_CFG2_PRESC_DIV10                           /**< ADC异步时钟: 10分频  */
#define ADC_ASYNC_CLK_DIV12                  ADC_CFG2_PRESC_DIV12                           /**< ADC异步时钟: 12分频  */
#define ADC_ASYNC_CLK_DIV16                  ADC_CFG2_PRESC_DIV16                           /**< ADC异步时钟: 16分频  */
#define ADC_ASYNC_CLK_DIV32                  ADC_CFG2_PRESC_DIV32                           /**< ADC异步时钟: 32分频  */
#define ADC_ASYNC_CLK_DIV64                  ADC_CFG2_PRESC_DIV64                           /**< ADC异步时钟: 64分频  */
#define ADC_ASYNC_CLK_DIV128                 ADC_CFG2_PRESC_DIV128                          /**< ADC异步时钟: 128分频 */

/* ADC转换模式 */
#define ADC_SINGLE_CONVER_MODE               ADC_CFG1_CONV_MOD_SINGLE                       /**< ADC单次扫描转换 */
#define ADC_CONTINUOUS_CONVER_MODE           ADC_CFG1_CONV_MOD_CONTINUOUS                   /**< ADC循环扫描转换 */
#define ADC_DISCONTINUOUS_CONVER_MODE        ADC_CFG1_CONV_MOD_DISCONTINUOUS                /**< ADC循环间断转换 */

/* ADC通道扫描方向 */
#define ADC_SCAN_DIR_FORWARD                 (0x00000000U)                                  /**< ADC转换通道: 正向扫描 */
#define ADC_SCAN_DIR_BACKWARD                ADC_CFG1_SDIR                                  /**< ADC转换通道: 反向扫描 */

/* ADC转换触发模式: 触发沿 */
#define ADC_TRIG_SW                          ADC_CFG1_TRIGEN_SW                             /**< 软件触发方式                 */
#define ADC_TRIG_HW_EDGE_RISING              ADC_CFG1_TRIGEN_HW_EDGE_RISING                 /**< 外部硬件触发使能: 上升沿触发 */
#define ADC_TRIG_HW_EDGE_FALLING             ADC_CFG1_TRIGEN_HW_EDGE_FALLING                /**< 外部硬件触发使能: 下降沿触发 */
#define ADC_TRIG_HW_EDGE_BOTH                ADC_CFG1_TRIGEN_HW_EDGE_BOTH                   /**< 外部硬件触发使能: 双沿触发   */

/*  ADC转换触发源 */
#define ADC_EXTRIG_TIM3_TRGO                 ADC_CFG1_TRIG_TIM3_TRGO                        /**< ADC触发源: TIM3 TRGO       */
#define ADC_EXTRIG_TIM4_TRGO                 ADC_CFG1_TRIG_TIM4_TRGO                        /**< ADC触发源: TIM4 TRGO       */
#define ADC_EXTRIG_TIM5_TRGO                 ADC_CFG1_TRIG_TIM5_TRGO                        /**< ADC触发源: TIM5 TRGO       */
#define ADC_EXTRIG_TIM8_TRGO                 ADC_CFG1_TRIG_TIM8_TRGO                        /**< ADC触发源: TIM8 TRGO       */
#define ADC_EXTRIG_EXTI2                     ADC_CFG1_TRIG_EXTI2                            /**< ADC触发源: 外部中断EXTI_2  */
#define ADC_EXTRIG_EXTI11                    ADC_CFG1_TRIG_EXTI11                           /**< ADC触发源: 外部中断EXTI_11 */

/* ADC转换溢出后ADC_DR寄存器数据存储方式 */
#define ADC_OVRN_MODE_PRESERVED              (0x00000000U)                                  /**< ADC_DR寄存器保留原数据 */
#define ADC_OVRN_MODE_OVERWRITTEN            ADC_CFG1_OVRN_MOD                              /**< ADC_DR寄存器覆盖新数据 */

/* ADC转换采样时间参数组 */
#define ADC_SAMPTIME_GROUP_1                 (0U)                                           /**< 采样时间参数：组1 */
#define ADC_SAMPTIME_GROUP_2                 (4U)                                           /**< 采样时间参数：组2 */

/* ADC采样时间参数 */
#define ADC_SAMPTIME_3CYCLES                 ADC_SAMPT_SAMPT1_3CYCLES                       /**< 采样时间为3个时钟周期    */
#define ADC_SAMPTIME_7CYCLES                 ADC_SAMPT_SAMPT1_7CYCLES                       /**< 采样时间为7个时钟周期    */
#define ADC_SAMPTIME_12CYCLES                ADC_SAMPT_SAMPT1_12CYCLES                      /**< 采样时间为12个时钟周期   */
#define ADC_SAMPTIME_19CYCLES                ADC_SAMPT_SAMPT1_19CYCLES                      /**< 采样时间为19个时钟周期   */
#define ADC_SAMPTIME_39CYCLES                ADC_SAMPT_SAMPT1_39CYCLES                      /**< 采样时间为39个时钟周期   */
#define ADC_SAMPTIME_79CYCLES                ADC_SAMPT_SAMPT1_79CYCLES                      /**< 采样时间为79个时钟周期   */
#define ADC_SAMPTIME_119CYCLES               ADC_SAMPT_SAMPT1_119CYCLES                     /**< 采样时间为119个时钟周期  */
#define ADC_SAMPTIME_159CYCLES               ADC_SAMPT_SAMPT1_159CYCLES                     /**< 采样时间为159个时钟周期  */
#define ADC_SAMPTIME_239CYCLES               ADC_SAMPT_SAMPT1_239CYCLES                     /**< 采样时间为239个时钟周期  */
#define ADC_SAMPTIME_319CYCLES               ADC_SAMPT_SAMPT1_319CYCLES                     /**< 采样时间为319个时钟周期  */
#define ADC_SAMPTIME_479CYCLES               ADC_SAMPT_SAMPT1_479CYCLES                     /**< 采样时间为479个时钟周期  */
#define ADC_SAMPTIME_639CYCLES               ADC_SAMPT_SAMPT1_639CYCLES                     /**< 采样时间为639个时钟周期  */
#define ADC_SAMPTIME_959CYCLES               ADC_SAMPT_SAMPT1_959CYCLES                     /**< 采样时间为959个时钟周期  */
#define ADC_SAMPTIME_1279CYCLES              ADC_SAMPT_SAMPT1_1279CYCLES                    /**< 采样时间为1279个时钟周期 */
#define ADC_SAMPTIME_1919CYCLES              ADC_SAMPT_SAMPT1_1919CYCLES                    /**< 采样时间为1919个时钟周期 */

/* ADC转换通道 */
#define ADC_CHANNEL_NONE                     (0x00000000U)                                  /**< ADC 转换通道清除       */ 
#define ADC_CHANNEL_0                        ADC_CHCFG_CHN0                                 /**< ADC 转换通道IN0        */
#define ADC_CHANNEL_1                        ADC_CHCFG_CHN1                                 /**< ADC 转换通道IN1        */
#define ADC_CHANNEL_2                        ADC_CHCFG_CHN2                                 /**< ADC 转换通道IN2        */
#define ADC_CHANNEL_3                        ADC_CHCFG_CHN3                                 /**< ADC 转换通道IN3        */
#define ADC_CHANNEL_4                        ADC_CHCFG_CHN4                                 /**< ADC 转换通道IN4        */
#define ADC_CHANNEL_5                        ADC_CHCFG_CHN5                                 /**< ADC 转换通道IN5        */
#define ADC_CHANNEL_6                        ADC_CHCFG_CHN6                                 /**< ADC 转换通道IN6        */
#define ADC_CHANNEL_7                        ADC_CHCFG_CHN7                                 /**< ADC 转换通道IN7        */
#define ADC_CHANNEL_8                        ADC_CHCFG_CHN8                                 /**< ADC 转换通道IN8        */
#define ADC_CHANNEL_9                        ADC_CHCFG_CHN9                                 /**< ADC 转换通道IN9        */
#define ADC_CHANNEL_10                       ADC_CHCFG_CHN10                                /**< ADC 转换通道IN10       */
#define ADC_CHANNEL_11                       ADC_CHCFG_CHN11                                /**< ADC 转换通道IN11       */
#define ADC_CHANNEL_12                       ADC_CHCFG_CHN12                                /**< ADC 转换通道IN12       */
#define ADC_CHANNEL_13                       ADC_CHCFG_CHN13                                /**< ADC 转换通道IN13       */
#define ADC_CHANNEL_14                       ADC_CHCFG_CHN14                                /**< ADC 转换通道IN14       */
#define ADC_CHANNEL_15                       ADC_CHCFG_CHN15                                /**< ADC 转换通道IN15       */
#define ADC_CHANNEL_16                       ADC_CHCFG_CHN16                                /**< ADC 转换通道IN16       */
#define ADC_CHANNEL_19                       ADC_CHCFG_CHN19                                /**< ADC 转换通道IN19       */
#define ADC_CHANNEL_VTS                      ADC_CHCFG_CHN12                                /**< ADC 内部转换通道VTS    */
#define ADC_CHANNEL_VBGR                     ADC_CHCFG_CHN13                                /**< ADC 内部转换通道VBGR   */
#define ADC_CHANNEL_VBAT_DIV3                ADC_CHCFG_CHN14                                /**< ADC 内部转换通道VBAT/3 */
#define ADC_CHANNEL_VDDA_DIV3                ADC_CHCFG_CHN14                                /**< ADC 内部转换通道VDDA/3 */
#define ADC_CHANNEL_ALL                      ADC_CHCFG_CHN                                  /**< ADC 全部转换通道       */ 

/* ADC模拟看门狗监测通道 */
#define ADC_AWDG_CHANNEL_NONE                (0x00000000U)                                  /**< ADC 模拟看门狗监测通道清除   */ 
#define ADC_AWDG_CHANNEL_0                   ADC_AWDG1CR_AWDG1_CHN0                         /**< ADC 模拟看门狗监测通道0      */ 
#define ADC_AWDG_CHANNEL_1                   ADC_AWDG1CR_AWDG1_CHN1                         /**< ADC 模拟看门狗监测通道1      */ 
#define ADC_AWDG_CHANNEL_2                   ADC_AWDG1CR_AWDG1_CHN2                         /**< ADC 模拟看门狗监测通道2      */ 
#define ADC_AWDG_CHANNEL_3                   ADC_AWDG1CR_AWDG1_CHN3                         /**< ADC 模拟看门狗监测通道3      */ 
#define ADC_AWDG_CHANNEL_4                   ADC_AWDG1CR_AWDG1_CHN4                         /**< ADC 模拟看门狗监测通道4      */ 
#define ADC_AWDG_CHANNEL_5                   ADC_AWDG1CR_AWDG1_CHN5                         /**< ADC 模拟看门狗监测通道5      */ 
#define ADC_AWDG_CHANNEL_6                   ADC_AWDG1CR_AWDG1_CHN6                         /**< ADC 模拟看门狗监测通道6      */ 
#define ADC_AWDG_CHANNEL_7                   ADC_AWDG1CR_AWDG1_CHN7                         /**< ADC 模拟看门狗监测通道7      */ 
#define ADC_AWDG_CHANNEL_8                   ADC_AWDG1CR_AWDG1_CHN8                         /**< ADC 模拟看门狗监测通道8      */ 
#define ADC_AWDG_CHANNEL_9                   ADC_AWDG1CR_AWDG1_CHN9                         /**< ADC 模拟看门狗监测通道9      */ 
#define ADC_AWDG_CHANNEL_10                  ADC_AWDG1CR_AWDG1_CHN10                        /**< ADC 模拟看门狗监测通道10     */ 
#define ADC_AWDG_CHANNEL_11                  ADC_AWDG1CR_AWDG1_CHN11                        /**< ADC 模拟看门狗监测通道11     */ 
#define ADC_AWDG_CHANNEL_12                  ADC_AWDG1CR_AWDG1_CHN12                        /**< ADC 模拟看门狗监测通道12     */ 
#define ADC_AWDG_CHANNEL_13                  ADC_AWDG1CR_AWDG1_CHN13                        /**< ADC 模拟看门狗监测通道13     */ 
#define ADC_AWDG_CHANNEL_14                  ADC_AWDG1CR_AWDG1_CHN14                        /**< ADC 模拟看门狗监测通道14     */ 
#define ADC_AWDG_CHANNEL_15                  ADC_AWDG1CR_AWDG1_CHN15                        /**< ADC 模拟看门狗监测通道15     */ 
#define ADC_AWDG_CHANNEL_16                  ADC_AWDG1CR_AWDG1_CHN16                        /**< ADC 模拟看门狗监测通道16     */ 
#define ADC_AWDG_CHANNEL_19                  ADC_AWDG1CR_AWDG1_CHN19                        /**< ADC 模拟看门狗监测通道19     */
#define ADC_AWDG_CHANNEL_VTS                 ADC_AWDG1CR_AWDG1_CHN12                        /**< ADC 模拟看门狗监测通道VTS    */ 
#define ADC_AWDG_CHANNEL_VBGR                ADC_AWDG1CR_AWDG1_CHN13                        /**< ADC 模拟看门狗监测通道VBGR   */ 
#define ADC_AWDG_CHANNEL_VBAT_DIV3           ADC_AWDG1CR_AWDG1_CHN14                        /**< ADC 模拟看门狗监测通道VBAT/3 */ 
#define ADC_AWDG_CHANNEL_VDDA_DIV3           ADC_AWDG1CR_AWDG1_CHN14                        /**< ADC 模拟看门狗监测通道VDDA/3 */
#define ADC_AWDG_CHANNEL_ALL                 ADC_AWDG1CR_AWDG1_CHN                          /**< ADC 全部转换通道             */ 

/* ADC内部通道使能 */
#define ADC_INTERNAL_CHANNEL_NONE            (0x00000000U)                                  /**< ADC 内部通道全部禁止   */ 
#define ADC_INTERNAL_CHANNEL_VBGREN          ADC_CFG2_VBGREN                                /**< ADC 内部通道VBGR使能   */ 
#define ADC_INTERNAL_CHANNEL_VTSEN           ADC_CFG2_VTSEN                                 /**< ADC 内部通道VTS使能    */ 
#define ADC_INTERNAL_CHANNEL_VBAT_DIV3       ADC_CFG2_VBAT_DIV3                             /**< ADC 内部通道VBAT/3使能 */ 
#define ADC_INTERNAL_CHANNEL_VDDA_DIV3       ADC_CFG2_VDDA_DIV3                             /**< ADC 内部通道VDDA/3使能 */ 

/* ADC中断源定义：IER中断寄存器 */
#define ADC_INTERRUPT_EOSAMP                 ADC_IER_EOSAMPIE                               /**< ADC采样结束中断            */
#define ADC_INTERRUPT_EOC                    ADC_IER_EOCIE                                  /**< ADC单通道转换完成中断      */
#define ADC_INTERRUPT_EOS                    ADC_IER_EOSIE                                  /**< ADC通道序列转换完成中断    */
#define ADC_INTERRUPT_OVRN                   ADC_IER_OVRNIE                                 /**< ADC数据溢出中断            */
#define ADC_INTERRUPT_AWDG1                  ADC_IER_AWDG1IE                                /**< ADC模拟看门狗1电压监控中断 */
#define ADC_INTERRUPT_EOCAL                  ADC_IER_EOCALIE                                /**< ADC校准结束中断            */

/* ADC状态定义：ISR状态寄存器 */
#define ADC_FLAG_EOSAMP                      ADC_ISR_EOSAMP                                 /**< ADC采样结束状态            */
#define ADC_FLAG_EOC                         ADC_ISR_EOC                                    /**< ADC单通道转换完成状态      */
#define ADC_FLAG_EOS                         ADC_ISR_EOS                                    /**< ADC通道序列转换完成状态    */
#define ADC_FLAG_OVRN                        ADC_ISR_OVRN                                   /**< ADC数据溢出状态            */
#define ADC_FLAG_AWDG1                       ADC_ISR_AWDG1                                  /**< ADC模拟看门狗1监控电压状态 */
#define ADC_FLAG_EOCAL                       ADC_ISR_EOCAL                                  /**< ADC校准状态                */
#define ADC_FLAG_ALL                         (ADC_ISR_EOSAMP | ADC_ISR_EOC | ADC_ISR_EOS \
                                            | ADC_ISR_OVRN | ADC_ISR_AWDG1 | ADC_ISR_EOCAL) /**< ADC全部状态                */

/* VBGR校准参数定义 */  
#define VBGR_CAL_ADDR                        ((uint16_t*)(BGR_CAL))                         /**< VBGR校准参数存储地址       */
#define VBGR_CAL_VREF                        (3300U)                                        /**< VBGR校准采用参考电压：3.3V */

/* 温度传感器校准参数定义 */ 
#define TS_CAL_ADDR_25                       ((uint16_t*)(TS_CAL_25))                       /**< 温度传感器校准参数存储地址：25℃  */
#define TS_CAL_ADDR_85                       ((uint16_t*)(TS_CAL_85))                       /**< 温度传感器校准参数存储地址：85℃  */
#define TS_CAL_TEMP_25                       ((int32_t)25U)                                 /**< 温度传感器校准温度：25℃          */
#define TS_CAL_TEMP_85                       ((int32_t)85U)                                 /**< 温度传感器校准温度：85℃          */
#define TS_CAL_VREF                          (3300U)                                        /**< 温度传感器校准采用参考电压：3.3V */

/* 等待内部通道的启动稳定时间 
   VBGR通道启动稳定时间                  15US
   VTS通道启动稳定时间                   18US
   VBAT_DIV3和VDDA_DIV3通道启动稳定时间  15US
   配置多个内部通道时，等待最大启动稳定时间即可
*/
#define ADC_VBGR_CHANNEL_DELAY               (15U)                                          /**< VBGR通道启动稳定时间 */
#define ADC_VTS_CHANNEL_DELAY                (18U)                                          /**< VTS通道启动稳定时间 */
#define ADC_VBAT_DIV3_CHANNEL_DELAY          (15U)                                          /**< VBAT/3通道启动稳定时间 */
#define ADC_VDDA_DIV3_CHANNEL_DELAY          (15U)                                          /**< VDDA/3通道启动稳定时间 */

/* ADC使能稳定时间 
   当ADC_CK时钟大于等于6MHz，需等待2.5us稳定时间
   当ADC_CK时钟小于6MHz，需等待17个ADC时钟周期稳定时间  
*/
#define ADC_EN_DELAY                         (3U)                                           /**< ADC使能稳定时间 */

/* ADC参考电压源 */
#define ADC_REFERENCE_VREFBUF                (0x00000000U)                                  /**< VRFEBUF输出作为参考电压源，需使能VREFBUF，配置PA0引脚为模拟模式，外接1uF+0.1uF电容 */
#define ADC_REFERENCE_VREFP                  (0x00000000U)                                  /**< VREF+引脚输入作为参考电压源，配置PA0引脚为模拟模式 */
#define ADC_REFERENCE_VDDA                   ADC_CFG2_REF                                   /**< VDDA作为参考电压源                                 */

/* ADC最大采样值 */
#define ADC_CONVER_SCALE                     (4095U)                                        /**< ADC最大采样值，用于ADC电压转换计算 */


/**
* @brief  根据ADC采集到的温度传感器数据，计算温度
* @param  VREF 参考电压
* @param  TS_DATA ADC采集的温度传感器电压值   
* @retval 温度传感器采集的温度
*/
#define ADC_CALC_TEMPERATURE(VREF, TS_DATA)                                       \
             ((((((int32_t)((TS_DATA * VREF) / TS_CAL_VREF)                       \
                - (int32_t) *TS_CAL_ADDR_25))                                     \
                * (int32_t)(TS_CAL_TEMP_85 - TS_CAL_TEMP_25))                     \
                / (int32_t)((int32_t)*TS_CAL_ADDR_85 - (int32_t)*TS_CAL_ADDR_25)) \
                + TS_CAL_TEMP_25)

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup ADC_External_Functions ADC External Functions
* @brief    ADC对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  使能ADC
* @retval 无
*/
__STATIC_INLINE void std_adc_enable(void)
{
    ADC->CR = (ADC_CR_ADEN);
}

/** 
* @brief  禁止ADC
* @retval 无
*/
__STATIC_INLINE void std_adc_disable(void)
{
    ADC->CR = (ADC_CR_ADDIS);
}

/** 
* @brief  获取ADC使能位状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示ADC处于使能状态
*             @arg false：表示ADC处于禁止状态
*/

__STATIC_INLINE bool std_adc_get_enable_status(void)
{
    return ((ADC->CR & ADC_CR_ADEN) == ADC_CR_ADEN);
}

/** 
* @brief  使能ADC的DMA传输  
* @retval 无
*/
__STATIC_INLINE void std_adc_dma_enable(void)
{
    ADC->CFG1 |= (ADC_CFG1_DMAEN);
}

/** 
* @brief  禁止ADC的DMA传输  
* @retval 无
*/
__STATIC_INLINE void std_adc_dma_disable(void)
{
    ADC->CFG1 &= (~ADC_CFG1_DMAEN);
}

/** 
* @brief  获取ADC的DMA位使能状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示ADC的DMA已使能
*             @arg false：表示ADC的DMA未使能
*/
__STATIC_INLINE bool std_adc_get_dma_status(void)
{
    return((ADC->CFG1 & ADC_CFG1_DMAEN) == ADC_CFG1_DMAEN);
}

/** 
* @brief  配置ADC时钟源
* @param  clock_src ADC时钟源配置
*             @arg  ADC_SYNC_CLK_PCLK_DIV1：PCLK不分频
*             @arg  ADC_SYNC_CLK_PCLK_DIV2：PCLK 2分频
*             @arg  ADC_SYNC_CLK_PCLK_DIV4：PCLK 4分频
*             @arg  ADC_ASYNC_CLK_KCLK：KCLK
* @retval 无
*/
__STATIC_INLINE void std_adc_clock_source_config(uint32_t clock_src)
{
    MODIFY_REG(ADC->CFG2, ADC_CFG2_CKSRC, clock_src);
}

/** 
* @brief  配置ADC异步时钟分频
* @param  presc ADC异步时钟源分频系数
*             @arg  ADC_ASYNC_CLK_DIV1：ADC_KCLK不分频
*             @arg  ADC_ASYNC_CLK_DIV2：ADC_KCLK 2分频
*             @arg  ADC_ASYNC_CLK_DIV4：ADC_KCLK 4分频
*             @arg ...
*             @arg  ADC_ASYNC_CLK_DIV128：ADC_KCLK 128分频
* @retval 无
*/
__STATIC_INLINE void std_adc_asynchronous_clock_config(uint32_t presc)
{
    MODIFY_REG(ADC->CFG2, ADC_CFG2_PRESC, presc);
}

/** 
* @brief  使能ADC校准
* @note   当ADEN=1，ADC稳定后，且START=0、STOP=0、ADDIS=0，才允许通过软件将CALEN位置1
* @retval 无
*/
__STATIC_INLINE void std_adc_calibration_enable(void)
{
    ADC->CR = (ADC_CR_CALEN);
}

/** 
* @brief  启动ADC转换 
* @retval 无
*/
__STATIC_INLINE void std_adc_start_conversion(void)
{
    ADC->CR = (ADC_CR_START);
}

/** 
* @brief  获取ADC工作状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示ADC正处于工作状态
*             @arg false：表示ADC处于未工作状态
*/
__STATIC_INLINE bool std_adc_get_conversion_status(void)
{
    return ((ADC->CR & ADC_CR_START) == ADC_CR_START);
}

/** 
* @brief  ADC停止转换
* @note   仅当START=1且ADDIS=0时，软件将STOP位置1生效
* @retval 无
*/
__STATIC_INLINE void std_adc_stop_conversion(void)
{
    ADC->CR = (ADC_CR_STOP);
}

/** 
* @brief  ADC中断使能
* @param  interrupt ADC中断源   
*             @arg ADC_INTERRUPT_EOSAMP
*             @arg ADC_INTERRUPT_EOC
*             @arg ADC_INTERRUPT_EOS
*             @arg ADC_INTERRUPT_OVRN
*             @arg ADC_INTERRUPT_AWDG1
*             @arg ADC_INTERRUPT_EOCAL
* @retval 无
*/
__STATIC_INLINE void std_adc_interrupt_enable(uint32_t interrupt)
{
    ADC->IER |= (interrupt);
}

/** 
* @brief  ADC中断禁止
* @param  interrupt ADC中断源   
*             @arg ADC_INTERRUPT_EOSAMP
*             @arg ADC_INTERRUPT_EOC
*             @arg ADC_INTERRUPT_EOS
*             @arg ADC_INTERRUPT_OVRN
*             @arg ADC_INTERRUPT_AWDG1
*             @arg ADC_INTERRUPT_EOCAL
* @retval 无
*/
__STATIC_INLINE void std_adc_interrupt_disable(uint32_t interrupt)
{
    ADC->IER &= (~interrupt);
}

/** 
* @brief  获取ADC中断源使能状态
* @param  interrupt ADC中断源信息 
*             @arg ADC_INTERRUPT_EOSAMP
*             @arg ADC_INTERRUPT_EOC
*             @arg ADC_INTERRUPT_EOS
*             @arg ADC_INTERRUPT_OVRN
*             @arg ADC_INTERRUPT_AWDG1
*             @arg ADC_INTERRUPT_EOCAL
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示指定的中断使能
*             @arg false：表示指定的中断未使能
*/

__STATIC_INLINE bool std_adc_get_interrupt_enable(uint32_t interrupt)
{
    return((ADC->IER & (interrupt)) == (interrupt));
}

/** 
* @brief  获取ADC标志状态
* @param  flag 获取ADC标志
*             @arg ADC_FLAG_EOSAMP
*             @arg ADC_FLAG_EOC
*             @arg ADC_FLAG_EOS
*             @arg ADC_FLAG_OVRN
*             @arg ADC_FLAG_AWDG1
*             @arg ADC_FLAG_EOCAL
* @retval bool 返回标志位状态
*             @arg true： 表示当前标志为置位状态
*             @arg false：表示当前标志为清除状态
*/
__STATIC_INLINE bool std_adc_get_flag(uint32_t flag)
{
    return((ADC->ISR & (flag)) == (flag));
}

/** 
* @brief  清除ADC标志
* @param  flag 清除ADC标志
*             @arg ADC_FLAG_EOSAMP
*             @arg ADC_FLAG_EOC
*             @arg ADC_FLAG_EOS
*             @arg ADC_FLAG_OVRN
*             @arg ADC_FLAG_AWDG1
*             @arg ADC_FLAG_EOCAL
* @retval 无
*/
__STATIC_INLINE void std_adc_clear_flag(uint32_t flag)
{
    ADC->ISR = (flag);
}

/** 
* @brief  配置ADC转换模式
* @param  conversion_mode 转换模式选择
*             @arg ADC_SINGLE_CONVER_MODE
*             @arg ADC_CONTINUOUS_CONVER_MODE
*             @arg ADC_DISCONTINUOUS_CONVER_MODE
* @note   当START=0时，软件对此位域执行写操作生效
* @retval 无
*/
__STATIC_INLINE void std_adc_conversion_mode_config(uint32_t conversion_mode)
{
    MODIFY_REG(ADC->CFG1, ADC_CFG1_CONV_MOD, conversion_mode);
}

/** 
* @brief  ADC通道使能
* @param  channel 通道号选择
*             @arg ADC_CHANNEL_NONE
*             @arg ADC_CHANNEL_0
*             @arg ...
*             @arg ADC_CHANNEL_ALL
* @retval 无
*/
__STATIC_INLINE void std_adc_fix_sequence_channel_enable(uint32_t channel)
{
    ADC->CHCFG |= (channel);
}

/** 
* @brief  ADC通道禁止
* @param  channel 禁止通道选择
*             @arg ADC_CHANNEL_0
*             @arg ADC_CHANNEL_1
*             @arg ...
*             @arg ADC_CHANNEL_ALL
* @retval 无
*/
__STATIC_INLINE void std_adc_fix_sequence_channel_disable(uint32_t channel)
{
    ADC->CHCFG &= (~channel);
}

/** 
* @brief  配置ADC触发方式和极性
* @param  trig_edge 触发极性选择
*             @arg ADC_TRIG_SW(软件触发方式)
*             @arg ADC_TRIG_HW_EDGE_RISING
*             @arg ADC_TRIG_HW_EDGE_FALLING
*             @arg ADC_TRIG_HW_EDGE_BOTH
* @retval 无
*/
__STATIC_INLINE void std_adc_trig_edge_config(uint32_t trig_edge)
{
    MODIFY_REG(ADC->CFG1, ADC_CFG1_TRIGEN, trig_edge);
}

/** 
* @brief  配置ADC外部触发源
* @param  trig_source 外部触发源性选择
*             @arg ADC_EXTRIG_TIM3_TRGO
*             @arg ADC_EXTRIG_TIM4_TRGO
*             @arg ADC_EXTRIG_TIM5_TRGO
*             @arg ADC_EXTRIG_TIM8_TRGO
*             @arg ADC_EXTRIG_EXTI2
*             @arg ADC_EXTRIG_EXTI11
* @retval 无
*/
__STATIC_INLINE void std_adc_external_trig_source_config(uint32_t trig_source)
{
    MODIFY_REG(ADC->CFG1, ADC_CFG1_TRIG_SEL, trig_source);
}

/** 
* @brief  ADC采样时间参数1配置
* @param  sample_time 采样时间选择
*           @arg ADC_SAMPTIME_3CYCLES
*           @arg ...
*           @arg ADC_SAMPTIME_1919CYCLES 
* @retval 无
*/
__STATIC_INLINE void std_adc_sampt1_time_config(uint32_t sample_time)
{
    MODIFY_REG(ADC->SAMPT, ADC_SAMPT_SAMPT1, sample_time);
}

/** 
* @brief  ADC采样时间参数2配置
* @param  sample_time 采样时间选择
*           @arg ADC_SAMPTIME_3CYCLES
*           @arg ...
*           @arg ADC_SAMPTIME_1919CYCLES
* @retval 无
*/
__STATIC_INLINE void std_adc_sampt2_time_config(uint32_t sample_time)
{
    MODIFY_REG(ADC->SAMPT, ADC_SAMPT_SAMPT2, sample_time << ADC_SAMPT_SAMPT2_POS);
}

/** 
* @brief  配置ADC通道采样时间
* @param  samptx 采样时间参数组选择
*           @arg ADC_SAMPTIME_GROUP_1
*           @arg ADC_SAMPTIME_GROUP_2
* @param  channel 通道采样时间选择
*           @arg ADC_CHANNEL_0
*           @arg ADC_CHANNEL_1
*           @arg ...
*           @arg ADC_CHANNEL_VBAT_DIV3
*           @arg ADC_CHANNEL_VDDA_DIV3
* @retval 无
*/
__STATIC_INLINE void std_adc_channel_sample_time_select(uint32_t samptx, uint32_t channel)
{
    if(samptx == ADC_SAMPTIME_GROUP_1)
    {
        ADC->SAMPT &= (~(channel << ADC_SAMPT_SAMPT_SEL_POS));
    }
    else
    {
        ADC->SAMPT |= (channel << ADC_SAMPT_SAMPT_SEL_POS);
    }
}

/** 
* @brief  配置ADC校准系数
* @param  calibration_factor 参数范围为0x00~0x3F
* @retval 无
*/
__STATIC_INLINE void std_adc_calibration_factor_config(uint32_t calibration_factor)
{
    ADC->CALFACT = calibration_factor;
}

/** 
* @brief  使能ADC等待模式
* @note   用于避免数据未及时读取，转换溢出
* @retval 无
*/
__STATIC_INLINE void std_adc_wait_mode_enable(void)
{
    ADC->CFG1 |= (ADC_CFG1_WAIT_MOD);
}

/** 
* @brief  禁止ADC等待模式
* @retval 无
*/
__STATIC_INLINE void std_adc_wait_mode_disable(void)
{
    ADC->CFG1 &= (~ADC_CFG1_WAIT_MOD);
}

/** 
* @brief  配置通道序列扫描方向
* @param  dir ADC通道扫描方向
*             @arg ADC_SCAN_DIR_FORWARD
*             @arg ADC_SCAN_DIR_BACKWARD
* @retval 无
*/
__STATIC_INLINE void std_adc_scan_direction_config(uint32_t dir)
{
    MODIFY_REG(ADC->CFG1, ADC_CFG1_SDIR, dir);
}

/** 
* @brief  配置ADC数据溢出管理方式
* @param  ovrn_mode ADC数据溢出管理方式
*             @arg ADC_OVRN_MODE_PRESERVED
*             @arg ADC_OVRN_MODE_OVERWRITTEN
* @retval 无
*/
__STATIC_INLINE void std_adc_ovrn_mode_config(uint32_t ovrn_mode)
{
    MODIFY_REG(ADC->CFG1, ADC_CFG1_OVRN_MOD, ovrn_mode);
}

/** 
* @brief  ADC内部通道使能
* @param  inter_channel ADC内部通道
*             @arg ADC_INTERNAL_CHANNEL_VBGREN
*             @arg ADC_INTERNAL_CHANNEL_VTSEN
*             @arg ADC_INTERNAL_CHANNEL_VBAT_DIV3
*             @arg ADC_INTERNAL_CHANNEL_VDDA_DIV3
* @note   VBAT_DIV3和VDDA_DIV3共用1个内部通道，因此要配置ADC_INTERNAL_CHANNEL_VBAT_DIV3
*         或ADC_INTERNAL_CHANNEL_VDDA_DIV3前，需先禁止这两个通道
* @retval 无
*/
__STATIC_INLINE void std_adc_internal_channel_enable(uint32_t inter_channel)
{
    ADC->CFG2 |= (inter_channel);
}

/** 
* @brief  ADC内部通道禁止
* @param  inter_channel ADC内部通道
*             @arg ADC_INTERNAL_CHANNEL_VBGREN
*             @arg ADC_INTERNAL_CHANNEL_VTSEN
*             @arg ADC_INTERNAL_CHANNEL_VBAT_DIV3
*             @arg ADC_INTERNAL_CHANNEL_VDDA_DIV3
* @retval 无
*/
__STATIC_INLINE void std_adc_internal_channel_disable(uint32_t inter_channel)
{
    ADC->CFG2 &= (~inter_channel);
}

/** 
* @brief  选择ADC模拟看门狗监控通道
* @param  channel ADC看门狗监控通道选择
*             @arg ADC_AWDG_CHANNEL_NONE
*             @arg ADC_AWDG_CHANNEL_0
*             @arg ...
*             @arg ADC_AWDG_CHANNEL_ALL
* @retval 无
*/
__STATIC_INLINE void std_adc_analog_watchdog_monit_channel(uint32_t channel)
{
    MODIFY_REG(ADC->AWDG1CR, ADC_AWDG1CR_AWDG1_CHN, channel);
}

/** 
* @brief  配置看门狗监控通道电压阈值
* @param  high_threshold 阈值上限选择范围为 0x000~0xFFF
* @param  low_threshold  阈值下限选择范围为 0x000~0xFFF
* @retval 无
*/
__STATIC_INLINE void std_adc_analog_watchdog_thresholds_config(uint32_t high_threshold, uint32_t low_threshold)
{
    MODIFY_REG(ADC->AWDG1TR, (ADC_AWDG1TR_AWDG1_LT | ADC_AWDG1TR_AWDG1_HT), (high_threshold << 16U) | (low_threshold >> 0U));
}

/** 
* @brief  获取ADC采样值
* @retval ADC转换值
*/
__STATIC_INLINE uint16_t std_adc_get_conversion_value(void)
{
    return ((uint16_t)(ADC->DR));
}

/** 
* @brief  使能低频触发
* @retval 无
*/
__STATIC_INLINE void std_adc_low_frequency_trig_enable(void)
{
    ADC->CFG2 |= (ADC_CFG2_LFTRG);
}

/** 
* @brief  禁止低频触发
* @retval 无
*/
__STATIC_INLINE void std_adc_low_frequency_trig_disable(void)
{
    ADC->CFG2 &= (~ADC_CFG2_LFTRG);
}

/** 
* @brief  ADC参考电压源设置
*             @arg ADC_REFERENCE_VREFBUF
*             @arg ADC_REFERENCE_VREFP
*             @arg ADC_REFERENCE_VDDA
* @note   VRFEBUF输出作为参考电压源，需使能VREFBUF，配置PA0引脚为模拟模式，外接1uF+0.1uF电容;
*         VREF+引脚输入作为参考电压源，配置PA0引脚为模拟模式;
* @retval 无
*/
__STATIC_INLINE void std_adc_set_reference_source(uint32_t reference_voltage)
{
    MODIFY_REG(ADC->CFG2, ADC_CFG2_REF, reference_voltage);
}

/* ADC初始化函数 */
void std_adc_init(std_adc_init_t *adc_init_param);
/* ADC结构体初始化*/
void std_adc_struct_init(std_adc_init_t *adc_init_struct);
/* ADC去初始化函数 */
void std_adc_deinit(void);

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

#endif /* CIU32L051_STD_ADC_H */
