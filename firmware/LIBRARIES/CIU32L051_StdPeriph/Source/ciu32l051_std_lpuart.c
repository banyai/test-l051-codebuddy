/************************************************************************************************/
/**
* @file               ciu32L051_std_lpuart.c
* @author             MCU Ecosystem Development Team
* @brief              LPUART STD库驱动。
*                     实现LPUART配置等API。
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
* @addtogroup LPUART 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32L051_std.h"

#ifdef STD_LPUART_PERIPHERAL_USED
/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup LPUART_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  LPUART 初始化
* @param  lpuartx LPUART外设
* @param  lpuart_init_param 初始化结构体
* @retval std_status_t 返回API执行结果
*/
std_status_t std_lpuart_init(LPUART_t *lpuartx, std_lpuart_init_t *lpuart_init_param)
{
    uint32_t direction = 0U;    
    /* 禁用LPUART */
    std_lpuart_disable(lpuartx);
 
    /* 配置字符长度 */
    std_lpuart_set_word_length(lpuartx,lpuart_init_param->wordlength);
    /* 配置奇偶校验 */
    std_lpuart_set_parity(lpuartx,lpuart_init_param->parity);
    /* 配置停止位 */
    std_lpuart_set_stopbits(lpuartx,lpuart_init_param->stopbits);
    /* 配置预分频 */
    std_lpuart_set_kclk_prescaler(lpuartx,lpuart_init_param->prescaler);
    /* 配置硬件流控 */
    std_lpuart_set_hardflow_control(lpuartx,lpuart_init_param->hardware_flow);
    /* 配置通信波特率 */
    if (STD_OK != (std_lpuart_set_baudrate(lpuartx,lpuart_init_param->baudrate)))
    {
        return STD_ERR;
    }
    /* 配置通信方向 */
    std_lpuart_set_transfer_direction(lpuartx,lpuart_init_param->direction);
    
    direction = std_lpuart_get_transfer_direction(lpuartx);
    
    /* 使能LPUART */
    std_lpuart_enable(lpuartx);
    
    /* 在使能发送器后，需等待TEACK标志置1 */
    if (LPUART_DIRECTION_SEND == (direction & LPUART_DIRECTION_SEND))
    {
        while (!std_lpuart_get_flag(lpuartx, LPUART_FLAG_TEACK))
        {
        }
    }
    /* 在使能接收器后，需等待REACK标志置1 */
    if (LPUART_DIRECTION_RECEIVE == (direction & LPUART_DIRECTION_RECEIVE))
    {
        while (!std_lpuart_get_flag(lpuartx, LPUART_FLAG_REACK))
        {
        }
    }     

    return  STD_OK;
}


/**
* @brief  LPUART 去初始化
* @param  lpuartx LPUART外设
* @retval 无
*/
void std_lpuart_deinit(LPUART_t *lpuartx)
{
    std_lpuart_disable(lpuartx);
    
    if(lpuartx == LPUART1)
    {
        /* 复位LPUART1 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_LPUART1);
        /* 关闭LPUART1时钟 */
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_LPUART1);
    }
    else if(lpuartx == LPUART2)
    {
        /* 复位LPUART2 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_LPUART2);
        /* 关闭LPUART2时钟 */
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_LPUART2);
    }
    else
    {
        /* 暂无操作 */
    }
}

/**
* @brief  LPUART 波特率计算及BRR寄存器配置
* @param  lpuartx LPUART外设 
* @param  baudrate LPUART波特率
* @retval std_status_t 返回API执行结果
*/
std_status_t std_lpuart_set_baudrate(LPUART_t *lpuartx, uint32_t baudrate)
{    
    uint32_t kclk_source = 0;
    uint32_t kclk_frequency = 0;
    uint32_t prescaler_temp = 0;
    uint32_t brr_temp = 0;

    /* 获取LPUART当前的时钟源 */ 
    if (lpuartx == LPUART1)    
    {
        kclk_source = std_rcc_get_lpuart1clk_source();
        /* 获取LPUART当前的时钟源频率 */
        switch (kclk_source)
        {
            case RCC_LPUART1_ASYNC_CLK_SRC_PCLK1:   
            {
                kclk_frequency = std_rcc_get_pclk1freq();
            }break;
            
            case RCC_LPUART1_ASYNC_CLK_SRC_SYSCLK:
            {
                kclk_frequency = std_rcc_get_sysclkfreq();
            }break;
            
            case RCC_LPUART1_ASYNC_CLK_SRC_RCH:
            {
                kclk_frequency = RCH_VALUE;
            }break;
            
            case RCC_LPUART1_ASYNC_CLK_SRC_LXTAL:
            {
                kclk_frequency = LXTAL_VALUE;
            }break;
             
            default:
            {
                kclk_frequency = 0;         
            }break;    
        }
    }
    else if (lpuartx == LPUART2)
    {
        kclk_source = std_rcc_get_lpuart2clk_source();
        
        /* 获取LPUART当前的时钟源频率 */
        switch (kclk_source)
        {
            case RCC_LPUART2_ASYNC_CLK_SRC_PCLK1:   
            {
                kclk_frequency = std_rcc_get_pclk1freq();
            }break;
            
            case RCC_LPUART2_ASYNC_CLK_SRC_SYSCLK:
            {
                kclk_frequency = std_rcc_get_sysclkfreq();
            }break;
            
            case RCC_LPUART2_ASYNC_CLK_SRC_RCH:
            {
                kclk_frequency = RCH_VALUE;
            }break;
            
            case RCC_LPUART2_ASYNC_CLK_SRC_LXTAL:
            {
                kclk_frequency = LXTAL_VALUE;
            }break;
             
            default:
            {
                kclk_frequency = 0;         
            }break; 
        }
    }
    else
    {
        /* 暂无操作 */
    }    
    
    /* 获取LPUART 预分频器的分频值 */
    prescaler_temp = std_lpuart_get_kclk_prescaler(lpuartx);
    /* 计算LPUART BRR配置 */
    brr_temp = (uint32_t)(((((uint64_t)kclk_frequency/(uint64_t)prescaler_temp)<<8) + (baudrate>>1))/(baudrate));
    /* 判断BRR配置在有效范围内 */
    if ((brr_temp>=LPUART_BRR_MIN) &&(brr_temp<=LPUART_BRR_MAX))
    {
        MODIFY_REG(lpuartx->BRR,USART_BRR_LPUART, brr_temp);
        return STD_OK;
    }
    else
    {
        return STD_ERR;
    } 
}

/**
* @brief  LPUART 结构体初始化
* @param  lpuart_init_struct LPUART初始化结构体指针
* @retval 无
*/
void std_lpuart_struct_init(std_lpuart_init_t *lpuart_init_struct)
{
    lpuart_init_struct->prescaler = LPUART_PRESCALER_DIV1;
    lpuart_init_struct->baudrate = 9600;
    lpuart_init_struct->wordlength = LPUART_WORDLENGTH_8BITS;
    lpuart_init_struct->hardware_flow = LPUART_FLOWCONTROL_NONE;
    lpuart_init_struct->parity = LPUART_PARITY_NONE;
    lpuart_init_struct->stopbits = LPUART_STOPBITS_1;
    lpuart_init_struct->direction =LPUART_DIRECTION_SEND_RECEIVE;
}    

/** 
* @} 
*/

#endif /* STD_LPUART_PERIPHERAL_USED */
/** 
* @} 
*/

/** 
* @} 
*/
