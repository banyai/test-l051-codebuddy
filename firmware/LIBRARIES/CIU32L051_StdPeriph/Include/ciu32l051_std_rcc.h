/************************************************************************************************/
/**
* @file               ciu32l051_std_rcc.h
* @author             MCU Ecosystem Development Team
* @brief              RCC STD库驱动头文件。
*                     提供RCC相关的STD库操作函数声明、数据类型以及常量的定义。                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_RCC_H
#define CIU32L051_STD_RCC_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup RCC RCC
* @brief 复位和时钟控制器的STD库驱动
* @{
*/
/************************************************************************************************/


#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"


/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup RCC_Constants RCC Constants 
* @brief  RCC常量定义及宏定义
* @{
*
*/
/************************************************************************************************/
/* HXTAL配置参数定义 */
#define RCC_HXTAL_ON                   (0x00000001UL)                      /**< HXTAL时钟开启        */
#define RCC_HXTAL_BYPASS               (0x00000002UL)                      /**< HXTAL为外部时钟模式  */ 

/* LXTAL配置参数定义 */
#define RCC_LXTAL_ON                   (0x00000001UL)                      /**< LXTAL时钟开启        */
                                                
/* RCH分频系数参数定义 */
#define RCC_RCH_DIV1                   RCC_CSR1_RCHDIV_1                   /**< RCH时钟不分频         */
#define RCC_RCH_DIV2                   RCC_CSR1_RCHDIV_2                   /**< RCH时钟分频因子 = 2   */
#define RCC_RCH_DIV4                   RCC_CSR1_RCHDIV_4                   /**< RCH时钟分频因子 = 4   */
#define RCC_RCH_DIV8                   RCC_CSR1_RCHDIV_8                   /**< RCH时钟分频因子 = 8   */                                                                                

/* HXTAL驱动能力参数定义 */
#define RCC_HXTAL_DRIVE_LEVEL0         RCC_CSR1_HXTAL_DRV_0                /**< 低档驱动能力               */ 
#define RCC_HXTAL_DRIVE_LEVEL1         RCC_CSR1_HXTAL_DRV_1                /**< 中低档驱动能力             */ 
#define RCC_HXTAL_DRIVE_LEVEL2         RCC_CSR1_HXTAL_DRV_2                /**< 中高档驱动能力             */ 
#define RCC_HXTAL_DRIVE_LEVEL3         RCC_CSR1_HXTAL_DRV_3                /**< 高档驱动能力               */ 

/* HXTAL时钟稳定周期数定义 */
#define RCC_HXTAL_STAB_SEL_256         (0x00000000UL)                               /**< HXTAL时钟稳定周期为256个时钟周期    */
#define RCC_HXTAL_STAB_SEL_1024        (0x1UL << RCC_STABC_HXTAL_STAB_SEL_POS)      /**< HXTAL时钟稳定周期为1024个时钟周期   */
#define RCC_HXTAL_STAB_SEL_4096        (0x2UL << RCC_STABC_HXTAL_STAB_SEL_POS)      /**< HXTAL时钟稳定周期为4096个时钟周期   */
#define RCC_HXTAL_STAB_SEL_16384       (0x3UL << RCC_STABC_HXTAL_STAB_SEL_POS)      /**< HXTAL时钟稳定周期为16384个时钟周期  */

                                                                                    
/* PLL VCO分频参数定义 */                                                           
#define RCC_PLL_DIV1                   RCC_PLLCFG_PLLDIV_1                          /**< PLL分频因子 = 1     */
#define RCC_PLL_DIV2                   RCC_PLLCFG_PLLDIV_2                          /**< PLL分频因子 = 2     */
#define RCC_PLL_DIV4                   RCC_PLLCFG_PLLDIV_4                          /**< PLL分频因子 = 4     */
#define RCC_PLL_DIV8                   RCC_PLLCFG_PLLDIV_8                          /**< PLL分频因子 = 8     */

/* PLLM倍频参数定义 */
#define RCC_PLLM_MUL1                  (0x01UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 1    */
#define RCC_PLLM_MUL2                  (0x02UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 2    */
#define RCC_PLLM_MUL3                  (0x03UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 3    */
#define RCC_PLLM_MUL4                  (0x04UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 4    */
#define RCC_PLLM_MUL5                  (0x05UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 5    */
#define RCC_PLLM_MUL6                  (0x06UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 6    */
#define RCC_PLLM_MUL7                  (0x07UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 7    */
#define RCC_PLLM_MUL8                  (0x08UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 8    */
#define RCC_PLLM_MUL9                  (0x09UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 9    */
#define RCC_PLLM_MUL10                 (0x0AUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 10   */
#define RCC_PLLM_MUL11                 (0x0BUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 11   */
#define RCC_PLLM_MUL12                 (0x0CUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 12   */
#define RCC_PLLM_MUL13                 (0x0DUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 13   */
#define RCC_PLLM_MUL14                 (0x0EUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 14   */
#define RCC_PLLM_MUL15                 (0x0FUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 15   */
#define RCC_PLLM_MUL16                 (0x10UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 16   */
#define RCC_PLLM_MUL17                 (0x11UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 17   */
#define RCC_PLLM_MUL18                 (0x12UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 18   */
#define RCC_PLLM_MUL19                 (0x13UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 19   */
#define RCC_PLLM_MUL20                 (0x14UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 20   */
#define RCC_PLLM_MUL21                 (0x15UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 21   */
#define RCC_PLLM_MUL22                 (0x16UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 22   */
#define RCC_PLLM_MUL23                 (0x17UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 23   */
#define RCC_PLLM_MUL24                 (0x18UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 24   */
#define RCC_PLLM_MUL25                 (0x19UL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 25   */
#define RCC_PLLM_MUL26                 (0x1AUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 26   */
#define RCC_PLLM_MUL27                 (0x1BUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 27   */
#define RCC_PLLM_MUL28                 (0x1CUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 28   */
#define RCC_PLLM_MUL29                 (0x1DUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 29   */
#define RCC_PLLM_MUL30                 (0x1EUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 30   */
#define RCC_PLLM_MUL31                 (0x1FUL << RCC_PLLCFG_PLLM_POS)              /**< PLLM倍频因子 = 31   */
#define RCC_PLLM_MUL32                 (0x00000000UL)                               /**< PLLM倍频因子 = 32   */


/* PLLN分频参数定义 */
#define RCC_PLLN_DIV1                  (0x1UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 1  */
#define RCC_PLLN_DIV2                  (0x2UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 2  */
#define RCC_PLLN_DIV3                  (0x3UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 3  */
#define RCC_PLLN_DIV4                  (0x4UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 4  */
#define RCC_PLLN_DIV5                  (0x5UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 5  */
#define RCC_PLLN_DIV6                  (0x6UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 6  */
#define RCC_PLLN_DIV7                  (0x7UL << RCC_PLLCFG_PLLN_POS)               /**< PLLN分频因子 = 7  */
#define RCC_PLLN_DIV8                  (0x00000000UL)                               /**< PLLN分频因子 = 8  */


/* PLL时钟源定义 */
#define RCC_PLLSRC_RCH                 RCC_PLLCFG_PLLSRC_RCH                        /**< RCH时钟作为PLL的时钟源    */
#define RCC_PLLSRC_HXTAL               RCC_PLLCFG_PLLSRC_HXTAL                      /**< HXTAL作为PLL的时钟源      */

/* 系统时钟源选择 */
#define RCC_SYSCLK_SRC_RCHSYS          RCC_CFG_SYSW_RCHSYS                          /**< 选择RCHSYS作为系统时钟源  */
#define RCC_SYSCLK_SRC_HXTAL           RCC_CFG_SYSW_HXTAL                           /**< 选择HXTAL作为系统时钟源   */
#define RCC_SYSCLK_SRC_PLLCLK          RCC_CFG_SYSW_PLL                             /**< 选择PLL作为系统时钟源     */
#define RCC_SYSCLK_SRC_RCL             RCC_CFG_SYSW_RCL                             /**< 选择RCL作为系统时钟源     */
#define RCC_SYSCLK_SRC_LXTAL           RCC_CFG_SYSW_LXTAL                           /**< 选择LXTAL作为系统时钟源   */

/* 系统时钟源状态定义 */
#define RCC_SYSCLK_SRC_STATUS_RCHSYS       RCC_CFG_SYSWS_RCHSYS                     /**< 系统时钟为RCHSYS   */
#define RCC_SYSCLK_SRC_STATUS_HXTAL        RCC_CFG_SYSWS_HXTAL                      /**< 系统时钟为HXTAL    */
#define RCC_SYSCLK_SRC_STATUS_PLLCLK       RCC_CFG_SYSWS_PLL                        /**< 系统时钟为PLL      */
#define RCC_SYSCLK_SRC_STATUS_RCL          RCC_CFG_SYSWS_RCL                        /**< 系统时钟为RCL      */
#define RCC_SYSCLK_SRC_STATUS_LXTAL        RCC_CFG_SYSWS_LXTAL                      /**< 系统时钟为LXTAL    */

/* AHB时钟分频参数定义 */
#define RCC_HCLK_DIV1                      RCC_CFG_HPRE_1                           /**< HCLK不分频         */
#define RCC_HCLK_DIV2                      RCC_CFG_HPRE_2                           /**< HCLK分频因子 = 2   */
#define RCC_HCLK_DIV4                      RCC_CFG_HPRE_4                           /**< HCLK分频因子 = 4   */
#define RCC_HCLK_DIV8                      RCC_CFG_HPRE_8                           /**< HCLK分频因子 = 8   */
#define RCC_HCLK_DIV16                     RCC_CFG_HPRE_16                          /**< HCLK分频因子 = 16  */
#define RCC_HCLK_DIV32                     RCC_CFG_HPRE_32                          /**< HCLK分频因子 = 32  */
#define RCC_HCLK_DIV64                     RCC_CFG_HPRE_64                          /**< HCLK分频因子 = 64  */
#define RCC_HCLK_DIV128                    RCC_CFG_HPRE_128                         /**< HCLK分频因子 = 128 */

/* APB1时钟分频参数定义 */
#define RCC_PCLK1_DIV1                     RCC_CFG_P1PRE_1                           /**< APB1总线时钟不分频        */
#define RCC_PCLK1_DIV2                     RCC_CFG_P1PRE_2                           /**< APB1总线时钟分频因子 = 2  */
#define RCC_PCLK1_DIV4                     RCC_CFG_P1PRE_4                           /**< APB1总线时钟分频因子 = 4  */
#define RCC_PCLK1_DIV8                     RCC_CFG_P1PRE_8                           /**< APB1总线时钟分频因子 = 8  */
#define RCC_PCLK1_DIV16                    RCC_CFG_P1PRE_16                          /**< APB1总线时钟分频因子 = 16 */
                                                                                                          
/* APB2时钟分频参数定义 */                                                                          
#define RCC_PCLK2_DIV1                     RCC_CFG_P2PRE_1                          /**< APB2总线时钟不分频        */
#define RCC_PCLK2_DIV2                     RCC_CFG_P2PRE_2                          /**< APB2总线时钟分频因子 = 2  */
#define RCC_PCLK2_DIV4                     RCC_CFG_P2PRE_4                          /**< APB2总线时钟分频因子 = 4  */
#define RCC_PCLK2_DIV8                     RCC_CFG_P2PRE_8                          /**< APB2总线时钟分频因子 = 8  */
#define RCC_PCLK2_DIV16                    RCC_CFG_P2PRE_16                         /**< APB2总线时钟分频因子 = 16 */
              
/* MCO时钟源参数定义 */                                                                            
#define RCC_MCO_SRC_DISABLE                RCC_CFG_MCOSEL_DISABLE                   /**< MCO输出无效       */
#define RCC_MCO_SRC_SYSCLK                 RCC_CFG_MCOSEL_SYSCLK                    /**< MCO选择SYSCLK输出 */
#define RCC_MCO_SRC_RCH                    RCC_CFG_MCOSEL_RCH                       /**< MCO选择RCH输出    */
#define RCC_MCO_SRC_HXTAL                  RCC_CFG_MCOSEL_HXTAL                     /**< MCO选择HXTAL输出  */
#define RCC_MCO_SRC_PLLCLK                 RCC_CFG_MCOSEL_PLLCLK                    /**< MCO选择PLLCLK输出 */
#define RCC_MCO_SRC_RCL                    RCC_CFG_MCOSEL_RCL                       /**< MCO选择RCL输出    */
#define RCC_MCO_SRC_LXTAL                  RCC_CFG_MCOSEL_LXTAL                     /**< MCO选择LXTAL输出  */

/* MCO时钟分频参数定义 */
#define RCC_MCO_DIV1                       RCC_CFG_MCOPRE_DIV1                      /**< MCO分频因子 = 1   */
#define RCC_MCO_DIV2                       RCC_CFG_MCOPRE_DIV2                      /**< MCO分频因子 = 2   */
#define RCC_MCO_DIV4                       RCC_CFG_MCOPRE_DIV4                      /**< MCO分频因子 = 4   */
#define RCC_MCO_DIV8                       RCC_CFG_MCOPRE_DIV8                      /**< MCO分频因子 = 8   */
#define RCC_MCO_DIV16                      RCC_CFG_MCOPRE_DIV16                     /**< MCO分频因子 = 16  */
#define RCC_MCO_DIV32                      RCC_CFG_MCOPRE_DIV32                     /**< MCO分频因子 = 32  */
#define RCC_MCO_DIV64                      RCC_CFG_MCOPRE_DIV64                     /**< MCO分频因子 = 64  */
#define RCC_MCO_DIV128                     RCC_CFG_MCOPRE_DIV128                    /**< MCO分频因子 = 128 */

/* RCC中断控制位定义 */
#define RCC_INTERRUPT_RCL_READY            RCC_IER_RCL_RDYIE                        /**< RCL Ready的中断控制位   */
#define RCC_INTERRUPT_LXTAL_READY          RCC_IER_LXTAL_RDYIE                      /**< LXTAL Ready的中断控制位 */
#define RCC_INTERRUPT_RCH_READY            RCC_IER_RCH_RDYIE                        /**< RCH Ready的中断控制位   */
#define RCC_INTERRUPT_HXTAL_READY          RCC_IER_HXTAL_RDYIE                      /**< HXTAL Ready的中断控制位 */
#define RCC_INTERRUPT_PLL_READY            RCC_IER_PLL_RDYIE                        /**< PLL Ready的中断控制位   */


/* RCC中断标志位定义 */
#define RCC_FLAG_RCL_READY                 RCC_ISR_RCL_RDYF                         /**< RCL Ready的中断标志位   */
#define RCC_FLAG_LXTAL_READY               RCC_ISR_LXTAL_RDYF                       /**< LXTAL Ready的中断标志位 */
#define RCC_FLAG_RCH_READY                 RCC_ISR_RCH_RDYF                         /**< RCH Ready的中断标志位   */
#define RCC_FLAG_HXTAL_READY               RCC_ISR_HXTAL_RDYF                       /**< HXTAL Ready的中断标志位 */
#define RCC_FLAG_PLL_READY                 RCC_ISR_PLL_RDYF                         /**< PLL Ready的中断标志位   */
#define RCC_FLAG_HXTALCSS                  RCC_ISR_HXTAL_CSSF                       /**< HXTAL CSS的中断标志位   */


/* RCC清除控制位定义 */
#define RCC_CLEAR_RCL_READY                RCC_ICR_RCL_RDYC                         /**< RCL Ready的清除控制位   */
#define RCC_CLEAR_LXTAL_READY              RCC_ICR_LXTAL_RDYC                       /**< LXTAL Ready的清除控制位 */
#define RCC_CLEAR_RCH_READY                RCC_ICR_RCH_RDYC                         /**< RCH Ready的清除控制位   */
#define RCC_CLEAR_HXTAL_READY              RCC_ICR_HXTAL_RDYC                       /**< HXTAL Ready的清除控制位 */
#define RCC_CLEAR_PLL_READY                RCC_ICR_PLL_RDYC                         /**< PLL Ready的清除控制位   */
#define RCC_CLEAR_HXTALCSS                 RCC_ICR_HXTAL_CSSC                       /**< HXTAL CSS的清除控制位   */

/* LXTAL驱动模式参数定义 */
#define RCC_LXTAL_DRIVE_MODE_NORMAL       (0x00000000UL)                            /**< LXTAL驱动能力为普通型   */
#define RCC_LXTAL_DRIVE_MODE_ENHANCE      (0x1UL << RCC_AWCR_LXTAL_DRV_MODE_POS)    /**< LXTAL驱动能力为增强型   */

/* LXTAL驱动参数配置定义 */
#define RCC_LXTAL_DRIVE_LEVEL0            RCC_AWCR_LXTAL_DRV_0                     /**< LXTAL低驱动能力   */
#define RCC_LXTAL_DRIVE_LEVEL1            RCC_AWCR_LXTAL_DRV_1                     /**< LXTAL中低驱动能力 */
#define RCC_LXTAL_DRIVE_LEVEL2            RCC_AWCR_LXTAL_DRV_2                     /**< LXTAL中高驱动能力 */
#define RCC_LXTAL_DRIVE_LEVEL3            RCC_AWCR_LXTAL_DRV_3                     /**< LXTAL高驱动能力   */

/* LXTAL时钟稳定周期数定义 */
#define RCC_LXTAL_STAB_SEL_256           (0x00000000UL)                            /**< LXTAL时钟稳定周期为256个时钟周期    */
#define RCC_LXTAL_STAB_SEL_1024          (0x1UL << RCC_AWCR_LXTAL_STAB_SEL_POS)    /**< LXTAL时钟稳定周期为1024个时钟周期   */
#define RCC_LXTAL_STAB_SEL_4096          (0x2UL << RCC_AWCR_LXTAL_STAB_SEL_POS)    /**< LXTAL时钟稳定周期为4096个时钟周期   */
#define RCC_LXTAL_STAB_SEL_16384         (0x3UL << RCC_AWCR_LXTAL_STAB_SEL_POS)    /**< LXTAL时钟稳定周期为16384个时钟周期  */

/* IO端口时钟选择 */
#define RCC_PERIPH_CLK_GPIOA              RCC_IOPEN_GPIOAEN                        /**< GPIOA 时钟控制位  */
#define RCC_PERIPH_CLK_GPIOB              RCC_IOPEN_GPIOBEN                        /**< GPIOB 时钟控制位  */
#define RCC_PERIPH_CLK_GPIOC              RCC_IOPEN_GPIOCEN                        /**< GPIOC 时钟控制位  */
#define RCC_PERIPH_CLK_GPIOD              RCC_IOPEN_GPIODEN                        /**< GPIOD 时钟控制位  */
#define RCC_PERIPH_CLK_GPIOF              RCC_IOPEN_GPIOFEN                        /**< GPIOF 时钟控制位  */

/* IO端口复位选择 */
#define RCC_PERIPH_RESET_GPIO_ALL         RCC_IOPRST_GPIOA_RST | RCC_IOPRST_GPIOB_RST  \
                                                               | RCC_IOPRST_GPIOC_RST  \
                                                               | RCC_IOPRST_GPIOD_RST  \
                                                               | RCC_IOPRST_GPIOF_RST     /**< GPIO所有端口复位控制位 */
                                                               
#define RCC_PERIPH_RESET_GPIOA            RCC_IOPRST_GPIOA_RST                            /**< GPIOA端口复位控制位    */
#define RCC_PERIPH_RESET_GPIOB            RCC_IOPRST_GPIOB_RST                            /**< GPIOB端口复位控制位    */
#define RCC_PERIPH_RESET_GPIOC            RCC_IOPRST_GPIOC_RST                            /**< GPIOC端口复位控制位    */
#define RCC_PERIPH_RESET_GPIOD            RCC_IOPRST_GPIOD_RST                            /**< GPIOD端口复位控制位    */
#define RCC_PERIPH_RESET_GPIOF            RCC_IOPRST_GPIOF_RST                            /**< GPIOF端口复位控制位    */

/* AHB外设时钟选择 */
#define RCC_PERIPH_CLK_DMA                RCC_AHBEN_DMAEN                                 /**< AHB外设DMA时钟控制位   */
#define RCC_PERIPH_CLK_FLASH              RCC_AHBEN_FLASHEN                               /**< AHB外设Flash时钟控制位 */
#define RCC_PERIPH_CLK_CRC                RCC_AHBEN_CRCEN                                 /**< AHB外设CRC时钟控制位   */
#define RCC_PERIPH_CLK_AES                RCC_AHBEN_AESEN                                 /**< AHB外设AES时钟控制位   */

/* AHB外设复位选择 */
#define RCC_PERIPH_RESET_AHB              RCC_AHBRST_DMA_RST | RCC_AHBRST_CRC_RST   \
                                                             | RCC_AHBRST_AES_RST         /**< AHB所有外设复位控制位  */
                                                                                                                      
#define RCC_PERIPH_RESET_DMA              RCC_AHBRST_DMA_RST                              /**< AHB外设DMA复位控制位   */
#define RCC_PERIPH_RESET_CRC              RCC_AHBRST_CRC_RST                              /**< AHB外设CRC复位控制位   */
#define RCC_PERIPH_RESET_AES              RCC_AHBRST_AES_RST                              /**< AHB外设AES复位控制位   */

/* APB1外设时钟选择 */
#define RCC_PERIPH_CLK_TIM3               RCC_APB1EN_TIM3EN                               /**< APB1外设TIM3时钟控制位    */
#define RCC_PERIPH_CLK_TIM4               RCC_APB1EN_TIM4EN                               /**< APB1外设TIM4时钟控制位    */
#define RCC_PERIPH_CLK_TIM5               RCC_APB1EN_TIM5EN                               /**< APB1外设TIM5时钟控制位    */
#define RCC_PERIPH_CLK_TIM8               RCC_APB1EN_TIM8EN                               /**< APB1外设TIM8时钟控制位    */
#define RCC_PERIPH_CLK_LCD                RCC_APB1EN_LCDEN                                /**< APB1外设LCD时钟控制位     */
#define RCC_PERIPH_CLK_RTC                RCC_APB1EN_RTCAPBEN                             /**< APB1外设RTC时钟控制位     */
#define RCC_PERIPH_CLK_WWDG               RCC_APB1EN_WWDGEN                               /**< APB1外设WWDGSH时钟控制位  */
#define RCC_PERIPH_CLK_SPI2               RCC_APB1EN_SPI2EN                               /**< APB1外设SPI2时钟控制位    */
#define RCC_PERIPH_CLK_UART2              RCC_APB1EN_UART2EN                              /**< APB1外设UART2时钟控制位   */
#define RCC_PERIPH_CLK_UART3              RCC_APB1EN_UART3EN                              /**< APB1外设UART3时钟控制位   */
#define RCC_PERIPH_CLK_UART4              RCC_APB1EN_UART4EN                              /**< APB1外设UART4时钟控制位   */
#define RCC_PERIPH_CLK_LPUART1            RCC_APB1EN_LPUART1EN                            /**< APB1外设LPUART1时钟控制位 */
#define RCC_PERIPH_CLK_LPUART2            RCC_APB1EN_LPUART2EN                            /**< APB1外设LPUART2时钟控制位 */
#define RCC_PERIPH_CLK_I2C1               RCC_APB1EN_I2C1EN                               /**< APB1外设I2C1时钟控制位    */
#define RCC_PERIPH_CLK_PMU                RCC_APB1EN_PMUEN                                /**< APB1外设PMU时钟控制位     */
#define RCC_PERIPH_CLK_LPTIM1             RCC_APB1EN_LPTIM1EN                             /**< APB1外设LPTIM1时钟控制位  */
#define RCC_PERIPH_CLK_LPTIM2             RCC_APB1EN_LPTIM2EN                             /**< APB1外设LPTIM2时钟控制位  */

/* APB1外设复位选择 */
#define RCC_PERIPH_RESET_APB1             RCC_APB1RST_TIM3_RST | RCC_APB1RST_TIM4_RST     \
                                                               | RCC_APB1RST_TIM5_RST     \
                                                               | RCC_APB1RST_TIM8_RST     \
                                                               | RCC_APB1RST_LCD_RST      \
                                                               | RCC_APB1RST_SPI2_RST     \
                                                               | RCC_APB1RST_UART2_RST    \
                                                               | RCC_APB1RST_UART3_RST    \
                                                               | RCC_APB1RST_UART4_RST    \
                                                               | RCC_APB1RST_LPUART1_RST  \
                                                               | RCC_APB1RST_LPUART2_RST  \
                                                               | RCC_APB1RST_I2C1_RST     \
                                                               | RCC_APB1RST_LPTIM1_RST   \
                                                               | RCC_APB1RST_LPTIM2_RST      /**< APB1所有外设复位控制位     */

#define RCC_PERIPH_RESET_TIM3             RCC_APB1RST_TIM3_RST                               /**< APB1外设TIM3复位控制位     */
#define RCC_PERIPH_RESET_TIM4             RCC_APB1RST_TIM4_RST                               /**< APB1外设TIM4复位控制位     */
#define RCC_PERIPH_RESET_TIM5             RCC_APB1RST_TIM5_RST                               /**< APB1外设TIM5复位控制位     */
#define RCC_PERIPH_RESET_TIM8             RCC_APB1RST_TIM8_RST                               /**< APB1外设TIM8复位控制位     */

#define RCC_PERIPH_RESET_LCD              RCC_APB1RST_LCD_RST                                /**< APB1外设LCD复位控制位      */
#define RCC_PERIPH_RESET_SPI2             RCC_APB1RST_SPI2_RST                               /**< APB1外设SPI2时复位制位     */
#define RCC_PERIPH_RESET_UART2            RCC_APB1RST_UART2_RST                              /**< APB1外设UART2复位控制位    */
#define RCC_PERIPH_RESET_UART3            RCC_APB1RST_UART3_RST                              /**< APB1外设UART3复位控制位    */
#define RCC_PERIPH_RESET_UART4            RCC_APB1RST_UART4_RST                              /**< APB1外设UART4复位控制位    */
#define RCC_PERIPH_RESET_LPUART1          RCC_APB1RST_LPUART1_RST                            /**< APB1外设LPUART1复位控制位  */
#define RCC_PERIPH_RESET_LPUART2          RCC_APB1RST_LPUART2_RST                            /**< APB1外设LPUART2复位控制位  */
#define RCC_PERIPH_RESET_I2C1             RCC_APB1RST_I2C1_RST                               /**< APB1外设I2C1复位控制位     */
#define RCC_PERIPH_RESET_LPTIM1           RCC_APB1RST_LPTIM1_RST                             /**< APB1外设LPTIM1复位控制位   */
#define RCC_PERIPH_RESET_LPTIM2           RCC_APB1RST_LPTIM2_RST                             /**< APB1外设LPTIM2复位控制位   */
                                                                                                 
/* APB2外设时钟选择 */                                                                           
#define RCC_PERIPH_CLK_SYSCFG             RCC_APB2EN_SYSCFGEN                                /**< APB2外设SYSCFG时钟控制位   */
#define RCC_PERIPH_CLK_TRNG               RCC_APB2EN_TRNGEN                                  /**< APB2外设TRNG时钟控制位     */
#define RCC_PERIPH_CLK_SPI1               RCC_APB2EN_SPI1EN                                  /**< APB2外设SPI1时钟控制位     */
#define RCC_PERIPH_CLK_USART1             RCC_APB2EN_USART1EN                                /**< APB2外设USART1时钟控制位   */
#define RCC_PERIPH_CLK_ADC                RCC_APB2EN_ADCEN                                   /**< APB2外设ADC时钟控制位      */
#define RCC_PERIPH_CLK_DBG                RCC_APB2EN_DBGEN                                   /**< APB2外设DBG时钟控制位      */

/* APB2外设复位选择 */
#define RCC_PERIPH_RESET_APB2             RCC_APB2RST_SYSCFG_RST | RCC_APB2RST_TRNG_RST     \
                                                                 | RCC_APB2RST_SPI1_RST     \
                                                                 | RCC_APB2RST_USART1_RST   \
                                                                 | RCC_APB2RST_ADC_RST      \
                                                                 | RCC_APB2RST_DBG_RST       /**< APB2所有外设复位控制位    */
                                                                 
#define RCC_PERIPH_RESET_SYSCFG             RCC_APB2RST_SYSCFG_RST                           /**< APB2外设SYSCFG复位控制位  */
#define RCC_PERIPH_RESET_TRNG               RCC_APB2RST_TRNG_RST                             /**< APB2外设TRNG时复位制位    */
#define RCC_PERIPH_RESET_SPI1               RCC_APB2RST_SPI1_RST                             /**< APB2外设SPI1复位控制位    */
#define RCC_PERIPH_RESET_USART1             RCC_APB2RST_USART1_RST                           /**< APB2外设USART复位控制位   */
#define RCC_PERIPH_RESET_ADC                RCC_APB2RST_ADC_RST                              /**< APB2外设ADC复位控制位     */
#define RCC_PERIPH_RESET_DBG                RCC_APB2RST_DBG_RST                              /**< APB2外设DBG复位控制位     */

/* LPUART1异步时钟源选择 */ 
#define RCC_LPUART1_ASYNC_CLK_SRC_PCLK1         RCC_CLKSEL_LPUART1_SEL_PCLK           /**< APB时钟作为LPUART1的时钟       */
#define RCC_LPUART1_ASYNC_CLK_SRC_SYSCLK        RCC_CLKSEL_LPUART1_SEL_SYSCLK         /**< 系统时钟作为LPUART1的时钟      */
#define RCC_LPUART1_ASYNC_CLK_SRC_RCH           RCC_CLKSEL_LPUART1_SEL_RCH            /**< RCH时钟作为LPUART1的时钟       */
#define RCC_LPUART1_ASYNC_CLK_SRC_LXTAL         RCC_CLKSEL_LPUART1_SEL_LXTAL          /**< LXTAL时钟作为LPUART1的时钟     */

/* LPUART2异步时钟源选择 */ 
#define RCC_LPUART2_ASYNC_CLK_SRC_PCLK1         RCC_CLKSEL_LPUART2_SEL_PCLK           /**< APB时钟作为LPUART2的时钟       */
#define RCC_LPUART2_ASYNC_CLK_SRC_SYSCLK        RCC_CLKSEL_LPUART2_SEL_SYSCLK         /**< 系统时钟作为LPUART2的时钟      */
#define RCC_LPUART2_ASYNC_CLK_SRC_RCH           RCC_CLKSEL_LPUART2_SEL_RCH            /**< RCH时钟作为LPUART2的时钟       */
#define RCC_LPUART2_ASYNC_CLK_SRC_LXTAL         RCC_CLKSEL_LPUART2_SEL_LXTAL          /**< LXTAL时钟作为LPUART2的时钟     */

/* LPTIM1异步时钟源选择 */
#define RCC_LPTIM1_ASYNC_CLK_SRC_PCLK1          RCC_CLKSEL_LPTIM1_SEL_PCLK             /**< APB1时钟作为LPTIM1的时钟     */
#define RCC_LPTIM1_ASYNC_CLK_SRC_RCL            RCC_CLKSEL_LPTIM1_SEL_RCL              /**< RCL作为LPTIM1的时钟          */  
#define RCC_LPTIM1_ASYNC_CLK_SRC_RCH            RCC_CLKSEL_LPTIM1_SEL_RCH              /**< RCH时钟作为LPTIM1的时钟      */
#define RCC_LPTIM1_ASYNC_CLK_SRC_LXTAL          RCC_CLKSEL_LPTIM1_SEL_LXTAL            /**< LXTAL时钟作为LPTIM1的时钟    */

/* LPTIM2异步时钟源选择 */
#define RCC_LPTIM2_ASYNC_CLK_SRC_PCLK1          RCC_CLKSEL_LPTIM2_SEL_PCLK             /**< APB1时钟作为LPTIM2的时钟     */
#define RCC_LPTIM2_ASYNC_CLK_SRC_RCL            RCC_CLKSEL_LPTIM2_SEL_RCL              /**< RCL作为LPTIM2的时钟          */  
#define RCC_LPTIM2_ASYNC_CLK_SRC_RCH            RCC_CLKSEL_LPTIM2_SEL_RCH              /**< RCH时钟作为LPTIM2的时钟      */
#define RCC_LPTIM2_ASYNC_CLK_SRC_LXTAL          RCC_CLKSEL_LPTIM2_SEL_LXTAL            /**< LXTAL时钟作为LPTIM2的时钟    */

/* I2C1异步时钟源选择 */
#define RCC_I2C1_ASYNC_CLK_SRC_PCLK1            RCC_CLKSEL_I2C1_SEL_PCLK              /**< APB时钟作为I2C1的时钟         */
#define RCC_I2C1_ASYNC_CLK_SRC_SYSCLK           RCC_CLKSEL_I2C1_SEL_SYSCLK            /**< 系统时钟作为I2C1的时钟        */
#define RCC_I2C1_ASYNC_CLK_SRC_RCH              RCC_CLKSEL_I2C1_SEL_RCH               /**< RCH时钟作为I2C1的时钟         */


/* ADC异步时钟源选择 */
#define RCC_ADC_ASYNC_CLK_SRC_SYSCLK            RCC_CLKSEL_ADC_SEL_SYSCLK             /**< 系统时钟作为ADC时钟          */
#define RCC_ADC_ASYNC_CLK_SRC_SYS_DIV2          RCC_CLKSEL_ADC_SEL_SYSCLK_DIV2        /**< 系统时钟2分频作为ADC时钟     */
#define RCC_ADC_ASYNC_CLK_SRC_SYS_DIV4          RCC_CLKSEL_ADC_SEL_SYSCLK_DIV4        /**< 系统时钟4分频作为ADC时钟     */
#define RCC_ADC_ASYNC_CLK_SRC_RCH               RCC_CLKSEL_ADC_SEL_RCH                /**< RCH时钟作为ADC时钟           */
                                                                                                                        
/* RTC、LCD异步时钟源选择 */                                                                                            
#define RCC_RTC_ASYNC_CLK_SRC_NONE              RCC_AWCR_RTCSEL_NONE                  /**< RTC无时钟配置                */
#define RCC_RTC_ASYNC_CLK_SRC_LXTAL             RCC_AWCR_RTCSEL_LXTAL                 /**< RTC时钟为LXTAL               */
#define RCC_RTC_ASYNC_CLK_SRC_RCL               RCC_AWCR_RTCSEL_RCL                   /**< RTC时钟为RCL                 */
                                                                                                                        
/* 复位标志定义 */                                                                                                      
#define RCC_RESET_FLAG_LOCKUP                   RCC_CSR2_LOCKUP_RSTF                  /**< LOCKUP复位标志               */
#define RCC_RESET_FLAG_OBL                      RCC_CSR2_OBL_RSTF                     /**< 选项字节加载复位标志         */
#define RCC_RESET_FLAG_NRST                     RCC_CSR2_NRST_RSTF                    /**< NRST引脚复位标志             */
#define RCC_RESET_FLAG_PMU                      RCC_CSR2_PMU_RSTF                     /**< POR/PDR、BOR复位标志         */
#define RCC_RESET_FLAG_SW                       RCC_CSR2_SW_RSTF                      /**< 软件复位标志                 */
#define RCC_RESET_FLAG_IWDG                     RCC_CSR2_IWDG_RSTF                    /**< IWDG复位标志                 */
#define RCC_RESET_FLAG_WWDG                     RCC_CSR2_WWDG_RSTF                    /**< WWDG复位标志                 */
#define RCC_RESET_FLAG_LPM                      RCC_CSR2_LPM_RSTF                     /**< 低功耗复位标志               */
#define RCC_RESET_FLAG_ALL                      (0xFFUL<<RCC_CSR2_LOCKUP_RSTF_POS)    /**< 所有复位标志                 */


/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup RCC_External_Functions RCC External Functions
* @brief    RCC对外函数
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  使能RCH时钟
* @note   使能RCH后，软件应等待RCHRDY标志置位后，再使用该时钟
* @retval 无
*/
__STATIC_INLINE void std_rcc_rch_enable(void)
{
    RCC->CSR1 |= RCC_CSR1_RCHON;
} 

/** 
* @brief  关闭RCH时钟
* @note   如果RCH为系统时钟源，则其不能被停止。此时用户应先将系统时钟源切换为其他时钟，再关闭该时钟源
* @note   当关闭RCH时，需等待RCHRDY标志清零
* @retval 无
*/
__STATIC_INLINE void std_rcc_rch_disable(void)
{
    RCC->CSR1 &= (~RCC_CSR1_RCHON);
}

/** 
* @brief  获取RCH ready标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示RCH ready置位
*             @arg false：表示RCH ready未置位
*/
__STATIC_INLINE bool std_rcc_get_rch_ready(void) 
{
    return((RCC->CSR1 & RCC_CSR1_RCHRDY) == RCC_CSR1_RCHRDY);
}        


/** 
* @brief  RCH分频因子配置
* @param  rchdiv 定义RCH的分频因子
*             @arg  RCC_RCH_DIV1：RCH时钟1分频
*             @arg  RCC_RCH_DIV2：RCH时钟2分频
*             @arg  RCC_RCH_DIV4：RCH时钟4分频
*             @arg  RCC_RCH_DIV8：RCH时钟8分频
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_rchdiv(uint32_t rchdiv)
{
    MODIFY_REG(RCC->CSR1, RCC_CSR1_RCHDIV, (rchdiv));
}
  
/** 
* @brief  获取RCH分频因子
* @retval uint32_t RCH的分频因子
*             @arg  RCC_RCH_DIV1：RCH时钟1分频
*             @arg  RCC_RCH_DIV2：RCH时钟2分频
*             @arg  RCC_RCH_DIV4：RCH时钟4分频
*             @arg  RCC_RCH_DIV8：RCH时钟8分频
*/
__STATIC_INLINE uint32_t std_rcc_get_rchdiv(void)
{
    return(RCC->CSR1 & RCC_CSR1_RCHDIV);
}
   
                   
/** 
* @brief  设置PLL时钟参数
* @param  pllsource PLL时钟源
*             @arg RCC_PLLSRC_RCH
*             @arg RCC_PLLSRC_HXTAL
* @param  pllm PLL时钟倍频因子m
*             @arg RCC_PLLM_MUL1
*             @arg RCC_PLLM_MUL4
*             @arg ...
*             @arg RCC_PLLM_MUL32
* @param  plln PLL时钟分频因子n
*             @arg RCC_PLLN_DIV1
*             @arg RCC_PLLN_DIV2
*             @arg ...
*             @arg RCC_PLLN_DIV8
* @param  plldiv PLL VCO分频因子
*             @arg RCC_PLL_DIV1
*             @arg RCC_PLL_DIV2
*             @arg RCC_PLL_DIV4
*             @arg RCC_PLL_DIV8
* @note   PLL参数配置必须在PLL使能前完成，一旦PLL使能后，PLL参数不能更改
* @retval 无
*/
__STATIC_INLINE void std_rcc_pll_config(uint32_t pllsource, uint32_t pllm, uint32_t plln, uint32_t plldiv)
{
    MODIFY_REG(RCC->PLLCFG, RCC_PLLCFG_PLLSRC | RCC_PLLCFG_PLLDIV | RCC_PLLCFG_PLLM | RCC_PLLCFG_PLLN, 
               pllsource | plldiv | pllm | plln);
}   

/** 
* @brief  获取PLL时钟源信息
* @retval uint32_t PLL时钟源
*             @arg RCC_PLLSRC_RCH
*             @arg RCC_PLLSRC_HXTAL
*/
__STATIC_INLINE uint32_t std_rcc_get_pllsource(void)
{
    return(RCC->PLLCFG & RCC_PLLCFG_PLLSRC);
}    


/** 
* @brief  使能PLL时钟输出
* @retval 无
*/
__STATIC_INLINE void std_rcc_pll_output_enable(void)
{
    RCC->PLLCFG |= RCC_PLLCFG_PLLEN;
}           

/** 
* @brief  禁止PLL时钟输出
* @retval 无
*/
__STATIC_INLINE void std_rcc_pll_output_disable(void)
{
    RCC->PLLCFG &= (~RCC_PLLCFG_PLLEN);
}

/** 
* @brief  使能PLL时钟
* @note   使能PLL后，软件应等待PLLRDY标志置位后，再使用该时钟
* @retval 无
*/
__STATIC_INLINE void std_rcc_pll_enable(void)
{
    RCC->CSR1 |= RCC_CSR1_PLLON;
}           

/** 
* @brief  关闭PLL时钟
* @note   如果PLL为系统时钟源，则其不能被停止。此时用户应先将系统时钟源切换为其他时钟，再关闭该时钟源
* @retval 无
*/
__STATIC_INLINE void std_rcc_pll_disable(void)
{
    RCC->CSR1 &= (~RCC_CSR1_PLLON);
}


/** 
* @brief  获取PLL ready标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示PLL ready置位
*             @arg false：表示PLL ready未置位
*/
__STATIC_INLINE bool std_rcc_get_pll_ready(void)
{
    return((RCC->CSR1 & RCC_CSR1_PLLRDY) == RCC_CSR1_PLLRDY);
}

/** 
* @brief  设置系统时钟源
* @param  clocksource 系统时钟源
*             @arg RCC_SYSCLK_SRC_RCHSYS   
*             @arg RCC_SYSCLK_SRC_HXTAL     
*             @arg RCC_SYSCLK_SRC_PLLCLK     
*             @arg RCC_SYSCLK_SRC_RCL     
*             @arg RCC_SYSCLK_SRC_LXTAL     
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_sysclk_source(uint32_t clocksource)
{
    MODIFY_REG(RCC->CFG, RCC_CFG_SYSW, clocksource);
}    

/** 
* @brief  获取系统时钟源信息
* @retval uint32_t 系统时钟源
*             @arg RCC_SYSCLK_SRC_STATUS_RCHSYS   
*             @arg RCC_SYSCLK_SRC_STATUS_HXTAL     
*             @arg RCC_SYSCLK_SRC_STATUS_PLLCLK     
*             @arg RCC_SYSCLK_SRC_STATUS_RCL     
*             @arg RCC_SYSCLK_SRC_STATUS_LXTAL     
*/
__STATIC_INLINE uint32_t std_rcc_get_sysclk_source(void)
{
    return(RCC->CFG & RCC_CFG_SYSWS);
}    

/** 
* @brief  设置AHB时钟分频因子
* @param  ahb_div AHB分频因子
*             @arg RCC_HCLK_DIV1   
*             @arg RCC_HCLK_DIV2     
*             @arg ...   
*             @arg RCC_HCLK_DIV128
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_ahbdiv(uint32_t ahb_div)
{
    MODIFY_REG(RCC->CFG, RCC_CFG_HPRE, ahb_div);
}    

/** 
* @brief  获取AHB时钟分频因子
* @retval uint32_t HCLK时钟分频因子
*             @arg RCC_HCLK_DIV1   
*             @arg RCC_HCLK_DIV2     
*             @arg ...   
*             @arg RCC_HCLK_DIV128
*/
__STATIC_INLINE uint32_t std_rcc_get_ahbdiv(void)
{
    return(RCC->CFG & RCC_CFG_HPRE);
} 

/** 
* @brief  设置APB1时钟分频因子
* @param  apb1_div APB1分频因子
*             @arg RCC_PCLK1_DIV1   
*             @arg RCC_PCLK1_DIV2     
*             @arg ...   
*             @arg RCC_PCLK1_DIV16
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_apb1div(uint32_t apb1_div)
{
    MODIFY_REG(RCC->CFG, RCC_CFG_P1PRE, apb1_div);
}    

/** 
* @brief  获取APB1时钟分频因子
* @retval uint32_t PCLK1时钟分频因子
*             @arg RCC_PCLK1_DIV1   
*             @arg RCC_PCLK1_DIV2     
*             @arg ...   
*             @arg RCC_PCLK1_DIV16
*/
__STATIC_INLINE uint32_t std_rcc_get_apb1div(void)
{
    return(RCC->CFG & RCC_CFG_P1PRE);
} 

/** 
* @brief  设置APB2时钟分频因子
* @param  apb2_div APB1分频因子
*             @arg RCC_PCLK2_DIV1   
*             @arg RCC_PCLK2_DIV2     
*             @arg ...   
*             @arg RCC_PCLK2_DIV16
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_apb2div(uint32_t apb2_div)
{
    MODIFY_REG(RCC->CFG, RCC_CFG_P2PRE, apb2_div);
}    

/** 
* @brief  获取APB2时钟分频因子
* @retval uint32_t PCLK2时钟分频因子
*             @arg RCC_PCLK2_DIV1   
*             @arg RCC_PCLK2_DIV2     
*             @arg ...   
*             @arg RCC_PCLK2_DIV16
*/
__STATIC_INLINE uint32_t std_rcc_get_apb2div(void)
{
    return(RCC->CFG & RCC_CFG_P2PRE);
} 


/**
* @brief  配置MCO输出信息
* @param  mco_source MCO输出源选择
*             @arg RCC_MCO_SRC_SYSCLK
*             @arg RCC_MCO_SRC_RCH
*             @arg RCC_MCO_SRC_HXTAL
*             @arg RCC_MCO_SRC_PLLCLK
*             @arg RCC_MCO_SRC_RCL
*             @arg RCC_MCO_SRC_LXTAL
* @param  mco_psc MCO输出分频因子
*             @arg RCC_MCO_DIV1
*             @arg RCC_MCO_DIV2
*             @arg ...
*             @arg RCC_MCO_DIV128
* @retval 无
*/
__STATIC_INLINE void std_rcc_mco_config(uint32_t mco_source, uint32_t mco_psc)
{
    MODIFY_REG(RCC->CFG, RCC_CFG_MCOSEL | RCC_CFG_MCOPRE, mco_source | mco_psc);
}


/** 
* @brief  关闭HXTAL时钟
* @note   如果HXTAL为系统时钟源，则其不能被停止。此时用户应先将系统时钟源切换为其他时钟，再关闭该时钟源
* @note   当关闭HXTAL时，需等待HXTALRDY标志清零
* @retval 无
*/
__STATIC_INLINE void std_rcc_hxtal_disable(void)
{
    RCC->CSR1 &= (~RCC_CSR1_HXTALON);
    RCC->CSR1 &= (~RCC_CSR1_HXTALBYP);
} 


/** 
* @brief  使能HXTAL时钟
* @param  mode  HXTAL的模式选择
*             @arg RCC_HXTAL_ON：    使能晶体模式
*             @arg RCC_HXTAL_BYPASS：使能外部时钟模式
* @note   使能HXTAL后，软件应等待HXTALRDY标志置位后，再使用该时钟
* @retval 无
*/
__STATIC_INLINE void std_rcc_hxtal_enable(uint32_t mode) 
{
    if(mode == RCC_HXTAL_BYPASS)
    {
        RCC->CSR1 |= RCC_CSR1_HXTALBYP; 
    }
    RCC->CSR1 |= RCC_CSR1_HXTALON;     
}


/** 
* @brief  获取HXTAL ready标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示HXTAL ready置位
*             @arg false：表示HXTAL ready未置位
*/
__STATIC_INLINE bool std_rcc_get_hxtal_ready(void)        
{
    return((RCC->CSR1 & RCC_CSR1_HXTALRDY) == RCC_CSR1_HXTALRDY);
}
              

/** 
* @brief  配置HXTAL驱动能力
* @param  drive_level HXTAL驱动能力参数
*             @arg  RCC_HXTAL_DRIVE_LEVEL0
*             @arg  RCC_HXTAL_DRIVE_LEVEL1
*             @arg  RCC_HXTAL_DRIVE_LEVEL2
*             @arg  RCC_HXTAL_DRIVE_LEVEL3
* @retval 无
*
*/
__STATIC_INLINE void std_rcc_hxtal_drive_config(uint32_t drive_level)
{
    MODIFY_REG(RCC->CSR1, RCC_CSR1_HXTAL_DRV, (drive_level));
}    

/** 
* @brief  配置HXTAL时钟稳定周期
* @param  drive_stabc HXTAL时钟稳定周期
*             @arg  RCC_HXTAL_STAB_SEL_256
*             @arg  ...
*             @arg  RCC_HXTAL_STAB_SEL_16384
* @retval 无
*
*/
__STATIC_INLINE void std_rcc_hxtal_stabc_config(uint32_t drive_stabc)
{
    MODIFY_REG(RCC->STABC, RCC_STABC_HXTAL_STAB_SEL, (drive_stabc));
} 


/** 
* @brief  关闭LXTAL时钟
* @note   如果LXTAL为系统时钟源，则其不能被停止。此时用户应先将系统时钟源切换为其他时钟，再关闭该时钟源
* @note   当关闭LXTAL时，需等待LXTALRDY标志清零
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_lxtal_disable(void) 
{
    RCC->AWCR &= (~RCC_AWCR_LXTALON);
}


/** 
* @brief  使能LXTAL时钟
* @param  mode LXTAL的旁路模式选择
              @arg RCC_LXTAL_ON
* @note   使能LXTAL后，软件应等待LXTALRDY标志置位后，再使用该时钟
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_lxtal_enable(uint32_t mode)
{
    RCC->AWCR |= RCC_AWCR_LXTALON; 
}                   


/** 
* @brief  获取LXTAL ready标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示LXTAL ready置位
*             @arg false：表示LXTAL ready未置位
*/
__STATIC_INLINE bool std_rcc_get_lxtal_ready(void)        
{
    return((RCC->AWCR & RCC_AWCR_LXTALRDY) == RCC_AWCR_LXTALRDY);
}

/** 
* @brief  LXTAL时钟驱动模式选择
* @param  lxtal_drv_mode LXTAL驱动模式选择
*             @arg RCC_LXTAL_DRIVE_MODE_NORMAL： 普通模式
*             @arg RCC_LXTAL_DRIVE_MODE_ENHANCE：增强模式
* @retval 无
*/
__STATIC_INLINE void std_rcc_lxtal_drive_mode_config(uint32_t lxtal_drv_mode) 
{
    MODIFY_REG(RCC->AWCR, RCC_AWCR_LXTAL_DRV_MODE, (lxtal_drv_mode));
}


/**
* @brief  配置LXTAL时钟驱动能力
* @param  drive_level LXTAL时钟驱动能力参数
*             @arg  RCC_LXTAL_DRIVE_LEVEL0
*             @arg  RCC_LXTAL_DRIVE_LEVEL1
*             @arg  RCC_LXTAL_DRIVE_LEVEL2
*             @arg  RCC_LXTAL_DRIVE_LEVEL3
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_lxtal_drive_config(uint32_t drive_level) 
{
    MODIFY_REG(RCC->AWCR, RCC_AWCR_LXTAL_DRV, (drive_level));
}  


/** 
* @brief  配置LXTAL时钟稳定周期
* @param  drive_stabc LXTAL时钟稳定周期
*             @arg  RCC_LXTAL_STAB_SEL_256
*             @arg  ...
*             @arg  RCC_LXTAL_STAB_SEL_16384
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_lxtal_stabc_config(uint32_t drive_stabc)
{
    MODIFY_REG(RCC->AWCR, RCC_AWCR_LXTAL_STAB_SEL, (drive_stabc));
}

/** 
* @brief  使能RCC中断
* @param  interrupt 使能RCC中断源的信息
*             @arg  RCC_INTERRUPT_RCL_READY
*             @arg  RCC_INTERRUPT_LXTAL_READY
*             @arg  RCC_INTERRUPT_RCH_READY
*             @arg  RCC_INTERRUPT_HXTAL_READY
*             @arg  RCC_INTERRUPT_PLL_READY
* @retval 无
*/
__STATIC_INLINE void std_rcc_interrupt_enable(uint32_t interrupt)     
{
    RCC->IER |= (interrupt);
}

/** 
* @brief  关闭RCC中断
* @param  interrupt 关闭RCC中断源的信息
*             @arg  RCC_INTERRUPT_RCL_READY
*             @arg  RCC_INTERRUPT_LXTAL_READY
*             @arg  RCC_INTERRUPT_RCH_READY
*             @arg  RCC_INTERRUPT_HXTAL_READY
*             @arg  RCC_INTERRUPT_PLL_READY
* @retval 无
*/
__STATIC_INLINE void std_rcc_interrupt_disable(uint32_t interrupt)    
{
    RCC->IER &= (~(interrupt));
} 


/**
* @brief  获取RCC中断使能状态
* @param  interrupt RCC中断源信息
*             @arg  RCC_INTERRUPT_RCL_READY
*             @arg  RCC_INTERRUPT_LXTAL_READY
*             @arg  RCC_INTERRUPT_RCH_READY
*             @arg  RCC_INTERRUPT_HXTAL_READY
*             @arg  RCC_INTERRUPT_PLL_READY
* @retval bool 返回输入中断标志置位状态
*             @arg true： 表示指定的中断使能
*             @arg false：表示指定的中断未使能
             
*/
__STATIC_INLINE bool std_rcc_get_interrupt_enable(uint32_t interrupt)    
{
    return((RCC->IER & (interrupt)) == (interrupt));
}

/**
* @brief  获取RCC中断标志状态
* @param  flag RCC中断标志信息
*             @arg  RCC_FLAG_RCL_READY
*             @arg  RCC_FLAG_LXTAL_READY
*             @arg  RCC_FLAG_RCH_READY
*             @arg  RCC_FLAG_HXTAL_READY
*             @arg  RCC_FLAG_PLL_READY
*             @arg  RCC_FLAG_HXTALCSS
* @retval bool 返回输入中断标志置位状态
*             @arg true： 表示指定的中断标志置位
*             @arg false：表示指定的中断标志未置位
             
*/
__STATIC_INLINE bool std_rcc_get_flag(uint32_t flag) 
{
    return((RCC->ISR & (flag)) == (flag));
}

/** 
* @brief  清除RCC标志
* @param  flags 清除标志位
*             @arg  RCC_CLEAR_RCL_READY
*             @arg  RCC_CLEAR_LXTAL_READY
*             @arg  RCC_CLEAR_RCH_READY
*             @arg  RCC_CLEAR_HXTAL_READY
*             @arg  RCC_CLEAR_PLL_READY
*             @arg  RCC_CLEAR_HXTALCSS
* @retval 无
*/
__STATIC_INLINE void std_rcc_clear_flag(uint32_t flags)   
{
    RCC->ICR |= (flags);
}


/** 
* @brief  使能RCL时钟
* @note   使能RCL后，软件应等待RCLRDY标志置位后，再使用该时钟
* @retval 无
*/
__STATIC_INLINE void std_rcc_rcl_enable(void)
{
    RCC->CSR2 |= RCC_CSR2_RCLON;
}          


/** 
* @brief  关闭RCL时钟
* @note   如果RCL为系统时钟源，则其不能被停止。此时用户应先将系统时钟源切换为其他时钟，再关闭该时钟源
* @note   当关闭RCL时，需等待RCLRDY标志清零
* @retval 无
*/
__STATIC_INLINE void std_rcc_rcl_disable(void) 
{
    RCC->CSR2 &= (~RCC_CSR2_RCLON);
}        


/** 
* @brief  获取RCL ready标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示RCL ready置位
*             @arg false：表示RCL ready未置位
*/
__STATIC_INLINE bool std_rcc_get_rcl_ready(void)          
{
    return((RCC->CSR2 & RCC_CSR2_RCLRDY) == RCC_CSR2_RCLRDY);
}


/** 
* @brief  使能HXTAL CSS
* @note   使能HXTAL CSS后，软件无法关闭，直到复位或者发生CSS故障才允许关闭
* @retval 无
*/
__STATIC_INLINE void std_rcc_hxtal_css_enable(void)
{
    RCC->CSR1 |= RCC_CSR1_HXTAL_CSSON;
}  

/** 
* @brief  获取复位标志
* @param  reset_flag 指定要获取的复位标志
*             @arg RCC_RESET_FLAG_LOCKUP
*             @arg RCC_RESET_FLAG_OBL   
*             @arg RCC_RESET_FLAG_NRST  
*             @arg RCC_RESET_FLAG_PMU   
*             @arg RCC_RESET_FLAG_SW    
*             @arg RCC_RESET_FLAG_IWDG  
*             @arg RCC_RESET_FLAG_WWDG  
*             @arg RCC_RESET_FLAG_LPM   
*             @arg RCC_RESET_FLAG_ALL   
* @retval bool 返回逻辑表达式的判断结果
*             @arg true：表示指定的复位标志置位
*             @arg false：表示指定的复位标志未置位
*/
__STATIC_INLINE bool std_rcc_get_reset_flag(uint32_t reset_flag)            
{
    return((RCC->CSR2 & (reset_flag)) == (reset_flag));
} 

/** 
* @brief  清除复位标志
* @note   该函数将清除所有复位标志
* @retval 无
*/
__STATIC_INLINE void std_rcc_clear_reset_flags(void)           
{
    RCC->CSR2 |= RCC_CSR2_RMVF;
}

/** 
* @brief  GPIO端口时钟使能
* @param  gpiox_clock 指定使能的GPIO时钟
*             @arg RCC_PERIPH_CLK_GPIOA
*             @arg ...
*             @arg RCC_PERIPH_CLK_GPIOF
* @retval 无
*/
__STATIC_INLINE void std_rcc_gpio_clk_enable(uint32_t gpiox_clock)
{
    RCC->IOPEN |= gpiox_clock; 
    
    /* RCC外围时钟启用后的延迟 */  
    __NOP(); __NOP(); __NOP(); 
}

/** 
* @brief  GPIO端口时钟禁止
* @param  gpiox_clock 指定禁止的GPIO时钟
*             @arg RCC_PERIPH_CLK_GPIOA
*             @arg ...
*             @arg RCC_PERIPH_CLK_GPIOF
* @retval 无
*/
__STATIC_INLINE void std_rcc_gpio_clk_disable(uint32_t gpiox_clock) 
{
    RCC->IOPEN &= (~(gpiox_clock)); 
    
    /* RCC外围时钟启用后的延迟 */  
    __NOP(); __NOP(); __NOP(); 
}

/** 
* @brief  GPIO端口复位
* @param  gpiox_rst 指定复位的GPIO端口
*             @arg RCC_PERIPH_RESET_GPIO_ALL
*             @arg RCC_PERIPH_RESET_GPIOA
*             @arg ...
*             @arg RCC_PERIPH_RESET_GPIOF
* @retval 无
*/
__STATIC_INLINE void std_rcc_gpio_reset(uint32_t gpiox_rst)
{
    RCC->IOPRST |= (gpiox_rst);
    RCC->IOPRST &= (~(gpiox_rst));
}         

/** 
* @brief  AHB外设时钟使能
* @param  periph_clock 指定使能的AHB外设时钟
*             @arg RCC_PERIPH_CLK_DMA
*             @arg RCC_PERIPH_CLK_FLASH    
*             @arg RCC_PERIPH_CLK_CRC  
*             @arg RCC_PERIPH_CLK_AES
* @retval 无
*/
__STATIC_INLINE void std_rcc_ahb_clk_enable(uint32_t periph_clock)
{
    RCC->AHBEN |= periph_clock;
    
    /* RCC外围时钟启用后的延迟 */    
    __NOP(); __NOP(); __NOP(); 
}   

/** 
* @brief  AHB外设时钟禁止
* @param  periph_clock 指定禁止的AHB外设时钟
*             @arg RCC_PERIPH_CLK_DMA  
*             @arg RCC_PERIPH_CLK_FLASH 
*             @arg RCC_PERIPH_CLK_CRC  
*             @arg RCC_PERIPH_CLK_AES
* @retval 无
*/
__STATIC_INLINE void std_rcc_ahb_clk_disable(uint32_t periph_clock)            
{
    RCC->AHBEN &= (~(periph_clock));
}

/** 
* @brief  AHB外设复位
* @param  periph_rst 指定复位的AHB外设
*             @arg RCC_PERIPH_RESET_AHB
*             @arg RCC_PERIPH_RESET_DMA
*             @arg RCC_PERIPH_RESET_CRC
*             @arg RCC_PERIPH_RESET_AES
* @retval 无
*/
__STATIC_INLINE void std_rcc_ahb_reset(uint32_t periph_rst)
{
    RCC->AHBRST |= (periph_rst);
    RCC->AHBRST &= (~(periph_rst));
}       

/** 
* @brief  APB1外设时钟使能
* @param  periph_clock 指定使能的APB1外设时钟
*             @arg RCC_PERIPH_CLK_TIM3   
*             @arg RCC_PERIPH_CLK_TIM4   
*             @arg RCC_PERIPH_CLK_TIM5   
*             @arg RCC_PERIPH_CLK_TIM8   
*             @arg RCC_PERIPH_CLK_LCD    
*             @arg RCC_PERIPH_CLK_RTC    
*             @arg RCC_PERIPH_CLK_WWDG  
*             @arg RCC_PERIPH_CLK_SPI2
*             @arg RCC_PERIPH_CLK_UART2
*             @arg RCC_PERIPH_CLK_UART3
*             @arg RCC_PERIPH_CLK_UART4
*             @arg RCC_PERIPH_CLK_LPUART1
*             @arg RCC_PERIPH_CLK_I2C1  
*             @arg RCC_PERIPH_CLK_LPUART2 
*             @arg RCC_PERIPH_CLK_PMU       
*             @arg RCC_PERIPH_CLK_LPTIM1 
*             @arg RCC_PERIPH_CLK_LPTIM2
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb1_clk_enable(uint32_t periph_clock)
{
    RCC->APB1EN |= periph_clock;
    
    /* RCC外围时钟启用后的延迟 */    
    __NOP(); __NOP(); __NOP(); 
}

/** 
* @brief  APB1外设时钟禁止
* @param  periph_clock 指定禁止的APB1外设时钟
*             @arg RCC_PERIPH_CLK_TIM3   
*             @arg RCC_PERIPH_CLK_TIM4   
*             @arg RCC_PERIPH_CLK_TIM5   
*             @arg RCC_PERIPH_CLK_TIM8   
*             @arg RCC_PERIPH_CLK_LCD    
*             @arg RCC_PERIPH_CLK_RTC    
*             @arg RCC_PERIPH_CLK_WWDG  
*             @arg RCC_PERIPH_CLK_SPI2
*             @arg RCC_PERIPH_CLK_UART2
*             @arg RCC_PERIPH_CLK_UART3
*             @arg RCC_PERIPH_CLK_UART4
*             @arg RCC_PERIPH_CLK_LPUART1
*             @arg RCC_PERIPH_CLK_I2C1  
*             @arg RCC_PERIPH_CLK_LPUART2 
*             @arg RCC_PERIPH_CLK_PMU       
*             @arg RCC_PERIPH_CLK_LPTIM1 
*             @arg RCC_PERIPH_CLK_LPTIM2
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb1_clk_disable(uint32_t periph_clock)            
{
    RCC->APB1EN &= (~(periph_clock));
}

/** 
* @brief  APB1外设复位
* @param  periph_rst 指定复位的APB1外设
*             @arg RCC_PERIPH_RESET_APB1
*             @arg RCC_PERIPH_RESET_TIM3   
*             @arg RCC_PERIPH_RESET_TIM4   
*             @arg RCC_PERIPH_RESET_TIM5   
*             @arg RCC_PERIPH_RESET_TIM8   
*             @arg RCC_PERIPH_RESET_LCD  
*             @arg RCC_PERIPH_RESET_SPI2  
*             @arg RCC_PERIPH_RESET_UART2 
*             @arg RCC_PERIPH_RESET_UART3 
*             @arg RCC_PERIPH_RESET_UART4 
*             @arg RCC_PERIPH_RESET_LPUART1
*             @arg RCC_PERIPH_RESET_I2C1   
*             @arg RCC_PERIPH_RESET_LPUART2
*             @arg RCC_PERIPH_RESET_LPTIM1 
*             @arg RCC_PERIPH_RESET_LPTIM2
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb1_reset(uint32_t periph_rst)
{
    RCC->APB1RST |= (periph_rst);
    RCC->APB1RST &= (~(periph_rst));
}       

/** 
* @brief  APB2外设时钟使能
* @param  periph_clock 指定使能的APB2外设时钟
*             @arg RCC_PERIPH_CLK_SYSCFG 
*             @arg RCC_PERIPH_CLK_TRNG    
*             @arg RCC_PERIPH_CLK_SPI1   
*             @arg RCC_PERIPH_CLK_USART1 
*             @arg RCC_PERIPH_CLK_ADC    
*             @arg RCC_PERIPH_CLK_DBG
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb2_clk_enable(uint32_t periph_clock)
{
    RCC->APB2EN |= periph_clock;
    
    /* RCC外围时钟启用后的延迟 */    
    __NOP(); __NOP(); __NOP(); 
}


/** 
* @brief  APB2外设时钟禁止
* @param  periph_clock 指定禁止的APB2外设时钟
*             @arg RCC_PERIPH_CLK_SYSCFG 
*             @arg RCC_PERIPH_CLK_TRNG   
*             @arg RCC_PERIPH_CLK_SPI1   
*             @arg RCC_PERIPH_CLK_USART1 
*             @arg RCC_PERIPH_CLK_ADC    
*             @arg RCC_PERIPH_CLK_DBG
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb2_clk_disable(uint32_t periph_clock)            
{
    RCC->APB2EN &= (~(periph_clock));
}

/** 
* @brief  APB2外设复位
* @param  periph_rst 指定复位的APB2外设
*             @arg RCC_PERIPH_RESET_APB2
*             @arg RCC_PERIPH_RESET_SYSCFG
*             @arg RCC_PERIPH_RESET_TRNG     
*             @arg RCC_PERIPH_RESET_SPI1   
*             @arg RCC_PERIPH_RESET_USART1 
*             @arg RCC_PERIPH_RESET_ADC    
*             @arg RCC_PERIPH_RESET_DBG    
* @retval 无
*/
__STATIC_INLINE void std_rcc_apb2_reset(uint32_t periph_rst)
{
    RCC->APB2RST |= (periph_rst);
    RCC->APB2RST &= (~(periph_rst));
}       


/** 
* @brief  使能LOCKUP复位
* @retval 无
*/
__STATIC_INLINE void std_rcc_lockup_reset_enable(void)
{
    RCC->CSR2 |= RCC_CSR2_LOCKUP_RSTEN;
}


/** 
* @brief  禁止LOCKUP复位
* @retval 无
*/
__STATIC_INLINE void std_rcc_lockup_reset_disable(void)
{
    RCC->CSR2 &= (~RCC_CSR2_LOCKUP_RSTEN);
}


/** 
* @brief  ADC时钟源选择
* @param  adcclk_select ADC时钟源
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYS_DIV2
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYS_DIV4   
*             @arg RCC_ADC_ASYNC_CLK_SRC_RCH     
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_adcclk_source(uint32_t adcclk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_ADC_SEL, (adcclk_select));
}       

/** 
* @brief  获取ADC时钟源
* @retval uint32_t 返回ADC时钟源信息
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYS_DIV2
*             @arg RCC_ADC_ASYNC_CLK_SRC_SYS_DIV4   
*             @arg RCC_ADC_ASYNC_CLK_SRC_RCH     
*/
__STATIC_INLINE uint32_t std_rcc_get_adcclk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_ADC_SEL);
} 

/** 
* @brief  LPTIM1时钟源选择
* @param  lptim1clk_select LPTIM1时钟源
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_RCL
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_RCH   
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_LXTAL     
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_lptim1clk_source(uint32_t lptim1clk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_LPTIM1_SEL, (lptim1clk_select));
}       

/** 
* @brief  获取LPTIM1时钟源
* @retval uint32_t 返回LPTIM1时钟源信息
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_RCL
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_RCH  
*             @arg RCC_LPTIM1_ASYNC_CLK_SRC_LXTAL     
*/
__STATIC_INLINE uint32_t std_rcc_get_lptim1clk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_LPTIM1_SEL);
} 


/** 
* @brief  LPTIM2时钟源选择
* @param  lptim2clk_select LPTIM2时钟源
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_RCL
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_RCH   
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_LXTAL     
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_lptim2clk_source(uint32_t lptim2clk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_LPTIM2_SEL, (lptim2clk_select));
}       

/** 
* @brief  获取LPTIM2时钟源
* @retval uint32_t 返回LPTIM2时钟源信息
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_RCL
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_RCH  
*             @arg RCC_LPTIM2_ASYNC_CLK_SRC_LXTAL     
*/
__STATIC_INLINE uint32_t std_rcc_get_lptim2clk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_LPTIM2_SEL);
} 


/** 
* @brief  I2C1时钟源选择
* @param  i2c1clk_select I2C1时钟源
*             @arg RCC_I2C1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_I2C1_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_I2C1_ASYNC_CLK_SRC_RCH  
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_i2c1clk_source(uint32_t i2c1clk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_I2C1_SEL, (i2c1clk_select));
}       

/** 
* @brief  获取I2C1时钟源
* @retval uint32_t 返回I2C1时钟源信息
*             @arg RCC_I2C1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_I2C1_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_I2C1_ASYNC_CLK_SRC_RCH
*/
__STATIC_INLINE uint32_t std_rcc_get_i2c1clk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_I2C1_SEL);
} 


/** 
* @brief  LPUART1时钟源选择
* @param  lpuart1clk_select LPUART1时钟源
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_RCH      
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_LXTAL  
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_lpuart1clk_source(uint32_t lpuart1clk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_LPUART1_SEL, (lpuart1clk_select));
}       

/** 
* @brief  获取LPUART1时钟源
* @retval uint32_t 返回LPUART1时钟源信息
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_RCH       
*             @arg RCC_LPUART1_ASYNC_CLK_SRC_LXTAL  
*/
__STATIC_INLINE uint32_t std_rcc_get_lpuart1clk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_LPUART1_SEL);
} 


/** 
* @brief  LPUART2时钟源选择
* @param  lpuart2clk_select LPUART2时钟源
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_RCH      
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_LXTAL  
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_lpuart2clk_source(uint32_t lpuart2clk_select)
{
    MODIFY_REG(RCC->CLKSEL, RCC_CLKSEL_LPUART2_SEL, (lpuart2clk_select));
}       

/** 
* @brief  获取LPUART2时钟源
* @retval uint32_t 返回LPUART2时钟源信息
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_PCLK1
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_SYSCLK
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_RCH       
*             @arg RCC_LPUART2_ASYNC_CLK_SRC_LXTAL  
*/
__STATIC_INLINE uint32_t std_rcc_get_lpuart2clk_source(void)
{
    return(RCC->CLKSEL & RCC_CLKSEL_LPUART2_SEL);
} 

/** 
* @brief  RTC/LCD时钟源选择
* @param  rtcclk_select RTC/LCD时钟源
*             @arg RCC_RTC_ASYNC_CLK_SRC_LXTAL
*             @arg RCC_RTC_ASYNC_CLK_SRC_RCL
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_set_rtcclk_source(uint32_t rtcclk_select)
{
    MODIFY_REG(RCC->AWCR, RCC_AWCR_RTCSEL, (rtcclk_select));
}       

/** 
* @brief  获取RTC/LCD时钟源
* @retval uint32_t 返回RTC/LCD时钟源信息
*             @arg RCC_RTC_ASYNC_CLK_SRC_LXTAL
*             @arg RCC_RTC_ASYNC_CLK_SRC_RCL 
*/
__STATIC_INLINE uint32_t std_rcc_get_rtcclk_source(void)
{
    return(RCC->AWCR & RCC_AWCR_RTCSEL);
} 


/** 
* @brief  使能RTC时钟
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @note   应先选择RTC时钟源后再调用该函数使能RTC KCLK时钟
* @retval 无
*/
__STATIC_INLINE void std_rcc_rtc_enable(void) 
{
    RCC->AWCR |= RCC_AWCR_RTCEN;
}        

/** 
* @brief  关闭RTC时钟
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_rtc_disable(void)       
{
    RCC->AWCR &= (~RCC_AWCR_RTCEN);
}


/**
* @brief  使能RCH常开功能
* @note   使能后在Stop模式下，RCH仍旧保持打开状态，可用作LPUART的工作时钟，避免因RCH启动时间而减慢通讯速度
* @note   此功能的置位和清除对RCHON位无影响
* @retval 无
*/
__STATIC_INLINE void std_rcc_rchawon_enable(void)
{
    RCC->CSR1 |= RCC_CSR1_RCH_AWON;
}

/**
* @brief  禁止RCH常开功能
* @note   此功能的置位和清除对RCHON位无影响
* @retval 无
*/
__STATIC_INLINE void std_rcc_rchawon_disable(void)
{
     RCC->CSR1 &= (~RCC_CSR1_RCH_AWON);
}   


/** 
* @brief  VCORE_AON 域复位
* @note   此函数用于重置RTC/TAMP外设（包括备份寄存器）和 RCC_AWCR部分控制位
* @note   调用该函数前应先调用std_pmu_vaon_write_enable(void)，解除RCC_AWCR的写保护
* @retval 无
*/
__STATIC_INLINE void std_rcc_vcore_aon_reset(void)  
{
    RCC->AWCR |= RCC_AWCR_AW_RST;
    RCC->AWCR &= (~RCC_AWCR_AW_RST);
}             


/** 
* @brief  写RCL校准值
* @param  cal_value RCL校准值，范围为：0x00~0x1F
* @retval 无
*/
__STATIC_INLINE void std_rcc_write_rcl_calibration(uint32_t cal_value)
{
    MODIFY_REG(RCC->RCLCAL, RCC_RCLCAL_RCL_CAL, cal_value << RCC_RCLCAL_RCL_CAL_POS);
}


/** 
* @brief  读取RCL校准值
* @retval uint32_t RCL校准值，范围为：0x00~0x1F
*/
__STATIC_INLINE uint32_t std_rcc_read_rcl_calibration(void)
{
    return(RCC->RCLCAL & RCC_RCLCAL_RCL_CAL);
}


/** 
* @brief  写RCH校准值
* @param  cal_value RCH校准值，范围为：0x00~0x7F
* @retval 无
*/
__STATIC_INLINE void std_rcc_write_rch_calibration(uint32_t cal_value)
{
    MODIFY_REG(RCC->RCHCAL, RCC_RCHCAL_RCH_CAL, cal_value << RCC_RCHCAL_RCH_CAL_POS);
}


/** 
* @brief  读取RCH校准值
* @retval uint32_t RCH校准值，范围为：0x00~0x7F
*/
__STATIC_INLINE uint32_t std_rcc_read_rch_calibration(void)
{
    return(RCC->RCHCAL & RCC_RCHCAL_RCH_CAL);
}

/** 
* @brief  写VREFBUF输出电压校准值
* @param  cal_value VREFBUF校准值，范围为：0x00~0x7F
* @retval 无
*/
__STATIC_INLINE void std_rcc_write_vrefbuf_calibration(uint32_t cal_value)
{
    MODIFY_REG(RCC->VREFBUFCAL, RCC_VRBUFCAL_VRBUF_CAL, cal_value);
} 


/** 
* @brief  读取VREFBUF输出电压校准值
* @retval uint32_t VREFBUF校准值，范围为：0x00~0x7F
*/
__STATIC_INLINE uint32_t std_rcc_read_vrefbuf_calibration(void)
{
    return(RCC->VREFBUFCAL & RCC_VRBUFCAL_VRBUF_CAL);
} 

                                                            


/* 获取时钟频率函数 */
uint32_t std_rcc_get_sysclkfreq(void);
uint32_t std_rcc_get_pllfreq(void);
uint32_t std_rcc_get_hclkfreq(void);
uint32_t std_rcc_get_pclk1freq(void);
uint32_t std_rcc_get_pclk2freq(void);    


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

#endif /* CIU32L051_STD_RCC_H */


