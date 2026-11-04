/************************************************************************************************/
/**
* @file               ciu32l051_std_aes.h
* @author             MCU Ecosystem Development Team
* @brief              AES STD库驱动头文件。
*                     提供AES相关的STD库操作函数声明、数据类型以及常量的定义。
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_AES_H
#define CIU32L051_STD_AES_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup AES AES
* @brief 高级加密标准协处理器的STD库驱动
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
* @defgroup AES_Types  AES Types 
* @brief    AES数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief AES参数配置结构体定义
*/
typedef struct
{    
    uint32_t                           mode;                         /**< 加解密模式选择
                                                                              @arg AES_MODE_DEC... */
    uint32_t                           swapped_data_type;            /**< 数据交换类型，分别为无交换/16位/8位/1位交换
                                                                              @arg AES_SWAPPED_DATA_NONE... */
} std_aes_init_t;

/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup AES_Constants AES Constants 
* @brief    AES常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* 加解密模式定义 */
#define AES_MODE_ENC                   AES_CR_MOD_SEL_ENC            /**< 加密模式 */
#define AES_MODE_DEC                   AES_CR_MOD_SEL_DEC            /**< 解密模式 */

/* 数据交换类型 */
#define AES_SWAPPED_DATA_NONE          AES_CR_DATA_TYPE_NONE         /**< 无交换类型，数据不做交换     */
#define AES_SWAPPED_DATA_16BIT         AES_CR_DATA_TYPE_16BIT        /**< 16位交换类型，数据按半字交换 */
#define AES_SWAPPED_DATA_8BIT          AES_CR_DATA_TYPE_8BIT         /**< 8位交换类型，数据按字节交换  */
#define AES_SWAPPED_DATA_1BIT          AES_CR_DATA_TYPE_BIT          /**< 1位交换类型，数据按位交换    */

/* 中断源定义 */
#define AES_INTERRUPT_COMPLETE         AES_CSR_CCIE                  /**< 加解密完成中断使能  */

/* 状态标志 */
#define AES_FLAG_COMPLETE              AES_CSR_DONE                  /**< 加解密完成标志     */
#define AES_FLAG_BUSY                  AES_CSR_BUSY                  /**< 运算过程标志       */

/* 清除标志 */
#define AES_CLEAR_FLAG_COMPLETE        AES_CSR_CCFC                  /**< 加解密完成清除标志 */


/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup AES_External_Functions AES External Functions
* @brief    AES对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  设置加解密模式
* @param  mode 加解密模式
*             @arg AES_MODE_ENC：加密模式
*             @arg AES_MODE_DEC：解密模式
* @retval 无
*/
__STATIC_INLINE void std_aes_set_cryption_mode(uint32_t mode)                 
{
    MODIFY_REG(AES->CR, AES_CR_MOD_SEL, mode);
}

/**
* @brief  获取加解密模式设置
* @retval uint32_t 返回加解密模式设置
*             @arg AES_MODE_ENC：设置为加密模式
*             @arg AES_MODE_DEC：设置为解密模式
*/
__STATIC_INLINE uint32_t std_aes_get_cryption_mode(void)                 
{
    return (AES->CR & AES_CR_MOD_SEL);
}

/**
* @brief  设置数据交换类型
* @param  data_type 数据交换类型
*             @arg AES_SWAPPED_DATA_NONE：无交换类型，数据不做交换
*             @arg AES_SWAPPED_DATA_16BIT：16位交换类型，数据按半字交换
*             @arg AES_SWAPPED_DATA_8BIT： 8位交换类型，数据按字节交换
*             @arg AES_SWAPPED_DATA_1BIT： 1位交换类型，数据按位交换
* @retval 无
*/
__STATIC_INLINE void std_aes_set_data_type(uint32_t data_type)                 
{
    MODIFY_REG(AES->CR, AES_CR_DATA_TYPE, data_type);
}

/**
* @brief  获取数据交换类型
* @retval  uint32_t 数据交换类型
*             @arg AES_SWAPPED_DATA_NONE：无交换类型，数据不做交换
*             @arg AES_SWAPPED_DATA_16BIT： 16位交换类型，数据按半字交换
*             @arg AES_SWAPPED_DATA_8BIT：  8位交换类型，数据按字节交换
*             @arg AES_SWAPPED_DATA_1BIT：  1位交换类型，数据按位交换
*/
__STATIC_INLINE uint32_t std_aes_get_data_type(void)                 
{
    return (AES->CR & AES_CR_DATA_TYPE);
}

/** 
* @brief  获取AES标志的状态
* @param  flag 待获取状态的标志
*             @arg AES_FLAG_COMPLETE：运算完成标志
*             @arg AES_FLAG_BUSY：运算状态标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 查询标志置位
*             @arg false：查询标志未置位
*/
__STATIC_INLINE bool std_aes_get_flag(uint32_t flag)                        
{
    return ((AES->CSR & (flag)) == (flag));
}

/** 
* @brief  清除AES状态标志位
* @param  flag 待清除的标志
*             @arg AES_CLEAR_FLAG_COMPLETE：清除计算完成标志
* @retval 无
*/
__STATIC_INLINE void std_aes_clear_flag(uint32_t flag)                      
{
    MODIFY_REG(AES->CSR, AES_CSR_CCFC, flag);
}

/**
* @brief  使能DMA数据输入
* @retval 无
*/
__STATIC_INLINE void std_aes_dmain_enable(void)                 
{
    AES->CSR |= AES_CSR_DMAIN_EN;    
}

/**
* @brief  禁止DMA数据输入
* @retval 无
*/
__STATIC_INLINE void std_aes_dmain_disable(void)                 
{
    AES->CSR &= (~AES_CSR_DMAIN_EN);    
}

/**
* @brief  使能DMA数据输出
* @retval 无
*/
__STATIC_INLINE void std_aes_dmaout_enable(void)                 
{
    AES->CSR |= AES_CSR_DMAOUT_EN;    
}

/**
* @brief  禁止DMA数据输出
* @retval 无
*/
__STATIC_INLINE void std_aes_dmaout_disable(void)                 
{
    AES->CSR &= (~AES_CSR_DMAOUT_EN);    
}

/**
* @brief  使能AES中断
* @param  interrupt AES中断源
*             @arg AES_INTERRUPT_COMPLETE： 计算完成中断使能
* @retval 无
*/
__STATIC_INLINE void std_aes_enable_interrupt(uint32_t interrupt)           
{
    AES->CSR |= (interrupt);
}

/**
* @brief  禁止AES中断
* @param  interrupt AES中断源
*             @arg AES_INTERRUPT_COMPLETE： 计算完成中断
* @retval 无
*/
__STATIC_INLINE void std_aes_disable_interrupt(uint32_t interrupt)          
{
    AES->CSR &= (~(interrupt));
}

/** 
* @brief  获取算法中断使能的状态
* @param  interrupt AES中断源
*             @arg AES_INTERRUPT_COMPLETE： 计算完成中断
* @retval bool 返回逻辑表达式的判断结果
*             @arg true：使能中断
*             @arg false：未使能中断
*/
__STATIC_INLINE bool std_aes_get_interrupt_enable(uint32_t interrupt)       
{
    return ((AES->CSR & (interrupt)) == (interrupt));
}

/**
* @brief  写入密钥
* @param  p_key 指向密钥的指针
* @note   密钥长度为4个字
* @retval 无
*/
__STATIC_INLINE void std_aes_write_key(uint32_t *p_key)                 
{
    AES->KEYR[3] = p_key[0];
    AES->KEYR[2] = p_key[1];
    AES->KEYR[1] = p_key[2];
    AES->KEYR[0] = p_key[3];
}

/**
* @brief  写入数据
* @param  p_data 指向数据的指针
* @note   数据长度为4个字
* @retval 无
*/
__STATIC_INLINE void std_aes_write_data(uint32_t *p_data)                 
{
    AES->DR = p_data[0];
    AES->DR = p_data[1];
    AES->DR = p_data[2];
    AES->DR = p_data[3];
}

/**
* @brief  读取数据
* @param  p_data 指向数据的指针
* @note   数据长度为4个字
* @retval 无
*/
__STATIC_INLINE void std_aes_read_data(uint32_t *p_data)                 
{
    p_data[0] = AES->DR;
    p_data[1] = AES->DR;
    p_data[2] = AES->DR;
    p_data[3] = AES->DR;
}

void std_aes_init(std_aes_init_t *aes_init_param);
void std_aes_deinit(void);
void std_aes_struct_init(std_aes_init_t *aes_init_struct);

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

#endif /* CIU32L051_STD_AES_H */
