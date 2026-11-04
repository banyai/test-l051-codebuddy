/************************************************************************************************/
/**
* @file               ciu32l051_std.c
* @author             MCU Ecosystem Development Team
* @brief              STD库基础功能驱动。
*                     实现STD库的计时等功能API。
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
* @addtogroup STD 
* @{
*
*/
/************************************************************************************************/  

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"




/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup STD_External_Functions 
* @{
*
*/
/************************************************************************************************/

/**
* @brief  Systick初始化
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @retval 无
*/
__weak void std_delay_init(void)
{
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/**
* @brief  us级延时函数（阻塞模式）
* @param  count 计数周期
* @note   延时函数最大值受限于SysTick重载值寄存器的最大值0xFFFFFF（16777216）
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @retval 无
*/
__weak void std_delayus(uint32_t count)
{
    count = STD_DELAY_US * count;
    count = count > 16777216 ? 16777216 : count;
    SysTick->LOAD = count - 1;
    SysTick->VAL = 0;
    while(!((SysTick->CTRL >> 16) & 0x1));
}

/**
* @brief  ms级延时函数（阻塞模式）
* @param  count 计数周期
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @retval 无
*/
__weak void std_delayms(uint32_t count)
{
    while(count--)
    {
        std_delayus(1000);
    }
}

/**
* @brief  us级延时函数（非阻塞模式）
* @param  count 计数周期
* @note   延时函数最大值受限于SysTick重载值寄存器的最大值0xFFFFFF（16777216）
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @retval 无
*/
__weak void std_delayus_start(uint32_t count)
{
    count = STD_DELAY_US * count;
    count = count > 16777216 ? 16777216 : count;
    SysTick->LOAD = count - 1;
    SysTick->VAL = 0;
}

/**
* @brief  ms级延时函数（非阻塞模式）
* @param  count 计数周期
* @note   延时函数最大值受限于SysTick重载值寄存器的最大值0xFFFFFF（16777216）
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @retval 无
*/
__weak void std_delayms_start(uint32_t count)
{
    std_delayus_start(1000 * count);
}


/**
* @brief  获取计数结束状态（非阻塞模式）
* @note   该函数为weak函数，用户可选择其他定时器重新定义实现该函数
* @note   该函数与std_delayus_start和std_delayms_start函数组合使用，用于判断计数结束状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示计数已结束
*             @arg false：表示计数正在进行中
*/
__weak bool std_delay_end(void)
{
    return (((SysTick->CTRL >> 16) & 0x1) == 0x1);
}

/** 
* @} 
*/


/** 
* @} 
*/

/** 
* @} 
*/
