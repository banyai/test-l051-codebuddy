/************************************************************************************************/
/**
* @file               ciu32l051_std_lcd.h
* @author             MCU Ecosystem Development Team
* @brief              LCD STD库驱动头文件。
*                     提供LCD 相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_LCD_H
#define CIU32L051_STD_LCD_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup LCD LCD
* @brief 液晶显示控制器的STD库驱动
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
* @defgroup LCD_Types LCD Types
* @brief  LCD 数据类型定义
* @{
*
*/
/************************************************************************************************/
/**
* @brief  LCD 初始化结构体定义
*/        
typedef struct
{
    uint32_t bias;                                                         /**< 偏置电压的设置
                                                                                    @arg  LCD_BIAS_1_3...                 */
    uint32_t duty;                                                         /**< 占空比的设置
                                                                                    @arg  LCD_DUTY_1_4...                 */
    uint32_t prescaler;                                                    /**< 时钟源预分频器的设置
                                                                                    @arg  LCD_PRESCALER_1...              */
    uint32_t divider;                                                      /**< 时钟源分频器的设置
                                                                                    @arg  LCD_DIVIDER_16...               */
    uint32_t driver_mode;                                                  /**< 驱动模式配置
                                                                                    @arg  LCD_DRIVER_MODE_CHARGE_PUMP...  */
    uint32_t vlcd_voltage;                                                 /**< VLCD输出电压配置
                                                                                    @arg  LCD_INNER_RESISTER_1_000_VDD...  
                                                                                    @arg  LCD_CHAGE_PUMP_1_3_BIAS_2_55V...  
                                                                                    @arg  LCD_CHAGE_PUMP_1_4_BIAS_2_60V...*/   
    uint32_t high_drive;                                                   /**< 驱动能力的设置
                                                                                    @arg  LCD_HIGH_DRIVE...               */
    uint32_t pulse_on_duration;                                            /**< 脉冲持续时间
                                                                                    @arg  LCD_PULSE_ON_DURATION_0...      */
    uint32_t mux_segment;                                                  /**< 区段多路复用的使能
                                                                                    @arg  LCD_MUX_SEGMENT_ENABLE...       
                                                                                    @note 1/6 和 1/4duty需使能区段多路复用，
                                                                                          1/8duty为无关项                 */
}std_lcd_init_t;


/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup LCD_Constants LCD Constants
* @brief LCD 常量定义及宏定义
* @{
*/
/************************************************************************************************/

/* LCD驱动模式 */
#define LCD_DRIVER_MODE_CHARGE_PUMP                           LCD_CR_MDSET_CHARGE_PUMP        /**< 电荷泵模式       */
#define LCD_DRIVER_MODE_INNER_RESISTER                        LCD_CR_MDSET_INNER_RES          /**< 片内电阻分压模式 */ 
#define LCD_DRIVER_MODE_OUTER_CAPACITY                        LCD_CR_MDSET_OUTER_CAP          /**< 片外电容分压模式 */

/* LCD电荷泵和片外电容分压模式时钟分频 */
#define LCD_CPCLK_DIV1                                        LCD_CR_CPDIV_DIV1               /**< 不分频  */
#define LCD_CPCLK_DIV2                                        LCD_CR_CPDIV_DIV2               /**< 2分频   */ 
#define LCD_CPCLK_DIV4                                        LCD_CR_CPDIV_DIV4               /**< 4分频   */
#define LCD_CPCLK_DIV8                                        LCD_CR_CPDIV_DIV8               /**< 8分频   */
#define LCD_CPCLK_DIV16                                       LCD_CR_CPDIV_DIV16              /**< 16分频  */
#define LCD_CPCLK_DIV32                                       LCD_CR_CPDIV_DIV32              /**< 32分频  */
#define LCD_CPCLK_DIV64                                       LCD_CR_CPDIV_DIV64              /**< 64分频  */
#define LCD_CPCLK_DIV128                                      LCD_CR_CPDIV_DIV128             /**< 128分频 */

/* LCD外设区段多路复用 */
#define LCD_MUX_SEGMENT_DISABLE                               (0x00000000U)                   /**< SEG 区段多路复用禁止 */
#define LCD_MUX_SEGMENT_ENABLE                                LCD_CR_MUX_SEG                  /**< SEG 区段多路复用使能 */

/* LCD外设偏置 */ 
#define LCD_BIAS_1_3                                          LCD_CR_BIAS_1_3                 /**< 1/3 偏置电压 */
#define LCD_BIAS_1_4                                          LCD_CR_BIAS_1_4                 /**< 1/4 偏置电压 */

/* LCD外设占空比 */
#define LCD_DUTY_1_4                                          LCD_CR_DUTY_1_4                 /**< 1/4 占空比 */
#define LCD_DUTY_1_6                                          LCD_CR_DUTY_1_6                 /**< 1/6 占空比 */
#define LCD_DUTY_1_8                                          LCD_CR_DUTY_1_8                 /**< 1/8 占空比 */

/* 外设时钟源预分频器 */
#define LCD_PRESCALER_1                                       LCD_FCR_PS_1                    /**< ck_ps = LCDCLK     */
#define LCD_PRESCALER_2                                       LCD_FCR_PS_2                    /**< ck_ps = LCDCLK/2   */
#define LCD_PRESCALER_4                                       LCD_FCR_PS_4                    /**< ck_ps = LCDCLK/4   */
#define LCD_PRESCALER_8                                       LCD_FCR_PS_8                    /**< ck_ps = LCDCLK/8   */
#define LCD_PRESCALER_16                                      LCD_FCR_PS_16                   /**< ck_ps = LCDCLK/16  */
#define LCD_PRESCALER_32                                      LCD_FCR_PS_32                   /**< ck_ps = LCDCLK/32  */
#define LCD_PRESCALER_64                                      LCD_FCR_PS_64                   /**< ck_ps = LCDCLK/64  */
#define LCD_PRESCALER_128                                     LCD_FCR_PS_128                  /**< ck_ps = LCDCLK/128 */

/* LCD外设时钟源分频器 */
#define LCD_DIVIDER_16                                        LCD_FCR_DIV16                   /**< ck_div = CLKPS/16 */
#define LCD_DIVIDER_17                                        LCD_FCR_DIV17                   /**< ck_div = CLKPS/17 */
#define LCD_DIVIDER_18                                        LCD_FCR_DIV18                   /**< ck_div = CLKPS/18 */
#define LCD_DIVIDER_19                                        LCD_FCR_DIV19                   /**< ck_div = CLKPS/19 */
#define LCD_DIVIDER_20                                        LCD_FCR_DIV20                   /**< ck_div = CLKPS/20 */
#define LCD_DIVIDER_21                                        LCD_FCR_DIV21                   /**< ck_div = CLKPS/21 */
#define LCD_DIVIDER_22                                        LCD_FCR_DIV22                   /**< ck_div = CLKPS/22 */
#define LCD_DIVIDER_23                                        LCD_FCR_DIV23                   /**< ck_div = CLKPS/23 */
#define LCD_DIVIDER_24                                        LCD_FCR_DIV24                   /**< ck_div = CLKPS/24 */
#define LCD_DIVIDER_25                                        LCD_FCR_DIV25                   /**< ck_div = CLKPS/25 */
#define LCD_DIVIDER_26                                        LCD_FCR_DIV26                   /**< ck_div = CLKPS/26 */
#define LCD_DIVIDER_27                                        LCD_FCR_DIV27                   /**< ck_div = CLKPS/27 */
#define LCD_DIVIDER_28                                        LCD_FCR_DIV28                   /**< ck_div = CLKPS/28 */
#define LCD_DIVIDER_29                                        LCD_FCR_DIV29                   /**< ck_div = CLKPS/29 */
#define LCD_DIVIDER_30                                        LCD_FCR_DIV30                   /**< ck_div = CLKPS/30 */
#define LCD_DIVIDER_31                                        LCD_FCR_DIV31                   /**< ck_div = CLKPS/31 */

/* LCD外设闪烁模式 */
#define LCD_BLINK_MODE_OFF                                    LCD_FCR_MODE_OFF                /**< 禁止闪烁                                              */
#define LCD_BLINK_MODE_SEG0_COM0                              LCD_FCR_MODE_SEG0_COM0          /**< 在SEG[0], COM[0] 使能闪烁(1个像素)                    */
#define LCD_BLINK_MODE_SEG0_ALLCOM                            LCD_FCR_MODE_SEG0_ALLCOM        /**< 在SEG[0]，所有COM 使能闪烁(最多8个像素，取决于占空比) */
#define LCD_BLINK_MODE_ALLSEG_ALLCOM                          LCD_FCR_MODE_ALLSEG_ALLCOM      /**< 在所有SEG，所有COM 使能闪烁(所有像素)                 */

/* LCD外设闪烁频率 */
#define LCD_BLINK_FREQUENCY_DIV8                              LCD_FCR_BLINKF_DIV8             /**< 闪烁频率 F = ck_div/8    */
#define LCD_BLINK_FREQUENCY_DIV16                             LCD_FCR_BLINKF_DIV16            /**< 闪烁频率 F = ck_div/16   */
#define LCD_BLINK_FREQUENCY_DIV32                             LCD_FCR_BLINKF_DIV32            /**< 闪烁频率 F = ck_div/32   */
#define LCD_BLINK_FREQUENCY_DIV64                             LCD_FCR_BLINKF_DIV64            /**< 闪烁频率 F = ck_div/64   */
#define LCD_BLINK_FREQUENCY_DIV128                            LCD_FCR_BLINKF_DIV128           /**< 闪烁频率 F = ck_div/128  */
#define LCD_BLINK_FREQUENCY_DIV256                            LCD_FCR_BLINKF_DIV256           /**< 闪烁频率 F = ck_div/256  */
#define LCD_BLINK_FREQUENCY_DIV512                            LCD_FCR_BLINKF_DIV512           /**< 闪烁频率 F = ck_div/512  */
#define LCD_BLINK_FREQUENCY_DIV1024                           LCD_FCR_BLINKF_DIV1024          /**< 闪烁频率 F = ck_div/1024 */

/* VLCD输出电压档位，适用于电荷泵模式，1/3 BIAS */
#define LCD_CHAGE_PUMP_1_3_BIAS_2_55V                         LCD_FCR_CC_LV0                  /**< VLCD电压档位0  2.55V */
#define LCD_CHAGE_PUMP_1_3_BIAS_2_70V                         LCD_FCR_CC_LV1                  /**< VLCD电压档位1  2.70V */
#define LCD_CHAGE_PUMP_1_3_BIAS_2_85V                         LCD_FCR_CC_LV2                  /**< VLCD电压档位2  2.85V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_00V                         LCD_FCR_CC_LV3                  /**< VLCD电压档位3  3.00V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_15V                         LCD_FCR_CC_LV4                  /**< VLCD电压档位4  3.15V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_30V                         LCD_FCR_CC_LV5                  /**< VLCD电压档位5  3.30V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_45V                         LCD_FCR_CC_LV6                  /**< VLCD电压档位6  3.45V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_60V                         LCD_FCR_CC_LV7                  /**< VLCD电压档位7  3.60V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_75V                         LCD_FCR_CC_LV8                  /**< VLCD电压档位8  3.75V */
#define LCD_CHAGE_PUMP_1_3_BIAS_3_90V                         LCD_FCR_CC_LV9                  /**< VLCD电压档位9  3.90V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_05V                         LCD_FCR_CC_LV10                 /**< VLCD电压档位10 4.05V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_20V                         LCD_FCR_CC_LV11                 /**< VLCD电压档位11 4.20V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_35V                         LCD_FCR_CC_LV12                 /**< VLCD电压档位12 4.35V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_50V                         LCD_FCR_CC_LV13                 /**< VLCD电压档位13 4.50V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_65V                         LCD_FCR_CC_LV14                 /**< VLCD电压档位14 4.65V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_80V                         LCD_FCR_CC_LV15                 /**< VLCD电压档位15 4.80V */
#define LCD_CHAGE_PUMP_1_3_BIAS_4_95V                         LCD_FCR_CC_LV16                 /**< VLCD电压档位16 4.95V */
#define LCD_CHAGE_PUMP_1_3_BIAS_5_10V                         LCD_FCR_CC_LV17                 /**< VLCD电压档位17 5.10V */
#define LCD_CHAGE_PUMP_1_3_BIAS_5_25V                         LCD_FCR_CC_LV18                 /**< VLCD电压档位18 5.25V */


/* VLCD输出电压档位，适用于电荷泵模式，1/4 BIAS */
#define LCD_CHAGE_PUMP_1_4_BIAS_2_60V                         LCD_FCR_CC_LV0                  /**< VLCD电压档位0  2.60V */
#define LCD_CHAGE_PUMP_1_4_BIAS_2_80V                         LCD_FCR_CC_LV1                  /**< VLCD电压档位1  2.80V */
#define LCD_CHAGE_PUMP_1_4_BIAS_3_00V                         LCD_FCR_CC_LV2                  /**< VLCD电压档位2  3.00V */
#define LCD_CHAGE_PUMP_1_4_BIAS_3_20V                         LCD_FCR_CC_LV3                  /**< VLCD电压档位3  3.20V */
#define LCD_CHAGE_PUMP_1_4_BIAS_3_40V                         LCD_FCR_CC_LV4                  /**< VLCD电压档位4  3.40V */
#define LCD_CHAGE_PUMP_1_4_BIAS_3_60V                         LCD_FCR_CC_LV5                  /**< VLCD电压档位5  3.60V */
#define LCD_CHAGE_PUMP_1_4_BIAS_3_80V                         LCD_FCR_CC_LV6                  /**< VLCD电压档位6  3.80V */
#define LCD_CHAGE_PUMP_1_4_BIAS_4_00V                         LCD_FCR_CC_LV7                  /**< VLCD电压档位7  4.00V */
#define LCD_CHAGE_PUMP_1_4_BIAS_4_20V                         LCD_FCR_CC_LV8                  /**< VLCD电压档位8  4.20V */
#define LCD_CHAGE_PUMP_1_4_BIAS_4_40V                         LCD_FCR_CC_LV9                  /**< VLCD电压档位9  4.40V */
#define LCD_CHAGE_PUMP_1_4_BIAS_4_60V                         LCD_FCR_CC_LV10                 /**< VLCD电压档位10 4.60V */
#define LCD_CHAGE_PUMP_1_4_BIAS_4_80V                         LCD_FCR_CC_LV11                 /**< VLCD电压档位11 4.80V */
#define LCD_CHAGE_PUMP_1_4_BIAS_5_00V                         LCD_FCR_CC_LV12                 /**< VLCD电压档位12 5.00V */
#define LCD_CHAGE_PUMP_1_4_BIAS_5_20V                         LCD_FCR_CC_LV13                 /**< VLCD电压档位13 5.20V */

/* VLCD输出电压档位，用于片内电阻分压模式（高驱） */
#define LCD_INNER_RESISTER_0_548_VDD                          LCD_FCR_CC_LV0                  /**< VLCD电压档位0  0.548*VDD */
#define LCD_INNER_RESISTER_0_566_VDD                          LCD_FCR_CC_LV1                  /**< VLCD电压档位1  0.566*VDD */
#define LCD_INNER_RESISTER_0_584_VDD                          LCD_FCR_CC_LV2                  /**< VLCD电压档位2  0.584*VDD */
#define LCD_INNER_RESISTER_0_602_VDD                          LCD_FCR_CC_LV3                  /**< VLCD电压档位3  0.602*VDD */
#define LCD_INNER_RESISTER_0_624_VDD                          LCD_FCR_CC_LV4                  /**< VLCD电压档位4  0.624*VDD */
#define LCD_INNER_RESISTER_0_646_VDD                          LCD_FCR_CC_LV5                  /**< VLCD电压档位5  0.646*VDD */
#define LCD_INNER_RESISTER_0_670_VDD                          LCD_FCR_CC_LV6                  /**< VLCD电压档位6  0.670*VDD */
#define LCD_INNER_RESISTER_0_694_VDD                          LCD_FCR_CC_LV7                  /**< VLCD电压档位7  0.694*VDD */
#define LCD_INNER_RESISTER_0_722_VDD                          LCD_FCR_CC_LV8                  /**< VLCD电压档位8  0.722*VDD */
#define LCD_INNER_RESISTER_0_752_VDD                          LCD_FCR_CC_LV9                  /**< VLCD电压档位9  0.752*VDD */
#define LCD_INNER_RESISTER_0_786_VDD                          LCD_FCR_CC_LV10                 /**< VLCD电压档位10 0.786*VDD */
#define LCD_INNER_RESISTER_0_820_VDD                          LCD_FCR_CC_LV11                 /**< VLCD电压档位11 0.820*VDD */
#define LCD_INNER_RESISTER_0_860_VDD                          LCD_FCR_CC_LV12                 /**< VLCD电压档位12 0.860*VDD */
#define LCD_INNER_RESISTER_0_902_VDD                          LCD_FCR_CC_LV13                 /**< VLCD电压档位13 0.902*VDD */
#define LCD_INNER_RESISTER_0_950_VDD                          LCD_FCR_CC_LV14                 /**< VLCD电压档位14 0.950*VDD */
#define LCD_INNER_RESISTER_1_000_VDD                          LCD_FCR_CC_LV15                 /**< VLCD电压档位15 1.000*VDD */

/* LCD外设死区时间 */
#define LCD_DEAD_TIME_0                                       LCD_FCR_DEAD_0                  /**< 无死区 */
#define LCD_DEAD_TIME_1                                       LCD_FCR_DEAD_1                  /**< 死区时间1个ck_div */
#define LCD_DEAD_TIME_2                                       LCD_FCR_DEAD_2                  /**< 死区时间2个ck_div */
#define LCD_DEAD_TIME_3                                       LCD_FCR_DEAD_3                  /**< 死区时间3个ck_div */
#define LCD_DEAD_TIME_4                                       LCD_FCR_DEAD_4                  /**< 死区时间4个ck_div */
#define LCD_DEAD_TIME_5                                       LCD_FCR_DEAD_5                  /**< 死区时间5个ck_div */
#define LCD_DEAD_TIME_6                                       LCD_FCR_DEAD_6                  /**< 死区时间6个ck_div */
#define LCD_DEAD_TIME_7                                       LCD_FCR_DEAD_7                  /**< 死区时间7个ck_div */

/* LCD外设脉冲持续时间 */
#define LCD_PULSE_ON_DURATION_0                               LCD_FCR_PON_0                   /**< 脉冲持续时间 T = 0        */
#define LCD_PULSE_ON_DURATION_1                               LCD_FCR_PON_1                   /**< 脉冲持续时间 T = 1/ck_ps  */
#define LCD_PULSE_ON_DURATION_2                               LCD_FCR_PON_2                   /**< 脉冲持续时间 T = 2/ck_ps  */
#define LCD_PULSE_ON_DURATION_3                               LCD_FCR_PON_3                   /**< 脉冲持续时间 T = 3/ck_ps  */
#define LCD_PULSE_ON_DURATION_4                               LCD_FCR_PON_4                   /**< 脉冲持续时间 T = 4/ck_ps  */
#define LCD_PULSE_ON_DURATION_5                               LCD_FCR_PON_5                   /**< 脉冲持续时间 T = 5/ck_ps  */
#define LCD_PULSE_ON_DURATION_6                               LCD_FCR_PON_6                   /**< 脉冲持续时间 T = 6/ck_ps  */
#define LCD_PULSE_ON_DURATION_7                               LCD_FCR_PON_7                   /**< 脉冲持续时间 T = 7/ck_ps  */
#define LCD_PULSE_ON_DURATION_8                               LCD_FCR_PON_8                   /**< 脉冲持续时间 T = 8/ck_ps  */
#define LCD_PULSE_ON_DURATION_9                               LCD_FCR_PON_9                   /**< 脉冲持续时间 T = 9/ck_ps  */
#define LCD_PULSE_ON_DURATION_10                              LCD_FCR_PON_10                  /**< 脉冲持续时间 T = 10/ck_ps */
#define LCD_PULSE_ON_DURATION_11                              LCD_FCR_PON_11                  /**< 脉冲持续时间 T = 11/ck_ps */
#define LCD_PULSE_ON_DURATION_12                              LCD_FCR_PON_12                  /**< 脉冲持续时间 T = 12/ck_ps */
#define LCD_PULSE_ON_DURATION_13                              LCD_FCR_PON_13                  /**< 脉冲持续时间 T = 13/ck_ps */
#define LCD_PULSE_ON_DURATION_14                              LCD_FCR_PON_14                  /**< 脉冲持续时间 T = 14/ck_ps */
#define LCD_PULSE_ON_DURATION_15                              LCD_FCR_PON_15                  /**< 脉冲持续时间 T = 15/ck_ps */

/* LCD外设驱动能力 */
#define LCD_LOW_DRIVE                                         (0x00000000U)                   /**< 高阻抗弱驱动 */
#define LCD_HIGH_DRIVE                                        LCD_FCR_HD                      /**< 低阻抗强驱动 */

/* LCD防极化 */
#define LCD_ANTIPOLAR_FLOATING                                (0x00000000U)                   /**< COM和SEG引脚输出浮空      */                      
#define LCD_ANTIPOLAR_GND                                     LCD_FCR_ANTI_POLAR              /**< COM和SEG引脚输出连接到GND */

/* LCD COM和SEG输出控制 */        
#define LCD_SCOC_GND                                          (0x00000000U)                   /**< COM和SEG引脚输出连接到GND            */
#define LCD_SCOC_OUT                                          (LCD_FCR_SCOC)                  /**< COM和SEG引脚根据偏置和占空比配置输出 */    

/* LCD外设中断标志 */
#define LCD_INTERRUPT_SOF                                     LCD_FCR_SOFIE                   /**< 帧起始中断 */

/* LCD状态标志 */
#define LCD_FLAG_ENS                                          LCD_SR_ENS                      /**< 使能状态标志   */
#define LCD_FLAG_SOF                                          LCD_SR_SOF                      /**< 帧起始状态标志 */

/* LCD状态标志 */
#define LCD_CLEAR_FLAG_SOF                                    LCD_CLR_SOFC                    /**< 清零帧起始状态标志 */

/* LCD_RAM显示存储器 */
#define LCD_RAM_REGISTER0                                     (0x00000000U)                   /**< LCD RAM 存储器 0 */
#define LCD_RAM_REGISTER1                                     (0x00000001U)                   /**< LCD RAM 存储器 1 */
#define LCD_RAM_REGISTER2                                     (0x00000002U)                   /**< LCD RAM 存储器 2 */
#define LCD_RAM_REGISTER3                                     (0x00000003U)                   /**< LCD RAM 存储器 3 */
#define LCD_RAM_REGISTER4                                     (0x00000004U)                   /**< LCD RAM 存储器 4 */
#define LCD_RAM_REGISTER5                                     (0x00000005U)                   /**< LCD RAM 存储器 5 */
#define LCD_RAM_REGISTER6                                     (0x00000006U)                   /**< LCD RAM 存储器 6 */
#define LCD_RAM_REGISTER7                                     (0x00000007U)                   /**< LCD RAM 存储器 7 */
#define LCD_RAM_REGISTER8                                     (0x00000008U)                   /**< LCD RAM 存储器 8 */
#define LCD_RAM_REGISTER9                                     (0x00000009U)                   /**< LCD RAM 存储器 9 */

/**
* @}
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup LCD_External_Functions LCD External Functions
* @brief    LCD对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  LCD 外设使能
* @retval 无
*/
__STATIC_INLINE void std_lcd_enable(void)
{
    LCD->CR |= (LCD_CR_LCDEN);    
}

/**
* @brief  LCD 外设禁止
* @note   禁止外设后，输出驱动波形在当前帧结束后停止输出
* @retval 无
*/
__STATIC_INLINE void std_lcd_disable(void)
{
    LCD->CR &= (~LCD_CR_LCDEN); 
}

/**
* @brief  选择 LCD 占空比
* @param  duty LCD占空比选择                      
*             @arg LCD_DUTY_1_4                        
*             @arg LCD_DUTY_1_6                        
*             @arg LCD_DUTY_1_8
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_duty(uint32_t duty)
{
    MODIFY_REG(LCD->CR, LCD_CR_DUTY, (duty));
}

/**
* @brief  获取LCD占空比
* @retval uint32_t LCD占空比                       
*             @arg LCD_DUTY_1_4                        
*             @arg LCD_DUTY_1_6                        
*             @arg LCD_DUTY_1_8  
*/
__STATIC_INLINE uint32_t std_lcd_get_duty(void)
{
    return (LCD->CR & LCD_CR_DUTY);
}

/**
* @brief  选择LCD 偏置
* @param  bias LCD偏置               
*             @arg LCD_BIAS_1_3  
*             @arg LCD_BIAS_1_4
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_bias(uint32_t bias)
{
    MODIFY_REG(LCD->CR, LCD_CR_BIAS, (bias));
}

/**
* @brief  获取LCD偏置
* @retval uint32_t LCD偏置
*             @arg LCD_BIAS_1_3  
*             @arg LCD_BIAS_1_4
*/
__STATIC_INLINE uint32_t std_lcd_get_bias(void)
{
    return (LCD->CR & LCD_CR_BIAS);
}

/**
* @brief  选择LCD驱动模式
* @param  driver_mode LCD驱动模式             
*             @arg LCD_DRIVER_MODE_CHARGE_PUMP  
*             @arg LCD_DRIVER_MODE_INNER_RESISTER
*             @arg LCD_DRIVER_MODE_OUTER_CAPACITY
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_driver_mode(uint32_t driver_mode)
{
    MODIFY_REG(LCD->CR, LCD_CR_MDSET, (driver_mode));
}

/**
* @brief  获取LCD驱动模式
* @retval uint32_t LCD驱动模式
*             @arg LCD_DRIVER_MODE_CHARGE_PUMP  
*             @arg LCD_DRIVER_MODE_INNER_RESISTER
*             @arg LCD_DRIVER_MODE_OUTER_CAPACITY
*/
__STATIC_INLINE uint32_t std_lcd_get_driver_mode(void)
{
    return (LCD->CR & LCD_CR_MDSET);
}

/**
* @brief  配置LCD显示帧速率
* @param  clock_prescaler LCD时钟预分频
*             @arg LCD_PRESCALER_1
*             @arg ...
*             @arg LCD_PRESCALER_128
*             
* @param  clock_divider LCD时钟分频
*             @arg LCD_DIVIDER_16
*             @arg ...
*             @arg LCD_DIVIDER_31
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_display_frame_frequency(uint32_t clock_prescaler, uint32_t clock_divider)  
{
    MODIFY_REG(LCD->FCR, (LCD_FCR_PS | LCD_FCR_DIV), ((clock_prescaler) | (clock_divider)));
} 

/**
* @brief  设置LCD电荷泵和片外电容分压模式时钟分频
* @param  clock_div 时钟分频系数                      
*             @arg LCD_CPCLK_DIV1                        
*             @arg ...                        
*             @arg LCD_CPCLK_DIV128
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_chargepump_clock(uint32_t clock_div)
{
    MODIFY_REG(LCD->CR, LCD_CR_CPDIV, (clock_div));
}

/**
* @brief  获取LCD电荷泵和片外电容分压模式时钟分频
* @retval uint32_t 时钟分频系数
*             @arg LCD_CPCLK_DIV1
*             @arg ...
*             @arg LCD_CPCLK_DIV128
* 
*/
__STATIC_INLINE uint32_t std_lcd_get_chargepump_clock(void)
{
    return (LCD->CR & LCD_CR_CPDIV);
}

/**
* @brief  LCD 区段多路复用配置
* @param  mux_seg LCD区段多路复用配置
*             @arg LCD_MUX_SEGMENT_ENABLE                   
*             @arg LCD_MUX_SEGMENT_DISABLE
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_mux_seg(uint32_t mux_seg)
{
    MODIFY_REG(LCD->CR, LCD_CR_MUX_SEG, (mux_seg));
}

/**
* @brief  使能LCD_V1引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v1_cap_enable(void)
{
    LCD->CR |= (LCD_CR_LCD_CAP_V1);
}

/**
* @brief  禁止LCD_V1引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v1_cap_disable(void)
{
    LCD->CR &= (~LCD_CR_LCD_CAP_V1);
}

/**
* @brief  使能LCD_V2引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v2_cap_enable(void)
{
    LCD->CR |= (LCD_CR_LCD_CAP_V2);
}

/**
* @brief  禁止LCD_V2引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v2_cap_disable(void)
{
    LCD->CR &= (~LCD_CR_LCD_CAP_V2);
}

/**
* @brief  使能LCD_V3引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v3_cap_enable(void)
{
    LCD->CR |= (LCD_CR_LCD_CAP_V3);
}

/**
* @brief  禁止LCD_V3引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_v3_cap_disable(void)
{
    LCD->CR &= (~LCD_CR_LCD_CAP_V3);
}

/**
* @brief  使能VLCD引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_vlcd_cap_enable(void)

{
    LCD->CR |= (LCD_CR_LCD_CAP_VLCD);
}

/**
* @brief  禁止VLCD引脚连接外部电容
* @retval 无
*/
__STATIC_INLINE void std_lcd_vlcd_cap_disable(void)
{
    LCD->CR &= (~LCD_CR_LCD_CAP_VLCD);
}

/**
* @brief  LCD外设强驱动使能
* @retval 无
*/
__STATIC_INLINE void std_lcd_high_drive_enable(void)
{
    LCD->FCR |= (LCD_FCR_HD);
}

/**
* @brief  LCD外设强驱动禁止
* @retval 无
*/
__STATIC_INLINE void std_lcd_high_drive_disable(void)
{
    LCD->FCR &= (~LCD_FCR_HD);
}

/**
* @brief  LCD外设脉冲持续时间的配置
* @param  duration LCD脉冲持续时间
*             @arg LCD_PULSE_ON_DURATION_0
*             @arg LCD_PULSE_ON_DURATION_1
*             @arg ...
*             @arg LCD_PULSE_ON_DURATION_14
*             @arg LCD_PULSE_ON_DURATION_15
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_pulse_duration(uint32_t duration)    
{
    MODIFY_REG(LCD->FCR, LCD_FCR_PON, (duration));
}

/**
* @brief  LCD外设输出VLCD电压档位配置
* @param  vlcd_voltage VLCD电压档位
*             @arg LCD_CHAGE_PUMP_1_3_BIAS_2_55V
*             @arg ...
*             @arg LCD_CHAGE_PUMP_1_4_BIAS_2_60V
*             @arg ...
*             @arg LCD_INNER_RESISTER_0_548_VDD
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_vlcd_voltage(uint32_t vlcd_voltage)
{
    MODIFY_REG(LCD->FCR, LCD_FCR_CC, (vlcd_voltage));
}

/**
* @brief  设置LCD外设死区时间
* @param  deadtime LCD死区时间
*             @arg LCD_DEAD_TIME_0
*             @arg LCD_DEAD_TIME_1
*             @arg LCD_DEAD_TIME_2
*             @arg LCD_DEAD_TIME_3
*             @arg LCD_DEAD_TIME_4
*             @arg LCD_DEAD_TIME_5
*             @arg LCD_DEAD_TIME_6
*             @arg LCD_DEAD_TIME_7
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_dead_time(uint32_t deadtime)    
{
    MODIFY_REG(LCD->FCR, LCD_FCR_DEAD, (deadtime));
}

/**
* @brief  配置LCD外设闪烁模式和闪烁频率
* @param  mode LCD闪烁模式
*             @arg LCD_BLINK_MODE_OFF
*             @arg LCD_BLINK_MODE_SEG0_COM0
*             @arg LCD_BLINK_MODE_SEG0_ALLCOM
*             @arg LCD_BLINK_MODE_ALLSEG_ALLCOM          
* @param  blink_frequency LCD闪烁频率
*             @arg LCD_BLINK_FREQUENCY_DIV8
*             @arg LCD_BLINK_FREQUENCY_DIV16
*             @arg LCD_BLINK_FREQUENCY_DIV32
*             @arg LCD_BLINK_FREQUENCY_DIV64
*             @arg LCD_BLINK_FREQUENCY_DIV128
*             @arg LCD_BLINK_FREQUENCY_DIV256
*             @arg LCD_BLINK_FREQUENCY_DIV512
*             @arg LCD_BLINK_FREQUENCY_DIV1024
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_blink_frequency(uint32_t mode, uint32_t blink_frequency)  
{
    MODIFY_REG(LCD->FCR, (LCD_FCR_BLINK | LCD_FCR_BLINKF), ((mode) | (blink_frequency)));
} 

/**
* @brief  配置LCD防极化
* @param  state LCD防极化配置
*             @arg LCD_ANTIPOLAR_FLOATING
*             @arg LCD_ANTIPOLAR_GND
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_anti_polar(uint32_t state) 
{
    MODIFY_REG(LCD->FCR, LCD_FCR_ANTI_POLAR, state);
}
 
/**
* @brief  配置LCD COM和SEG输出
* @param  state COM和SEG输出配置
*             @arg LCD_SCOC_GND
*             @arg LCD_SCOC_OUT
* @retval 无
*/
__STATIC_INLINE void std_lcd_set_scoc(uint32_t state)  
{
    MODIFY_REG(LCD->FCR, LCD_FCR_SCOC, state);
}

/** 
* @brief  使能LCD外设中断
* @param  interrupt LCD中断源
*             @arg LCD_INTERRUPT_SOF
* @retval 无
*/
__STATIC_INLINE void std_lcd_interrupt_enable(uint32_t interrupt)  
{
    LCD->FCR |= (interrupt);
}

/** 
* @brief  禁止LCD外设中断
* @param  interrupt LCD中断源
*             @arg LCD_INTERRUPT_SOF
* @retval 无
*/
__STATIC_INLINE void std_lcd_interrupt_disable(uint32_t interrupt)  
{
    LCD->FCR  &= (~interrupt);
}

/** 
* @brief  获取LCD外设中断使能
* @param  interrupt LCD中断源
*             @arg LCD_INTERRUPT_SOF
* @retval bool 返回选择的中断源使能状态
*             @arg true:  表示选择中断源使能
*             @arg false: 表示选择中断源未使能
*/
__STATIC_INLINE bool std_lcd_get_interrupt_enable(uint32_t interrupt)  
{
    return ((LCD->FCR & interrupt) == (interrupt));
}

/**
* @brief  查询LCD状态标志
* @param  flag LCD状态标志
*             @arg LCD_FLAG_ENS
*             @arg LCD_FLAG_SOF
* @retval bool 返回标志的状态 
*             @arg true： 当前标志为置起状态 
*             @arg false：当前标志为清除状态
*/
__STATIC_INLINE bool std_lcd_get_flag(uint32_t flag)
{
    return ((LCD->SR & (flag)) == (flag));
}

/**
* @brief  清除LCD中断标志
* @param  clear_flag LCD中断标志
*             @arg LCD_CLEAR_FLAG_SOF                 
* @retval 无
*/
__STATIC_INLINE void std_lcd_clear_flag(uint32_t clear_flag)
{
    LCD->CLR |= (clear_flag);
}

/**
* @brief  写入指定LCD RAM数据
* @param lcd_ram_index 指定LCD_RAM 显示存储器
*            @arg LCD_RAM_REGISTER0
*            @arg LCD_RAM_REGISTER1
*            @arg LCD_RAM_REGISTER2
*            @arg LCD_RAM_REGISTER3
*            @arg LCD_RAM_REGISTER4
*            @arg LCD_RAM_REGISTER5
*            @arg LCD_RAM_REGISTER6
*            @arg LCD_RAM_REGISTER7
*            @arg LCD_RAM_REGISTER8
*            @arg LCD_RAM_REGISTER9
* @param  lcd_ram_mask LCD_RAM 显示存储器数据掩码
* @param  pixel 写入LCD_RAM的数值
* @retval 无
*/
__STATIC_INLINE void std_lcd_write(uint32_t lcd_ram_index, uint32_t lcd_ram_mask, uint32_t pixel)
{
    MODIFY_REG(LCD->RAM[lcd_ram_index], ~(lcd_ram_mask), pixel);
}

/* LCD初始化相关函数 */
void std_lcd_init(std_lcd_init_t *lcd_init_param);
void std_lcd_deinit(void);

/* LCD结构体初始化相关函数 */
void std_lcd_struct_init(std_lcd_init_t *lcd_init_struct);

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
#endif /* CIU32L051_STD_LCD_H */
