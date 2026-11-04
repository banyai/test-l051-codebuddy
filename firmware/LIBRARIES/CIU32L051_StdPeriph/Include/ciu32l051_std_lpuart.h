/************************************************************************************************/
/**
* @file               ciu32L051_std_lpuart.h
* @author             MCU Ecosystem Development Team
* @brief              LPUART STD库驱动头文件。
*                     提供LPUART相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_LPUART_H
#define CIU32L051_STD_LPUART_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup LPUART LPUART
* @brief  低功耗通用异步收发器的STD库驱动
* @{
*/
/************************************************************************************************/

/************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32L051_std_common.h"

/*-----------------------------------------type define------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup LPUART_Types LPUART Types
* @brief  LPUART数据类型定义
* @{
*
*/
/************************************************************************************************/

/**
* @brief  LPUART 初始化结构体定义
*/    
typedef struct
{
    uint32_t prescaler;                                       /**< LPUART 时钟预分频 
                                                                       @arg LPUART_PRESCALER_DIV1 ...     */
    uint32_t direction;                                       /**< LPUART 传输方向
                                                                       @arg LPUART_DIRECTION_SEND ...     */ 
    uint32_t baudrate;                                        /**< LPUART 波特率                          */
    uint32_t wordlength;                                      /**< LPUART 数据帧字长
                                                                       @arg LPUART_WORDLENGTH_8BITS ...   */
    uint32_t stopbits;                                        /**< LPUART 数据帧停止位长度
                                                                       @arg LPUART_STOPBITS_1 ...         */
    uint32_t parity;                                          /**< LPUART 数据帧奇偶校验
                                                                       @arg LPUART_PARITY_NONE ...        */
    uint32_t hardware_flow;                                   /**< LPUART RS232硬件流控
                                                                       @arg LPUART_FLOWCONTROL_NONE ...   */
} std_lpuart_init_t;

/**
* @brief  LPUART 预分频值
*/
static const uint16_t LPUART_PRESCALER_TABLE[] =
{
    (uint16_t)1U,
    (uint16_t)2U,
    (uint16_t)4U,
    (uint16_t)6U,
    (uint16_t)8U,
    (uint16_t)10U,
    (uint16_t)12U,
    (uint16_t)16U,
    (uint16_t)32U,
    (uint16_t)64U,
    (uint16_t)128U,
    (uint16_t)256U
};
/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup LPUART_Constants LPUART Constants 
* @brief  LPUART常量定义及宏定义
* @{
*
*/

#define  LPUART_t USART_t

/* LPUART标志清除位(LPUART_ICR寄存器) */
#define  LPUART_CLEAR_PE                              USART_ICR_PECF                            /**< 奇偶校验错误标志清除     */
#define  LPUART_CLEAR_FE                              USART_ICR_FECF                            /**< 帧错误标志清除           */
#define  LPUART_CLEAR_ORE                             USART_ICR_ORECF                           /**< 接收溢出错误标志清除     */
#define  LPUART_CLEAR_TC                              USART_ICR_TCCF                            /**< 发送完成标志清除         */
#define  LPUART_CLEAR_CTS                             USART_ICR_CTSCF                           /**< CTS标志清除              */
#define  LPUART_CLEAR_CM                              USART_ICR_CMCF                            /**< 字符匹配清除             */
#define  LPUART_CLEAR_LPWK                            USART_ICR_LPWKCF                          /**< 低功耗模式唤醒标志清除   */

/* LPUART标志(LPUART_ISR寄存器) */
#define  LPUART_FLAG_PE                               USART_ISR_PE                              /**< LPUART 奇偶校验错误标志     */
#define  LPUART_FLAG_FE                               USART_ISR_FE                              /**< LPUART 帧错误标志           */
#define  LPUART_FLAG_ORE                              USART_ISR_ORE                             /**< LPUART 接收溢出错误标志     */
#define  LPUART_FLAG_RXNE                             USART_ISR_RXNE                            /**< LPUART 接收寄存器非空标志   */
#define  LPUART_FLAG_TC                               USART_ISR_TC                              /**< LPUART 发送完成标志         */
#define  LPUART_FLAG_TXE                              USART_ISR_TXE                             /**< LPUART 发送数据寄存器空标志 */
#define  LPUART_FLAG_CTSIF                            USART_ISR_CTSIF                           /**< LPUART CTS标志中断标志      */
#define  LPUART_FLAG_CTS                              USART_ISR_CTS                             /**< LPUART CTS标志              */
#define  LPUART_FLAG_CM                               USART_ISR_CMF                             /**< LPUART 字符匹配标志         */
#define  LPUART_FLAG_LPWKF                            USART_ISR_LPWK                            /**< LPUART 低功耗模式唤醒标志   */
#define  LPUART_FLAG_TEACK                            USART_ISR_TEACK                           /**< LPUART 发送器使能确认标志   */
#define  LPUART_FLAG_REACK                            USART_ISR_REACK                           /**< LPUART 接收器使能确认标志   */
#define  LPUART_FLAG_BUSY                             USART_ISR_BUSY                            /**< LPUART 接收忙标志           */  

/*
* LPUART中断使能位(LPUART_CR1、LPUART_CR3寄存器)
* RXNE或ERR中断使能时，溢出错误均会造成ORE中断
*/
#define  LPUART_CR1_INTERRUPT_RXNE                    USART_CR1_RXNEIE                          /**< LPUART 接收数据寄存器非空中断使能    */
#define  LPUART_CR1_INTERRUPT_TC                      USART_CR1_TCIE                            /**< LPUART 发送完成中断使能              */
#define  LPUART_CR1_INTERRUPT_TXE                     USART_CR1_TXEIE                           /**< LPUART 发送数据寄存器空中断使能      */
#define  LPUART_CR1_INTERRUPT_PE                      USART_CR1_PEIE                            /**< LPUART 奇偶校验错误中断使能          */
#define  LPUART_CR1_INTERRUPT_CM                      USART_CR1_CMIE                            /**< LPUART 字符匹配中断使能              */
#define  LPUART_CR3_INTERRUPT_ERR                     USART_CR3_EIE                             /**< LPUART 错误中断使能(帧错误，噪声错误，接收溢出错误) */
#define  LPUART_CR3_INTERRUPT_CTS                     USART_CR3_CTSIE                           /**< LPUART CTS中断使能                   */
#define  LPUART_CR3_INTERRUPT_LPWK                    USART_CR3_LPWKIE                          /**< LPUART Stop低功耗模式唤醒中断使能    */

/* 
*  LPUART时钟预分频参数  
*  默认1分频，超出范围则硬件采用256分频
*/
#define  LPUART_PRESCALER_DIV1                        (0x00000000U)                             /**< 预分频时钟fclk_pres = fclk     */
#define  LPUART_PRESCALER_DIV2                        (0x00000001U)                             /**< 预分频时钟fclk_pres = fclk/2   */
#define  LPUART_PRESCALER_DIV4                        (0x00000002U)                             /**< 预分频时钟fclk_pres = fclk/4   */
#define  LPUART_PRESCALER_DIV6                        (0x00000003U)                             /**< 预分频时钟fclk_pres = fclk/6   */
#define  LPUART_PRESCALER_DIV8                        (0x00000004U)                             /**< 预分频时钟fclk_pres = fclk/8   */
#define  LPUART_PRESCALER_DIV10                       (0x00000005U)                             /**< 预分频时钟fclk_pres = fclk/10  */
#define  LPUART_PRESCALER_DIV12                       (0x00000006U)                             /**< 预分频时钟fclk_pres = fclk/12  */
#define  LPUART_PRESCALER_DIV16                       (0x00000007U)                             /**< 预分频时钟fclk_pres = fclk/16  */
#define  LPUART_PRESCALER_DIV32                       (0x00000008U)                             /**< 预分频时钟fclk_pres = fclk/32  */
#define  LPUART_PRESCALER_DIV64                       (0x00000009U)                             /**< 预分频时钟fclk_pres = fclk/64  */
#define  LPUART_PRESCALER_DIV128                      (0x0000000AU)                             /**< 预分频时钟fclk_pres = fclk/128 */
#define  LPUART_PRESCALER_DIV256                      (0x0000000BU)                             /**< 预分频时钟fclk_pres = fclk/256 */

/* LPUART 数据帧长度 */
#define  LPUART_WORDLENGTH_8BITS                       USART_CR1_WL8BITS                        /**< 8-bits 字长 */
#define  LPUART_WORDLENGTH_9BITS                       USART_CR1_WL9BITS                        /**< 9-bits 字长 */

/* LPUART 数据帧奇偶校验 */
#define  LPUART_PARITY_NONE                           (0x00000000U)                             /**< 无校验 */
#define  LPUART_PARITY_EVEN                            USART_CR1_PEN                            /**< 偶校验 */
#define  LPUART_PARITY_ODD                            (USART_CR1_PEN | USART_CR1_PTS)           /**< 奇校验 */
                                                                                             
/* LPUART 数据帧停止位 */                                                                    
#define  LPUART_STOPBITS_1                            (0x00000000U)                             /**< 1bit停止位 */
#define  LPUART_STOPBITS_2                             USART_CR2_STOPBIT_2                      /**< 2bits停止位 */

/* LPUART 数据帧大小端 */
#define  LPUART_DATA_ORDER_LSBFIRST                   (0x00000000U)                             /**< 低有效位优先 */
#define  LPUART_DATA_ORDER_MSBFIRST                    USART_CR2_MSBFIRST                       /**< 高有效位优先 */

/* LPUART 波特率参数范围 */
#define  LPUART_BRR_MIN                               (0x00000300U)                             /**< LPUART波特率寄存器允许的最小值 */
#define  LPUART_BRR_MAX                               (0x000FFFFFU)                             /**< LPUART波特率寄存器允许的最大值 */
                                                                                              
/* LPUART RS232硬件流控 */                                                                    
#define  LPUART_FLOWCONTROL_NONE                      (0x00000000U)                             /**< 无流控功能        */
#define  LPUART_FLOWCONTROL_RTS                        USART_CR3_RTSE                           /**< RTS使能           */ 
#define  LPUART_FLOWCONTROL_CTS                        USART_CR3_CTSE                           /**< CTS使能           */ 
#define  LPUART_FLOWCONTROL_RTS_CTS                   (USART_CR3_RTSE | USART_CR3_CTSE)         /**< RTS和CTS同时使能  */ 
                                                                                                                                                                                          
/* LPUART 传输方向 */  
#define  LPUART_DIRECTION_NONE                        (0x00000000U)                             /**< 未使能发送器和接收器              */
#define  LPUART_DIRECTION_SEND                         USART_CR1_TE                             /**< 单发送模式（仅使能发送器）        */
#define  LPUART_DIRECTION_RECEIVE                      USART_CR1_RE                             /**< 单接收模式（仅使能接收器）        */
#define  LPUART_DIRECTION_SEND_RECEIVE                (USART_CR1_TE |USART_CR1_RE)              /**< 发送接收模式（使能发送器和接收器）*/                                                                                                                                                                                                                        
                                                                                                                                                                                     
/* DMA模式LPUART发送 */                                                                       
#define  LPUART_DMA_SEND_DISABLE                      (0x00000000U)                             /**< 禁止DMA模式LPUART发送 */
#define  LPUART_DMA_SEND_ENABLE                        USART_CR3_DMAT                           /**< 使能DMA模式LPUART发送 */
                                                                                              
/* DMA模式LPUART接收 */                                                                       
#define  LPUART_DMA_RECEIVE_DISABLE                   (0x00000000U)                             /**< 禁止DMA模式LPUART接收 */
#define  LPUART_DMA_RECEIVE_ENABLE                     USART_CR3_DMAR                           /**< 使能DMA模式LPUART接收 */
                                                                                              
/* LPUART单线半双工模式 */                                                                    
#define  LPUART_HALF_DUPLEX_DISABLE                   (0x00000000U)                             /**< 禁止LPUART单线半双工模式 */
#define  LPUART_HALF_DUPLEX_ENABLE                     USART_CR3_HDEN                           /**< 使能LPUART单线半双工模式 */                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                      
/* LPUART Stop低功耗模式唤醒源选择 */                                                         
#define  LPUART_WAKEUP_ON_STARTBIT                    (0x00000000U)                             /**< 起始位检测唤醒     */  
#define  LPUART_WAKEUP_ON_READDATA_NOTEMPTY            USART_CR3_LPWKS                          /**< 接收到一帧数据唤醒 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup LPUART_External_Functions LPUART External Functions
* @brief    LPUART对外函数
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  使能 LPUART外设
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_enable(LPUART_t *lpuartx)
{
    lpuartx->CR1 |= (USART_CR1_UE);
} 

/** 
* @brief  禁止 LPUART外设
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_disable(LPUART_t *lpuartx)
{
    lpuartx->CR1 &= (~USART_CR1_UE);
} 

/** 
* @brief  LPUART 校验配置
* @param  lpuartx LPUART外设
* @param  parity LPUART 奇偶校验配置项
*             @arg LPUART_PARITY_NONE
*             @arg LPUART_PARITY_EVEN
*             @arg LPUART_PARITY_ODD 
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_parity(LPUART_t *lpuartx,uint32_t parity)
{
    MODIFY_REG(lpuartx->CR1, USART_CR1_PTS | USART_CR1_PEN, parity);
} 

/** 
* @brief  获取LPUART奇偶校验
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART奇偶校验项
*             @arg LPUART_PARITY_NONE
*             @arg LPUART_PARITY_EVEN
*             @arg LPUART_PARITY_ODD 
*/
__STATIC_INLINE uint32_t std_lpuart_get_parity(LPUART_t *lpuartx)
{
    return(lpuartx->CR1 & (USART_CR1_PTS | USART_CR1_PEN));
}

/** 
* @brief  LPUART 字符长度配置
* @param  lpuartx LPUART外设
* @param  word_length LPUART 字符长度配置项
*             @arg LPUART_WORDLENGTH_8BITS
*             @arg LPUART_WORDLENGTH_9BITS 
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_word_length(LPUART_t *lpuartx, uint32_t word_length)
{
    MODIFY_REG(lpuartx->CR1, USART_CR1_WL, word_length);
}

/** 
* @brief  获取LPUART字符长度
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART 字符长度
*             @arg LPUART_WORDLENGTH_8BITS
*             @arg LPUART_WORDLENGTH_9BITS 
*/
__STATIC_INLINE uint32_t std_lpuart_get_word_length(LPUART_t *lpuartx)
{
    return (lpuartx->CR1 & USART_CR1_WL);
}

/** 
* @brief  LPUART 停止位配置
* @param  lpuartx LPUART外设
* @param  stopbits LPUART 停止位位数配置项
*             @arg LPUART_STOPBITS_1
*             @arg LPUART_STOPBITS_2
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_stopbits(LPUART_t *lpuartx, uint32_t stopbits)
{
    MODIFY_REG(lpuartx->CR2, USART_CR2_STOPBIT, stopbits);
}

/** 
* @brief  获取LPUART停止位
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART停止位位数
*             @arg LPUART_STOPBITS_1  
*             @arg LPUART_STOPBITS_2  
*/
__STATIC_INLINE uint32_t std_lpuart_get_stopbits(LPUART_t *lpuartx)
{
    return(lpuartx->CR2 & USART_CR2_STOPBIT);
}

/** 
* @brief  LPUART 字符大小端配置
* @param  lpuartx LPUART外设
* @param  data_order LPUART 字符帧格式大小端配置
*             @arg LPUART_DATA_ORDER_LSBFIRST
*             @arg LPUART_DATA_ORDER_MSBFIRST
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_data_order(LPUART_t *lpuartx, uint32_t data_order)
{
    MODIFY_REG(lpuartx->CR2, USART_CR2_MSBFIRST, data_order);
}

/** 
* @brief  获取 LPUART 字符大小端配置
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART 字符帧格式大小端配置
*             @arg LPUART_DATA_ORDER_LSBFIRST
*             @arg LPUART_DATA_ORDER_MSBFIRST
*/
__STATIC_INLINE uint32_t std_lpuart_get_data_order(LPUART_t *lpuartx)
{
    return(lpuartx->CR2 & USART_CR2_MSBFIRST);
}

/** 
* @brief  LPUART 传输方向控制
* @param  lpuartx LPUART外设
* @param  direction 传输方向控制
*             @arg LPUART_DIRECTION_NONE 
*             @arg LPUART_DIRECTION_SEND                                                                                        
*             @arg LPUART_DIRECTION_RECEIVE                                                      
*             @arg LPUART_DIRECTION_SEND_RECEIVE                                                                                                               
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_transfer_direction(LPUART_t *lpuartx, uint32_t direction)
{
    MODIFY_REG(lpuartx->CR1, USART_CR1_TE|USART_CR1_RE, direction);
}

/** 
* @brief  获取 LPUART 传输方向控制
* @param  lpuartx LPUART外设
* @retval uint32_t 传输方向
*             @arg LPUART_DIRECTION_NONE
*             @arg LPUART_DIRECTION_SEND                                                                                        
*             @arg LPUART_DIRECTION_RECEIVE                                                      
*             @arg LPUART_DIRECTION_SEND_RECEIVE                                                                                                               
*/
__STATIC_INLINE uint32_t std_lpuart_get_transfer_direction(LPUART_t *lpuartx)
{
    return(lpuartx->CR1 & (USART_CR1_TE|USART_CR1_RE));
}

/** 
* @brief  设置LPUART 匹配字符
* @param  lpuartx LPUART外设
* @param  data_match 匹配字符 8bits 0~0xFF
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_data_match(LPUART_t *lpuartx, uint32_t data_match)
{
    MODIFY_REG(lpuartx->CR2, USART_CR2_LPUART_CMFD, (data_match << USART_CR2_LPUART_CMFD_POS));
}

/** 
* @brief  LPUART 预分频寄存器配置
* @param  lpuartx LPUART外设
* @param  prescaler_value LPUART 预分频配置
*             @arg LPUART_PRESCALER_DIV1   
*             @arg LPUART_PRESCALER_DIV2                        
*             @arg LPUART_PRESCALER_DIV4                        
*             @arg ...                        
*             @arg LPUART_PRESCALER_DIV256                     
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_kclk_prescaler(LPUART_t *lpuartx, uint32_t prescaler_value)
{
    MODIFY_REG(lpuartx->PRESC, USART_PRESC_PRESCALER, prescaler_value);
}

/** 
* @brief  获取 LPUART 预分频值
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART预分频器分频值
*/
__STATIC_INLINE uint32_t std_lpuart_get_kclk_prescaler(LPUART_t *lpuartx)  
{
    return  (uint32_t)(LPUART_PRESCALER_TABLE[(lpuartx->PRESC & USART_PRESC_PRESCALER)]);    
}

/** 
* @brief  LPUART 从低功耗唤醒信号源选择
* @param  lpuartx LPUART外设
* @param  wakeup_method LPUART 通过LPWK标志唤醒的信号源选选择
*             @arg LPUART_WAKEUP_ON_STARTBIT                                                                 
*             @arg LPUART_WAKEUP_ON_READDATA_NOTEMPTY
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_wakeup_method(LPUART_t *lpuartx, uint32_t wakeup_method)
{
    MODIFY_REG(lpuartx->CR3, USART_CR3_LPWKS, wakeup_method);
}

/** 
* @brief  使能LPUART Stop模式下唤醒功能
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_wakeup_enable(LPUART_t *lpuartx)
{
    lpuartx->CR1 |= (USART_CR1_UEWK);
} 

/** 
* @brief  禁止LPUART Stop模式下唤醒功能
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_wakeup_disable(LPUART_t *lpuartx)
{
    lpuartx->CR1 &= (~USART_CR1_UEWK);
} 

/** 
* @brief  使能 LPUART接收器
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_rx_enable(LPUART_t *lpuartx)
{
    lpuartx->CR1 |= (USART_CR1_RE);
} 

/** 
* @brief  禁止 LPUART接收器
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_rx_disable(LPUART_t *lpuartx)
{
    lpuartx->CR1 &= (~USART_CR1_RE);
} 

/** 
* @brief  使能 LPUART发送器
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_tx_enable(LPUART_t *lpuartx)
{
    lpuartx->CR1 |= (USART_CR1_TE);
} 

/** 
* @brief  禁止 LPUART发送器
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_tx_disable(LPUART_t *lpuartx)
{
    lpuartx->CR1 &= (~USART_CR1_TE);
} 

/** 
* @brief  使能 LPUART 引脚交换
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_pin_swap_enable(LPUART_t *lpuartx)
{
    lpuartx->CR2 |= (USART_CR2_SWAP);
} 

/** 
* @brief  禁止 LPUART 引脚交换
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_pin_swap_disable(LPUART_t *lpuartx)
{
    lpuartx->CR2 &= (~USART_CR2_SWAP);
} 

/** 
* @brief  使能 LPUART RX引脚电平反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_rx_level_invert_enable(LPUART_t *lpuartx)
{
    lpuartx->CR2 |= (USART_CR2_RXIVC);
} 

/** 
* @brief  禁止 LPUART RX引脚电平反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_rx_level_invert_disable(LPUART_t *lpuartx)
{
    lpuartx->CR2 &= (~USART_CR2_RXIVC);
} 

/** 
* @brief  使能 LPUART TX引脚电平反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_tx_level_invert_enable(LPUART_t *lpuartx)
{
    lpuartx->CR2 |= (USART_CR2_TXIVC);
} 

/** 
* @brief  禁止 LPUART TX引脚电平反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_tx_level_invert_disable(LPUART_t *lpuartx)
{
    lpuartx->CR2 &= (~USART_CR2_TXIVC);
} 

/** 
* @brief  使能 LPUART 数据极性反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_data_invert_enable(LPUART_t *lpuartx)
{
    lpuartx->CR2 |= (USART_CR2_DATAIVC);
} 

/** 
* @brief  禁止 LPUART 数据极性反向
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_data_invert_disable(LPUART_t *lpuartx)
{
    lpuartx->CR2 &= (~USART_CR2_DATAIVC);
}

/** 
* @brief  使能 LPUART 单线半双工模式
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_half_duplex_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_HDEN);
} 

/** 
* @brief  禁止 LPUART 单线半双工模式
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_half_duplex_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_HDEN);
}

/** 
* @brief  使能 LPUART DMA模式接收
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_rx_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_DMAR);
} 

/** 
* @brief  禁止 LPUART DMA模式接收
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_rx_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_DMAR);
}

/** 
* @brief  使能 LPUART DMA模式发送
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_tx_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_DMAT);
} 

/** 
* @brief  禁止 LPUART DMA模式发送
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_tx_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_DMAT);
}

/** 
* @brief  使能 LPUART 接收出错时禁止DMA
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_off_onrxerror_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_DDRE);
}

/** 
* @brief  禁止 LPUART 接收出错时禁止DMA
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_dma_off_onrxerror_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_DDRE);
}

/** 
* @brief  使能 LPUART RTS硬件流控
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_hardflow_control_rts_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_RTSE);
} 

/** 
* @brief  禁止 LPUART RTS硬件流控
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_hardflow_control_rts_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_RTSE);
}
/** 
* @brief  LPUART 硬件流控配置
* @param  lpuartx LPUART外设
* @param  hardflow 硬件流控控制方式
*             @arg LPUART_FLOWCONTROL_NONE                                                         
*             @arg LPUART_FLOWCONTROL_RTS                          
*             @arg LPUART_FLOWCONTROL_CTS                          
*             @arg LPUART_FLOWCONTROL_RTS_CTS                                                                  

* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_hardflow_control(LPUART_t *lpuartx, uint32_t hardflow)
{
    MODIFY_REG(lpuartx->CR3, USART_CR3_CTSE|USART_CR3_RTSE, hardflow);
}

/** 
* @brief  使能 LPUART CTS硬件流控
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_hardflow_control_cts_enable(LPUART_t *lpuartx)
{
    lpuartx->CR3 |= (USART_CR3_CTSE);
}

/** 
* @brief  禁止 LPUART CTS硬件流控
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_hardflow_control_cts_disable(LPUART_t *lpuartx)
{
    lpuartx->CR3 &= (~USART_CR3_CTSE);
}

/** 
* @brief  使能LPUART CR1寄存器中控制的中断
* @param  lpuartx LPUART外设
* @param  interrupt LPUART中断源选择   
*             @arg LPUART_CR1_INTERRUPT_RXNE                               
*             @arg LPUART_CR1_INTERRUPT_TC                    
*             @arg LPUART_CR1_INTERRUPT_TXE                    
*             @arg LPUART_CR1_INTERRUPT_PE                                     
*             @arg LPUART_CR1_INTERRUPT_CM                                    
* @retval 无
*/
__STATIC_INLINE void std_lpuart_cr1_interrupt_enable(LPUART_t *lpuartx, uint32_t interrupt)
{
    lpuartx->CR1 |= (interrupt);
}

/** 
* @brief  禁止LPUART CR1寄存器中控制的中断
* @param  lpuartx LPUART外设
* @param  interrupt LPUART中断源选择
*             @arg LPUART_CR1_INTERRUPT_RXNE                              
*             @arg LPUART_CR1_INTERRUPT_TC                    
*             @arg LPUART_CR1_INTERRUPT_TXE                    
*             @arg LPUART_CR1_INTERRUPT_PE                                     
*             @arg LPUART_CR1_INTERRUPT_CM                       
* @retval 无
*/
__STATIC_INLINE void std_lpuart_cr1_interrupt_disable(LPUART_t *lpuartx, uint32_t interrupt)
{
    lpuartx->CR1 &= (~interrupt);
}

/** 
* @brief  获取LPUART CR1寄存器中控制的中断使能
* @param  lpuartx LPUART外设
* @param  interrupt LPUART中断源选择
*             @arg LPUART_CR1_INTERRUPT_RXNE                                
*             @arg LPUART_CR1_INTERRUPT_TC                    
*             @arg LPUART_CR1_INTERRUPT_TXE                    
*             @arg LPUART_CR1_INTERRUPT_PE                                     
*             @arg LPUART_CR1_INTERRUPT_CM                       
* @retval bool 返回选择的LPUART中断源使能状态
*             @arg true:  表示选择中断源使能
*             @arg false: 表示选择中断源未使能
*/
__STATIC_INLINE bool std_lpuart_cr1_get_interrupt_enable(LPUART_t *lpuartx, uint32_t interrupt)
{
    return ((lpuartx->CR1 & (interrupt)) == (interrupt));
}

/** 
* @brief  使能LPUART CR3寄存器中控制的中断
* @param  lpuartx LPUART外设
* @param  interrupt LPUART中断源选择
*             @arg LPUART_CR3_INTERRUPT_ERR                                              
*             @arg LPUART_CR3_INTERRUPT_CTS                                   
*             @arg LPUART_CR3_INTERRUPT_LPWK                                 
* @retval 无
*/
__STATIC_INLINE void std_lpuart_cr3_interrupt_enable(LPUART_t *lpuartx, uint32_t interrupt)
{
    lpuartx->CR3 |= (interrupt);
}

/** 
* @brief  禁止LPUART CR3寄存器中控制的中断
* @param  lpuartx LPUART外设
* @param  interrupt LPUART中断源选择
*             @arg LPUART_CR3_INTERRUPT_ERR                                              
*             @arg LPUART_CR3_INTERRUPT_CTS                                   
*             @arg LPUART_CR3_INTERRUPT_LPWK                                 
* @retval 无
*/
__STATIC_INLINE void std_lpuart_cr3_interrupt_disable(LPUART_t *lpuartx, uint32_t interrupt)
{
    lpuartx->CR3 &= (~interrupt);
}

/** 
* @brief  获取LPUART CR3寄存器中中断使能
* @param  lpuartx LPUART外设
* @param  interrupt 使能I2C中断源选择
*              @arg LPUART_CR3_INTERRUPT_ERR                                              
*              @arg LPUART_CR3_INTERRUPT_CTS                                   
*              @arg LPUART_CR3_INTERRUPT_LPWK                                 
* @retval bool 返回选择的LPUART中断源使能状态
*              @arg true:  表示选择中断源使能
*              @arg false: 表示选择中断源未使能
*/
__STATIC_INLINE bool std_lpuart_cr3_get_interrupt_enable(LPUART_t *lpuartx, uint32_t interrupt)
{
     return ((lpuartx->CR3 & (interrupt)) == (interrupt));
}

/** 
* @brief  获取 LPUART 标志状态
* @param  lpuartx LPUART外设
* @param  flag LPUART标志信息
*             @arg  LPUART_FLAG_PE                                
*             @arg  LPUART_FLAG_FE                                
*             @arg  LPUART_FLAG_ORE                              
*             @arg  LPUART_FLAG_RXNE   
*             @arg  LPUART_FLAG_TC                                                  
*             @arg  LPUART_FLAG_TXE
*             @arg  LPUART_FLAG_CTSIF
*             @arg  LPUART_FLAG_CTS
*             @arg  LPUART_FLAG_LPWKF                 
*             @arg  LPUART_FLAG_TEACK                
*             @arg  LPUART_FLAG_REACK                
*             @arg  LPUART_FLAG_BUSY
*             @arg  LPUART_FLAG_CM
*             @arg  LPUART_FLAG_LPWK

* @retval bool 返回输入标志置位状态
*             @arg true： 表示指定的标志置位
*             @arg false：表示指定的标志未置位            
*/
__STATIC_INLINE bool std_lpuart_get_flag(LPUART_t *lpuartx, uint32_t flag)
{
    return ((lpuartx->ISR & flag) == flag);
}

/** 
* @brief  清零 LPUART 状态标志 
* @param  lpuartx LPUART外设
* @param  clear_flag LPUART标志信息
*             @arg  LPUART_CLEAR_PE                                                              
*             @arg  LPUART_CLEAR_FE                                                              
*             @arg  LPUART_CLEAR_ORE                                                                                
*             @arg  LPUART_CLEAR_TC                                 
*             @arg  LPUART_CLEAR_CTS                                                            
*             @arg  LPUART_CLEAR_CM                                                                                
*             @arg  LPUART_CLEAR_LPWK                                                                                                                                       

* @retval 无      
*/
__STATIC_INLINE void std_lpuart_clear_flag(LPUART_t *lpuartx, uint32_t clear_flag)
{
    lpuartx->ICR = (clear_flag);
}

/** 
* @brief  LPUART 请求清空发送数据
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_request_tx_flush(LPUART_t *lpuartx)
{
    lpuartx->RQR |= (USART_RQR_TXFLUQ);
}

/** 
* @brief  LPUART 请求清空接收数据
* @param  lpuartx LPUART外设
* @retval 无
*/
__STATIC_INLINE void std_lpuart_request_rx_flush(LPUART_t *lpuartx)
{
    lpuartx->RQR |= (USART_RQR_RXFLUQ);
}

/** 
* @brief  LPUART 获取接收数据
* @param  lpuartx LPUART外设
* @retval uint32_t 接收数据
*/
__STATIC_INLINE uint32_t std_lpuart_rx_data_read(LPUART_t *lpuartx)
{
    return (lpuartx->RDR & USART_RDR_RDR);
}

/** 
* @brief  LPUART 写入发送数据
* @param  lpuartx LPUART外设
* @param  data 发送数据
* @retval 无
*/
__STATIC_INLINE void std_lpuart_tx_data_write(LPUART_t *lpuartx, uint32_t data)
{
    lpuartx->TDR = data;
}

/** 
* @brief  写入LPUART波特率分频寄存器
* @param  lpuartx LPUART外设
* @param  brr_value 波特率分频值:0x300 ~ 0xFFFFF
* @retval 无
*/
__STATIC_INLINE void std_lpuart_set_brr_value(LPUART_t *lpuartx, uint32_t brr_value)
{
    lpuartx->BRR = brr_value;
}

/** 
* @brief  获取LPUART波特率分频寄存器
* @param  lpuartx LPUART外设
* @retval uint32_t LPUART波特率分频配置值
*/
__STATIC_INLINE uint32_t std_lpuart_get_brr_value(LPUART_t *lpuartx)
{
    return (lpuartx->BRR & USART_BRR_LPUART);
}


/* LPUART 初始化相关函数 */
void std_lpuart_deinit(LPUART_t *lpuartx);
std_status_t std_lpuart_init(LPUART_t *lpuartx, std_lpuart_init_t *lpuart_init_param);
std_status_t std_lpuart_set_baudrate(LPUART_t *lpuartx, uint32_t baudrate);

/* LPUART 结构体初始化相关函数 */
void std_lpuart_struct_init(std_lpuart_init_t *lpuart_init);
    
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
#endif /* CIU32L051_STD_LPUART_H */
