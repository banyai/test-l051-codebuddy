/************************************************************************************************/
/**
* @file               ciu32L051_std_usart.h
* @author             MCU Ecosystem Development Team
* @brief              USART STD库驱动头文件。
*                     提供USART相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_USART_H
#define CIU32L051_STD_USART_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup USART USART
* @brief 通用同步/异步收发器的STD库驱动
* @{
*/
/************************************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32L051_std_common.h"


/*-----------------------------------------type define------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup USART_Types USART Types 
* @brief  USART数据类型定义
* @{
*
*/
/************************************************************************************************/

/**
* @brief  USART初始化配置结构体定义
*/
typedef struct
{
    uint32_t direction;                                      /**< USART 传输模式(传输方向)
                                                                      @arg USART_DIRECTION_SEND ...                                              */
    uint32_t over_sample;                                    /**< USART 过采样方式
                                                                      @arg USART_OVERSAMPLE_16 ...                                          */
    uint32_t baudrate;                                       /**< USART 波特率 */
    
    uint32_t wordlength;                                     /**< USART 数据帧字长
                                                                      @arg USART_WORDLENGTH_8BITS ...                                            */
    uint32_t stopbits;                                       /**< USART 数据帧停止位长度
                                                                      @arg USART_STOPBITS_1 ...                                             */
    uint32_t parity;                                         /**< USART 数据帧奇偶校验
                                                                      @arg USART_PARITY_NONE ...                                            */
    uint32_t hardware_flow;                                  /**< USART 硬件控制
                                                                      @arg USART_FLOWCONTROL_NONE ...                                       */
}std_usart_init_t;

/**
* @brief  USART同步模式初始化配置结构体定义
*/
typedef struct
{    
    uint32_t sync_clk;                                  /**< 指定同步时钟模式
                                                                      @arg USART_CLOCK_ENABLE ...                                       */   
    uint32_t sync_clock_polarity;                            /**< 指定同步时钟极性
                                                                      @arg USART_SYNC_POLARITY_LOW ...                                      */
    uint32_t sync_clock_phase;                               /**< 指定同步时钟相位
                                                                      @arg USART_SYNC_PHASE_1EDGE ...                                       */
}std_usart_sync_clk_init_t;

/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup USART_Constants USART Constants
* @brief    USART常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* USART 数据帧长度 */
#define  USART_WORDLENGTH_8BITS                 USART_CR1_WL8BITS                     /**< 8-bits 字长 */
#define  USART_WORDLENGTH_9BITS                 USART_CR1_WL9BITS                     /**< 9-bits 字长 */


/* USART 数据帧奇偶校验 */
#define  USART_PARITY_NONE                      (0x00000000U)                         /**< 无校验 */
#define  USART_PARITY_EVEN                      USART_CR1_PEN                         /**< 偶校验 */
#define  USART_PARITY_ODD                       (USART_CR1_PEN | USART_CR1_PTS)       /**< 奇校验 */

/* USART 数据帧过采样 */
#define  USART_OVERSAMPLE_16                    (0x00000000U)                         /**< 16倍过采样 */
#define  USART_OVERSAMPLE_8                     USART_CR1_OVS8                        /**< 8倍过采样  */

/* USART接收器静默模式退出方式 */
#define  USART_MUTE_EXIT_IDLELINE               (0x00000000U)                         /**< 空闲帧唤醒   */
#define  USART_MUTE_EXIT_ADDRESSMARK            USART_CR1_RXWKUP                      /**< 地址匹配唤醒 */

/* USART 波特率分频配置范围 */
#define  USART_BRR_MIN                          (0x00000010U)                         /**< USART波特率寄存器允许的最小值 */
#define  USART_BRR_MAX                          (0x0000FFFFU)                         /**< USART波特率寄存器允许的最大值 */

/* USART传输模式 */
#define  USART_DIRECTION_NONE                   (0x00000000U)                         /**< 未使能发送器和接收器          */
#define  USART_DIRECTION_SEND                   USART_CR1_TE                          /**< 单接收模式(仅使能接收器)      */
#define  USART_DIRECTION_RECEIVE                USART_CR1_RE                          /**< 单发送模式(仅使能发送器)      */
#define  USART_DIRECTION_SEND_RECEIVE           (USART_CR1_TE |USART_CR1_RE)          /**< 发送/接收(使能发送器和接收器) */

/* USART 时钟控制，用于同步及智能卡模式 */
#define  USART_CLOCK_DISABLE                    (0x00000000U)                         /**< 禁止USART时钟 */
#define  USART_CLOCK_ENABLE                     USART_CR2_CLKEN                       /**< 使能USART时钟 */

/* USART 数据帧大小端 */
#define  USART_DATA_ORDER_LSBFIRST              (0x00000000U)                         /**< 低有效位优先 */
#define  USART_DATA_ORDER_MSBFIRST              USART_CR2_MSBFIRST                    /**< 高有效位优先 */

/* USART 同步时钟极性 */
#define  USART_SYNC_POLARITY_LOW                (0x00000000U)                         /**< 空闲态，同步时钟引脚处于低电平 */
#define  USART_SYNC_POLARITY_HIGH               USART_CR2_CPOL                        /**< 空闲态，同步时钟引脚处于高电平 */

/* USART 同步时钟相位 */
#define  USART_SYNC_PHASE_1EDGE                 (0x00000000U)                         /**< 同步时钟的第1个边沿采样数据帧的第1个bit */
#define  USART_SYNC_PHASE_2EDGE                 USART_CR2_CPHA                        /**< 同步时钟的第2个边沿采样数据帧的第1个bit */

/* USART唤醒地址长度 */
#define  USART_DETECT_4BITS                     (0x00000000U)                         /**< 4-bits长度唤醒地址 */
#define  USART_DETECT_7BITS                     USART_CR2_ADDRM                       /**< 7-bits长度唤醒地址 */

/* USART 数据帧停止位 */
#define  USART_STOPBITS_0_5                     USART_CR2_STOPBIT_0_5                 /**< 0.5bit停止位  */
#define  USART_STOPBITS_1                       USART_CR2_STOPBIT_1                   /**< 1bit停止位    */
#define  USART_STOPBITS_1_5                     USART_CR2_STOPBIT_1_5                 /**< 1.5bits停止位 */
#define  USART_STOPBITS_2                       USART_CR2_STOPBIT_2                   /**< 2bits停止位   */

/* USART RS485 Driver通信模式 */
#define  USART_DE_POLARITY_HIGH                 (0x00000000U)                         /**< Driver信号极性，高有效 */
#define  USART_DE_POLARITY_LOW                  USART_CR3_DEP                         /**< Driver信号极性，低有效 */

/* USART接收溢出 */
#define  USART_OVERRUN_ENABLE                   (0x00000000U)                         /**< 禁止USART接收溢出 */
#define  USART_OVERRUN_DISABLE                  USART_CR3_ORED                        /**< 使能USART接收溢出 */

/* USART IRDA 工作模式 */
#define  USART_IRDA_NORMAL_MODE                 (0x00000000U)                          /**< 使用IRDA 正常模式           */
#define  USART_IRDA_LOWPOWER_MODE               USART_CR3_IRLP                         /**< 使用IRDA 低功耗模式         */

/* USART LIN 模式 中断帧检测长度 */
#define  USART_LIN_BREAK_DETECT_10_BITS         (0x00000000U)                          /**< LIN模式中断帧检测长度 10bits   */
#define  USART_LIN_BREAK_DETECT_11_BITS         USART_CR2_LBDL                         /**< LIN模式中断帧检测长度 11bits   */

/* USART 硬件流控 */
#define  USART_FLOWCONTROL_NONE                 (0x00000000U)                          /**< 无流控功能                               */
#define  USART_FLOWCONTROL_RTS                  USART_CR3_RTSE                         /**< RTS功能使能                              */
#define  USART_FLOWCONTROL_CTS                  USART_CR3_CTSE                         /**< CTS功能使能                              */
#define  USART_FLOWCONTROL_RTS_CTS              (USART_CR3_RTSE | USART_CR3_CTSE)      /**< RTS和CTS功能同时使能                     */
                                                                                       
/* USART 数据帧采样策略 */                                                             
#define  USART_SAMPLE_THREE_BIT                 (0x00000000U)                          /**< Three-bit采样，支持噪声检测 */
#define  USART_SAMPLE_ONE_BIT                   USART_CR3_OBS                          /**< One-bit采样，不支持噪声检测 */
                                                                                       
/*
* USART中断使能位(USART_CR1、USART_CR3寄存器)
* RXNE或ERR中断使能时，溢出错误均会造成ORE中断
*/                                                                         
#define USART_CR1_INTERRUPT_IDLE                USART_CR1_IDLEIE                       /**< USART 空闲中断使能                                 */
#define USART_CR1_INTERRUPT_RXNE                USART_CR1_RXNEIE                       /**< USART 接收寄存器非空中断使能                       */
#define USART_CR1_INTERRUPT_TC                  USART_CR1_TCIE                         /**< USART 发送完成中断使能                             */
#define USART_CR1_INTERRUPT_TXE                 USART_CR1_TXEIE                        /**< USART 发送寄存器空中断使能                         */
#define USART_CR1_INTERRUPT_PE                  USART_CR1_PEIE                         /**< USART 奇偶校验错误中断使能                         */
#define USART_CR1_INTERRUPT_CM                  USART_CR1_CMIE                         /**< USART 字符匹配中断使能                             */
#define USART_CR1_INTERRUPT_RTO                 USART_CR1_RTOIE                        /**< USART 接收超时中断使能                             */
#define USART_CR1_INTERRUPT_EB                  USART_CR1_EBIE                         /**< USART 块尾检测中断使能                             */
#define USART_CR2_INTERRUPT_LBD                 USART_CR2_LBDIE                        /**< USART 中断帧检测中断使能                           */
#define USART_CR3_INTERRUPT_ERR                 USART_CR3_EIE                          /**< USART 错误中断使能（帧错误，噪声错误，溢出错误）   */
#define USART_CR3_INTERRUPT_CTS                 USART_CR3_CTSIE                        /**< USART CTS中断使能                                  */
#define USART_CR3_INTERRUPT_TCBGT               USART_CR3_TCBGTIE                      /**< USART 保护时间前发送完成中断使能                   */
                                                                                       
                                                                                       
/* USART中断标志清除位(USART_ICR寄存器) */                                             
#define  USART_CLEAR_PE                         USART_ICR_PECF                         /**< 奇偶校验错误标志清除             */
#define  USART_CLEAR_FE                         USART_ICR_FECF                         /**< 帧错误标志清除                   */
#define  USART_CLEAR_NOISE                      USART_ICR_NOISECF                      /**< 噪声错误标志清除                 */
#define  USART_CLEAR_ORE                        USART_ICR_ORECF                        /**< 接收溢出错误标志清除             */
#define  USART_CLEAR_IDLE                       USART_ICR_IDLECF                       /**< 线路空闲标志清除                 */
#define  USART_CLEAR_TC                         USART_ICR_TCCF                         /**< 发送完成标志清除                 */
#define  USART_CLEAR_TCBGT                      USART_ICR_TCBGTCF                      /**< 在保护时间前发送完成标志清除     */
#define  USART_CLEAR_LBD                        USART_ICR_LBDCF                        /**< LBD标志清除                      */
#define  USART_CLEAR_CTS                        USART_ICR_CTSCF                        /**< CTS标志清除                      */
#define  USART_CLEAR_RTO                        USART_ICR_RTOCF                        /**< 接收超时标志清除                 */
#define  USART_CLEAR_EB                         USART_ICR_EBCF                         /**< 块尾标志清除                     */
#define  USART_CLEAR_CM                         USART_ICR_CMCF                         /**< 字符匹配清除                     */
                                                                                       
/* USART 状态标志 */
#define  USART_FLAG_REACK                       USART_ISR_REACK                        /**< USART 接收器使能确认标志                   */
#define  USART_FLAG_TEACK                       USART_ISR_TEACK                        /**< USART 发送器使能确认标志                   */
#define  USART_FLAG_IDLE                        USART_ISR_IDLE                         /**< USART 空闲标志                             */
#define  USART_FLAG_RECEIVE_BUSY                USART_ISR_BUSY                         /**< USART 接收忙(接收管脚上有数据传输)         */
#define  USART_FLAG_TXE                         USART_ISR_TXE                          /**< USART 发送数据寄存器空标志                 */
#define  USART_FLAG_TC                          USART_ISR_TC                           /**< USART 发送完成标志                         */
#define  USART_FLAG_TCBGT                       USART_ISR_TCBGT                        /**< USART 在保护时间前发送完成标志             */
#define  USART_FLAG_RXNE                        USART_ISR_RXNE                         /**< USART 接收数据寄存器非空标志               */
#define  USART_FLAG_LBD                         USART_ISR_LBD                          /**< USART 中断帧接收标志                       */
#define  USART_FLAG_CM                          USART_ISR_CMF                          /**< USART 字符/地址匹配标志                    */
#define  USART_FLAG_BKSEND                      USART_ISR_BKSEND                       /**< USART 中断字符发送标志                     */
#define  USART_FLAG_CTS                         USART_ISR_CTS                          /**< USART CTS标志                              */
#define  USART_FLAG_CTSIF                       USART_ISR_CTSIF                        /**< USART CTS标志中断标志                      */
#define  USART_FLAG_RTO                         USART_ISR_RTOF                         /**< USART 接收超时标志                         */
#define  USART_FLAG_EB                          USART_ISR_EBF                          /**< USART 块接收完成标志                       */
#define  USART_FLAG_RWU                         USART_ISR_RWU                          /**< USART 接收器静默模式标志                   */
#define  USART_FLAG_ORE                         USART_ISR_ORE                          /**< USART 接收溢出错误标志                     */
#define  USART_FLAG_NOISE                       USART_ISR_NOISE                        /**< USART 噪声错误标志                         */
#define  USART_FLAG_FE                          USART_ISR_FE                           /**< USART 帧错误标志                           */
#define  USART_FLAG_PE                          USART_ISR_PE                           /**< USART 奇偶校验错误标志                     */

/**
* @}
*/


/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup USART_External_Functions USART External Functions
* @brief    USART对外函数
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  使能USART
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_enable(USART_t *usartx)
{
    usartx->CR1 |= (USART_CR1_UE);    
}

/** 
* @brief  禁止USART
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_disable(USART_t *usartx)
{
    usartx->CR1 &= (~USART_CR1_UE);
}

/** 
* @brief  设置USART字符长度
* @param  usartx USART外设
* @param  word_length USART 字符长度
*             @arg USART_WORDLENGTH_8BITS
*             @arg USART_WORDLENGTH_9BITS 
* @retval 无
*/
__STATIC_INLINE void std_usart_set_word_length(USART_t *usartx, uint32_t word_length)
{
    MODIFY_REG(usartx->CR1, USART_CR1_WL, word_length);
}

/** 
* @brief  获取USART字符长度
* @param  usartx USART外设
* @retval uint32_t USART 字符长度
*             @arg USART_WORDLENGTH_8BITS
*             @arg USART_WORDLENGTH_9BITS 
*/
__STATIC_INLINE uint32_t std_usart_get_word_length(USART_t *usartx)
{
    return (usartx->CR1 & USART_CR1_WL);
}

/** 
* @brief  设置USART奇偶校验
* @param  usartx USART外设
* @param  parity USART奇偶校验项
*             @arg USART_PARITY_NONE
*             @arg USART_PARITY_EVEN
*             @arg USART_PARITY_ODD 
* @retval 无
*/
__STATIC_INLINE void std_usart_set_parity(USART_t *usartx,uint32_t parity)
{
    MODIFY_REG(usartx->CR1,(USART_CR1_PTS | USART_CR1_PEN), parity);
} 

/** 
* @brief  获取USART奇偶校验
* @param  usartx USART外设
* @retval uint32_t USART奇偶校验项
*             @arg USART_PARITY_NONE
*             @arg USART_PARITY_EVEN
*             @arg USART_PARITY_ODD 
*/
__STATIC_INLINE uint32_t std_usart_get_parity(USART_t *usartx )
{
    return(usartx->CR1 & (USART_CR1_PTS | USART_CR1_PEN));
} 

/** 
* @brief  设置USART停止位
* @param  usartx USART外设
* @param  stopbits USART停止位位数
*             @arg USART_STOPBITS_0_5  
*             @arg USART_STOPBITS_1    
*             @arg USART_STOPBITS_1_5  
*             @arg USART_STOPBITS_2    
* @retval 无
*/
__STATIC_INLINE void std_usart_set_stopbits(USART_t *usartx, uint32_t stopbits)
{
    MODIFY_REG(usartx->CR2, USART_CR2_STOPBIT, stopbits);
}

/** 
* @brief  获取USART停止位
* @param  usartx USART外设
* @retval uint32_t USART停止位位数
*             @arg USART_STOPBITS_0_5  
*             @arg USART_STOPBITS_1    
*             @arg USART_STOPBITS_1_5  
*             @arg USART_STOPBITS_2    
*/
__STATIC_INLINE uint32_t std_usart_get_stopbits(USART_t *usartx)
{
    return(usartx->CR2 & USART_CR2_STOPBIT);
}

/** 
* @brief  设置USART字符大小端
* @param  usartx USART外设
* @param  data_order USART 字符帧格式大小端
*             @arg USART_DATA_ORDER_LSBFIRST
*             @arg USART_DATA_ORDER_MSBFIRST
* @retval 无
*/
__STATIC_INLINE void std_usart_set_data_order(USART_t *usartx, uint32_t data_order)
{
    MODIFY_REG(usartx->CR2, USART_CR2_MSBFIRST, data_order);
}

/** 
* @brief  获取USART字符大小端
* @param  usartx USART外设
* @retval uint32_t USART 字符帧格式大小端
*             @arg USART_DATA_ORDER_LSBFIRST
*             @arg USART_DATA_ORDER_MSBFIRST
*/
__STATIC_INLINE uint32_t std_usart_get_data_order(USART_t *usartx)
{
    return(usartx->CR2 & USART_CR2_MSBFIRST);
}

/** 
* @brief  设置USART过采样模式
* @param  usartx USART外设
* @param  over_sample USART过采样模式
*             @arg USART_OVERSAMPLE_8
*             @arg USART_OVERSAMPLE_16
* @retval 无
*/
__STATIC_INLINE void std_usart_set_over_sample(USART_t *usartx,uint32_t over_sample)
{
    MODIFY_REG(usartx->CR1,USART_CR1_OVS8, over_sample);
}

/** 
* @brief  获取USART过采样模式
* @param  usartx USART外设
* @retval uint32_t USART过采样模式
*             @arg USART_OVERSAMPLE_8
*             @arg USART_OVERSAMPLE_16
*/
__STATIC_INLINE uint32_t std_usart_get_over_sample(USART_t *usartx)
{
    return (usartx->CR1 & USART_CR1_OVS8);
}
/** 
* @brief  设置USART采样策略
* @param  usartx USART外设
* @param  sample_method USART采样策略
*             @arg USART_SAMPLE_THREE_BIT
*             @arg USART_SAMPLE_ONE_BIT
* @retval 无
*/
__STATIC_INLINE void std_usart_set_sample_method(USART_t *usartx,uint32_t sample_method)
{
    MODIFY_REG(usartx->CR3,USART_CR3_OBS, sample_method);
}

/** 
* @brief  设置USART传输方向
* @param  usartx USART外设
* @param  direction USART传输方向
*             @arg USART_DIRECTION_NONE
*             @arg USART_DIRECTION_SEND                                                                                        
*             @arg USART_DIRECTION_RECEIVE                                                      
*             @arg USART_DIRECTION_SEND_RECEIVE                                                                                                               
* @retval 无
*/
__STATIC_INLINE void std_usart_set_transfer_direction(USART_t *usartx, uint32_t direction)
{
    MODIFY_REG(usartx->CR1, USART_CR1_TE|USART_CR1_RE, direction);
}

/** 
* @brief  获取 USART 传输方向控制
* @param  usartx USART外设
* @retval uint32_t 传输方向
*             @arg USART_DIRECTION_NONE  
*             @arg USART_DIRECTION_SEND                                                                                        
*             @arg USART_DIRECTION_RECEIVE                                                      
*             @arg USART_DIRECTION_SEND_RECEIVE                                                                                                               
*/
__STATIC_INLINE uint32_t std_usart_get_transfer_direction(USART_t *usartx)
{
    return(usartx->CR1 & (USART_CR1_TE|USART_CR1_RE));
}

/** 
* @brief  使能USART引脚交换
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_pin_swap_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_SWAP);
} 

/** 
* @brief  禁止USART引脚交换
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_pin_swap_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_SWAP);
} 

/** 
* @brief  使能USART RX引脚电平反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_rx_level_invert_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_RXIVC);
} 

/** 
* @brief  禁止USART RX引脚电平反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_rx_level_invert_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_RXIVC);
} 

/** 
* @brief  使能USART TX引脚电平反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_tx_level_invert_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_TXIVC);
} 

/** 
* @brief  禁止USART TX引脚电平反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_tx_level_invert_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_TXIVC);
} 

/** 
* @brief  使能USART数据极性反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_data_invert_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_DATAIVC);
} 

/** 
* @brief  禁止USART数据极性反向
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_data_invert_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_DATAIVC);
}
/** 
* @brief  使能USART时钟 用于同步及智能卡模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_clk_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_CLKEN);
}

/** 
* @brief  禁止USART时钟 用于同步及智能卡模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_clk_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_CLKEN);
}

/** 
* @brief  设置USART同步时钟极性
* @param  usartx USART外设
* @param  sync_clk_polarity USART同步时钟极性
*             @arg USART_SYNC_POLARITY_LOW
*             @arg USART_SYNC_POLARITY_HIGH
* @retval 无
*/
__STATIC_INLINE void std_usart_set_sync_clk_polarity(USART_t *usartx, uint32_t sync_clk_polarity)
{
    MODIFY_REG(usartx->CR2, USART_CR2_CPOL, sync_clk_polarity);
}

/** 
* @brief  设置USART同步时钟相位
* @param  usartx USART外设
* @param  sync_clk_phase USART同步时钟相位
*             @arg USART_SYNC_PHASE_1EDGE
*             @arg USART_SYNC_PHASE_2EDGE
* @retval 无
*/
__STATIC_INLINE void std_usart_set_sync_clk_phase(USART_t *usartx, uint32_t sync_clk_phase)
{
    MODIFY_REG(usartx->CR2, USART_CR2_CPHA, sync_clk_phase);
}

/** 
* @brief  USART从静默退出方式选择
* @param  usartx USART外设
* @param  mute_mode USART 退出静默方式
*             @arg USART_MUTE_EXIT_IDLELINE                     
*             @arg USART_MUTE_EXIT_ADDRESSMARK
* @retval 无
*/
__STATIC_INLINE void std_usart_set_mute_exit_mode(USART_t *usartx,uint32_t mute_mode)
{
    MODIFY_REG(usartx->CR1, USART_CR1_RXWKUP, mute_mode);
}

/** 
* @brief  使能USART多机通信模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_multi_mode_enable(USART_t *usartx)
{
    usartx->CR1 |= (USART_CR1_RXMME);
} 

/** 
* @brief  禁止USART多机通信模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_multi_mode_disable(USART_t *usartx)
{
    usartx->CR1 &= (~USART_CR1_RXMME);
} 

/** 
* @brief  设置USART地址匹配模式选择
* @param  usartx USART外设
* @param  addr_mode USART 地址匹配模式
*             @arg USART_DETECT_4BITS                     
*             @arg USART_DETECT_7BITS
* @retval 无
*/
__STATIC_INLINE void std_usart_set_addr_match(USART_t *usartx,uint32_t addr_mode)
{
    MODIFY_REG(usartx->CR2, USART_CR2_ADDRM, addr_mode);
}

/** 
* @brief  设置USART地址匹配模式 本地地址
* @param  usartx USART外设
* @param  local_address USART 本地地址 8bits
* @note   地址匹配的行为还与选择的匹配模式有关，匹配模式有USART_DETECT_4BITS、USART_DETECT_7BITS两种
* @retval 无
*/
__STATIC_INLINE void std_usart_set_local_address(USART_t *usartx, uint32_t local_address)
{
    MODIFY_REG(usartx->CR2, USART_CR2_ADDR,(local_address << USART_CR2_ADDR_POS));
}

/** 
* @brief  设置USART 匹配字符
* @param  usartx USART外设
* @param  data_match 匹配字符 8bits 0~0xFF
* @retval 无
*/
__STATIC_INLINE void std_usart_set_data_match(USART_t *usartx, uint32_t data_match)
{
    MODIFY_REG(usartx->CR2, USART_CR2_ADDR,(data_match << USART_CR2_ADDR_POS));
}

/** 
* @brief  使能USART 智能卡模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_SCEN);
} 

/** 
* @brief  禁止USART 智能卡模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_SCEN);
}

/** 
* @brief  使能USART 智能卡模式NACK
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_nack_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_SCNAK);
} 

/** 
* @brief  禁止USART 智能卡模式NACK
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_nack_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_SCNAK);
}

/** 
* @brief  设置USART 智能卡模式自动重试次数
* @param  usartx USART外设
* @param  retry_cnt 智能卡模式重试次数 取值范围：0x00 ~ 0x07                                      
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_set_retry(USART_t *usartx, uint32_t retry_cnt)
{
    MODIFY_REG(usartx->CR3, USART_CR3_SCRETRY_MASK, retry_cnt<<USART_CR3_SCRETRY_POS);
}

/** 
* @brief  设置USART时钟预分频，用于智能卡和IrDA模式
* @param  usartx USART外设
* @param  presc_value 智能卡模式下为时钟输出的预分频值， IrDA模式下为工作时钟的预分频值 
* @note   智能卡模式下 presc_value 取值范围：0x01~ 0x01F, 对应预分频值 2 ~ 62
* @note   IrDA模式下 presc_value 取值范围：0x01~ 0x0FF, 对应预分频值 1 ~ 255 
* @note   presc_value 禁止赋值为0  
* @retval 无
*/
__STATIC_INLINE void std_usart_set_prescaler(USART_t *usartx, uint32_t presc_value)
{
    MODIFY_REG(usartx->GTPR, USART_GTPR_PSV, presc_value);
}

/** 
* @brief  获取USART 智能卡时钟输出的预分频值
* @param  usartx USART外设  
* @note   智能卡模式下 时钟输出的实际分配值为返回值*2，预分频值范围 2 ~ 62
* @note   IrDA模式下 返回值为IrDA工作时钟的实际分频值 预分频值范围 1 ~ 255 
* @retval uint32_t 预分频值
*/
__STATIC_INLINE uint32_t std_usart_get_prescaler(USART_t *usartx)
{
     return (usartx->GTPR & USART_GTPR_PSV);
}

/** 
* @brief  设置USART 智能卡模式额外保护时间
* @param  usartx USART外设
* @param  guard_time 智能卡模式额外保护时间
* @note   guard_time 取值范围：0x00~ 0x0FF, 单位：1etu
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_set_guard_time(USART_t *usartx, uint32_t guard_time)
{
    MODIFY_REG(usartx->GTPR, USART_GTPR_GT, (guard_time<< USART_GTPR_GT_POS));
}

/** 
* @brief  获取USART 智能卡模式额外保护时间
* @param  usartx USART外设
* @note   取值范围：0x00~ 0x0FF, 单位：1etu 
* @retval uint32_t 已配置的额外保护时间
*/
__STATIC_INLINE uint32_t std_usart_smartcard_get_guard_time(USART_t *usartx)
{
    return ((usartx->GTPR & USART_GTPR_GT) >> USART_GTPR_GT_POS);
}

/** 
* @brief  设置USART 智能卡模式预计接收的块长度
* @param  usartx USART外设
* @param  block_length 预计接收的块长度  取值范围：0x00~ 0x0FF,                                 
* @retval 无
*/
__STATIC_INLINE void std_usart_smartcard_set_block_length(USART_t *usartx, uint32_t block_length)
{
    MODIFY_REG(usartx->RTO, USART_RTO_BLKN, block_length<<USART_RTO_BLKN_POS);
}

/** 
* @brief  获取USART 智能卡模式预计接收的块长度
* @param  usartx USART外设  
* @retval uint32_t 已配置的预计接收块长度
*/
__STATIC_INLINE uint32_t std_usart_smartcard_get_block_length(USART_t *usartx)
{
     return ((usartx->RTO & USART_RTO_BLKN) >> USART_RTO_BLKN_POS);
}

/** 
* @brief  使能USART IrDA 模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_irda_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_IREN);
} 

/** 
* @brief  禁止USART IrDA 模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_irda_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_IREN);
}

/** 
* @brief  设置 USART IrDA 工作模式
* @param  usartx USART外设
* @param  irda_mode USART外设
*             @arg USART_IRDA_NORMAL_MODE
*             @arg USART_IRDA_LOWPOWER_MODE
* @retval 无
*/
__STATIC_INLINE void std_usart_irda_set_mode(USART_t *usartx, uint32_t irda_mode)
{
    MODIFY_REG(usartx->CR3, USART_CR3_IRLP, irda_mode);
}

/** 
* @brief  获取 USART IrDA 工作模式
* @param  usartx USART外设
* @retval uint32_t  IrDA工作模式
              @arg USART_IRDA_NORMAL_MODE
*             @arg USART_IRDA_LOWPOWER_MODE
*/
__STATIC_INLINE uint32_t std_usart_irda_get_mode(USART_t *usartx)
{
    return(usartx->CR3 & USART_CR3_IRLP);
}

/** 
* @brief  使能USART LIN 模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_lin_mode_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_LINEN);
} 

/** 
* @brief  禁止USART LIN 模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_lin_mode_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_LINEN);
}

/** 
* @brief  设置USART LIN 模式中断帧检测长度
* @param  usartx USART外设
* @param  break_length LIN 模式中断帧检测长度
*             @arg USART_LIN_BREAK_DETECT_10_BITS                                                         
*             @arg USART_LIN_BREAK_DETECT_11_BITS                                                                                        
* @retval 无
*/
__STATIC_INLINE void std_usart_lin_set_break_length(USART_t *usartx, uint32_t break_length)
{
    MODIFY_REG(usartx->CR2, USART_CR2_LBDL, break_length);
}

/** 
* @brief  获取USART LIN 模式中断帧检测长度
* @param  usartx USART外设                                                                                      
* @retval uint32_t LIN 模式中断帧检测长度
*             @arg USART_LIN_BREAK_DETECT_10_BITS                                                         
*             @arg USART_LIN_BREAK_DETECT_11_BITS 
*/
__STATIC_INLINE uint32_t std_usart_lin_get_break_length(USART_t *usartx)
{
    return (usartx->CR2 & USART_CR2_LBDL);
}

/** 
* @brief  使能 USART 接收超时
* @param  usartx USART外设                                                                                    
* @retval 无
*/
__STATIC_INLINE void std_usart_receive_timeout_enable(USART_t *usartx)
{
    usartx->CR2 |= (USART_CR2_RTOEN);
}

/** 
* @brief  禁用 USART 接收超时
* @param  usartx USART外设                                                                                    
* @retval 无
*/
__STATIC_INLINE void std_usart_receive_timeout_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_RTOEN);
}

/** 
* @brief  设置USART 接收超时时间
* @param  usartx USART外设
* @param  timeout 接收超时时间， 取值范围：0x00 ~ 0x00FFFFFF  单位：1数据位                                                                                      
* @retval 无
*/
__STATIC_INLINE void std_usart_set_receive_timeout(USART_t *usartx, uint32_t timeout)
{
    MODIFY_REG(usartx->RTO, USART_RTO_RTOV, timeout);
}

/** 
* @brief  设置USART 硬件流控控制方式
* @param  usartx USART外设
* @param  hardflow 硬件流控控制方式
*             @arg USART_FLOWCONTROL_NONE                                                         
*             @arg USART_FLOWCONTROL_RTS                          
*             @arg USART_FLOWCONTROL_CTS                          
*             @arg USART_FLOWCONTROL_RTS_CTS                                                                  
* @retval 无
*/
__STATIC_INLINE void std_usart_set_hardflow_control(USART_t *usartx, uint32_t hardflow)
{
    MODIFY_REG(usartx->CR3, USART_CR3_CTSE|USART_CR3_RTSE, hardflow);
}

/** 
* @brief  使能USART RS485 DE控制
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_de_control_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_DEM);
}


/** 
* @brief  禁止USART RS485 DE控制
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_de_control_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_DEM);
}

/** 
* @brief  设置USART RS485 DE控制建立时间
* @param  usartx USART外设
* @param  setup_time DE信号建立时间，范围为：0x00~0x1F
* @retval 无
*/
__STATIC_INLINE void std_usart_rs485_set_de_setup(USART_t *usartx,uint32_t setup_time)
{
    MODIFY_REG(usartx->CR1, USART_CR1_DEST, setup_time<<USART_CR1_DEST_POS);
}

/** 
* @brief  设置USART RS485 DE控制信号保持时间
* @param  usartx USART外设
* @param  hold_time USART DE控制信号保持时间，范围为：0x00~0x1F
* @retval 无
*/
__STATIC_INLINE void std_usart_rs485_set_de_hold(USART_t *usartx,uint32_t hold_time)
{
    MODIFY_REG(usartx->CR1, USART_CR1_DEHT, hold_time<<USART_CR1_DEHT_POS);
}

/** 
* @brief  USART RS485 DE信号极性选择
* @param  usartx USART外设
* @param  polarity USART RS485 DE信号极性
*             @arg USART_DE_POLARITY_HIGH                                            
*             @arg USART_DE_POLARITY_LOW                       
* @retval 无
*/
__STATIC_INLINE void std_usart_set_de_control_polarity(USART_t *usartx, uint32_t polarity)
{
    MODIFY_REG(usartx->CR3, USART_CR3_DEP, polarity);
}

/** 
* @brief  使能USART单线半双工模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_half_duplex_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_HDEN);
} 

/** 
* @brief  禁止USART单线半双工模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_half_duplex_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_HDEN);
}

/** 
* @brief  使能USART DMA模式USART接收
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_rx_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_DMAR);
} 

/** 
* @brief  禁止USART DMA模式USART接收
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_rx_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_DMAR);
}

/** 
* @brief  使能USART DMA模式发送
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_tx_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_DMAT);
} 

/** 
* @brief  禁止USART DMA模式发送
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_tx_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_DMAT);
}

/** 
* @brief  使能USART接收出错时禁止DMA
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_off_onrxerror_enable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_DDRE);
}

/** 
* @brief  禁止USART接收出错时禁止DMA
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_dma_off_onrxerror_disable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_DDRE);
}

/** 
* @brief  禁止USART上溢
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_overrun_disable(USART_t *usartx)
{
    usartx->CR3 |= (USART_CR3_ORED);
}

/** 
* @brief  使能USART上溢
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_overrun_enable(USART_t *usartx)
{
    usartx->CR3 &= (~USART_CR3_ORED);
}


/** 
* @brief  请求清空USART发送数据
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_request_tx_flush(USART_t *usartx)
{
    usartx->RQR |= (USART_RQR_TXFLUQ);
}

/** 
* @brief  请求清空USART接收数据
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_request_rx_flush(USART_t *usartx)
{
    usartx->RQR |= (USART_RQR_RXFLUQ);
}

/** 
* @brief  USART请求发送中断帧
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_request_break_frame(USART_t *usartx)
{
    usartx->RQR |= (USART_RQR_BKSENDQ);
}


/** 
* @brief  USART请求进入静默模式
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_request_enter_mutemode(USART_t *usartx)
{
    usartx->RQR |= (USART_RQR_MUTEQ);
}

/** 
* @brief  使能USART CR1寄存器中控制的中断
* @param  usartx USART外设
* @param  interrupt USART中断源选择
*             @arg USART_CR1_INTERRUPT_IDLE
*             @arg USART_CR1_INTERRUPT_RXNE
*             @arg USART_CR1_INTERRUPT_TC
*             @arg USART_CR1_INTERRUPT_TXE
*             @arg USART_CR1_INTERRUPT_PE
*             @arg USART_CR1_INTERRUPT_CM
*             @arg USART_CR1_INTERRUPT_RTO
*             @arg USART_CR1_INTERRUPT_EB                                                     
* @retval 无
*/
__STATIC_INLINE void std_usart_cr1_interrupt_enable(USART_t *usartx, uint32_t interrupt)
{
    usartx->CR1 |= (interrupt);
}

/** 
* @brief  禁止USART CR1寄存器中控制的中断
* @param  usartx USART外设
* @param  interrupt USART中断源选择
*             @arg USART_CR1_INTERRUPT_IDLE
*             @arg USART_CR1_INTERRUPT_RXNE
*             @arg USART_CR1_INTERRUPT_TC
*             @arg USART_CR1_INTERRUPT_TXE
*             @arg USART_CR1_INTERRUPT_PE
*             @arg USART_CR1_INTERRUPT_CM
*             @arg USART_CR1_INTERRUPT_RTO
*             @arg USART_CR1_INTERRUPT_EB                       
* @retval 无
*/
__STATIC_INLINE void std_usart_cr1_interrupt_disable(USART_t *usartx, uint32_t interrupt)
{
    usartx->CR1 &= (~interrupt);
}

/** 
* @brief  获取USART CR1寄存器中控制的中断使能
* @param  usartx USART外设
* @param  interrupt USART中断源选择
*             @arg USART_CR1_INTERRUPT_IDLE
*             @arg USART_CR1_INTERRUPT_RXNE
*             @arg USART_CR1_INTERRUPT_TC
*             @arg USART_CR1_INTERRUPT_TXE
*             @arg USART_CR1_INTERRUPT_PE
*             @arg USART_CR1_INTERRUPT_CM
*             @arg USART_CR1_INTERRUPT_RTO
*             @arg USART_CR1_INTERRUPT_EB                                    
* @retval bool 返回选择的USART中断源使能状态
*             @arg true:  表示选择中断源使能
*             @arg false: 表示选择中断源未使能
*/
__STATIC_INLINE bool std_usart_get_cr1_interrupt_enable(USART_t *usartx, uint32_t interrupt)
{
    return ((usartx->CR1 & (interrupt)) == (interrupt));
}

/** 
* @brief  使能USART LIN 模式中断帧检测中断
* @param  usartx USART外设               
* @retval 无
*/
__STATIC_INLINE void std_usart_lin_break_detection_interrupt_enable(USART_t *usartx)
{
    usartx->CR2 |= USART_CR2_INTERRUPT_LBD;
}

/** 
* @brief  禁止USART LIN 模式中断帧检测中断
* @param  usartx USART外设                                                                                                                     
* @retval 无
*/
__STATIC_INLINE void std_usart_lin_break_detection_interrupt_disable(USART_t *usartx)
{
    usartx->CR2 &= (~USART_CR2_INTERRUPT_LBD);
}

/** 
* @brief  获取USART LIN 模式中断帧检测中断
* @param  usartx USART外设               
* @retval bool 返回选择的USART中断源使能状态
*             @arg true  表示选择中断源使能
*             @arg false 表示选择中断源未使能
*/
__STATIC_INLINE bool std_usart_lin_get_break_interrupt_enable(USART_t *usartx)
{
     return ((usartx->CR2 & (USART_CR2_INTERRUPT_LBD)) == (USART_CR2_INTERRUPT_LBD));
}

/** 
* @brief  使能USART CR3寄存器中控制的中断
* @param  usartx USART外设
* @param  interrupt USART中断源选择
*             @arg USART_CR3_INTERRUPT_ERR                 
*             @arg USART_CR3_INTERRUPT_CTS                 
*             @arg USART_CR3_INTERRUPT_TCBGT               
* @retval 无
*/
__STATIC_INLINE void std_usart_cr3_interrupt_enable(USART_t *usartx, uint32_t interrupt)
{
    usartx->CR3 |= (interrupt);
}

/** 
* @brief  禁止USART CR3寄存器中控制的中断
* @param  usartx USART外设
* @param  interrupt USART中断源选择
*             @arg USART_CR3_INTERRUPT_ERR                 
*             @arg USART_CR3_INTERRUPT_CTS                 
*             @arg USART_CR3_INTERRUPT_TCBGT                                                                                                      
* @retval 无
*/
__STATIC_INLINE void std_usart_cr3_interrupt_disable(USART_t *usartx, uint32_t interrupt)
{
    usartx->CR3 &= (~interrupt);
}

/** 
* @brief  获取USART CR3寄存器中中断使能
* @param  usartx USART外设
* @param  interrupt 使能中断源选择
*             @arg USART_CR3_INTERRUPT_ERR                 
*             @arg USART_CR3_INTERRUPT_CTS                 
*             @arg USART_CR3_INTERRUPT_TCBGT               
* @retval bool 返回选择的USART中断源使能状态
*             @arg true  表示选择中断源使能
*             @arg false 表示选择中断源未使能
*/
__STATIC_INLINE bool std_usart_get_cr3_interrupt_enable(USART_t *usartx, uint32_t interrupt)
{
     return ((usartx->CR3 & (interrupt)) == (interrupt));
}

/** 
* @brief  获取USART标志
* @param  usartx  USART外设
* @param  flag    USART标志
*             @arg USART_FLAG_REACK           
*             @arg USART_FLAG_TEACK
*             @arg USART_FLAG_IDLE
*             @arg USART_FLAG_RECEIVE_BUSY
*             @arg USART_FLAG_TXE
*             @arg USART_FLAG_TC
*             @arg USART_FLAG_TCBGT
*             @arg USART_FLAG_RXNE
*             @arg USART_FLAG_LBD
*             @arg USART_FLAG_CM
*             @arg USART_FLAG_BKSEND
*             @arg USART_FLAG_CTS
*             @arg USART_FLAG_CTSIF
*             @arg USART_FLAG_RTO
*             @arg USART_FLAG_EB
*             @arg USART_FLAG_RWU
*             @arg USART_FLAG_ORE
*             @arg USART_FLAG_NOISE
*             @arg USART_FLAG_FE
*             @arg USART_FLAG_PE
* @retval bool   USART标志置起状态
*             @arg true   状态置起
*             @arg flase  状态未置起
*/
__STATIC_INLINE bool std_usart_get_flag(USART_t *usartx,uint32_t flag)
{
    return ((usartx->ISR & (flag)) == (flag));
}

/** 
* @brief  清除USART标志 
* @param  usartx USART外设
* @param  clear_flag USART标志信息
*             @arg USART_CLEAR_PE
*             @arg USART_CLEAR_FE
*             @arg USART_CLEAR_NOISE
*             @arg USART_CLEAR_ORE
*             @arg USART_CLEAR_IDLE
*             @arg USART_CLEAR_TC
*             @arg USART_CLEAR_TCBGT
*             @arg USART_CLEAR_LBD
*             @arg USART_CLEAR_CTS
*             @arg USART_CLEAR_RTO
*             @arg USART_CLEAR_EB
*             @arg USART_CLEAR_CM                                                                                                                                     
* @retval 无      
*/
__STATIC_INLINE void std_usart_clear_flag(USART_t *usartx, uint32_t clear_flag)
{
    usartx->ICR = (clear_flag);
}

/** 
* @brief  使能USART接收器
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_rx_enable(USART_t *usartx)
{
    usartx->CR1 |= (USART_CR1_RE);
} 

/** 
* @brief  禁止USART接收器
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_rx_disable(USART_t *usartx)
{
    usartx->CR1 &= (~USART_CR1_RE);
} 

/** 
* @brief  使能USART发送器
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_tx_enable(USART_t *usartx)
{
    usartx->CR1 |= (USART_CR1_TE);
} 

/** 
* @brief  禁止USART发送器
* @param  usartx USART外设
* @retval 无
*/
__STATIC_INLINE void std_usart_tx_disable(USART_t *usartx)
{
    usartx->CR1 &= (~USART_CR1_TE);
} 

/** 
* @brief  获取USART接收数据
* @param  usartx USART外设
* @retval uint32_t USART接收到的数据
*/
__STATIC_INLINE uint32_t std_usart_rx_read_data(USART_t *usartx)
{
    return (usartx->RDR & USART_RDR_RDR);
}

/** 
* @brief  写入USART发送数据
* @param  usartx USART外设
* @param  data_value   发送数据
* @retval 无
*/
__STATIC_INLINE void std_usart_tx_write_data(USART_t *usartx, uint32_t data_value)
{
    usartx->TDR = data_value;
}

/** 
* @brief  写入USART 波特率分频寄存器
* @param  usartx USART外设
* @param  brr_value 波特率分频值     范围： 0x10 ~ 0xFFFF
* @retval 无
*/
__STATIC_INLINE void std_usart_set_brr_value(USART_t *usartx, uint32_t brr_value)
{
    usartx->BRR = brr_value;
}

/** 
* @brief  获取USART波特率分频配置
* @param  usartx USART外设
* @retval uint32_t USART波特率分频的配置值
*/
__STATIC_INLINE uint32_t std_usart_get_brr_value(USART_t *usartx)
{
    return (usartx->BRR & USART_BRR_BRR);
}

std_status_t std_usart_init(USART_t *usartx,std_usart_init_t *usart_init_param);
void std_usart_deinit(USART_t *usartx);
void std_usart_struct_init(std_usart_init_t *usart_init_struct);
void std_usart_sync_clk_init(USART_t *usartx,std_usart_sync_clk_init_t *usart_sync_clock_init_param);
void std_usart_sync_clk_struct_init(std_usart_sync_clk_init_t *usart_sync_clock_init_struct);
std_status_t std_usart_baudrate_config(USART_t *usartx, uint32_t baudrate);

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

#endif /* CIU32L051_STD_USART_H */

