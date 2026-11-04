/************************************************************************************************/
/**
* @file               ciu32l051_std_adc.c
* @author             MCU Ecosystem Development Team
* @brief              ADC STD库驱动。
*                     实现ADC初始化配置等功能API。
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
* @addtogroup ADC 
* @{
*
*/
/************************************************************************************************/


/*-------------------------------------------includes-------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_ADC_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup ADC_External_Functions 
* @{
*
*/
/************************************************************************************************/


/** 
* @brief  ADC初始化
* @param  adc_init_param ADC初始化结构体
* @note   若ADC时钟源配置为异步时钟，则需要在std_adc_init外部配置ADC异步时钟源
* @retval 无
*/
void std_adc_init(std_adc_init_t *adc_init_param)
{
    /* 时钟源配置 */
    std_adc_clock_source_config(adc_init_param->clock_src);
    /* 异步时钟分频配置 */
    if(adc_init_param->clock_src == ADC_ASYNC_CLK_KCLK)
    {
        std_adc_asynchronous_clock_config(adc_init_param->clock_presc);
    }
    
    if(adc_init_param->trigger_edge != ADC_TRIG_SW)
    {
        /* 配置外部触发源 */
        std_adc_external_trig_source_config(adc_init_param->trigger_source);
        /* 触发方式和极性配置 */
        std_adc_trig_edge_config(adc_init_param->trigger_edge);
    }
    else
    {
        /* 配置软件触发方式 */
        std_adc_trig_edge_config(adc_init_param->trigger_edge);
    }
    /* 转换模式配置 */
    std_adc_conversion_mode_config(adc_init_param->conver_mode);
    /* 采样时间参数1配置 */
    std_adc_sampt1_time_config(adc_init_param->sampt1);
    /* 采样时间参数2配置 */
    std_adc_sampt2_time_config(adc_init_param->sampt2);
    /* 数据溢出管理 */
    std_adc_ovrn_mode_config(adc_init_param->overrun_mode);
    /* 扫描方向配置 */
    std_adc_scan_direction_config(adc_init_param->scan_dir);
}


/** 
* @brief  ADC结构体初始化
* @param  adc_init_struct ADC初始化结构体
* @retval 无
*/
void std_adc_struct_init(std_adc_init_t *adc_init_struct)
{
    adc_init_struct->clock_src = ADC_SYNC_CLK_PCLK_DIV1;
    adc_init_struct->clock_presc = ADC_ASYNC_CLK_DIV1;
    adc_init_struct->conver_mode = ADC_SINGLE_CONVER_MODE;
    adc_init_struct->overrun_mode = ADC_OVRN_MODE_OVERWRITTEN;
    adc_init_struct->sampt1 = ADC_SAMPTIME_3CYCLES;
    adc_init_struct->sampt2 = ADC_SAMPTIME_3CYCLES;
    adc_init_struct->scan_dir = ADC_SCAN_DIR_FORWARD;
    adc_init_struct->trigger_edge = ADC_TRIG_SW;
    adc_init_struct->trigger_source = ADC_EXTRIG_EXTI11;
}


/** 
* @brief  ADC去初始化
* @note   执行去初始化前应停止转换
* @retval 无
*/
void std_adc_deinit(void)
{
    /* 禁止ADC */
    std_adc_disable();
    /* 复位ADC外设 */
    std_rcc_apb2_reset(RCC_PERIPH_RESET_ADC);
    
    /* 禁止ADC外设时钟 */
    std_rcc_apb2_clk_disable(RCC_PERIPH_CLK_ADC);  
}


/** 
* @} 
*/

#endif /* STD_ADC_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
