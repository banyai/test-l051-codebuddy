/************************************************************************************************/
/**
* @file               ciu32l051_std_pmu.c
* @author             MCU Ecosystem Development Team
* @brief              PMU STD库驱动。
*                     实现PVD配置、低功耗模式进入等功能API。
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
* @addtogroup PMU 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_PMU_PERIPHERAL_USED


/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup PMU_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  PMU去初始化
* @note   本函数初始化为默认值的内容如下：
*             VCORE_AON域写操作禁止；
*             低功耗模式选择；
*             PVD中断标志。
* @note   本函数不修改的内容如下：
*             BGR使能控制位；
*             PVD相关配置参数。
* @retval 无
*/
void std_pmu_reg_reset(void)
{
    PMU->CR1 &= (~PMU_CR1_VAON_WEN_MASK);  
    PMU->CR3 = PMU_CR3_DEFAULT_VALUE;
    PMU->CLR = PMU_CLR_FLAG_VALUE;  
}

/**
* @brief  配置PVD的监测源、报警阈值、工作模式等
* @param  pvd_init_param  PVD的配置信息     
* @note   当SYSCFG_SECCR寄存器中PVD_LOCK置位或PVD使能时，不允许更改PVD的配置，调用本函数前应保证PVD_LOCK未置位，且PVD处于禁止状态
* @retval std_status_t 返回API执行结果
*/
void std_pmu_pvd_init(std_pvd_init_t *pvd_init_param)
{
    /* 清零PVD配置 */
    PMU->CR2 = 0U;
       
    /* 配置PVD监测阈值 */
    std_pmu_pvd_level_config(pvd_init_param->level);
              
    if (PVD_FILTER_TIME_ENABLE == pvd_init_param->filter_enable)
    {
        /* 配置PVD的数字滤波时间 */
        std_pmu_pvd_filter_config(pvd_init_param->filter_time);
        
        /* 使能PVD滤波 */
        std_pmu_pvd_filter_enable();
    }
   
    /* 配置有效信号边沿 */
    std_pmu_pvd_alarm_enable(pvd_init_param->alarm_type);  
}

/**
* @brief  设置PVD结构体为默认值
* @param  pvd_init_struct PVD的配置信息    
* @retval 无
*/
void std_pmu_struct_init(std_pvd_init_t *pvd_init_struct)
{
    pvd_init_struct->level          = PMU_PVD_LEVEL_7;
    pvd_init_struct->alarm_type     = PMU_PVD_RISING;
    pvd_init_struct->filter_enable  = PVD_FILTER_TIME_DISABLE;
    pvd_init_struct->filter_time    = PVD_FILTER_TIME_2PCLK;
}

/**
* @brief  进入sleep模式
* @param  mode_entry 进入低功耗模式的方式
*             @arg PMU_ENTRY_LOWPOWER_MODE_WFE
*             @arg PMU_ENTRY_LOWPOWER_MODE_WFI
* @retval 无
*/
void std_pmu_enter_sleep(uint32_t mode_entry)
{    
    /* 清除 SLEEPDEEP 标志 */
    SCB->SCR &= (~SCB_SCR_SLEEPDEEP_Msk); 
    
    /* 处理低功耗模式的进入方式*/
    if(PMU_ENTRY_LOWPOWER_MODE_WFI == mode_entry)
    {
        __WFI();
    }
    else
    {
        /* 先生成一个事件，通过WFE清除事件，重新调用WFE进入低功耗模式*/
        __SEV();
        __WFE();
        __WFE();
    }
}

/**
* @brief  进入stop模式
* @param  mode_entry 进入低功耗模式的方式
*             @arg PMU_ENTRY_LOWPOWER_MODE_WFE
*             @arg PMU_ENTRY_LOWPOWER_MODE_WFI
* @retval 无
*/
void std_pmu_enter_stop(uint32_t mode_entry)
{       
    /* 置位SLEEPDEEP标志 */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;   
    
     /* 处理低功耗模式的进入方式*/
    if(PMU_ENTRY_LOWPOWER_MODE_WFI == mode_entry)
    {
        __WFI();
    }
    else
    {
        /* 先生成一个事件，通过WFE清除事件，重新调用WFE进入低功耗模式*/
        __SEV();
        __WFE();
        __WFE();
    }   
    
    /* 还原SLEEPDEEP标志 */
    SCB->SCR &= (~SCB_SCR_SLEEPDEEP_Msk);
}

/** 
* @} 
*/

#endif /* STD_PMU_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/

