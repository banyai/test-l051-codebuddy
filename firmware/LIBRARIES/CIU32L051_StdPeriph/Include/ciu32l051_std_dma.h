/************************************************************************************************/
/**
* @file               ciu32l051_std_dma.h
* @author             MCU Ecosystem Development Team
* @brief              DMA STD库驱动头文件。
*                     提供DMA相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_DMA_H
#define CIU32L051_STD_DMA_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup DMA DMA
* @brief 直接存储器访问控制器的STD库驱动
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
* @defgroup DMA_Types DMA Types
* @brief  DMA数据类型定义
* @{
*
*/
/************************************************************************************************/

/**
* @brief  DMA初始化配置结构体定义
*/
typedef struct 
{
    uint32_t dma_channel;         /**< DMA通道
                                           @arg DMA_CHANNEL_0
                                           @arg DMA_CHANNEL_1                                   */
       
    uint32_t transfer_type;       /**< DMA传输控制，Block传输或Burst传输
                                           @arg DMA_BLOCK_TRANSFER                              
                                           @arg DMA_BURST_TRANSFER                              */
    
    uint32_t dma_req_id;          /**< DMA请求源ID
                                           @arg DMA_REQUEST_SOFTWARE                            
                                           @arg DMA_REQUEST_ADC...                              */
    
    uint32_t src_addr_inc;        /**< DMA源地址自增使能或禁止
                                           @arg DMA_SRC_INC_DISABLE                             
                                           @arg DMA_SRC_INC_ENABLE                              */

    uint32_t dst_addr_inc;        /**< DMA目的地址自增使能或禁止
                                           @arg DMA_DST_INC_DISABLE                             
                                           @arg DMA_DST_INC_ENABLE                              */

    uint32_t data_size;           /**< DMA传输数据宽度，字节、半字或字
                                           @arg DMA_DATA_SIZE_BYTE                              
                                           @arg DMA_DATA_SIZE_HALFWORD
                                           @arg DMA_DATA_SIZE_WORD                              */
                                                                                     
    uint32_t mode;                /**< DMA工作模式，正常模式或循环模式
                                           @arg DMA_MODE_NORMAL 
                                           @arg DMA_MODE_CIRCULAR
                                           @note 存储器到存储器传输方向不能配置为循环模式       */
} std_dma_init_t;


/**
* @brief  DMA传输参数配置结构体定义
*/
typedef struct
{
    uint32_t dma_channel;         /**< DMA通道
                                           @arg DMA_CHANNEL_0
                                           @arg DMA_CHANNEL_1                   */
    
    uint32_t src_addr;            /**< DMA传输源地址                             */
    
    uint32_t dst_addr;            /**< DMA传输目的地址                           */
    
    uint32_t data_number;         /**< DMA传输次数                               */

} std_dma_config_t;


/**
* @}
*/


/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup DMA_Constants DMA Constants
* @brief DMA常量定义及宏定义
* @{
*/
/************************************************************************************************/

/* DMA通道 */
#define DMA_CHANNEL_0                    (0x00U)                    /**< DMA通道0  */
#define DMA_CHANNEL_1                    (0x01U)                    /**< DMA通道1  */

/* DMA传输控制 */
#define DMA_BLOCK_TRANSFER               (0x00000000U)              /**< DMA BLOCK传输类型 */
#define DMA_BURST_TRANSFER               (DMA_CC_TYPE)              /**< DMA BURST传输类型 */

/* DMA源地址自增模式 */
#define DMA_SRC_INC_DISABLE              (0x00000000U)              /**< 源地址自增禁止    */
#define DMA_SRC_INC_ENABLE               (DMA_CC_SINC)              /**< 源地址自增使能    */

/* DMA目的地址自增模式 */
#define DMA_DST_INC_DISABLE              (0x00000000U)              /**< 目的地址自增禁止  */
#define DMA_DST_INC_ENABLE               (DMA_CC_DINC)              /**< 目的地址自增使能  */

/* DMA传输数据宽度 */
#define DMA_DATA_SIZE_BYTE               (DMA_CC_SIZE_BYTE)         /**< 传输数据为字节    */
#define DMA_DATA_SIZE_HALFWORD           (DMA_CC_SIZE_HALFWORD)     /**< 传输数据为半字    */
#define DMA_DATA_SIZE_WORD               (DMA_CC_SIZE_WORD)         /**< 传输数据为字      */

/* DMA模式 */
#define DMA_MODE_NORMAL                  (0x00000000U)              /**< 正常模式  */
#define DMA_MODE_CIRCULAR                (DMA_CC_CIRC)              /**< 循环模式  */

/* DMA请求源ID */
#define DMA_REQUEST_SOFTWARE             (0U)                       /**< DMA软件触发通道请求            */
#define DMA_REQUEST_ADC                  (1U)                       /**< DMA请求为ADC                   */
#define DMA_REQUEST_SPI1_RX              (2U)                       /**< DMA请求为SPI1接收              */
#define DMA_REQUEST_SPI1_TX              (2U)                       /**< DMA请求为SPI1发送              */
#define DMA_REQUEST_SPI2_RX              (3U)                       /**< DMA请求为SPI2接收              */
#define DMA_REQUEST_SPI2_TX              (3U)                       /**< DMA请求为SPI2发送              */
#define DMA_REQUEST_I2C1_RX              (4U)                       /**< DMA请求为I2C1接收              */
#define DMA_REQUEST_I2C1_TX              (4U)                       /**< DMA请求为I2C1发送              */
#define DMA_REQUEST_USART1_RX            (6U)                       /**< DMA请求为USART1接收            */
#define DMA_REQUEST_USART1_TX            (6U)                       /**< DMA请求为USART1发送            */
#define DMA_REQUEST_UART2_RX             (7U)                       /**< DMA请求为UART2接收             */
#define DMA_REQUEST_UART2_TX             (7U)                       /**< DMA请求为UART2发送             */
#define DMA_REQUEST_UART3_RX             (8U)                       /**< DMA请求为UART3接收             */
#define DMA_REQUEST_UART3_TX             (8U)                       /**< DMA请求为UART3发送             */
#define DMA_REQUEST_UART4_RX             (9U)                       /**< DMA请求为UART4接收             */
#define DMA_REQUEST_UART4_TX             (9U)                       /**< DMA请求为UART4发送             */
#define DMA_REQUEST_LPUART1_RX           (10U)                      /**< DMA请求为LPUART1接收           */
#define DMA_REQUEST_LPUART1_TX           (10U)                      /**< DMA请求为LPUART1发送           */
#define DMA_REQUEST_LPUART2_RX           (11U)                      /**< DMA请求为LPUART2接收           */
#define DMA_REQUEST_LPUART2_TX           (11U)                      /**< DMA请求为LPUART2发送           */
#define DMA_REQUEST_TIM3_CC1             (15U)                      /**< DMA请求为TIM3通道1比较/匹配    */
#define DMA_REQUEST_TIM3_CC2             (15U)                      /**< DMA请求为TIM3通道2比较/匹配    */
#define DMA_REQUEST_TIM3_CC3             (16U)                      /**< DMA请求为TIM3通道3比较/匹配    */
#define DMA_REQUEST_TIM3_CC4             (16U)                      /**< DMA请求为TIM3通道4比较/匹配    */
#define DMA_REQUEST_TIM3_TRIG            (17U)                      /**< DMA请求为TIM3触发              */
#define DMA_REQUEST_TIM3_UP              (17U)                      /**< DMA请求为TIM3更新              */
#define DMA_REQUEST_TIM4_CC1             (18U)                      /**< DMA请求为TIM4通道1比较/匹配    */
#define DMA_REQUEST_TIM4_CC2             (18U)                      /**< DMA请求为TIM4通道2比较/匹配    */
#define DMA_REQUEST_TIM4_CC3             (19U)                      /**< DMA请求为TIM4通道3比较/匹配    */
#define DMA_REQUEST_TIM4_CC4             (19U)                      /**< DMA请求为TIM4通道4比较/匹配    */
#define DMA_REQUEST_TIM4_TRIG            (20U)                      /**< DMA请求为TIM4触发              */
#define DMA_REQUEST_TIM4_UP              (20U)                      /**< DMA请求为TIM4更新              */
#define DMA_REQUEST_TIM5_CC1             (21U)                      /**< DMA请求为TIM5通道1比较/匹配    */
#define DMA_REQUEST_TIM5_CC2             (21U)                      /**< DMA请求为TIM5通道2比较/匹配    */
#define DMA_REQUEST_TIM5_CC3             (22U)                      /**< DMA请求为TIM5通道3比较/匹配    */
#define DMA_REQUEST_TIM5_CC4             (22U)                      /**< DMA请求为TIM5通道4比较/匹配    */
#define DMA_REQUEST_TIM5_TRIG            (23U)                      /**< DMA请求为TIM5触发              */
#define DMA_REQUEST_TIM5_UP              (23U)                      /**< DMA请求为TIM5更新              */
#define DMA_REQUEST_TIM8_UP              (24U)                      /**< DMA请求为TIM8更新              */
#define DMA_REQUEST_AES_IN               (26U)                      /**< DMA请求为AES数据输入           */
#define DMA_REQUEST_AES_OUT              (26U)                      /**< DMA请求为AES数据输出           */
#define DMA_REQUEST_LPTIM1_CMPM          (27U)                      /**< DMA请求为LPTIM1比较/匹配       */
#define DMA_REQUEST_LPTIM1_ARRM          (27U)                      /**< DMA请求为LPTIM1自动重载        */
#define DMA_REQUEST_LPTIM2_CMPM          (28U)                      /**< DMA请求为LPTIM2比较/匹配       */
#define DMA_REQUEST_LPTIM2_ARRM          (28U)                      /**< DMA请求为LPTIM2自动重载        */

/* DMA中断状态 */
#define DMA_FLAG_G0                      (DMA_ISR_G0)            /**< DMA通道0全局状态      */
#define DMA_FLAG_TF0                     (DMA_ISR_TF0)           /**< DMA通道0传输完成状态  */
#define DMA_FLAG_TH0                     (DMA_ISR_TH0)           /**< DMA通道0传输一半状态  */
#define DMA_FLAG_TE0                     (DMA_ISR_TE0)           /**< DMA通道0传输错误状态  */
#define DMA_FLAG_G1                      (DMA_ISR_G1)            /**< DMA通道1全局状态      */
#define DMA_FLAG_TF1                     (DMA_ISR_TF1)           /**< DMA通道1传输完成状态  */
#define DMA_FLAG_TH1                     (DMA_ISR_TH1)           /**< DMA通道1传输一半状态  */
#define DMA_FLAG_TE1                     (DMA_ISR_TE1)           /**< DMA通道1传输错误状态  */

/* DMA中断源 */
#define DMA_INTERRUPT_TF                 (DMA_CC_TFIE)           /**< DMA传输完成中断  */
#define DMA_INTERRUPT_TH                 (DMA_CC_THIE)           /**< DMA传输一半中断  */
#define DMA_INTERRUPT_TE                 (DMA_CC_TEIE)           /**< DMA传输错误中断  */

/* DMA中断状态清除 */
#define DMA_CLEAR_G0                      (DMA_ICR_GCF0)         /**< DMA通道0全局状态清除      */
#define DMA_CLEAR_TF0                     (DMA_ICR_TFCF0)        /**< DMA通道0传输完成状态清除  */
#define DMA_CLEAR_TH0                     (DMA_ICR_THCF0)        /**< DMA通道0传输一半状态清除  */
#define DMA_CLEAR_TE0                     (DMA_ICR_TECF0)        /**< DMA通道0传输错误状态清除  */
#define DMA_CLEAR_G1                      (DMA_ICR_GCF1)         /**< DMA通道1全局状态清除      */
#define DMA_CLEAR_TF1                     (DMA_ICR_TFCF1)        /**< DMA通道1传输完成状态清除  */
#define DMA_CLEAR_TH1                     (DMA_ICR_THCF1)        /**< DMA通道1传输一半状态清除  */
#define DMA_CLEAR_TE1                     (DMA_ICR_TECF1)        /**< DMA通道1传输错误状态清除  */


/**
* @}
*/

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup DMA_External_Functions DMA External Functions
* @brief    DMA对外函数
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  使能DMA通道
* @param  channel DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_enable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC |= (DMA_CC_EN);
}


/** 
* @brief  禁止DMA通道
* @param  channel DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_disable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC &= (~DMA_CC_EN);
}


/** 
* @brief  配置DMA传输类型
* @param  channel DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  transfer_type DMA传输类型
*             @arg DMA_BLOCK_TRANSFER
*             @arg DMA_BURST_TRANSFER
* @retval 无
*/
__STATIC_INLINE void std_dma_transfer_type_config(uint32_t channel, uint32_t transfer_type)
{
    MODIFY_REG((&(DMA->channel[channel]))->CC, DMA_CC_TYPE, transfer_type);
}


/** 
* @brief  获取DMA传输类型
* @param  channel DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA传输类型
*             @arg DMA_BLOCK_TRANSFER
*             @arg DMA_BURST_TRANSFER
*/
__STATIC_INLINE uint32_t std_dma_get_transfer_type(uint32_t channel)
{
    return ((&(DMA->channel[channel]))->CC & DMA_CC_TYPE);
}


/** 
* @brief  使能DMA源地址递增
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_src_addr_inc_enable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC |= (DMA_CC_SINC);    
}


/** 
* @brief  禁止DMA源地址递增
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_src_addr_inc_disable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC &= (~DMA_CC_SINC);    
}


/** 
* @brief  使能DMA目的地址递增
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_dst_addr_inc_enable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC |= (DMA_CC_DINC);    
}


/** 
* @brief  禁止DMA目的地址递增
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_dst_addr_inc_disable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC &= (~DMA_CC_DINC);    
}


/** 
* @brief  配置DMA传输数据大小，为字节、半字或字
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  data_size  DMA传输数据大小
*             @arg DMA_DATA_SIZE_BYTE
*             @arg DMA_DATA_SIZE_HALFWORD
*             @arg DMA_DATA_SIZE_WORD
* @retval 无
*/
__STATIC_INLINE void std_dma_set_transfer_data_size(uint32_t channel, uint32_t data_size)
{
    MODIFY_REG((&(DMA->channel[channel]))->CC, (DMA_CC_SIZE), (data_size & DMA_CC_SIZE));
}


/** 
* @brief  获取DMA传输数据大小，为字节、半字或字
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA传输数据大小
*             @arg DMA_DATA_SIZE_BYTE
*             @arg DMA_DATA_SIZE_HALFWORD
*             @arg DMA_DATA_SIZE_WORD
*/
__STATIC_INLINE uint32_t std_dma_get_transfer_data_size(uint32_t channel)
{
    return ((&(DMA->channel[channel]))->CC & (DMA_CC_SIZE));
}


/** 
* @brief  使能DMA循环模式
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_circular_mode_enable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC |= DMA_MODE_CIRCULAR;
}


/** 
* @brief  禁止DMA循环模式
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_circular_mode_disable(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC &= (~DMA_MODE_CIRCULAR);
}


/** 
* @brief  获取DMA循环模式使能状态
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval bool     DMA循环模式使能状态
*             @arg true  DMA循环模式使能
*             @arg false DMA循环模式禁止
*/
__STATIC_INLINE bool std_dma_get_circular_mode_status(uint32_t channel)
{
    return (((&(DMA->channel[channel]))->CC & DMA_MODE_CIRCULAR) == DMA_MODE_CIRCULAR);     
}


/** 
* @brief  使能DMA中断
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  dma_interrupt DMA中断，包括错误中断、传输完成中断，传输一半中断
*             @arg DMA_INTERRUPT_TE
*             @arg DMA_INTERRUPT_TF
*             @arg DMA_INTERRUPT_TH
* @retval 无
*/
__STATIC_INLINE void std_dma_interrupt_enable(uint32_t channel, uint32_t dma_interrupt)
{
    (&(DMA->channel[channel]))->CC |= (dma_interrupt);
}


/** 
* @brief  禁止DMA中断
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  dma_interrupt DMA中断，包括错误中断、传输完成中断，传输一半中断
*             @arg DMA_INTERRUPT_TE
*             @arg DMA_INTERRUPT_TF
*             @arg DMA_INTERRUPT_TH
* @retval 无
*/
__STATIC_INLINE void std_dma_interrupt_disable(uint32_t channel, uint32_t dma_interrupt)
{
    (&(DMA->channel[channel]))->CC &= (~dma_interrupt);
}


/** 
* @brief  获取DMA中断使能状态
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  dma_interrupt DMA中断，包括错误中断、传输完成中断，传输一半中断
*             @arg DMA_INTERRUPT_TE
*             @arg DMA_INTERRUPT_TF
*             @arg DMA_INTERRUPT_TH
* @retval bool DMA中断使能状态
*             @arg true  DMA中断使能
*             @arg false DMA中断禁止
*/
__STATIC_INLINE bool std_dma_get_interrupt_enable(uint32_t channel, uint32_t dma_interrupt)
{
    return (((&(DMA->channel[channel]))->CC & (dma_interrupt)) == (dma_interrupt));
}


/** 
* @brief  获取DMA标志位状态
* @param  flag DMA状态,包括全局中断、传输完成中断、传输一半中断、错误中断
*             @arg DMA_FLAG_G0  
*             @arg DMA_FLAG_TF0 
*             @arg DMA_FLAG_TH0 
*             @arg DMA_FLAG_TE0 
*             @arg DMA_FLAG_G1  
*             @arg DMA_FLAG_TF1 
*             @arg DMA_FLAG_TH1 
*             @arg DMA_FLAG_TE1 
* @retval bool DMA标志位状态
*             @arg true   DMA标志位置起
*             @arg false  DMA标志位未置起
*/
__STATIC_INLINE bool std_dma_get_flag(uint32_t flag)
{
    return ((DMA->ISR & (flag)) == (flag));
}


/** 
* @brief  清除DMA标志位
* @param  flag DMA状态,包括全局中断、传输完成中断、传输一半中断、错误中断
*             @arg DMA_CLEAR_G0  
*             @arg DMA_CLEAR_TF0 
*             @arg DMA_CLEAR_TH0 
*             @arg DMA_CLEAR_TE0 
*             @arg DMA_CLEAR_G1  
*             @arg DMA_CLEAR_TF1 
*             @arg DMA_CLEAR_TH1 
*             @arg DMA_CLEAR_TE1 
* @retval 无
*/
__STATIC_INLINE void std_dma_clear_flag(uint32_t flag)
{
    DMA->ICR |= (flag);
}


/** 
* @brief  DMA请求信号源配置
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  req_id   DMA请求信号源
*             @arg DMA_REQUEST_SOFTWARE
*             @arg DMA_REQUEST_ADC
*             @arg ...
*             @arg DMA_REQUEST_LPTIM2_ARRM
* @retval 无
*/
__STATIC_INLINE void std_dma_set_req_id(uint32_t channel, uint32_t req_id)
{
    MODIFY_REG((&(DMA->channel[channel]))->CC, (DMA_CC_REQ_ID), (req_id << DMA_CC_REQ_ID_POS));
}


/** 
* @brief  获取DMA请求信号源配置
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA请求信号源
*             @arg DMA_REQUEST_SOFTWARE
*             @arg DMA_REQUEST_ADC
*             @arg ...
*             @arg DMA_REQUEST_LPTIM2_ARRM
*/
__STATIC_INLINE uint32_t std_dma_get_req_id(uint32_t channel)
{
    return (((&(DMA->channel[channel]))->CC & (DMA_CC_REQ_ID)) >> DMA_CC_REQ_ID_POS);
}


/** 
* @brief  DMA通道控制参数配置
* @param  channel dma通道
* @param  config_value DMA配置
*             @arg DMA_MODE_NORMAL     or DMA_MODE_CIRCULAR
*             @arg DMA_BLOCK_TRANSFER  or DMA_BURST_TRANSFER
*             @arg DMA_DATA_SIZE_BYTE  or DMA_DATA_SIZE_HALFWORD or DMA_DATA_SIZE_WORD
*             @arg DMA_SRC_INC_DISABLE or DMA_SRC_INC_ENABLE
*             @arg DMA_DST_INC_DISABLE or DMA_DST_INC_ENABLE
* @retval 无
*/
__STATIC_INLINE void std_dma_channel_config(uint32_t channel, uint32_t config_value)
{
    MODIFY_REG((&(DMA->channel[channel]))->CC, (DMA_CC_CIRC | DMA_CC_TYPE | DMA_CC_SIZE | DMA_CC_SINC | DMA_CC_DINC), (config_value));
}


/** 
* @brief  复位DMA通道控制器
* @param  channel DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval 无
*/
__STATIC_INLINE void std_dma_reset_control(uint32_t channel)
{
    (&(DMA->channel[channel]))->CC &= (~DMA_CC_EN);
    (&(DMA->channel[channel]))->CC = 0U;
}


/** 
* @brief  配置DMA源地址
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  src_addr DMA源地址
* @retval 无
*/
__STATIC_INLINE void std_dma_set_src_address(uint32_t channel, uint32_t src_addr)
{
    (&(DMA->channel[channel]))->CSAR = src_addr;
}


/** 
* @brief  获取DMA源地址
* @param  channel  DMA通道 
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA源地址
*/
__STATIC_INLINE uint32_t std_dma_get_src_address(uint32_t channel)
{
    return ((&(DMA->channel[channel]))->CSAR);
}


/** 
* @brief  配置DMA目的地址
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  dst_addr DMA目的地址
* @retval 无
*/
__STATIC_INLINE void std_dma_set_dst_address(uint32_t channel, uint32_t dst_addr)
{
    (&(DMA->channel[channel]))->CDAR = dst_addr;   
}


/** 
* @brief  获取DMA目的地址
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA目的地址
*/
__STATIC_INLINE uint32_t std_dma_get_dts_address(uint32_t channel)
{
    return ((&(DMA->channel[channel]))->CDAR);
}


/** 
* @brief  配置DMA传输次数
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @param  data_number 传输次数 
* @retval 无
*/
__STATIC_INLINE void std_dma_set_transfer_data_number(uint32_t channel, uint32_t data_number)
{
    (&(DMA->channel[channel]))->CNDTR = data_number;
}


/** 
* @brief  获取DMA传输次数
* @param  channel  DMA通道
*             @arg DMA_CHANNEL_0
*             @arg DMA_CHANNEL_1
* @retval uint32_t DMA传输次数
*/
__STATIC_INLINE uint32_t std_dma_get_transfer_data_number(uint32_t channel)
{
    return ((&(DMA->channel[channel]))->CNDTR);
}


void std_dma_init(std_dma_init_t *dma_init_param);
void std_dma_deinit(std_dma_init_t *dma_init_param);
void std_dma_struct_init(std_dma_init_t *dma_init_struct);
void std_dma_start_transmit(std_dma_config_t *dma_config);

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

#endif /* CIU32L051_STD_DMA_H */
