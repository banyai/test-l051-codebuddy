/************************************************************************************************/
/**
* @file               ciu32l051_std_tim.h          
* @author             MCU Ecosystem Development Team
* @brief              TIM STD库驱动头文件。
*                     提供TIM相关的STD库操作函数声明、数据类型以及常量的定义。 
*                                 
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_TIM_H
#define CIU32L051_STD_TIM_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup TIM TIM
* @brief    通用定时器/基本定时器的STD库驱动
* @{
*
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
* @defgroup TIM_Types TIM Types
* @brief    TIM数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  TIM基本参数配置结构体定义
*/
typedef struct
{ 
    uint32_t prescaler;              /**< TIM时钟的预分频参数，其值必须在0x0000~0xFFFF之间            */
                                   
    uint32_t counter_mode;           /**< 计数器模式选择
                                              @arg TIM_COUNTER_MODE_UP ...                            */
                                   
    uint32_t period;                 /**< 自动重载值，其值必须在0x0000~0xFFFF之间                     */
                                   
    uint32_t clock_div;              /**< TIM时钟分频参数
                                              @arg TIM_CLOCK_DTS_DIV1 ...                             */
                                   
    uint32_t auto_reload_preload;    /**< 自动重载预加载
                                              @arg TIM_AUTORELOAD_PRE_DISABLE ...                     */
}std_tim_basic_init_t;


/**
* @brief  TIM输入捕获参数配置结构体定义
*/
typedef struct
{
    uint32_t  input_capture_pol;         /**< 输入信号的有效边沿选择                           
                                                  @arg TIM_INPUT_POL_RISING ...               */
                                
    uint32_t input_capture_sel;          /**< 输入模式定义
                                                  @arg TIM_INPUT_CAPTURE_SEL_DIRECTTI ...     */
                                
    uint32_t input_capture_prescaler;    /**< 输入捕获预分频定义
                                                  @arg TIM_INPUT_CAPTURE_PSC_DIV1 ...         */
                                
    uint32_t input_capture_filter;       /**< 输入捕获滤波器定义，其值必须在0x0~0x7之间       */
    
}std_tim_input_capture_init_t;      


/**
* @brief  TIM输出比较参数配置结构体定义
*/
typedef struct
{
    uint32_t output_compare_mode;        /**< TIM输出比较模式定义
                                                  @arg TIM_OUTPUT_MODE_ACTIVE ...                           */
                                   
    uint32_t pulse;                      /**< TIM载入捕获比较寄存器的脉冲值，其值必须在0x0000~0xFFFF之间    */    
                                   
    uint32_t output_pol;                 /**< 输出极性定义
                                                  @arg TIM_OUTPUT_POL_HIGH ...                              */                                   
    
    uint32_t output_preloadccx;           /**< 通道预加载使能定义                                                
                                                  @arg TIM_OUTPUT_PRECC_ENABLE ...                          */
                                                  
    uint32_t output_fast_mode;           /**< 快速模式定义
                                                  @arg  TIM_OUTPUT_FAST_ENABLE ... 
                                                  @note 该参数仅在PWM1和PWM2模式下有效                      */    
}std_tim_output_compare_init_t;


/**
* @}
*/
  
/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup TIM_Constants TIM Constants 
* @brief    TIM常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* TIM计数模式定义 */
#define TIM_COUNTER_MODE_UP                (0x00000000U)                      /**< 向上计数                      */
#define TIM_COUNTER_MODE_DOWN              TIM_CR1_DIR                        /**< 向下计数                      */
#define TIM_COUNTER_MODE_CENT_MODE1        TIM_CR1_CMS_CENTER_UP              /**< 中心对齐模式1                 */
#define TIM_COUNTER_MODE_CENT_MODE2        TIM_CR1_CMS_CENTER_DOWN            /**< 中心对齐模式2                 */
#define TIM_COUNTER_MODE_CENT_MODE3        TIM_CR1_CMS_CENTER_UP_DOWN         /**< 中心对齐模式3                 */

/* TIM计数方向定义 */
#define TIM_COUNTER_UP                     (0x00000000U)                      /**< 计数方向为:向上               */
#define TIM_COUNTER_DOWN                   TIM_CR1_DIR                        /**< 计数方向为:向下               */

/* TIM自动重载预装载状态定义 */
#define TIM_AUTORELOAD_PRE_DISABLE         (0x00000000U)                      /**< 禁止寄存器预装载功能          */
#define TIM_AUTORELOAD_PRE_ENABLE          TIM_CR1_ARPE                       /**< 使能寄存器预装载功能          */

/* TIM更新事件源选择 */
#define TIM_UPDATE_SOURCE_REGULAR          (0x00000000U)                      /**< 计数上溢或下溢触发                       */
#define TIM_UPDATE_SOURCE_COUNTER          TIM_CR1_URS                        /**< 计数上溢或下溢、UG置位、从模式控制器触发 */


/* TIM时钟分频 */
#define TIM_CLOCK_DTS_DIV1                 (0x00000000U)                      /**< tDTS=tTIMx_KCLK          */
#define TIM_CLOCK_DTS_DIV2                 TIM_CR1_CLK_DIV2                   /**< tDTS=2*tTIMx_KCLK        */
#define TIM_CLOCK_DTS_DIV4                 TIM_CR1_CLK_DIV4                   /**< tDTS=4*tTIMx_KCLK        */

/* TIM通道定义 */
#define TIM_CHANNEL_1                      (0x00U)                            /**< 捕获/比较1定义            */
#define TIM_CHANNEL_2                      (0x01U)                            /**< 捕获/比较2定义            */
#define TIM_CHANNEL_3                      (0x02U)                            /**< 捕获/比较3定义            */
#define TIM_CHANNEL_4                      (0x03U)                            /**< 捕获/比较4定义            */

/* TIM输入通道极性定义 */
#define TIM_INPUT_POL_RISING               (0x00000000U)                        /**< 未反向/上升沿触发             */
#define TIM_INPUT_POL_FALLING              TIM_CCEN_CC1P                        /**< 反向/下降沿触发               */
#define TIM_INPUT_POL_BOTH                 (TIM_CCEN_CC1P | TIM_CCEN_CC1NP)     /**< 未反向/上升下降均触发         */

/* TIM输入捕获选择 */
#define TIM_INPUT_CAPTURE_SEL_DIRECTTI         TIM_CCM1_CC1S_DIRECTTI             /**< TIM输入1, 2, 3 or 4，且被映射到IC1, IC2, IC3 or IC4（一一对应） */
#define TIM_INPUT_CAPTURE_SEL_INDIRECTTI       TIM_CCM1_CC1S_INDIRECTTI           /**< TIM输入1, 2, 3 or 4，且被映射到IC2, IC1, IC4 or IC3（一一对应） */
#define TIM_INPUT_CAPTURE_SEL_TRC              TIM_CCM1_CC1S_TRC                  /**< TIM输入1, 2, 3 or 4，且被映射到TRC                              */

/* TIM输入捕获预分频参数定义 */
#define TIM_INPUT_CAPTURE_PSC_DIV1             (0x00000000U)                      /**< 无预分频器，捕获输入上每检测到一个边沿便执行捕获 */
#define TIM_INPUT_CAPTURE_PSC_DIV2             TIM_CCM1_IC1PSC_DIV2               /**< 每发生2个事件执行一次捕获                        */
#define TIM_INPUT_CAPTURE_PSC_DIV4             TIM_CCM1_IC1PSC_DIV4               /**< 每发生4个事件执行一次捕获                        */
#define TIM_INPUT_CAPTURE_PSC_DIV8             TIM_CCM1_IC1PSC_DIV8               /**< 每发生8个事件执行一次捕获                        */

/* TIM输出比较预装载状态定义 */                                                                                        
#define TIM_OUTPUT_PRECC_DISABLE           (0x00000000U)                      /**< 禁止输出比较预装载模式        */
#define TIM_OUTPUT_PRECC_ENABLE            TIM_CCM1_OC1PE                     /**< 使能输出比较预装载模式        */

/* TIM输出快速状态定义 */                                                                                        
#define TIM_OUTPUT_FAST_DISABLE            (0x00000000U)                      /**< 禁止输出比较快速模式          */
#define TIM_OUTPUT_FAST_ENABLE             TIM_CCM1_OC1FE                     /**< 使能输出比较快速模式          */

/* TIM输出比较极性定义 */
#define TIM_OUTPUT_POL_HIGH                (0x00000000U)                      /**< 比较输出极性:高电平为有效电平      */
#define TIM_OUTPUT_POL_LOW                 TIM_CCEN_CC1P                      /**< 比较输出极性:低电平为有效电平      */

/* TIM输出比较参数定义 */   
#define TIM_OUTPUT_MODE_FROZEN                  (0x00000000U)                                /**< 冻结                          */
#define TIM_OUTPUT_MODE_ACTIVE                  TIM_CCM1_OC1M_ACTIVE                         /**< 通道1设置为匹配时输出有效电平 */
#define TIM_OUTPUT_MODE_INACTIVE                TIM_CCM1_OC1M_INACTIVE                       /**< 通道1设置为匹配时输出无效电平 */
#define TIM_OUTPUT_MODE_TOGGLE                  TIM_CCM1_OC1M_TOGGLE                         /**< 翻转                          */
#define TIM_OUTPUT_MODE_FORCED_INACTIVE         TIM_CCM1_OC1M_FORCED_INACTIVE                /**< 强制变为无效电平              */
#define TIM_OUTPUT_MODE_FORCED_ACTIVE           TIM_CCM1_OC1M_FORCED_ACTIVE                  /**< 强制变为有效电平              */
#define TIM_OUTPUT_MODE_PWM1                    TIM_CCM1_OC1M_PWM1                           /**< PWM模式1                      */
#define TIM_OUTPUT_MODE_PWM2                    TIM_CCM1_OC1M_PWM2                           /**< PWM模式2                      */

/* TIM ETR极性定义 */
#define TIM_ETR_POL_HIGH                   (0x00000000U)                      /**< ETR高电平或上升沿有效         */
#define TIM_ETR_POL_LOW                    TIM_SMC_ETP                        /**< ETR低电平或下降沿有效         */

/* TIM ETR预分频参数 */
#define TIM_ETR_PSC_DIV1                   (0x00000000U)                      /**< 预分频器关闭                  */
#define TIM_ETR_PSC_DIV2                   TIM_SMC_ET_PRE_DIV2                /**< ETR输入源预分频系数为2        */
#define TIM_ETR_PSC_DIV4                   TIM_SMC_ET_PRE_DIV4                /**< ETR输入源预分频系数为4        */
#define TIM_ETR_PSC_DIV8                   TIM_SMC_ET_PRE_DIV8                /**< ETR输入源预分频系数为8        */

/*  TIM时钟源选择 */ 
#define TIM_CLKSRC_INT                     (0x00000000U)                      /**< TIM时钟源：内部时钟           */
#define TIM_CLKSRC_ETR_MODE1               TIM_SMC_SM_SEL_EXT_MODE1           /**< TIM时钟源：外部时钟源模式1    */
#define TIM_CLKSRC_ETR_MODE2               TIM_SMC_ECEN                       /**< TIM时钟源：外部时钟源模式2    */

/* TIM时钟极性定义 */
#define TIM_CLK_ETR_POL_HIGH               (0x00000000U)                      /**< ETR时钟源的极性：高有效       */
#define TIM_CLK_ETR_POL_LOW                TIM_SMC_ETP                        /**< ETR时钟源的极性：低有效       */
#define TIM_CLK_TIX_POL_RISING             (0x00000000U)                      /**< TIx时钟源的极性：上升沿有效   */
#define TIM_CLK_TIX_POL_FALLING            TIM_CCEN_CC1P                      /**< TIx时钟源的极性：下降沿有效   */
#define TIM_CLK_TIX_POL_BOTH               (TIM_CCEN_CC1P | TIM_CCEN_CC1NP)   /**< TIx时钟源的极性：双沿有效     */

/* TIM DMA请求生成事件源 */
#define TIM_GEN_DMA_REQ_CCX                (0x00000000U)                     /**< 发生CCx事件生成DMA请求      */
#define TIM_GEN_DMA_REQ_UPDATE             (TIM_CR2_CC_DMASEL)               /**< 发生更新事件生成DMA请求     */

/* TIM事件源 */
#define TIM_EVENT_SRC_UPDATE               TIM_EVTG_UG                       /**< 重新初始化计数器并生成一个更新事件      */
#define TIM_EVENT_SRC_CC1                  TIM_EVTG_CC1G                     /**< 在通道1上生成一个捕获/比较事件          */
#define TIM_EVENT_SRC_CC2                  TIM_EVTG_CC2G                     /**< 在通道2上生成一个捕获/比较事件          */ 
#define TIM_EVENT_SRC_CC3                  TIM_EVTG_CC3G                     /**< 在通道3上生成一个捕获/比较事件          */ 
#define TIM_EVENT_SRC_CC4                  TIM_EVTG_CC4G                     /**< 在通道4上生成一个捕获/比较事件          */ 
#define TIM_EVENT_SRC_TRIG                 TIM_EVTG_TG                       /**< 生成一个触发事件                        */

/* TIM中断定义 */
#define TIM_INTERRUPT_UPDATE               TIM_DIER_UIE                       /**< 更新中断                */
#define TIM_INTERRUPT_CC1                  TIM_DIER_CC1IE                     /**< 捕获/比较1中断          */
#define TIM_INTERRUPT_CC2                  TIM_DIER_CC2IE                     /**< 捕获/比较1中断2         */
#define TIM_INTERRUPT_CC3                  TIM_DIER_CC3IE                     /**< 捕获/比较1中断3         */
#define TIM_INTERRUPT_CC4                  TIM_DIER_CC4IE                     /**< 捕获/比较1中断4         */
#define TIM_INTERRUPT_TRIG                 TIM_DIER_TIE                       /**< 触发中断                */

/* TIM DMA源 */
#define TIM_DMA_REQ_UPDATE                  TIM_DIER_UDMAEN                   /**< 更新事件触发DMA请求      */
#define TIM_DMA_REQ_CC1                     TIM_DIER_CC1_DMAEN                /**< 捕获/比较1触发DMA请求    */
#define TIM_DMA_REQ_CC2                     TIM_DIER_CC2_DMAEN                /**< 捕获/比较2触发DMA请求    */
#define TIM_DMA_REQ_CC3                     TIM_DIER_CC3_DMAEN                /**< 捕获/比较3触发DMA请求    */
#define TIM_DMA_REQ_CC4                     TIM_DIER_CC4_DMAEN                /**< 捕获/比较4触发DMA请求    */
#define TIM_DMA_REQ_TRIG                    TIM_DIER_TDMAEN                   /**< 触发事件触发DMA请求      */

/* TIM标志定义 */
#define TIM_FLAG_ALL                       (0x1E5FU)                          /**< 所有事件标志              */
#define TIM_FLAG_UPDATE                    TIM_SR_UIF                         /**< 更新中断标志              */
#define TIM_FLAG_CC1                       TIM_SR_CC1IF                       /**< 捕获/比较1事件标志        */
#define TIM_FLAG_CC2                       TIM_SR_CC2IF                       /**< 捕获/比较2事件标志        */
#define TIM_FLAG_CC3                       TIM_SR_CC3IF                       /**< 捕获/比较3事件标志        */
#define TIM_FLAG_CC4                       TIM_SR_CC4IF                       /**< 捕获/比较4事件标志        */
#define TIM_FLAG_TRIG                      TIM_SR_TIF                         /**< 触发事件标志              */
#define TIM_FLAG_CC1OF                     TIM_SR_CC1OF                       /**< 捕获/比较1重复捕获标志    */
#define TIM_FLAG_CC2OF                     TIM_SR_CC2OF                       /**< 捕获/比较2重复捕获标志    */
#define TIM_FLAG_CC3OF                     TIM_SR_CC3OF                       /**< 捕获/比较3重复捕获标志    */
#define TIM_FLAG_CC4OF                     TIM_SR_CC4OF                       /**< 捕获/比较3重复捕获标志    */

/* TIM清除OCxREF输出的输入源 */
#define TIM_CLEAR_INPUT_SRC_ETR            TIM_SMC_OCCS                     /**< 清除OCREF输出的信号源与ETRF相连   */
                                 
#define TIM_CLEAR_INPUT_SRC_COMP1          (0x00000000U)                    /**< OCREF_CLR_INPUT连接到COMP1的输出  */
#define TIM_CLEAR_INPUT_SRC_COMP2          TIM_CFG_OCREF_CLR                /**< OCREF_CLR_INPUT连接到COMP2的输出  */

/* TIM清除OCxREF输出的信号源极性定义 */
#define TIM_CLEAR_INPUT_POL_HIGH           (0x00000000U)                    /**< ETR引脚极性:高电平或上升沿有效   */
#define TIM_CLEAR_INPUT_POL_LOW            TIM_SMC_ETP                      /**< ETR引脚极性:低电平或下降沿有效   */

/* TIM正交编码模式选择 */
#define TIM_ENCODER_MODE_TI1               TIM_SMC_SM_SEL_ENCODE_TI1          /**< 正交编码模式1, x2模式, 
                                                                                   计数器根据TI1FP1电平在TI2FP2边沿递增/递减计数                        */
#define TIM_ENCODER_MODE_TI2               TIM_SMC_SM_SEL_ENCODE_TI2          /**< 正交编码模式2, x2模式, 
                                                                                   计数器根据TI2FP2电平在TI1FP1边沿递增/递减计数                        */
#define TIM_ENCODER_MODE_TI12              TIM_SMC_SM_SEL_ENCODE_TI12         /**< 正交编码模式3, x4模式, 
                                                                                   计数器在TI1FP1和TI2FP2的边沿计数，计数的方向取决于另外一个输入的电平 */

/* TIM主模式选择(TRIG_OUT)参数定义*/
#define TIM_TRIG_OUT_RESET                     (0x00000000U)                         /**< TIM1_EVTG寄存器中的UG位用作触发输出（TRIG_OUT）  */
#define TIM_TRIG_OUT_ENABLE                    TIM_CR2_MM_SEL_ENABLE                 /**< 计数器使能信号CEN用作触发输出（TRIG_OUT）        */
#define TIM_TRIG_OUT_UPDATE                    TIM_CR2_MM_SEL_UPDATE                 /**< 选择更新事件作为触发输出（TRIG_OUT）             */
#define TIM_TRIG_OUT_CC1                       TIM_CR2_MM_SEL_CC1IF                  /**< 捕获或比较匹配，触发输出（TRIG_OUT）             */
#define TIM_TRIG_OUT_OC1REF                    TIM_CR2_MM_SEL_OC1REF                 /**< OC1REF信号用作触发输出(TRIG_OUT)                 */
#define TIM_TRIG_OUT_OC2REF                    TIM_CR2_MM_SEL_OC2REF                 /**< OC2REF信号用作触发输出(TRIG_OUT)                 */
#define TIM_TRIG_OUT_OC3REF                    TIM_CR2_MM_SEL_OC3REF                 /**< OC3REF信号用作触发输出(TRIG_OUT)                 */
#define TIM_TRIG_OUT_OC4REF                    TIM_CR2_MM_SEL_OC4REF                 /**< OC4REF信号用作触发输出(TRIG_OUT)                 */

/* TIM从模式参数定义*/
#define TIM_SLAVE_MODE_DISABLE             (0x00000000U)                                /**< 禁止从模式          */
#define TIM_SLAVE_MODE_RESET               TIM_SMC_SM_SEL_RESET                         /**< 复位模式            */
#define TIM_SLAVE_MODE_GATED               TIM_SMC_SM_SEL_GATED                         /**< 门控模式            */
#define TIM_SLAVE_MODE_TRIG                TIM_SMC_SM_SEL_TRIG                          /**< 触发模式            */

/* TIM触发选择参数定义*/
#define TIM_TRIG_SOURCE_ITR0               TIM_SMC_TS_ITR0                              /**< 内部触发0（ITR0）               */
#define TIM_TRIG_SOURCE_ITR1               TIM_SMC_TS_ITR1                              /**< 内部触发1（ITR1）               */
#define TIM_TRIG_SOURCE_ITR2               TIM_SMC_TS_ITR2                              /**< 内部触发2（ITR2）               */
#define TIM_TRIG_SOURCE_TI1F_ED            TIM_SMC_TS_TI1F_ED                           /**< TI1边沿检测器（TI1F_ED）        */
#define TIM_TRIG_SOURCE_TI1FP1             TIM_SMC_TS_TI1FP1                            /**< 滤波后的定时器输入1（TI1FP1）   */
#define TIM_TRIG_SOURCE_TI2FP2             TIM_SMC_TS_TI2FP2                            /**< 滤波后的定时器输入2（TI1FP2）   */
#define TIM_TRIG_SOURCE_ETRF               TIM_SMC_TS_ETRF                              /**< 外部触发输入（ETRF）            */

/* TIM触发极性参数定义*/
#define TIM_TRIG_ETR_POL_RISING            (0x00000000U)                        /**< ETR触发极性:高电平或上升沿有效               */
#define TIM_TRIG_ETR_POL_FALLING           TIM_SMC_ETP                          /**< ETR触发极性:低电平或下降沿有效               */
#define TIM_TRIG_TIX_POL_RISING            (0x00000000U)                        /**< TIxFPx或TI1F_ED触发极性:高电平或上升沿有效   */
#define TIM_TRIG_TIX_POL_FALLING           TIM_CCEN_CC1P                        /**< TIxFPx或TI1F_ED触发极性:低电平或下降沿有效   */
#define TIM_TRIG_TIX_POL_BOTH              (TIM_CCEN_CC1P | TIM_CCEN_CC1NP)     /**< TIxFPx或TI1F_ED触发极性:上升下降均触发       */
                                                                                       
/* TIM触发预分频定义*/                                                                 
#define TIM_TRIG_PSC_DIV1                  TIM_ETR_PSC_DIV1                   /**< 未使用预分频                */ 
#define TIM_TRIG_PSC_DIV2                  TIM_ETR_PSC_DIV2                   /**< 外部ETR时钟预分频 = 2       */
#define TIM_TRIG_PSC_DIV4                  TIM_ETR_PSC_DIV4                   /**< 外部ETR时钟预分频 = 4       */
#define TIM_TRIG_PSC_DIV8                  TIM_ETR_PSC_DIV8                   /**< 外部ETR时钟预分频 = 8       */

/* TIM ETR定义  */                                                                            
#define TIM_TIM3_ETR_GPIO                  TIM3_AF1_ETR_SEL_GPIO                       /**< TIM3_ETR连接到GPIO            */                                                
#define TIM_TIM3_ETR_COMP1                 TIM3_AF1_ETR_SEL_COMP1                      /**< TIM3_ETR连接到COMP1输出       */
#define TIM_TIM3_ETR_COMP2                 TIM3_AF1_ETR_SEL_COMP2                      /**< TIM3_ETR连接到COMP2输出       */                                                            
#define TIM_TIM3_ETR_LXTAL                 TIM3_AF1_ETR_SEL_LXTAL                      /**< TIM3_ETR连接到LXTAL           */
#define TIM_TIM3_ETR_HXTAL                 TIM3_AF1_ETR_SEL_HXTAL                      /**< TIM3_ETR连接到HXTAL           */
#define TIM_TIM3_ETR_MCO                   TIM3_AF1_ETR_SEL_MCO                        /**< TIM3_ETR连接到MCO             */
#define TIM_TIM3_ETR_RCL                   TIM3_AF1_ETR_SEL_RCL                        /**< TIM3_ETR连接到RCL             */
                                                                    
#define TIM_TIM4_ETR_GPIO                  TIM4_AF1_ETR_SEL_GPIO                       /**< TIM4_ETR连接到GPIO            */                                                  
#define TIM_TIM4_ETR_COMP1                 TIM4_AF1_ETR_SEL_COMP1                      /**< TIM4_ETR连接到COMP1输出       */
#define TIM_TIM4_ETR_COMP2                 TIM4_AF1_ETR_SEL_COMP2                      /**< TIM4_ETR连接到COMP2输出       */                                                           
                                                                                                                                                                                                                        
#define TIM_TIM5_ETR_GPIO                  TIM5_AF1_ETR_SEL_GPIO                       /**< TIM5_ETR连接到GPIO            */                                                   
#define TIM_TIM5_ETR_COMP1                 TIM5_AF1_ETR_SEL_COMP1                      /**< TIM5_ETR连接到COMP1输出       */
#define TIM_TIM5_ETR_COMP2                 TIM5_AF1_ETR_SEL_COMP2                      /**< TIM5_ETR连接到COMP2输出       */                                                                                 
                                                                                                                                                                              
/* TIM外部时钟输入选择  */                                                                                                                                                    
#define TIM_TIM3_TI1_GPIO                  TIM_TISEL_TI1_SEL_CH1                      /**< TIM3_TI1连接到GPIO       */
#define TIM_TIM3_TI1_COMP1                 TIM_TISEL_TI1_SEL_COMP1                    /**< TIM3_TI1连接到COMP1输出  */    
                                                                                       
#define TIM_TIM3_TI2_GPIO                  TIM_TISEL_TI2_SEL_CH2                      /**< TIM3_TI2连接到GPIO       */  
#define TIM_TIM3_TI2_COMP2                 TIM_TISEL_TI2_SEL_COMP2                    /**< TIM3_TI2连接到COMP2输出  */                                                                       

#define TIM_TIM3_TI4_GPIO                  TIM3_TISEL_TI4_SEL_CH4                      /**< TIM3_TI4连接到GPIO       */  
#define TIM_TIM3_TI4_LXTAL                 TIM3_TISEL_TI4_SEL_LXTAL                    /**< TIM3_TI4连接到LXTAL时钟  */
#define TIM_TIM3_TI4_HXTAL                 TIM3_TISEL_TI4_SEL_HXTAL                    /**< TIM3_TI4连接到HXTAL时钟  */
#define TIM_TIM3_TI4_MCO                   TIM3_TISEL_TI4_SEL_MCO                      /**< TIM3_TI4连接到MCO        */
#define TIM_TIM3_TI4_RCL                   TIM3_TISEL_TI4_SEL_RCL                      /**< TIM3_TI4连接到RCL时钟    */
                                                                                                                                                         
#define TIM_TIM4_TI1_GPIO                  TIM_TISEL_TI1_SEL_CH1                      /**< TIM4_TI1连接到GPIO       */
#define TIM_TIM4_TI1_COMP1                 TIM_TISEL_TI1_SEL_COMP1                    /**< TIM4_TI1连接到COMP1输出  */    
                                                                                       
#define TIM_TIM4_TI2_GPIO                  TIM_TISEL_TI2_SEL_CH2                      /**< TIM4_TI2连接到GPIO       */  
#define TIM_TIM4_TI2_COMP2                 TIM_TISEL_TI2_SEL_COMP2                    /**< TIM4_TI2连接到COMP2输出  */    

#define TIM_TIM5_TI1_GPIO                  TIM_TISEL_TI1_SEL_CH1                      /**< TIM5_TI1连接到GPIO       */
#define TIM_TIM5_TI1_COMP1                 TIM_TISEL_TI1_SEL_COMP1                    /**< TIM5_TI1连接到COMP1输出  */    
                                                                                       
#define TIM_TIM5_TI2_GPIO                  TIM_TISEL_TI2_SEL_CH2                      /**< TIM5_TI2连接到GPIO       */  
#define TIM_TIM5_TI2_COMP2                 TIM_TISEL_TI2_SEL_COMP2                    /**< TIM5_TI2连接到COMP2输出  */    

/**
* @}
*/


/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup TIM_External_Functions TIM External Functions
* @brief    TIM对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  TIM启动计数
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_enable(TIM_t *timx)
{
    timx->CR1 |= TIM_CR1_CEN;    
}

/**
* @brief  TIM停止计数
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_disable(TIM_t *timx)
{
    timx->CR1 &= (~TIM_CR1_CEN);
}


/**
* @brief  设置TIM预分频参数
* @param  timx TIM外设
* @param  presc 预分频新值
* @retval 无
*/
__STATIC_INLINE void std_tim_set_psc(TIM_t *timx, uint32_t presc)          
{
    timx->PSC = (presc);
}


/**
* @brief  获取TIM预分频参数
* @param  timx TIM外设
* @retval uint32_t TIM预分频值
*/
__STATIC_INLINE uint32_t std_tim_get_psc(TIM_t *timx)          
{
    return (timx->PSC);    
}


/**
* @brief  设置TIM计数值
* @param  timx TIM外设 
* @param  counter 计数新值
* @retval 无
*/
__STATIC_INLINE void std_tim_set_counter(TIM_t *timx, uint32_t counter)     
{
    timx->CNT = (counter);
}

/**
* @brief  获取TIM计数值
* @param  timx TIM外设
* @retval uint32_t TIM计数值
*/
__STATIC_INLINE uint32_t std_tim_get_counter(TIM_t *timx)   
{
    return (timx->CNT);
}

/**
* @brief  设置TIM ARR值
* @param  timx TIM外设
* @param  autoreload TIM ARR值，其值必须≥3。
* @retval 无
*/
__STATIC_INLINE void std_tim_set_autoreload(TIM_t *timx, uint32_t autoreload)
{
    timx->ARR = (autoreload); 
}
                                                            
/**
* @brief  获取TIM ARR值
* @param  timx TIM外设
* @retval uint32_t TIM ARR值
*/
__STATIC_INLINE uint32_t std_tim_get_autoreload(TIM_t *timx)
{
    return (timx->ARR);
}

/**
* @brief  设置TIM时钟分频值
* @param  timx TIM外设
* @param  clk_div 时钟分频值
*             @arg TIM_CLOCK_DTS_DIV1:  tDTS=tTIM_KCLK
*             @arg TIM_CLOCK_DTS_DIV2:  tDTS=2*tTIM_KCLK
*             @arg TIM_CLOCK_DTS_DIV4:  tDTS=4*tTIM_KCLK
* @retval 无
*/
__STATIC_INLINE void std_tim_set_clock_div(TIM_t *timx, uint32_t clk_div) 
{
    MODIFY_REG(timx->CR1, TIM_CR1_CLK_DIV, clk_div);    
}

/**
* @brief  获取TIM时钟分频值
* @param  timx TIM外设
* @retval uint32_t 时钟分频值
*             @arg TIM_CLOCK_DIV1: tDTS=tTIM_KCLK
*             @arg TIM_CLOCK_DIV2: tDTS=2*tTIM_KCLK
*             @arg TIM_CLOCK_DIV4: tDTS=4*tTIM_KCLK
*/
__STATIC_INLINE uint32_t std_tim_get_clock_div(TIM_t *timx)           
{
    return (timx->CR1 & TIM_CR1_CLK_DIV);
}

/**
* @brief  使能自动重载功能
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_arrpreload_enable(TIM_t *timx)           
{
    timx->CR1 |= TIM_CR1_ARPE;
}

/**
* @brief  禁止自动重载功能
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_arrpreload_disable(TIM_t *timx)           
{
    timx->CR1 &= (~TIM_CR1_ARPE);
}

/**
* @brief  使能更新事件
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_updateevent_enable(TIM_t *timx)
{
    timx->CR1 |= TIM_CR1_UDIS;
}

/**
* @brief  禁止更新事件
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_updateevent_disable(TIM_t *timx)
{
    timx->CR1 &= (~TIM_CR1_UDIS);
}

/**
* @brief  设置更新事件源
* @param  timx TIM外设
* @param  update_source 更新事件源选择
*             @arg TIM_UPDATE_SOURCE_REGULAR
*             @arg TIM_UPDATE_SOURCE_COUNTER
* @retval 无
*/
__STATIC_INLINE void std_tim_set_update_source(TIM_t *timx, uint32_t update_source)
{
    MODIFY_REG(timx->CR1, TIM_CR1_URS, update_source);
}

/**
* @brief  获取更新事件源
* @param  timx TIM外设
* @retval uint32_t 更新事件源选择
*             @arg TIM_UPDATE_SOURCE_REGULAR
*             @arg TIM_UPDATE_SOURCE_COUNTER
*/
__STATIC_INLINE uint32_t std_tim_get_update_source(TIM_t *timx)
{
    return (timx->CR1 & TIM_CR1_URS);
}


/**
* @brief  设置计数模式
* @param  timx TIM外设
* @param  counter_mode 计数方式
*             @arg TIM_COUNTER_MODE_UP
*             @arg TIM_COUNTER_MODE_DOWN
*             @arg TIM_COUNTER_MODE_CENT_MODE1
*             @arg TIM_COUNTER_MODE_CENT_MODE2
*             @arg TIM_COUNTER_MODE_CENT_MODE3
* @note   由于DIR控制位在中心对齐模式下为只读权限，当从中心对齐模式切换到边沿模式时，避免计数方向修改异常，应先复位一次TIM
* @retval 无
*/
__STATIC_INLINE void std_tim_set_counter_mode(TIM_t *timx, uint32_t counter_mode)
{
    MODIFY_REG(timx->CR1, (TIM_CR1_DIR | TIM_CR1_CMS), counter_mode);
}

/**
* @brief  获取计数模式
* @param  timx TIM外设
* @retval uint32_t 计数方式
*             @arg TIM_COUNTER_MODE_UP
*             @arg TIM_COUNTER_MODE_DOWN
*             @arg TIM_COUNTER_MODE_CENT_MODE1
*             @arg TIM_COUNTER_MODE_CENT_MODE2
*             @arg TIM_COUNTER_MODE_CENT_MODE3
*/
__STATIC_INLINE uint32_t std_tim_get_counter_mode(TIM_t *timx)
{
    if(timx->CR1 & TIM_CR1_CMS)
    {
        return (timx->CR1 & TIM_CR1_CMS);
    }
    else
    {
        return (timx->CR1 & TIM_CR1_DIR);       
    }
}

/**
* @brief  获取TIM计数方向
* @param  timx TIM外设
* @retval bool 返回TIM计数方向标志
*             @arg true: 当前计数方向为向下计数
*             @arg false:当前计数方向为向上计数
*/
__STATIC_INLINE bool std_tim_get_count_dir(TIM_t *timx)  
{
    return ((timx->CR1 & TIM_CR1_DIR) == (TIM_CR1_DIR));
}


/**
* @brief  使能单脉冲模式
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_onepulse_enable(TIM_t *timx)
{
    timx->CR1 |= TIM_CR1_OPM;
}

/**
* @brief  禁止单脉冲模式
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_onepulse_disable(TIM_t *timx)
{
    timx->CR1 &= (~TIM_CR1_OPM);
}

/**
* @brief  获取单脉冲模式
* @param  timx TIM外设
* @retval bool 返回单脉冲计数模式
*             @arg true: 当前配置为单脉冲模式
*             @arg false:当前配置为连续计数模式
*/
__STATIC_INLINE bool std_tim_get_onepulse_mode(TIM_t *timx)
{
    return ((timx->CR1 & (TIM_CR1_OPM)) == (TIM_CR1_OPM));
}


/**
* @brief  设置计数时钟源参数
* @param  timx TIM外设
* @param  clock_source 时钟源选择
*             @arg TIM_CLKSRC_INT:      内部时钟源
*             @arg TIM_CLKSRC_ETR_MODE1:外部时钟模式1
*             @arg TIM_CLKSRC_ETR_MODE2:外部时钟模式2
* @retval 无
*/
__STATIC_INLINE void std_tim_clock_source_config(TIM_t *timx, uint32_t clock_source)
{
    MODIFY_REG(timx->SMC, TIM_SMC_SM_SEL | TIM_SMC_ECEN, clock_source);
}


/**
* @brief  生成一个软件事件
* @param  timx TIM外设
* @param  event_src 事件源
*             @arg TIM_EVENT_SRC_UPDATE:更新事件源
*             @arg TIM_EVENT_SRC_CC1:   捕获比较1事件源
*             @arg TIM_EVENT_SRC_CC2:   捕获比较2事件源
*             @arg TIM_EVENT_SRC_CC3:   捕获比较3事件源
*             @arg TIM_EVENT_SRC_CC4:   捕获比较4事件源
*             @arg TIM_EVENT_SRC_TRIG:  触发事件源
* @retval 无
*/
__STATIC_INLINE void std_tim_set_sw_trig_event(TIM_t *timx, uint32_t event_src)
{
    timx->EVTG = event_src;
}


/** 
* @brief  TIM中断使能
* @param  timx TIM外设
* @param  interrupt TIM中断源
*             @arg TIM_INTERRUPT_UPDATE:  更新中断
*             @arg TIM_INTERRUPT_CC1:     捕获/比较1中断
*             @arg TIM_INTERRUPT_CC2:     捕获/比较2中断
*             @arg TIM_INTERRUPT_CC3:     捕获/比较3中断
*             @arg TIM_INTERRUPT_CC4:     捕获/比较4中断
*             @arg TIM_INTERRUPT_TRIG:    触发中断
* @retval 无
*/
__STATIC_INLINE void std_tim_interrupt_enable(TIM_t *timx, uint32_t interrupt)    
{
    timx->DIER |= (interrupt);
}

/** 
* @brief  TIM中断禁止
* @param  timx TIM外设
* @param  interrupt TIM中断源
*             @arg TIM_INTERRUPT_UPDATE:  更新中断
*             @arg TIM_INTERRUPT_CC1:     捕获/比较1中断
*             @arg TIM_INTERRUPT_CC2:     捕获/比较2中断
*             @arg TIM_INTERRUPT_CC3:     捕获/比较3中断
*             @arg TIM_INTERRUPT_CC4:     捕获/比较4中断
*             @arg TIM_INTERRUPT_TRIG:    触发中断
* @retval 无
*/
__STATIC_INLINE void std_tim_interrupt_disable(TIM_t *timx, uint32_t interrupt)   
{
    timx->DIER &= (~(interrupt));
}


/**
* @brief  获取TIM中断源的状态
* @param  timx TIM外设
* @param  interrupt TIM中断源信息
*             @arg TIM_INTERRUPT_UPDATE:  更新中断
*             @arg TIM_INTERRUPT_CC1:     捕获/比较1中断
*             @arg TIM_INTERRUPT_CC2:     捕获/比较2中断
*             @arg TIM_INTERRUPT_CC3:     捕获/比较3中断
*             @arg TIM_INTERRUPT_CC4:     捕获/比较4中断
*             @arg TIM_INTERRUPT_TRIG:    触发中断
* @retval bool 返回中断请求源的状态 
*             @arg true: 当前中断请求源为使能状态
*             @arg false:当前中断请求源为禁止状态
*/
__STATIC_INLINE bool std_tim_get_interrupt_enable(TIM_t *timx, uint32_t interrupt)   
{
    return ((timx->DIER &(interrupt)) == (interrupt));
}


/** 
* @brief  DMA请求使能
* @param  timx TIM外设
* @param  dam_req TIM_DMA请求
*             @arg TIM_DMA_REQ_UPDATE:  更新DMA请求
*             @arg TIM_DMA_REQ_CC1:     捕获/比较1 DMA请求
*             @arg TIM_DMA_REQ_CC2:     捕获/比较2 DMA请求
*             @arg TIM_DMA_REQ_CC3:     捕获/比较3 DMA请求
*             @arg TIM_DMA_REQ_CC4:     捕获/比较4 DMA请求
*             @arg TIM_DMA_REQ_TRIG:    触发DMA请求
* @retval 无
*/
__STATIC_INLINE void std_tim_dma_req_enable(TIM_t *timx, uint32_t dam_req)
{
    timx->DIER |= (dam_req);
}


/** 
* @brief  DMA请求禁止
* @param  timx TIM外设
* @param  dam_req TIM_DMA请求
*             @arg TIM_DMA_REQ_UPDATE:  更新DMA请求
*             @arg TIM_DMA_REQ_CC1:     捕获/比较1 DMA请求
*             @arg TIM_DMA_REQ_CC2:     捕获/比较2 DMA请求
*             @arg TIM_DMA_REQ_CC3:     捕获/比较3 DMA请求
*             @arg TIM_DMA_REQ_CC4:     捕获/比较4 DMA请求
*             @arg TIM_DMA_REQ_TRIG:    触发DMA请求
* @retval 无
*/
__STATIC_INLINE void std_tim_dma_req_disable(TIM_t *timx, uint32_t dam_req)        
{
    timx->DIER &= (~(dam_req));
}

/**
* @brief  获取TIM DMA使能状态
* @param  timx TIM外设
* @param  dam_req TIM_DMA请求
*             @arg TIM_DMA_REQ_UPDATE:  更新DMA请求
*             @arg TIM_DMA_REQ_CC1:     捕获/比较1 DMA请求
*             @arg TIM_DMA_REQ_CC2:     捕获/比较2 DMA请求
*             @arg TIM_DMA_REQ_CC3:     捕获/比较3 DMA请求
*             @arg TIM_DMA_REQ_CC4:     捕获/比较4 DMA请求
*             @arg TIM_DMA_REQ_TRIG:    触发DMA请求
* @retval bool 返回DMA请求源的状态 
*             @arg true: 当前DMA请求源为使能状态
*             @arg false:当前DMA请求源为禁止状态
*/
__STATIC_INLINE bool std_tim_get_dma_req_enable(TIM_t *timx, uint32_t dam_req)   
{
    return ((timx->DIER &(dam_req)) == (dam_req));
}


/** 
* @brief  获取TIM标志状态
* @param  timx TIM外设
* @param  flag TIM标志信息
*             @arg TIM_FLAG_UPDATE:       更新事件标志
*             @arg TIM_FLAG_CC1:          捕获/比较1事件标志
*             @arg TIM_FLAG_CC2:          捕获/比较2事件标志
*             @arg TIM_FLAG_CC3:          捕获/比较3事件标志
*             @arg TIM_FLAG_CC4:          捕获/比较4事件标志
*             @arg TIM_FLAG_TRIG:         触发事件标志
*             @arg TIM_FLAG_CC1OF:        捕获/比较1重复捕获标志
*             @arg TIM_FLAG_CC2OF:        捕获/比较2重复捕获标志
*             @arg TIM_FLAG_CC3OF:        捕获/比较3重复捕获标志
*             @arg TIM_FLAG_CC4OF:        捕获/比较4重复捕获标志
* @retval bool 返回标志的状态 
*             @arg true: 当前标志为置起状态 
*             @arg false:当前标志为清除状态
*/
__STATIC_INLINE bool std_tim_get_flag(TIM_t *timx, uint32_t flag)          
{
    return ((timx->SR &(flag)) == (flag));
}

/** 
* @brief  清除TIM标志
* @param  timx TIM外设
* @param  flag 清除TIM标志
*             @arg TIM_FLAG_UPDATE:       更新事件标志
*             @arg TIM_FLAG_CC1:          捕获/比较1事件标志
*             @arg TIM_FLAG_CC2:          捕获/比较2事件标志
*             @arg TIM_FLAG_CC3:          捕获/比较3事件标志
*             @arg TIM_FLAG_CC4:          捕获/比较4事件标志
*             @arg TIM_FLAG_TRIG:         触发事件标志
*             @arg TIM_FLAG_CC1OF:        捕获/比较1重复捕获标志
*             @arg TIM_FLAG_CC2OF:        捕获/比较2重复触发标志
*             @arg TIM_FLAG_CC3OF:        捕获/比较3重复触发标志
*             @arg TIM_FLAG_CC4OF:        捕获/比较4重复触发标志
* @retval 无
*/
__STATIC_INLINE void std_tim_clear_flag(TIM_t *timx, uint32_t flag)
{
    timx->SR = (~(flag));
}


/**
* @brief  使能TIM比较/匹配通道
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_ccx_channel_enable(TIM_t *timx, uint32_t channel_id)
{  
    timx->CCEN |= (TIM_CCEN_CC1E << (channel_id << 2));
}


/**
* @brief  禁止TIM比较/匹配通道
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_ccx_channel_disable(TIM_t *timx, uint32_t channel_id)
{     
    timx->CCEN &= (~(TIM_CCEN_CC1E << (channel_id << 2)));
}


/**
* @brief  配置TIM输入捕获通道极性
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  input_capture_pol 输入极性
*             @arg TIM_INPUT_POL_RISING
*             @arg TIM_INPUT_POL_FALLING
*             @arg TIM_INPUT_POL_BOTH
* @retval 无
*/
__STATIC_INLINE void std_tim_set_input_pol(TIM_t *timx, uint32_t channel_id, uint32_t input_capture_pol)
{ 
    MODIFY_REG(timx->CCEN, ((TIM_CCEN_CC1P | TIM_CCEN_CC1NP) << (channel_id << 2)), (input_capture_pol << (channel_id << 2)));
}

/**
* @brief  获取TIM输入捕获通道极性
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 输入极性
*             @arg TIM_INPUT_POL_RISING
*             @arg TIM_INPUT_POL_FALLING
*             @arg TIM_INPUT_POL_BOTH
*/
__STATIC_INLINE uint32_t std_tim_get_input_pol(TIM_t *timx, uint32_t channel_id)
{ 
    return (((timx->CCEN) >> (channel_id << 2)) & (TIM_CCEN_CC1P | TIM_CCEN_CC1NP));
}


/**
* @brief  配置TIM通道输出的极性
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  output_commpare_pol 输出极性
*             @arg TIM_OUTPUT_POL_HIGH
*             @arg TIM_OUTPUT_POL_LOW
* @retval 无
*/
__STATIC_INLINE void std_tim_set_output_pol(TIM_t *timx, uint32_t channel_id, uint32_t output_commpare_pol)
{ 
    MODIFY_REG(timx->CCEN, (TIM_CCEN_CC1P << (channel_id << 2)), (output_commpare_pol << (channel_id << 2)));
}

/**
* @brief  获取TIM通道输出的极性
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 输出极性
*             @arg TIM_OUTPUT_POL_HIGH
*             @arg TIM_OUTPUT_POL_LOW
*/
__STATIC_INLINE uint32_t std_tim_get_output_pol(TIM_t *timx, uint32_t channel_id)
{ 
    return (((timx->CCEN) >> (channel_id << 2)) & TIM_CCEN_CC1P);
}


/**
* @brief  使能清除OCxREF功能
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_channel_clear_ocxref_enable(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;    
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    /* 使能清除OCxREF */ 
    *preg |= (TIM_CCM1_OC1CE << tmp_value);
}

/**
* @brief  禁止清除OCxREF功能
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_channel_clear_ocxref_disable(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;      
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    /* 禁止清除OCxREF */ 
    *preg &= (~(TIM_CCM1_OC1CE << tmp_value));
}

/**
* @brief  设置输入捕获预分频值
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  icxpsc_num 输入捕获预分频值
*             @arg TIM_INPUT_CAPTURE_PSC_DIV1
*             @arg TIM_INPUT_CAPTURE_PSC_DIV2
*             @arg TIM_INPUT_CAPTURE_PSC_DIV4
*             @arg TIM_INPUT_CAPTURE_PSC_DIV8
* @retval 无
*/
__STATIC_INLINE void std_tim_set_channel_icxpsc(TIM_t *timx, uint32_t channel_id, uint32_t icxpsc_num)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;      
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    /* 设置输入捕获预分频 */ 
    MODIFY_REG(*preg, (TIM_CCM1_IC1PSC << tmp_value), (icxpsc_num << tmp_value));
}


/**
* @brief  获取输入捕获预分频值
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 输入捕获预分频值
*             @arg TIM_INPUT_CAPTURE_PSC_DIV1
*             @arg TIM_INPUT_CAPTURE_PSC_DIV2
*             @arg TIM_INPUT_CAPTURE_PSC_DIV4
*             @arg TIM_INPUT_CAPTURE_PSC_DIV8
*/
__STATIC_INLINE uint32_t std_tim_get_channel_icxpsc(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    /* 获取输入捕获预分频 */ 
    return ((*preg >> tmp_value) & TIM_CCM1_IC1PSC);
    
}


/**
* @brief  使能TIM通道输出比较的预装载功能
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_preloadccx_channel_enable(TIM_t *timx, uint32_t channel_id)
{ 
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);    
 
    /* 使能输出比较预装载功能 */ 
    *preg |= (TIM_CCM1_OC1PE << tmp_value);
}


/**
* @brief  禁止TIM通道输出比较的预装载功能
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_preloadccx_channel_disable(TIM_t *timx, uint32_t channel_id)
{ 
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);    
 
    /* 使能输出比较预装载功能 */ 
    *preg &= (~(TIM_CCM1_OC1PE << tmp_value));
}


/**
* @brief  使能TIM通道快速模式
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_fastmode_channel_enable(TIM_t *timx, uint32_t channel_id)
{ 
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);    
 
    /* 使能输出比较预装载功能 */ 
    *preg |= (TIM_CCM1_OC1FE << tmp_value);
}


/**
* @brief  禁止TIM通道快速模式
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_fastmode_channel_disable(TIM_t *timx, uint32_t channel_id)
{ 
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);    
 
    /* 禁止输出快速模式 */ 
    *preg &= (~(TIM_CCM1_OC1FE << tmp_value));
}


/**
* @brief  配置通道输出模式
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  ocmode 输出模式选择
*             @arg TIM_OUTPUT_MODE_FROZEN         
*             @arg TIM_OUTPUT_MODE_ACTIVE         
*             @arg TIM_OUTPUT_MODE_INACTIVE       
*             @arg TIM_OUTPUT_MODE_TOGGLE         
*             @arg TIM_OUTPUT_MODE_FORCED_INACTIVE
*             @arg TIM_OUTPUT_MODE_FORCED_ACTIVE  
*             @arg TIM_OUTPUT_MODE_PWM1           
*             @arg TIM_OUTPUT_MODE_PWM2                   
* @retval 无
*/
__STATIC_INLINE void std_tim_set_ocmode(TIM_t *timx, uint32_t channel_id, uint32_t ocmode)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    MODIFY_REG(*preg, ((TIM_CCM1_OC1M  | TIM_CCM1_CC1S) << tmp_value), (ocmode << tmp_value));
}


/**
* @brief  获取通道输出模式
* @param  timx TIM外设
* @param  channel_id 指定TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @note   该函数执行后，会将通道设置为输出模式
* @retval uint32_t 输出模式选择
*             @arg TIM_OUTPUT_MODE_FROZEN         
*             @arg TIM_OUTPUT_MODE_ACTIVE         
*             @arg TIM_OUTPUT_MODE_INACTIVE       
*             @arg TIM_OUTPUT_MODE_TOGGLE         
*             @arg TIM_OUTPUT_MODE_FORCED_INACTIVE
*             @arg TIM_OUTPUT_MODE_FORCED_ACTIVE  
*             @arg TIM_OUTPUT_MODE_PWM1           
*             @arg TIM_OUTPUT_MODE_PWM2               
*/
__STATIC_INLINE uint32_t std_tim_get_ocmode(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;    
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);

    return ((*preg >> tmp_value) & TIM_CCM1_OC1M);
}

/**
* @brief  设置捕获/比较寄存器的值
* @param  timx TIM外设
* @param  ccx_value 捕获比较寄存器的值
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval std_status_t 返回API执行结果
*/
__STATIC_INLINE void std_tim_set_ccx_value(TIM_t *timx, uint32_t channel_id, uint32_t ccx_value)
{    
    __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)(&timx->CC1) + (channel_id << 2));

    MODIFY_REG(*pReg, TIM_CC1_CC1, ccx_value);
}


/**
* @brief  获取捕获/比较寄存器的值
* @param  timx TIM外设
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 捕获比较寄存器的值
*/
__STATIC_INLINE uint32_t std_tim_get_ccx_value(TIM_t *timx, uint32_t channel_id)
{
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CC1) + (channel_id << 2));
      
    return (*preg & TIM_CC1_CC1);
}

/**
* @brief  设置通道为输入模式
* @param  timx TIM外设
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  icmode 输入模式选择
*             @arg TIM_INPUT_CAPTURE_SEL_DIRECTTI
*             @arg TIM_INPUT_CAPTURE_SEL_INDIRECTTI
*             @arg TIM_INPUT_CAPTURE_SEL_TRC
* @retval 无
*/
__STATIC_INLINE void std_tim_set_icmode(TIM_t *timx, uint32_t channel_id, uint32_t icmode)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    MODIFY_REG(*preg, (TIM_CCM1_CC1S << tmp_value), (icmode << tmp_value));
}

/**
* @brief  获取通道的输入状态
* @param  timx TIM外设
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 输入模式选择
*             @arg TIM_INPUT_CAPTURE_SEL_DIRECTTI
*             @arg TIM_INPUT_CAPTURE_SEL_INDIRECTTI
*             @arg TIM_INPUT_CAPTURE_SEL_TRC
*/
__STATIC_INLINE uint32_t std_tim_get_icmode(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    return ((*preg >> tmp_value) & TIM_CCM1_CC1S);
}

/**
* @brief  设置输入通道的滤波参数
* @param  timx TIM外设
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @param  icfilter 输入滤波参数，其值的范围为:0x00~0x07
* @retval 无
*/
__STATIC_INLINE void std_tim_set_icfilter(TIM_t *timx, uint32_t channel_id, uint32_t icfilter)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    MODIFY_REG(*preg, (TIM_CCM1_IC1F << tmp_value), ((icfilter << tmp_value) << 4U));
}

/**
* @brief  获取输入通道的滤波参数
* @param  timx TIM外设
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval uint32_t 输入滤波参数，其值的范围为:0x00~0x07
*/
__STATIC_INLINE uint32_t std_tim_get_icfilter(TIM_t *timx, uint32_t channel_id)
{
    uint32_t tmp_value = ((channel_id & 0x01) == 0)?0U:8U;
    uint32_t shift_value = ((channel_id & 0x02) == 0)?0U:4U;        
    __IO uint32_t *preg = (__IO uint32_t *)((uint32_t)(&timx->CCM1) + shift_value);
    
    return (((*preg >> tmp_value) & TIM_CCM1_IC1F) >> 4U);
}



/**
* @brief  设置编码器模式计数方式
* @param  timx TIM外设
* @param  encoder_mode 编码器计数方式
*             @arg TIM_ENCODER_MODE_TI1
*             @arg TIM_ENCODER_MODE_TI2
*             @arg TIM_ENCODER_MODE_TI12
* @retval 无
*/
__STATIC_INLINE void std_tim_encode_mode_config(TIM_t *timx, uint32_t encoder_mode)
{
    MODIFY_REG(timx->SMC, TIM_SMC_SM_SEL, encoder_mode);
}


/**
* @brief  设置主模式（TRIG_OUT）输出参数
* @param  timx TIM外设
* @param  trigout_mode 主模式输出参数定义
*             @arg TIM_TRIG_OUT_RESET
*             @arg TIM_TRIG_OUT_ENABLE
*             @arg TIM_TRIG_OUT_UPDATE
*             @arg TIM_TRIG_OUT_CC1      
*             @arg TIM_TRIG_OUT_OC1REF   
*             @arg TIM_TRIG_OUT_OC2REF   
*             @arg TIM_TRIG_OUT_OC3REF   
*             @arg TIM_TRIG_OUT_OC4REF
* @retval 无
*/
__STATIC_INLINE void std_tim_trigout_mode_config(TIM_t *timx, uint32_t trigout_mode)
{
    MODIFY_REG(timx->CR2, TIM_CR2_MM_SEL, trigout_mode);
}


/**
* @brief  设置从模式参数
* @param  timx TIM外设
* @param  slave_mode 从模式参数定义
*             @arg TIM_SLAVE_MODE_DISABLE 
*             @arg TIM_SLAVE_MODE_RESET   
*             @arg TIM_SLAVE_MODE_GATED   
*             @arg TIM_SLAVE_MODE_TRIG    
* @retval 无
*/
__STATIC_INLINE void std_tim_slave_mode_config(TIM_t *timx, uint32_t slave_mode)
{
    MODIFY_REG(timx->SMC, TIM_SMC_SM_SEL, slave_mode);
}

/**
* @brief  设置触发输入源
* @param  timx TIM外设
* @param  trig_source 触发输入源定义
*             @arg TIM_TRIG_SOURCE_ITR0   
*             @arg TIM_TRIG_SOURCE_ITR1   
*             @arg TIM_TRIG_SOURCE_ITR2   
*             @arg TIM_TRIG_SOURCE_TI1F_ED
*             @arg TIM_TRIG_SOURCE_TI1FP1 
*             @arg TIM_TRIG_SOURCE_TI2FP2 
*             @arg TIM_TRIG_SOURCE_ETRF   
* @retval 无
*/
__STATIC_INLINE void std_tim_trig_source_config(TIM_t *timx, uint32_t trig_source)
{
    MODIFY_REG(timx->SMC, TIM_SMC_TS, trig_source);
}


/**
* @brief  使能主/从模式
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_master_mode_enable(TIM_t *timx)
{
    timx->SMC |= TIM_SMC_MS_MOD;
}


/**
* @brief  禁止主/从模式
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_master_mode_disable(TIM_t *timx)
{
    timx->SMC &= (~TIM_SMC_MS_MOD);
}

/**
* @brief  ETR参数配置
* @param  timx TIM外设
* @param  etr_pol ETR极性参数定义
*             @arg TIM_ETR_POL_HIGH
*             @arg TIM_ETR_POL_LOW
* @param  etr_psc ETR预分频参数定义
*             @arg TIM_ETR_PSC_DIV1
*             @arg TIM_ETR_PSC_DIV2
*             @arg TIM_ETR_PSC_DIV4
*             @arg TIM_ETR_PSC_DIV8
* @param  etr_filter ETR滤波参数定义，其值范围为:0x00~0x07
* @retval 无
*/
__STATIC_INLINE void std_tim_etr_config(TIM_t *timx, uint32_t etr_pol, uint32_t etr_psc, uint32_t etr_filter)
{
    MODIFY_REG(timx->SMC, TIM_SMC_ETP | TIM_SMC_ET_PRE | TIM_SMC_ETF, etr_pol | etr_psc | (etr_filter << TIM_SMC_ETF_POS));
}



/**
* @brief  配置ETR源
* @param  timx TIM外设
* @param  etr_source ETR源选择
*         对于TIM3，参数可以取以下值之一:
*             @arg TIM_TIM3_ETR_GPIO:     TIM3 ETR连接到GPIO
*             @arg TIM_TIM3_ETR_COMP1:    TIM3 ETR连接到COMP1输出
*             @arg TIM_TIM3_ETR_COMP2:    TIM3 ETR连接到COMP2输出
*             @arg TIM_TIM3_ETR_LXTAL:    TIM3 ETR连接到LXTAL
*             @arg TIM_TIM3_ETR_HXTAL:    TIM3 ETR连接到HXTAL
*             @arg TIM_TIM3_ETR_MCO:      TIM3 ETR连接到MCO
*             @arg TIM_TIM3_ETR_RCL:      TIM3 ETR连接到RCL
*
*         对于TIM4，参数可以取以下值之一:
*             @arg TIM_TIM4_ETR_GPIO:     TIM4 ETR连接到GPIO
*             @arg TIM_TIM4_ETR_COMP1:    TIM4 ETR连接到COMP1输出
*             @arg TIM_TIM4_ETR_COMP2:    TIM4 ETR连接到COMP2输出
*
*         对于TIM5，参数可以取以下值之一:
*             @arg TIM_TIM5_ETR_GPIO:     TIM5 ETR连接到GPIO
*             @arg TIM_TIM5_ETR_COMP1:    TIM5 ETR连接到COMP1输出
*             @arg TIM_TIM5_ETR_COMP2:    TIM5 ETR连接到COMP2输出
* @retval 无
*/
__STATIC_INLINE void std_tim_set_etr_source(TIM_t *timx, uint32_t etr_source)
{
    MODIFY_REG(timx->AF1, TIM_AF1_ETR_SEL, etr_source);
}

/**
* @brief  获取ETR源
* @param  timx TIM外设
* @retval uint32_t ETR源选择
*         对于TIM3，参数可以取以下值之一:
*             @arg TIM_TIM3_ETR_GPIO:     TIM3 ETR连接到GPIO
*             @arg TIM_TIM3_ETR_COMP1:    TIM3 ETR连接到COMP1输出
*             @arg TIM_TIM3_ETR_COMP2:    TIM3 ETR连接到COMP2输出
*             @arg TIM_TIM3_ETR_LXTAL:    TIM3 ETR连接到LXTAL
*             @arg TIM_TIM3_ETR_HXTAL:    TIM3 ETR连接到HXTAL
*             @arg TIM_TIM3_ETR_MCO:      TIM3 ETR连接到MCO
*             @arg TIM_TIM3_ETR_RCL:      TIM3 ETR连接到RCL
*
*         对于TIM4，参数可以取以下值之一:
*             @arg TIM_TIM4_ETR_GPIO:     TIM4 ETR连接到GPIO
*             @arg TIM_TIM4_ETR_COMP1:    TIM4 ETR连接到COMP1输出
*             @arg TIM_TIM4_ETR_COMP2:    TIM4 ETR连接到COMP2输出
*
*         对于TIM5，参数可以取以下值之一:
*             @arg TIM_TIM5_ETR_GPIO:     TIM5 ETR连接到GPIO
*             @arg TIM_TIM5_ETR_COMP1:    TIM5 ETR连接到COMP1输出
*             @arg TIM_TIM5_ETR_COMP2:    TIM5 ETR连接到COMP2输出
*/
__STATIC_INLINE uint32_t std_tim_get_etr_source(TIM_t *timx)
{
    return (timx->AF1 & TIM_AF1_ETR_SEL);
}


/**
* @brief  配置TIM OCREF CLEAR输入源
* @param  timx TIM外设
* @param  ocrefclr_source OCREF CLR源选择
*             @arg TIM_CLEAR_INPUT_SRC_ETR:   OCREF CLR连接到ETR
*             @arg TIM_CLEAR_INPUT_SRC_COMP1: OCREF CLR连接到COMP1
*             @arg TIM_CLEAR_INPUT_SRC_COMP2: OCREF CLR连接到COMP2
* @retval 无
*/
__STATIC_INLINE void std_tim_ocrefclr_source_config(TIM_t *timx, uint32_t ocrefclr_source)
{
    if(ocrefclr_source == TIM_CLEAR_INPUT_SRC_ETR)
    {
        timx->SMC |= TIM_SMC_OCCS;
    }
    else
    {
        timx->SMC &= (~TIM_SMC_OCCS);
        MODIFY_REG(timx->CFG, TIM_CFG_OCREF_CLR, ocrefclr_source);
    }
}


/**
* @brief  配置捕获/比较DMA请求生成选择
* @param  timx TIM外设
* @param  gen_event 生成DMA请求的事件
*             @arg TIM_GEN_DMA_REQ_CCX
*             @arg TIM_GEN_DMA_REQ_UPDATE
* @note   DMA Burst模式下该配置无效
* @retval 无
*/
__STATIC_INLINE void std_tim_dma_request_gen_event_config(TIM_t *timx, uint32_t gen_event)
{
    MODIFY_REG(timx->CR2, (TIM_CR2_CC_DMASEL), gen_event);
}

/**
* @brief  使能TI1的XOR功能
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_ti1xor_enable(TIM_t *timx)
{
    timx->CR2 |= TIM_CR2_TI1_XOR_SEL;
}


/**
* @brief  禁止TI1的XOR功能
* @param  timx TIM外设
* @retval 无
*/
__STATIC_INLINE void std_tim_ti1xor_disable(TIM_t *timx)
{
    timx->CR2 &= (~TIM_CR2_TI1_XOR_SEL);
}

/**
* @brief  配置TIM输入通道重映射功能
* @param  timx TIM外设
* @param  ti_sel 通道输入源选择参数
*         对于TIM3，参数可以取以下值之一:
*             @arg TIM_TIM3_TI1_GPIO:     TIM3 TI1连接到GPIO
*             @arg TIM_TIM3_TI1_COMP1:    TIM3 TI1连接到COMP1输出
*             @arg TIM_TIM3_TI2_GPIO:     TIM3 TI2连接到GPIO
*             @arg TIM_TIM3_TI2_COMP2:    TIM3 TI2连接到COMP2输出
*
*             @arg TIM_TIM3_TI4_GPIO:     TIM3 TI4连接到GPIO
*             @arg TIM_TIM3_TI4_LXTAL:    TIM3 TI4连接到LXTAL
*             @arg TIM_TIM3_TI4_HXTAL:    TIM3 TI4连接到HXTAL
*             @arg TIM_TIM3_TI4_MCO:      TIM3 TI4连接到MCO
*             @arg TIM_TIM3_TI4_RCL:      TIM3 TI4连接到RCL
*
*         对于TIM4，参数可以取以下值之一:
*             @arg TIM_TIM4_TI1_GPIO:     TIM4 TI1连接到GPIO
*             @arg TIM_TIM4_TI1_COMP1:    TIM4 TI1连接到COMP1输出
*             @arg TIM_TIM4_TI2_GPIO:     TIM4 TI2连接到GPIO
*             @arg TIM_TIM4_TI2_COMP2:    TIM4 TI2连接到COMP2输出
*
*         对于TIM5，参数可以取以下值之一:
*             @arg TIM_TIM5_TI1_GPIO:     TIM5 TI1连接到GPIO
*             @arg TIM_TIM5_TI1_COMP1:    TIM5 TI1连接到COMP1输出
*             @arg TIM_TIM5_TI2_GPIO:     TIM5 TI2连接到GPIO
*             @arg TIM_TIM5_TI2_COMP2:    TIM5 TI2连接到COMP2输出
* @param  channel_id TIM通道
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
__STATIC_INLINE void std_tim_set_channel_remap(TIM_t *timx, uint32_t ti_sel, uint32_t channel_id)
{
    MODIFY_REG(timx->TISEL, (TIM_TISEL_TI1_SEL << (channel_id << 3)), ti_sel);
}



/* 基础计数功能初始化/去初始化 */
void std_tim_init(TIM_t *timx, std_tim_basic_init_t *tim_init_param);
void std_tim_deinit(TIM_t *timx);
void std_tim_struct_init(std_tim_basic_init_t *tim_init_struct);

/* 输入捕获初始化 */
void std_tim_input_capture_init(TIM_t *timx, std_tim_input_capture_init_t *input_config, uint32_t channel_id);
void std_tim_input_capture_struct_init(std_tim_input_capture_init_t *input_init_struct);

/* 输出模式初始化及参数配置函数 */
void std_tim_output_compare_init(TIM_t *timx, std_tim_output_compare_init_t *output_config, uint32_t channel_id);
void std_tim_output_compare_struct_init(std_tim_output_compare_init_t *output_init_struct);


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
#endif /* CIU32L051_STD_TIM_H */

