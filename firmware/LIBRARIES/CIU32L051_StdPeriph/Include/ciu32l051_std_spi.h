/************************************************************************************************/
/**
* @file               ciu32l051_std_spi.h
* @author             MCU Ecosystem Development Team
* @brief              SPI STD库驱动头文件。
*                     提供SPI相关的STD库操作函数声明、数据类型以及常量的定义。
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_SPI_H
#define CIU32L051_STD_SPI_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup SPI SPI
* @brief 串行外设接口的STD库驱动 
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
* @defgroup SPI_Types SPI Types
* @brief  SPI数据类型定义
* @{
*
*/
/************************************************************************************************/

/**
* @brief  SPI初始化配置结构体定义
*/
typedef struct
{
    uint32_t mode;                     /**< SPI工作模式
                                                @arg SPI_MODE_SLAVE
                                                @arg SPI_MODE_MASTER                            */

    uint32_t baud_rate_prescaler;      /**< SPI速率配置参数                                    
                                                @arg  SPI_BAUDRATEPRESCALER_2          
                                                @arg  SPI_BAUDRATEPRESCALER_4 ...      
                                                @note 主机输出时钟设置，从机不需要设置          */

    uint32_t clk_polarity;             /**< SPI时钟极性                                
                                                @arg SPI_POLARITY_LOW                  
                                                @arg SPI_POLARITY_HIGH                          */

    uint32_t clk_phase;                /**< SPI时钟相位                                
                                                @arg SPI_PHASE_1EDGE                   
                                                @arg SPI_PHASE_2EDGE                            */

}std_spi_init_t; 


/** 
* @} 
*/


/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup SPI_Constants SPI Constants
* @brief SPI常量定义及宏定义
* @{
*/
/************************************************************************************************/

/* SPI 工作模式 */
#define SPI_MODE_SLAVE                  (0x00000000U)                      /**< SPI从机模式     */
#define SPI_MODE_MASTER                 SPI_CR1_MSTR                       /**< SPI主机模式     */

/* SPI 速率配置参数 */    
#define SPI_BAUDRATEPRESCALER_2         SPI_CR1_BR_PCLK_DIV_2              /**< SPI速率为fPLCK/2   */
#define SPI_BAUDRATEPRESCALER_4         SPI_CR1_BR_PCLK_DIV_4              /**< SPI速率为fPLCK/4   */
#define SPI_BAUDRATEPRESCALER_8         SPI_CR1_BR_PCLK_DIV_8              /**< SPI速率为fPLCK/8   */
#define SPI_BAUDRATEPRESCALER_16        SPI_CR1_BR_PCLK_DIV_16             /**< SPI速率为fPLCK/16  */
#define SPI_BAUDRATEPRESCALER_32        SPI_CR1_BR_PCLK_DIV_32             /**< SPI速率为fPLCK/32  */
#define SPI_BAUDRATEPRESCALER_64        SPI_CR1_BR_PCLK_DIV_64             /**< SPI速率为fPLCK/64  */
#define SPI_BAUDRATEPRESCALER_128       SPI_CR1_BR_PCLK_DIV_128            /**< SPI速率为fPLCK/128 */

/* SPI 时钟极性 */
#define SPI_POLARITY_LOW                (0x00000000U)                      /**< SPI时钟空闲为低 */
#define SPI_POLARITY_HIGH               SPI_CR1_CPOL                       /**< SPI时钟空闲为高 */

/* SPI 时钟相位 */
#define SPI_PHASE_1EDGE                 (0x00000000U)                      /**< SPI数据采样在第一个时钟沿 */
#define SPI_PHASE_2EDGE                 SPI_CR1_CPHA                       /**< SPI数据采样在第二个时钟沿 */

/* SPI 数据大小端 */
#define SPI_FIRSTBIT_MSB                (0x00000000U)                      /**< SPI数据收发为高位优先 */
#define SPI_FIRSTBIT_LSB                SPI_CR1_LSBFIRST                   /**< SPI数据收发为低位优先 */

/* SPI NSS输出状态*/
#define SPI_NSS_OUTPUT_LOW              (0x00000000U)                      /**< SPI片选信号输出低电平 */
#define SPI_NSS_OUTPUT_HIGH             SPI_CR2_NSSO                       /**< SPI片选信号输出高电平 */

/* SPI 中断事件 */
#define SPI_INTERRUPT_TXFE              SPI_CR1_TXFEIE                     /**< SPI发送数据寄存器为空中断使能 */
#define SPI_INTERRUPT_RXFNE             SPI_CR1_RXFNEIE                    /**< SPI接收数据寄存器非空中断使能 */
#define SPI_INTERRUPT_ERR               SPI_CR1_ERRIE                      /**< SPI错误中断使能                */

/* SPI 硬件状态信息 */
#define SPI_FLAG_TXFE                   SPI_ISR_TXFE                       /**< SPI发送数据寄存器空标志   */
#define SPI_FLAG_RXFNE                  SPI_ISR_RXFNE                      /**< SPI接收数据寄存器非空标志 */
#define SPI_FLAG_BUSY                   SPI_ISR_BUSY                       /**< SPI总线传输状态标志       */
#define SPI_FLAG_OVR                    SPI_ISR_OVR                        /**< SPI接收上溢出标志         */
#define SPI_FLAG_MMF                    SPI_ISR_MMF                        /**< SPI主机模式冲突标志       */

/* SPI 状态清除信息 */
#define SPI_CLEAR_FLAG_OVR              SPI_ICR_OVRCF                      /**< SPI主机上溢标志清除     */
#define SPI_CLEAR_FLAG_MMF              SPI_ICR_MMFCF                      /**< SPI主机模式冲突标志清除 */

/* 数据清空位 */
#define SPI_FLUSH_SEND                  SPI_DATACLR_TXCLR                  /**< SPI清空发送数据寄存器 */
#define SPI_FLUSH_RECEIVE               SPI_DATACLR_RXCLR                  /**< SPI清空接收数据寄存器 */


/** 
* @} 
*/


/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup SPI_External_Functions SPI External Functions
* @brief    SPI对外函数
* @{
*
*/
/************************************************************************************************/


/** 
* @brief  使能SPI
* @param  spix SPI外设   
* @retval 无
*/
__STATIC_INLINE void std_spi_enable(SPI_t *spix)
{
    spix->CR1 |= SPI_CR1_SPE;
}

/** 
* @brief  禁止SPI
* @param  spix SPI外设
* @retval 无
*/
__STATIC_INLINE void std_spi_disable(SPI_t *spix)
{
    spix->CR1 &= (~SPI_CR1_SPE);
}


/** 
* @brief  设置SPI主从模式
* @param  spix SPI外设
* @param  mode SPI主从模式
*             @arg SPI_MODE_SLAVE
*             @arg SPI_MODE_MASTER   
* @retval 无
*/
__STATIC_INLINE void std_spi_set_mode(SPI_t *spix, uint32_t mode)
{
    MODIFY_REG(spix->CR1, SPI_CR1_MSTR, mode);
}


/** 
* @brief  获取SPI主从模式
* @param  spix SPI外设
* @retval uint32_t SPI主从模式
*             @arg SPI_MODE_SLAVE
*             @arg SPI_MODE_MASTER  
*/
__STATIC_INLINE uint32_t std_spi_get_mode(SPI_t *spix)
{
    return (spix->CR1 & SPI_CR1_MSTR);
}


/** 
* @brief  设置SPI波特率
* @param  spix SPI外设
* @param  baud_rate SPI波特率
*             @arg  SPI_BAUDRATEPRESCALER_2      
*             @arg  SPI_BAUDRATEPRESCALER_4
*             @arg  ...  
*             @arg  SPI_BAUDRATEPRESCALER_128
* @note  主机输出时钟设置，从机不需要设置
* @retval 无
*/
__STATIC_INLINE void std_spi_set_baud_rate(SPI_t *spix, uint32_t baud_rate)
{
    MODIFY_REG(spix->CR1, SPI_CR1_BR, baud_rate);
}


/** 
* @brief  获取SPI波特率
* @param  spix SPI外设  
* @retval uint32_t  SPI波特率
*             @arg  SPI_BAUDRATEPRESCALER_2      
*             @arg  SPI_BAUDRATEPRESCALER_4
*             @arg  ...  
*             @arg  SPI_BAUDRATEPRESCALER_128
*/
__STATIC_INLINE uint32_t std_spi_get_baud_rate(SPI_t *spix)
{
    return (spix->CR1 & SPI_CR1_BR);
}


/** 
* @brief  设置SPI时钟极性
* @param  spix SPI外设
* @param  polarity SPI时钟极性
*             @arg SPI_POLARITY_LOW  
*             @arg SPI_POLARITY_HIGH 
* @retval 无
*/
__STATIC_INLINE void std_spi_set_polarity(SPI_t *spix, uint32_t polarity)
{
    MODIFY_REG(spix->CR1, SPI_CR1_CPOL, polarity);
}


/** 
* @brief  获取SPI时钟极性
* @param  spix SPI外设  
* @retval uint32_t SPI时钟极性
*             @arg SPI_POLARITY_LOW  
*             @arg SPI_POLARITY_HIGH 
*/
__STATIC_INLINE uint32_t std_spi_get_polarity(SPI_t *spix)
{
    return (spix->CR1 & SPI_CR1_CPOL);
}


/** 
* @brief  设置SPI时钟相位 
* @param  spix SPI外设
* @param  phase SPI时钟相位
*             @arg SPI_PHASE_1EDGE 
*             @arg SPI_PHASE_2EDGE 
* @retval 无
*/
__STATIC_INLINE void std_spi_set_phase(SPI_t *spix, uint32_t phase)
{
    MODIFY_REG(spix->CR1, SPI_CR1_CPHA, phase);
}


/** 
* @brief  获取SPI时钟相位 
* @param  spix SPI外设 
* @retval uint32_t SPI时钟相位
*             @arg SPI_PHASE_1EDGE 
*             @arg SPI_PHASE_2EDGE 
*/
__STATIC_INLINE uint32_t std_spi_get_phase(SPI_t *spix)
{
    return (spix->CR1 & SPI_CR1_CPHA);
}


/** 
* @brief  设置SPI数据大小端
* @param  spix SPI外设
* @param  first_bit SPI数据大小端
*             @arg SPI_FIRSTBIT_MSB 
*             @arg SPI_FIRSTBIT_LSB 
* @note   仅在禁止SPI（SPE为0）时才可对此位执行写操作
* @retval 无
*/
__STATIC_INLINE void std_spi_set_first_bit(SPI_t *spix, uint32_t first_bit)
{
    MODIFY_REG(spix->CR1, SPI_CR1_LSBFIRST, first_bit);
}


/** 
* @brief  获取SPI数据大小端
* @param  spix SPI外设 
* @retval uint32_t SPI数据大小端
*             @arg SPI_FIRSTBIT_MSB 
*             @arg SPI_FIRSTBIT_LSB 
*/
__STATIC_INLINE uint32_t std_spi_get_first_bit(SPI_t *spix)
{
    return (spix->CR1 & SPI_CR1_LSBFIRST);
}


/** 
* @brief  使能NSS软片选
* @param  spix SPI外设 
* @note   SPI_CR1_SSM位仅在从机模式下设置有效
* @retval 无
*/
__STATIC_INLINE void std_spi_nss_soft_chip_select_enable(SPI_t *spix)
{
    spix->CR1 |= SPI_CR1_SSM;
}

/** 
* @brief  禁止NSS软片选
* @param  spix SPI外设 
* @note   SPI_CR1_SSM位仅在从机模式下设置有效
* @retval 无
*/
__STATIC_INLINE void std_spi_nss_soft_chip_select_disable(SPI_t *spix)
{
    spix->CR1 &= (~SPI_CR1_SSM);
}

/** 
* @brief  使能SPI NSS输出
* @param  spix SPI外设 
* @note   SPI_CR1_NSSOE位仅在主机模式下设置有效
* @retval 无
*/
__STATIC_INLINE void std_spi_nss_output_enable(SPI_t *spix)
{
    spix->CR1 |= SPI_CR1_NSSOE;
}


/** 
* @brief  禁止SPI NSS输出
* @param  spix SPI外设 
* @retval 无
*/
__STATIC_INLINE void std_spi_nss_output_disable(SPI_t *spix)
{
    spix->CR1 &= (~SPI_CR1_NSSOE);
}


/** 
* @brief  使能SPI 中断
* @param  spix SPI外设
* @param  spi_interrupt SPI中断信息
*             @arg SPI_INTERRUPT_TXFE     
*             @arg SPI_INTERRUPT_RXFNE    
*             @arg SPI_INTERRUPT_ERR      
* @retval 无
*/
__STATIC_INLINE void std_spi_interrupt_enable(SPI_t *spix, uint32_t spi_interrupt)
{
    spix->CR1 |= spi_interrupt;
}


/** 
* @brief  禁止SPI 中断
* @param  spix SPI外设
* @param  spi_interrupt SPI中断信息
*             @arg SPI_INTERRUPT_TXFE     
*             @arg SPI_INTERRUPT_RXFNE    
*             @arg SPI_INTERRUPT_ERR      
* @retval 无
*/
__STATIC_INLINE void std_spi_interrupt_disable(SPI_t *spix, uint32_t spi_interrupt)
{
    spix->CR1 &= (~spi_interrupt);
}


/** 
* @brief  获取SPI中断使能状态
* @param  spix SPI外设
* @param  spi_interrupt SPI中断信息
*             @arg SPI_INTERRUPT_TXFE     
*             @arg SPI_INTERRUPT_RXFNE    
*             @arg SPI_INTERRUPT_ERR      
* @retval bool 中断使能状态
*             @arg true 中断使能
*             @arg false 中断禁止
*/
__STATIC_INLINE bool std_spi_get_interrupt_enable(SPI_t *spix, uint32_t spi_interrupt)
{
    return ((spix->CR1 & (spi_interrupt)) == (spi_interrupt));
}


/** 
* @brief  使能SPI DMA发送
* @param  spix SPI外设
* @retval 无
*/
__STATIC_INLINE void std_spi_dma_tx_enable(SPI_t *spix)
{
    spix->CR1 |= SPI_CR1_DMAT;
}


/** 
* @brief  禁止SPI DMA发送
* @param  spix SPI外设
* @retval 无
*/
__STATIC_INLINE void std_spi_dma_tx_disable(SPI_t *spix)
{
    spix->CR1 &= (~SPI_CR1_DMAT);
}


/** 
* @brief  使能SPI DMA接收
* @param  spix SPI外设
* @retval 无
*/
__STATIC_INLINE void std_spi_dma_rx_enable(SPI_t *spix)
{
    spix->CR1 |= SPI_CR1_DMAR;
}


/** 
* @brief  禁止SPI DMA接收
* @param  spix SPI外设
* @retval 无
*/
__STATIC_INLINE void std_spi_dma_rx_disable(SPI_t *spix)
{
    spix->CR1 &= (~SPI_CR1_DMAR);
}


/** 
* @brief  设置SPI NSS输出状态
* @param  spix SPI外设
* @param  nss_output NSS输出状态
*             @arg SPI_NSS_OUTPUT_LOW   
*             @arg SPI_NSS_OUTPUT_HIGH  
* @note   仅在主机模式下且SPE使能的情况下设置有效
* @retval 无
*/
__STATIC_INLINE void std_spi_set_nss_output(SPI_t *spix, uint32_t nss_output)
{
    MODIFY_REG(spix->CR2, SPI_CR2_NSSO, nss_output);
}


/** 
* @brief  获取SPI 状态信息
* @param  spix SPI外设
* @param  flag SPI状态
*             @arg SPI_FLAG_TXFE 
*             @arg SPI_FLAG_RXFNE
*             @arg SPI_FLAG_BUSY 
*             @arg SPI_FLAG_OVR  
*             @arg SPI_FLAG_MMF  
* @retval bool SPI状态
*             true  状态发生
*             false 状态未发生
*/
__STATIC_INLINE bool std_spi_get_flag(SPI_t *spix, uint32_t flag)
{
    return ((spix->ISR & (flag)) == (flag));
}


/** 
* @brief  SPI 标志清零
* @param  spix SPI外设
* @param  flag SPI标志
*             @arg SPI_CLEAR_FLAG_OVR
*             @arg SPI_CLEAR_FLAG_MMF
* @retval 无
*/
__STATIC_INLINE void std_spi_clear_flag(SPI_t *spix, uint32_t flag)
{
    spix->ICR |= (flag);
}


/** 
* @brief  SPI 读数据
* @param  spix SPI外设
* @retval uint8_t: 返回读取的SPI数据寄存器读取的数据
*/
__STATIC_INLINE uint8_t std_spi_read_data(SPI_t *spix)
{
    return (spix->DR);
}

/** 
* @brief  SPI 写数据
* @param  spix SPI外设
* @param  send_data: 写入SPI数据寄存器的数据
* @retval 无
*/
__STATIC_INLINE void std_spi_write_data(SPI_t *spix, uint8_t send_data)
{
    spix->DR = send_data;
}


/** 
* @brief  清空SPI 数据寄存器
* @param  spix SPI外设
* @param  data_type 数据寄存器类型
*             @arg SPI_FLUSH_SEND
*             @arg SPI_FLUSH_RECEIVE
* @retval 无
*/
__STATIC_INLINE void std_spi_clear_data(SPI_t *spix, uint32_t data_type)
{
    MODIFY_REG(spix->DATACLR, (SPI_FLUSH_SEND | SPI_FLUSH_RECEIVE), data_type);
}



void std_spi_init(SPI_t *spix, std_spi_init_t *spi_init_param);
void std_spi_deinit(SPI_t *spix);
void std_spi_struct_init(std_spi_init_t *spi_init_struct);


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

#endif /* CIU32L051_STD_SPI_H */
