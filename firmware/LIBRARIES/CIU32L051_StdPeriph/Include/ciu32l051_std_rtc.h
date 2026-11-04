/************************************************************************************************/
/**
* @file               ciu32l051_std_rtc.h
* @author             MCU Ecosystem Development Team
* @brief              RTC STD库驱动头文件。
*                     提供RTC的STD库操作函数声明、数据类型以及常量的定义。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_RTC_H
#define CIU32L051_STD_RTC_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup RTC RTC
* @brief 实时时钟的STD库驱动 
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
* @defgroup RTC_Types RTC Types
* @brief RTC数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  RTC日历时间参数结构体定义
*/
typedef struct
{
    uint8_t  hours;                         /**< RTC 日历小时（BCD格式），24小时制，取值0~23  */
    uint8_t  minutes;                       /**< RTC 日历分钟（BCD格式），取值0~59            */
    uint8_t  seconds;                       /**< RTC 日历秒（BCD格式），取值0~59              */
} std_rtc_time_t;

/**
* @brief  RTC日历日期参数结构体定义
*/
typedef struct
{
    uint8_t  weekday;                       /**< RTC 日历星期
                                                     @arg RTC_WEEKDAY_MONDAY ...  */
    uint8_t  month;                         /**< RTC 日历月份（BCD格式） 
                                                     @arg RTC_MONTH_JANUARY  ...  */
    uint8_t  day;                           /**< RTC 日历日期（BCD格式）          */
    uint8_t  year;                          /**< RTC 日历年份（BCD格式）          */
} std_rtc_date_t;

/**
* @brief  RTC闹钟参数结构体定义
*/
typedef struct
{
    std_rtc_time_t time;                    /**< RTC 闹钟设定时间                 */
    uint32_t       time_mask;               /**< RTC 闹钟屏蔽
                                                      @arg RTC_ALARM_MASK_NONE ...*/
} std_rtc_alarm_t;

/** 
* @} 
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup RTC_Constants RTC Constants
* @brief    RTC常量定义及宏定义                                    
* @{
*
*/
/************************************************************************************************/

/* RTC超时等待时间 */
#define RTC_INITMODE_TIMEOUT                (1000U)

/* RTC模式 */
#define RTC_MODE_RUNNING                    (0x00000000U)              /**< 正常运行模式 */
#define RTC_MODE_INIT                       RTC_CSR_MODSTA             /**< 初始化模式   */
                                                                       
/* RTC_OUT输出信号 */                                                  
#define RTC_OUTPUT_APRE_256HZ               RTC_CR_OUT_SEL_APRE        /**< 输出异步预分频器输出时钟256Hz */
#define RTC_OUTPUT_SPRE_1HZ                 RTC_CR_OUT_SEL_SPRE        /**< 输出同步预分频器输出时钟1Hz   */
#define RTC_OUTPUT_ALARM                    RTC_CR_OUT_SEL_ALARMF      /**< 输出闹钟匹配状态              */
#define RTC_OUTPUT_MINUTE                   RTC_CR_OUT_SEL_MIN         /**< 输出日历分钟进位信号          */
#define RTC_OUTPUT_HOUR                     RTC_CR_OUT_SEL_HOUR        /**< 输出日历小时进位信号          */
#define RTC_OUTPUT_DAY                      RTC_CR_OUT_SEL_DAY         /**< 输出日历天进位信号            */
#define RTC_OUTPUT_CALIB_CYCLE              RTC_CR_OUT_SEL_CAL         /**< 输出校准周期信号              */
                                                                       
/* RTC_OUT信号输出极性 */                                              
#define RTC_OUT_POLARITY_NORMAL             (0x00000000U)              /**< 有标志置起输出高电平 */
#define RTC_OUT_POLARITY_REVERSE            RTC_CR_POL                 /**< 有标志置起输出低电平 */
                                                                       
/* RTC_OUT信号输出使能控制 */                                          
#define RTC_OUT_DISABLE                     (0x00000000U)              /**< RTC_OUT输出禁止 */
#define RTC_OUT_ENABLE                      RTC_CR_OUTEN               /**< RTC_OUT输出使能 */

/* RTC日历月份（BCD格式） */ 
#define RTC_MONTH_JANUARY                   ((uint8_t)0x01U)           /**< 1月    */
#define RTC_MONTH_FEBRUARY                  ((uint8_t)0x02U)           /**< 2月    */
#define RTC_MONTH_MARCH                     ((uint8_t)0x03U)           /**< 3月    */
#define RTC_MONTH_APRIL                     ((uint8_t)0x04U)           /**< 4月    */
#define RTC_MONTH_MAY                       ((uint8_t)0x05U)           /**< 5月    */
#define RTC_MONTH_JUNE                      ((uint8_t)0x06U)           /**< 6月    */
#define RTC_MONTH_JULY                      ((uint8_t)0x07U)           /**< 7月    */
#define RTC_MONTH_AUGUST                    ((uint8_t)0x08U)           /**< 8月    */
#define RTC_MONTH_SEPTEMBER                 ((uint8_t)0x09U)           /**< 9月    */
#define RTC_MONTH_OCTOBER                   ((uint8_t)0x10U)           /**< 10月   */
#define RTC_MONTH_NOVEMBER                  ((uint8_t)0x11U)           /**< 11月   */
#define RTC_MONTH_DECEMBER                  ((uint8_t)0x12U)           /**< 12月   */

/* RTC日历星期 */ 
#define RTC_WEEKDAY_MONDAY                  ((uint8_t)0x01U)           /**< 星期一 */
#define RTC_WEEKDAY_TUESDAY                 ((uint8_t)0x02U)           /**< 星期二 */
#define RTC_WEEKDAY_WEDNESDAY               ((uint8_t)0x03U)           /**< 星期三 */
#define RTC_WEEKDAY_THURSDAY                ((uint8_t)0x04U)           /**< 星期四 */
#define RTC_WEEKDAY_FRIDAY                  ((uint8_t)0x05U)           /**< 星期五 */
#define RTC_WEEKDAY_SATURDAY                ((uint8_t)0x06U)           /**< 星期六 */
#define RTC_WEEKDAY_SUNDAY                  ((uint8_t)0x07U)           /**< 星期日 */

/* 日期/时间偏移量 */
#define RTC_OFFSET_YEAR                     ((uint32_t)16U)
#define RTC_OFFSET_MONTH                    ((uint32_t)8U)
#define RTC_OFFSET_HOUR                     ((uint32_t)16U)
#define RTC_OFFSET_MINUTE                   ((uint32_t)8U)

/* 日期/时间 */
#define RTC_DAY_MASK                        (RTC_DR_DT  | RTC_DR_DU)   /**< 日期 */
#define RTC_MONTH_MASK                      (RTC_DR_MT  | RTC_DR_MU)   /**< 月份 */
#define RTC_YEAR_MASK                       (RTC_DR_YT  | RTC_DR_YU)   /**< 年份 */
#define RTC_HOUR_MASK                       (RTC_TR_HT  | RTC_TR_HU)   /**< 小时 */
#define RTC_MINUTE_MASK                     (RTC_TR_MNT | RTC_TR_MNU)  /**< 分钟 */
#define RTC_SECOND_MASK                     (RTC_TR_ST  | RTC_TR_SU)   /**< 秒钟 */

/* 闹钟时间 */
#define RTC_ALARM_HOUR_MASK                 (RTC_ALARMR_HT  | RTC_ALARMR_HU)   /**< 闹钟小时 */
#define RTC_ALARM_MINUTE_MASK               (RTC_ALARMR_MNT | RTC_ALARMR_MNU)  /**< 闹钟分钟 */
#define RTC_ALARM_SECOND_MASK               (RTC_ALARMR_ST  | RTC_ALARMR_SU)   /**< 闹钟秒钟 */

/* RTC闹钟时间域屏蔽配置 */                                            
#define RTC_ALARM_MASK_NONE                 (0x00000000U)              /**< 闹钟所有域未屏蔽，均参与日历比较       */
#define RTC_ALARM_MASK_HOURS                RTC_ALARMR_MSK3            /**< 闹钟小时域被屏蔽，不参与日历比较       */
#define RTC_ALARM_MASK_MINUTES              RTC_ALARMR_MSK2            /**< 闹钟分钟域被屏蔽，不参与日历比较       */
#define RTC_ALARM_MASK_SECONDS              RTC_ALARMR_MSK1            /**< 闹钟秒钟域被屏蔽，不参与日历比较       */
#define RTC_ALARM_MASK_ALL                  RTC_ALARMR_MSKALL          /**< 闹钟所有域均被屏蔽，不参与日历比较     */
#define RTC_ALARM_MASK_HOURMIN              (RTC_ALARM_MASK_HOURS   \
                                           | RTC_ALARM_MASK_MINUTES)   /**< 闹钟小时与分钟域被屏蔽，不参与日历比较 */
#define RTC_ALARM_MASK_HOURSEC              (RTC_ALARM_MASK_HOURS   \
                                           | RTC_ALARM_MASK_SECONDS)   /**< 闹钟小时与秒钟域被屏蔽，不参与日历比较 */
#define RTC_ALARM_MASK_MINSEC               (RTC_ALARM_MASK_MINUTES \
                                           | RTC_ALARM_MASK_SECONDS)   /**< 闹钟分钟域秒钟域被屏蔽，不参与日历比较 */

/* RTC周期定时器中断使能 */
#define RTC_WUT_INTERRUPT_DAY               RTC_WUT_DAYIE              /**< 天进位中断使能             */
#define RTC_WUT_INTERRUPT_HOUR              RTC_WUT_HOURIE             /**< 小时进位中断使能           */
#define RTC_WUT_INTERRUPT_MIN               RTC_WUT_MINIE              /**< 分钟进位中断使能           */
#define RTC_WUT_INTERRUPT_SEC               RTC_WUT_SECIE              /**< 秒进位中断使能             */
#define RTC_WUT_INTERRUPT_2HZ               RTC_WUT_2HZIE              /**< 2Hz周期定时中断使能        */
#define RTC_WUT_INTERRUPT_4HZ               RTC_WUT_4HZIE              /**< 4Hz周期定时中断使能        */
#define RTC_WUT_INTERRUPT_8HZ               RTC_WUT_8HZIE              /**< 8Hz周期定时中断使能        */
#define RTC_WUT_INTERRUPT_16HZ              RTC_WUT_16HZIE             /**< 16Hz周期定时中断使能       */
#define RTC_WUT_INTERRUPT_64HZ              RTC_WUT_64HZIE             /**< 64Hz周期定时中断使能       */
#define RTC_WUT_INTERRUPT_256HZ             RTC_WUT_256HZIE            /**< 256Hz周期定时中断使能      */
#define RTC_WUT_INTERRUPT_1024HZ            RTC_WUT_1024HZIE           /**< 1024Hz周期定时中断使能     */

/* RTC中断标志 */
#define RTC_INTERRUPT_FLAG_ALARM            RTC_ISR_ALARMIF            /**< 闹钟中断标志               */
#define RTC_INTERRUPT_FLAG_CALIBRATION      RTC_ISR_CALIIF             /**< 校准周期中断标志           */
#define RTC_INTERRUPT_FLAG_DAY              RTC_ISR_DAYIF              /**< 天进位中断标志             */
#define RTC_INTERRUPT_FLAG_HOUR             RTC_ISR_HOURIF             /**< 小时进位中断标志           */
#define RTC_INTERRUPT_FLAG_MIN              RTC_ISR_MINIF              /**< 分钟进位中断标志           */
#define RTC_INTERRUPT_FLAG_SEC              RTC_ISR_SECIF              /**< 秒进位中断标志             */
#define RTC_INTERRUPT_FLAG_2HZ              RTC_ISR_2HZIF              /**< 2Hz周期定时中断标志        */
#define RTC_INTERRUPT_FLAG_4HZ              RTC_ISR_4HZIF              /**< 4Hz周期定时中断标志        */
#define RTC_INTERRUPT_FLAG_8HZ              RTC_ISR_8HZIF              /**< 8Hz周期定时中断标志        */
#define RTC_INTERRUPT_FLAG_16HZ             RTC_ISR_16HZIF             /**< 16Hz周期定时中断标志       */
#define RTC_INTERRUPT_FLAG_64HZ             RTC_ISR_64HZIF             /**< 64Hz周期定时中断标志       */
#define RTC_INTERRUPT_FLAG_256HZ            RTC_ISR_256HZIF            /**< 256Hz周期定时中断标志      */
#define RTC_INTERRUPT_FLAG_1024HZ           RTC_ISR_1024HZIF           /**< 1024Hz周期定时中断标志     */
                                                                       
/* RTC标志 */                                                          
#define RTC_FLAG_ALARM                      RTC_SR_ALARMF              /**< 闹钟标志                   */
#define RTC_FLAG_CALIBRATION                RTC_SR_CALF                /**< 校准周期标志               */
#define RTC_FLAG_TIMESTAMP                  RTC_SR_TSF                 /**< 时间戳标志                 */
#define RTC_FLAG_DAY                        RTC_SR_DAYF                /**< 天进位标志                 */
#define RTC_FLAG_HOUR                       RTC_SR_HOURF               /**< 小时进位标志               */
#define RTC_FLAG_MIN                        RTC_SR_MINF                /**< 分钟进位标志               */
#define RTC_FLAG_SEC                        RTC_SR_SECF                /**< 秒进位标志                 */
#define RTC_FLAG_2HZ                        RTC_SR_2HZF                /**< 2Hz周期定时标志            */
#define RTC_FLAG_4HZ                        RTC_SR_4HZF                /**< 4Hz周期定时标志            */
#define RTC_FLAG_8HZ                        RTC_SR_8HZF                /**< 8Hz周期定时标志            */
#define RTC_FLAG_16HZ                       RTC_SR_16HZF               /**< 16Hz周期定时标志           */
#define RTC_FLAG_64HZ                       RTC_SR_64HZF               /**< 64Hz周期定时标志           */
#define RTC_FLAG_256HZ                      RTC_SR_256HZF              /**< 256Hz周期定时标志          */
#define RTC_FLAG_1024HZ                     RTC_SR_1024HZF             /**< 1024Hz周期定时标志         */

/* RTC标志清除位 */
#define RTC_CLEAR_ALARM                     RTC_CLR_CALARMF            /**< 清除闹钟标志               */
#define RTC_CLEAR_CALIBRATION               RTC_CLR_CCALF              /**< 清除校准周期标志           */
#define RTC_CLEAR_TIMESTAMP                 RTC_CLR_CTSF               /**< 清除时间戳标志             */
#define RTC_CLEAR_DAY                       RTC_CLR_CDAYF              /**< 清除天进位标志             */
#define RTC_CLEAR_HOUR                      RTC_CLR_CHOURF             /**< 清除小时进位标志           */
#define RTC_CLEAR_MIN                       RTC_CLR_CMINF              /**< 清除分钟进位标志           */
#define RTC_CLEAR_SEC                       RTC_CLR_CSECF              /**< 清除秒进位标志             */
#define RTC_CLEAR_2HZ                       RTC_CLR_C2HZF              /**< 清除2Hz进位标志            */
#define RTC_CLEAR_4HZ                       RTC_CLR_C4HZF              /**< 清除4Hz进位标志            */
#define RTC_CLEAR_8HZ                       RTC_CLR_C8HZF              /**< 清除8Hz进位标志            */
#define RTC_CLEAR_16HZ                      RTC_CLR_C16HZF             /**< 清除16Hz进位标志           */
#define RTC_CLEAR_64HZ                      RTC_CLR_C64HZF             /**< 清除64Hz进位标志           */
#define RTC_CLEAR_256HZ                     RTC_CLR_C256HZF            /**< 清除256Hz进位标志          */
#define RTC_CLEAR_1024HZ                    RTC_CLR_C1024HZF           /**< 清除1024Hz进位标志         */

/* RTC平滑校准脉冲增加配置 */          
#define RTC_SMOOTH_CALIB_PLUS_PULSES_RESET   (0x00000000U)             /**< 不增加脉冲                 */
#define RTC_SMOOTH_CALIB_PLUS_PULSES_SET     RTC_CALR_CALP             /**< 每隔2^11个RTCLK增加1个脉冲 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup RTC_External_Functions RTC External Functions
* @brief    RTC对外函数
* @{
*
*/
/************************************************************************************************/

/**
*@brief  BIN转BCD
*@param  value BIN格式数字
*@retval uint8_t BCD格式数字
*/
__STATIC_INLINE uint8_t std_rtc_convert_bin2bcd(uint8_t value)
{
    return (uint8_t)((((value) / 10U) << 4U) | ((value) % 10U));
}

/**
*@brief  BCD转BIN
*@param  value BCD格式数字
*@retval uint8_t BIN格式数字
*/
__STATIC_INLINE uint8_t std_rtc_convert_bcd2bin(uint8_t value)
{
    return (uint8_t)(((((value) & 0xF0U) >> 0x4U) * 10U ) + ((value) & 0x0FU));
}


/**
* @brief  使能RTC寄存器写保护
* @retval 无
*/
__STATIC_INLINE void std_rtc_write_protection_enable(void)
{
    RTC->WPR = 0x00U;
}

/**
* @brief  禁止RTC寄存器写保护
* @retval 无
*/
__STATIC_INLINE void std_rtc_write_protection_disable(void)
{
    RTC->WPR = 0xCAU;
    RTC->WPR = 0x53U;
}

/**
* @brief  使能RTC初始化
* @retval 无
*/
__STATIC_INLINE void std_rtc_init_mode_enable(void)
{
    RTC->CSR |= RTC_CSR_MODSEL;
}

/**
* @brief  禁止RTC初始化
* @retval 无
*/
__STATIC_INLINE void std_rtc_init_mode_disable(void)
{
    RTC->CSR &= (~RTC_CSR_MODSEL);
}

/**
* @brief  读取RTC模式状态
* @retval uint32_t RTC模式状态
*             @arg RTC_MODE_RUNNING
*             @arg RTC_MODE_INIT
*/
__STATIC_INLINE uint32_t std_rtc_get_mode(void)
{
    return (RTC->CSR & RTC_CSR_MODSTA);
}

/**
* @brief  配置日历日期（BCD格式）
* @param  weekday 星期
*             @arg RTC_WEEKDAY_MONDAY  
*             @arg RTC_WEEKDAY_TUESDAY 
*             @arg ...     
*             @arg RTC_WEEKDAY_SUNDAY     
* @param  day 日期（最小0x01，最大0x31）
* @param  month 月份
*             @arg RTC_MONTH_JANUARY  
*             @arg RTC_MONTH_FEBRUARY 
*             @arg ... 
*             @arg RTC_MONTH_DECEMBER 
* @param  year 年份（最小0x00，最大0x99）
* @retval 无
*/
__STATIC_INLINE void std_rtc_date_config(uint32_t weekday, uint32_t day, uint32_t month, uint32_t year)
{
    uint32_t temp;

    temp = (weekday << RTC_DR_WDU_POS) \
         | (((year  & 0xF0U) << (RTC_DR_YT_POS - 4U)) | ((year  & 0x0FU) << RTC_DR_YU_POS)) \
         | (((month & 0xF0U) << (RTC_DR_MT_POS - 4U)) | ((month & 0x0FU) << RTC_DR_MU_POS)) \
         | (((day   & 0xF0U) << (RTC_DR_DT_POS - 4U)) | ((day   & 0x0FU) << RTC_DR_DU_POS));

    RTC->DR = temp;
}

/**
* @brief  读取日历日期（BCD格式）
* @retval uint32_t 日期（星期+年+月+日）
*/
__STATIC_INLINE uint32_t std_rtc_date_get_date(void)
{
    uint32_t temp;
    temp = RTC->DR;    
    return (uint32_t)((temp & (~RTC_DR_WDU)) | ((temp & RTC_DR_WDU) << 11));
}

/**
* @brief  设置日历日期（BCD格式）
* @param  day 日期（最小0x01，最大0x31）
* @retval 无
*/
__STATIC_INLINE void std_rtc_date_set_day(uint32_t day)
{
    MODIFY_REG(RTC->DR, RTC_DAY_MASK,
              (((day & 0xF0U) << (RTC_DR_DT_POS - 4U)) | ((day & 0x0FU) << RTC_DR_DU_POS)));
}

/**
* @brief  读取日历日期（BCD格式）
* @retval uint32_t 日期 （最小0x01，最大0x31）
*/
__STATIC_INLINE uint32_t std_rtc_date_get_day(void)
{
    return ((RTC->DR & RTC_DAY_MASK) >> RTC_DR_DU_POS);
}

/**
* @brief  设置日历月份（BCD格式）
* @param  month 月份
*             @arg RTC_MONTH_JANUARY  
*             @arg RTC_MONTH_FEBRUARY 
*             @arg ... 
*             @arg RTC_MONTH_DECEMBER 
* @retval 无
*/
__STATIC_INLINE void std_rtc_date_set_month(uint32_t month)
{
    MODIFY_REG(RTC->DR, RTC_MONTH_MASK,
              (((month & 0xF0U) << (RTC_DR_MT_POS - 4U)) | ((month & 0x0FU) << RTC_DR_MU_POS)));
}

/**
* @brief  读取日历月份（BCD格式）
* @retval uint32_t 月份
*             @arg RTC_MONTH_JANUARY  
*             @arg RTC_MONTH_FEBRUARY 
*             @arg ... 
*             @arg RTC_MONTH_DECEMBER 
*/
__STATIC_INLINE uint32_t std_rtc_date_get_month(void)
{
    return ((RTC->DR & RTC_MONTH_MASK) >> RTC_DR_MU_POS);
}

/**
* @brief  设置日历星期（BCD格式）
* @param  weekday 星期
*             @arg RTC_WEEKDAY_MONDAY  
*             @arg RTC_WEEKDAY_TUESDAY 
*             @arg ...     
*             @arg RTC_WEEKDAY_SUNDAY     
* @retval 无
*/
__STATIC_INLINE void std_rtc_date_set_weekday(uint32_t weekday)
{
    MODIFY_REG(RTC->DR, RTC_DR_WDU, (weekday << RTC_DR_WDU_POS));
}

/**
* @brief  读取日历星期（BCD格式）
* @retval uint32_t 星期
*             @arg RTC_WEEKDAY_MONDAY  
*             @arg RTC_WEEKDAY_TUESDAY 
*             @arg ...     
*             @arg RTC_WEEKDAY_SUNDAY     
*/
__STATIC_INLINE uint32_t std_rtc_date_get_weekday(void)
{
    return ((RTC->DR & RTC_DR_WDU) >> RTC_DR_WDU_POS);
}

/**
* @brief  设置日历年份（BCD格式）
* @param  year 年份（最小0x00，最大0x99）
* @retval 无
*/
__STATIC_INLINE void std_rtc_date_set_year(uint32_t year)
{
    MODIFY_REG(RTC->DR, RTC_YEAR_MASK,
              (((year & 0xF0U) << (RTC_DR_YT_POS - 4U)) | ((year & 0x0FU) << RTC_DR_YU_POS)));
}

/**
* @brief  读取日历年份（BCD格式）
* @retval uint32_t 年份（最小0x00，最大0x99）
*/
__STATIC_INLINE uint32_t std_rtc_date_get_year(void)
{
    return ((RTC->DR & RTC_YEAR_MASK) >> RTC_DR_YU_POS);
}

/**
* @brief  配置日历时间（BCD格式）
* @param  hours 小时（最小0x00，最大0x23）
* @param  minutes 分钟（最小0x00，最大0x59）
* @param  seconds 秒钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_time_config(uint32_t hours, uint32_t minutes, uint32_t seconds)
{
    uint32_t temp;

    temp = (((hours & 0xF0U)   << (RTC_TR_HT_POS  - 4U)) | ((hours & 0x0FU)   << RTC_TR_HU_POS))  \
         | (((minutes & 0xF0U) << (RTC_TR_MNT_POS - 4U)) | ((minutes & 0x0FU) << RTC_TR_MNU_POS)) \
         | (((seconds & 0xF0U) << (RTC_TR_ST_POS  - 4U)) | ((seconds & 0x0FU) << RTC_TR_SU_POS));
    
    RTC->TR = temp; 
}

/**
* @brief  读取日历时间（BCD格式）
* @retval uint32_t 时间（时钟+分钟+秒钟）
*/
__STATIC_INLINE uint32_t std_rtc_time_get_time(void)
{
    return (RTC->TR);
}

/**
* @brief  设置日历小时（BCD格式）
* @param  hours 小时（最小0x00，最大0x23）
* @retval 无
*/
__STATIC_INLINE void std_rtc_time_set_hour(uint32_t hours)
{
    MODIFY_REG(RTC->TR, RTC_HOUR_MASK,
              (((hours & 0xF0U) << (RTC_TR_HT_POS - 4U)) | ((hours & 0x0FU) << RTC_TR_HU_POS)));
}

/**
* @brief  设置日历分钟（BCD格式）
* @param  minutes 分钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_time_set_minute(uint32_t minutes)
{
    MODIFY_REG(RTC->TR, RTC_MINUTE_MASK,
              (((minutes & 0xF0U) << (RTC_TR_MNT_POS - 4U)) | ((minutes & 0x0FU) << RTC_TR_MNU_POS)));
}

/**
* @brief  设置日历秒钟（BCD格式）
* @param  seconds 秒钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_time_set_second(uint32_t seconds)
{
    MODIFY_REG(RTC->TR, RTC_SECOND_MASK,
              (((seconds & 0xF0U) << (RTC_TR_ST_POS - 4U)) | ((seconds & 0x0FU) << RTC_TR_SU_POS)));
}

/**
* @brief  设置日历亚秒
* @param  subseconds 亚秒（最小0x00，最大0xff，单位1/256 s）
* @retval 无
*/
__STATIC_INLINE void std_rtc_time_set_subsecond(uint32_t subseconds)
{
    RTC->SSR = subseconds;
}

/**
* @brief  读取日历亚秒（BCD格式）
* @retval uint32_t 亚秒
*/
__STATIC_INLINE uint32_t std_rtc_time_get_subsecond(void)
{
    return (RTC->SSR);
}


/**
* @brief  选择RTC时钟输出信号
* @param  rtc_out 校准时钟输出信号
*             @arg RTC_OUTPUT_APRE_256HZ  
*             @arg RTC_OUTPUT_SPRE_1HZ
*             @arg ...
*             @arg RTC_OUTPUT_CALIB_CYCLE
* @retval 无
*/
__STATIC_INLINE void std_rtc_out_config(uint32_t rtc_out)
{
    MODIFY_REG(RTC->CR, RTC_CR_OUT_SEL, rtc_out);
}

/**
* @brief  读取RTC时钟输出信号
* @retval uint32_t 校准时钟输出信号
*             @arg RTC_OUTPUT_APRE_256HZ  
*             @arg RTC_OUTPUT_SPRE_1HZ
*             @arg ...
*             @arg RTC_OUTPUT_CALIB_CYCLE
*/
__STATIC_INLINE uint32_t std_rtc_get_rtc_out(void)
{
    return (RTC->CR & RTC_CR_OUT_SEL);
}

/**
* @brief  设置RTC OUT信号输出极性
* @param  polarity 输出极性
*             @arg RTC_OUT_POLARITY_NORMAL
*             @arg RTC_OUT_POLARITY_REVERSE
* @retval 无
*/
__STATIC_INLINE void std_rtc_set_output_polarity(uint32_t polarity)
{
    MODIFY_REG(RTC->CR, RTC_CR_POL, polarity);
}

/**
* @brief  读取RTC OUT信号输出极性
* @retval uint32_t 输出极性
*             @arg RTC_OUT_POLARITY_NORMAL
*             @arg RTC_OUT_POLARITY_REVERSE
*/
__STATIC_INLINE uint32_t std_rtc_get_output_polarity(void)
{
    return (RTC->CR & RTC_CR_POL);
}

/** 
* @brief  使能RTC OUT信号输出
* @retval 无
*/
__STATIC_INLINE void std_rtc_output_enable(void)
{
    RTC->CR |= RTC_CR_OUTEN;
} 

/** 
* @brief  关闭RTC OUT信号输出
* @retval 无
*/
__STATIC_INLINE void std_rtc_output_disable(void)
{
    RTC->CR &= (~RTC_CR_OUTEN);
}


/**
* @brief  使能RTC周期定时中断
* @param  wut_interrupt_sel
*             @arg RTC_WUT_INTERRUPT_DAY
*             @arg RTC_WUT_INTERRUPT_HOUR
*             @arg ...
*             @arg RTC_WUT_INTERRUPT_1024HZ
* @retval 无
*/
__STATIC_INLINE void std_rtc_wut_interrupt_enable(uint32_t wut_interrupt_sel)
{
    RTC->WUT |= wut_interrupt_sel;
}

/**
* @brief  禁止RTC周期定时中断
* @param  wut_interrupt_sel
*             @arg RTC_WUT_INTERRUPT_DAY
*             @arg RTC_WUT_INTERRUPT_HOUR
*             @arg ...
*             @arg RTC_WUT_INTERRUPT_1024HZ
* @retval 无
*/
__STATIC_INLINE void std_rtc_wut_interrupt_disable(uint32_t wut_interrupt_sel)
{
    RTC->WUT &= (~wut_interrupt_sel);
}

/**
* @brief  读取RTC周期定时中断使能状态
* @param  wut_interrupt_sel
*             @arg RTC_WUT_INTERRUPT_DAY
*             @arg RTC_WUT_INTERRUPT_HOUR
*             @arg ...
*             @arg RTC_WUT_INTERRUPT_1024HZ
* @retval bool 标志状态
*             @arg true  表示定时中断使能
*             @arg false 表示定时中断关闭
*/
__STATIC_INLINE bool std_rtc_get_wut_interrupt_enable(uint32_t wut_interrupt_sel)
{
    return ((RTC->WUT & wut_interrupt_sel) == wut_interrupt_sel);
}


/**
* @brief  使能闹钟
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_enable(void)
{
    RTC->CR |= RTC_CR_ALARME;
}

/**
* @brief  禁止闹钟
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_disable(void)
{
    RTC->CR &= (~RTC_CR_ALARME);
}

/**
* @brief  配置闹钟时间（BCD格式）
* @param  hours   小时（最小0x00，最大0x23）
* @param  minutes 分钟（最小0x00，最大0x59）
* @param  seconds 秒钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_config(uint32_t hours, uint32_t minutes, uint32_t seconds)
{
    register uint32_t temp;

    temp = (((hours   & 0xF0U) << (RTC_ALARMR_HT_POS  - 4U)) | ((hours   & 0x0FU) << RTC_ALARMR_HU_POS))
         | (((minutes & 0xF0U) << (RTC_ALARMR_MNT_POS - 4U)) | ((minutes & 0x0FU) << RTC_ALARMR_MNU_POS))
         | (((seconds & 0xF0U) << (RTC_ALARMR_ST_POS  - 4U)) | ((seconds & 0x0FU) << RTC_ALARMR_SU_POS));

    MODIFY_REG(RTC->ALARMR, (RTC_ALARM_HOUR_MASK | RTC_ALARM_MINUTE_MASK | RTC_ALARM_SECOND_MASK), temp);
}

/**
* @brief  读取闹钟时间（BCD格式）
* @retval uint32_t 时间（时+分+秒）
*/
__STATIC_INLINE uint32_t std_rtc_alarm_get_time(void)
{
    return (uint32_t)(RTC->ALARMR & (RTC_ALARM_HOUR_MASK | RTC_ALARM_MINUTE_MASK | RTC_ALARM_SECOND_MASK));
}

/**
* @brief  设置闹钟小时（BCD格式）
* @param  hours 小时（最小0x00，最大0x23）
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_set_hour(uint32_t hours)
{
    MODIFY_REG(RTC->ALARMR, RTC_ALARM_HOUR_MASK,
              (((hours & 0xF0U) << (RTC_ALARMR_HT_POS - 4U)) | ((hours & 0x0FU) << RTC_ALARMR_HU_POS)));
}

/**
* @brief  读取闹钟小时（BCD格式）
* @retval uint32_t 小时（最小0x00，最大0x23）
*/
__STATIC_INLINE uint32_t std_rtc_alarm_get_hour(void)
{
    return ((RTC->ALARMR & RTC_ALARM_HOUR_MASK) >> RTC_ALARMR_HU_POS);
}

/**
* @brief  设置闹钟分钟（BCD格式）
* @param  minutes 分钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_set_minute(uint32_t minutes)
{
    MODIFY_REG(RTC->ALARMR, RTC_ALARM_MINUTE_MASK,
              (((minutes & 0xF0U) << (RTC_ALARMR_MNT_POS - 4U)) | ((minutes & 0x0FU) << RTC_ALARMR_MNU_POS)));
}

/**
* @brief  读取闹钟分钟（BCD格式）
* @retval uint32_t 分钟（最小0x00，最大0x59）
*/
__STATIC_INLINE uint32_t std_rtc_alarm_get_minute(void)
{
    return ((RTC->ALARMR & RTC_ALARM_MINUTE_MASK) >> RTC_ALARMR_MNU_POS);
}

/**
* @brief  设置闹钟秒钟（BCD格式）
* @param  seconds 秒钟（最小0x00，最大0x59）
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_set_second(uint32_t seconds)
{
    MODIFY_REG(RTC->ALARMR, RTC_ALARM_SECOND_MASK,
              (((seconds & 0xF0U) << (RTC_ALARMR_ST_POS - 4U)) | ((seconds & 0x0FU) << RTC_ALARMR_SU_POS)));
}

/**
* @brief  读取闹钟秒钟（BCD格式）
* @retval uint32_t 秒钟（最小0x00，最大0x59）
*/
__STATIC_INLINE uint32_t std_rtc_alarm_get_second(void)
{
    return ((RTC->ALARMR & RTC_ALARM_SECOND_MASK) >> RTC_ALARMR_SU_POS);
}

/**
* @brief  使能闹钟中断
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_interrupt_enable(void)
{
    RTC->CR |= RTC_CR_ALARMIE;
}

/**
* @brief  禁止闹钟中断
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_interrupt_disable(void)
{
    RTC->CR &= (~RTC_CR_ALARMIE);
}

/**
* @brief  读取RTC闹钟中断使能状态
* @retval bool 标志状态
*             @arg true  表示闹钟中断使能
*             @arg false 表示闹钟中断关闭
*/
__STATIC_INLINE bool std_rtc_get_alarm_interrupt_enable()
{
    return ((RTC->CR & RTC_CR_ALARMIE) == RTC_CR_ALARMIE);
}

/**
* @brief  设置闹钟时间屏蔽
* @param  alarm_mask 时间屏蔽位组合
*             @arg RTC_ALARM_MASK_NONE
*             @arg RTC_ALARM_MASK_HOURS
*             @arg ...
*             @arg RTC_ALARM_MASK_MINSEC
* @retval 无
*/
__STATIC_INLINE void std_rtc_alarm_set_mask(uint32_t alarm_mask)
{
    MODIFY_REG(RTC->ALARMR, RTC_ALARMR_MSKALL, alarm_mask);
}

/**
* @brief  读取闹钟时间屏蔽
* @retval uint32_t 时间屏蔽位
*             @arg RTC_ALARM_MASK_NONE
*             @arg RTC_ALARM_MASK_HOURS
*             @arg ...
*             @arg RTC_ALARM_MASK_MINSEC
*/
__STATIC_INLINE uint32_t std_rtc_alarm_get_mask(void)
{
    return (RTC->ALARMR & RTC_ALARM_MASK_ALL);
}


/**
* @brief  读取时钟数字平滑校准状态
* @retval bool 时钟数字平滑校准状态
*             @arg true  表示校准参数已写入，尚未生效
*             @arg false 表示校准参数已生效，可写入新值
*/
__STATIC_INLINE bool std_rtc_cal_get_status(void)
{
    return ((RTC->CSR & RTC_CSR_CALSTA) == RTC_CSR_CALSTA);
}

/**
* @brief  配置数字平滑校准参数
* @param  calib_plus 插入时钟脉冲控制
*             @arg RTC_SMOOTH_CALIB_PLUS_PULSES_RESET  
*             @arg RTC_SMOOTH_CALIB_PLUS_PULSES_SET   
* @param  calib_minus 屏蔽时钟脉冲个数
* @retval 无
*/
__STATIC_INLINE void std_rtc_cal_config(uint32_t calib_plus, uint32_t calib_minus)
{
    RTC->CALR = (uint32_t)(calib_plus | calib_minus);
}

/**
* @brief  读取数字平滑校准插入时钟脉冲
* @retval uint32_t 数字平滑校准插入时钟脉冲
*             @arg RTC_SMOOTH_CALIB_PLUS_PULSES_RESET  
*             @arg RTC_SMOOTH_CALIB_PLUS_PULSES_SET   
*/
__STATIC_INLINE uint32_t std_rtc_cal_get_plus(void)
{
    return (RTC->CALR & RTC_CALR_CALP);
}

/**
* @brief  读取数字平滑校准脉冲屏蔽个数
* @retval uint32_t 数字平滑校准脉冲屏蔽个数（最小0x00，最大0x1FF）
*/
__STATIC_INLINE uint32_t std_rtc_cal_get_minus(void)
{
    return (RTC->CALR & RTC_CALR_CALM);
}

/**
* @brief  使能校准周期中断
* @retval 无
*/
__STATIC_INLINE void std_rtc_calib_interrupt_enable(void)
{
    RTC->CR |= RTC_CR_CALIE;
}

/**
* @brief  禁止校准周期中断
* @retval 无
*/
__STATIC_INLINE void std_rtc_calib_interrupt_disable(void)
{
    RTC->CR &= (~RTC_CR_CALIE);
}

/**
* @brief  读取RTC校准周期中断使能状态
* @retval bool 标志状态
*             @arg true  表示RTC校准周期中断使能
*             @arg false 表示RTC校准周期中断关闭
*/
__STATIC_INLINE bool std_rtc_get_calib_interrupt_enable()
{
    return ((RTC->CR & RTC_CR_CALIE) == RTC_CR_CALIE);
}


/**
* @brief  读取时间戳日期（BCD格式）
* @retval uint32_t 日期 
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_day(void)
{
    return (RTC->TSDR & (RTC_TSDR_DT | RTC_TSDR_DU));
}

/**
* @brief  读取时间戳月份（BCD格式）
* @retval uint32_t 月份
*             @arg RTC_MONTH_JANUARY  
*             @arg RTC_MONTH_FEBRUARY 
*             @arg ... 
*             @arg RTC_MONTH_DECEMBER 
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_month(void)
{
    return ((RTC->TSDR & (RTC_TSDR_MT | RTC_TSDR_MU)) >> RTC_TSDR_MU_POS);
}

/**
* @brief  读取时间戳日期（BCD格式）
* @retval uint32_t 日期（月份+日期）
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_date(void)
{
    return (RTC->TSDR);
}

/**
* @brief  读取时间戳小时（BCD格式）
* @retval uint32_t 小时（最小0x00，最大0x23）
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_hour(void)
{
    return ((RTC->TSTR & (RTC_TSTR_HT | RTC_TSTR_HU)) >> RTC_TSTR_HU_POS);
}

/**
* @brief  读取时间戳分钟（BCD格式）
* @retval uint32_t 分钟（最小0x00，最大0x59）
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_minute(void)
{
    return ((RTC->TSTR & (RTC_TSTR_MNT | RTC_TSTR_MNU)) >> RTC_TSTR_MNU_POS);
}

/**
* @brief  读取时间戳秒钟（BCD格式）
* @retval uint32_t 秒钟（最小0x00，最大0x59）
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_second(void)
{
    return (RTC->TSTR & (RTC_TSTR_ST | RTC_TSTR_SU));
}

/**
* @brief  读取时间戳时间（BCD格式）
* @retval uint32_t 时间（时钟+分钟+秒钟）
*/
__STATIC_INLINE uint32_t std_rtc_timestamp_get_time(void)
{
  return (RTC->TSTR);
}


/**
* @brief  读取状态标志
* @param  flag 标志
*             @arg RTC_FLAG_ALARM
*             @arg RTC_FLAG_CALIBRATION
*             @arg ...
*             @arg RTC_FLAG_1024HZ
* @retval bool 标志状态
*             @arg true  表示标志置1
*             @arg false 表示标志清0
*/
__STATIC_INLINE bool std_rtc_get_flag(uint32_t flag)
{
    return ((RTC->SR & flag) == flag);
}

/**
* @brief  读取中断状态标志
* @param  interrupt 标志
*             @arg RTC_INTERRUPT_FLAG_ALARM
*             @arg RTC_INTERRUPT_FLAG_CALIBRATION
*             @arg ...
*             @arg RTC_INTERRUPT_FLAG_1024HZ
* @retval bool 中断状态
*             @arg true  表示中断已发生
*             @arg false 表示中断未发生
*/
__STATIC_INLINE bool std_rtc_get_interrupt_flag(uint32_t interrupt)
{
    return ((RTC->ISR & interrupt) == interrupt);
}

/**
* @brief  清除状态标志
* @param  flag 标志
*             @arg RTC_CLEAR_ALARM
*             @arg RTC_CLEAR_CALIBRATION
*             @arg ...
*             @arg RTC_CLEAR_1024HZ
* @retval 无
*/
__STATIC_INLINE void std_rtc_clear_flag(uint32_t flag)
{
    RTC->CLR = flag;
}


void std_rtc_deinit(void);

std_status_t std_rtc_date_init(std_rtc_date_t *rtc_date_init_param);
void std_rtc_date_struct_init(std_rtc_date_t *rtc_date_init_struct);

std_status_t std_rtc_time_init(std_rtc_time_t *rtc_time_init_param);
void std_rtc_time_struct_init(std_rtc_time_t *rtc_time_init_struct);

void std_rtc_alarm_init(std_rtc_alarm_t *rtc_alarm_init_param);
void std_rtc_alarm_struct_init(std_rtc_alarm_t *rtc_alarm_init_struct);

std_status_t std_rtc_init_mode_enter(void);
std_status_t std_rtc_init_mode_exit(void);

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

#endif /* CIU32L051_STD_RTC_H */
