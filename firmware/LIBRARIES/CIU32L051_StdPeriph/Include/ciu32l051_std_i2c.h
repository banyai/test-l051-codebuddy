/************************************************************************************************/
/**
* @file               ciu32l051_std_i2c.h
* @author             MCU Ecosystem Development Team
* @brief              I2C STD库驱动头文件。
*                     提供I2C相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_I2C_H
#define CIU32L051_STD_I2C_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup I2C I2C
* @brief I2C接口的STD库驱动
* @{
*/
/************************************************************************************************/


#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------includes--------------------------------------------------*/
#include "ciu32l051_std_common.h"

/*------------------------------------type define-----------------------------------------------*/
     
/************************************************************************************************/
/**
* @defgroup I2C_Types I2C Types
* @brief    I2C数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  I2C初始化结构体定义
*/
typedef struct
{
    uint32_t timing;                /**< 时钟分频、通信速率、占空比、数据建立时间、数据保持时间配置参数  */
    
    uint32_t digital_filter;        /**< 数字滤波器配置
                                            @arg I2C_DIGITALFILTER_DISABLE...                            */
    
    uint32_t address1_length;       /**< 设备地址1地址模式配置
                                            @arg I2C_ADDRESS1MODE_7BIT...                                */
    
    uint32_t address1;              /**< I2C设备地址1                                                    */

    uint32_t acknowledge_type;      /**< 应答模式配置                                                    
                                            @arg I2C_DATA_ACK                                            */
}std_i2c_init_t;

/** 
* @} 
*/
/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup I2C_Constants I2C Constants
* @brief    I2C常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* 数字滤波器配置 */
#define I2C_DIGITALFILTER_DISABLE       I2C_CR1_DNF_DISABLE         /**< 数字滤波器禁止             */
#define I2C_DIGITALFILTER_1CLK          I2C_CR1_DNF_1CLK            /**< 滤除小于1个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_2CLK          I2C_CR1_DNF_2CLK            /**< 滤除小于2个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_3CLK          I2C_CR1_DNF_3CLK            /**< 滤除小于3个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_4CLK          I2C_CR1_DNF_4CLK            /**< 滤除小于4个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_5CLK          I2C_CR1_DNF_5CLK            /**< 滤除小于5个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_6CLK          I2C_CR1_DNF_6CLK            /**< 滤除小于6个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_7CLK          I2C_CR1_DNF_7CLK            /**< 滤除小于7个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_8CLK          I2C_CR1_DNF_8CLK            /**< 滤除小于8个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_9CLK          I2C_CR1_DNF_9CLK            /**< 滤除小于9个I2C_KCLK的噪声  */
#define I2C_DIGITALFILTER_10CLK         I2C_CR1_DNF_10CLK           /**< 滤除小于10个I2C_KCLK的噪声 */
#define I2C_DIGITALFILTER_11CLK         I2C_CR1_DNF_11CLK           /**< 滤除小于11个I2C_KCLK的噪声 */
#define I2C_DIGITALFILTER_12CLK         I2C_CR1_DNF_12CLK           /**< 滤除小于12个I2C_KCLK的噪声 */
#define I2C_DIGITALFILTER_13CLK         I2C_CR1_DNF_13CLK           /**< 滤除小于13个I2C_KCLK的噪声 */
#define I2C_DIGITALFILTER_14CLK         I2C_CR1_DNF_14CLK           /**< 滤除小于14个I2C_KCLK的噪声 */
#define I2C_DIGITALFILTER_15CLK         I2C_CR1_DNF_15CLK           /**< 滤除小于15个I2C_KCLK的噪声 */

/* I2C设备地址1模式配置 */
#define I2C_ADDRESS1MODE_7BIT           (0x00000000U)               /**< 7位地址模式  */
#define I2C_ADDRESS1MODE_10BIT          I2C_ADDR1_ADDR1MODE         /**< 10位地址模式 */

/* 从模式应答配置 */
#define I2C_DATA_ACK                    (0x00000000U)               /**< 从模式应答开启 */
#define I2C_DATA_NACK                   I2C_CR2_NACK                /**< 从模式应答关闭 */

/* I2C主模式寻址长度配置 */
#define I2C_MASTER_ADDRESSING_7BIT      (0x00000000U)               /**< I2C 主机发送7bit地址 */
#define I2C_MASTER_ADDRESSING_10BIT     I2C_CR2_ADDR10              /**< I2C 主机发送10bit地址*/

/* I2C设备地址2掩码配置 */
#define I2C_ADDR2_NOMASK                ((uint8_t)0x00U)            /**< ADDR2[7:1]全部比较                */
#define I2C_ADDR2_MASK1                 ((uint8_t)0x01U)            /**< ADDR2[1]被屏蔽,只比较ADDR2[7:2]   */
#define I2C_ADDR2_MASK2                 ((uint8_t)0x02U)            /**< ADDR2[2:1]被屏蔽,只比较ADDR2[7:3] */
#define I2C_ADDR2_MASK3                 ((uint8_t)0x03U)            /**< ADDR2[3:1]被屏蔽,只比较ADDR2[7:4] */
#define I2C_ADDR2_MASK4                 ((uint8_t)0x04U)            /**< ADDR2[4:1]被屏蔽,只比较ADDR2[7:5] */
#define I2C_ADDR2_MASK5                 ((uint8_t)0x05U)            /**< ADDR2[5:1]被屏蔽,只比较ADDR2[7:6] */
#define I2C_ADDR2_MASK6                 ((uint8_t)0x06U)            /**< ADDR2[6:1]被屏蔽,只比较ADDR2[7]   */
#define I2C_ADDR2_MASK7                 ((uint8_t)0x07U)            /**< ADDR2[7:1]全部屏蔽,对接收的全部7位地址(除I2C保留地址)应答 */

/* I2C 中断源配置 */
#define I2C_INTERRUPT_ERR               I2C_CR1_ERRIE               /**< 错误中断        */
#define I2C_INTERRUPT_TC                I2C_CR1_TCIE                /**< 发送完成中断    */
#define I2C_INTERRUPT_STOP              I2C_CR1_STOPIE              /**< 停止位检测中断  */
#define I2C_INTERRUPT_NACK              I2C_CR1_NACKIE              /**< 接收NACK中断    */
#define I2C_INTERRUPT_ADDR              I2C_CR1_ADDRIE              /**< 地址匹配中断    */
#define I2C_INTERRUPT_RX                I2C_CR1_RXIE                /**< 接收中断        */
#define I2C_INTERRUPT_TX                I2C_CR1_TXIE                /**< 发送中断        */

/* I2C 状态标志位 */
#define I2C_FLAG_TXE                    I2C_ISR_TXE                 /**< 发送数据寄存器为空标志    */
#define I2C_FLAG_TXIS                   I2C_ISR_TXIS                /**< 发送中断状态标志          */
#define I2C_FLAG_RXNE                   I2C_ISR_RXNE                /**< 接收数据寄存器非空标志    */
#define I2C_FLAG_ADDR                   I2C_ISR_ADDR                /**< 地址匹配标志 (从模式)     */
#define I2C_FLAG_NACK                   I2C_ISR_NACKF               /**< 接收NACK标志              */
#define I2C_FLAG_STOP                   I2C_ISR_STOPF               /**< 停止位检测标志            */
#define I2C_FLAG_TC                     I2C_ISR_TC                  /**< 发送完成标志 (主模式)     */
#define I2C_FLAG_TCR                    I2C_ISR_TCR                 /**< 发送完成等待重载标志      */
#define I2C_FLAG_BERR                   I2C_ISR_BERR                /**< 总线错误标志              */
#define I2C_FLAG_ARLO                   I2C_ISR_ARLO                /**< 仲裁失败标志              */
#define I2C_FLAG_OVR                    I2C_ISR_OVR                 /**< 溢出标志                  */
#define I2C_FLAG_BUSY                   I2C_ISR_BUSY                /**< 总线被占用标志            */
#define I2C_FLAG_DIR                    I2C_ISR_DIR                 /**< 数据传输方向标志 (从模式) */

/* I2C 数据传输方向配置 */
#define I2C_REQUEST_WRITE               (0x00000000U)               /**< 写请求     */
#define I2C_REQUEST_READ                I2C_CR2_RD_WRN              /**< 读请求     */

/* I2C 结束模式配置 */
#define I2C_MODE_RELOAD                 I2C_CR2_RELOAD              /**< 重装载模式     */
#define I2C_MODE_AUTOEND                I2C_CR2_AUTOEND             /**< 自动结束模式   */
#define I2C_MODE_SOFTEND                (0x00000000U)               /**< 软件结束模式   */

/* NBYTES传输最大值 */
#define I2C_MAX_NBYTES_SIZE             (255U)                      /**< NBYTES传输最大值 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup I2C_External_Functions I2C External Functions
* @brief    I2C对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  使能I2C接口
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_PE;
}

/** 
* @brief  禁止I2C接口
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_PE);
}

/** 
* @brief  配置数字滤波器
* @param  i2cx I2C外设
* @param  digital_filter 数字滤波器配置参数
*             @arg I2C_DIGITALFILTER_DISABLE: 禁止数字滤波器
*             @arg I2C_DIGITALFILTER_1CLK:    滤波脉宽小于1 * I2C_KCLK
*             @arg I2C_DIGITALFILTER_2CLK:    滤波脉宽小于2 * I2C_KCLK
*             @arg ...
*             @arg I2C_DIGITALFILTER_15CLK:   滤波脉宽小于15 * I2C_KCLK
* @note   滤波器配置只能在I2C禁止的状态下条件下有效
* @retval 无
*/
__STATIC_INLINE void std_i2c_digital_filter_config(I2C_t *i2cx, uint32_t digital_filter)
{
    MODIFY_REG(i2cx->CR1, I2C_CR1_DNF, digital_filter);
}

/** 
* @brief  I2C发送DMA请求使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_dma_tx_req_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_TXDMAEN;
}

/** 
* @brief  I2C发送DMA请求禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_dma_tx_req_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_TXDMAEN);
}

/** 
* @brief  I2C接收DMA请求使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_dma_rx_req_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_RXDMAEN;
}

/** 
* @brief  I2C接收DMA请求禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_dma_rx_req_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_RXDMAEN);
}

/** 
* @brief  I2C从模式时钟延长功能开启
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_clock_stretch_enable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_NOSTRETCH);
}

/** 
* @brief  I2C从模式时钟延长功能禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_clock_stretch_disable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_NOSTRETCH;
}

/** 
* @brief  I2C从模式字节计数器使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_slave_bytes_control_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_SBC;
}

/** 
* @brief  I2C从模式字节计数器禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_slave_bytes_control_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_SBC);
}

/** 
* @brief  I2C低功耗STOP模式唤醒使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_wakeup_from_stop_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_WUPEN;
}

/** 
* @brief  I2C低功耗STOP模式唤醒禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_wakeup_from_stop_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_WUPEN);
}

/** 
* @brief  I2C广播地址应答使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_general_call_address_enable(I2C_t *i2cx)
{
    i2cx->CR1 |= I2C_CR1_GCEN;
}

/** 
* @brief  I2C广播地址应答禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_general_call_address_disable(I2C_t *i2cx)
{
    i2cx->CR1 &= (~I2C_CR1_GCEN);
}

/** 
* @brief  设置I2C从模式地址1
* @param  i2cx I2C外设
* @param  dev_addr1_mode I2C设备地址1长度
*             @arg I2C_ADDRESS1MODE_7BIT:  I2C设备地址1长度为7bit
*             @arg I2C_ADDRESS1MODE_10BIT: I2C设备地址1长度为10bit
* @param  dev_address1 I2C设备地址1（该变量的范围在0x0~0x3FF之间）
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address1_config(I2C_t *i2cx, uint32_t dev_addr1_mode, uint32_t dev_address1)
{
    MODIFY_REG(i2cx->ADDR1, (I2C_ADDR1_ADDR1MODE | I2C_ADDR1_ADDR1), (dev_addr1_mode | dev_address1));
}

/** 
* @brief  I2C从模式地址1使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address1_enable(I2C_t *i2cx)
{
    i2cx->ADDR1 |= I2C_ADDR1_ADDR1EN;
}

/** 
* @brief  I2C从模式地址1禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address1_disable(I2C_t *i2cx)
{
    i2cx->ADDR1 &= (~I2C_ADDR1_ADDR1EN);
}

/** 
* @brief  设置I2C从模式地址2
* @param  i2cx I2C外设
* @param  dev_addr2_mask I2C设备地址2掩码设置
*             @arg I2C_ADDR2_NOMASK: ADDR2[7:1]全部比较 
*             @arg I2C_ADDR2_MASK1:  ADDR2[1]被屏蔽,只比较ADDR2[7:2] 
*             @arg I2C_ADDR2_MASK2:  ADDR2[2:1]被屏蔽,只比较ADDR2[7:3]
*             @arg ...
*             @arg I2C_ADDR2_MASK7:  ADDR2[7:1]全部屏蔽,对接收的全部7位地址(除I2C保留地址)应答
* @param  dev_address2 I2C设备地址1（该变量的范围在0x0~0x7F之间）
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address2_config(I2C_t *i2cx, uint32_t dev_addr2_mask, uint32_t dev_address2)
{
    MODIFY_REG(i2cx->ADDR2, (I2C_ADDR2_ADDR2MASK | I2C_ADDR2_ADDR2), ((dev_addr2_mask << I2C_ADDR2_ADDR2MASK_POS) | (dev_address2 << I2C_ADDR2_ADDR2_POS)));
}

/** 
* @brief  I2C从模式地址2使能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address2_enable(I2C_t *i2cx)
{
    i2cx->ADDR2 |= I2C_ADDR2_ADDR2EN;
}

/** 
* @brief  I2C从模式地址2禁止
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_device_address2_disable(I2C_t *i2cx)
{
    i2cx->ADDR2 &= (~I2C_ADDR2_ADDR2EN);
}

/** 
* @brief  I2C时序参数配置
* @param  i2cx I2C外设
* @param  timing 写入TIMING寄存器的值
* @note   I2C禁止时才能配置I2C时序参数（包括时钟预分频、数据建立时间、数据保持时间和SCL高电平时间、SCL低电平时间）
* @retval 无
*/
__STATIC_INLINE void std_i2c_set_timing(I2C_t *i2cx, uint32_t timing)
{
    i2cx->TIMING = timing;
}

/** 
* @brief  获取I2C时序参数配置
* @param  i2cx I2C外设
* @param  timing_param I2C时序控制参数
*             @arg I2C_TIMING_PRESC:  时钟预分频
*             @arg I2C_TIMING_SCLDEL: 数据建立时间
*             @arg I2C_TIMING_SDADEL: 数据保持时间
*             @arg I2C_TIMING_SCLH:   SCL高电平时间
*             @arg I2C_TIMING_SCLL:   SCL低电平时间
* @retval uint32_t TIMING寄存器的时序配置参数
*/
__STATIC_INLINE uint32_t std_i2c_get_timing(I2C_t *i2cx, uint32_t timing_param)
{
    return (uint32_t)(i2cx->TIMING & timing_param);
}

/** 
* @brief  使能I2C中断
* @param  i2cx I2C外设
* @param  interrupt 使能I2C中断源选择
*             @arg I2C_INTERRUPT_ERR:  I2C错误中断
*             @arg I2C_INTERRUPT_TC:   I2C传输完成中断
*             @arg I2C_INTERRUPT_STOP: I2C传输停止位中断
*             @arg ...
*             @arg I2C_INTERRUPT_TX:   I2C发送中断
* @retval 无
*/
__STATIC_INLINE void std_i2c_interrupt_enable(I2C_t *i2cx, uint32_t interrupt)
{
    i2cx->CR1 |= interrupt;
}

/** 
* @brief  禁止I2C中断
* @param  i2cx I2C外设
* @param  interrupt I2C中断选择
*             @arg I2C_INTERRUPT_ERR:  I2C错误中断
*             @arg I2C_INTERRUPT_TC:   I2C传输完成中断
*             @arg I2C_INTERRUPT_STOP: I2C传输停止位中断
*             @arg ...
*             @arg I2C_INTERRUPT_TX:   I2C发送中断
* @retval 无
*/
__STATIC_INLINE void std_i2c_interrupt_disable(I2C_t *i2cx, uint32_t interrupt)
{
    i2cx->CR1 &= (~interrupt);
}

/** 
* @brief  获取I2C中断使能状态
* @param  i2cx I2C外设
* @param  interrupt I2C中断选择
*             @arg I2C_INTERRUPT_ERR:  I2C错误中断
*             @arg I2C_INTERRUPT_TC:   I2C传输完成中断
*             @arg I2C_INTERRUPT_STOP: I2C传输停止位中断
*             @arg ...
*             @arg I2C_INTERRUPT_TX:   I2C发送中断
* @retval bool 返回选择的I2C中断使能状态
*             @arg true:  表示选择中断源使能
*             @arg false: 表示选择中断源未使能
*/
__STATIC_INLINE bool std_i2c_get_interrupt_enable(I2C_t *i2cx, uint32_t interrupt)
{
    return ((i2cx->CR1 & interrupt) == interrupt);
}

/** 
* @brief  获取I2C状态标志位
* @param  i2cx I2C外设
* @param  flag I2C状态标志位选择
*             @arg I2C_FLAG_TXE:      I2C发送数据寄存器为空
*             @arg I2C_FLAG_TXIS:     I2C发送中断状态
*             @arg I2C_FLAG_RXNE:     I2C接收数据寄存器非空
*             @arg ...
*             @arg I2C_FLAG_DIR:      I2C从模式数据传输方向
* @retval bool 返回选择的I2C状态标志位状态
*             @arg true:  状态标志位置起
*             @arg false: 状态标志位清零
*/
__STATIC_INLINE bool std_i2c_get_flag(I2C_t *i2cx, uint32_t flag)
{
    return ((i2cx->ISR & flag) == flag);
}

/** 
* @brief  从模式下获取总线上匹配的从设备地址
* @param  i2cx I2C外设
* @retval uint32_t 匹配的从设备地址（该值范围为0x00~0x3F）
*/
__STATIC_INLINE uint32_t std_i2c_get_address_match_code(I2C_t *i2cx)
{
    return (uint32_t)(((i2cx->ISR & I2C_ISR_ADDRCODE) >> I2C_ISR_ADDRCODE_POS) << 1);
}

/** 
* @brief  清除I2C状态标志位
* @param  i2cx I2C外设
* @param  flag I2C状态标志位选择
*             @arg I2C_FLAG_ADDR:     清除ADDR标志
*             @arg I2C_FLAG_NACK:     清除NACKF标志
*             @arg I2C_FLAG_STOP:     清除STOPF标志
*             @arg I2C_FLAG_BERR:     清除BERR标志
*             @arg I2C_FLAG_ARLO:     清除ARLO标志
*             @arg I2C_FLAG_OVR:      清除OVR标志
* @retval 无
*/
__STATIC_INLINE void std_i2c_clear_flag(I2C_t *i2cx, uint32_t flag)
{
    i2cx->ICR |= flag;
}

/** 
* @brief  使能I2C主模式自动结束功能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_autoend_enable(I2C_t *i2cx)
{
    i2cx->CR2 |= I2C_CR2_AUTOEND;
}

/** 
* @brief  禁止I2C主模式自动结束功能
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_autoend_disable(I2C_t *i2cx)
{
    i2cx->CR2 &= (~I2C_CR2_AUTOEND);
}

/** 
* @brief  使能I2C重载模式
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_reload_enable(I2C_t *i2cx)
{
    i2cx->CR2 |= I2C_CR2_RELOAD;
}

/** 
* @brief  禁止I2C重载模式
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_reload_disable(I2C_t *i2cx)
{
    i2cx->CR2 &= (~I2C_CR2_RELOAD);
}

/** 
* @brief  配置字节计数器计数值
* @param  i2cx I2C外设
* @param  value 字节计数器计数值（该值遍历的范围在0x0~0xFF之间）
* @retval 无
*/
__STATIC_INLINE void std_i2c_set_bytes_count_value(I2C_t *i2cx, uint32_t value)
{
     MODIFY_REG(i2cx->CR2, I2C_CR2_NBYTES, value << I2C_CR2_NBYTES_POS);
}

/** 
* @brief  获取字节计数器计数值
* @param  i2cx I2C外设
* @retval uint32_t 字节计数器计数值（该值遍历的范围在0x0~0xFF之间）
*/
__STATIC_INLINE uint32_t std_i2c_get_bytes_count_value(I2C_t *i2cx)
{
    return (uint32_t)((i2cx->CR2 & I2C_CR2_NBYTES) >> I2C_CR2_NBYTES_POS);
}

/** 
* @brief  配置从模式下地址匹配或接收下个数据时返回ACK或NACK应答信号
* @param  i2cx I2C外设
* @param  acknowledge 应答信号选择
*             @arg I2C_DATA_ACK:      返回ACK应答信号
*             @arg I2C_DATA_NACK:     返回NACK应答信号
* @retval 无
*/
__STATIC_INLINE void std_i2c_set_next_data_ack(I2C_t *i2cx, uint32_t acknowledge)
{
    MODIFY_REG(i2cx->CR2, I2C_CR2_NACK, acknowledge);
}

/** 
* @brief  主模式生成起始位或重复起始位
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_start_condition_generate(I2C_t *i2cx)
{
    i2cx->CR2 |= I2C_CR2_START;
}

/** 
* @brief  主模式生成停止位
* @param  i2cx I2C外设
* @retval 无
*/
__STATIC_INLINE void std_i2c_stop_condition_generate(I2C_t *i2cx)
{
    i2cx->CR2 |= I2C_CR2_STOP;
}

/** 
* @brief  使能10位地址头发送转接收控制
* @param  i2cx I2C外设
* @note   仅在主模式下配置有效
* @retval 无
*/
__STATIC_INLINE void std_i2c_10bit_address_auto_read_enable(I2C_t *i2cx)
{
    i2cx->CR2 |= I2C_CR2_HEAD10R;
}

/** 
* @brief  禁止10位地址头发送转接收控制
* @param  i2cx I2C外设
* @note   仅在主模式下配置有效
* @retval 无
*/
__STATIC_INLINE void std_i2c_10bit_address_auto_read_disable(I2C_t *i2cx)
{
    i2cx->CR2 &= (~I2C_CR2_HEAD10R);
}

/** 
* @brief  配置I2C主模式下寻址长度
* @param  i2cx I2C外设
* @param  address_mode I2C主模式寻址长度配置
*             @arg I2C_MASTER_ADDRESSING_7BIT:  I2C设备地址1长度为7bit
*             @arg I2C_MASTER_ADDRESSING_10BIT: I2C设备地址1长度为10bit
* @retval 无
*/
__STATIC_INLINE void std_i2c_address1_mode_config(I2C_t *i2cx, uint32_t address_mode)
{
    MODIFY_REG(i2cx->CR2, I2C_CR2_ADDR10, address_mode);
}

/** 
* @brief  主模式下设置数据传输方向
* @param  i2cx I2C外设
* @param  direct 主模式数据传输方向
*             @arg I2C_REQUEST_WRITE: 主模式下请求写数据
*             @arg I2C_REQUEST_READ:  主模式下请求读数据
* @note   当START位置1时，不允许设置传输方向
* @retval 无
*/
__STATIC_INLINE void std_i2c_set_transfer_direction(I2C_t *i2cx, uint32_t direct)
{
    MODIFY_REG(i2cx->CR2, I2C_CR2_RD_WRN, direct);
}

/** 
* @brief  主模式下获取数据传输方向
* @param  i2cx I2C外设
* @retval uint32_t 返回主模式数据传输方向
*             @arg I2C_REQUEST_WRITE: 主模式下请求写数据
*             @arg I2C_REQUEST_READ:  主模式下请求读数据
*/
__STATIC_INLINE uint32_t std_i2c_get_transfer_direction(I2C_t *i2cx)
{
    return (uint32_t)(i2cx->CR2 & I2C_CR2_RD_WRN);
}

/** 
* @brief  主模式下设置待发送从设备地址
* @param  i2cx I2C外设
* @param  slave_addr 待发送的从设备地址
* @note   当START位置1时，不允许设置从设备地址
* @retval 无
*/
__STATIC_INLINE void std_i2c_set_slave_address(I2C_t *i2cx, uint32_t slave_addr)
{
    MODIFY_REG(i2cx->CR2, I2C_CR2_SADDR, slave_addr);
}

/** 
* @brief  主模式下获取待发送从设备地址
* @param  i2cx I2C外设
* @retval uint32_t 返回从设备地址
*/
__STATIC_INLINE uint32_t std_i2c_get_slave_address(I2C_t *i2cx)
{
    return (uint32_t)(i2cx->CR2 & I2C_CR2_SADDR);
}

/** 
* @brief  I2C主模式通信配置
* @param  i2cx I2C外设
* @param  slave_addr 待发送从设备地址
* @param  transfer_size 传输数据长度（该变量的值的范围为0x0~0xFF）
* @param  end_mode 选择I2C的结束模式
*             @arg I2C_MODE_RELOAD:   重加载模式
*             @arg I2C_MODE_AUTOEND:  自动结束模式
*             @arg I2C_MODE_SOFTEND:  软件结束模式
* @retval 无
*/
__STATIC_INLINE void std_i2c_master_transfer_config(I2C_t *i2cx, uint32_t slave_addr, uint32_t transfer_size, uint32_t end_mode)
{   
    MODIFY_REG(i2cx->CR2, (I2C_CR2_SADDR | I2C_CR2_NBYTES | I2C_CR2_RELOAD | I2C_CR2_AUTOEND),   \
                          ((slave_addr & I2C_CR2_SADDR) | ((transfer_size << I2C_CR2_NBYTES_POS) & I2C_CR2_NBYTES)  \
                          | end_mode));    
}

/** 
* @brief  读数据寄存器
* @param  i2cx I2C外设
* @retval uint8_t 数据寄存器中的值（该值范围为0x00~0xFF）
*/
__STATIC_INLINE uint8_t std_i2c_receive_byte(I2C_t *i2cx)
{
    return (uint8_t)(i2cx->RDR);
}

/** 
* @brief  写数据寄存器
* @param  i2cx I2C外设
* @param  send_data 写入I2C TDR寄存器中的值（该变量范围为0x00~0xFF）
* @retval 无
*/
__STATIC_INLINE void std_i2c_transmit_byte(I2C_t *i2cx, uint8_t send_data)
{
    i2cx->TDR = send_data;
}

/* I2C初始化相关函数 */
void std_i2c_deinit(I2C_t *i2cx);
void std_i2c_init(I2C_t *i2cx, std_i2c_init_t *i2c_init);

/* I2C结构体初始化相关函数 */
void std_i2c_struct_init(std_i2c_init_t *i2c_init);

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

#endif /* CIU32L051_STD_I2C_H */
