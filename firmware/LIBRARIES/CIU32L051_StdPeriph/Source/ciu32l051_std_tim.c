/************************************************************************************************/
/**
* @file               ciu32l051_std_tim.c
* @author             MCU Ecosystem Development Team
* @brief              TIM STD库驱动。
*                     实现TIM基本计数、输入捕获、输出比较等功能初始化API。
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
* @addtogroup TIM
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_TIM_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup TIM_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  TIM初始化
* @param  timx TIM外设
* @param  pvd_init_param TIM初始化结构体
* @note   由于DIR位在中心对齐模式下为只读，从中心对齐模式切换到边沿对齐计数器模式(或反向)，
*         需要停止计数后修改，以避免造成计数异常。
* @retval std_status_t 返回API执行结果
*/
void std_tim_init(TIM_t *timx, std_tim_basic_init_t *pvd_init_param)
{     
    /* 设置自动加载值 */
    std_tim_set_autoreload(timx, pvd_init_param->period);   
     
    /* 设置自动加载预加载，并清除计数模式选择配置 */
    /* 修改计数方式，需先切换到边沿模式，才能修改DIR控制位 */   
    MODIFY_REG(timx->CR1, (TIM_CR1_ARPE | TIM_CR1_CMS), pvd_init_param->auto_reload_preload);    

    /* 选择计数器模式 */
    std_tim_set_counter_mode(timx, pvd_init_param->counter_mode);
        
    /* 设置时钟分频 */
    std_tim_set_clock_div(timx, pvd_init_param->clock_div);   
    
    /* 设置预分频值 */
    std_tim_set_psc(timx, pvd_init_param->prescaler);
       
    /* 生成一个更新事件来重新加载预预分频值 */
    std_tim_set_sw_trig_event(timx, TIM_EVENT_SRC_UPDATE);
    
    /* 清除所有标志 */
    std_tim_clear_flag(timx, TIM_FLAG_ALL);
}

/**
* @brief  TIM去初始化
* @param  timx TIM外设
* @retval 无
*/
void std_tim_deinit(TIM_t *timx)    
{    
    std_tim_disable(timx);   
    
    /* 复位外设 */
    if(TIM3 == timx)
    {
        std_rcc_apb1_reset(RCC_PERIPH_RESET_TIM3);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_TIM3);
    }
    else if(TIM4 == timx)
    {
        std_rcc_apb1_reset(RCC_PERIPH_RESET_TIM4);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_TIM4);
    }
    else if(TIM5 == timx)
    {
        std_rcc_apb1_reset(RCC_PERIPH_RESET_TIM5);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_TIM5);
    }
    else if(TIM8 == timx)
    {
        std_rcc_apb1_reset(RCC_PERIPH_RESET_TIM8);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_TIM8);
    }
    else
    {
        ;/* 暂无操作 */
    }      
    
}

/**
* @brief  设置std_tim_basic_init_t结构体为默认值
* @param  tim_init_struct TIM初始化结构体
* @retval 无
*/
void std_tim_struct_init(std_tim_basic_init_t *tim_init_struct)
{
    tim_init_struct->prescaler             = 0x00U;
    tim_init_struct->counter_mode          = TIM_COUNTER_MODE_UP;
    tim_init_struct->period                = 0xFFFFU;
    tim_init_struct->clock_div             = TIM_CLOCK_DTS_DIV1;
    tim_init_struct->auto_reload_preload   = TIM_AUTORELOAD_PRE_DISABLE;
}


/**
* @brief  配置TIM输入捕获通道
* @param  timx TIM外设
* @param  input_config TIM 输入捕获配置结构体
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
void std_tim_input_capture_init(TIM_t *timx, std_tim_input_capture_init_t *input_config, uint32_t channel_id)
{       
    /* 禁止CCxE位 */
    std_tim_ccx_channel_disable(timx, channel_id);
   
    /* 选择输入源和滤波参数 */
    std_tim_set_icmode(timx, channel_id, input_config->input_capture_sel);
    std_tim_set_icfilter(timx, channel_id, input_config->input_capture_filter);
     
    /* 选择极性 */
    std_tim_set_input_pol(timx, channel_id, input_config->input_capture_pol);
    
    /* 配置TIM输入预分频参数 */
    std_tim_set_channel_icxpsc(timx, channel_id, input_config->input_capture_prescaler);
}


/**
* @brief  设置std_tim_input_capture_init_t结构体为默认值
* @param  input_init_struct TIM输入捕获结构体
* @retval 无
*/
void std_tim_input_capture_struct_init(std_tim_input_capture_init_t *input_init_struct)
{
    input_init_struct->input_capture_pol       = TIM_INPUT_POL_RISING;
    input_init_struct->input_capture_sel       = TIM_INPUT_CAPTURE_SEL_DIRECTTI;
    input_init_struct->input_capture_prescaler = TIM_INPUT_CAPTURE_PSC_DIV1;
    input_init_struct->input_capture_filter    = 0x00U;
}


/**
* @brief  配置TIM比较输出参数
* @param  timx TIM外设
* @param  output_config TIM 输出比较配置结构体
* @param  channel_id TIM 通道配置
*             @arg TIM_CHANNEL_1
*             @arg TIM_CHANNEL_2
*             @arg TIM_CHANNEL_3
*             @arg TIM_CHANNEL_4
* @retval 无
*/
void std_tim_output_compare_init(TIM_t *timx, std_tim_output_compare_init_t *output_config, uint32_t channel_id)
{          
    /* 禁止CCxE和CCxNE位 */
    std_tim_ccx_channel_disable(timx, channel_id);

    /* 选择输出比较模式 */
    std_tim_set_ocmode(timx, channel_id, output_config->output_compare_mode);   
    
    /* 设置输出比较极性 */
    std_tim_set_output_pol(timx, channel_id, output_config->output_pol);
    
    /* 输出比较预装载模式配置 */
    if (output_config->output_preloadccx  == TIM_OUTPUT_PRECC_ENABLE)
    {
        std_tim_preloadccx_channel_enable(timx, channel_id);
    }
    else
    {
        std_tim_preloadccx_channel_disable(timx, channel_id);
    }
    
    /* 快速模式配置 */
    if (output_config->output_fast_mode  == TIM_OUTPUT_FAST_ENABLE)
    {
        std_tim_fastmode_channel_enable(timx, channel_id);
    }
    else
    {
        std_tim_fastmode_channel_disable(timx, channel_id);
    }  
      
    /* 配置比较匹配值 */
    std_tim_set_ccx_value(timx, channel_id, output_config->pulse);
}


/**
* @brief  设置std_tim_output_compare_init_t结构体为默认值
* @param  output_init_struct TIM输出结构体
* @retval 无
*/
void std_tim_output_compare_struct_init(std_tim_output_compare_init_t *output_init_struct)
{
    output_init_struct->output_compare_mode         = TIM_OUTPUT_MODE_FROZEN;
    output_init_struct->pulse                       = 0x00U;
    output_init_struct->output_pol                  = TIM_OUTPUT_POL_HIGH;
    output_init_struct->output_preloadccx           = TIM_OUTPUT_PRECC_DISABLE;
    output_init_struct->output_fast_mode            = TIM_OUTPUT_FAST_DISABLE;
}



/** 
* @} 
*/

#endif /* STD_TIM_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
