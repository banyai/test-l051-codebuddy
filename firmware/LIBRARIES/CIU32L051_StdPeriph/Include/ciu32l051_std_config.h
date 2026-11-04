/************************************************************************************************/
/**
* @file               ciu32l051_std_config.h
* @author             MCU Ecosystem Development Team
* @brief              STD库相关配置项定义。
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_CONFIG_H
#define CIU32L051_STD_CONFIG_H   

#ifdef __cplusplus
extern "C" {
#endif

    
/*--------------------------------------------define--------------------------------------------*/
/* 定义CIU32L051 STD库中所有芯片外设的使用开关 */
#define STD_ADC_PERIPHERAL_USED
#define STD_AES_PERIPHERAL_USED
#define STD_COMP_PERIPHERAL_USED
#define STD_CRC_PERIPHERAL_USED
#define STD_DBG_PERIPHERAL_USED
#define STD_DMA_PERIPHERAL_USED
#define STD_EXTI_PERIPHERAL_USED 
#define STD_FLASH_PERIPHERAL_USED
#define STD_GPIO_PERIPHERAL_USED
#define STD_I2C_PERIPHERAL_USED
#define STD_IWDG_PERIPHERAL_USED
#define STD_LCD_PERIPHERAL_USED
#define STD_LPTIM_PERIPHERAL_USED
#define STD_LPUART_PERIPHERAL_USED  
#define STD_PMU_PERIPHERAL_USED
#define STD_RTC_PERIPHERAL_USED
#define STD_SPI_PERIPHERAL_USED
#define STD_SYSCFG_PERIPHERAL_USED
#define STD_TAMP_PERIPHERAL_USED  
#define STD_TIM_PERIPHERAL_USED
#define STD_TRNG_PERIPHERAL_USED
#define STD_USART_PERIPHERAL_USED  
#define STD_VREFBUF_PERIPHERAL_USED  
#define STD_WWDG_PERIPHERAL_USED 

/* 时钟源配置信息 */
#if !defined  (HXTAL_VALUE)  
    #define HXTAL_VALUE              (8000000UL)    /**< HXTAL时钟频率(Hz) */
#endif 

#if !defined  (HXTAL_READY_TIMEOUT)
    #define HXTAL_READY_TIMEOUT      (100U)         /**< HXTAL稳定超时时间 (ms) */
#endif 

#if !defined  (LXTAL_VALUE)
    #define LXTAL_VALUE              (32768UL)      /**< LXTAL时钟频率(Hz) */
#endif 

#if !defined  (LXTAL_READY_TIMEOUT)
    #define LXTAL_READY_TIMEOUT      (5000U)        /**< LXTAL稳定超时时间 (ms) */
#endif 

#if !defined  (RCH_VALUE)
    #define RCH_VALUE                (16000000UL)   /**< RCH时钟频率(Hz) */
#endif 

#if !defined  (RCL_VALUE)
    #define RCL_VALUE                (32000UL)      /**< RCL时钟频率(Hz) */
#endif 


/** 
* @brief  PVD稳定时间参数配置,单位：us
* @note   该时间为使能PVD到PVD状态稳定输出的延时配置（未配置数字滤波）
*/
#define PMU_PVD_DELAY                (40UL)            

/*------------------------------------------includes--------------------------------------------*/

/* 根据外设配置，引用外设头文件 */
#include "ciu32l051_std_rcc.h"
    
    
#ifdef STD_ADC_PERIPHERAL_USED
    #include "ciu32l051_std_adc.h"
#endif 

#ifdef STD_AES_PERIPHERAL_USED
    #include "ciu32l051_std_aes.h"
#endif 

#ifdef STD_COMP_PERIPHERAL_USED
    #include "ciu32l051_std_comp.h"
#endif 

#ifdef STD_CRC_PERIPHERAL_USED
    #include "ciu32l051_std_crc.h"
#endif 

#ifdef STD_DBG_PERIPHERAL_USED
    #include "ciu32l051_std_dbg.h"
#endif 

#ifdef STD_DMA_PERIPHERAL_USED
    #include "ciu32l051_std_dma.h"
#endif 

#ifdef STD_EXTI_PERIPHERAL_USED
    #include "ciu32l051_std_exti.h"
#endif 

#ifdef STD_FLASH_PERIPHERAL_USED
    #include "ciu32l051_std_flash.h"
#endif 

#ifdef STD_GPIO_PERIPHERAL_USED
    #include "ciu32l051_std_gpio.h"
#endif 

#ifdef STD_I2C_PERIPHERAL_USED
    #include "ciu32l051_std_i2c.h"
#endif 

#ifdef STD_IWDG_PERIPHERAL_USED
    #include "ciu32l051_std_iwdg.h"
#endif 

#ifdef STD_LCD_PERIPHERAL_USED
    #include "ciu32l051_std_lcd.h"
#endif 

#ifdef STD_LPTIM_PERIPHERAL_USED
    #include "ciu32l051_std_lptim.h"
#endif 

#ifdef STD_LPUART_PERIPHERAL_USED
    #include "ciu32l051_std_lpuart.h"
#endif

#ifdef STD_PMU_PERIPHERAL_USED
    #include "ciu32l051_std_pmu.h"
#endif 

#ifdef STD_RTC_PERIPHERAL_USED
    #include "ciu32l051_std_rtc.h"
#endif

#ifdef STD_SPI_PERIPHERAL_USED
    #include "ciu32l051_std_spi.h"
#endif

#ifdef STD_SYSCFG_PERIPHERAL_USED
    #include "ciu32l051_std_syscfg.h"
#endif

#ifdef STD_TAMP_PERIPHERAL_USED
    #include "ciu32l051_std_tamp.h"
#endif

#ifdef STD_TIM_PERIPHERAL_USED
    #include "ciu32l051_std_tim.h"
#endif

#ifdef STD_TRNG_PERIPHERAL_USED
    #include "ciu32l051_std_trng.h"
#endif

#ifdef STD_USART_PERIPHERAL_USED
    #include "ciu32l051_std_usart.h"
#endif

#ifdef STD_VREFBUF_PERIPHERAL_USED
    #include "ciu32l051_std_vrefbuf.h"
#endif

#ifdef STD_WWDG_PERIPHERAL_USED
    #include "ciu32l051_std_wwdg.h"
#endif


/*-------------------------------------------functions------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* CIU32L051_STD_CONFIG_H */

