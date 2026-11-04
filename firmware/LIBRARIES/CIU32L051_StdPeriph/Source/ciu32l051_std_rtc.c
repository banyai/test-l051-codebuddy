/************************************************************************************************/
/**
* @file               ciu32l051_std_rtc.c
* @author             MCU Ecosystem Development Team
* @brief              RTC STD库驱动。
*                     实现了RTC模块的日历、闹钟初始化、去初始化API。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @addtogroup RTC 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_RTC_PERIPHERAL_USED
/*---------------------------------------- functions-------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup RTC_External_Functions 
* @{
*
*/
/************************************************************************************************/

/**
* @brief  RTC去初始化
* @retval 无
*/
void std_rtc_deinit(void)
{
    /* 关闭RTC寄存器写保护 */
    std_rtc_write_protection_disable();

    RTC->WUT = 0;
    RTC->CR  = 0;
    
    while(std_rtc_cal_get_status())
    {
    }
    RTC->CALR = 0;
    RTC->ALARMR = 0; 
    
    /* 进入RTC初始化模式 */
    if (std_rtc_init_mode_enter() == STD_OK)
    {
        /* 恢复日历默认值 */
        RTC->TR  = 0;
        RTC->DR  = 0x00002101;
        RTC->SSR = 0;
    }
    
    /* 退出RTC初始化模式 */
    std_rtc_init_mode_exit();
    
    /* RTC寄存器写保护使能 */
    std_rtc_write_protection_enable();
    
    /* 清除SR、ISR中标志 */
    RTC->CLR = 0xFFFFFFFF;
}

/**
* @brief  RTC日期初始化
* @param  rtc_date_init_param RTC日期初始化结构体
* @retval std_status_t API执行结果
*/
std_status_t std_rtc_date_init(std_rtc_date_t *rtc_date_init_param)
{
    std_status_t status = STD_ERR_TIMEOUT;

    /* 关闭RTC寄存器写保护 */
    std_rtc_write_protection_disable();

    /* 进入RTC初始化模式 */
    if (std_rtc_init_mode_enter() == STD_OK)
    {
        std_rtc_date_config(rtc_date_init_param->weekday, rtc_date_init_param->day, 
                            rtc_date_init_param->month,   rtc_date_init_param->year);

        /* 退出RTC初始化模式 */
        status = std_rtc_init_mode_exit();
    }
    
    /* RTC寄存器写保护使能 */
    std_rtc_write_protection_enable();
    
    return status;
}

/**
* @brief  RTC日期初始化结构体初始化
* @param  rtc_date_init_struct RTC初始化结构体
* @retval 无
*/
void std_rtc_date_struct_init(std_rtc_date_t *rtc_date_init_struct)
{
    /* 星期一/1月/1日/00年 */
    rtc_date_init_struct->weekday = RTC_WEEKDAY_MONDAY;
    rtc_date_init_struct->month   = RTC_MONTH_JANUARY;
    rtc_date_init_struct->day     = 1U;
    rtc_date_init_struct->year    = 0U;
}

/**
* @brief  RTC时间初始化
* @param  rtc_time_init_param RTC时间初始化结构体
* @retval std_status_t API执行结果
*/
std_status_t std_rtc_time_init(std_rtc_time_t *rtc_time_init_param)
{
    std_status_t status = STD_ERR_TIMEOUT;

    /* 关闭RTC寄存器写保护 */
    std_rtc_write_protection_disable();

    /* 进入RTC初始化模式 */
    if (std_rtc_init_mode_enter() == STD_OK)
    {
        std_rtc_time_config(rtc_time_init_param->hours,
                            rtc_time_init_param->minutes,
                            rtc_time_init_param->seconds);

        /* 退出RTC初始化模式 */
        status = std_rtc_init_mode_exit();
    }
    
    /* RTC寄存器写保护使能 */
    std_rtc_write_protection_enable();
    
    return status;
}

/**
* @brief  RTC时间初始化结构体初始化
* @param  rtc_time_init_struct RTC初始化结构体
* @retval 无
*/
void std_rtc_time_struct_init(std_rtc_time_t *rtc_time_init_struct)
{
    /* 00时:00分:00秒 */
    rtc_time_init_struct->hours   = 0U;
    rtc_time_init_struct->minutes = 0U;
    rtc_time_init_struct->seconds = 0U;
}

/**
* @brief  RTC闹钟初始化
* @param  rtc_alarm_init_param RTC闹钟初始化结构体
* @retval 无
*/
void std_rtc_alarm_init(std_rtc_alarm_t *rtc_alarm_init_param)
{
    /* 关闭RTC寄存器写保护 */
    std_rtc_write_protection_disable();
  
    /* 设置闹钟时间 */
    std_rtc_alarm_config(rtc_alarm_init_param->time.hours, 
                         rtc_alarm_init_param->time.minutes, 
                         rtc_alarm_init_param->time.seconds);

    /* 设置闹钟屏蔽位*/
    std_rtc_alarm_set_mask(rtc_alarm_init_param->time_mask);
        
    /* RTC寄存器写保护使能 */
    std_rtc_write_protection_enable();
}

/**
* @brief  RTC闹钟初始化结构体初始化
* @param  rtc_alarm_init_struct RTC初始化结构体
* @retval 无
*/
void std_rtc_alarm_struct_init(std_rtc_alarm_t *rtc_alarm_init_struct)
{
    rtc_alarm_init_struct->time_mask = RTC_ALARM_MASK_NONE;

    /* 初始化时间初始化结构体 */
    std_rtc_time_struct_init(&rtc_alarm_init_struct->time);
}

/**
* @brief  进入RTC初始化模式
* @retval std_status_t API执行结果
*/
std_status_t std_rtc_init_mode_enter(void)
{
    uint32_t timeout = RTC_INITMODE_TIMEOUT *(SystemCoreClock / 1000U);
    std_status_t status = STD_OK;
    
    /* 查询RTC当前所处模式 */
    if (std_rtc_get_mode() == RTC_MODE_RUNNING)
    {
        /* 初始化模式使能 */
        std_rtc_init_mode_enable();
        
        /* 等待RTC进入初始化模式 */
        while (std_rtc_get_mode() == RTC_MODE_RUNNING)
        {
            if (timeout == 0U)
            {
                status = STD_ERR_TIMEOUT;
                break;
            }
            timeout--;
        }        
    }
    
    return (status);
}

/**
* @brief  退出RTC初始化模式
* @retval std_status_t API执行结果
*/
std_status_t std_rtc_init_mode_exit(void)
{
    uint32_t timeout = RTC_INITMODE_TIMEOUT *(SystemCoreClock / 1000U);
    std_status_t status = STD_OK;
    
    /* 初始化模式禁止 */
    std_rtc_init_mode_disable();
    
    /* 等待RTC退出初始化模式 */
    while (std_rtc_get_mode() == RTC_MODE_INIT)
    {
        if (timeout == 0U)
        {
            status = STD_ERR_TIMEOUT;
            break;
        }
        timeout--;
    }
    
    return (status);
}

/** 
* @} 
*/

#endif /* STD_RTC_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
