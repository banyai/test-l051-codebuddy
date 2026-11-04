/************************************************************************************************/
/**
* @file               ciu32L051_std_usart.c
* @author             MCU Ecosystem Development Team
* @brief              USART STD库驱动。
*                     实现USART初始化、波特率配置、clock配置等功能API。
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
* @addtogroup USART 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32L051_std.h"


#ifdef STD_USART_PERIPHERAL_USED
/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup USART_External_Functions 
* @{
*
*/
/************************************************************************************************/ 


/**
* @brief  USART初始化
* @param  usartx USART外设
* @param  usart_init_param USART初始化结构体
* @retval std_status_t 返回初始化配置结果
*/
std_status_t std_usart_init(USART_t *usartx,std_usart_init_t *usart_init_param)
{
    /* 设置USART字长 */
    std_usart_set_word_length(usartx,usart_init_param->wordlength);
    
    /* 设置USART停止位 */
    std_usart_set_stopbits(usartx,usart_init_param->stopbits);
    
    /* 设置USART过采样，如果配置为8倍过采样可以达到最大通信速率 */
    std_usart_set_over_sample(usartx,usart_init_param->over_sample);
    
    /* 设置USART通信模式(单发送、单接收、发送/接收)*/
    std_usart_set_transfer_direction(usartx,usart_init_param->direction);
    
    /* 设置奇偶校验 */
    std_usart_set_parity(usartx,usart_init_param->parity);
    
    /* 设置硬件流控 */
    std_usart_set_hardflow_control(usartx,usart_init_param->hardware_flow);
    
    /* 设置波特率 */
    if(std_usart_baudrate_config(usartx,usart_init_param->baudrate)!=STD_OK)
    {
        return STD_ERR;
    }
    
    return STD_OK;
    
}


/**
* @brief  USART去初始化
* @param  usartx USART外设
* @retval std_status_t 返回去初始化结果
*/
void std_usart_deinit(USART_t *usartx)
{
    std_usart_disable(usartx);

    /* USART 的RCC时钟复位 */
    if(usartx == USART1)
    {
        /* 复位USART1 */
        std_rcc_apb2_reset(RCC_PERIPH_RESET_USART1);
        /* 关闭USART1时钟 */
        std_rcc_apb2_clk_disable(RCC_PERIPH_CLK_USART1);
    }
    else if(usartx == UART2)
    {
        /* 复位UART2 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_UART2);
        /* 关闭UART2时钟 */
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_UART2);
    }
    else if(usartx == UART3)
    {
        /* 复位UART3 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_UART3);
        /* 关闭UART3时钟 */
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_UART3);
    }
    else if(usartx == UART4)
    {
        /* 复位UART4 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_UART4);
        /* 关闭UART4时钟 */
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_UART4);
    }
    else
    {
        /* 暂无操作 */
    }
}


/**
* @brief  USART结构体初始化
* @param  usart_init_struct USART结构体
* @retval 无
*/
void std_usart_struct_init(std_usart_init_t *usart_init_struct)
{ 
    usart_init_struct->baudrate = 115200;
    usart_init_struct->over_sample = USART_OVERSAMPLE_16;
    usart_init_struct->wordlength = USART_WORDLENGTH_8BITS;
    usart_init_struct->stopbits = USART_STOPBITS_1;
    usart_init_struct->direction = USART_DIRECTION_SEND_RECEIVE;
    usart_init_struct->parity = USART_PARITY_NONE;
    usart_init_struct->hardware_flow = USART_FLOWCONTROL_NONE;
}


/**
* @brief  USART同步时钟初始化
* @param  usartx   USART外设
* @param  usart_sync_clk_init_param USART同步时钟结构体
* @retval 无
*/
void std_usart_sync_clk_init(USART_t *usartx, std_usart_sync_clk_init_t *usart_sync_clk_init_param)
{
    /* 配置CK引脚时钟输出 */
    if( USART_CLOCK_ENABLE == usart_sync_clk_init_param->sync_clk)
    {        
        std_usart_clk_enable(usartx);
    }
    else
    {
        std_usart_clk_disable(usartx);
    } 
    
    /* 设置同步时钟相位 */
    std_usart_set_sync_clk_phase(usartx,usart_sync_clk_init_param->sync_clock_phase);
    
    /* 设置同步时钟极性 */
    std_usart_set_sync_clk_polarity(usartx,usart_sync_clk_init_param->sync_clock_polarity);
    
}

/**
* @brief  USART同步时钟结构体初始化
* @param  usart_sync_clk_struct USART同步时钟结构体
* @retval 无
*/
void std_usart_sync_clk_struct_init(std_usart_sync_clk_init_t *usart_sync_clk_struct)
{
    usart_sync_clk_struct->sync_clk = USART_CLOCK_ENABLE;
    usart_sync_clk_struct->sync_clock_polarity = USART_SYNC_POLARITY_LOW;
    usart_sync_clk_struct->sync_clock_phase = USART_SYNC_PHASE_1EDGE;
}


/**
* @brief  设置USART波特率
* @param  usartx   USART外设
* @param  baudrate 波特率
* @retval std_status_t 返回波特率设置结果
*/
std_status_t std_usart_baudrate_config(USART_t *usartx, uint32_t baudrate)
{
    uint32_t pclk;
    uint32_t over_sample;
    uint32_t brr_value;
    
    /* 获取USART时钟频率 */
    if(usartx == USART1)
    {
        pclk = std_rcc_get_pclk2freq();
    }
    else if((usartx == UART2) | (usartx == UART3) | (usartx == UART4))
    {
        pclk = std_rcc_get_pclk1freq();
    }
    else
    {
        return STD_ERR;
    }
    
    /* 获取过采样配置 */
    over_sample=std_usart_get_over_sample(usartx);
    
    /* 波特率计算 */
    if(over_sample == USART_OVERSAMPLE_8)
    {
        brr_value = ((((pclk)<<1U) + ((baudrate)>>1U)) / (baudrate));    
    }
    else if(over_sample == USART_OVERSAMPLE_16)
    {
        brr_value = (((pclk)+((baudrate)>>1U))/(baudrate));
    }
    else
    {
        return STD_ERR;
    }
  
    /* BRR取值范围[0x10,0xFFFF], 必须大于0x10(0d16) */    
    if ((brr_value >= USART_BRR_MIN) && (brr_value <= USART_BRR_MAX))
    {
        usartx->BRR = (uint32_t)brr_value;
        return STD_OK;
    }
    else
    {
        return STD_ERR;
    }
}


/** 
* @} 
*/

#endif /* STD_USART_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/


