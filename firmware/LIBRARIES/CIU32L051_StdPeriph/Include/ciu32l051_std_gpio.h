/************************************************************************************************/
/**
* @file               ciu32l051_std_gpio.h
* @author             MCU Ecosystem Development Team
* @brief              GPIO STD库驱动头文件。
*                     提供GPIO相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_GPIO_H
#define CIU32L051_STD_GPIO_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup GPIO GPIO
* @brief 通用输入/输出接口的STD库驱动
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
* @defgroup GPIO_Types GPIO Types
* @brief GPIO数据类型定义
* @{
*/
/************************************************************************************************/
/**
* @brief  GPIO初始化结构体定义
*/
typedef struct
{                         
    uint32_t pin;                 /**< 指定GPIO引脚，可以是GPIO引脚组合 
                                           @arg GPIO_PIN_0 ...           */

    uint32_t mode;                /**< 指定GPIO引脚模式及输出类型配置 
                                           @arg GPIO_MODE_INPUT
                                           @arg GPIO_MODE_ANALOG
                                           @arg GPIO_MODE_OUTPUT
                                           @arg GPIO_MODE_ALTERNATE      */

    uint32_t pull;                /**< 指定GPIO引脚上/下拉配置  
                                           @arg GPIO_NOPULL ...          */

    uint32_t output_type;         /**< 指定GPIO输出类型  
                                           @arg GPIO_OUTPUT_PUSHPULL
                                           @arg GPIO_OUTPUT_OPENDRAIN    */
    
    uint32_t alternate;           /**< 指定GPIO引脚复用功能配置   
                                           @arg GPIO_AF0_MCO ...         */
} std_gpio_init_t;

/** 
* @} 
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup GPIO_Constants GPIO Constants 
* @brief  GPIO常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* GPIO PIN常量 */
#define  GPIO_PIN_0                            ((uint16_t)0x0001U)        /**< 选定  PIN 0   */
#define  GPIO_PIN_1                            ((uint16_t)0x0002U)        /**< 选定  PIN 1   */
#define  GPIO_PIN_2                            ((uint16_t)0x0004U)        /**< 选定  PIN 2   */
#define  GPIO_PIN_3                            ((uint16_t)0x0008U)        /**< 选定  PIN 3   */
#define  GPIO_PIN_4                            ((uint16_t)0x0010U)        /**< 选定  PIN 4   */
#define  GPIO_PIN_5                            ((uint16_t)0x0020U)        /**< 选定  PIN 5   */
#define  GPIO_PIN_6                            ((uint16_t)0x0040U)        /**< 选定  PIN 6   */
#define  GPIO_PIN_7                            ((uint16_t)0x0080U)        /**< 选定  PIN 7   */
#define  GPIO_PIN_8                            ((uint16_t)0x0100U)        /**< 选定  PIN 8   */
#define  GPIO_PIN_9                            ((uint16_t)0x0200U)        /**< 选定  PIN 9   */
#define  GPIO_PIN_10                           ((uint16_t)0x0400U)        /**< 选定  PIN 10  */
#define  GPIO_PIN_11                           ((uint16_t)0x0800U)        /**< 选定  PIN 11  */
#define  GPIO_PIN_12                           ((uint16_t)0x1000U)        /**< 选定  PIN 12  */
#define  GPIO_PIN_13                           ((uint16_t)0x2000U)        /**< 选定  PIN 13  */
#define  GPIO_PIN_14                           ((uint16_t)0x4000U)        /**< 选定  PIN 14  */
#define  GPIO_PIN_15                           ((uint16_t)0x8000U)        /**< 选定  PIN 15  */
#define  GPIO_PIN_All                          ((uint16_t)0xFFFFU)        /**< 选定  全部    */

/* GPIO 模式配置常量 */
#define  GPIO_MODE_INPUT                       (0x00000000U)              /**< 输入浮空 */
#define  GPIO_MODE_OUTPUT                      (0x00000001U)              /**< 输出功能 */
#define  GPIO_MODE_ALTERNATE                   (0x00000002U)              /**< 复用功能 */
#define  GPIO_MODE_ANALOG                      (0x00000003U)              /**< 模拟功能 */

/* GPIO 上下拉配置参数 */
#define  GPIO_NOPULL                           (0x00000000U)              /**< 无上、下拉 */
#define  GPIO_PULLUP                           (0x00000001U)              /**< 上拉       */
#define  GPIO_PULLDOWN                         (0x00000002U)              /**< 下拉       */

/* GPIO 输出类型 */
#define  GPIO_OUTPUT_PUSHPULL                  (0x00000000U)             /**< 推挽输出   */
#define  GPIO_OUTPUT_OPENDRAIN                 (0x00000001U)             /**< 开漏输出   */

/* 复用功能0 */
#define  GPIO_AF0_MCO                          ((uint8_t)0x00U)           /**< MCO   复用功能映射 */
#define  GPIO_AF0_SWD                          ((uint8_t)0x00U)           /**< SWD   复用功能映射 */
#define  GPIO_AF0_SPI1                         ((uint8_t)0x00U)           /**< SPI1  复用功能映射 */
#define  GPIO_AF0_SPI2                         ((uint8_t)0x00U)           /**< SPI2  复用功能映射 */
#define  GPIO_AF0_TIM5                         ((uint8_t)0x00U)           /**< TIM5  复用功能映射 */

/* 复用功能1 */
#define  GPIO_AF1_IROUT                        ((uint8_t)0x01U)           /**< IROUT   复用功能映射 */
#define  GPIO_AF1_SPI2                         ((uint8_t)0x01U)           /**< SPI2    复用功能映射 */
#define  GPIO_AF1_TIM3                         ((uint8_t)0x01U)           /**< TIM3    复用功能映射 */
#define  GPIO_AF1_TIM4                         ((uint8_t)0x01U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF1_USART1                       ((uint8_t)0x01U)           /**< USART1  复用功能映射 */
#define  GPIO_AF1_UART2                        ((uint8_t)0x01U)           /**< UART2   复用功能映射 */
#define  GPIO_AF1_UART3                        ((uint8_t)0x01U)           /**< UART3   复用功能映射 */
#define  GPIO_AF1_UART4                        ((uint8_t)0x01U)           /**< UART4   复用功能映射 */

/* 复用功能2 */
#define  GPIO_AF2_IROUT                        ((uint8_t)0x02U)           /**< IROUT   复用功能映射 */
#define  GPIO_AF2_COMP2                        ((uint8_t)0x02U)           /**< COMP2   复用功能映射 */
#define  GPIO_AF2_SPI1                         ((uint8_t)0x02U)           /**< SPI1    复用功能映射 */
#define  GPIO_AF2_TIM3                         ((uint8_t)0x02U)           /**< TIM3    复用功能映射 */
#define  GPIO_AF2_TIM4                         ((uint8_t)0x02U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF2_TIM5                         ((uint8_t)0x02U)           /**< TIM5    复用功能映射 */
#define  GPIO_AF2_USART1                       ((uint8_t)0x02U)           /**< USART1  复用功能映射 */
#define  GPIO_AF2_UART3                        ((uint8_t)0x02U)           /**< UART3   复用功能映射 */
#define  GPIO_AF2_UART4                        ((uint8_t)0x02U)           /**< UART4   复用功能映射 */

/* 复用功能3 */
#define  GPIO_AF3_LCD                          ((uint8_t)0x03U)           /**< LCD     复用功能映射 */

/* 复用功能4 */
#define  GPIO_AF4_SPI2                         ((uint8_t)0x04U)           /**< SPI2    复用功能映射 */
#define  GPIO_AF4_TIM3                         ((uint8_t)0x04U)           /**< TIM3    复用功能映射 */
#define  GPIO_AF4_TIM4                         ((uint8_t)0x04U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF4_TIM5                         ((uint8_t)0x04U)           /**< TIM5    复用功能映射 */
#define  GPIO_AF4_UART2                        ((uint8_t)0x04U)           /**< UART2   复用功能映射 */
#define  GPIO_AF4_UART3                        ((uint8_t)0x04U)           /**< UART3   复用功能映射 */
#define  GPIO_AF4_UART4                        ((uint8_t)0x04U)           /**< UART4   复用功能映射 */
#define  GPIO_AF4_LPUART2                      ((uint8_t)0x04U)           /**< LPUART2 复用功能映射 */

/* 复用功能5 */
#define  GPIO_AF5_IROUT                        ((uint8_t)0x05U)           /**< IROUT   复用功能映射 */
#define  GPIO_AF5_MCO                          ((uint8_t)0x05U)           /**< MCO     复用功能映射 */
#define  GPIO_AF5_LPTIM1                       ((uint8_t)0x05U)           /**< LPTIM1  复用功能映射 */
#define  GPIO_AF5_TIM4                         ((uint8_t)0x05U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF5_TIM5                         ((uint8_t)0x05U)           /**< TIM5    复用功能映射 */
#define  GPIO_AF5_LPUART2                      ((uint8_t)0x05U)           /**< LPUART2 复用功能映射 */
#define  GPIO_AF5_UART3                        ((uint8_t)0x05U)           /**< UART3   复用功能映射 */

/* 复用功能6 */
#define  GPIO_AF6_LPTIM1                       ((uint8_t)0x06U)           /**< LPTIM1  复用功能映射 */
#define  GPIO_AF6_TIM4                         ((uint8_t)0x06U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF6_TIM5                         ((uint8_t)0x06U)           /**< TIM5    复用功能映射 */
#define  GPIO_AF6_LPUART1                      ((uint8_t)0x06U)           /**< LPUART1 复用功能映射 */
#define  GPIO_AF6_LPUART2                      ((uint8_t)0x06U)           /**< LPUART2 复用功能映射 */
#define  GPIO_AF6_USART1                       ((uint8_t)0x06U)           /**< USART1  复用功能映射 */
#define  GPIO_AF6_UART3                        ((uint8_t)0x06U)           /**< UART3   复用功能映射 */
#define  GPIO_AF6_I2C1                         ((uint8_t)0x06U)           /**< I2C1    复用功能映射 */

/* 复用功能7 */
#define  GPIO_AF7_IROUT                        ((uint8_t)0x07U)           /**< IROUT   复用功能映射 */
#define  GPIO_AF7_LPTIM1                       ((uint8_t)0x07U)           /**< LPTIM1  复用功能映射 */
#define  GPIO_AF7_TIM4                         ((uint8_t)0x07U)           /**< TIM4    复用功能映射 */
#define  GPIO_AF7_TIM5                         ((uint8_t)0x07U)           /**< TIM5    复用功能映射 */
#define  GPIO_AF7_LPUART2                      ((uint8_t)0x07U)           /**< LPUART2 复用功能映射 */
#define  GPIO_AF7_UART3                        ((uint8_t)0x07U)           /**< UART3   复用功能映射 */
#define  GPIO_AF7_I2C1                         ((uint8_t)0x07U)           /**< I2C1    复用功能映射 */
#define  GPIO_AF7_COMP1                        ((uint8_t)0x07U)           /**< COMP1   复用功能映射 */
#define  GPIO_AF7_COMP2                        ((uint8_t)0x07U)           /**< COMP2   复用功能映射 */

/* 复用功能寄存器GPIO源选择偏移位 */
#define  GPIO_AF_SELECT_OFFSET                 (0x0000000FU)              /**< GPIO源选择偏移位 */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup GPIO_External_Functions GPIO External Functions
* @brief    GPIO对外函数
* @{
*
*/
/************************************************************************************************/
/**
* @brief  设置GPIO引脚模式
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin  GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @param  mode GPIO引脚模式
*             @arg GPIO_MODE_INPUT     输入模式
*             @arg GPIO_MODE_OUTPUT    输出模式
*             @arg GPIO_MODE_ALTERNATE 复用模式
*             @arg GPIO_MODE_ANALOG    模拟模式
* @note   仅支持单个引脚
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_pin_mode(GPIO_t *gpiox, uint32_t pin, uint32_t mode)
{
    MODIFY_REG(gpiox->MODE, ((pin * pin) * GPIO_MODE_MODE0), ((pin * pin) * mode));
}

/**
* @brief  读取GPIO引脚模式
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval uint32_t GPIO引脚模式
*             @arg GPIO_MODE_INPUT     输入模式
*             @arg GPIO_MODE_OUTPUT    输出模式
*             @arg GPIO_MODE_ALTERNATE 复用模式
*             @arg GPIO_MODE_ANALOG    模拟模式
*/
__STATIC_INLINE uint32_t std_gpio_get_pin_mode(GPIO_t *gpiox, uint32_t pin)
{
    return ((gpiox->MODE & ((pin * pin) * GPIO_MODE_MODE0)) / (pin * pin));
}

/**
* @brief  设置GPIO引脚输出类型
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin_mask GPIO引脚组合
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @param  output_type GPIO引脚输出类型
*             @arg GPIO_OUTPUT_PUSHPULL  推挽输出
*             @arg GPIO_OUTPUT_OPENDRAIN 开漏输出
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_pin_output_type(GPIO_t *gpiox, uint32_t pin_mask, uint32_t output_type)
{
    MODIFY_REG(gpiox->OTYPE, pin_mask, pin_mask * output_type);
}

/**
* @brief  读取GPIO引脚输出类型
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin  GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval uint32_t GPIO引脚输出类型
*             @arg GPIO_OUTPUT_PUSHPULL  推挽输出
*             @arg GPIO_OUTPUT_OPENDRAIN 开漏输出
*/
__STATIC_INLINE uint32_t std_gpio_get_pin_output_type(GPIO_t *gpiox, uint32_t pin)
{
    return ((gpiox->OTYPE & (pin)) != 0U ? GPIO_OUTPUT_OPENDRAIN : GPIO_OUTPUT_PUSHPULL);
}

/**
* @brief  设置GPIO引脚上下拉配置
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @param  pull GPIO引脚上下拉配置
*             @arg GPIO_NOPULL   无上、下拉
*             @arg GPIO_PULLUP   上拉
*             @arg GPIO_PULLDOWN 下拉
* @note   仅支持单个引脚
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_pin_pull(GPIO_t *gpiox, uint32_t pin, uint32_t pull)
{
    MODIFY_REG(gpiox->PUPD, ((pin * pin) * GPIO_PUPD_PUPD0), ((pin * pin) * pull));
}

/**
* @brief  读取GPIO引脚上下拉配置
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin  GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval uint32_t GPIO引脚上下拉配置
*             @arg GPIO_NOPULL   无上、下拉
*             @arg GPIO_PULLUP   上拉
*             @arg GPIO_PULLDOWN 下拉
*/
__STATIC_INLINE uint32_t std_gpio_get_pin_pull(GPIO_t *gpiox, uint32_t pin)
{
  return ((gpiox->PUPD & ((pin * pin) * GPIO_PUPD_PUPD0)) / (pin * pin));
}

/**
* @brief  设置GPIO引脚（0~7）复用功能
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin  GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_7
* @param  alternate GPIO引脚（0~7）复用功能
*             @arg GPIO_AF0_MCO
*             @arg GPIO_AF0_SWD
*             @arg ...
*             @arg GPIO_AF1_IROUT
*             @arg GPIO_AF1_SPI2
*             @arg ...
*             @arg GPIO_AF2_IROUT
*             @arg GPIO_AF2_COMP2
*             @arg ...
*             @arg GPIO_AF3_LCD
*             @arg GPIO_AF4_SPI2
*             @arg GPIO_AF4_TIM3
*             @arg ...
*             @arg GPIO_AF5_IROUT
*             @arg GPIO_AF5_MCO
*             @arg ...
*             @arg GPIO_AF6_LPTIM1
*             @arg GPIO_AF6_TIM4
*             @arg ...
*             @arg GPIO_AF7_IROUT
*             @arg ...
*             @arg GPIO_AF7_COMP2
* @note   仅支持单个引脚
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_afpin_0_7(GPIO_t *gpiox, uint32_t pin, uint32_t alternate)
{
    MODIFY_REG(gpiox->AFL, ((((pin * pin) * pin) * pin) * GPIO_AF_SELECT_OFFSET),
               ((((pin * pin) * pin) * pin) * alternate)); 
}

/**
* @brief  读取GPIO引脚（0~7）复用功能
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_7
* @note   仅支持单个引脚
* @retval uint32_t GPIO引脚（0~7）复用功能
*             @arg GPIO_AF0_MCO
*             @arg GPIO_AF0_SWD
*             @arg ...
*             @arg GPIO_AF1_IROUT
*             @arg GPIO_AF1_SPI2
*             @arg ...
*             @arg GPIO_AF2_IROUT
*             @arg GPIO_AF2_COMP2
*             @arg ...
*             @arg GPIO_AF3_LCD
*             @arg GPIO_AF4_SPI2
*             @arg GPIO_AF4_TIM3
*             @arg ...
*             @arg GPIO_AF5_IROUT
*             @arg GPIO_AF5_MCO
*             @arg ...
*             @arg GPIO_AF6_LPTIM1
*             @arg GPIO_AF6_TIM4
*             @arg ...
*             @arg GPIO_AF7_IROUT
*             @arg ...
*             @arg GPIO_AF7_COMP2
*/
__STATIC_INLINE uint32_t std_gpio_get_afpin_0_7(GPIO_t *gpiox, uint32_t pin)
{
    return ((gpiox->AFL & ((((pin * pin) * pin) * pin) * GPIO_AF_SELECT_OFFSET)) / 
            (((pin * pin) * pin) * pin));
}

/**
* @brief  设置GPIO引脚（8~15）复用功能
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_8
*             @arg GPIO_PIN_9
*             @arg ...
*             @arg GPIO_PIN_15
* @param  alternate GPIO引脚（8~15）复用功能
*             @arg GPIO_AF0_MCO
*             @arg GPIO_AF0_SWD
*             @arg ...
*             @arg GPIO_AF1_IROUT
*             @arg GPIO_AF1_SPI2
*             @arg ...
*             @arg GPIO_AF2_IROUT
*             @arg GPIO_AF2_COMP2
*             @arg ...
*             @arg GPIO_AF3_LCD
*             @arg GPIO_AF4_SPI2
*             @arg GPIO_AF4_TIM3
*             @arg ...
*             @arg GPIO_AF5_IROUT
*             @arg GPIO_AF5_MCO
*             @arg ...
*             @arg GPIO_AF6_LPTIM1
*             @arg GPIO_AF6_TIM4
*             @arg ...
*             @arg GPIO_AF7_IROUT
*             @arg ...
*             @arg GPIO_AF7_COMP2
* @note   仅支持单个引脚
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_afpin_8_15(GPIO_t *gpiox, uint32_t pin, uint32_t alternate)
{
    MODIFY_REG(gpiox->AFH,  (((((pin >> 8U) * (pin >> 8U)) * (pin >> 8U)) * (pin >> 8U)) * GPIO_AF_SELECT_OFFSET),
             (((((pin >> 8U) * (pin >> 8U)) * (pin >> 8U)) * (pin >> 8U)) * alternate)); 
}

/**
* @brief  读取GPIO引脚（8~15）复用功能
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_8
*             @arg GPIO_PIN_9
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval uint32_t GPIO引脚（8~15）复用功能
*             @arg GPIO_AF0_MCO
*             @arg GPIO_AF0_SWD
*             @arg ...
*             @arg GPIO_AF1_IROUT
*             @arg GPIO_AF1_SPI2
*             @arg ...
*             @arg GPIO_AF2_IROUT
*             @arg GPIO_AF2_COMP2
*             @arg ...
*             @arg GPIO_AF3_LCD
*             @arg GPIO_AF4_SPI2
*             @arg GPIO_AF4_TIM3
*             @arg ...
*             @arg GPIO_AF5_IROUT
*             @arg GPIO_AF5_MCO
*             @arg ...
*             @arg GPIO_AF6_LPTIM1
*             @arg GPIO_AF6_TIM4
*             @arg ...
*             @arg GPIO_AF7_IROUT
*             @arg ...
*             @arg GPIO_AF7_COMP2
*/
__STATIC_INLINE uint32_t std_gpio_get_afpin_8_15(GPIO_t *gpiox, uint32_t pin)
{
    return ((gpiox->AFH & (((((pin >> 8U) * (pin >> 8U)) * (pin >> 8U)) * (pin >> 8U)) * GPIO_AF_SELECT_OFFSET)) / 
            ((((pin >> 8U) * (pin >> 8U)) * (pin >> 8U)) * (pin >> 8U)));
}

/**
* @brief  读取GPIO引脚输入状态
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin  GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval bool GPIO引脚输入状态
*             @arg true  表示高电平
*             @arg false 表示低电平
*/
__STATIC_INLINE bool std_gpio_get_input_pin(GPIO_t* gpiox, uint32_t pin)
{
    return ((gpiox->IDR & (pin)) == (pin));
}

/**
* @brief  读取GPIO引脚输出状态
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin GPIO引脚
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @note   仅支持单个引脚
* @retval bool GPIO引脚输出状态
*             @arg true  表示高电平
*             @arg false 表示低电平
*/
__STATIC_INLINE bool std_gpio_get_output_pin(GPIO_t* gpiox, uint32_t pin)
{
    return ((gpiox->ODR & (pin)) == (pin));
}

/**
* @brief  读取GPIO端口输入数据
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @retval uint32_t GPIO端口输入数据
*/
__STATIC_INLINE uint32_t std_gpio_read_input_port(GPIO_t* gpiox)
{
    return (gpiox->IDR);
}

/**
* @brief  读取GPIO端口输出数据
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @retval uint32_t GPIO端口输出数据
*/
__STATIC_INLINE uint32_t std_gpio_read_output_port(GPIO_t* gpiox)
{
    return (gpiox->ODR);
}

/**
* @brief  写入GPIO端口输出数据
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  value 输出数据
* @retval 无
*/
__STATIC_INLINE void std_gpio_write_output_port(GPIO_t* gpiox, uint32_t value)
{
    gpiox->ODR = value;
}

/**
* @brief  设置GPIO输出高电平
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin_mask GPIO引脚组合
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_pin(GPIO_t* gpiox, uint32_t pin_mask)
{
    gpiox->BSR = pin_mask;
}

/**
* @brief  设置GPIO输出低电平
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin_mask  GPIO引脚组合
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @retval 无
*/
__STATIC_INLINE void std_gpio_reset_pin(GPIO_t* gpiox, uint32_t pin_mask)
{
    gpiox->BR = pin_mask;
}

/**
* @brief  切换GPIO端口高/低电平
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOB
*             @arg ...
* @param  pin_mask  GPIO引脚组合
*             @arg GPIO_PIN_0
*             @arg GPIO_PIN_1
*             @arg ...
*             @arg GPIO_PIN_15
* @retval 无
*/
__STATIC_INLINE void std_gpio_toggle_pin(GPIO_t* gpiox, uint32_t pin_mask)
{
    gpiox->ODR ^= pin_mask;
}

/**
* @brief  使能GPIO引脚高驱能力
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOD
* @param  pin_mask  GPIO引脚组合
*             @arg GPIO_PIN_2
* @retval 无
*/
__STATIC_INLINE void std_gpio_set_highdrive_pin(GPIO_t* gpiox, uint32_t pin_mask)
{
    gpiox->HDCFG |= (pin_mask);
}

/**
* @brief  清除GPIO引脚高驱能力
* @param  gpiox GPIO外设
*             @arg GPIOA
*             @arg GPIOD
* @param  pin_mask  GPIO引脚组合
*             @arg GPIO_PIN_2
* @retval 无
*/
__STATIC_INLINE void std_gpio_reset_highdrive_pin(GPIO_t* gpiox, uint32_t pin_mask)
{
    gpiox->HDCFG &= (~(pin_mask));
}

void std_gpio_init(GPIO_t* gpiox, std_gpio_init_t* gpio_init_param);
void std_gpio_deinit(GPIO_t* gpiox, uint32_t pin_mask);
void std_gpio_struct_init(std_gpio_init_t* gpio_init_struct);

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

#endif /* CIU32L051_STD_GPIO_H */


