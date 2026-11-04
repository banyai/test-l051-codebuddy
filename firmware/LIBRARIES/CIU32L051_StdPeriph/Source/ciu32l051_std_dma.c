/************************************************************************************************/
/**
* @file               ciu32l051_std_dma.c
* @author             MCU Ecosystem Development Team
* @brief              DMA STD库驱动。
*                     实现DMA初始化和启动等API。
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
* @addtogroup DMA 
* @{
*
*/
/************************************************************************************************/

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"


#ifdef STD_DMA_PERIPHERAL_USED
/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup DMA_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  DMA通道初始化
* @param  dma_init_param  DMA初始化结构体
* @retval 无
*/
void std_dma_init(std_dma_init_t *dma_init_param)
{
    /* 设置DMA配置寄存器 */
    std_dma_channel_config(dma_init_param->dma_channel, dma_init_param->transfer_type     \
                                                      | dma_init_param->src_addr_inc      \
                                                      | dma_init_param->dst_addr_inc      \
                                                      | dma_init_param->data_size         \
                                                      | dma_init_param->mode);
    
    /* 设置DMA请求源ID */
    std_dma_set_req_id(dma_init_param->dma_channel, dma_init_param->dma_req_id);
}


/**
* @brief  DMA通道去初始化
* @param  dma_init_param dma初始化结构体
* @retval 无
*/
void std_dma_deinit(std_dma_init_t *dma_init_param)
{   
    /* 清除DMA通道的所有状态 */
    DMA->ICR = (DMA_FLAG_G0 << (dma_init_param->dma_channel << 2U));
      
    /* 禁止DMA通道 */
    std_dma_disable(dma_init_param->dma_channel);
    
    /* 复位DMA通道的控制寄存器 */
    std_dma_reset_control(dma_init_param->dma_channel);
    
     /* DMA传输数量清零 */
    std_dma_set_transfer_data_number(dma_init_param->dma_channel, 0U);

    /* DMA传输源地址清零 */
    std_dma_set_src_address(dma_init_param->dma_channel, 0U);
    
    /* DMA传目的地址清零 */
    std_dma_set_dst_address(dma_init_param->dma_channel, 0U);
}


/**
* @brief  初始化std_dma_init_t结构体
* @param  dma_init_struct dma初始化结构体
* @note   源地址、目的地址、DMA传输数的配置不在该函数
* @retval 无
*/
void std_dma_struct_init(std_dma_init_t *dma_init_struct)
{
    dma_init_struct->dma_channel = DMA_CHANNEL_0;
    dma_init_struct->transfer_type = DMA_BLOCK_TRANSFER;
    dma_init_struct->dma_req_id = DMA_REQUEST_SOFTWARE;
    dma_init_struct->src_addr_inc = DMA_SRC_INC_DISABLE;
    dma_init_struct->dst_addr_inc = DMA_DST_INC_DISABLE;
    dma_init_struct->data_size = DMA_DATA_SIZE_BYTE;
    dma_init_struct->mode = DMA_MODE_NORMAL;
}


/**
* @brief  配置DMA源地址、目的地址、DMA传输数，使能DMA
* @param  dma_config 配置寄存器
* @note   当DMA通道配置软件触发DMA请求，立即启动DMA传输
* @retval 无
*/
void std_dma_start_transmit(std_dma_config_t *dma_config)
{
    /* 设置DMA传输数量 */
    std_dma_set_transfer_data_number(dma_config->dma_channel,dma_config->data_number);

    /* 设置DMA传输源地址 */
    std_dma_set_src_address(dma_config->dma_channel,dma_config->src_addr);
    
    /* 设置DMA传目的地址 */
    std_dma_set_dst_address(dma_config->dma_channel,dma_config->dst_addr);

    /* 使能DMA传输 */
    std_dma_enable(dma_config->dma_channel);  
}


/**
* @} 
*/

#endif /* STD_DMA_PERIPHERAL_USED */

/**
* @} 
*/

/**
* @} 
*/

