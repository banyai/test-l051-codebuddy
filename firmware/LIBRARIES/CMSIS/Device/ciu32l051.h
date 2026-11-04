/************************************************************************************************/
/**
* @file               ciu32l051.h
* @author             MCU Ecosystem Development Team
* @brief              CMSIS Core Peripheral Access Layer Header File for
*                     CIU32L051(CM0+). 
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

#ifndef CIU32L051_H
#define CIU32L051_H


/************************************************************************************************/
/**
* @addtogroup CMSIS
* @{
*/

/** 
* @defgroup CIU32L051 CIU32L051
* @{
*/
/************************************************************************************************/

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */



/*-----------------------------------------type define------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup CIU32L051_Types CIU32L051 Types
* @brief CIU32L051 data type definition
* @{
*/
/************************************************************************************************/ 

/**
* @brief Interrupt Number Definition
*/
typedef enum IRQn
{
    /* -------------------------------Cortex-M0+ Processor Exceptions Numbers  -------------------------------------- */
    
    NonMaskableInt_IRQn              = -14,    /**< 2 Non Maskable Interrupt                                          */
    HardFault_IRQn                   = -13,    /**< 3 Cortex-M Hard Fault Interrupt                                   */
    SVC_IRQn                         = -5,     /**< 11 Cortex-M SV Call Interrupt                                     */
    PendSV_IRQn                      = -2,     /**< 14 Cortex-M Pend SV Interrupt                                     */
    SysTick_IRQn                     = -1,     /**< 15 Cortex-M System Tick Interrupt                                 */
    
    /* -------------------------------CIU32L051 Interrupt Numbers---------------------------------------------------- */
    
    WWDG_IRQn                        = 0,      /**< WWDG interrupt                                                    */
    PVD_IRQn                         = 1,      /**< PVD interrupt                                                     */
    RTC_TAMP_IRQn                    = 2,      /**< RTC and TAMP interrupt                                            */
    FLASH_IRQn                       = 3,      /**< FLASH global interrupt                                            */
    RCC_IRQn                         = 4,      /**< RCC global interrupt                                              */
    EXTI0_1_IRQn                     = 5,      /**< EXTI line 0 & 1 interrupts                                        */
    EXTI2_3_IRQn                     = 6,      /**< EXTI line 2 & 3 interrupts                                        */
    EXTI4_15_IRQn                    = 7,      /**< EXTI line 4 to 15 interrupts                                      */
    LCD_IRQn                         = 8,      /**< LCD globlal interrupts                                            */    
    DMA_Channel0_IRQn                = 9,      /**< DMA channel 0 interrupt                                           */
    DMA_Channel1_IRQn                = 10,     /**< DMA channel 1                                                     */
    ADC_COMP_IRQn                    = 12,     /**< ADC, COMP1 and COMP2 interrupts                                   */
    TIM3_IRQn                        = 15,     /**< TIM3 global interrupt                                             */
    TIM4_IRQn                        = 16,     /**< TIM4 global interrupt                                             */
    TIM5_IRQn                        = 17,     /**< TIM5 global interrupt                                             */   
    TIM8_IRQn                        = 18,     /**< TIM8 global interrupt                                             */ 
    AES_IRQn                         = 19,     /**< AES global interrupt                                              */ 
    LPTIM1_IRQn                      = 20,     /**< LPTIM1 global interrupt                                           */
    I2C1_IRQn                        = 21,     /**< I2C1 globlal interrupt                                            */
    SPI1_IRQn                        = 23,     /**< SPI1 globlal interrupt                                            */
    SPI2_IRQn                        = 24,     /**< SPI2 globlal interrupt                                            */    
    USART1_IRQn                      = 25,     /**< USART1 globlal interrupt                                          */
    UART2_IRQn                       = 26,     /**< UART2 globlal interrupt                                           */
    UART3_4_IRQn                     = 27,     /**< UART3, UART4 globlal interrupt                                    */
    LPUART1_IRQn                     = 28,     /**< LPUART1 globlal interrupts                                        */
    TRNG_IRQn                        = 29,     /**< TRNG globlal interrupt                                            */
    LPTIM2_IRQn                      = 30,     /**< LPTIM2 global interrupt                                           */
    LPUART2_IRQn                     = 31,     /**< LPUART2 globlal interrupts                                        */                
} IRQn_Type;

/** 
* @} 
*/

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup CIU32L051_Constants CIU32L051 Constants
* @brief CIU32L051 constants definition
* @{
*
*/
/************************************************************************************************/    
/**
* @brief Configuration of Core Peripherals
*/
#define __CM0PLUS_REV             0x0001U /**< core revision r0p1                            */
#define __MPU_PRESENT             0U      /**< MPU not defined                               */
#define __VTOR_PRESENT            1U      /**< VTOR present                                  */
#define __NVIC_PRIO_BITS          2U      /**< number of bits used for priority levels       */
#define __Vendor_SysTickConfig    0U      /**< set to 1 if different SysTick Config is used  */

/**
* @brief  NVIC interrupt priority
*/
#define NVIC_PRIO_0         (0x00U)
#define NVIC_PRIO_1         (0x01U)    
#define NVIC_PRIO_2         (0x02U)    
#define NVIC_PRIO_3         (0x03U)

/** 
* @} 
*/

/*------------------------------------------includes--------------------------------------------*/
#include "core_cm0plus.h"                /* Cortex-M0+ processor and core peripherals */
#include "system_ciu32l051.h"            /* CIU32l051 System Header */
#include <stdint.h>

/*-----------------------------------------type define------------------------------------------*/
/************************************************************************************************/
/** 
* @addtogroup  CIU32L051_Types
* @{
*/
/************************************************************************************************/
/**
* @brief registers of ADC 
*/
typedef struct  
{
    __IO uint32_t CR;                   /**< ADC control register,                          Address offset: 0x000         */
    __IO uint32_t CFG1;                 /**< ADC configuration register 1,                  Address offset: 0x004         */
    __IO uint32_t CFG2;                 /**< ADC configuration register 2,                  Address offset: 0x008         */
         uint32_t RESERVED_0[1];        /**< Reserved,                                      Address offset: 0x00C         */
    __IO uint32_t ISR;                  /**< ADC interrupt and status register,             Address offset: 0x010         */
    __IO uint32_t IER;                  /**< ADC interrupt enable register,                 Address offset: 0x014         */
    __IO uint32_t SAMPT;                /**< ADC sampling time register,                    Address offset: 0x018         */
    __IO uint32_t CHCFG;                /**< ADC group regular sequencer register,          Address offset: 0x01C         */
    __IO uint32_t AWDG1CR;              /**< ADC analog watchdog 1 configuration register,  Address offset: 0x020         */
         uint32_t RESERVED_1[1];        /**< Reserved,                                      Address offset: 0x024         */    
    __IO uint32_t AWDG1TR;              /**< ADC analog watchdog 1 threshold register,      Address offset: 0x028         */
         uint32_t RESERVED_2[1];        /**< Reserved,                                      Address offset: 0x02C         */      
    __IO uint32_t CALFACT;              /**< ADC calibration factor register,               Address offset: 0x030         */
         uint32_t RESERVED_3[3];        /**< Reserved,                                      Address offset: 0x034 - 0x03C */
    __IO uint32_t DR;                   /**< ADC group regular data register,               Address offset: 0x040         */
} ADC_t;

/**
* @brief registers of AES
*/
typedef struct
{
    __IO uint32_t CR;                /**< AES mode register,                        Address offset: 0x00        */
    __IO uint32_t CSR;               /**< AES control register,                     Address offset: 0x04        */
         uint32_t RESERVED_0[2];     /**< Reserved,                                 Address offset: 0x08 - 0x0C */
    __IO uint32_t KEYR[4];           /**< AES key register,                         Address offset: 0x10 - 0x1C */
         uint32_t RESERVED_1[4];     /**< Reserved,                                 Address offset: 0x20 - 0x2C */    
    __IO uint32_t DR;                /**< AES data register,                        Address offset: 0x30        */
} AES_t;

/**
* @brief registers of COMP
*/
typedef struct
{
    __IO uint32_t CSR;               /**< COMP control and status register,        Address offset: 0x00 */
} COMP_t;

/**
* @brief registers of CRC
*/
typedef struct
{
    __IO uint32_t CSR;               /**< CRC control state register,              Address offset: 0x00      */
    __IO uint32_t RDR;               /**< CRC result  data register,               Address offset: 0x04      */
         uint32_t RESERVED_0[30];    /**< Reserved,                                Address offset: 0x08 - 7C */
    __IO uint32_t DR;                /**< CRC data register,                       Address offset: 0x80      */
} CRC_t;


/**
* @brief registers of DBG
*/
typedef struct
{
    __IO uint32_t CR;                /**< Debug control register,                  Address offset: 0x00 */
    __IO uint32_t APB1_FZ;           /**< Debug APB1 freeze register,              Address offset: 0x04 */
} DBG_t;

/**
* @brief registers of DMA
*/
typedef struct
{
    __IO uint32_t CC;             /**< DMA channel x configuration register,        Address offset: 0x00 */
    __IO uint32_t CNDTR;          /**< DMA channel x number of data register,       Address offset: 0x04 */
    __IO uint32_t CSAR;           /**< DMA channel x source address register,       Address offset: 0x08 */
    __IO uint32_t CDAR;           /**< DMA channel x destination address register,  Address offset: 0x0C */
         uint32_t RESERVED_0[1];  /**< Reserved,                                    Address offset: 0x10 */
} DMA_Channel_t;

typedef struct
{
    __IO uint32_t ISR;            /**< DMA interrupt status register,                 Address offset: 0x00        */
    __IO uint32_t ICR;            /**< DMA interrupt flag clear register,             Address offset: 0x04        */
    DMA_Channel_t channel[2];     /**< DMA channel registers,                         Address offset: 0x08 - 0x20 */
} DMA_t;


/**
* @brief registers of EXTI
*/
typedef struct
{
    __IO uint32_t RTSR;                /**< EXTI rising trigger selection register ,         Address offset: 0x00        */
    __IO uint32_t FTSR;                /**< EXTI falling trigger selection register ,        Address offset: 0x04        */
    __IO uint32_t PIR;                 /**< EXTI rising pending register ,                   Address offset: 0x08        */
         uint32_t RESERVED_0[17];      /**< Reserved,                                        Address offset: 0x0C - 0x4C */
    __IO uint32_t EXTICR[2];           /**< EXTI external interrupt configuration register,  Address offset: 0x50 - 0x54 */
         uint32_t RESERVED_1[6];       /**< Reserved,                                        Address offset: 0x58 - 0x6C */
    __IO uint32_t IMR;                 /**< EXTI interrupt mask register ,                   Address offset: 0x70        */
    __IO uint32_t EMR;                 /**< EXTI event mask register ,                       Address offset: 0x74        */

} EXTI_t;


/**
* @brief registers of FLASH
*/
typedef struct
{
    __IO uint32_t ACR;              /**< FLASH access control register,                Address offset: 0x00        */
         uint32_t RESERVED_0[1];    /**< Reserved,                                     Address offset: 0x04        */
    __IO uint32_t CRKEY;            /**< FLASH control key register,                   Address offset: 0x08        */
    __IO uint32_t OPTKEY;           /**< FLASH option key register,                    Address offset: 0x0C        */
    __IO uint32_t SR;               /**< FLASH status register,                        Address offset: 0x10        */
    __IO uint32_t CR;               /**< FLASH control register,                       Address offset: 0x14        */
         uint32_t RESERVED_1[2];    /**< Reserved,                                     Address offset: 0x18 - 0x1C */
    __IO uint32_t OPTR1;            /**< FLASH option register 1,                      Address offset: 0x20        */
    __IO uint32_t OPTR2;            /**< FLASH option register 2,                      Address offset: 0x24        */
         uint32_t RESERVED_2[4];    /**< Reserved,                                     Address offset: 0x28 - 0x34 */
    __IO uint32_t WRP1AS;           /**< FLASH WRP area A start address register,      Address offset: 0x38        */
    __IO uint32_t WRP1AE;           /**< FLASH WRP area A end address register,        Address offset: 0x3C        */
    __IO uint32_t WRP1BS;           /**< FLASH WRP area B start address register,      Address offset: 0x40        */
    __IO uint32_t WRP1BE;           /**< FLASH WRP area B end address register,        Address offset: 0x44        */
} FLASH_t;

/**
* @brief registers of GPIO 
*/
typedef struct
{
    __IO uint32_t MODE;            /**< GPIO port mode register,               Address offset: 0x00        */
    __IO uint32_t OTYPE;           /**< GPIO port output type register,        Address offset: 0x04        */
         uint32_t RESERVED_0[1];   /**< Reserved,                              Address offset: 0x08        */
    __IO uint32_t PUPD;            /**< GPIO port pull-up/pull-down register,  Address offset: 0x0C        */
    __IO uint32_t IDR;             /**< GPIO port input data register,         Address offset: 0x10        */
    __IO uint32_t ODR;             /**< GPIO port output data register,        Address offset: 0x14        */
    __IO uint32_t BSR;             /**< GPIO port bit set/reset  register,     Address offset: 0x18        */
         uint32_t RESERVED_1[1];   /**< Reserved,                              Address offset: 0x1C        */
    __IO uint32_t AFL;             /**< GPIO alternate function registers,     Address offset: 0x20        */
    __IO uint32_t AFH;             /**< GPIO alternate function registers,     Address offset: 0x24        */
    __IO uint32_t BR;              /**< GPIO bit reset register,               Address offset: 0x28        */
    __IO uint32_t HDCFG;           /**< GPIO high drive config register,       Address offset: 0x2C        */
} GPIO_t;


/**
* @brief registers of I2C
*/
typedef struct
{
    __IO uint32_t CR1;             /**< I2C control register 1,            Address offset: 0x00 */
    __IO uint32_t CR2;             /**< I2C control register 2,            Address offset: 0x04 */
    __IO uint32_t ADDR1;           /**< I2C own address 1 register,        Address offset: 0x08 */
    __IO uint32_t ADDR2;           /**< I2C own address 2 register,        Address offset: 0x0C */
    __IO uint32_t TIMING;          /**< I2C timing register,               Address offset: 0x10 */
         uint32_t RESERVED_0[1];   /**< Reserved,                          Address offset: 0x14 */
    __IO uint32_t ISR;             /**< I2C interrupt status register,     Address offset: 0x18 */
    __IO uint32_t ICR;             /**< I2C interrupt clear register,      Address offset: 0x1C */
         uint32_t RESERVED_1[1];   /**< Reserved,                          Address offset: 0x20 */
    __IO uint32_t RDR;             /**< I2C receive data register,         Address offset: 0x24 */
    __IO uint32_t TDR;             /**< I2C transmit data register,        Address offset: 0x28 */
} I2C_t;

/**
* @brief registers of IWDG
*/
typedef struct
{
    __IO uint32_t CR;              /**< IWDG control register,             Address offset: 0x00        */
    __IO uint32_t CFG;             /**< IWDG configuration register,       Address offset: 0x04        */
    __IO uint32_t RESERVED_0[2];   /**< Reserved,                          Address offset: 0x08 - 0x0C */
    __IO uint32_t WINR;            /**< IWDG window register,              Address offset: 0x10        */
    __IO uint32_t CNT;             /**< IWDG counter register,             Address offset: 0x14        */
} IWDG_t;


/**
* @brief registers of LCD
*/
typedef struct
{
    __IO uint32_t CR;            /**< LCD control register,              Address offset: 0x00      */
    __IO uint32_t FCR;           /**< LCD frame control register,        Address offset: 0x04      */
    __IO uint32_t SR;            /**< LCD status register,               Address offset: 0x08      */
    __IO uint32_t CLR;           /**< LCD clear register,                Address offset: 0x0C      */
         uint32_t RESERVED_0[1]; /**< Reserved,                          Address offset: 0x10      */
    __IO uint32_t RAM[10];       /**< LCD display memory,                Address offset: 0x14-0x38  */
} LCD_t;



/**
* @brief registers of LPTimer
*/
typedef struct
{
    __IO uint32_t ISR;              /**< LPTIM interrupt and status register,                Address offset: 0x00 */
    __IO uint32_t ICR;              /**< LPTIM interrupt clear register,                     Address offset: 0x04 */
    __IO uint32_t IER;              /**< LPTIM interrupt enable register,                    Address offset: 0x08 */
    __IO uint32_t CFG;              /**< LPTIM configuration register,                       Address offset: 0x0C */
    __IO uint32_t CR;               /**< LPTIM control register,                             Address offset: 0x10 */
    __IO uint32_t CMP;              /**< LPTIM compare register,                             Address offset: 0x14 */
    __IO uint32_t ARR;              /**< LPTIM autoreload register,                          Address offset: 0x18 */
    __IO uint32_t CNT;              /**< LPTIM counter register,                             Address offset: 0x1C */
    __IO uint32_t CFG2;             /**< LPTIM configuration register2,                      Address offset: 0x20 */
} LPTIM_t;


/**
* @brief registers of PMU
*/
typedef struct
{
    __IO uint32_t CR1;              /**< PMU control register 1,                     Address offset: 0x00         */
    __IO uint32_t CR2;              /**< PMU control register 2,                     Address offset: 0x04         */
    __IO uint32_t CR3;              /**< PMU control register 3,                     Address offset: 0x08         */
         uint32_t RESERVED_0[2];    /**< Reserved,                                   Address offset: 0x0C - 0x10  */
    __IO uint32_t SR;               /**< PMU status register,                        Address offset: 0x14         */
    __IO uint32_t CLR;              /**< PMU status clear register,                  Address offset: 0x18         */
} PMU_t;


/**
* @brief registers of RCC
*/
typedef struct
{
    __IO uint32_t CSR1;             /**< RCC clock control and status register 1,                                Address offset: 0x00            */
    __IO uint32_t STABC;            /**< RCC clock ready config register,                                        Address offset: 0x04            */
    __IO uint32_t CFG;              /**< RCC clocks config register,                                             Address offset: 0x08            */
    __IO uint32_t PLLCFG;           /**< RCC PLL config register,                                                Address offset: 0x0C            */
    __IO uint32_t IER;              /**< RCC interrupt enable register,                                          Address offset: 0x10            */
    __IO uint32_t ISR;              /**< RCC interrupt status register,                                          Address offset: 0x14            */
    __IO uint32_t ICR;              /**< RCC interrupt clear register,                                           Address offset: 0x18            */
    __IO uint32_t IOPRST;           /**< RCC IO port reset register,                                             Address offset: 0x1C            */
    __IO uint32_t AHBRST;           /**< RCC AHB peripherals reset register,                                     Address offset: 0x20            */
    __IO uint32_t APB1RST;          /**< RCC APB1 peripherals reset register,                                    Address offset: 0x24            */
    __IO uint32_t APB2RST;          /**< RCC APB2 peripherals reset register,                                    Address offset: 0x28            */
    __IO uint32_t IOPEN;            /**< RCC IO port clock enable register,                                      Address offset: 0x2C            */
    __IO uint32_t AHBEN;            /**< RCC AHB peripherals clock enable register,                              Address offset: 0x30            */
    __IO uint32_t APB1EN;           /**< RCC APB1 peripherals clock enable register,                             Address offset: 0x34            */
    __IO uint32_t APB2EN;           /**< RCC APB2 peripherals clock enable register,                             Address offset: 0x38            */
    __IO uint32_t CLKSEL;           /**< RCC peripherals independent clock source select register,               Address offset: 0x3C            */
    __IO uint32_t AWCR;             /**< RCC AON domain control register,                                        Address offset: 0x40            */
    __IO uint32_t CSR2;             /**< RCC clock control and status register 2,                                Address offset: 0x44            */
         uint32_t RESERVED_0[2];    /**< Reserved,                                                               Address offset: 0x48 - 0x4C     */
    __IO uint32_t RCLCAL;           /**< RCC RCL calibration register,                                           Address offset: 0x50            */    
    __IO uint32_t RCHCAL;           /**< RCC RCH calibration register,                                           Address offset: 0x54            */        
         uint32_t RESERVED_1[42];   /**< Reserved,                                                               Address offset: 0x58 - 0xFC     */
    __IO uint32_t VREFBUFCAL;       /**< RCC VREFBUF calibration register,                                       Address offset: 0x100           */
} RCC_t;

/**
* @brief registers of RTC
*/
typedef struct
{
    __IO uint32_t TR;               /**< RTC time register,                     Address offset: 0x00        */
    __IO uint32_t DR;               /**< RTC date register,                     Address offset: 0x04        */
    __IO uint32_t SSR;              /**< RTC sub second register,               Address offset: 0x08        */
    __IO uint32_t CSR;              /**< RTC control and status register,       Address offset: 0x0C        */
         uint32_t RESERVED_0[1];    /**< Reserved,                              Address offset: 0x10        */    
    __IO uint32_t WUT;              /**< RTC wakeup timer register,             Address offset: 0x14        */
    __IO uint32_t CR;               /**< RTC control register,                  Address offset: 0x18        */
         uint32_t RESERVED_1[2];    /**< Reserved,                              Address offset: 0x1C - 0x20 */
    __IO uint32_t WPR;              /**< RTC write protection register,         Address offset: 0x24        */
    __IO uint32_t CALR;             /**< RTC calibration register,              Address offset: 0x28        */
         uint32_t RESERVED_2[1];    /**< Reserved,                              Address offset: 0x2C        */
    __IO uint32_t TSTR;             /**< RTC time-stamp time register,          Address offset: 0x30        */
    __IO uint32_t TSDR;             /**< RTC time-stamp date register,          Address offset: 0x34        */
         uint32_t RESERVED_3[2];    /**< Reserved,                              Address offset: 0x38 - 0x3C */
    __IO uint32_t ALARMR;           /**< RTC alarm register,                    Address offset: 0x40        */
         uint32_t RESERVED_4[3];    /**< Reserved,                              Address offset: 0x44 - 0x4C */
    __IO uint32_t SR;               /**< RTC status register,                   Address offset: 0x50        */
    __IO uint32_t ISR;              /**< RTC interrupt status register,         Address offset: 0x54        */
         uint32_t RESERVED_5[1];    /**< Reserved,                              Address offset: 0x58        */
    __IO uint32_t CLR;              /**< RTC status clear register,             Address offset: 0x5C        */
} RTC_t;


/**
* @brief registers of SPI
*/
typedef struct
{
    __IO uint32_t CR1;               /**< SPI control register 1,                       Address offset: 0x00 */
    __IO uint32_t CR2;               /**< SPI control register 2,                       Address offset: 0x04 */
    __IO uint32_t DATACLR;           /**< SPI data clear register,                      Address offset: 0x08 */
    __IO uint32_t ISR;               /**< SPI interrupt status register,                Address offset: 0x0C */
    __IO uint32_t ICR;               /**< SPI interrupt status clear register,          Address offset: 0x10 */ 
    __IO uint32_t DR;                /**< SPI data register,                            Address offset: 0x14 */
} SPI_t;

/**
* @brief registers of SYSCFG
*/
typedef struct
{
    __IO uint32_t CR;                /**< SYSCFG control register,                      Address offset: 0x00 */
    __IO uint32_t SECCR;             /**< SYSCFG security control register,             Address offset: 0x04 */
} SYSCFG_t;

/**
* @brief registers of TAMP
*/
typedef struct
{
    __IO uint32_t ENR;             /**< TAMP enable register,                  Address offset: 0x000         */
    __IO uint32_t CR;              /**< TAMP control register,                 Address offset: 0x004         */
         uint32_t RESERVED_0[1];   /**< Reserved,                              Address offset: 0x008         */
    __IO uint32_t FLTCR;           /**< TAMP fliter control register,          Address offset: 0x00C         */
         uint32_t RESERVED_1[7];   /**< Reserved,                              Address offset: 0x010 - 0x028 */
    __IO uint32_t IER;             /**< TAMP interrupt enable register,        Address offset: 0x02C         */
    __IO uint32_t SR;              /**< TAMP status register,                  Address offset: 0x030         */
    __IO uint32_t ISR;             /**< TAMP interrupt Status register,        Address offset: 0x034         */
         uint32_t RESERVED_2[1];   /**< Reserved,                              Address offset: 0x038         */
    __IO uint32_t CLR;             /**< TAMP status clear register,            Address offset: 0x03C         */
         uint32_t RESERVED_3[48];  /**< Reserved,                              Address offset: 0x040 - 0x0FC */
    __IO uint32_t BKP0R;           /**< TAMP backup register 0,                Address offset: 0x100         */
    __IO uint32_t BKP1R;           /**< TAMP backup register 1,                Address offset: 0x104         */
    __IO uint32_t BKP2R;           /**< TAMP backup register 2,                Address offset: 0x108         */
    __IO uint32_t BKP3R;           /**< TAMP backup register 3,                Address offset: 0x10C         */
    __IO uint32_t BKP4R;           /**< TAMP backup register 4,                Address offset: 0x110         */
} TAMP_t;

/**
* @brief registers of Timer
*/
typedef struct
{
    __IO uint32_t CR1;             /**< TIM control register 1,                   Address offset: 0x00        */
    __IO uint32_t CR2;             /**< TIM control register 2,                   Address offset: 0x04        */
    __IO uint32_t SMC;             /**< TIM slave mode control register,          Address offset: 0x08        */
    __IO uint32_t DIER;            /**< TIM DMA/interrupt enable register,        Address offset: 0x0C        */
    __IO uint32_t SR;              /**< TIM status register,                      Address offset: 0x10        */
    __IO uint32_t EVTG;            /**< TIM event generation register,            Address offset: 0x14        */
    __IO uint32_t CCM1;            /**< TIM capture/compare mode register 1,      Address offset: 0x18        */
    __IO uint32_t CCM2;            /**< TIM capture/compare mode register 2,      Address offset: 0x1C        */
    __IO uint32_t CCEN;            /**< TIM capture/compare enable register,      Address offset: 0x20        */
    __IO uint32_t CNT;             /**< TIM counter register,                     Address offset: 0x24        */
    __IO uint32_t PSC;             /**< TIM prescaler register,                   Address offset: 0x28        */
    __IO uint32_t ARR;             /**< TIM auto-reload register,                 Address offset: 0x2C        */
         uint32_t RESERVED_0[1];   /**< Reserved,                                 Address offset: 0x30        */
    __IO uint32_t CC1;             /**< TIM capture/compare register 1,           Address offset: 0x34        */
    __IO uint32_t CC2;             /**< TIM capture/compare register 2,           Address offset: 0x38        */
    __IO uint32_t CC3;             /**< TIM capture/compare register 3,           Address offset: 0x3C        */
    __IO uint32_t CC4;             /**< TIM capture/compare register 4,           Address offset: 0x40        */
         uint32_t RESERVED_1[3];   /**< Reserved,                                 Address offset: 0x44 - 0x4C */
    __IO uint32_t CFG;             /**< TIM option register,                      Address offset: 0x50        */
         uint32_t RESERVED_2[3];   /**< Reserved,                                 Address offset: 0x54 - 0x5C */
    __IO uint32_t AF1;             /**< TIM alternate function register 1,        Address offset: 0x60        */
         uint32_t RESERVED_3[1];   /**< Reserved,                                 Address offset: 0x64        */
    __IO uint32_t TISEL;           /**< TIM Input Selection register,             Address offset: 0x68        */
} TIM_t;



/**
* @brief registers of TRNG
*/
typedef struct
{
    __IO uint32_t CR1;             /**< TRNG control register 1,                  Address offset: 0x00        */
         uint32_t RESERVED_0[1];   /**< Reserved,                                 Address offset: 0x04        */ 
    __IO uint32_t SR;              /**< TRNG status register,                     Address offset: 0x08        */
         uint32_t RESERVED_1[1];   /**< Reserved,                                 Address offset: 0x0C        */
    __IO uint32_t DR;              /**< TRNG data register,                       Address offset: 0x10        */
} TRNG_t;


/**
* @brief registers of USART
*/
typedef struct
{
    __IO uint32_t CR1;             /**< USART control register 1,                 Address offset: 0x00        */
    __IO uint32_t CR2;             /**< USART control register 2,                 Address offset: 0x04        */
    __IO uint32_t CR3;             /**< USART control register 3,                 Address offset: 0x08        */
    __IO uint32_t BRR;             /**< USART baud rate register,                 Address offset: 0x0C        */         
    __IO uint32_t GTPR;            /**< USART guard time & PSV register           Address offset: 0x10        */
    __IO uint32_t RTO;             /**< USART receive timeout register            Address offset: 0x14        */
    __IO uint32_t RQR;             /**< USART request register,                   Address offset: 0x18        */
    __IO uint32_t ISR;             /**< USART interrupt and status register,      Address offset: 0x1C        */
    __IO uint32_t ICR;             /**< USART interrupt flag clear register,      Address offset: 0x20        */
    __IO uint32_t RDR;             /**< USART receive data register,              Address offset: 0x24        */
    __IO uint32_t TDR;             /**< USART transmit data register,             Address offset: 0x28        */
    __IO uint32_t PRESC;           /**< USART Prescaler register,                 Address offset: 0x2C        */    
} USART_t;

/**
* @brief registers of VREFBUF
*/
typedef struct
{
    __IO uint32_t CSR;             /**< VREFBUF control and status register,     Address offset: 0x00 */
} VREFBUF_t;

/**
* @brief registers of WWDG
*/
typedef struct
{
    __IO uint32_t CR;              /**< WWDG control register,                   Address offset: 0x00 */
    __IO uint32_t CFG;             /**< WWDG configuration register,             Address offset: 0x04 */
    __IO uint32_t SR;              /**< WWDG status register,                    Address offset: 0x08 */
} WWDG_t;


/**
* @}
*/

/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/** 
* @addtogroup CIU32l051_Constants
* @{
*/
/************************************************************************************************/
/* Memory Map */
#define FLASH_MEM_BASE        (0x08000000UL)  /**< FLASH Base Address */
#define SRAM_BASE             (0x20000000UL)  /**< SRAM Base Address  */
#define APB1_BASE             (0x40000000UL)  /**< APB1 Base Address  */
#define APB2_BASE             (0x40010000UL)  /**< APB2 Base Address  */
#define AHB_BASE              (0x40020000UL)  /**< AHB Base Address   */
#define GPIO_BASE             (0x50000000UL)  /**< GPIO Base Address  */


#define UID_BASE              (0x1FFF0340UL)  /**< Unique device ID register base address        */
#define DEVICE_TYPE           (0x1FFF03A4UL)  /**< device type                                   */
#define USERFLASH_SIZE        (0x1FFF03A8UL)  /**< Size of user flash                            */
#define SRAM_SIZE             (0x1FFF03ACUL)  /**< Size of sram                                  */
#define BGR_CAL               (0x1FFF03C0UL)  /**< BGR calibration value address                 */
#define TS_CAL_25             (0x1FFF03C4UL)  /**< TS calibration value address for 25¡æ         */
#define TS_CAL_85             (0x1FFF03C8UL)  /**< TS calibration value address for 85¡æ         */
#define RCH_CAL               (0x1FFF03CCUL)  /**< RCH calibration value address                 */
#define RCL_CAL               (0x1FFF03D0UL)  /**< RCL calibration value address                 */
#define VREFBUF_CAL_20        (0x1FFF03D4UL)  /**< VREFBUF calibration value address for 2.048V  */
#define VREFBUF_CAL_25        (0x1FFF03D8UL)  /**< VREFBUF calibration value address for 2.5V    */
#define VREFBUF_CAL_30        (0x1FFF03DCUL)  /**< VREFBUF calibration value address for 3.0V    */


/* APB1 Peripherals */
#define TIM3_BASE             (APB1_BASE + 0x00000400UL)
#define TIM4_BASE             (APB1_BASE + 0x00000800UL)
#define TIM5_BASE             (APB1_BASE + 0x00000C00UL)
#define TIM8_BASE             (APB1_BASE + 0x00001000UL)
#define LCD_BASE              (APB1_BASE + 0x00002400UL)
#define RTC_BASE              (APB1_BASE + 0x00002800UL)
#define WWDG_BASE             (APB1_BASE + 0x00002C00UL)
#define IWDG_BASE             (APB1_BASE + 0x00003000UL)
#define SPI2_BASE             (APB1_BASE + 0x00003800UL)
#define UART2_BASE            (APB1_BASE + 0x00004400UL)
#define UART3_BASE            (APB1_BASE + 0x00004800UL)
#define UART4_BASE            (APB1_BASE + 0x00004C00UL)
#define I2C1_BASE             (APB1_BASE + 0x00005400UL)
#define PMU_BASE              (APB1_BASE + 0x00007000UL)
#define LPTIM1_BASE           (APB1_BASE + 0x00007C00UL)
#define LPUART1_BASE          (APB1_BASE + 0x00008000UL)
#define LPUART2_BASE          (APB1_BASE + 0x00008400UL)
#define LPTIM2_BASE           (APB1_BASE + 0x00009000UL)
#define TAMP_BASE             (APB1_BASE + 0x0000B000UL)

/* APB2 Peripherals */
#define SYSCFG_BASE           (APB2_BASE + 0x00000000UL)
#define VREFBUF_BASE          (APB2_BASE + 0x000001B0UL)
#define COMP1_BASE            (APB2_BASE + 0x00000200UL)
#define COMP2_BASE            (APB2_BASE + 0x00000204UL)
#define ADC_BASE              (APB2_BASE + 0x00002400UL)
#define SPI1_BASE             (APB2_BASE + 0x00003000UL)
#define USART1_BASE           (APB2_BASE + 0x00003800UL)
#define DBG_BASE              (APB2_BASE + 0x00005800UL)
#define TRNG_BASE             (APB2_BASE + 0x00008000UL)

/* AHB Peripherals */
#define DMA_BASE              (AHB_BASE + 0x00000000UL)
#define RCC_BASE              (AHB_BASE + 0x00001000UL)
#define EXTI_BASE             (AHB_BASE + 0x00001800UL)
#define FLASH_REGISTERS_BASE  (AHB_BASE + 0x00002000UL)
#define CRC_BASE              (AHB_BASE + 0x00003000UL)
#define AES_BASE              (AHB_BASE + 0x00006000UL)

/* GPIO */
#define GPIOA_BASE            (GPIO_BASE + 0x00000000UL)
#define GPIOB_BASE            (GPIO_BASE + 0x00000400UL)
#define GPIOC_BASE            (GPIO_BASE + 0x00000800UL)
#define GPIOD_BASE            (GPIO_BASE + 0x00000C00UL)
#define GPIOF_BASE            (GPIO_BASE + 0x00001400UL)


/* APB1 Peripherals instance*/
#define TIM3                ((TIM_t *) TIM3_BASE)
#define TIM4                ((TIM_t *) TIM4_BASE)
#define TIM5                ((TIM_t *) TIM5_BASE)
#define TIM8                ((TIM_t *) TIM8_BASE)
#define LCD                 ((LCD_t *) LCD_BASE)
#define RTC                 ((RTC_t *) RTC_BASE)
#define WWDG                ((WWDG_t *) WWDG_BASE)
#define IWDG                ((IWDG_t *) IWDG_BASE)
#define SPI2                ((SPI_t *) SPI2_BASE)
#define UART2               ((USART_t *) UART2_BASE)
#define UART3               ((USART_t *) UART3_BASE)
#define UART4               ((USART_t *) UART4_BASE)
#define I2C1                ((I2C_t *) I2C1_BASE)
#define PMU                 ((PMU_t *) PMU_BASE)
#define LPTIM1              ((LPTIM_t *) LPTIM1_BASE)
#define LPTIM2              ((LPTIM_t *) LPTIM2_BASE)
#define LPUART1             ((USART_t *) LPUART1_BASE)
#define LPUART2             ((USART_t *) LPUART2_BASE)
#define TAMP                ((TAMP_t *) TAMP_BASE)

/* APB2 Peripherals instance*/
#define SYSCFG              ((SYSCFG_t *) SYSCFG_BASE)
#define VREFBUF             ((VREFBUF_t *) VREFBUF_BASE)
#define COMP1               ((COMP_t *) COMP1_BASE)
#define COMP2               ((COMP_t *) COMP2_BASE)
#define ADC                 ((ADC_t *) ADC_BASE)
#define SPI1                ((SPI_t *) SPI1_BASE)
#define USART1              ((USART_t *) USART1_BASE)
#define DBG                 ((DBG_t *) DBG_BASE)
#define TRNG                ((TRNG_t *) TRNG_BASE)

/* AHB Peripherals instance*/
#define DMA                 ((DMA_t *) DMA_BASE)
#define RCC                 ((RCC_t *) RCC_BASE)
#define EXTI                ((EXTI_t *) EXTI_BASE)
#define FLASH               ((FLASH_t *) FLASH_REGISTERS_BASE)
#define CRC                 ((CRC_t *) CRC_BASE)
#define AES                 ((AES_t *) AES_BASE)

/* GPIO instance*/
#define GPIOA               ((GPIO_t *) GPIOA_BASE)
#define GPIOB               ((GPIO_t *) GPIOB_BASE)
#define GPIOC               ((GPIO_t *) GPIOC_BASE)
#define GPIOD               ((GPIO_t *) GPIOD_BASE)
#define GPIOF               ((GPIO_t *) GPIOF_BASE)


/*---------------------------Peripheral Registers Bits Definition-------------------------------*/

/*-----------------------------------------------------------------------------------------------
                                       ADC Registers Bits  
------------------------------------------------------------------------------------------------*/

/* Bits for ADC_CR */
#define ADC_CR_ADEN_POS                 (0U)
#define ADC_CR_ADEN_MASK                (0x1UL << ADC_CR_ADEN_POS)              /**< 0x00000001 */
#define ADC_CR_ADEN                     ADC_CR_ADEN_MASK                        /**< ADC enable */

#define ADC_CR_ADDIS_POS                (1U)
#define ADC_CR_ADDIS_MASK               (0x1UL << ADC_CR_ADDIS_POS)            /**< 0x00000002 */
#define ADC_CR_ADDIS                    ADC_CR_ADDIS_MASK                      /**< ADC disable */

#define ADC_CR_START_POS                (2U)
#define ADC_CR_START_MASK               (0x1UL << ADC_CR_START_POS)            /**< 0x00000004 */
#define ADC_CR_START                    ADC_CR_START_MASK                      /**< ADC group regular conversion start */

#define ADC_CR_STOP_POS                 (4U)
#define ADC_CR_STOP_MASK                (0x1UL << ADC_CR_STOP_POS)             /**< 0x00000010 */
#define ADC_CR_STOP                     ADC_CR_STOP_MASK                       /**< ADC group regular conversion stop */

#define ADC_CR_CALEN_POS                (31U)
#define ADC_CR_CALEN_MASK               (0x1UL << ADC_CR_CALEN_POS)            /**< 0x80000000 */
#define ADC_CR_CALEN                    ADC_CR_CALEN_MASK                      /**< ADC calibration */

/* Bits for ADC_CFG1 */
#define ADC_CFG1_DMAEN_POS              (0U)
#define ADC_CFG1_DMAEN_MASK             (0x1UL << ADC_CFG1_DMAEN_POS)          /**< 0x00000001 */
#define ADC_CFG1_DMAEN                  ADC_CFG1_DMAEN_MASK                    /**< ADC DMA transfer enable */

#define ADC_CFG1_SDIR_POS               (2U)
#define ADC_CFG1_SDIR_MASK              (0x1UL << ADC_CFG1_SDIR_POS)           /**< 0x00000004 */
#define ADC_CFG1_SDIR                   ADC_CFG1_SDIR_MASK                     /**< ADC group regular sequencer scan direction */

#define ADC_CFG1_TRIGEN_POS             (9U)
#define ADC_CFG1_TRIGEN_MASK            (0x3UL << ADC_CFG1_TRIGEN_POS)         /**< 0x00000600 */
#define ADC_CFG1_TRIGEN                 ADC_CFG1_TRIGEN_MASK                   /**< ADC group regular external trigger polarity */
#define ADC_CFG1_TRIGEN_SW              (0x0UL << ADC_CFG1_TRIGEN_POS)         /**< 0x00000000 */
#define ADC_CFG1_TRIGEN_HW_EDGE_RISING  (0x1UL << ADC_CFG1_TRIGEN_POS)         /**< 0x00000200 */
#define ADC_CFG1_TRIGEN_HW_EDGE_FALLING (0x2UL << ADC_CFG1_TRIGEN_POS)         /**< 0x00000400 */
#define ADC_CFG1_TRIGEN_HW_EDGE_BOTH    (0x3UL << ADC_CFG1_TRIGEN_POS)         /**< 0x00000600 */

#define ADC_CFG1_OVRN_MOD_POS           (11U)
#define ADC_CFG1_OVRN_MOD_MASK          (0x1UL << ADC_CFG1_OVRN_MOD_POS)       /**< 0x00000800 */
#define ADC_CFG1_OVRN_MOD               ADC_CFG1_OVRN_MOD_MASK                 /**< ADC group regular overrun configuration */

#define ADC_CFG1_CONV_MOD_POS           (12U)
#define ADC_CFG1_CONV_MOD_MASK          (0x3UL << ADC_CFG1_CONV_MOD_POS)       /**< 0x00003000 */
#define ADC_CFG1_CONV_MOD               ADC_CFG1_CONV_MOD_MASK                 /**< ADC group regular sequencer conversion mode */

#define ADC_CFG1_CONV_MOD_SINGLE        (0x0UL << ADC_CFG1_CONV_MOD_POS)       /**< 0x00000000 */
#define ADC_CFG1_CONV_MOD_CONTINUOUS    (0x1UL << ADC_CFG1_CONV_MOD_POS)       /**< 0x00001000 */
#define ADC_CFG1_CONV_MOD_DISCONTINUOUS (0x2UL << ADC_CFG1_CONV_MOD_POS)       /**< 0x00002000 */

#define ADC_CFG1_WAIT_MOD_POS          (14U)
#define ADC_CFG1_WAIT_MOD_MASK         (0x1UL << ADC_CFG1_WAIT_MOD_POS)        /**< 0x00004000 */
#define ADC_CFG1_WAIT_MOD              ADC_CFG1_WAIT_MOD_MASK                  /**< ADC auto wait */

#define ADC_CFG1_TRIG_SEL_POS          (16U)
#define ADC_CFG1_TRIG_SEL_MASK         (0x7UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00070000 */
#define ADC_CFG1_TRIG_SEL              ADC_CFG1_TRIG_SEL_MASK                  /**< ADC group regular external trigger source */

#define ADC_CFG1_TRIG_TIM3_TRGO        (0x2UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00020000 */
#define ADC_CFG1_TRIG_TIM4_TRGO        (0x3UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00030000 */
#define ADC_CFG1_TRIG_TIM5_TRGO        (0x4UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00040000 */
#define ADC_CFG1_TRIG_TIM8_TRGO        (0x5UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00050000 */
#define ADC_CFG1_TRIG_EXTI2            (0x6UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00060000 */
#define ADC_CFG1_TRIG_EXTI11           (0x7UL << ADC_CFG1_TRIG_SEL_POS)        /**< 0x00070000 */

/* Bits for ADC_CFG2 */
#define ADC_CFG2_REF_POS               (0U)
#define ADC_CFG2_REF_MASK              (0x1UL << ADC_CFG2_REF_POS)             /**< 0x00000001 */
#define ADC_CFG2_REF                   ADC_CFG2_REF_MASK                       /**< ADC reference voltage */

#define ADC_CFG2_LFTRG_POS             (8U)
#define ADC_CFG2_LFTRG_MASK            (0x1UL << ADC_CFG2_LFTRG_POS)           /**< 0x00000100 */
#define ADC_CFG2_LFTRG                 ADC_CFG2_LFTRG_MASK                     /**< ADC Low frequency trigger mode enable */

#define ADC_CFG2_VBGREN_POS            (16U)
#define ADC_CFG2_VBGREN_MASK           (0x1UL << ADC_CFG2_VBGREN_POS)          /**< 0x00010000 */
#define ADC_CFG2_VBGREN                ADC_CFG2_VBGREN_MASK                    /**< ADC internal path to VBGR enable */

#define ADC_CFG2_VTSEN_POS             (17U)
#define ADC_CFG2_VTSEN_MASK            (0x1UL << ADC_CFG2_VTSEN_POS)           /**< 0x00020000 */
#define ADC_CFG2_VTSEN                 ADC_CFG2_VTSEN_MASK                     /**< ADC internal path to temperature sensor enable */

#define ADC_CFG2_VBAT_DIV3_POS         (18U)
#define ADC_CFG2_VBAT_DIV3_MASK        (0x1UL << ADC_CFG2_VBAT_DIV3_POS)       /**< 0x00040000 */
#define ADC_CFG2_VBAT_DIV3             ADC_CFG2_VBAT_DIV3_MASK                 /**< ADC internal path to battery voltage enable */

#define ADC_CFG2_VDDA_DIV3_POS         (19U)
#define ADC_CFG2_VDDA_DIV3_MASK        (0x1UL << ADC_CFG2_VDDA_DIV3_POS)       /**< 0x00080000 */
#define ADC_CFG2_VDDA_DIV3             ADC_CFG2_VDDA_DIV3_MASK                 /**< ADC internal path to VDDA voltage enable */

#define ADC_CFG2_PRESC_POS             (24U)
#define ADC_CFG2_PRESC_MASK            (0xFUL << ADC_CFG2_PRESC_POS)           /**< 0x0F000000 */
#define ADC_CFG2_PRESC                 ADC_CFG2_PRESC_MASK                     /**< ADC asynchronous clock prescaler (prescaler only for clock source asynchronous) */
#define ADC_CFG2_PRESC_DIV1            (0x0UL << ADC_CFG2_PRESC_POS)           /**< 0x00000000 */
#define ADC_CFG2_PRESC_DIV2            (0x1UL << ADC_CFG2_PRESC_POS)           /**< 0x01000000 */
#define ADC_CFG2_PRESC_DIV4            (0x2UL << ADC_CFG2_PRESC_POS)           /**< 0x02000000 */
#define ADC_CFG2_PRESC_DIV6            (0x3UL << ADC_CFG2_PRESC_POS)           /**< 0x03000000 */
#define ADC_CFG2_PRESC_DIV8            (0x4UL << ADC_CFG2_PRESC_POS)           /**< 0x04000000 */
#define ADC_CFG2_PRESC_DIV10           (0x5UL << ADC_CFG2_PRESC_POS)           /**< 0x05000000 */
#define ADC_CFG2_PRESC_DIV12           (0x6UL << ADC_CFG2_PRESC_POS)           /**< 0x06000000 */
#define ADC_CFG2_PRESC_DIV16           (0x7UL << ADC_CFG2_PRESC_POS)           /**< 0x07000000 */
#define ADC_CFG2_PRESC_DIV32           (0x8UL << ADC_CFG2_PRESC_POS)           /**< 0x08000000 */
#define ADC_CFG2_PRESC_DIV64           (0x9UL << ADC_CFG2_PRESC_POS)           /**< 0x09000000 */
#define ADC_CFG2_PRESC_DIV128          (0xAUL << ADC_CFG2_PRESC_POS)           /**< 0x0A000000 */

#define ADC_CFG2_CKSRC_POS             (30U)
#define ADC_CFG2_CKSRC_MASK            (0x3UL << ADC_CFG2_CKSRC_POS)           /**< 0xC0000000 */
#define ADC_CFG2_CKSRC                 ADC_CFG2_CKSRC_MASK                     /**< ADC clock source and prescaler (prescaler only for clock source synchronous) */
#define ADC_CFG2_CKSRC_PCLK            (0x0UL << ADC_CFG2_CKSRC_POS)           /**< 0x00000000 */
#define ADC_CFG2_CKSRC_PCLK_DIV2       (0x1UL << ADC_CFG2_CKSRC_POS)           /**< 0x40000000 */
#define ADC_CFG2_CKSRC_PCLK_DIV4       (0x2UL << ADC_CFG2_CKSRC_POS)           /**< 0x80000000 */
#define ADC_CFG2_CKSRC_KCLK            (0x3UL << ADC_CFG2_CKSRC_POS)           /**< 0xC0000000 */

/* Bits for ADC_ISR */
#define ADC_ISR_EOSAMP_POS             (1U)
#define ADC_ISR_EOSAMP_MASK            (0x1UL << ADC_ISR_EOSAMP_POS)           /**< 0x00000002 */
#define ADC_ISR_EOSAMP                 ADC_ISR_EOSAMP_MASK                     /**< ADC group regular end of sampling flag */

#define ADC_ISR_EOC_POS                (2U)
#define ADC_ISR_EOC_MASK               (0x1UL << ADC_ISR_EOC_POS)              /**< 0x00000004 */
#define ADC_ISR_EOC                    ADC_ISR_EOC_MASK                        /**< ADC group regular end of unitary conversion flag */

#define ADC_ISR_EOS_POS                (3U)
#define ADC_ISR_EOS_MASK               (0x1UL << ADC_ISR_EOS_POS)              /**< 0x00000008 */
#define ADC_ISR_EOS                    ADC_ISR_EOS_MASK                        /**< ADC group regular end of sequence conversions flag */

#define ADC_ISR_OVRN_POS               (4U)
#define ADC_ISR_OVRN_MASK              (0x1UL << ADC_ISR_OVRN_POS)             /**< 0x00000010 */
#define ADC_ISR_OVRN                   ADC_ISR_OVRN_MASK                       /**< ADC group regular overrun flag */

#define ADC_ISR_AWDG1_POS              (7U)
#define ADC_ISR_AWDG1_MASK             (0x1UL << ADC_ISR_AWDG1_POS)            /**< 0x00000080 */
#define ADC_ISR_AWDG1                  ADC_ISR_AWDG1_MASK                      /**< ADC analog watchdog 1 flag */

#define ADC_ISR_EOCAL_POS              (11U)
#define ADC_ISR_EOCAL_MASK             (0x1UL << ADC_ISR_EOCAL_POS)            /**< 0x00000800 */
#define ADC_ISR_EOCAL                  ADC_ISR_EOCAL_MASK                      /**< ADC end of calibration flag */

/* Bits for ADC_IER */
#define ADC_IER_EOSAMPIE_POS           (1U)
#define ADC_IER_EOSAMPIE_MASK          (0x1UL << ADC_IER_EOSAMPIE_POS)         /**< 0x00000002 */
#define ADC_IER_EOSAMPIE               ADC_IER_EOSAMPIE_MASK                   /**< ADC group regular end of sampling interrupt */

#define ADC_IER_EOCIE_POS              (2U)
#define ADC_IER_EOCIE_MASK             (0x1UL << ADC_IER_EOCIE_POS)            /**< 0x00000004 */
#define ADC_IER_EOCIE                  ADC_IER_EOCIE_MASK                      /**< ADC group regular end of unitary conversion interrupt */

#define ADC_IER_EOSIE_POS              (3U)
#define ADC_IER_EOSIE_MASK             (0x1UL << ADC_IER_EOSIE_POS)            /**< 0x00000008 */
#define ADC_IER_EOSIE                  ADC_IER_EOSIE_MASK                      /**< ADC group regular end of sequence conversions interrupt */

#define ADC_IER_OVRNIE_POS             (4U)
#define ADC_IER_OVRNIE_MASK            (0x1UL << ADC_IER_OVRNIE_POS)           /**< 0x00000010 */
#define ADC_IER_OVRNIE                 ADC_IER_OVRNIE_MASK                     /**< ADC group regular overrun interrupt */

#define ADC_IER_AWDG1IE_POS             (7U)
#define ADC_IER_AWDG1IE_MASK            (0x1UL << ADC_IER_AWDG1IE_POS)         /**< 0x00000080 */
#define ADC_IER_AWDG1IE                 ADC_IER_AWDG1IE_MASK                   /**< ADC analog watchdog 1 interrupt */

#define ADC_IER_EOCALIE_POS            (11U)
#define ADC_IER_EOCALIE_MASK           (0x1UL << ADC_IER_EOCALIE_POS)          /**< 0x00000800 */
#define ADC_IER_EOCALIE                ADC_IER_EOCALIE_MASK                    /**< ADC end of calibration interrupt */

/* Bits for ADC_SAMPT */
#define ADC_SAMPT_SAMPT1_POS           (0U)
#define ADC_SAMPT_SAMPT1_MASK          (0xFUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000F */
#define ADC_SAMPT_SAMPT1               ADC_SAMPT_SAMPT1_MASK                   /**< ADC group of channels sampling time 1 */
#define ADC_SAMPT_SAMPT1_3CYCLES       (0x1UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000001 */
#define ADC_SAMPT_SAMPT1_7CYCLES       (0x2UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000002 */
#define ADC_SAMPT_SAMPT1_12CYCLES      (0x3UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000003 */
#define ADC_SAMPT_SAMPT1_19CYCLES      (0x4UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000004 */
#define ADC_SAMPT_SAMPT1_39CYCLES      (0x5UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000005 */
#define ADC_SAMPT_SAMPT1_79CYCLES      (0x6UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000006 */
#define ADC_SAMPT_SAMPT1_119CYCLES     (0x7UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000007 */
#define ADC_SAMPT_SAMPT1_159CYCLES     (0x8UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000008 */
#define ADC_SAMPT_SAMPT1_239CYCLES     (0x9UL << ADC_SAMPT_SAMPT1_POS)         /**< 0x00000009 */
#define ADC_SAMPT_SAMPT1_319CYCLES     (0xAUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000A */
#define ADC_SAMPT_SAMPT1_479CYCLES     (0xBUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000B */
#define ADC_SAMPT_SAMPT1_639CYCLES     (0xCUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000C */
#define ADC_SAMPT_SAMPT1_959CYCLES     (0xDUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000D */
#define ADC_SAMPT_SAMPT1_1279CYCLES    (0xEUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000E */
#define ADC_SAMPT_SAMPT1_1919CYCLES    (0xFUL << ADC_SAMPT_SAMPT1_POS)         /**< 0x0000000F */

#define ADC_SAMPT_SAMPT2_POS           (4U)
#define ADC_SAMPT_SAMPT2_MASK          (0xFUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x000000F0 */
#define ADC_SAMPT_SAMPT2               ADC_SAMPT_SAMPT2_MASK                   /**< ADC group of channels sampling time 2 */
#define ADC_SAMPT_SAMPT2_3CYCLES       (0x1UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000001 */
#define ADC_SAMPT_SAMPT2_7CYCLES       (0x2UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000002 */
#define ADC_SAMPT_SAMPT2_12CYCLES      (0x3UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000003 */
#define ADC_SAMPT_SAMPT2_19CYCLES      (0x4UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000004 */
#define ADC_SAMPT_SAMPT2_39CYCLES      (0x5UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000005 */
#define ADC_SAMPT_SAMPT2_79CYCLES      (0x6UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000006 */
#define ADC_SAMPT_SAMPT2_119CYCLES     (0x7UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000007 */
#define ADC_SAMPT_SAMPT2_159CYCLES     (0x8UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000008 */
#define ADC_SAMPT_SAMPT2_239CYCLES     (0x9UL << ADC_SAMPT_SAMPT2_POS)         /**< 0x00000009 */
#define ADC_SAMPT_SAMPT2_319CYCLES     (0xAUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000A */
#define ADC_SAMPT_SAMPT2_479CYCLES     (0xBUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000B */
#define ADC_SAMPT_SAMPT2_639CYCLES     (0xCUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000C */
#define ADC_SAMPT_SAMPT2_959CYCLES     (0xDUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000D */
#define ADC_SAMPT_SAMPT2_1279CYCLES    (0xEUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000E */
#define ADC_SAMPT_SAMPT2_1919CYCLES    (0xFUL << ADC_SAMPT_SAMPT2_POS)         /**< 0x0000000F */

#define ADC_SAMPT_SAMPT_SEL_POS        (8U)
#define ADC_SAMPT_SAMPT_SEL_MASK       (0xFFFFFUL << ADC_SAMPT_SAMPT_SEL_POS)  /**< 0x0FFFFF00 */
#define ADC_SAMPT_SAMPT_SEL            ADC_SAMPT_SAMPT_SEL_MASK                /**< ADC all channels sampling time selection */

#define ADC_SAMPT_SAMPT_SEL0_POS       (8U)
#define ADC_SAMPT_SAMPT_SEL0_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL0_POS)     /**< 0x00000100 */
#define ADC_SAMPT_SAMPT_SEL0           ADC_SAMPT_SAMPT_SEL0_MASK               /**< ADC channel 0 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL1_POS       (9U)
#define ADC_SAMPT_SAMPT_SEL1_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL1_POS)     /**< 0x00000200 */
#define ADC_SAMPT_SAMPT_SEL1           ADC_SAMPT_SAMPT_SEL1_MASK               /**< ADC channel 1 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL2_POS       (10U)
#define ADC_SAMPT_SAMPT_SEL2_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL2_POS)     /**< 0x00000400 */
#define ADC_SAMPT_SAMPT_SEL2           ADC_SAMPT_SAMPT_SEL2_MASK               /**< ADC channel 2 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL3_POS       (11U)
#define ADC_SAMPT_SAMPT_SEL3_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL3_POS)     /**< 0x00000800 */
#define ADC_SAMPT_SAMPT_SEL3           ADC_SAMPT_SAMPT_SEL3_MASK               /**< ADC channel 3 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL4_POS       (12U)
#define ADC_SAMPT_SAMPT_SEL4_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL4_POS)     /**< 0x00001000 */
#define ADC_SAMPT_SAMPT_SEL4           ADC_SAMPT_SAMPT_SEL4_MASK               /**< ADC channel 4 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL5_POS       (13U)
#define ADC_SAMPT_SAMPT_SEL5_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL5_POS)     /**< 0x00002000 */
#define ADC_SAMPT_SAMPT_SEL5           ADC_SAMPT_SAMPT_SEL5_MASK               /**< ADC channel 5 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL6_POS       (14U)
#define ADC_SAMPT_SAMPT_SEL6_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL6_POS)     /**< 0x00004000 */
#define ADC_SAMPT_SAMPT_SEL6           ADC_SAMPT_SAMPT_SEL6_MASK               /**< ADC channel 6 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL7_POS       (15U)
#define ADC_SAMPT_SAMPT_SEL7_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL7_POS)     /**< 0x00008000 */
#define ADC_SAMPT_SAMPT_SEL7           ADC_SAMPT_SAMPT_SEL7_MASK               /**< ADC channel 7 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL8_POS       (16U)
#define ADC_SAMPT_SAMPT_SEL8_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL8_POS)     /**< 0x00010000 */
#define ADC_SAMPT_SAMPT_SEL8           ADC_SAMPT_SAMPT_SEL8_MASK               /**< ADC channel 8 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL9_POS       (17U)
#define ADC_SAMPT_SAMPT_SEL9_MASK      (0x1UL << ADC_SAMPT_SAMPT_SEL9_POS)     /**< 0x00020000 */
#define ADC_SAMPT_SAMPT_SEL9           ADC_SAMPT_SAMPT_SEL9_MASK               /**< ADC channel 9 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL10_POS      (18U)
#define ADC_SAMPT_SAMPT_SEL10_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL10_POS)    /**< 0x00040000 */
#define ADC_SAMPT_SAMPT_SEL10          ADC_SAMPT_SAMPT_SEL10_MASK              /**< ADC channel 10 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL11_POS      (19U)
#define ADC_SAMPT_SAMPT_SEL11_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL11_POS)    /**< 0x00080000 */
#define ADC_SAMPT_SAMPT_SEL11          ADC_SAMPT_SAMPT_SEL11_MASK              /**< ADC channel 11 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL12_POS      (20U)
#define ADC_SAMPT_SAMPT_SEL12_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL12_POS)    /**< 0x00100000 */
#define ADC_SAMPT_SAMPT_SEL12          ADC_SAMPT_SAMPT_SEL12_MASK              /**< ADC channel 12 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL13_POS      (21U)
#define ADC_SAMPT_SAMPT_SEL13_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL13_POS)    /**< 0x00200000 */
#define ADC_SAMPT_SAMPT_SEL13          ADC_SAMPT_SAMPT_SEL13_MASK              /**< ADC channel 13 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL14_POS      (22U)
#define ADC_SAMPT_SAMPT_SEL14_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL14_POS)    /**< 0x00400000 */
#define ADC_SAMPT_SAMPT_SEL14          ADC_SAMPT_SAMPT_SEL14_MASK              /**< ADC channel 14 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL15_POS      (23U)
#define ADC_SAMPT_SAMPT_SEL15_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL15_POS)    /**< 0x00800000 */
#define ADC_SAMPT_SAMPT_SEL15          ADC_SAMPT_SAMPT_SEL15_MASK              /**< ADC channel 15 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL16_POS      (24U)
#define ADC_SAMPT_SAMPT_SEL16_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL16_POS)    /**< 0x01000000 */
#define ADC_SAMPT_SAMPT_SEL16          ADC_SAMPT_SAMPT_SEL16_MASK              /**< ADC channel 16 sampling time selection */

#define ADC_SAMPT_SAMPT_SEL19_POS      (27U)
#define ADC_SAMPT_SAMPT_SEL19_MASK     (0x1UL << ADC_SAMPT_SAMPT_SEL19_POS)    /**< 0x08000000 */
#define ADC_SAMPT_SAMPT_SEL19          ADC_SAMPT_SAMPT_SEL19_MASK              /**< ADC channel 19 sampling time selection */

/* Bits for ADC_CHCFG */
#define ADC_CHCFG_CHN_POS              (0U)
#define ADC_CHCFG_CHN_MASK             (0xFFFFFUL << ADC_CHCFG_CHN_POS)        /**< 0x000FFFFF */
#define ADC_CHCFG_CHN                  ADC_CHCFG_CHN_MASK                      /**< ADC group regular sequencer channels */

#define ADC_CHCFG_CHN0_POS             (0U)
#define ADC_CHCFG_CHN0_MASK            (0x1UL << ADC_CHCFG_CHN0_POS)           /**< 0x00000001 */
#define ADC_CHCFG_CHN0                 ADC_CHCFG_CHN0_MASK                     /**< ADC group regular sequencer channel 0 */

#define ADC_CHCFG_CHN1_POS             (1U)
#define ADC_CHCFG_CHN1_MASK            (0x1UL << ADC_CHCFG_CHN1_POS)           /**< 0x00000002 */
#define ADC_CHCFG_CHN1                 ADC_CHCFG_CHN1_MASK                     /**< ADC group regular sequencer channel 1 */

#define ADC_CHCFG_CHN2_POS             (2U)
#define ADC_CHCFG_CHN2_MASK            (0x1UL << ADC_CHCFG_CHN2_POS)           /**< 0x00000004 */
#define ADC_CHCFG_CHN2                 ADC_CHCFG_CHN2_MASK                     /**< ADC group regular sequencer channel 2 */

#define ADC_CHCFG_CHN3_POS             (3U)
#define ADC_CHCFG_CHN3_MASK            (0x1UL << ADC_CHCFG_CHN3_POS)           /**< 0x00000008 */
#define ADC_CHCFG_CHN3                 ADC_CHCFG_CHN3_MASK                     /**< ADC group regular sequencer channel 3 */

#define ADC_CHCFG_CHN4_POS             (4U)
#define ADC_CHCFG_CHN4_MASK            (0x1UL << ADC_CHCFG_CHN4_POS)           /**< 0x00000010 */
#define ADC_CHCFG_CHN4                 ADC_CHCFG_CHN4_MASK                     /**< ADC group regular sequencer channel 4 */

#define ADC_CHCFG_CHN5_POS             (5U)
#define ADC_CHCFG_CHN5_MASK            (0x1UL << ADC_CHCFG_CHN5_POS)           /**< 0x00000020 */
#define ADC_CHCFG_CHN5                 ADC_CHCFG_CHN5_MASK                     /**< ADC group regular sequencer channel 5 */

#define ADC_CHCFG_CHN6_POS             (6U)
#define ADC_CHCFG_CHN6_MASK            (0x1UL << ADC_CHCFG_CHN6_POS)           /**< 0x00000040 */
#define ADC_CHCFG_CHN6                 ADC_CHCFG_CHN6_MASK                     /**< ADC group regular sequencer channel 6 */

#define ADC_CHCFG_CHN7_POS             (7U)
#define ADC_CHCFG_CHN7_MASK            (0x1UL << ADC_CHCFG_CHN7_POS)           /**< 0x00000080 */
#define ADC_CHCFG_CHN7                 ADC_CHCFG_CHN7_MASK                     /**< ADC group regular sequencer channel 7 */

#define ADC_CHCFG_CHN8_POS             (8U)
#define ADC_CHCFG_CHN8_MASK            (0x1UL << ADC_CHCFG_CHN8_POS)           /**< 0x00000100 */
#define ADC_CHCFG_CHN8                 ADC_CHCFG_CHN8_MASK                     /**< ADC group regular sequencer channel 8 */

#define ADC_CHCFG_CHN9_POS             (9U)
#define ADC_CHCFG_CHN9_MASK            (0x1UL << ADC_CHCFG_CHN9_POS)           /**< 0x00000200 */
#define ADC_CHCFG_CHN9                 ADC_CHCFG_CHN9_MASK                     /**< ADC group regular sequencer channel 9 */

#define ADC_CHCFG_CHN10_POS            (10U)
#define ADC_CHCFG_CHN10_MASK           (0x1UL << ADC_CHCFG_CHN10_POS)          /**< 0x00000400 */
#define ADC_CHCFG_CHN10                ADC_CHCFG_CHN10_MASK                    /**< ADC group regular sequencer channel 10 */

#define ADC_CHCFG_CHN11_POS            (11U)
#define ADC_CHCFG_CHN11_MASK           (0x1UL << ADC_CHCFG_CHN11_POS)          /**< 0x00000800 */
#define ADC_CHCFG_CHN11                ADC_CHCFG_CHN11_MASK                    /**< ADC group regular sequencer channel 11 */

#define ADC_CHCFG_CHN12_POS            (12U)
#define ADC_CHCFG_CHN12_MASK           (0x1UL << ADC_CHCFG_CHN12_POS)          /**< 0x00001000 */
#define ADC_CHCFG_CHN12                ADC_CHCFG_CHN12_MASK                    /**< ADC group regular sequencer channel 12 */

#define ADC_CHCFG_CHN13_POS            (13U)
#define ADC_CHCFG_CHN13_MASK           (0x1UL << ADC_CHCFG_CHN13_POS)          /**< 0x00002000 */
#define ADC_CHCFG_CHN13                ADC_CHCFG_CHN13_MASK                    /**< ADC group regular sequencer channel 13 */

#define ADC_CHCFG_CHN14_POS            (14U)
#define ADC_CHCFG_CHN14_MASK           (0x1UL << ADC_CHCFG_CHN14_POS)          /**< 0x00004000 */
#define ADC_CHCFG_CHN14                ADC_CHCFG_CHN14_MASK                    /**< ADC group regular sequencer channel 14 */

#define ADC_CHCFG_CHN15_POS            (15U)
#define ADC_CHCFG_CHN15_MASK           (0x1UL << ADC_CHCFG_CHN15_POS)          /**< 0x00008000 */
#define ADC_CHCFG_CHN15                ADC_CHCFG_CHN15_MASK                    /**< ADC group regular sequencer channel 15 */

#define ADC_CHCFG_CHN16_POS            (16U)
#define ADC_CHCFG_CHN16_MASK           (0x1UL << ADC_CHCFG_CHN16_POS)          /**< 0x00010000 */
#define ADC_CHCFG_CHN16                ADC_CHCFG_CHN16_MASK                    /**< ADC group regular sequencer channel 16 */

#define ADC_CHCFG_CHN19_POS            (19U)
#define ADC_CHCFG_CHN19_MASK           (0x1UL << ADC_CHCFG_CHN19_POS)          /**< 0x00080000 */
#define ADC_CHCFG_CHN19                ADC_CHCFG_CHN19_MASK                    /**< ADC group regular sequencer channel 19 */

/* Bits for ADC_AWDG1CR */
#define ADC_AWDG1CR_AWDG1_CHN_POS        (0U)
#define ADC_AWDG1CR_AWDG1_CHN_MASK       (0xFFFFFUL << ADC_AWDG1CR_AWDG1_CHN_POS)  /**< 0x000FFFFF */
#define ADC_AWDG1CR_AWDG1_CHN            ADC_AWDG1CR_AWDG1_CHN_MASK                /**< ADC analog watchdog 1 monitored channel selection */

#define ADC_AWDG1CR_AWDG1_CHN0_POS       (0U)
#define ADC_AWDG1CR_AWDG1_CHN0_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN0_POS)     /**< 0x00000001 */
#define ADC_AWDG1CR_AWDG1_CHN0           ADC_AWDG1CR_AWDG1_CHN0_MASK               /**< ADC analog watchdog 1 monitored channel 0 */

#define ADC_AWDG1CR_AWDG1_CHN1_POS       (1U)
#define ADC_AWDG1CR_AWDG1_CHN1_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN1_POS)     /**< 0x00000002 */
#define ADC_AWDG1CR_AWDG1_CHN1           ADC_AWDG1CR_AWDG1_CHN1_MASK               /**< ADC analog watchdog 1 monitored channel 1 */

#define ADC_AWDG1CR_AWDG1_CHN2_POS       (2U)
#define ADC_AWDG1CR_AWDG1_CHN2_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN2_POS)     /**< 0x00000004 */
#define ADC_AWDG1CR_AWDG1_CHN2           ADC_AWDG1CR_AWDG1_CHN2_MASK               /**< ADC analog watchdog 1 monitored channel 2 */

#define ADC_AWDG1CR_AWDG1_CHN3_POS       (3U)
#define ADC_AWDG1CR_AWDG1_CHN3_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN3_POS)     /**< 0x00000008 */
#define ADC_AWDG1CR_AWDG1_CHN3           ADC_AWDG1CR_AWDG1_CHN3_MASK               /**< ADC analog watchdog 1 monitored channel 3 */

#define ADC_AWDG1CR_AWDG1_CHN4_POS       (4U)
#define ADC_AWDG1CR_AWDG1_CHN4_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN4_POS)     /**< 0x00000010 */
#define ADC_AWDG1CR_AWDG1_CHN4           ADC_AWDG1CR_AWDG1_CHN4_MASK               /**< ADC analog watchdog 1 monitored channel 4 */

#define ADC_AWDG1CR_AWDG1_CHN5_POS       (5U)
#define ADC_AWDG1CR_AWDG1_CHN5_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN5_POS)     /**< 0x00000020 */
#define ADC_AWDG1CR_AWDG1_CHN5           ADC_AWDG1CR_AWDG1_CHN5_MASK               /**< ADC analog watchdog 1 monitored channel 5 */

#define ADC_AWDG1CR_AWDG1_CHN6_POS       (6U)
#define ADC_AWDG1CR_AWDG1_CHN6_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN6_POS)     /**< 0x00000040 */
#define ADC_AWDG1CR_AWDG1_CHN6           ADC_AWDG1CR_AWDG1_CHN6_MASK               /**< ADC analog watchdog 1 monitored channel 6 */

#define ADC_AWDG1CR_AWDG1_CHN7_POS       (7U)
#define ADC_AWDG1CR_AWDG1_CHN7_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN7_POS)     /**< 0x00000080 */
#define ADC_AWDG1CR_AWDG1_CHN7           ADC_AWDG1CR_AWDG1_CHN7_MASK               /**< ADC analog watchdog 1 monitored channel 7 */

#define ADC_AWDG1CR_AWDG1_CHN8_POS       (8U)
#define ADC_AWDG1CR_AWDG1_CHN8_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN8_POS)     /**< 0x00000100 */
#define ADC_AWDG1CR_AWDG1_CHN8           ADC_AWDG1CR_AWDG1_CHN8_MASK               /**< ADC analog watchdog 1 monitored channel 8 */

#define ADC_AWDG1CR_AWDG1_CHN9_POS       (9U)
#define ADC_AWDG1CR_AWDG1_CHN9_MASK      (0x1UL << ADC_AWDG1CR_AWDG1_CHN9_POS)     /**< 0x00000200 */
#define ADC_AWDG1CR_AWDG1_CHN9           ADC_AWDG1CR_AWDG1_CHN9_MASK               /**< ADC analog watchdog 1 monitored channel 9 */

#define ADC_AWDG1CR_AWDG1_CHN10_POS      (10U)
#define ADC_AWDG1CR_AWDG1_CHN10_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN10_POS)    /**< 0x00000400 */
#define ADC_AWDG1CR_AWDG1_CHN10          ADC_AWDG1CR_AWDG1_CHN10_MASK              /**< ADC analog watchdog 1 monitored channel 10 */

#define ADC_AWDG1CR_AWDG1_CHN11_POS      (11U)
#define ADC_AWDG1CR_AWDG1_CHN11_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN11_POS)    /**< 0x00000800 */
#define ADC_AWDG1CR_AWDG1_CHN11          ADC_AWDG1CR_AWDG1_CHN11_MASK              /**< ADC analog watchdog 1 monitored channel 11 */

#define ADC_AWDG1CR_AWDG1_CHN12_POS      (12U)
#define ADC_AWDG1CR_AWDG1_CHN12_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN12_POS)    /**< 0x00001000 */
#define ADC_AWDG1CR_AWDG1_CHN12          ADC_AWDG1CR_AWDG1_CHN12_MASK              /**< ADC analog watchdog 1 monitored channel 12 */

#define ADC_AWDG1CR_AWDG1_CHN13_POS      (13U)
#define ADC_AWDG1CR_AWDG1_CHN13_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN13_POS)    /**< 0x00002000 */
#define ADC_AWDG1CR_AWDG1_CHN13          ADC_AWDG1CR_AWDG1_CHN13_MASK              /**< ADC analog watchdog 1 monitored channel 13 */

#define ADC_AWDG1CR_AWDG1_CHN14_POS      (14U)
#define ADC_AWDG1CR_AWDG1_CHN14_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN14_POS)    /**< 0x00004000 */
#define ADC_AWDG1CR_AWDG1_CHN14          ADC_AWDG1CR_AWDG1_CHN14_MASK              /**< ADC analog watchdog 1 monitored channel 14 */

#define ADC_AWDG1CR_AWDG1_CHN15_POS      (15U)
#define ADC_AWDG1CR_AWDG1_CHN15_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN15_POS)    /**< 0x00008000 */
#define ADC_AWDG1CR_AWDG1_CHN15          ADC_AWDG1CR_AWDG1_CHN15_MASK              /**< ADC analog watchdog 1 monitored channel 15 */

#define ADC_AWDG1CR_AWDG1_CHN16_POS      (16U)
#define ADC_AWDG1CR_AWDG1_CHN16_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN16_POS)    /**< 0x00010000 */
#define ADC_AWDG1CR_AWDG1_CHN16          ADC_AWDG1CR_AWDG1_CHN16_MASK              /**< ADC analog watchdog 1 monitored channel 16 */

#define ADC_AWDG1CR_AWDG1_CHN19_POS      (19U)
#define ADC_AWDG1CR_AWDG1_CHN19_MASK     (0x1UL << ADC_AWDG1CR_AWDG1_CHN19_POS)    /**< 0x00080000 */
#define ADC_AWDG1CR_AWDG1_CHN19          ADC_AWDG1CR_AWDG1_CHN19_MASK              /**< ADC analog watchdog 1 monitored channel 19 */

/* Bits for ADC_AWDG1TR */
#define ADC_AWDG1TR_AWDG1_LT_POS         (0U)
#define ADC_AWDG1TR_AWDG1_LT_MASK        (0xFFFUL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000FFF */
#define ADC_AWDG1TR_AWDG1_LT             ADC_AWDG1TR_AWDG1_LT_MASK                 /**< ADC analog watchdog 1 threshold low */

#define ADC_AWDG1TR_AWDG1_LT_0           (0x001UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000001 */
#define ADC_AWDG1TR_AWDG1_LT_1           (0x002UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000002 */
#define ADC_AWDG1TR_AWDG1_LT_2           (0x004UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000004 */
#define ADC_AWDG1TR_AWDG1_LT_3           (0x008UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000008 */
#define ADC_AWDG1TR_AWDG1_LT_4           (0x010UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000010 */
#define ADC_AWDG1TR_AWDG1_LT_5           (0x020UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000020 */
#define ADC_AWDG1TR_AWDG1_LT_6           (0x040UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000040 */
#define ADC_AWDG1TR_AWDG1_LT_7           (0x080UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000080 */
#define ADC_AWDG1TR_AWDG1_LT_8           (0x100UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000100 */
#define ADC_AWDG1TR_AWDG1_LT_9           (0x200UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000200 */
#define ADC_AWDG1TR_AWDG1_LT_10          (0x400UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000400 */
#define ADC_AWDG1TR_AWDG1_LT_11          (0x800UL << ADC_AWDG1TR_AWDG1_LT_POS)     /**< 0x00000800 */

#define ADC_AWDG1TR_AWDG1_HT_POS         (16U)
#define ADC_AWDG1TR_AWDG1_HT_MASK        (0xFFFUL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x0FFF0000 */
#define ADC_AWDG1TR_AWDG1_HT             ADC_AWDG1TR_AWDG1_HT_MASK                 /**< ADC Analog watchdog 1 threshold high */

#define ADC_AWDG1TR_AWDG1_HT_0           (0x001UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00010000 */
#define ADC_AWDG1TR_AWDG1_HT_1           (0x002UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00020000 */
#define ADC_AWDG1TR_AWDG1_HT_2           (0x004UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00040000 */
#define ADC_AWDG1TR_AWDG1_HT_3           (0x008UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00080000 */
#define ADC_AWDG1TR_AWDG1_HT_4           (0x010UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00100000 */
#define ADC_AWDG1TR_AWDG1_HT_5           (0x020UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00200000 */
#define ADC_AWDG1TR_AWDG1_HT_6           (0x040UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00400000 */
#define ADC_AWDG1TR_AWDG1_HT_7           (0x080UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x00800000 */
#define ADC_AWDG1TR_AWDG1_HT_8           (0x100UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x01000000 */
#define ADC_AWDG1TR_AWDG1_HT_9           (0x200UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x02000000 */
#define ADC_AWDG1TR_AWDG1_HT_10          (0x400UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x04000000 */
#define ADC_AWDG1TR_AWDG1_HT_11          (0x800UL << ADC_AWDG1TR_AWDG1_HT_POS)     /**< 0x08000000 */

/* Bits for ADC_CALFACT */
#define ADC_CALFACT_CALFACT_POS         (0U)
#define ADC_CALFACT_CALFACT_MASK        (0x3FUL << ADC_CALFACT_CALFACT_POS)        /**< 0x0000003F */
#define ADC_CALFACT_CALFACT             ADC_CALFACT_CALFACT_MASK                   /**< ADC calibration factor in single-ended mode */
#define ADC_CALFACT_CALFACT_0           (0x01UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000001 */
#define ADC_CALFACT_CALFACT_1           (0x02UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000002 */
#define ADC_CALFACT_CALFACT_2           (0x04UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000004 */
#define ADC_CALFACT_CALFACT_3           (0x08UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000008 */
#define ADC_CALFACT_CALFACT_4           (0x10UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000010 */
#define ADC_CALFACT_CALFACT_5           (0x20UL << ADC_CALFACT_CALFACT_POS)        /**< 0x00000020 */

/* Bits for ADC_DR */
#define ADC_DR_DATA_POS                 (0U)
#define ADC_DR_DATA_MASK                (0xFFFUL << ADC_DR_DATA_POS)               /**< 0x00000FFF */
#define ADC_DR_DATA                     ADC_DR_DATA_MASK                           /**< ADC group regular conversion data */


/*-----------------------------------------------------------------------------------------------
                                       AES Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for AES_CR */
#define AES_CR_DATA_TYPE_POS           (5U)
#define AES_CR_DATA_TYPE_MASK          (0x3UL << AES_CR_DATA_TYPE_POS)         /**< 0x00000060 */
#define AES_CR_DATA_TYPE               AES_CR_DATA_TYPE_MASK                   /**< Data type selection */
#define AES_CR_DATA_TYPE_NONE          (0x0UL << AES_CR_DATA_TYPE_POS)         /**< 0x00000000 */
#define AES_CR_DATA_TYPE_16BIT         (0x1UL << AES_CR_DATA_TYPE_POS)         /**< 0x00000020 */
#define AES_CR_DATA_TYPE_8BIT          (0x2UL << AES_CR_DATA_TYPE_POS)         /**< 0x00000040 */
#define AES_CR_DATA_TYPE_BIT           (0x3UL << AES_CR_DATA_TYPE_POS)         /**< 0x00000060 */

#define AES_CR_MOD_SEL_POS             (7U)
#define AES_CR_MOD_SEL_MASK            (0x1UL << AES_CR_MOD_SEL_POS)           /**< 0x00000080 */
#define AES_CR_MOD_SEL                 AES_CR_MOD_SEL_MASK                     /**< AES Mode Of Operation */
#define AES_CR_MOD_SEL_ENC             (0x0UL << AES_CR_MOD_SEL_POS)           /**< 0x00000000 */
#define AES_CR_MOD_SEL_DEC             (0x1UL << AES_CR_MOD_SEL_POS)           /**< 0x00000080 */


/* Bit for AES_CSR */
#define AES_CSR_DONE_POS               (4U)
#define AES_CSR_DONE_MASK              (0x1UL << AES_CSR_DONE_POS)             /**< 0x00000010 */
#define AES_CSR_DONE                   AES_CSR_DONE_MASK                       /**< AES Complete Flag */

#define AES_CSR_DMAIN_EN_POS           (5U)
#define AES_CSR_DMAIN_EN_MASK          (0x3UL << AES_CSR_DMAIN_EN_POS)         /**< 0x00000020 */
#define AES_CSR_DMAIN_EN               AES_CSR_DMAIN_EN_MASK                   /**< AES DMA IN Enable */

#define AES_CSR_DMAOUT_EN_POS          (6U)
#define AES_CSR_DMAOUT_EN_MASK         (0x1UL << AES_CSR_DMAOUT_EN_POS)        /**< 0x00000040 */
#define AES_CSR_DMAOUT_EN              AES_CSR_DMAOUT_EN_MASK                  /**< AES DMA_OUT Enable */

#define AES_CSR_BUSY_POS               (7U)
#define AES_CSR_BUSY_MASK              (0x1UL << AES_CSR_BUSY_POS)             /**< 0x00000080 */
#define AES_CSR_BUSY                   AES_CSR_BUSY_MASK                       /**< AES Caclulte busy */

#define AES_CSR_CCIE_POS               (8U)
#define AES_CSR_CCIE_MASK              (0x1UL << AES_CSR_CCIE_POS)             /**< 0x00000100 */
#define AES_CSR_CCIE                   AES_CSR_CCIE_MASK                       /**< AES Complete Interrupt Enable */

#define AES_CSR_CCFC_POS               (10U)
#define AES_CSR_CCFC_MASK              (0x1UL << AES_CSR_CCFC_POS)             /**< 0x00000400 */
#define AES_CSR_CCFC                   AES_CSR_CCFC_MASK                       /**< AES Complete Flag Clear */

/* Bits for AES_KEYR */
#define AES_KEYR_POS                   (0U)
#define AES_KEYR_MASK                  (0xFFFFFFFFUL << AES_KEYR_POS)          /**< 0xFFFFFFFF */
#define AES_KEYR                       AES_KEYR_MASK                           /**< AES Key Register   */

/* Bits for AES_DR */
#define AES_DR_POS                     (0U)
#define AES_DR_MASK                    (0xFFFFFFFFUL << AES_DR_POS)            /**< 0xFFFFFFFF */
#define AES_DR                         AES_DR_MASK                             /**< AES Data Register  */

/*-----------------------------------------------------------------------------------------------
                                       COMP Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for COMP_CSR */
#define COMP_CSR_EN_POS            (0U)
#define COMP_CSR_EN_MASK           (0x1UL << COMP_CSR_EN_POS)                  /**< 0x00000001 */
#define COMP_CSR_EN                COMP_CSR_EN_MASK                            /**< Comparator enable */

#define COMP_CSR_INM_POS           (4U)
#define COMP_CSR_INM_MASK          (0x7UL << COMP_CSR_INM_POS)                 /**< 0x00000070 */
#define COMP_CSR_INM               COMP_CSR_INM_MASK                           /**< Comparator input minus selection */
#define COMP_CSR_INM_VBGR          (0x1UL << COMP_CSR_INM_POS)                 /**< 0x00000010 */
#define COMP_CSR_INM_6BIT_DAC      (0x2UL << COMP_CSR_INM_POS)                 /**< 0x00000020 */
#define COMP_CSR_INM_IO1           (0x3UL << COMP_CSR_INM_POS)                 /**< 0x00000030 */
#define COMP_CSR_INM_IO2           (0x4UL << COMP_CSR_INM_POS)                 /**< 0x00000040 */
#define COMP_CSR_INM_IO3           (0x5UL << COMP_CSR_INM_POS)                 /**< 0x00000050 */
#define COMP_CSR_INM_IO4           (0x6UL << COMP_CSR_INM_POS)                 /**< 0x00000060 */

#define COMP_CSR_INP_POS           (8U)
#define COMP_CSR_INP_MASK          (0x3UL << COMP_CSR_INP_POS)                 /**< 0x00000300 */
#define COMP_CSR_INP               COMP_CSR_INP_MASK                           /**< Comparator input plus selection */
#define COMP_CSR_INP_IO1           (0x0UL << COMP_CSR_INP_POS)                 /**< 0x00000000 */
#define COMP_CSR_INP_IO2           (0x1UL << COMP_CSR_INP_POS)                 /**< 0x00000100 */
#define COMP_CSR_INP_IO3           (0x2UL << COMP_CSR_INP_POS)                 /**< 0x00000200 */
#define COMP_CSR_INP_IO4           (0x3UL << COMP_CSR_INP_POS)                 /**< 0x00000300 */

#define COMP_CSR_INPMOD_POS        (13U)
#define COMP_CSR_INPMOD_MASK       (0x1UL << COMP_CSR_INPMOD_POS)              /**< 0x00002000 */
#define COMP_CSR_INPMOD            COMP_CSR_INPMOD_MASK                        /**< Pair of comparators window mode. */

#define COMP_CSR_OUTMOD_POS        (14U)
#define COMP_CSR_OUTMOD_MASK       (0x1UL << COMP_CSR_OUTMOD_POS)              /**< 0x00004000 */
#define COMP_CSR_OUTMOD            COMP_CSR_OUTMOD_MASK                        /**< Pair of comparators window output level. */

#define COMP_CSR_POL_POS           (15U)
#define COMP_CSR_POL_MASK          (0x1UL << COMP_CSR_POL_POS)                 /**< 0x00008000 */
#define COMP_CSR_POL               COMP_CSR_POL_MASK                           /**< Comparator output polarity */

#define COMP_CSR_HYST_POS          (16U)
#define COMP_CSR_HYST_MASK         (0x3UL << COMP_CSR_HYST_POS)                /**< 0x00030000 */
#define COMP_CSR_HYST              COMP_CSR_HYST_MASK                          /**< Comparator input hysteresis */
#define COMP_CSR_HYST_NONE         (0x0UL << COMP_CSR_HYST_POS)                /**< 0x00000000 */
#define COMP_CSR_HYST_LOW          (0x1UL << COMP_CSR_HYST_POS)                /**< 0x00010000 */
#define COMP_CSR_HYST_MEDIUM       (0x2UL << COMP_CSR_HYST_POS)                /**< 0x00020000 */
#define COMP_CSR_HYST_HIGH         (0x3UL << COMP_CSR_HYST_POS)                /**< 0x00030000 */

#define COMP_CSR_SPEED_POS         (18U)
#define COMP_CSR_SPEED_MASK        (0x3UL << COMP_CSR_SPEED_POS)               /**< 0x000C0000 */
#define COMP_CSR_SPEED             COMP_CSR_SPEED_MASK                         /**< Comparator speed mode */
#define COMP_CSR_HIGH_SPEED        (0x0UL << COMP_CSR_SPEED_POS)               /**< 0x00000000 */
#define COMP_CSR_MEDIUM_SPEED      (0x1UL << COMP_CSR_SPEED_POS)               /**< 0x00040000 */
#define COMP_CSR_LOW_SPEED         (0x2UL << COMP_CSR_SPEED_POS)               /**< 0x00080000 */
#define COMP_CSR_VERY_LOW_SPEED    (0x3UL << COMP_CSR_SPEED_POS)               /**< 0x000C0000 */

#define COMP_CSR_FLTIME_POS        (25U)
#define COMP_CSR_FLTIME_MASK       (0x7UL << COMP_CSR_FLTIME_POS)             /**< 0x0E000000 */
#define COMP_CSR_FLTIME            COMP_CSR_FLTIME_MASK                        /**< Comparator filtering time */
#define COMP_CSR_FLTIME_2CYCLE     (0x0UL << COMP_CSR_FLTIME_POS)              /**< 0x00000000 */
#define COMP_CSR_FLTIME_4CYCLE     (0x1UL << COMP_CSR_FLTIME_POS)              /**< 0x02000000 */
#define COMP_CSR_FLTIME_8CYCLE     (0x2UL << COMP_CSR_FLTIME_POS)              /**< 0x04000000 */
#define COMP_CSR_FLTIME_16CYCLE    (0x3UL << COMP_CSR_FLTIME_POS)              /**< 0x06000000 */
#define COMP_CSR_FLTIME_32CYCLE    (0x4UL << COMP_CSR_FLTIME_POS)              /**< 0x08000000 */
#define COMP_CSR_FLTIME_64CYCLE    (0x5UL << COMP_CSR_FLTIME_POS)              /**< 0x0A000000 */
#define COMP_CSR_FLTIME_128CYCLE   (0x6UL << COMP_CSR_FLTIME_POS)              /**< 0x0C000000 */
#define COMP_CSR_FLTIME_256CYCLE   (0x7UL << COMP_CSR_FLTIME_POS)              /**< 0x0E000000 */

#define COMP_CSR_FLTEN_POS         (28U)
#define COMP_CSR_FLTEN_MASK        (0x1UL << COMP_CSR_FLTEN_POS)              /**< 0x10000000 */
#define COMP_CSR_FLTEN              COMP_CSR_FLTEN_MASK                        /**< Comparator filtering enable */

#define COMP_CSR_VAL_POS           (30U)
#define COMP_CSR_VAL_MASK          (0x1UL << COMP_CSR_VAL_POS)                 /**< 0x40000000 */
#define COMP_CSR_VAL               COMP_CSR_VAL_MASK                           /**< Comparator output level */

#define COMP_CSR_LOCK_POS          (31U)
#define COMP_CSR_LOCK_MASK         (0x1UL << COMP_CSR_LOCK_POS)                /**< 0x80000000 */
#define COMP_CSR_LOCK              COMP_CSR_LOCK_MASK                          /**< Comparator lock */

/*-----------------------------------------------------------------------------------------------
                                       CRC Registers Bits  
------------------------------------------------------------------------------------------------*/

/* Bits for CRC_CSR */
#define CRC_CSR_POLY_SIZE_POS      (0U)
#define CRC_CSR_POLY_SIZE_MASK     (0x1UL << CRC_CSR_POLY_SIZE_POS)            /**< 0x00000001 */
#define CRC_CSR_POLY_SIZE          CRC_CSR_POLY_SIZE_MASK                      /**< Polynomial size bits */
#define CRC_CSR_POLY_SIZE_16       (0x0UL << CRC_CSR_POLY_SIZE_POS)            /**< 0x00000000 */
#define CRC_CSR_POLY_SIZE_32       (0x1UL << CRC_CSR_POLY_SIZE_POS)            /**< 0x00000001 */

#define CRC_CSR_CHK_FLAG_POS       (1U)
#define CRC_CSR_CHK_FLAG_MASK      (0x1UL << CRC_CSR_CHK_FLAG_POS)             /**< 0x00000002 */
#define CRC_CSR_CHK_FLAG           CRC_CSR_CHK_FLAG_MASK                       /**< Check result flag bits */

/* Bits for CRC_RDR */
#define CRC_RDR_RESULT_POS         (0U)
#define CRC_RDR_RESULT_MASK        (0xFFFFFFFFUL << CRC_RDR_RESULT_POS)        /**< 0xFFFFFFFF */
#define CRC_RDR_RESULT             CRC_RDR_RESULT_MASK                         /**< Result data register bits */

/* Bits for CRC_DR */
#define CRC_DR_DATA_POS            (0U)
#define CRC_DR_DATA_MASK           (0xFFUL << CRC_DR_DATA_POS)                 /**< 0x000000FF */
#define CRC_DR_DATA                CRC_DR_DATA_MASK                            /**< Data register bits */

/*-----------------------------------------------------------------------------------------------
                                       DBG Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for DBG_CR */
#define DBG_CR_DBG_STOP_POS                            (0U)
#define DBG_CR_DBG_STOP_MASK                           (0x1UL << DBG_CR_DBG_STOP_POS)             /**< 0x00000001 */
#define DBG_CR_DBG_STOP                                DBG_CR_DBG_STOP_MASK

/* Bits for DBG_APB1_FZ */
#define DBG_APB1_FZ_DBG_TIM3_HOLD_POS                  (1U)
#define DBG_APB1_FZ_DBG_TIM3_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_TIM3_HOLD_POS)   /**< 0x00000002 */
#define DBG_APB1_FZ_DBG_TIM3_HOLD                      DBG_APB1_FZ_DBG_TIM3_HOLD_MASK
#define DBG_APB1_FZ_DBG_TIM4_HOLD_POS                  (2U)
#define DBG_APB1_FZ_DBG_TIM4_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_TIM4_HOLD_POS)   /**< 0x00000004 */
#define DBG_APB1_FZ_DBG_TIM4_HOLD                      DBG_APB1_FZ_DBG_TIM4_HOLD_MASK
#define DBG_APB1_FZ_DBG_TIM5_HOLD_POS                  (3U)
#define DBG_APB1_FZ_DBG_TIM5_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_TIM5_HOLD_POS)   /**< 0x00000008 */
#define DBG_APB1_FZ_DBG_TIM5_HOLD                      DBG_APB1_FZ_DBG_TIM5_HOLD_MASK
#define DBG_APB1_FZ_DBG_TIM8_HOLD_POS                  (6U)
#define DBG_APB1_FZ_DBG_TIM8_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_TIM8_HOLD_POS)   /**< 0x00000040 */
#define DBG_APB1_FZ_DBG_TIM8_HOLD                      DBG_APB1_FZ_DBG_TIM8_HOLD_MASK
#define DBG_APB1_FZ_DBG_RTC_HOLD_POS                   (16U)
#define DBG_APB1_FZ_DBG_RTC_HOLD_MASK                  (0x1UL << DBG_APB1_FZ_DBG_RTC_HOLD_POS)    /**< 0x00010000 */
#define DBG_APB1_FZ_DBG_RTC_HOLD                       DBG_APB1_FZ_DBG_RTC_HOLD_MASK
#define DBG_APB1_FZ_DBG_WWDG_HOLD_POS                  (17U)
#define DBG_APB1_FZ_DBG_WWDG_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_WWDG_HOLD_POS)   /**< 0x00020000 */
#define DBG_APB1_FZ_DBG_WWDG_HOLD                      DBG_APB1_FZ_DBG_WWDG_HOLD_MASK
#define DBG_APB1_FZ_DBG_IWDG_HOLD_POS                  (18U)
#define DBG_APB1_FZ_DBG_IWDG_HOLD_MASK                 (0x1UL << DBG_APB1_FZ_DBG_IWDG_HOLD_POS)   /**< 0x00040000 */
#define DBG_APB1_FZ_DBG_IWDG_HOLD                      DBG_APB1_FZ_DBG_IWDG_HOLD_MASK
#define DBG_APB1_FZ_DBG_LPTIM1_HOLD_POS                (29U)
#define DBG_APB1_FZ_DBG_LPTIM1_HOLD_MASK               (0x1UL << DBG_APB1_FZ_DBG_LPTIM1_HOLD_POS) /**< 0x20000000 */
#define DBG_APB1_FZ_DBG_LPTIM1_HOLD                    DBG_APB1_FZ_DBG_LPTIM1_HOLD_MASK
#define DBG_APB1_FZ_DBG_LPTIM2_HOLD_POS                (30U)
#define DBG_APB1_FZ_DBG_LPTIM2_HOLD_MASK               (0x1UL << DBG_APB1_FZ_DBG_LPTIM2_HOLD_POS) /**< 0x40000000 */
#define DBG_APB1_FZ_DBG_LPTIM2_HOLD                    DBG_APB1_FZ_DBG_LPTIM2_HOLD_MASK

/*-----------------------------------------------------------------------------------------------
                                       DMA Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for DMA_ISR */
#define DMA_ISR_G0_POS       (0U)
#define DMA_ISR_G0_MASK      (0x1UL << DMA_ISR_G0_POS)                         /**< 0x00000001 */
#define DMA_ISR_G0           DMA_ISR_G0_MASK                                   /**< Channel 0 global interrupt flag */
#define DMA_ISR_TF0_POS      (1U)
#define DMA_ISR_TF0_MASK     (0x1UL << DMA_ISR_TF0_POS)                        /**< 0x00000002 */
#define DMA_ISR_TF0          DMA_ISR_TF0_MASK                                  /**< Channel 0 transfer complete flag */
#define DMA_ISR_TH0_POS      (2U)
#define DMA_ISR_TH0_MASK     (0x1UL << DMA_ISR_TH0_POS)                        /**< 0x00000004 */
#define DMA_ISR_TH0          DMA_ISR_TH0_MASK                                  /**< Channel 0 half transfer flag */
#define DMA_ISR_TE0_POS      (3U)
#define DMA_ISR_TE0_MASK     (0x1UL << DMA_ISR_TE0_POS)                        /**< 0x00000008 */
#define DMA_ISR_TE0          DMA_ISR_TE0_MASK                                  /**< Channel 0 transfer Error flag */
#define DMA_ISR_G1_POS       (4U)
#define DMA_ISR_G1_MASK      (0x1UL << DMA_ISR_G1_POS)                         /**< 0x00000010 */
#define DMA_ISR_G1           DMA_ISR_G1_MASK                                   /**< Channel 1 global interrupt flag */
#define DMA_ISR_TF1_POS      (5U)
#define DMA_ISR_TF1_MASK     (0x1UL << DMA_ISR_TF1_POS)                        /**< 0x00000020 */
#define DMA_ISR_TF1          DMA_ISR_TF1_MASK                                  /**< Channel 1 transfer complete flag */
#define DMA_ISR_TH1_POS      (6U)
#define DMA_ISR_TH1_MASK     (0x1UL << DMA_ISR_TH1_POS)                        /**< 0x00000040 */
#define DMA_ISR_TH1          DMA_ISR_TH1_MASK                                  /**< Channel 1 half transfer flag */
#define DMA_ISR_TE1_POS      (7U)
#define DMA_ISR_TE1_MASK     (0x1UL << DMA_ISR_TE1_POS)                        /**< 0x00000080 */
#define DMA_ISR_TE1          DMA_ISR_TE1_MASK                                  /**< Channel 1 transfer error flag */


/* Bits for DMA_ICR */
#define DMA_ICR_GCF0_POS     (0U)
#define DMA_ICR_GCF0_MASK    (0x1UL << DMA_ICR_GCF0_POS)                       /**< 0x00000001 */
#define DMA_ICR_GCF0         DMA_ICR_GCF0_MASK                                 /**< Channel 0 global interrupt clearr */
#define DMA_ICR_TFCF0_POS    (1U)
#define DMA_ICR_TFCF0_MASK   (0x1UL << DMA_ICR_TFCF0_POS)                      /**< 0x00000002 */
#define DMA_ICR_TFCF0        DMA_ICR_TFCF0_MASK                                /**< Channel 0 transfer complete clear */
#define DMA_ICR_THCF0_POS    (2U)
#define DMA_ICR_THCF0_MASK   (0x1UL << DMA_ICR_THCF0_POS)                      /**< 0x00000004 */
#define DMA_ICR_THCF0        DMA_ICR_THCF0_MASK                                /**< Channel 0 half transfer clear */
#define DMA_ICR_TECF0_POS    (3U)
#define DMA_ICR_TECF0_MASK   (0x1UL << DMA_ICR_TECF0_POS)                      /**< 0x00000008 */
#define DMA_ICR_TECF0        DMA_ICR_TECF0_MASK                                /**< Channel 0 transfer error clear */
#define DMA_ICR_GCF1_POS     (4U)
#define DMA_ICR_GCF1_MASK    (0x1UL << DMA_ICR_GCF1_POS)                       /**< 0x00000010 */
#define DMA_ICR_GCF1         DMA_ICR_GCF1_MASK                                 /**< Channel 1 global interrupt clear */
#define DMA_ICR_TFCF1_POS    (5U)
#define DMA_ICR_TFCF1_MASK   (0x1UL << DMA_ICR_TFCF1_POS)                      /**< 0x00000020 */
#define DMA_ICR_TFCF1        DMA_ICR_TFCF1_MASK                                /**< Channel 1 transfer complete clear */
#define DMA_ICR_THCF1_POS    (6U)
#define DMA_ICR_THCF1_MASK   (0x1UL << DMA_ICR_THCF1_POS)                      /**< 0x00000040 */
#define DMA_ICR_THCF1        DMA_ICR_THCF1_MASK                                /**< Channel 1 half transfer clear */
#define DMA_ICR_TECF1_POS    (7U)
#define DMA_ICR_TECF1_MASK   (0x1UL << DMA_ICR_TECF1_POS)                      /**< 0x00000080 */
#define DMA_ICR_TECF1        DMA_ICR_TECF1_MASK                                /**< Channel 1 transfer error clear */


/* Bits for DMA_CC */
#define DMA_CC_EN_POS        (0U)
#define DMA_CC_EN_MASK       (0x1UL << DMA_CC_EN_POS)                          /**< 0x00000001 */
#define DMA_CC_EN            DMA_CC_EN_MASK                                    /**< Channel enable */
#define DMA_CC_TFIE_POS      (1U)
#define DMA_CC_TFIE_MASK     (0x1UL << DMA_CC_TFIE_POS)                        /**< 0x00000002 */
#define DMA_CC_TFIE          DMA_CC_TFIE_MASK                                  /**< Transfer complete interrupt enable */
#define DMA_CC_THIE_POS      (2U)
#define DMA_CC_THIE_MASK     (0x1UL << DMA_CC_THIE_POS)                        /**< 0x00000004 */
#define DMA_CC_THIE          DMA_CC_THIE_MASK                                  /**< Half transfer interrupt enable */
#define DMA_CC_TEIE_POS      (3U)
#define DMA_CC_TEIE_MASK     (0x1UL << DMA_CC_TEIE_POS)                        /**< 0x00000008 */
#define DMA_CC_TEIE          DMA_CC_TEIE_MASK                                  /**< Transfer error interrupt enable */
#define DMA_CC_DINC_POS      (4U)
#define DMA_CC_DINC_MASK     (0x1UL << DMA_CC_DINC_POS)                        /**< 0x00000010 */
#define DMA_CC_DINC          DMA_CC_DINC_MASK                                  /**< Destinate address increment mode */
#define DMA_CC_SINC_POS      (5U)
#define DMA_CC_SINC_MASK     (0x1UL << DMA_CC_SINC_POS)                        /**< 0x00000020 */
#define DMA_CC_SINC          DMA_CC_SINC_MASK                                  /**< Source address increment mode */
#define DMA_CC_SIZE_POS      (6U)
#define DMA_CC_SIZE_MASK     (0x3UL << DMA_CC_SIZE_POS)                        /**< 0x000000C0 */
#define DMA_CC_SIZE          DMA_CC_SIZE_MASK                                  /**< Transfer data size */
#define DMA_CC_SIZE_BYTE     (0x0 << DMA_CC_SIZE_POS)                          /**< 0x00000000 */
#define DMA_CC_SIZE_HALFWORD (0x1 << DMA_CC_SIZE_POS)                          /**< 0x00000040 */
#define DMA_CC_SIZE_WORD     (0x2 << DMA_CC_SIZE_POS)                          /**< 0x00000080 */
#define DMA_CC_CIRC_POS      (11U)
#define DMA_CC_CIRC_MASK     (0x1UL << DMA_CC_CIRC_POS)                        /**< 0x00000800 */
#define DMA_CC_CIRC          DMA_CC_CIRC_MASK                                  /**< Circulate mode */
#define DMA_CC_TYPE_POS      (12U)
#define DMA_CC_TYPE_MASK     (0x1UL << DMA_CC_TYPE_POS)                        /**< 0x00010000 */
#define DMA_CC_TYPE          DMA_CC_TYPE_MASK                                  /**< DMA transmit type */
#define DMA_CC_REQ_ID_POS    (16U)
#define DMA_CC_REQ_ID_MASK   (0x1FUL << DMA_CC_REQ_ID_POS)                     /**< 0x001F0000 */
#define DMA_CC_REQ_ID        DMA_CC_REQ_ID_MASK                                /**< DMA request ID */

/* Bits for DMA_CNDTR */
#define DMA_CNDTR_NDT_POS      (0U)
#define DMA_CNDTR_NDT_MASK     (0xFFFFUL << DMA_CNDTR_NDT_POS)                 /**< 0x0000FFFF */
#define DMA_CNDTR_NDT          DMA_CNDTR_NDT_MASK                              /**< Number of data to transfer */

/* Bits for DMA_CSAR */
#define DMA_CSAR_SA_POS        (0U)
#define DMA_CSAR_SA_MASK       (0xFFFFFFFFUL << DMA_CSAR_SA_POS)               /**< 0xFFFFFFFF */
#define DMA_CSAR_SA            DMA_CSAR_SA_MASK                                /**< Source address */

/* Bits for DMA_CDAR */
#define DMA_CDAR_DA_POS        (0U)
#define DMA_CDAR_DA_MASK       (0xFFFFFFFFUL << DMA_CDAR_DA_POS)               /**< 0xFFFFFFFF */
#define DMA_CDAR_DA            DMA_CDAR_DA_MASK                                /**< Destination address */

/*-----------------------------------------------------------------------------------------------
                                       EXTI Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for EXTI_RTSR */
#define EXTI_RTSR_RT0_POS           (0U)
#define EXTI_RTSR_RT0_MASK          (0x1UL << EXTI_RTSR_RT0_POS)              /**< 0x00000001 */
#define EXTI_RTSR_RT0               EXTI_RTSR_RT0_MASK                        /**< Rising trigger configuration for input line 0 */
#define EXTI_RTSR_RT1_POS           (1U)
#define EXTI_RTSR_RT1_MASK          (0x1UL << EXTI_RTSR_RT1_POS)              /**< 0x00000002 */
#define EXTI_RTSR_RT1               EXTI_RTSR_RT1_MASK                        /**< Rising trigger configuration for input line 1 */
#define EXTI_RTSR_RT2_POS           (2U)
#define EXTI_RTSR_RT2_MASK          (0x1UL << EXTI_RTSR_RT2_POS)              /**< 0x00000004 */
#define EXTI_RTSR_RT2               EXTI_RTSR_RT2_MASK                        /**< Rising trigger configuration for input line 2 */
#define EXTI_RTSR_RT3_POS           (3U)
#define EXTI_RTSR_RT3_MASK          (0x1UL << EXTI_RTSR_RT3_POS)              /**< 0x00000008 */
#define EXTI_RTSR_RT3               EXTI_RTSR_RT3_MASK                        /**< Rising trigger configuration for input line 3 */
#define EXTI_RTSR_RT4_POS           (4U)
#define EXTI_RTSR_RT4_MASK          (0x1UL << EXTI_RTSR_RT4_POS)              /**< 0x00000010 */
#define EXTI_RTSR_RT4               EXTI_RTSR_RT4_MASK                        /**< Rising trigger configuration for input line 4 */
#define EXTI_RTSR_RT5_POS           (5U)
#define EXTI_RTSR_RT5_MASK          (0x1UL << EXTI_RTSR_RT5_POS)              /**< 0x00000020 */
#define EXTI_RTSR_RT5               EXTI_RTSR_RT5_MASK                        /**< Rising trigger configuration for input line 5 */
#define EXTI_RTSR_RT6_POS           (6U)
#define EXTI_RTSR_RT6_MASK          (0x1UL << EXTI_RTSR_RT6_POS)              /**< 0x00000040 */
#define EXTI_RTSR_RT6               EXTI_RTSR_RT6_MASK                        /**< Rising trigger configuration for input line 6 */
#define EXTI_RTSR_RT7_POS           (7U)
#define EXTI_RTSR_RT7_MASK          (0x1UL << EXTI_RTSR_RT7_POS)              /**< 0x00000080 */
#define EXTI_RTSR_RT7               EXTI_RTSR_RT7_MASK                        /**< Rising trigger configuration for input line 7 */
#define EXTI_RTSR_RT8_POS           (8U)
#define EXTI_RTSR_RT8_MASK          (0x1UL << EXTI_RTSR_RT8_POS)              /**< 0x00000100 */
#define EXTI_RTSR_RT8               EXTI_RTSR_RT8_MASK                        /**< Rising trigger configuration for input line 8 */
#define EXTI_RTSR_RT9_POS           (9U)
#define EXTI_RTSR_RT9_MASK          (0x1UL << EXTI_RTSR_RT9_POS)              /**< 0x00000200 */
#define EXTI_RTSR_RT9               EXTI_RTSR_RT9_MASK                        /**< Rising trigger configuration for input line 9 */
#define EXTI_RTSR_RT10_POS          (10U)
#define EXTI_RTSR_RT10_MASK         (0x1UL << EXTI_RTSR_RT10_POS)             /**< 0x00000400 */
#define EXTI_RTSR_RT10              EXTI_RTSR_RT10_MASK                       /**< Rising trigger configuration for input line 10 */
#define EXTI_RTSR_RT11_POS          (11U)
#define EXTI_RTSR_RT11_MASK         (0x1UL << EXTI_RTSR_RT11_POS)             /**< 0x00000800 */
#define EXTI_RTSR_RT11              EXTI_RTSR_RT11_MASK                       /**< Rising trigger configuration for input line 11 */
#define EXTI_RTSR_RT12_POS          (12U)
#define EXTI_RTSR_RT12_MASK         (0x1UL << EXTI_RTSR_RT12_POS)             /**< 0x00001000 */
#define EXTI_RTSR_RT12              EXTI_RTSR_RT12_MASK                       /**< Rising trigger configuration for input line 12 */
#define EXTI_RTSR_RT13_POS          (13U)
#define EXTI_RTSR_RT13_MASK         (0x1UL << EXTI_RTSR_RT13_POS)             /**< 0x00002000 */
#define EXTI_RTSR_RT13              EXTI_RTSR_RT13_MASK                       /**< Rising trigger configuration for input line 13 */
#define EXTI_RTSR_RT14_POS          (14U)
#define EXTI_RTSR_RT14_MASK         (0x1UL << EXTI_RTSR_RT14_POS)             /**< 0x00004000 */
#define EXTI_RTSR_RT14              EXTI_RTSR_RT14_MASK                       /**< Rising trigger configuration for input line 14 */
#define EXTI_RTSR_RT15_POS          (15U)
#define EXTI_RTSR_RT15_MASK         (0x1UL << EXTI_RTSR_RT15_POS)             /**< 0x00008000 */
#define EXTI_RTSR_RT15              EXTI_RTSR_RT15_MASK                       /**< Rising trigger configuration for input line 15 */
#define EXTI_RTSR_RT16_POS          (16U)
#define EXTI_RTSR_RT16_MASK         (0x1UL << EXTI_RTSR_RT16_POS)             /**< 0x00010000 */
#define EXTI_RTSR_RT16              EXTI_RTSR_RT16_MASK                       /**< Rising trigger configuration for input line 16 */
#define EXTI_RTSR_RT17_POS          (17U)
#define EXTI_RTSR_RT17_MASK         (0x1UL << EXTI_RTSR_RT17_POS)             /**< 0x00020000 */
#define EXTI_RTSR_RT17              EXTI_RTSR_RT17_MASK                       /**< Rising trigger configuration for input line 17 */

/* Bits for EXTI_FTSR */
#define EXTI_FTSR_FT0_POS           (0U)
#define EXTI_FTSR_FT0_MASK          (0x1UL << EXTI_FTSR_FT0_POS)              /**< 0x00000001 */
#define EXTI_FTSR_FT0               EXTI_FTSR_FT0_MASK                        /**< Falling trigger configuration for input line 0 */
#define EXTI_FTSR_FT1_POS           (1U)
#define EXTI_FTSR_FT1_MASK          (0x1UL << EXTI_FTSR_FT1_POS)              /**< 0x00000002 */
#define EXTI_FTSR_FT1               EXTI_FTSR_FT1_MASK                        /**< Falling trigger configuration for input line 1 */
#define EXTI_FTSR_FT2_POS           (2U)
#define EXTI_FTSR_FT2_MASK          (0x1UL << EXTI_FTSR_FT2_POS)              /**< 0x00000004 */
#define EXTI_FTSR_FT2               EXTI_FTSR_FT2_MASK                        /**< Falling trigger configuration for input line 2 */
#define EXTI_FTSR_FT3_POS           (3U)
#define EXTI_FTSR_FT3_MASK          (0x1UL << EXTI_FTSR_FT3_POS)              /**< 0x00000008 */
#define EXTI_FTSR_FT3               EXTI_FTSR_FT3_MASK                        /**< Falling trigger configuration for input line 3 */
#define EXTI_FTSR_FT4_POS           (4U)
#define EXTI_FTSR_FT4_MASK          (0x1UL << EXTI_FTSR_FT4_POS)              /**< 0x00000010 */
#define EXTI_FTSR_FT4               EXTI_FTSR_FT4_MASK                        /**< Falling trigger configuration for input line 4 */
#define EXTI_FTSR_FT5_POS           (5U)
#define EXTI_FTSR_FT5_MASK          (0x1UL << EXTI_FTSR_FT5_POS)              /**< 0x00000020 */
#define EXTI_FTSR_FT5               EXTI_FTSR_FT5_MASK                        /**< Falling trigger configuration for input line 5 */
#define EXTI_FTSR_FT6_POS           (6U)
#define EXTI_FTSR_FT6_MASK          (0x1UL << EXTI_FTSR_FT6_POS)              /**< 0x00000040 */
#define EXTI_FTSR_FT6               EXTI_FTSR_FT6_MASK                        /**< Falling trigger configuration for input line 6 */
#define EXTI_FTSR_FT7_POS           (7U)
#define EXTI_FTSR_FT7_MASK          (0x1UL << EXTI_FTSR_FT7_POS)              /**< 0x00000080 */
#define EXTI_FTSR_FT7               EXTI_FTSR_FT7_MASK                        /**< Falling trigger configuration for input line 7 */
#define EXTI_FTSR_FT8_POS           (8U)
#define EXTI_FTSR_FT8_MASK          (0x1UL << EXTI_FTSR_FT8_POS)              /**< 0x00000100 */
#define EXTI_FTSR_FT8               EXTI_FTSR_FT8_MASK                        /**< Falling trigger configuration for input line 8 */
#define EXTI_FTSR_FT9_POS           (9U)
#define EXTI_FTSR_FT9_MASK          (0x1UL << EXTI_FTSR_FT9_POS)              /**< 0x00000200 */
#define EXTI_FTSR_FT9               EXTI_FTSR_FT9_MASK                        /**< Falling trigger configuration for input line 9 */
#define EXTI_FTSR_FT10_POS          (10U)
#define EXTI_FTSR_FT10_MASK         (0x1UL << EXTI_FTSR_FT10_POS)             /**< 0x00000400 */
#define EXTI_FTSR_FT10              EXTI_FTSR_FT10_MASK                       /**< Falling trigger configuration for input line 10 */
#define EXTI_FTSR_FT11_POS          (11U)
#define EXTI_FTSR_FT11_MASK         (0x1UL << EXTI_FTSR_FT11_POS)             /**< 0x00000800 */
#define EXTI_FTSR_FT11              EXTI_FTSR_FT11_MASK                       /**< Falling trigger configuration for input line 11 */
#define EXTI_FTSR_FT12_POS          (12U)
#define EXTI_FTSR_FT12_MASK         (0x1UL << EXTI_FTSR_FT12_POS)             /**< 0x00001000 */
#define EXTI_FTSR_FT12              EXTI_FTSR_FT12_MASK                       /**< Falling trigger configuration for input line 12 */
#define EXTI_FTSR_FT13_POS          (13U)
#define EXTI_FTSR_FT13_MASK         (0x1UL << EXTI_FTSR_FT13_POS)             /**< 0x00002000 */
#define EXTI_FTSR_FT13              EXTI_FTSR_FT13_MASK                       /**< Falling trigger configuration for input line 13 */
#define EXTI_FTSR_FT14_POS          (14U)
#define EXTI_FTSR_FT14_MASK         (0x1UL << EXTI_FTSR_FT14_POS)             /**< 0x00004000 */
#define EXTI_FTSR_FT14              EXTI_FTSR_FT14_MASK                       /**< Falling trigger configuration for input line 14 */
#define EXTI_FTSR_FT15_POS          (15U)
#define EXTI_FTSR_FT15_MASK         (0x1UL << EXTI_FTSR_FT15_POS)             /**< 0x00008000 */
#define EXTI_FTSR_FT15              EXTI_FTSR_FT15_MASK                       /**< Falling trigger configuration for input line 15 */
#define EXTI_FTSR_FT16_POS          (16U)
#define EXTI_FTSR_FT16_MASK         (0x1UL << EXTI_FTSR_FT16_POS)             /**< 0x00010000 */
#define EXTI_FTSR_FT16              EXTI_FTSR_FT16_MASK                       /**< Falling trigger configuration for input line 16 */
#define EXTI_FTSR_FT17_POS          (17U)
#define EXTI_FTSR_FT17_MASK         (0x1UL << EXTI_FTSR_FT17_POS)             /**< 0x00020000 */
#define EXTI_FTSR_FT17              EXTI_FTSR_FT17_MASK                       /**< Falling trigger configuration for input line 17 */

/* Bits for EXTI_PIR */
#define EXTI_PIR_PIF0_POS          (0U)
#define EXTI_PIR_PIF0_MASK         (0x1UL << EXTI_PIR_PIF0_POS)               /**< 0x00000001 */
#define EXTI_PIR_PIF0              EXTI_PIR_PIF0_MASK                         /**< Rising or Falling pending interrupt flag on line 0 */
#define EXTI_PIR_PIF1_POS          (1U)
#define EXTI_PIR_PIF1_MASK         (0x1UL << EXTI_PIR_PIF1_POS)               /**< 0x00000002 */
#define EXTI_PIR_PIF1              EXTI_PIR_PIF1_MASK                         /**< Rising or Falling pending interrupt flag on line 1 */
#define EXTI_PIR_PIF2_POS          (2U)
#define EXTI_PIR_PIF2_MASK         (0x1UL << EXTI_PIR_PIF2_POS)               /**< 0x00000004 */
#define EXTI_PIR_PIF2              EXTI_PIR_PIF2_MASK                         /**< Rising or Falling pending interrupt flag on line 2 */
#define EXTI_PIR_PIF3_POS          (3U)
#define EXTI_PIR_PIF3_MASK         (0x1UL << EXTI_PIR_PIF3_POS)               /**< 0x00000008 */
#define EXTI_PIR_PIF3              EXTI_PIR_PIF3_MASK                         /**< Rising or Falling pending interrupt flag on line 3 */
#define EXTI_PIR_PIF4_POS          (4U)
#define EXTI_PIR_PIF4_MASK         (0x1UL << EXTI_PIR_PIF4_POS)               /**< 0x00000010 */
#define EXTI_PIR_PIF4              EXTI_PIR_PIF4_MASK                         /**< Rising or Falling pending interrupt flag on line 4 */
#define EXTI_PIR_PIF5_POS          (5U)
#define EXTI_PIR_PIF5_MASK         (0x1UL << EXTI_PIR_PIF5_POS)               /**< 0x00000020 */
#define EXTI_PIR_PIF5              EXTI_PIR_PIF5_MASK                         /**< Rising or Falling pending interrupt flag on line 5 */
#define EXTI_PIR_PIF6_POS          (6U)
#define EXTI_PIR_PIF6_MASK         (0x1UL << EXTI_PIR_PIF6_POS)               /**< 0x00000040 */
#define EXTI_PIR_PIF6              EXTI_PIR_PIF6_MASK                         /**< Rising or Falling pending interrupt flag on line 6 */
#define EXTI_PIR_PIF7_POS          (7U)
#define EXTI_PIR_PIF7_MASK         (0x1UL << EXTI_PIR_PIF7_POS)               /**< 0x00000080 */
#define EXTI_PIR_PIF7              EXTI_PIR_PIF7_MASK                         /**< Rising or Falling pending interrupt flag on line 7 */
#define EXTI_PIR_PIF8_POS          (8U)
#define EXTI_PIR_PIF8_MASK         (0x1UL << EXTI_PIR_PIF8_POS)               /**< 0x00000100 */
#define EXTI_PIR_PIF8              EXTI_PIR_PIF8_MASK                         /**< Rising or Falling pending interrupt flag on line 8 */
#define EXTI_PIR_PIF9_POS          (9U)
#define EXTI_PIR_PIF9_MASK         (0x1UL << EXTI_PIR_PIF9_POS)               /**< 0x00000200 */
#define EXTI_PIR_PIF9              EXTI_PIR_PIF9_MASK                         /**< Rising or Falling pending interrupt flag on line 9 */
#define EXTI_PIR_PIF10_POS         (10U)
#define EXTI_PIR_PIF10_MASK        (0x1UL << EXTI_PIR_PIF10_POS)              /**< 0x00000400 */
#define EXTI_PIR_PIF10             EXTI_PIR_PIF10_MASK                        /**< Rising or Falling pending interrupt flag on line 10 */
#define EXTI_PIR_PIF11_POS         (11U)
#define EXTI_PIR_PIF11_MASK        (0x1UL << EXTI_PIR_PIF11_POS)              /**< 0x00000800 */
#define EXTI_PIR_PIF11             EXTI_PIR_PIF11_MASK                        /**< Rising or Falling pending interrupt flag on line 11 */
#define EXTI_PIR_PIF12_POS         (12U)
#define EXTI_PIR_PIF12_MASK        (0x1UL << EXTI_PIR_PIF12_POS)              /**< 0x00001000 */
#define EXTI_PIR_PIF12             EXTI_PIR_PIF12_MASK                        /**< Rising or Falling pending interrupt flag on line 12 */
#define EXTI_PIR_PIF13_POS         (13U)
#define EXTI_PIR_PIF13_MASK        (0x1UL << EXTI_PIR_PIF13_POS)              /**< 0x00002000 */
#define EXTI_PIR_PIF13             EXTI_PIR_PIF13_MASK                        /**< Rising or Falling pending interrupt flag on line 13 */
#define EXTI_PIR_PIF14_POS         (14U)
#define EXTI_PIR_PIF14_MASK        (0x1UL << EXTI_PIR_PIF14_POS)              /**< 0x00004000 */
#define EXTI_PIR_PIF14             EXTI_PIR_PIF14_MASK                        /**< Rising or Falling pending interrupt flag on line 14 */
#define EXTI_PIR_PIF15_POS         (15U)
#define EXTI_PIR_PIF15_MASK        (0x1UL << EXTI_PIR_PIF15_POS)              /**< 0x00008000 */
#define EXTI_PIR_PIF15             EXTI_PIR_PIF15_MASK                        /**< Rising or Falling pending interrupt flag on line 15 */
#define EXTI_PIR_PIF16_POS         (16U)
#define EXTI_PIR_PIF16_MASK        (0x1UL << EXTI_PIR_PIF16_POS)              /**< 0x00010000 */
#define EXTI_PIR_PIF16             EXTI_PIR_PIF16_MASK                        /**< Rising or Falling pending interrupt flag on line 16 */
#define EXTI_PIR_PIF17_POS         (17U)
#define EXTI_PIR_PIF17_MASK        (0x1UL << EXTI_PIR_PIF17_POS)              /**< 0x00020000 */
#define EXTI_PIR_PIF17             EXTI_PIR_PIF17_MASK                        /**< Rising or Falling pending interrupt flag on line 17 */

/* Bits for EXTI_EXTICR1 */
#define EXTI_EXTICR1_EXTI0_POS            (0U)
#define EXTI_EXTICR1_EXTI0_MASK           (0x7UL << EXTI_EXTICR1_EXTI0_POS)   /**< 0x00000007 */
#define EXTI_EXTICR1_EXTI0                EXTI_EXTICR1_EXTI0_MASK             /**< EXTI 0 configuration */
#define EXTI_EXTICR1_EXTI1_POS            (4U)
#define EXTI_EXTICR1_EXTI1_MASK           (0x7UL << EXTI_EXTICR1_EXTI1_POS)   /**< 0x00000070 */
#define EXTI_EXTICR1_EXTI1                EXTI_EXTICR1_EXTI1_MASK             /**< EXTI 1 configuration */
#define EXTI_EXTICR1_EXTI2_POS            (8U)
#define EXTI_EXTICR1_EXTI2_MASK           (0x7UL << EXTI_EXTICR1_EXTI2_POS)   /**< 0x00000700 */
#define EXTI_EXTICR1_EXTI2                EXTI_EXTICR1_EXTI2_MASK             /**< EXTI 2 configuration */
#define EXTI_EXTICR1_EXTI3_POS            (12U)
#define EXTI_EXTICR1_EXTI3_MASK           (0x7UL << EXTI_EXTICR1_EXTI3_POS)   /**< 0x00007000 */
#define EXTI_EXTICR1_EXTI3                EXTI_EXTICR1_EXTI3_MASK             /**< EXTI 3 configuration */
#define EXTI_EXTICR1_EXTI4_POS            (16U)
#define EXTI_EXTICR1_EXTI4_MASK           (0x7UL << EXTI_EXTICR1_EXTI4_POS)   /**< 0x00070000 */
#define EXTI_EXTICR1_EXTI4                EXTI_EXTICR1_EXTI4_MASK             /**< EXTI 4 configuration */
#define EXTI_EXTICR1_EXTI5_POS            (20U)
#define EXTI_EXTICR1_EXTI5_MASK           (0x7UL << EXTI_EXTICR1_EXTI5_POS)   /**< 0x00700000 */
#define EXTI_EXTICR1_EXTI5                EXTI_EXTICR1_EXTI5_MASK             /**< EXTI 5 configuration */
#define EXTI_EXTICR1_EXTI6_POS            (24U)
#define EXTI_EXTICR1_EXTI6_MASK           (0x7UL << EXTI_EXTICR1_EXTI6_POS)   /**< 0x07000000 */
#define EXTI_EXTICR1_EXTI6                EXTI_EXTICR1_EXTI6_MASK             /**< EXTI 6 configuration */
#define EXTI_EXTICR1_EXTI7_POS            (28U)
#define EXTI_EXTICR1_EXTI7_MASK           (0x7UL << EXTI_EXTICR1_EXTI7_POS)   /**< 0x70000000 */
#define EXTI_EXTICR1_EXTI7                EXTI_EXTICR1_EXTI7_MASK             /**< EXTI 7 configuration */

/* Bits for EXTI_EXTICR2 */
#define EXTI_EXTICR2_EXTI8_POS            (0U)
#define EXTI_EXTICR2_EXTI8_MASK           (0x7UL << EXTI_EXTICR2_EXTI8_POS)   /**< 0x00000007 */
#define EXTI_EXTICR2_EXTI8                EXTI_EXTICR2_EXTI8_MASK             /**< EXTI 8 configuration */
#define EXTI_EXTICR2_EXTI9_POS            (4U)
#define EXTI_EXTICR2_EXTI9_MASK           (0x7UL << EXTI_EXTICR2_EXTI9_POS)   /**< 0x00000070 */
#define EXTI_EXTICR2_EXTI9                EXTI_EXTICR2_EXTI9_MASK             /**< EXTI 9 configuration */
#define EXTI_EXTICR2_EXTI10_POS           (8U)
#define EXTI_EXTICR2_EXTI10_MASK          (0x7UL << EXTI_EXTICR2_EXTI10_POS)  /**< 0x00000700 */
#define EXTI_EXTICR2_EXTI10               EXTI_EXTICR2_EXTI10_MASK            /**< EXTI 10 configuration */
#define EXTI_EXTICR2_EXTI11_POS           (12U)
#define EXTI_EXTICR2_EXTI11_MASK          (0x7UL << EXTI_EXTICR2_EXTI11_POS)  /**< 0x00007000 */
#define EXTI_EXTICR2_EXTI11               EXTI_EXTICR2_EXTI11_MASK            /**< EXTI 11 configuration */
#define EXTI_EXTICR2_EXTI12_POS           (16U)
#define EXTI_EXTICR2_EXTI12_MASK          (0x7UL << EXTI_EXTICR2_EXTI12_POS)  /**< 0x00070000 */
#define EXTI_EXTICR2_EXTI12               EXTI_EXTICR2_EXTI12_MASK            /**< EXTI 12 configuration */
#define EXTI_EXTICR2_EXTI13_POS           (20U)
#define EXTI_EXTICR2_EXTI13_MASK          (0x7UL << EXTI_EXTICR2_EXTI13_POS)  /**< 0x00700000 */
#define EXTI_EXTICR2_EXTI13               EXTI_EXTICR2_EXTI13_MASK            /**< EXTI 13 configuration */
#define EXTI_EXTICR2_EXTI14_POS           (24U)
#define EXTI_EXTICR2_EXTI14_MASK          (0x7UL << EXTI_EXTICR2_EXTI14_POS)  /**< 0x07000000 */
#define EXTI_EXTICR2_EXTI14               EXTI_EXTICR2_EXTI14_MASK            /**< EXTI 14 configuration */
#define EXTI_EXTICR2_EXTI15_POS           (28U)
#define EXTI_EXTICR2_EXTI15_MASK          (0x7UL << EXTI_EXTICR2_EXTI15_POS)  /**< 0x70000000 */
#define EXTI_EXTICR2_EXTI15               EXTI_EXTICR2_EXTI15_MASK            /**< EXTI 15 configuration */

/* Bits for EXTI_IMR */
#define EXTI_IMR_IM0_POS            (0U)
#define EXTI_IMR_IM0_MASK           (0x1UL << EXTI_IMR_IM0_POS)               /**< 0x00000001 */
#define EXTI_IMR_IM0                EXTI_IMR_IM0_MASK                         /**< Interrupt mask on line 0 */
#define EXTI_IMR_IM1_POS            (1U)
#define EXTI_IMR_IM1_MASK           (0x1UL << EXTI_IMR_IM1_POS)               /**< 0x00000002 */
#define EXTI_IMR_IM1                EXTI_IMR_IM1_MASK                         /**< Interrupt mask on line 1 */
#define EXTI_IMR_IM2_POS            (2U)
#define EXTI_IMR_IM2_MASK           (0x1UL << EXTI_IMR_IM2_POS)               /**< 0x00000004 */
#define EXTI_IMR_IM2                EXTI_IMR_IM2_MASK                         /**< Interrupt mask on line 2 */
#define EXTI_IMR_IM3_POS            (3U)
#define EXTI_IMR_IM3_MASK           (0x1UL << EXTI_IMR_IM3_POS)               /**< 0x00000008 */
#define EXTI_IMR_IM3                EXTI_IMR_IM3_MASK                         /**< Interrupt mask on line 3 */
#define EXTI_IMR_IM4_POS            (4U)
#define EXTI_IMR_IM4_MASK           (0x1UL << EXTI_IMR_IM4_POS)               /**< 0x00000010 */
#define EXTI_IMR_IM4                EXTI_IMR_IM4_MASK                         /**< Interrupt mask on line 4 */
#define EXTI_IMR_IM5_POS            (5U)
#define EXTI_IMR_IM5_MASK           (0x1UL << EXTI_IMR_IM5_POS)               /**< 0x00000020 */
#define EXTI_IMR_IM5                EXTI_IMR_IM5_MASK                         /**< Interrupt mask on line 5 */
#define EXTI_IMR_IM6_POS            (6U)
#define EXTI_IMR_IM6_MASK           (0x1UL << EXTI_IMR_IM6_POS)               /**< 0x00000040 */
#define EXTI_IMR_IM6                EXTI_IMR_IM6_MASK                         /**< Interrupt mask on line 6 */
#define EXTI_IMR_IM7_POS            (7U)
#define EXTI_IMR_IM7_MASK           (0x1UL << EXTI_IMR_IM7_POS)               /**< 0x00000080 */
#define EXTI_IMR_IM7                EXTI_IMR_IM7_MASK                         /**< Interrupt mask on line 7 */
#define EXTI_IMR_IM8_POS            (8U)
#define EXTI_IMR_IM8_MASK           (0x1UL << EXTI_IMR_IM8_POS)               /**< 0x00000100 */
#define EXTI_IMR_IM8                EXTI_IMR_IM8_MASK                         /**< Interrupt mask on line 8 */
#define EXTI_IMR_IM9_POS            (9U)
#define EXTI_IMR_IM9_MASK           (0x1UL << EXTI_IMR_IM9_POS)               /**< 0x00000200 */
#define EXTI_IMR_IM9                EXTI_IMR_IM9_MASK                         /**< Interrupt mask on line 9 */
#define EXTI_IMR_IM10_POS           (10U)
#define EXTI_IMR_IM10_MASK          (0x1UL << EXTI_IMR_IM10_POS)              /**< 0x00000400 */
#define EXTI_IMR_IM10               EXTI_IMR_IM10_MASK                        /**< Interrupt mask on line 10 */
#define EXTI_IMR_IM11_POS           (11U)
#define EXTI_IMR_IM11_MASK          (0x1UL << EXTI_IMR_IM11_POS)              /**< 0x00000800 */
#define EXTI_IMR_IM11               EXTI_IMR_IM11_MASK                        /**< Interrupt mask on line 11 */
#define EXTI_IMR_IM12_POS           (12U)
#define EXTI_IMR_IM12_MASK          (0x1UL << EXTI_IMR_IM12_POS)              /**< 0x00001000 */
#define EXTI_IMR_IM12               EXTI_IMR_IM12_MASK                        /**< Interrupt mask on line 12 */
#define EXTI_IMR_IM13_POS           (13U)
#define EXTI_IMR_IM13_MASK          (0x1UL << EXTI_IMR_IM13_POS)              /**< 0x00002000 */
#define EXTI_IMR_IM13               EXTI_IMR_IM13_MASK                        /**< Interrupt mask on line 13 */
#define EXTI_IMR_IM14_POS           (14U)
#define EXTI_IMR_IM14_MASK          (0x1UL << EXTI_IMR_IM14_POS)              /**< 0x00004000 */
#define EXTI_IMR_IM14               EXTI_IMR_IM14_MASK                        /**< Interrupt mask on line 14 */
#define EXTI_IMR_IM15_POS           (15U)
#define EXTI_IMR_IM15_MASK          (0x1UL << EXTI_IMR_IM15_POS)              /**< 0x00008000 */
#define EXTI_IMR_IM15               EXTI_IMR_IM15_MASK                        /**< Interrupt mask on line 15 */
#define EXTI_IMR_IM16_POS           (16U)
#define EXTI_IMR_IM16_MASK          (0x1UL << EXTI_IMR_IM16_POS)              /**< 0x00010000 */
#define EXTI_IMR_IM16               EXTI_IMR_IM16_MASK                        /**< Interrupt mask on line 16 */
#define EXTI_IMR_IM17_POS           (17U)
#define EXTI_IMR_IM17_MASK          (0x1UL << EXTI_IMR_IM17_POS)              /**< 0x00020000 */
#define EXTI_IMR_IM17               EXTI_IMR_IM17_MASK                        /**< Interrupt mask on line 17 */
#define EXTI_IMR_IM22_POS           (22U)
#define EXTI_IMR_IM22_MASK          (0x1UL << EXTI_IMR_IM22_POS)              /**< 0x00400000 */
#define EXTI_IMR_IM22               EXTI_IMR_IM22_MASK                        /**< Interrupt mask on line 22 */
#define EXTI_IMR_IM23_POS           (23U)
#define EXTI_IMR_IM23_MASK          (0x1UL << EXTI_IMR_IM23_POS)              /**< 0x00800000 */
#define EXTI_IMR_IM23               EXTI_IMR_IM23_MASK                        /**< Interrupt mask on line 23 */
#define EXTI_IMR_IM24_POS           (24U)
#define EXTI_IMR_IM24_MASK          (0x1UL << EXTI_IMR_IM24_POS)              /**< 0x01000000 */
#define EXTI_IMR_IM24               EXTI_IMR_IM24_MASK                        /**< Interrupt mask on line 24 */
#define EXTI_IMR_IM25_POS           (25U)
#define EXTI_IMR_IM25_MASK          (0x1UL << EXTI_IMR_IM25_POS)              /**< 0x02000000 */
#define EXTI_IMR_IM25               EXTI_IMR_IM25_MASK                        /**< Interrupt mask on line 25 */
#define EXTI_IMR_IM26_POS           (26U)
#define EXTI_IMR_IM26_MASK          (0x1UL << EXTI_IMR_IM26_POS)              /**< 0x04000000 */
#define EXTI_IMR_IM26               EXTI_IMR_IM26_MASK                        /**< Interrupt mask on line 26 */
#define EXTI_IMR_IM27_POS           (27U)
#define EXTI_IMR_IM27_MASK          (0x1UL << EXTI_IMR_IM27_POS)              /**< 0x08000000 */
#define EXTI_IMR_IM27               EXTI_IMR_IM27_MASK                        /**< Interrupt mask on line 27 */
#define EXTI_IMR_IM29_POS           (29U)
#define EXTI_IMR_IM29_MASK          (0x1UL << EXTI_IMR_IM29_POS)              /**< 0x20000000 */
#define EXTI_IMR_IM29               EXTI_IMR_IM29_MASK                        /**< Interrupt mask on line 29 */
#define EXTI_IMR_IM30_POS           (30U)
#define EXTI_IMR_IM30_MASK          (0x1UL << EXTI_IMR_IM30_POS)              /**< 0x40000000 */
#define EXTI_IMR_IM30               EXTI_IMR_IM30_MASK                        /**< Interrupt mask on line 30 */
#define EXTI_IMR_IM31_POS           (31U)
#define EXTI_IMR_IM31_MASK          (0x1UL << EXTI_IMR_IM31_POS)              /**< 0x80000000 */
#define EXTI_IMR_IM31               EXTI_IMR_IM31_MASK                        /**< Interrupt mask on line 31 */

/* Bits for EXTI_EMR */
#define EXTI_EMR_EM0_POS            (0U)
#define EXTI_EMR_EM0_MASK           (0x1UL << EXTI_EMR_EM0_POS)               /**< 0x00000001 */
#define EXTI_EMR_EM0                EXTI_EMR_EM0_MASK                         /**< Event mask on line 0 */
#define EXTI_EMR_EM1_POS            (1U)
#define EXTI_EMR_EM1_MASK           (0x1UL << EXTI_EMR_EM1_POS)               /**< 0x00000002 */
#define EXTI_EMR_EM1                EXTI_EMR_EM1_MASK                         /**< Event mask on line 1 */
#define EXTI_EMR_EM2_POS            (2U)
#define EXTI_EMR_EM2_MASK           (0x1UL << EXTI_EMR_EM2_POS)               /**< 0x00000004 */
#define EXTI_EMR_EM2                EXTI_EMR_EM2_MASK                         /**< Event mask on line 2 */
#define EXTI_EMR_EM3_POS            (3U)
#define EXTI_EMR_EM3_MASK           (0x1UL << EXTI_EMR_EM3_POS)               /**< 0x00000008 */
#define EXTI_EMR_EM3                EXTI_EMR_EM3_MASK                         /**< Event mask on line 3 */
#define EXTI_EMR_EM4_POS            (4U)
#define EXTI_EMR_EM4_MASK           (0x1UL << EXTI_EMR_EM4_POS)               /**< 0x00000010 */
#define EXTI_EMR_EM4                EXTI_EMR_EM4_MASK                         /**< Event mask on line 4 */
#define EXTI_EMR_EM5_POS            (5U)
#define EXTI_EMR_EM5_MASK           (0x1UL << EXTI_EMR_EM5_POS)               /**< 0x00000020 */
#define EXTI_EMR_EM5                EXTI_EMR_EM5_MASK                         /**< Event mask on line 5 */
#define EXTI_EMR_EM6_POS            (6U)
#define EXTI_EMR_EM6_MASK           (0x1UL << EXTI_EMR_EM6_POS)               /**< 0x00000040 */
#define EXTI_EMR_EM6                EXTI_EMR_EM6_MASK                         /**< Event mask on line 6 */
#define EXTI_EMR_EM7_POS            (7U)
#define EXTI_EMR_EM7_MASK           (0x1UL << EXTI_EMR_EM7_POS)               /**< 0x00000080 */
#define EXTI_EMR_EM7                EXTI_EMR_EM7_MASK                         /**< Event mask on line 7 */
#define EXTI_EMR_EM8_POS            (8U)
#define EXTI_EMR_EM8_MASK           (0x1UL << EXTI_EMR_EM8_POS)               /**< 0x00000100 */
#define EXTI_EMR_EM8                EXTI_EMR_EM8_MASK                         /**< Event mask on line 8 */
#define EXTI_EMR_EM9_POS            (9U)
#define EXTI_EMR_EM9_MASK           (0x1UL << EXTI_EMR_EM9_POS)               /**< 0x00000200 */
#define EXTI_EMR_EM9                EXTI_EMR_EM9_MASK                         /**< Event mask on line 9 */
#define EXTI_EMR_EM10_POS           (10U)
#define EXTI_EMR_EM10_MASK          (0x1UL << EXTI_EMR_EM10_POS)              /**< 0x00000400 */
#define EXTI_EMR_EM10               EXTI_EMR_EM10_MASK                        /**< Event mask on line 10 */
#define EXTI_EMR_EM11_POS           (11U)
#define EXTI_EMR_EM11_MASK          (0x1UL << EXTI_EMR_EM11_POS)              /**< 0x00000800 */
#define EXTI_EMR_EM11               EXTI_EMR_EM11_MASK                        /**< Event mask on line 11 */
#define EXTI_EMR_EM12_POS           (12U)
#define EXTI_EMR_EM12_MASK          (0x1UL << EXTI_EMR_EM12_POS)              /**< 0x00001000 */
#define EXTI_EMR_EM12               EXTI_EMR_EM12_MASK                        /**< Event mask on line 12 */
#define EXTI_EMR_EM13_POS           (13U)
#define EXTI_EMR_EM13_MASK          (0x1UL << EXTI_EMR_EM13_POS)              /**< 0x00002000 */
#define EXTI_EMR_EM13               EXTI_EMR_EM13_MASK                        /**< Event mask on line 13 */
#define EXTI_EMR_EM14_POS           (14U)
#define EXTI_EMR_EM14_MASK          (0x1UL << EXTI_EMR_EM14_POS)              /**< 0x00004000 */
#define EXTI_EMR_EM14               EXTI_EMR_EM14_MASK                        /**< Event mask on line 14 */
#define EXTI_EMR_EM15_POS           (15U)
#define EXTI_EMR_EM15_MASK          (0x1UL << EXTI_EMR_EM15_POS)              /**< 0x00008000 */
#define EXTI_EMR_EM15               EXTI_EMR_EM15_MASK                        /**< Event mask on line 15 */
#define EXTI_EMR_EM16_POS           (16U)
#define EXTI_EMR_EM16_MASK          (0x1UL << EXTI_EMR_EM16_POS)              /**< 0x00010000 */
#define EXTI_EMR_EM16               EXTI_EMR_EM16_MASK                        /**< Event mask on line 16 */
#define EXTI_EMR_EM17_POS           (17U)
#define EXTI_EMR_EM17_MASK          (0x1UL << EXTI_EMR_EM17_POS)              /**< 0x00020000 */
#define EXTI_EMR_EM17               EXTI_EMR_EM17_MASK                        /**< Event mask on line 17 */
#define EXTI_EMR_EM22_POS           (22U)
#define EXTI_EMR_EM22_MASK          (0x1UL << EXTI_EMR_EM22_POS)              /**< 0x00400000 */
#define EXTI_EMR_EM22               EXTI_EMR_EM22_MASK                        /**< Event mask on line 22 */
#define EXTI_EMR_EM23_POS           (23U)
#define EXTI_EMR_EM23_MASK          (0x1UL << EXTI_EMR_EM23_POS)              /**< 0x00800000 */
#define EXTI_EMR_EM23               EXTI_EMR_EM23_MASK                        /**< Event mask on line 23 */
#define EXTI_EMR_EM24_POS           (24U)
#define EXTI_EMR_EM24_MASK          (0x1UL << EXTI_EMR_EM24_POS)              /**< 0x01000000 */
#define EXTI_EMR_EM24               EXTI_EMR_EM24_MASK                        /**< Event mask on line 24 */
#define EXTI_EMR_EM25_POS           (25U)
#define EXTI_EMR_EM25_MASK          (0x1UL << EXTI_EMR_EM25_POS)              /**< 0x02000000 */
#define EXTI_EMR_EM25               EXTI_EMR_EM25_MASK                        /**< Event mask on line 25 */
#define EXTI_EMR_EM26_POS           (26U)
#define EXTI_EMR_EM26_MASK          (0x1UL << EXTI_EMR_EM26_POS)              /**< 0x04000000 */
#define EXTI_EMR_EM26               EXTI_EMR_EM26_MASK                        /**< Event mask on line 26 */
#define EXTI_EMR_EM27_POS           (27U)
#define EXTI_EMR_EM27_MASK          (0x1UL << EXTI_EMR_EM27_POS)              /**< 0x08000000 */
#define EXTI_EMR_EM27               EXTI_EMR_EM27_MASK                        /**< Event mask on line 27 */
#define EXTI_EMR_EM29_POS           (29U)
#define EXTI_EMR_EM29_MASK          (0x1UL << EXTI_EMR_EM29_POS)              /**< 0x20000000 */
#define EXTI_EMR_EM29               EXTI_EMR_EM29_MASK                        /**< Event mask on line 29 */
#define EXTI_EMR_EM30_POS           (30U)
#define EXTI_EMR_EM30_MASK          (0x1UL << EXTI_EMR_EM30_POS)              /**< 0x40000000 */
#define EXTI_EMR_EM30               EXTI_EMR_EM30_MASK                        /**< Event mask on line 30 */
#define EXTI_EMR_EM31_POS           (31U)
#define EXTI_EMR_EM31_MASK          (0x1UL << EXTI_EMR_EM31_POS)              /**< 0x80000000 */
#define EXTI_EMR_EM31               EXTI_EMR_EM31_MASK                        /**< Event mask on line 31 */

/*-----------------------------------------------------------------------------------------------
                                       Flash Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for FLASH_ACR */
#define FLASH_ACR_LATENCY_POS                  (0U)
#define FLASH_ACR_LATENCY_MASK                 (0x3UL << FLASH_ACR_LATENCY_POS)               /**< 0x00000003 */
#define FLASH_ACR_LATENCY                      FLASH_ACR_LATENCY_MASK       
#define FLASH_ACR_LATENCY_0CLK                 (0U)
#define FLASH_ACR_LATENCY_1CLK                 (0x1UL << FLASH_ACR_LATENCY_POS)               /**< 0x00000001 */
#define FLASH_ACR_LATENCY_2CLK                 (0x2UL << FLASH_ACR_LATENCY_POS)               /**< 0x00000002 */

/* Bits for FLASH_CRKEY */
#define FLASH_CRKEY_KEY_POS                    (0U)
#define FLASH_CRKEY_KEY_MASK                   (0xFFFFFFFFUL << FLASH_CRKEY_KEY_POS)          /**< 0xFFFFFFFF */
#define FLASH_CRKEY_KEY                        FLASH_CRKEY_KEY_MASK

/* Bits for FLASH_OPTKEY */
#define FLASH_OPTKEY_KEY_POS                   (0U)
#define FLASH_OPTKEY_KEY_MASK                  (0xFFFFFFFFUL << FLASH_OPTKEY_KEY_POS)         /**< 0xFFFFFFFF */
#define FLASH_OPTKEY_KEY                       FLASH_OPTKEY_KEY_MASK

/* Bits for FLASH_SR */
#define FLASH_SR_FSTERR_POS                    (2U)
#define FLASH_SR_FSTERR_MASK                   (0x1UL << FLASH_SR_FSTERR_POS)                 /**< 0x00000004 */
#define FLASH_SR_FSTERR                        FLASH_SR_FSTERR_MASK

#define FLASH_SR_PROGERR_POS                   (3U)
#define FLASH_SR_PROGERR_MASK                  (0x1UL << FLASH_SR_PROGERR_POS)                /**< 0x00000008 */
#define FLASH_SR_PROGERR                       FLASH_SR_PROGERR_MASK

#define FLASH_SR_WRPERR_POS                    (4U)
#define FLASH_SR_WRPERR_MASK                   (0x1UL << FLASH_SR_WRPERR_POS)                 /**< 0x00000010 */
#define FLASH_SR_WRPERR                        FLASH_SR_WRPERR_MASK

#define FLASH_SR_BSY_POS                       (16U)              
#define FLASH_SR_BSY_MASK                      (0x1UL << FLASH_SR_BSY_POS)                    /**< 0x00010000 */
#define FLASH_SR_BSY                           FLASH_SR_BSY_MASK

#define FLASH_SR_EOP_POS                       (24U)
#define FLASH_SR_EOP_MASK                      (0x1UL << FLASH_SR_EOP_POS)                    /**< 0x01000000 */
#define FLASH_SR_EOP                           FLASH_SR_EOP_MASK

/* Bits for FLASH_CR */
#define FLASH_CR_PG_MODE_POS                   (0U)
#define FLASH_CR_PG_MODE_MASK                  (0x1UL << FLASH_CR_PG_MODE_POS)                /**< 0x00000001 */
#define FLASH_CR_PG_MODE                       FLASH_CR_PG_MODE_MASK          

#define FLASH_CR_ER_MODE_POS                   (1U)          
#define FLASH_CR_ER_MODE_MASK                  (0x3UL << FLASH_CR_ER_MODE_POS)                /**< 0x00000006 */
#define FLASH_CR_ER_MODE                       FLASH_CR_ER_MODE_MASK                 
#define FLASH_CR_ER_MODE_NONE                  (0x0UL << FLASH_CR_ER_MODE_POS)                /**< 0x00000000 */
#define FLASH_CR_ER_MODE_PAGE                  (0x1UL << FLASH_CR_ER_MODE_POS)                /**< 0x00000002 */
#define FLASH_CR_ER_MODE_MASS                  (0x3UL << FLASH_CR_ER_MODE_POS)                /**< 0x00000006 */

#define FLASH_CR_ERASE_POS                     (3U)          
#define FLASH_CR_ERASE_MASK                    (0x1UL << FLASH_CR_ERASE_POS)                  /**< 0x00000008 */
#define FLASH_CR_ERASE                         FLASH_CR_ERASE_MASK          

#define FLASH_CR_OPT_ERASE_POS                 (4U)          
#define FLASH_CR_OPT_ERASE_MASK                (0x1UL << FLASH_CR_OPT_ERASE_POS)              /**< 0x00000010 */
#define FLASH_CR_OPT_ERASE                     FLASH_CR_OPT_ERASE_MASK          

#define FLASH_CR_FSTPG_MODE_POS                (5U)          
#define FLASH_CR_FSTPG_MODE_MASK               (0x1UL << FLASH_CR_FSTPG_MODE_POS)             /**< 0x00000020 */
#define FLASH_CR_FSTPG_MODE                    FLASH_CR_FSTPG_MODE_MASK          

#define FLASH_CR_PNB_POS                       (8U)          
#define FLASH_CR_PNB_MASK                      (0x7FUL << FLASH_CR_PNB_POS)                   /**< 0x00007F00 */
#define FLASH_CR_PNB                           FLASH_CR_PNB_MASK    

#define FLASH_CR_EOPIE_POS                     (24U)          
#define FLASH_CR_EOPIE_MASK                    (0x1UL << FLASH_CR_EOPIE_POS)                  /**< 0x01000000 */
#define FLASH_CR_EOPIE                         FLASH_CR_EOPIE_MASK          

#define FLASH_CR_OPERRIE_POS                   (25U)          
#define FLASH_CR_OPERRIE_MASK                  (0x1UL << FLASH_CR_OPERRIE_POS)                /**< 0x02000000 */
#define FLASH_CR_OPERRIE                       FLASH_CR_OPERRIE_MASK           

#define FLASH_CR_OBL_LAUNCH_POS                (27U)           
#define FLASH_CR_OBL_LAUNCH_MASK               (0x1UL << FLASH_CR_OBL_LAUNCH_POS)             /**< 0x08000000 */
#define FLASH_CR_OBL_LAUNCH                    FLASH_CR_OBL_LAUNCH_MASK           

#define FLASH_CR_OPTLOCK_POS                   (30U)           
#define FLASH_CR_OPTLOCK_MASK                  (0x1UL << FLASH_CR_OPTLOCK_POS)                /**< 0x40000000 */
#define FLASH_CR_OPTLOCK                       FLASH_CR_OPTLOCK_MASK           

#define FLASH_CR_LOCK_POS                      (31U)           
#define FLASH_CR_LOCK_MASK                     (0x1UL << FLASH_CR_LOCK_POS)                   /**< 0x80000000 */
#define FLASH_CR_LOCK                          FLASH_CR_LOCK_MASK

/* Bits for FLASH_OPTR1 */
#define FLASH_OPTR1_RDP_POS                    (0U)
#define FLASH_OPTR1_RDP_MASK                   (0xFFUL << FLASH_OPTR1_RDP_POS)                /**< 0x000000FF */
#define FLASH_OPTR1_RDP                        FLASH_OPTR1_RDP_MASK

#define FLASH_OPTR1_BOR_EN_POS                 (8U)
#define FLASH_OPTR1_BOR_EN_MASK                (0x1UL << FLASH_OPTR1_BOR_EN_POS)              /**< 0x00000100 */
#define FLASH_OPTR1_BOR_EN                     FLASH_OPTR1_BOR_EN_MASK

#define FLASH_OPTR1_BOR_LEVEL_POS              (9U)
#define FLASH_OPTR1_BOR_LEVEL_MASK             (0x3UL << FLASH_OPTR1_BOR_LEVEL_POS)           /**< 0x00000600 */
#define FLASH_OPTR1_BOR_LEVEL                  FLASH_OPTR1_BOR_LEVEL_MASK
#define FLASH_OPTR1_BOR_LEVEL_0                (0x0UL << FLASH_OPTR1_BOR_LEVEL_POS)           /**< 0x00000000 */
#define FLASH_OPTR1_BOR_LEVEL_1                (0x1UL << FLASH_OPTR1_BOR_LEVEL_POS)           /**< 0x00000200 */
#define FLASH_OPTR1_BOR_LEVEL_2                (0x2UL << FLASH_OPTR1_BOR_LEVEL_POS)           /**< 0x00000400 */
#define FLASH_OPTR1_BOR_LEVEL_3                (0x3UL << FLASH_OPTR1_BOR_LEVEL_POS)           /**< 0x00000600 */

/* Bits for FLASH_OPTR2 */
#define FLASH_OPTR2_RST_STOP_POS               (0U)
#define FLASH_OPTR2_RST_STOP_MASK              (0x1UL << FLASH_OPTR2_RST_STOP_POS)            /**< 0x00000001 */
#define FLASH_OPTR2_RST_STOP                   FLASH_OPTR2_RST_STOP_MASK

#define FLASH_OPTR2_IWDG_STOP_POS              (5U)
#define FLASH_OPTR2_IWDG_STOP_MASK             (0x1UL << FLASH_OPTR2_IWDG_STOP_POS)           /**< 0x00000020 */
#define FLASH_OPTR2_IWDG_STOP                  FLASH_OPTR2_IWDG_STOP_MASK

#define FLASH_OPTR2_VBAT_MODE_EN_POS           (8U)
#define FLASH_OPTR2_VBAT_MODE_EN_MASK          (0x1UL << FLASH_OPTR2_VBAT_MODE_EN_POS)        /**< 0x00000100 */
#define FLASH_OPTR2_VBAT_MODE_EN               FLASH_OPTR2_VBAT_MODE_EN_MASK

#define FLASH_OPTR2_BOOT1_SW_POS               (12U)
#define FLASH_OPTR2_BOOT1_SW_MASK              (0x1UL << FLASH_OPTR2_BOOT1_SW_POS)            /**< 0x00001000 */
#define FLASH_OPTR2_BOOT1_SW                   FLASH_OPTR2_BOOT1_SW_MASK

#define FLASH_OPTR2_BOOT0_SW_POS               (13U)
#define FLASH_OPTR2_BOOT0_SW_MASK              (0x1UL << FLASH_OPTR2_BOOT0_SW_POS)            /**< 0x00002000 */
#define FLASH_OPTR2_BOOT0_SW                   FLASH_OPTR2_BOOT0_SW_MASK

#define FLASH_OPTR2_BOOT_SEL_POS               (14U)
#define FLASH_OPTR2_BOOT_SEL_MASK              (0x1UL << FLASH_OPTR2_BOOT_SEL_POS)            /**< 0x00004000 */
#define FLASH_OPTR2_BOOT_SEL                   FLASH_OPTR2_BOOT_SEL_MASK

/* Bits for FLASH_WRP1AS */
#define FLASH_WRP1AS_WRP1A_START_POS           (0U)
#define FLASH_WRP1AS_WRP1A_START_MASK          (0x7FUL << FLASH_WRP1AS_WRP1A_START_POS)       /**< 0x0000007F */
#define FLASH_WRP1AS_WRP1A_START               FLASH_WRP1AS_WRP1A_START_MASK

/* Bits for FLASH_WRP1AE */
#define FLASH_WRP1AE_WRP1A_END_POS             (0U)
#define FLASH_WRP1AE_WRP1A_END_MASK            (0x7FUL << FLASH_WRP1AE_WRP1A_END_POS)         /**< 0x0000007F */
#define FLASH_WRP1AE_WRP1A_END                 FLASH_WRP1AE_WRP1A_END_MASK

/* Bits for FLASH_WRP1BS */
#define FLASH_WRP1BS_WRP1B_START_POS           (0U)
#define FLASH_WRP1BS_WRP1B_START_MASK          (0x7FUL << FLASH_WRP1BS_WRP1B_START_POS)       /**< 0x0000007F */
#define FLASH_WRP1BS_WRP1B_START               FLASH_WRP1BS_WRP1B_START_MASK

/* Bits for FLASH_WRP1BE */
#define FLASH_WRP1BE_WRP1B_END_POS             (0U)
#define FLASH_WRP1BE_WRP1B_END_MASK            (0x7FUL << FLASH_WRP1BE_WRP1B_END_POS)         /**< 0x0000007F */
#define FLASH_WRP1BE_WRP1B_END                 FLASH_WRP1BE_WRP1B_END_MASK

/*-----------------------------------------------------------------------------------------------
                                       GPIO Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for GPIO_MODER */
#define GPIO_MODE_MODE0_POS            (0U)
#define GPIO_MODE_MODE0_MASK           (0x3UL << GPIO_MODE_MODE0_POS)          /**< 0x00000003 */
#define GPIO_MODE_MODE0                GPIO_MODE_MODE0_MASK
#define GPIO_MODE_MODE1_POS            (2U)
#define GPIO_MODE_MODE1_MASK           (0x3UL << GPIO_MODE_MODE1_POS)          /**< 0x0000000C */
#define GPIO_MODE_MODE1                GPIO_MODE_MODE1_MASK
#define GPIO_MODE_MODE2_POS            (4U)
#define GPIO_MODE_MODE2_MASK           (0x3UL << GPIO_MODE_MODE2_POS)          /**< 0x00000030 */
#define GPIO_MODE_MODE2                GPIO_MODE_MODE2_MASK
#define GPIO_MODE_MODE3_POS            (6U)
#define GPIO_MODE_MODE3_MASK           (0x3UL << GPIO_MODE_MODE3_POS)          /**< 0x000000C0 */
#define GPIO_MODE_MODE3                GPIO_MODE_MODE3_MASK
#define GPIO_MODE_MODE4_POS            (8U)
#define GPIO_MODE_MODE4_MASK           (0x3UL << GPIO_MODE_MODE4_POS)          /**< 0x00000300 */
#define GPIO_MODE_MODE4                GPIO_MODE_MODE4_MASK
#define GPIO_MODE_MODE5_POS            (10U)
#define GPIO_MODE_MODE5_MASK           (0x3UL << GPIO_MODE_MODE5_POS)          /**< 0x00000C00 */
#define GPIO_MODE_MODE5                GPIO_MODE_MODE5_MASK
#define GPIO_MODE_MODE6_POS            (12U)
#define GPIO_MODE_MODE6_MASK           (0x3UL << GPIO_MODE_MODE6_POS)          /**< 0x00003000 */
#define GPIO_MODE_MODE6                GPIO_MODE_MODE6_MASK
#define GPIO_MODE_MODE7_POS            (14U)
#define GPIO_MODE_MODE7_MASK           (0x3UL << GPIO_MODE_MODE7_POS)          /**< 0x0000C000 */
#define GPIO_MODE_MODE7                GPIO_MODE_MODE7_MASK
#define GPIO_MODE_MODE8_POS            (16U)
#define GPIO_MODE_MODE8_MASK           (0x3UL << GPIO_MODE_MODE8_POS)          /**< 0x00030000 */
#define GPIO_MODE_MODE8                GPIO_MODE_MODE8_MASK
#define GPIO_MODE_MODE9_POS            (18U)
#define GPIO_MODE_MODE9_MASK           (0x3UL << GPIO_MODE_MODE9_POS)          /**< 0x000C0000 */
#define GPIO_MODE_MODE9                GPIO_MODE_MODE9_MASK
#define GPIO_MODE_MODE10_POS           (20U)
#define GPIO_MODE_MODE10_MASK          (0x3UL << GPIO_MODE_MODE10_POS)         /**< 0x00300000 */
#define GPIO_MODE_MODE10               GPIO_MODE_MODE10_MASK
#define GPIO_MODE_MODE11_POS           (22U)
#define GPIO_MODE_MODE11_MASK          (0x3UL << GPIO_MODE_MODE11_POS)         /**< 0x00C00000 */
#define GPIO_MODE_MODE11               GPIO_MODE_MODE11_MASK
#define GPIO_MODE_MODE12_POS           (24U)
#define GPIO_MODE_MODE12_MASK          (0x3UL << GPIO_MODE_MODE12_POS)         /**< 0x03000000 */
#define GPIO_MODE_MODE12               GPIO_MODE_MODE12_MASK

#define GPIO_MODE_MODE13_POS           (26U)
#define GPIO_MODE_MODE13_MASK          (0x3UL << GPIO_MODE_MODE13_POS)         /**< 0x0C000000 */
#define GPIO_MODE_MODE13               GPIO_MODE_MODE13_MASK
#define GPIO_MODE_MODE14_POS           (28U)
#define GPIO_MODE_MODE14_MASK          (0x3UL << GPIO_MODE_MODE14_POS)         /**< 0x30000000 */
#define GPIO_MODE_MODE14               GPIO_MODE_MODE14_MASK
#define GPIO_MODE_MODE15_POS           (30U)
#define GPIO_MODE_MODE15_MASK          (0x3UL << GPIO_MODE_MODE15_POS)         /**< 0xC0000000 */
#define GPIO_MODE_MODE15               GPIO_MODE_MODE15_MASK

/* Bits for GPIO_OTYPER */
#define GPIO_OTYPE_OT0_POS             (0U)
#define GPIO_OTYPE_OT0_MASK            (0x1UL << GPIO_OTYPE_OT0_POS)           /**< 0x00000001 */
#define GPIO_OTYPE_OT0                 GPIO_OTYPE_OT0_MASK
#define GPIO_OTYPE_OT1_POS             (1U)
#define GPIO_OTYPE_OT1_MASK            (0x1UL << GPIO_OTYPE_OT1_POS)           /**< 0x00000002 */
#define GPIO_OTYPE_OT1                 GPIO_OTYPE_OT1_MASK
#define GPIO_OTYPE_OT2_POS             (2U)
#define GPIO_OTYPE_OT2_MASK            (0x1UL << GPIO_OTYPE_OT2_POS)           /**< 0x00000004 */
#define GPIO_OTYPE_OT2                 GPIO_OTYPE_OT2_MASK
#define GPIO_OTYPE_OT3_POS             (3U)
#define GPIO_OTYPE_OT3_MASK            (0x1UL << GPIO_OTYPE_OT3_POS)           /**< 0x00000008 */
#define GPIO_OTYPE_OT3                 GPIO_OTYPE_OT3_MASK
#define GPIO_OTYPE_OT4_POS             (4U)
#define GPIO_OTYPE_OT4_MASK            (0x1UL << GPIO_OTYPE_OT4_POS)           /**< 0x00000010 */
#define GPIO_OTYPE_OT4                 GPIO_OTYPE_OT4_MASK
#define GPIO_OTYPE_OT5_POS             (5U)
#define GPIO_OTYPE_OT5_MASK            (0x1UL << GPIO_OTYPE_OT5_POS)           /**< 0x00000020 */
#define GPIO_OTYPE_OT5                 GPIO_OTYPE_OT5_MASK
#define GPIO_OTYPE_OT6_POS             (6U)
#define GPIO_OTYPE_OT6_MASK            (0x1UL << GPIO_OTYPE_OT6_POS)           /**< 0x00000040 */
#define GPIO_OTYPE_OT6                 GPIO_OTYPE_OT6_MASK
#define GPIO_OTYPE_OT7_POS             (7U)
#define GPIO_OTYPE_OT7_MASK            (0x1UL << GPIO_OTYPE_OT7_POS)           /**< 0x00000080 */
#define GPIO_OTYPE_OT7                 GPIO_OTYPE_OT7_MASK
#define GPIO_OTYPE_OT8_POS             (8U)
#define GPIO_OTYPE_OT8_MASK            (0x1UL << GPIO_OTYPE_OT8_POS)           /**< 0x00000100 */
#define GPIO_OTYPE_OT8                 GPIO_OTYPE_OT8_MASK
#define GPIO_OTYPE_OT9_POS             (9U)
#define GPIO_OTYPE_OT9_MASK            (0x1UL << GPIO_OTYPE_OT9_POS)           /**< 0x00000200 */
#define GPIO_OTYPE_OT9                 GPIO_OTYPE_OT9_MASK
#define GPIO_OTYPE_OT10_POS            (10U)
#define GPIO_OTYPE_OT10_MASK           (0x1UL << GPIO_OTYPE_OT10_POS)          /**< 0x00000400 */
#define GPIO_OTYPE_OT10                GPIO_OTYPE_OT10_MASK
#define GPIO_OTYPE_OT11_POS            (11U)
#define GPIO_OTYPE_OT11_MASK           (0x1UL << GPIO_OTYPE_OT11_POS)          /**< 0x00000800 */
#define GPIO_OTYPE_OT11                GPIO_OTYPE_OT11_MASK
#define GPIO_OTYPE_OT12_POS            (12U)
#define GPIO_OTYPE_OT12_MASK           (0x1UL << GPIO_OTYPE_OT12_POS)          /**< 0x00001000 */
#define GPIO_OTYPE_OT12                GPIO_OTYPE_OT12_MASK
#define GPIO_OTYPE_OT13_POS            (13U)
#define GPIO_OTYPE_OT13_MASK           (0x1UL << GPIO_OTYPE_OT13_POS)          /**< 0x00002000 */
#define GPIO_OTYPE_OT13                GPIO_OTYPE_OT13_MASK
#define GPIO_OTYPE_OT14_POS            (14U)
#define GPIO_OTYPE_OT14_MASK           (0x1UL << GPIO_OTYPE_OT14_POS)          /**< 0x00004000 */
#define GPIO_OTYPE_OT14                GPIO_OTYPE_OT14_MASK
#define GPIO_OTYPE_OT15_POS            (15U)
#define GPIO_OTYPE_OT15_MASK           (0x1UL << GPIO_OTYPE_OT15_POS)          /**< 0x00008000 */
#define GPIO_OTYPE_OT15                GPIO_OTYPE_OT15_MASK

/* Bits for GPIO_PUPDR */
#define GPIO_PUPD_PUPD0_POS            (0U)
#define GPIO_PUPD_PUPD0_MASK           (0x3UL << GPIO_PUPD_PUPD0_POS)          /**< 0x00000003 */
#define GPIO_PUPD_PUPD0                GPIO_PUPD_PUPD0_MASK
#define GPIO_PUPD_PUPD1_POS            (2U)
#define GPIO_PUPD_PUPD1_MASK           (0x3UL << GPIO_PUPD_PUPD1_POS)          /**< 0x0000000C */
#define GPIO_PUPD_PUPD1                GPIO_PUPD_PUPD1_MASK
#define GPIO_PUPD_PUPD2_POS            (4U)
#define GPIO_PUPD_PUPD2_MASK           (0x3UL << GPIO_PUPD_PUPD2_POS)          /**< 0x00000030 */
#define GPIO_PUPD_PUPD2                GPIO_PUPD_PUPD2_MASK
#define GPIO_PUPD_PUPD3_POS            (6U)
#define GPIO_PUPD_PUPD3_MASK           (0x3UL << GPIO_PUPD_PUPD3_POS)          /**< 0x000000C0 */
#define GPIO_PUPD_PUPD3                GPIO_PUPD_PUPD3_MASK
#define GPIO_PUPD_PUPD4_POS            (8U)
#define GPIO_PUPD_PUPD4_MASK           (0x3UL << GPIO_PUPD_PUPD4_POS)          /**< 0x00000300 */
#define GPIO_PUPD_PUPD4                GPIO_PUPD_PUPD4_MASK
#define GPIO_PUPD_PUPD5_POS            (10U)
#define GPIO_PUPD_PUPD5_MASK           (0x3UL << GPIO_PUPD_PUPD5_POS)          /**< 0x00000C00 */
#define GPIO_PUPD_PUPD5                GPIO_PUPD_PUPD5_MASK
#define GPIO_PUPD_PUPD6_POS            (12U)
#define GPIO_PUPD_PUPD6_MASK           (0x3UL << GPIO_PUPD_PUPD6_POS)          /**< 0x00003000 */
#define GPIO_PUPD_PUPD6                GPIO_PUPD_PUPD6_MASK
#define GPIO_PUPD_PUPD7_POS            (14U)
#define GPIO_PUPD_PUPD7_MASK           (0x3UL << GPIO_PUPD_PUPD7_POS)          /**< 0x0000C000 */
#define GPIO_PUPD_PUPD7                GPIO_PUPD_PUPD7_MASK
#define GPIO_PUPD_PUPD8_POS            (16U)
#define GPIO_PUPD_PUPD8_MASK           (0x3UL << GPIO_PUPD_PUPD8_POS)          /**< 0x00030000 */
#define GPIO_PUPD_PUPD8                GPIO_PUPD_PUPD8_MASK
#define GPIO_PUPD_PUPD9_POS            (18U)
#define GPIO_PUPD_PUPD9_MASK           (0x3UL << GPIO_PUPD_PUPD9_POS)          /**< 0x000C0000 */
#define GPIO_PUPD_PUPD9                GPIO_PUPD_PUPD9_MASK
#define GPIO_PUPD_PUPD10_POS           (20U)
#define GPIO_PUPD_PUPD10_MASK          (0x3UL << GPIO_PUPD_PUPD10_POS)         /**< 0x00300000 */
#define GPIO_PUPD_PUPD10               GPIO_PUPD_PUPD10_MASK
#define GPIO_PUPD_PUPD11_POS           (22U)
#define GPIO_PUPD_PUPD11_MASK          (0x3UL << GPIO_PUPD_PUPD11_POS)         /**< 0x00C00000 */
#define GPIO_PUPD_PUPD11               GPIO_PUPD_PUPD11_MASK
#define GPIO_PUPD_PUPD12_POS           (24U)
#define GPIO_PUPD_PUPD12_MASK          (0x3UL << GPIO_PUPD_PUPD12_POS)         /**< 0x03000000 */
#define GPIO_PUPD_PUPD12               GPIO_PUPD_PUPD12_MASK
#define GPIO_PUPD_PUPD13_POS           (26U)
#define GPIO_PUPD_PUPD13_MASK          (0x3UL << GPIO_PUPD_PUPD13_POS)         /**< 0x0C000000 */
#define GPIO_PUPD_PUPD13               GPIO_PUPD_PUPD13_MASK
#define GPIO_PUPD_PUPD14_POS           (28U)
#define GPIO_PUPD_PUPD14_MASK          (0x3UL << GPIO_PUPD_PUPD14_POS)         /**< 0x30000000 */
#define GPIO_PUPD_PUPD14               GPIO_PUPD_PUPD14_MASK
#define GPIO_PUPD_PUPD15_POS           (30U)
#define GPIO_PUPD_PUPD15_MASK          (0x3UL << GPIO_PUPD_PUPD15_POS)         /**< 0xC0000000 */
#define GPIO_PUPD_PUPD15               GPIO_PUPD_PUPD15_MASK

/* Bits for GPIO_IDR */
#define GPIO_IDR_ID0_POS               (0U)
#define GPIO_IDR_ID0_MASK              (0x1UL << GPIO_IDR_ID0_POS)             /**< 0x00000001 */
#define GPIO_IDR_ID0                   GPIO_IDR_ID0_MASK
#define GPIO_IDR_ID1_POS               (1U)
#define GPIO_IDR_ID1_MASK              (0x1UL << GPIO_IDR_ID1_POS)             /**< 0x00000002 */
#define GPIO_IDR_ID1                   GPIO_IDR_ID1_MASK
#define GPIO_IDR_ID2_POS               (2U)
#define GPIO_IDR_ID2_MASK              (0x1UL << GPIO_IDR_ID2_POS)             /**< 0x00000004 */
#define GPIO_IDR_ID2                   GPIO_IDR_ID2_MASK
#define GPIO_IDR_ID3_POS               (3U)
#define GPIO_IDR_ID3_MASK              (0x1UL << GPIO_IDR_ID3_POS)             /**< 0x00000008 */
#define GPIO_IDR_ID3                   GPIO_IDR_ID3_MASK
#define GPIO_IDR_ID4_POS               (4U)
#define GPIO_IDR_ID4_MASK              (0x1UL << GPIO_IDR_ID4_POS)             /**< 0x00000010 */
#define GPIO_IDR_ID4                   GPIO_IDR_ID4_MASK
#define GPIO_IDR_ID5_POS               (5U)
#define GPIO_IDR_ID5_MASK              (0x1UL << GPIO_IDR_ID5_POS)             /**< 0x00000020 */
#define GPIO_IDR_ID5                   GPIO_IDR_ID5_MASK
#define GPIO_IDR_ID6_POS               (6U)
#define GPIO_IDR_ID6_MASK              (0x1UL << GPIO_IDR_ID6_POS)             /**< 0x00000040 */
#define GPIO_IDR_ID6                   GPIO_IDR_ID6_MASK
#define GPIO_IDR_ID7_POS               (7U)
#define GPIO_IDR_ID7_MASK              (0x1UL << GPIO_IDR_ID7_POS)             /**< 0x00000080 */
#define GPIO_IDR_ID7                   GPIO_IDR_ID7_MASK
#define GPIO_IDR_ID8_POS               (8U)
#define GPIO_IDR_ID8_MASK              (0x1UL << GPIO_IDR_ID8_POS)             /**< 0x00000100 */
#define GPIO_IDR_ID8                   GPIO_IDR_ID8_MASK
#define GPIO_IDR_ID9_POS               (9U)
#define GPIO_IDR_ID9_MASK              (0x1UL << GPIO_IDR_ID9_POS)             /**< 0x00000200 */
#define GPIO_IDR_ID9                   GPIO_IDR_ID9_MASK
#define GPIO_IDR_ID10_POS              (10U)
#define GPIO_IDR_ID10_MASK             (0x1UL << GPIO_IDR_ID10_POS)            /**< 0x00000400 */
#define GPIO_IDR_ID10                  GPIO_IDR_ID10_MASK
#define GPIO_IDR_ID11_POS              (11U)
#define GPIO_IDR_ID11_MASK             (0x1UL << GPIO_IDR_ID11_POS)            /**< 0x00000800 */
#define GPIO_IDR_ID11                  GPIO_IDR_ID11_MASK
#define GPIO_IDR_ID12_POS              (12U)
#define GPIO_IDR_ID12_MASK             (0x1UL << GPIO_IDR_ID12_POS)            /**< 0x00001000 */
#define GPIO_IDR_ID12                  GPIO_IDR_ID12_MASK
#define GPIO_IDR_ID13_POS              (13U)
#define GPIO_IDR_ID13_MASK             (0x1UL << GPIO_IDR_ID13_POS)            /**< 0x00002000 */
#define GPIO_IDR_ID13                  GPIO_IDR_ID13_MASK
#define GPIO_IDR_ID14_POS              (14U)
#define GPIO_IDR_ID14_MASK             (0x1UL << GPIO_IDR_ID14_POS)            /**< 0x00004000 */
#define GPIO_IDR_ID14                  GPIO_IDR_ID14_MASK
#define GPIO_IDR_ID15_POS              (15U)
#define GPIO_IDR_ID15_MASK             (0x1UL << GPIO_IDR_ID15_POS)            /**< 0x00008000 */
#define GPIO_IDR_ID15                  GPIO_IDR_ID15_MASK

/* Bits for GPIO_ODR */
#define GPIO_ODR_OD0_POS               (0U)
#define GPIO_ODR_OD0_MASK              (0x1UL << GPIO_ODR_OD0_POS)             /**< 0x00000001 */
#define GPIO_ODR_OD0                   GPIO_ODR_OD0_MASK
#define GPIO_ODR_OD1_POS               (1U)
#define GPIO_ODR_OD1_MASK              (0x1UL << GPIO_ODR_OD1_POS)             /**< 0x00000002 */
#define GPIO_ODR_OD1                   GPIO_ODR_OD1_MASK
#define GPIO_ODR_OD2_POS               (2U)
#define GPIO_ODR_OD2_MASK              (0x1UL << GPIO_ODR_OD2_POS)             /**< 0x00000004 */
#define GPIO_ODR_OD2                   GPIO_ODR_OD2_MASK
#define GPIO_ODR_OD3_POS               (3U)
#define GPIO_ODR_OD3_MASK              (0x1UL << GPIO_ODR_OD3_POS)             /**< 0x00000008 */
#define GPIO_ODR_OD3                   GPIO_ODR_OD3_MASK
#define GPIO_ODR_OD4_POS               (4U)
#define GPIO_ODR_OD4_MASK              (0x1UL << GPIO_ODR_OD4_POS)             /**< 0x00000010 */
#define GPIO_ODR_OD4                   GPIO_ODR_OD4_MASK
#define GPIO_ODR_OD5_POS               (5U)
#define GPIO_ODR_OD5_MASK              (0x1UL << GPIO_ODR_OD5_POS)             /**< 0x00000020 */
#define GPIO_ODR_OD5                   GPIO_ODR_OD5_MASK
#define GPIO_ODR_OD6_POS               (6U)
#define GPIO_ODR_OD6_MASK              (0x1UL << GPIO_ODR_OD6_POS)             /**< 0x00000040 */
#define GPIO_ODR_OD6                   GPIO_ODR_OD6_MASK
#define GPIO_ODR_OD7_POS               (7U)
#define GPIO_ODR_OD7_MASK              (0x1UL << GPIO_ODR_OD7_POS)             /**< 0x00000080 */
#define GPIO_ODR_OD7                   GPIO_ODR_OD7_MASK
#define GPIO_ODR_OD8_POS               (8U)
#define GPIO_ODR_OD8_MASK              (0x1UL << GPIO_ODR_OD8_POS)             /**< 0x00000100 */
#define GPIO_ODR_OD8                   GPIO_ODR_OD8_MASK
#define GPIO_ODR_OD9_POS               (9U)
#define GPIO_ODR_OD9_MASK              (0x1UL << GPIO_ODR_OD9_POS)             /**< 0x00000200 */
#define GPIO_ODR_OD9                   GPIO_ODR_OD9_MASK
#define GPIO_ODR_OD10_POS              (10U)
#define GPIO_ODR_OD10_MASK             (0x1UL << GPIO_ODR_OD10_POS)            /**< 0x00000400 */
#define GPIO_ODR_OD10                  GPIO_ODR_OD10_MASK
#define GPIO_ODR_OD11_POS              (11U)
#define GPIO_ODR_OD11_MASK             (0x1UL << GPIO_ODR_OD11_POS)            /**< 0x00000800 */
#define GPIO_ODR_OD11                  GPIO_ODR_OD11_MASK
#define GPIO_ODR_OD12_POS              (12U)
#define GPIO_ODR_OD12_MASK             (0x1UL << GPIO_ODR_OD12_POS)            /**< 0x00001000 */
#define GPIO_ODR_OD12                  GPIO_ODR_OD12_MASK
#define GPIO_ODR_OD13_POS              (13U)
#define GPIO_ODR_OD13_MASK             (0x1UL << GPIO_ODR_OD13_POS)            /**< 0x00002000 */
#define GPIO_ODR_OD13                  GPIO_ODR_OD13_MASK
#define GPIO_ODR_OD14_POS              (14U)
#define GPIO_ODR_OD14_MASK             (0x1UL << GPIO_ODR_OD14_POS)            /**< 0x00004000 */
#define GPIO_ODR_OD14                  GPIO_ODR_OD14_MASK
#define GPIO_ODR_OD15_POS              (15U)
#define GPIO_ODR_OD15_MASK             (0x1UL << GPIO_ODR_OD15_POS)            /**< 0x00008000 */
#define GPIO_ODR_OD15                  GPIO_ODR_OD15_MASK

/* Bits for GPIO_BSRR */
#define GPIO_BSR_BS0_POS               (0U)
#define GPIO_BSR_BS0_MASK              (0x1UL << GPIO_BSR_BS0_POS)             /**< 0x00000001 */
#define GPIO_BSR_BS0                   GPIO_BSR_BS0_MASK
#define GPIO_BSR_BS1_POS               (1U)
#define GPIO_BSR_BS1_MASK              (0x1UL << GPIO_BSR_BS1_POS)             /**< 0x00000002 */
#define GPIO_BSR_BS1                   GPIO_BSR_BS1_MASK
#define GPIO_BSR_BS2_POS               (2U)
#define GPIO_BSR_BS2_MASK              (0x1UL << GPIO_BSR_BS2_POS)             /**< 0x00000004 */
#define GPIO_BSR_BS2                   GPIO_BSR_BS2_MASK
#define GPIO_BSR_BS3_POS               (3U)
#define GPIO_BSR_BS3_MASK              (0x1UL << GPIO_BSR_BS3_POS)             /**< 0x00000008 */
#define GPIO_BSR_BS3                   GPIO_BSR_BS3_MASK
#define GPIO_BSR_BS4_POS               (4U)
#define GPIO_BSR_BS4_MASK              (0x1UL << GPIO_BSR_BS4_POS)             /**< 0x00000010 */
#define GPIO_BSR_BS4                   GPIO_BSR_BS4_MASK
#define GPIO_BSR_BS5_POS               (5U)
#define GPIO_BSR_BS5_MASK              (0x1UL << GPIO_BSR_BS5_POS)             /**< 0x00000020 */
#define GPIO_BSR_BS5                   GPIO_BSR_BS5_MASK
#define GPIO_BSR_BS6_POS               (6U)
#define GPIO_BSR_BS6_MASK              (0x1UL << GPIO_BSR_BS6_POS)             /**< 0x00000040 */
#define GPIO_BSR_BS6                   GPIO_BSR_BS6_MASK
#define GPIO_BSR_BS7_POS               (7U)
#define GPIO_BSR_BS7_MASK              (0x1UL << GPIO_BSR_BS7_POS)             /**< 0x00000080 */
#define GPIO_BSR_BS7                   GPIO_BSR_BS7_MASK
#define GPIO_BSR_BS8_POS               (8U)
#define GPIO_BSR_BS8_MASK              (0x1UL << GPIO_BSR_BS8_POS)             /**< 0x00000100 */
#define GPIO_BSR_BS8                   GPIO_BSR_BS8_MASK
#define GPIO_BSR_BS9_POS               (9U)
#define GPIO_BSR_BS9_MASK              (0x1UL << GPIO_BSR_BS9_POS)             /**< 0x00000200 */
#define GPIO_BSR_BS9                   GPIO_BSR_BS9_MASK
#define GPIO_BSR_BS10_POS              (10U)
#define GPIO_BSR_BS10_MASK             (0x1UL << GPIO_BSR_BS10_POS)            /**< 0x00000400 */
#define GPIO_BSR_BS10                  GPIO_BSR_BS10_MASK
#define GPIO_BSR_BS11_POS              (11U)
#define GPIO_BSR_BS11_MASK             (0x1UL << GPIO_BSR_BS11_POS)            /**< 0x00000800 */
#define GPIO_BSR_BS11                  GPIO_BSR_BS11_MASK
#define GPIO_BSR_BS12_POS              (12U)
#define GPIO_BSR_BS12_MASK             (0x1UL << GPIO_BSR_BS12_POS)            /**< 0x00001000 */
#define GPIO_BSR_BS12                  GPIO_BSR_BS12_MASK
#define GPIO_BSR_BS13_POS              (13U)
#define GPIO_BSR_BS13_MASK             (0x1UL << GPIO_BSR_BS13_POS)            /**< 0x00002000 */
#define GPIO_BSR_BS13                  GPIO_BSR_BS13_MASK
#define GPIO_BSR_BS14_POS              (14U)
#define GPIO_BSR_BS14_MASK             (0x1UL << GPIO_BSR_BS14_POS)            /**< 0x00004000 */
#define GPIO_BSR_BS14                  GPIO_BSR_BS14_MASK
#define GPIO_BSR_BS15_POS              (15U)
#define GPIO_BSR_BS15_MASK             (0x1UL << GPIO_BSR_BS15_POS)            /**< 0x00008000 */
#define GPIO_BSR_BS15                  GPIO_BSR_BS15_MASK
#define GPIO_BSR_BR0_POS               (16U)
#define GPIO_BSR_BR0_MASK              (0x1UL << GPIO_BSR_BR0_POS)             /**< 0x00010000 */
#define GPIO_BSR_BR0                   GPIO_BSR_BR0_MASK
#define GPIO_BSR_BR1_POS               (17U)
#define GPIO_BSR_BR1_MASK              (0x1UL << GPIO_BSR_BR1_POS)             /**< 0x00020000 */
#define GPIO_BSR_BR1                   GPIO_BSR_BR1_MASK
#define GPIO_BSR_BR2_POS               (18U)
#define GPIO_BSR_BR2_MASK              (0x1UL << GPIO_BSR_BR2_POS)             /**< 0x00040000 */
#define GPIO_BSR_BR2                   GPIO_BSR_BR2_MASK
#define GPIO_BSR_BR3_POS               (19U)
#define GPIO_BSR_BR3_MASK              (0x1UL << GPIO_BSR_BR3_POS)             /**< 0x00080000 */
#define GPIO_BSR_BR3                   GPIO_BSR_BR3_MASK
#define GPIO_BSR_BR4_POS               (20U)
#define GPIO_BSR_BR4_MASK              (0x1UL << GPIO_BSR_BR4_POS)             /**< 0x00100000 */
#define GPIO_BSR_BR4                   GPIO_BSR_BR4_MASK
#define GPIO_BSR_BR5_POS               (21U)
#define GPIO_BSR_BR5_MASK              (0x1UL << GPIO_BSR_BR5_POS)             /**< 0x00200000 */
#define GPIO_BSR_BR5                   GPIO_BSR_BR5_MASK
#define GPIO_BSR_BR6_POS               (22U)
#define GPIO_BSR_BR6_MASK              (0x1UL << GPIO_BSR_BR6_POS)             /**< 0x00400000 */
#define GPIO_BSR_BR6                   GPIO_BSR_BR6_MASK
#define GPIO_BSR_BR7_POS               (23U)
#define GPIO_BSR_BR7_MASK              (0x1UL << GPIO_BSR_BR7_POS)             /**< 0x00800000 */
#define GPIO_BSR_BR7                   GPIO_BSR_BR7_MASK
#define GPIO_BSR_BR8_POS               (24U)
#define GPIO_BSR_BR8_MASK              (0x1UL << GPIO_BSR_BR8_POS)             /**< 0x01000000 */
#define GPIO_BSR_BR8                   GPIO_BSR_BR8_MASK
#define GPIO_BSR_BR9_POS               (25U)
#define GPIO_BSR_BR9_MASK              (0x1UL << GPIO_BSR_BR9_POS)             /**< 0x02000000 */
#define GPIO_BSR_BR9                   GPIO_BSR_BR9_MASK
#define GPIO_BSR_BR10_POS              (26U)
#define GPIO_BSR_BR10_MASK             (0x1UL << GPIO_BSR_BR10_POS)            /**< 0x04000000 */
#define GPIO_BSR_BR10                  GPIO_BSR_BR10_MASK
#define GPIO_BSR_BR11_POS              (27U)
#define GPIO_BSR_BR11_MASK             (0x1UL << GPIO_BSR_BR11_POS)            /**< 0x08000000 */
#define GPIO_BSR_BR11                  GPIO_BSR_BR11_MASK
#define GPIO_BSR_BR12_POS              (28U)
#define GPIO_BSR_BR12_MASK             (0x1UL << GPIO_BSR_BR12_POS)            /**< 0x10000000 */
#define GPIO_BSR_BR12                  GPIO_BSR_BR12_MASK
#define GPIO_BSR_BR13_POS              (29U)
#define GPIO_BSR_BR13_MASK             (0x1UL << GPIO_BSR_BR13_POS)            /**< 0x20000000 */
#define GPIO_BSR_BR13                  GPIO_BSR_BR13_MASK
#define GPIO_BSR_BR14_POS              (30U)
#define GPIO_BSR_BR14_MASK             (0x1UL << GPIO_BSR_BR14_POS)            /**< 0x40000000 */
#define GPIO_BSR_BR14                  GPIO_BSR_BR14_MASK
#define GPIO_BSR_BR15_POS              (31U)
#define GPIO_BSR_BR15_MASK             (0x1UL << GPIO_BSR_BR15_POS)            /**< 0x80000000 */
#define GPIO_BSR_BR15                  GPIO_BSR_BR15_MASK

/* Bits for GPIO_AFRL */
#define GPIO_AFL_AFSEL0_POS           (0U)
#define GPIO_AFL_AFSEL0_MASK          (0x7UL << GPIO_AFL_AFSEL0_POS)           /**< 0x00000007 */
#define GPIO_AFL_AFSEL0               GPIO_AFL_AFSEL0_MASK
#define GPIO_AFL_AFSEL1_POS           (4U)
#define GPIO_AFL_AFSEL1_MASK          (0x7UL << GPIO_AFL_AFSEL1_POS)           /**< 0x00000070 */
#define GPIO_AFL_AFSEL1               GPIO_AFL_AFSEL1_MASK
#define GPIO_AFL_AFSEL2_POS           (8U)
#define GPIO_AFL_AFSEL2_MASK          (0x7UL << GPIO_AFL_AFSEL2_POS)           /**< 0x00000700 */
#define GPIO_AFL_AFSEL2               GPIO_AFL_AFSEL2_MASK
#define GPIO_AFL_AFSEL3_POS           (12U)
#define GPIO_AFL_AFSEL3_MASK          (0x7UL << GPIO_AFL_AFSEL3_POS)           /**< 0x00007000 */
#define GPIO_AFL_AFSEL3               GPIO_AFL_AFSEL3_MASK
#define GPIO_AFL_AFSEL4_POS           (16U)
#define GPIO_AFL_AFSEL4_MASK          (0x7UL << GPIO_AFL_AFSEL4_POS)           /**< 0x00070000 */
#define GPIO_AFL_AFSEL4               GPIO_AFL_AFSEL4_MASK
#define GPIO_AFL_AFSEL5_POS           (20U)
#define GPIO_AFL_AFSEL5_MASK          (0x7UL << GPIO_AFL_AFSEL5_POS)           /**< 0x00700000 */
#define GPIO_AFL_AFSEL5               GPIO_AFL_AFSEL5_MASK
#define GPIO_AFL_AFSEL6_POS           (24U)
#define GPIO_AFL_AFSEL6_MASK          (0x7UL << GPIO_AFL_AFSEL6_POS)           /**< 0x07000000 */
#define GPIO_AFL_AFSEL6               GPIO_AFL_AFSEL6_MASK
#define GPIO_AFL_AFSEL7_POS           (28U)
#define GPIO_AFL_AFSEL7_MASK          (0x7UL << GPIO_AFL_AFSEL7_POS)           /**< 0x70000000 */
#define GPIO_AFL_AFSEL7               GPIO_AFL_AFSEL7_MASK

/* Bits for GPIO_AFRH */
#define GPIO_AFH_AFSEL8_POS           (0U)
#define GPIO_AFH_AFSEL8_MASK          (0x7UL << GPIO_AFH_AFSEL8_POS)           /**< 0x00000007 */
#define GPIO_AFH_AFSEL8               GPIO_AFH_AFSEL8_MASK
#define GPIO_AFH_AFSEL9_POS           (4U)
#define GPIO_AFH_AFSEL9_MASK          (0x7UL << GPIO_AFH_AFSEL9_POS)           /**< 0x00000070 */
#define GPIO_AFH_AFSEL9               GPIO_AFH_AFSEL9_MASK
#define GPIO_AFH_AFSEL10_POS          (8U)
#define GPIO_AFH_AFSEL10_MASK         (0x7UL << GPIO_AFH_AFSEL10_POS)          /**< 0x00000700 */
#define GPIO_AFH_AFSEL10              GPIO_AFH_AFSEL10_MASK
#define GPIO_AFH_AFSEL11_POS          (12U)
#define GPIO_AFH_AFSEL11_MASK         (0x7UL << GPIO_AFH_AFSEL11_POS)          /**< 0x00007000 */
#define GPIO_AFH_AFSEL11              GPIO_AFH_AFSEL11_MASK
#define GPIO_AFH_AFSEL12_POS          (16U)
#define GPIO_AFH_AFSEL12_MASK         (0x7UL << GPIO_AFH_AFSEL12_POS)          /**< 0x00070000 */
#define GPIO_AFH_AFSEL12              GPIO_AFH_AFSEL12_MASK
#define GPIO_AFH_AFSEL13_POS          (20U)
#define GPIO_AFH_AFSEL13_MASK         (0x7UL << GPIO_AFH_AFSEL13_POS)          /**< 0x00700000 */
#define GPIO_AFH_AFSEL13              GPIO_AFH_AFSEL13_MASK
#define GPIO_AFH_AFSEL14_POS          (24U)
#define GPIO_AFH_AFSEL14_MASK         (0x7UL << GPIO_AFH_AFSEL14_POS)          /**< 0x07000000 */
#define GPIO_AFH_AFSEL14              GPIO_AFH_AFSEL14_MASK
#define GPIO_AFH_AFSEL15_POS          (28U)
#define GPIO_AFH_AFSEL15_MASK         (0x7UL << GPIO_AFH_AFSEL15_POS)          /**< 0x70000000 */
#define GPIO_AFH_AFSEL15              GPIO_AFH_AFSEL15_MASK

/* Bits for GPIO_BRR */
#define GPIO_BR_BR0_POS                (0U)
#define GPIO_BR_BR0_MASK               (0x1UL << GPIO_BR_BR0_POS)              /**< 0x00000001 */
#define GPIO_BR_BR0                    GPIO_BR_BR0_MASK
#define GPIO_BR_BR1_POS                (1U)
#define GPIO_BR_BR1_MASK               (0x1UL << GPIO_BR_BR1_POS)              /**< 0x00000002 */
#define GPIO_BR_BR1                    GPIO_BR_BR1_MASK
#define GPIO_BR_BR2_POS                (2U)
#define GPIO_BR_BR2_MASK               (0x1UL << GPIO_BR_BR2_POS)              /**< 0x00000004 */
#define GPIO_BR_BR2                    GPIO_BR_BR2_MASK
#define GPIO_BR_BR3_POS                (3U)
#define GPIO_BR_BR3_MASK               (0x1UL << GPIO_BR_BR3_POS)              /**< 0x00000008 */
#define GPIO_BR_BR3                    GPIO_BR_BR3_MASK
#define GPIO_BR_BR4_POS                (4U)
#define GPIO_BR_BR4_MASK               (0x1UL << GPIO_BR_BR4_POS)              /**< 0x00000010 */
#define GPIO_BR_BR4                    GPIO_BR_BR4_MASK
#define GPIO_BR_BR5_POS                (5U)
#define GPIO_BR_BR5_MASK               (0x1UL << GPIO_BR_BR5_POS)              /**< 0x00000020 */
#define GPIO_BR_BR5                    GPIO_BR_BR5_MASK
#define GPIO_BR_BR6_POS                (6U)
#define GPIO_BR_BR6_MASK               (0x1UL << GPIO_BR_BR6_POS)              /**< 0x00000040 */
#define GPIO_BR_BR6                    GPIO_BR_BR6_MASK
#define GPIO_BR_BR7_POS                (7U)
#define GPIO_BR_BR7_MASK               (0x1UL << GPIO_BR_BR7_POS)              /**< 0x00000080 */
#define GPIO_BR_BR7                    GPIO_BR_BR7_MASK
#define GPIO_BR_BR8_POS                (8U)
#define GPIO_BR_BR8_MASK               (0x1UL << GPIO_BR_BR8_POS)              /**< 0x00000100 */
#define GPIO_BR_BR8                    GPIO_BR_BR8_MASK
#define GPIO_BR_BR9_POS                (9U)
#define GPIO_BR_BR9_MASK               (0x1UL << GPIO_BR_BR9_POS)              /**< 0x00000200 */
#define GPIO_BR_BR9                    GPIO_BR_BR9_MASK
#define GPIO_BR_BR10_POS               (10U)
#define GPIO_BR_BR10_MASK              (0x1UL << GPIO_BR_BR10_POS)             /**< 0x00000400 */
#define GPIO_BR_BR10                   GPIO_BR_BR10_MASK
#define GPIO_BR_BR11_POS               (11U)
#define GPIO_BR_BR11_MASK              (0x1UL << GPIO_BR_BR11_POS)             /**< 0x00000800 */
#define GPIO_BR_BR11                   GPIO_BR_BR11_MASK
#define GPIO_BR_BR12_POS               (12U)
#define GPIO_BR_BR12_MASK              (0x1UL << GPIO_BR_BR12_POS)             /**< 0x00001000 */
#define GPIO_BR_BR12                   GPIO_BR_BR12_MASK
#define GPIO_BR_BR13_POS               (13U)
#define GPIO_BR_BR13_MASK              (0x1UL << GPIO_BR_BR13_POS)             /**< 0x00002000 */
#define GPIO_BR_BR13                   GPIO_BR_BR13_MASK
#define GPIO_BR_BR14_POS               (14U)
#define GPIO_BR_BR14_MASK              (0x1UL << GPIO_BR_BR14_POS)             /**< 0x00004000 */
#define GPIO_BR_BR14                   GPIO_BR_BR14_MASK
#define GPIO_BR_BR15_POS               (15U)
#define GPIO_BR_BR15_MASK              (0x1UL <<  GPIO_BR_BR15_POS)             /**< 0x00008000 */
#define GPIO_BR_BR15                   GPIO_BR_BR15_MASK

/*  Bits for GPIO_HDCFG */
#define GPIO_HDCFG_HD2_POS             (2U)
#define GPIO_HDCFG_HD2_MASK            (0x1UL << GPIO_HDCFG_HD2_POS)           /**< 0x00000004 */
#define GPIO_HDCFG_HD2                 GPIO_HDCFG_HD2_MASK

/*-----------------------------------------------------------------------------------------------
                                       I2C Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for I2C_CR1 */
#define I2C_CR1_PE_POS               (0U)
#define I2C_CR1_PE_MASK              (0x1UL << I2C_CR1_PE_POS)                 /**< 0x00000001 */
#define I2C_CR1_PE                   I2C_CR1_PE_MASK                           /**< Peripheral enable */
#define I2C_CR1_TXIE_POS             (1U)
#define I2C_CR1_TXIE_MASK            (0x1UL << I2C_CR1_TXIE_POS)               /**< 0x00000002 */
#define I2C_CR1_TXIE                 I2C_CR1_TXIE_MASK                         /**< TX interrupt enable */
#define I2C_CR1_RXIE_POS             (2U)
#define I2C_CR1_RXIE_MASK            (0x1UL << I2C_CR1_RXIE_POS)               /**< 0x00000004 */
#define I2C_CR1_RXIE                 I2C_CR1_RXIE_MASK                         /**< RX interrupt enable */
#define I2C_CR1_ADDRIE_POS           (3U)
#define I2C_CR1_ADDRIE_MASK          (0x1UL << I2C_CR1_ADDRIE_POS)             /**< 0x00000008 */
#define I2C_CR1_ADDRIE               I2C_CR1_ADDRIE_MASK                       /**< Address match interrupt enable */
#define I2C_CR1_NACKIE_POS           (4U)
#define I2C_CR1_NACKIE_MASK          (0x1UL << I2C_CR1_NACKIE_POS)             /**< 0x00000010 */
#define I2C_CR1_NACKIE               I2C_CR1_NACKIE_MASK                       /**< NACK received interrupt enable */
#define I2C_CR1_STOPIE_POS           (5U)
#define I2C_CR1_STOPIE_MASK          (0x1UL << I2C_CR1_STOPIE_POS)             /**< 0x00000020 */
#define I2C_CR1_STOPIE               I2C_CR1_STOPIE_MASK                       /**< STOP detection interrupt enable */
#define I2C_CR1_TCIE_POS             (6U)
#define I2C_CR1_TCIE_MASK            (0x1UL << I2C_CR1_TCIE_POS)               /**< 0x00000040 */
#define I2C_CR1_TCIE                 I2C_CR1_TCIE_MASK                         /**< Transfer complete interrupt enable */
#define I2C_CR1_ERRIE_POS            (7U)
#define I2C_CR1_ERRIE_MASK           (0x1UL << I2C_CR1_ERRIE_POS)              /**< 0x00000080 */
#define I2C_CR1_ERRIE                I2C_CR1_ERRIE_MASK                        /**< Errors interrupt enable */

#define I2C_CR1_DNF_POS              (8U)
#define I2C_CR1_DNF_MASK             (0xFUL << I2C_CR1_DNF_POS)                /**< 0x00000F00 */
#define I2C_CR1_DNF                  I2C_CR1_DNF_MASK                          /**< Digital noise filter */
#define I2C_CR1_DNF_DISABLE          (0x0UL << I2C_CR1_DNF_POS)                /**< 0x00000000 */
#define I2C_CR1_DNF_1CLK             (0x1UL << I2C_CR1_DNF_POS)                /**< 0x00000100 */
#define I2C_CR1_DNF_2CLK             (0x2UL << I2C_CR1_DNF_POS)                /**< 0x00000200 */
#define I2C_CR1_DNF_3CLK             (0x3UL << I2C_CR1_DNF_POS)                /**< 0x00000300 */
#define I2C_CR1_DNF_4CLK             (0x4UL << I2C_CR1_DNF_POS)                /**< 0x00000400 */
#define I2C_CR1_DNF_5CLK             (0x5UL << I2C_CR1_DNF_POS)                /**< 0x00000500 */
#define I2C_CR1_DNF_6CLK             (0x6UL << I2C_CR1_DNF_POS)                /**< 0x00000600 */
#define I2C_CR1_DNF_7CLK             (0x7UL << I2C_CR1_DNF_POS)                /**< 0x00000700 */
#define I2C_CR1_DNF_8CLK             (0x8UL << I2C_CR1_DNF_POS)                /**< 0x00000800 */
#define I2C_CR1_DNF_9CLK             (0x9UL << I2C_CR1_DNF_POS)                /**< 0x00000900 */
#define I2C_CR1_DNF_10CLK            (0xAUL << I2C_CR1_DNF_POS)                /**< 0x00000A00 */
#define I2C_CR1_DNF_11CLK            (0xBUL << I2C_CR1_DNF_POS)                /**< 0x00000B00 */
#define I2C_CR1_DNF_12CLK            (0xCUL << I2C_CR1_DNF_POS)                /**< 0x00000C00 */
#define I2C_CR1_DNF_13CLK            (0xDUL << I2C_CR1_DNF_POS)                /**< 0x00000D00 */
#define I2C_CR1_DNF_14CLK            (0xEUL << I2C_CR1_DNF_POS)                /**< 0x00000E00 */
#define I2C_CR1_DNF_15CLK            (0xFUL << I2C_CR1_DNF_POS)                /**< 0x00000F00 */

#define I2C_CR1_TXDMAEN_POS          (14U)
#define I2C_CR1_TXDMAEN_MASK         (0x1UL << I2C_CR1_TXDMAEN_POS)            /**< 0x00004000 */
#define I2C_CR1_TXDMAEN              I2C_CR1_TXDMAEN_MASK                      /**< DMA transmission requests enable */
#define I2C_CR1_RXDMAEN_POS          (15U)
#define I2C_CR1_RXDMAEN_MASK         (0x1UL << I2C_CR1_RXDMAEN_POS)            /**< 0x00008000 */
#define I2C_CR1_RXDMAEN              I2C_CR1_RXDMAEN_MASK                      /**< DMA reception requests enable */
#define I2C_CR1_SBC_POS              (16U)
#define I2C_CR1_SBC_MASK             (0x1UL << I2C_CR1_SBC_POS)                /**< 0x00010000 */
#define I2C_CR1_SBC                  I2C_CR1_SBC_MASK                          /**< Slave byte control */
#define I2C_CR1_NOSTRETCH_POS        (17U)
#define I2C_CR1_NOSTRETCH_MASK       (0x1UL << I2C_CR1_NOSTRETCH_POS)          /**< 0x00020000 */
#define I2C_CR1_NOSTRETCH            I2C_CR1_NOSTRETCH_MASK                    /**< Clock stretching disable */
#define I2C_CR1_WUPEN_POS            (18U)
#define I2C_CR1_WUPEN_MASK           (0x1UL << I2C_CR1_WUPEN_POS)              /**< 0x00040000 */
#define I2C_CR1_WUPEN                I2C_CR1_WUPEN_MASK                        /**< Stop mode wakeup enable */
#define I2C_CR1_GCEN_POS             (19U)
#define I2C_CR1_GCEN_MASK            (0x1UL << I2C_CR1_GCEN_POS)               /**< 0x00080000 */
#define I2C_CR1_GCEN                 I2C_CR1_GCEN_MASK                         /**< General call enable */

/* Bits for I2C_CR2 */
#define I2C_CR2_SADDR_POS            (0U)
#define I2C_CR2_SADDR_MASK           (0x3FFUL << I2C_CR2_SADDR_POS)            /**< 0x000003FF */
#define I2C_CR2_SADDR                I2C_CR2_SADDR_MASK                        /**< Slave address (master mode) */
#define I2C_CR2_RD_WRN_POS           (10U)
#define I2C_CR2_RD_WRN_MASK          (0x1UL << I2C_CR2_RD_WRN_POS)             /**< 0x00000400 */
#define I2C_CR2_RD_WRN               I2C_CR2_RD_WRN_MASK                       /**< Transfer direction (master mode) */
#define I2C_CR2_ADDR10_POS           (11U)
#define I2C_CR2_ADDR10_MASK          (0x1UL << I2C_CR2_ADDR10_POS)             /**< 0x00000800 */
#define I2C_CR2_ADDR10               I2C_CR2_ADDR10_MASK                       /**< 10-bit addressing mode (master mode) */
#define I2C_CR2_HEAD10R_POS          (12U)
#define I2C_CR2_HEAD10R_MASK         (0x1UL << I2C_CR2_HEAD10R_POS)            /**< 0x00001000 */
#define I2C_CR2_HEAD10R              I2C_CR2_HEAD10R_MASK                      /**< 10-bit address header only read direction (master mode) */
#define I2C_CR2_START_POS            (13U)
#define I2C_CR2_START_MASK           (0x1UL << I2C_CR2_START_POS)              /**< 0x00002000 */
#define I2C_CR2_START                I2C_CR2_START_MASK                        /**< START generation */
#define I2C_CR2_STOP_POS             (14U)
#define I2C_CR2_STOP_MASK            (0x1UL << I2C_CR2_STOP_POS)               /**< 0x00004000 */
#define I2C_CR2_STOP                 I2C_CR2_STOP_MASK                         /**< STOP generation (master mode) */
#define I2C_CR2_NACK_POS             (15U)
#define I2C_CR2_NACK_MASK            (0x1UL << I2C_CR2_NACK_POS)               /**< 0x00008000 */
#define I2C_CR2_NACK                 I2C_CR2_NACK_MASK                         /**< NACK generation (slave mode) */
#define I2C_CR2_NBYTES_POS           (16U)
#define I2C_CR2_NBYTES_MASK          (0xFFUL << I2C_CR2_NBYTES_POS)            /**< 0x00FF0000 */
#define I2C_CR2_NBYTES               I2C_CR2_NBYTES_MASK                       /**< Number of bytes */
#define I2C_CR2_RELOAD_POS           (24U)
#define I2C_CR2_RELOAD_MASK          (0x1UL << I2C_CR2_RELOAD_POS)             /**< 0x01000000 */
#define I2C_CR2_RELOAD               I2C_CR2_RELOAD_MASK                       /**< NBYTES reload mode */
#define I2C_CR2_AUTOEND_POS          (25U)
#define I2C_CR2_AUTOEND_MASK         (0x1UL << I2C_CR2_AUTOEND_POS)            /**< 0x02000000 */
#define I2C_CR2_AUTOEND              I2C_CR2_AUTOEND_MASK                      /**< Automatic end mode (master mode) */

/* Bits for I2C_ADDR1 */
#define I2C_ADDR1_ADDR1_POS          (0U)
#define I2C_ADDR1_ADDR1_MASK         (0x3FFUL << I2C_ADDR1_ADDR1_POS)          /**< 0x000003FF */
#define I2C_ADDR1_ADDR1              I2C_ADDR1_ADDR1_MASK                      /**< Interface  address 1 */
#define I2C_ADDR1_ADDR1MODE_POS      (10U)
#define I2C_ADDR1_ADDR1MODE_MASK     (0x1UL << I2C_ADDR1_ADDR1MODE_POS)        /**< 0x00000400 */
#define I2C_ADDR1_ADDR1MODE          I2C_ADDR1_ADDR1MODE_MASK                  /**< Address 1 10-bit mode */
#define I2C_ADDR1_ADDR1EN_POS        (15U)
#define I2C_ADDR1_ADDR1EN_MASK       (0x1UL << I2C_ADDR1_ADDR1EN_POS)          /**< 0x00008000 */
#define I2C_ADDR1_ADDR1EN            I2C_ADDR1_ADDR1EN_MASK                    /**< Address 1 enable */

/* Bits for I2C_ADDR2 */
#define I2C_ADDR2_ADDR2_POS          (1U)
#define I2C_ADDR2_ADDR2_MASK         (0x7FUL << I2C_ADDR2_ADDR2_POS)           /**< 0x000000FE */
#define I2C_ADDR2_ADDR2              I2C_ADDR2_ADDR2_MASK                      /**< Interface  address 2 */
#define I2C_ADDR2_ADDR2MASK_POS      (8U)
#define I2C_ADDR2_ADDR2MASK_MASK     (0x7UL << I2C_ADDR2_ADDR2MASK_POS)        /**< 0x00000700 */
#define I2C_ADDR2_ADDR2MASK           I2C_ADDR2_ADDR2MASK_MASK                 /**< Address 2 masks */
#define I2C_ADDR2_ADDR2EN_POS        (15U)
#define I2C_ADDR2_ADDR2EN_MASK       (0x1UL << I2C_ADDR2_ADDR2EN_POS)          /**< 0x00008000 */
#define I2C_ADDR2_ADDR2EN            I2C_ADDR2_ADDR2EN_MASK                    /**< Address 2 enable */

/* Bits for I2C_TIMING */
#define I2C_TIMING_SCLL_POS          (0U)
#define I2C_TIMING_SCLL_MASK         (0xFFUL << I2C_TIMING_SCLL_POS)           /**< 0x000000FF */
#define I2C_TIMING_SCLL              I2C_TIMING_SCLL_MASK                      /**< SCL low period (master mode) */
#define I2C_TIMING_SCLH_POS          (8U)
#define I2C_TIMING_SCLH_MASK         (0xFFUL << I2C_TIMING_SCLH_POS)           /**< 0x0000FF00 */
#define I2C_TIMING_SCLH              I2C_TIMING_SCLH_MASK                      /**< SCL high period (master mode) */
#define I2C_TIMING_SDADEL_POS        (16U)
#define I2C_TIMING_SDADEL_MASK       (0xFUL << I2C_TIMING_SDADEL_POS)          /**< 0x000F0000 */
#define I2C_TIMING_SDADEL            I2C_TIMING_SDADEL_MASK                    /**< Data hold time */
#define I2C_TIMING_SCLDEL_POS        (20U)
#define I2C_TIMING_SCLDEL_MASK       (0xFUL << I2C_TIMING_SCLDEL_POS)          /**< 0x00F00000 */
#define I2C_TIMING_SCLDEL            I2C_TIMING_SCLDEL_MASK                    /**< Data setup time */
#define I2C_TIMING_PRESC_POS         (28U)
#define I2C_TIMING_PRESC_MASK        (0xFUL << I2C_TIMING_PRESC_POS)           /**< 0xF0000000 */
#define I2C_TIMING_PRESC             I2C_TIMING_PRESC_MASK                     /**< Timings prescaler */

/* Bits for I2C_ISR */
#define I2C_ISR_TXE_POS              (0U)
#define I2C_ISR_TXE_MASK             (0x1UL << I2C_ISR_TXE_POS)                /**< 0x00000001 */
#define I2C_ISR_TXE                  I2C_ISR_TXE_MASK                          /**< Transmit data register empty */
#define I2C_ISR_TXIS_POS             (1U)
#define I2C_ISR_TXIS_MASK            (0x1UL << I2C_ISR_TXIS_POS)               /**< 0x00000002 */
#define I2C_ISR_TXIS                 I2C_ISR_TXIS_MASK                         /**< Transmit interrupt status */
#define I2C_ISR_RXNE_POS             (2U)
#define I2C_ISR_RXNE_MASK            (0x1UL << I2C_ISR_RXNE_POS)               /**< 0x00000004 */
#define I2C_ISR_RXNE                 I2C_ISR_RXNE_MASK                         /**< Receive data register not empty */
#define I2C_ISR_ADDR_POS             (3U)
#define I2C_ISR_ADDR_MASK            (0x1UL << I2C_ISR_ADDR_POS)               /**< 0x00000008 */
#define I2C_ISR_ADDR                 I2C_ISR_ADDR_MASK                         /**< Address matched (slave mode)*/
#define I2C_ISR_NACKF_POS            (4U)
#define I2C_ISR_NACKF_MASK           (0x1UL << I2C_ISR_NACKF_POS)              /**< 0x00000010 */
#define I2C_ISR_NACKF                I2C_ISR_NACKF_MASK                        /**< NACK received flag */
#define I2C_ISR_STOPF_POS            (5U)
#define I2C_ISR_STOPF_MASK           (0x1UL << I2C_ISR_STOPF_POS)              /**< 0x00000020 */
#define I2C_ISR_STOPF                I2C_ISR_STOPF_MASK                        /**< STOP detection flag */
#define I2C_ISR_TC_POS               (6U)
#define I2C_ISR_TC_MASK              (0x1UL << I2C_ISR_TC_POS)                 /**< 0x00000040 */
#define I2C_ISR_TC                   I2C_ISR_TC_MASK                           /**< Transfer complete (master mode) */
#define I2C_ISR_TCR_POS              (7U)
#define I2C_ISR_TCR_MASK             (0x1UL << I2C_ISR_TCR_POS)                /**< 0x00000080 */
#define I2C_ISR_TCR                  I2C_ISR_TCR_MASK                          /**< Transfer complete reload */
#define I2C_ISR_BERR_POS             (8U)
#define I2C_ISR_BERR_MASK            (0x1UL << I2C_ISR_BERR_POS)               /**< 0x00000100 */
#define I2C_ISR_BERR                 I2C_ISR_BERR_MASK                         /**< Bus error */
#define I2C_ISR_ARLO_POS             (9U)
#define I2C_ISR_ARLO_MASK            (0x1UL << I2C_ISR_ARLO_POS)               /**< 0x00000200 */
#define I2C_ISR_ARLO                 I2C_ISR_ARLO_MASK                         /**< Arbitration lost */
#define I2C_ISR_OVR_POS              (10U)
#define I2C_ISR_OVR_MASK             (0x1UL << I2C_ISR_OVR_POS)                /**< 0x00000400 */
#define I2C_ISR_OVR                  I2C_ISR_OVR_MASK                          /**< Overrun/Underrun */
#define I2C_ISR_BUSY_POS             (15U)
#define I2C_ISR_BUSY_MASK            (0x1UL << I2C_ISR_BUSY_POS)               /**< 0x00008000 */
#define I2C_ISR_BUSY                 I2C_ISR_BUSY_MASK                         /**< Bus busy */
#define I2C_ISR_DIR_POS              (16U)
#define I2C_ISR_DIR_MASK             (0x1UL << I2C_ISR_DIR_POS)                /**< 0x00010000 */
#define I2C_ISR_DIR                  I2C_ISR_DIR_MASK                          /**< Transfer direction (slave mode) */
#define I2C_ISR_ADDRCODE_POS         (17U)
#define I2C_ISR_ADDRCODE_MASK        (0x7FUL << I2C_ISR_ADDRCODE_POS)          /**< 0x00FE0000 */
#define I2C_ISR_ADDRCODE             I2C_ISR_ADDRCODE_MASK                     /**< Address match code (slave mode) */

/* Bits for I2C_ICR */
#define I2C_ICR_ADDRCF_POS           (3U)
#define I2C_ICR_ADDRCF_MASK          (0x1UL << I2C_ICR_ADDRCF_POS)             /**< 0x00000008 */
#define I2C_ICR_ADDRCF               I2C_ICR_ADDRCF_MASK                       /**< Address matched clear flag */
#define I2C_ICR_NACKCF_POS           (4U)
#define I2C_ICR_NACKCF_MASK          (0x1UL << I2C_ICR_NACKCF_POS)             /**< 0x00000010 */
#define I2C_ICR_NACKCF               I2C_ICR_NACKCF_MASK                       /**< NACK clear flag */
#define I2C_ICR_STOPCF_POS           (5U)
#define I2C_ICR_STOPCF_MASK          (0x1UL << I2C_ICR_STOPCF_POS)             /**< 0x00000020 */
#define I2C_ICR_STOPCF               I2C_ICR_STOPCF_MASK                       /**< STOP detection clear flag */
#define I2C_ICR_BERRCF_POS           (8U)
#define I2C_ICR_BERRCF_MASK          (0x1UL << I2C_ICR_BERRCF_POS)             /**< 0x00000100 */
#define I2C_ICR_BERRCF               I2C_ICR_BERRCF_MASK                       /**< Bus error clear flag */
#define I2C_ICR_ARLOCF_POS           (9U)
#define I2C_ICR_ARLOCF_MASK          (0x1UL << I2C_ICR_ARLOCF_POS)             /**< 0x00000200 */
#define I2C_ICR_ARLOCF               I2C_ICR_ARLOCF_MASK                       /**< Arbitration lost clear flag */
#define I2C_ICR_OVRCF_POS            (10U)
#define I2C_ICR_OVRCF_MASK           (0x1UL << I2C_ICR_OVRCF_POS)              /**< 0x00000400 */
#define I2C_ICR_OVRCF                I2C_ICR_OVRCF_MASK                        /**< Overrun/Underrun clear flag */

/* Bits for I2C_RDR */
#define I2C_RDR_RXDATA_POS           (0U)
#define I2C_RDR_RXDATA_MASK          (0xFFUL << I2C_RDR_RXDATA_POS)            /**< 0x000000FF */
#define I2C_RDR_RXDATA               I2C_RDR_RXDATA_MASK                       /**< 8-bit receive data */

/* Bits for I2C_TDR */
#define I2C_TDR_TXDATA_POS           (0U)
#define I2C_TDR_TXDATA_MASK          (0xFFUL << I2C_TDR_TXDATA_POS)            /**< 0x000000FF */
#define I2C_TDR_TXDATA               I2C_TDR_TXDATA_MASK                       /**< 8-bit transmit data */


/*-----------------------------------------------------------------------------------------------
                                       IWDG Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for IWDG_CR */
#define IWDG_CR_KEY_POS              (0U)
#define IWDG_CR_KEY_MASK             (0xFFFFUL << IWDG_CR_KEY_POS)              /**< 0x0000FFFF */
#define IWDG_CR_KEY                  IWDG_CR_KEY_MASK                           /**< KEY[15:0] bits(16-bit key value) */

/* Bits for IWDG_CFG */
#define IWDG_CFG_OVP_POS             (0U)
#define IWDG_CFG_OVP_MASK            (0x7UL << IWDG_CFG_OVP_POS)                /**< 0x00000007 */
#define IWDG_CFG_OVP                 IWDG_CFG_OVP_MASK                          /**< OVP[2:0] bits (3-bit overflowperiod value) */
#define IWDG_CFG_OVP_128             (0x0UL << IWDG_CFG_OVP_POS)                /**< 0x00000000 */
#define IWDG_CFG_OVP_256             (0x1UL << IWDG_CFG_OVP_POS)                /**< 0x00000001 */
#define IWDG_CFG_OVP_512             (0x2UL << IWDG_CFG_OVP_POS)                /**< 0x00000002 */
#define IWDG_CFG_OVP_1024            (0x3UL << IWDG_CFG_OVP_POS)                /**< 0x00000003 */
#define IWDG_CFG_OVP_2048            (0x4UL << IWDG_CFG_OVP_POS)                /**< 0x00000004 */
#define IWDG_CFG_OVP_4096            (0x5UL << IWDG_CFG_OVP_POS)                /**< 0x00000005 */
#define IWDG_CFG_OVP_8192            (0x6UL << IWDG_CFG_OVP_POS)                /**< 0x00000006 */
#define IWDG_CFG_OVP_16384           (0x7UL << IWDG_CFG_OVP_POS)                /**< 0x00000007 */

/* Bits for IWDG_WINR */
#define IWDG_WINR_WIN_POS            (0U)
#define IWDG_WINR_WIN_MASK           (0xFFFUL << IWDG_WINR_WIN_POS)             /**< 0x00000FFF */
#define IWDG_WINR_WIN                IWDG_WINR_WIN_MASK                         /**< WIN[11:0] bits (12-bit window value) */

/* Bits for IWDG_CNT */
#define IWDG_CNT_CNT_POS             (0U)
#define IWDG_CNT_CNT_MASK            (0xFFFUL << IWDG_CNT_CNT_POS)              /**< 0x00000FFF */
#define IWDG_CNT_CNT                 IWDG_CNT_CNT_MASK                          /**< CNT[11:0] bits (12-bit counter value) */


/*-----------------------------------------------------------------------------------------------
                                       LCD Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for LCD_CR */
#define LCD_CR_LCDEN_POS                     (0U)      
#define LCD_CR_LCDEN_MASK                    (0x1UL << LCD_CR_LCDEN_POS)                /**< 0x00000001 */
#define LCD_CR_LCDEN                         LCD_CR_LCDEN_MASK                          /**< LCD enable bit */

#define LCD_CR_DUTY_POS                      (2U)      
#define LCD_CR_DUTY_MASK                     (0x3UL << LCD_CR_DUTY_POS)                 /**< 0x0000000C */
#define LCD_CR_DUTY                          LCD_CR_DUTY_MASK                           /**< DUTY[1:0] bits (duty selector) */
#define LCD_CR_DUTY_1_4                      (0x0UL << LCD_CR_DUTY_POS)                 /**< 0x00000000 */
#define LCD_CR_DUTY_1_6                      (0x1UL << LCD_CR_DUTY_POS)                 /**< 0x00000004 */
#define LCD_CR_DUTY_1_8                      (0x2UL << LCD_CR_DUTY_POS)                 /**< 0x00000008 */

#define LCD_CR_BIAS_POS                      (5U)      
#define LCD_CR_BIAS_MASK                     (0x1UL << LCD_CR_BIAS_POS)                 /**< 0x00000020 */
#define LCD_CR_BIAS                          LCD_CR_BIAS_MASK                           /**< BIAS bits (bias selector) */
#define LCD_CR_BIAS_1_3                      (0x0UL << LCD_CR_BIAS_POS)                 /**< 0x00000000 */
#define LCD_CR_BIAS_1_4                      (0x1UL << LCD_CR_BIAS_POS)                 /**< 0x00000020 */

#define LCD_CR_MUX_SEG_POS                   (7U)      
#define LCD_CR_MUX_SEG_MASK                  (0x1UL << LCD_CR_MUX_SEG_POS)              /**< 0x00000080 */
#define LCD_CR_MUX_SEG                       LCD_CR_MUX_SEG_MASK                        /**< Mux segment enable bit */

#define LCD_CR_LCD_CAP_POS                   (8U)     
#define LCD_CR_LCD_CAP_MASK                  (0xFUL << LCD_CR_LCD_CAP_POS)              /**< 0x00000F00 */                
#define LCD_CR_LCD_CAP                       LCD_CR_LCD_CAP_MASK                        /**< LCD_CAP[3:0] bits (capacitance or resistance selector) */                            
#define LCD_CR_LCD_CAP_NONE                  (0x0UL << LCD_CR_LCD_CAP_POS)              /**< 0x00000000 */     
#define LCD_CR_LCD_CAP_V1                    (0x1UL << LCD_CR_LCD_CAP_POS)              /**< 0x00000100 */     
#define LCD_CR_LCD_CAP_V2                    (0x2UL << LCD_CR_LCD_CAP_POS)              /**< 0x00000200 */
#define LCD_CR_LCD_CAP_V3                    (0x4UL << LCD_CR_LCD_CAP_POS)              /**< 0x00000400 */     
#define LCD_CR_LCD_CAP_VLCD                  (0x8UL << LCD_CR_LCD_CAP_POS)              /**< 0x00000800 */
#define LCD_CR_LCD_CAP_VLCD_V2_V1            (0xBUL << LCD_CR_LCD_CAP_POS)              /**< 0x00000B00 */
#define LCD_CR_LCD_CAP_VLCD_V3_V2_V1         (0xFUL << LCD_CR_LCD_CAP_POS)              /**< 0x00000F00 */

#define LCD_CR_MDSET_POS                     (12U)     
#define LCD_CR_MDSET_MASK                    (0x3UL << LCD_CR_MDSET_POS)                /**< 0x00003000 */                
#define LCD_CR_MDSET                         LCD_CR_MDSET_MASK                          /**< LCD_MDSET[1:0] bits (drive mode selector) */                              
#define LCD_CR_MDSET_CHARGE_PUMP             (0x0UL << LCD_CR_MDSET_POS)                /**< 0x00000000 */     
#define LCD_CR_MDSET_OUTER_CAP               (0x1UL << LCD_CR_MDSET_POS)                /**< 0x00001000 */
#define LCD_CR_MDSET_INNER_RES               (0x2UL << LCD_CR_MDSET_POS)                /**< 0x00002000 */       

#define LCD_CR_CPDIV_POS                     (16U)     
#define LCD_CR_CPDIV_MASK                    (0x7UL << LCD_CR_CPDIV_POS)                /**< 0x00070000 */                
#define LCD_CR_CPDIV                         LCD_CR_CPDIV_MASK                          /**< LCD_CPDIV[2:0] bits (charge pump clock divider) */                              
#define LCD_CR_CPDIV_DIV1                    (0x0UL << LCD_CR_CPDIV_POS)                /**< 0x00000000 */     
#define LCD_CR_CPDIV_DIV2                    (0x1UL << LCD_CR_CPDIV_POS)                /**< 0x00010000 */
#define LCD_CR_CPDIV_DIV4                    (0x2UL << LCD_CR_CPDIV_POS)                /**< 0x00020000 */     
#define LCD_CR_CPDIV_DIV8                    (0x3UL << LCD_CR_CPDIV_POS)                /**< 0x00030000 */   
#define LCD_CR_CPDIV_DIV16                   (0x4UL << LCD_CR_CPDIV_POS)                /**< 0x00040000 */  
#define LCD_CR_CPDIV_DIV32                   (0x5UL << LCD_CR_CPDIV_POS)                /**< 0x00050000 */  
#define LCD_CR_CPDIV_DIV64                   (0x6UL << LCD_CR_CPDIV_POS)                /**< 0x00060000 */  
#define LCD_CR_CPDIV_DIV128                  (0x7UL << LCD_CR_CPDIV_POS)                /**< 0x00070000 */

/* Bits for LCD_FCR */
#define LCD_FCR_HD_POS                       (0U)      
#define LCD_FCR_HD_MASK                      (0x1UL << LCD_FCR_HD_POS)                  /**< 0x00000001 */
#define LCD_FCR_HD                           LCD_FCR_HD_MASK                            /**< High drive enable bit */

#define LCD_FCR_SOFIE_POS                    (1U)      
#define LCD_FCR_SOFIE_MASK                   (0x1UL << LCD_FCR_SOFIE_POS)               /**< 0x00000002 */
#define LCD_FCR_SOFIE                        LCD_FCR_SOFIE_MASK                         /**< Start of frame interrupt enable bit */

#define LCD_FCR_PON_POS                      (2U)      
#define LCD_FCR_PON_MASK                     (0xFUL << LCD_FCR_PON_POS)                 /**< 0x0000003C */
#define LCD_FCR_PON                          LCD_FCR_PON_MASK                           /**< PON[3:0] bits (puls on duration) */
#define LCD_FCR_PON_0                        (0x0UL << LCD_FCR_PON_POS)                 /**< 0x00000000 */
#define LCD_FCR_PON_1                        (0x1UL << LCD_FCR_PON_POS)                 /**< 0x00000004 */
#define LCD_FCR_PON_2                        (0x2UL << LCD_FCR_PON_POS)                 /**< 0x00000008 */
#define LCD_FCR_PON_3                        (0x3UL << LCD_FCR_PON_POS)                 /**< 0x0000000C */
#define LCD_FCR_PON_4                        (0x4UL << LCD_FCR_PON_POS)                 /**< 0x00000010 */
#define LCD_FCR_PON_5                        (0x5UL << LCD_FCR_PON_POS)                 /**< 0x00000014 */
#define LCD_FCR_PON_6                        (0x6UL << LCD_FCR_PON_POS)                 /**< 0x00000018 */
#define LCD_FCR_PON_7                        (0x7UL << LCD_FCR_PON_POS)                 /**< 0x0000001C */
#define LCD_FCR_PON_8                        (0x8UL << LCD_FCR_PON_POS)                 /**< 0x00000020 */
#define LCD_FCR_PON_9                        (0x9UL << LCD_FCR_PON_POS)                 /**< 0x00000024 */
#define LCD_FCR_PON_10                       (0xAUL << LCD_FCR_PON_POS)                 /**< 0x00000028 */
#define LCD_FCR_PON_11                       (0xBUL << LCD_FCR_PON_POS)                 /**< 0x0000002C */
#define LCD_FCR_PON_12                       (0xCUL << LCD_FCR_PON_POS)                 /**< 0x00000030 */
#define LCD_FCR_PON_13                       (0xDUL << LCD_FCR_PON_POS)                 /**< 0x00000034 */
#define LCD_FCR_PON_14                       (0xEUL << LCD_FCR_PON_POS)                 /**< 0x00000038 */
#define LCD_FCR_PON_15                       (0xFUL << LCD_FCR_PON_POS)                 /**< 0x0000003C */

#define LCD_FCR_DEAD_POS                     (6U)      
#define LCD_FCR_DEAD_MASK                    (0x7UL << LCD_FCR_DEAD_POS)                /**< 0x000001C0 */
#define LCD_FCR_DEAD                         LCD_FCR_DEAD_MASK                          /**< DEAD[2:0] bits (DEAD time) */
#define LCD_FCR_DEAD_0                       (0x0UL << LCD_FCR_DEAD_POS)                /**< 0x00000000 */
#define LCD_FCR_DEAD_1                       (0x1UL << LCD_FCR_DEAD_POS)                /**< 0x00000040 */
#define LCD_FCR_DEAD_2                       (0x2UL << LCD_FCR_DEAD_POS)                /**< 0x00000080 */
#define LCD_FCR_DEAD_3                       (0x3UL << LCD_FCR_DEAD_POS)                /**< 0x000000C0 */
#define LCD_FCR_DEAD_4                       (0x4UL << LCD_FCR_DEAD_POS)                /**< 0x00000100 */
#define LCD_FCR_DEAD_5                       (0x5UL << LCD_FCR_DEAD_POS)                /**< 0x00000140 */
#define LCD_FCR_DEAD_6                       (0x6UL << LCD_FCR_DEAD_POS)                /**< 0x00000180 */
#define LCD_FCR_DEAD_7                       (0x7UL << LCD_FCR_DEAD_POS)                /**< 0x000001C0 */

#define LCD_FCR_BLINKF_POS                   (13U)     
#define LCD_FCR_BLINKF_MASK                  (0x7UL << LCD_FCR_BLINKF_POS)              /**< 0x0000E000 */
#define LCD_FCR_BLINKF                       LCD_FCR_BLINKF_MASK                        /**< BLINKF[2:0] bits (blink frequency) */
#define LCD_FCR_BLINKF_DIV8                  (0x0UL << LCD_FCR_BLINKF_POS)              /**< 0x00000000 */
#define LCD_FCR_BLINKF_DIV16                 (0x1UL << LCD_FCR_BLINKF_POS)              /**< 0x00002000 */
#define LCD_FCR_BLINKF_DIV32                 (0x2UL << LCD_FCR_BLINKF_POS)              /**< 0x00004000 */
#define LCD_FCR_BLINKF_DIV64                 (0x3UL << LCD_FCR_BLINKF_POS)              /**< 0x00006000 */
#define LCD_FCR_BLINKF_DIV128                (0x4UL << LCD_FCR_BLINKF_POS)              /**< 0x00008000 */
#define LCD_FCR_BLINKF_DIV256                (0x5UL << LCD_FCR_BLINKF_POS)              /**< 0x0000A000 */
#define LCD_FCR_BLINKF_DIV512                (0x6UL << LCD_FCR_BLINKF_POS)              /**< 0x0000C000 */
#define LCD_FCR_BLINKF_DIV1024               (0x7UL << LCD_FCR_BLINKF_POS)              /**< 0x0000E000 */

#define LCD_FCR_BLINK_POS                    (16U)     
#define LCD_FCR_BLINK_MASK                   (0x3UL << LCD_FCR_BLINK_POS)               /**< 0x00030000 */
#define LCD_FCR_BLINK                        LCD_FCR_BLINK_MASK                         /**< BLINK[1:0] bits (blink enable) */
#define LCD_FCR_MODE_OFF                     (0x0UL << LCD_FCR_BLINK_POS)               /**< 0x00000000 */
#define LCD_FCR_MODE_SEG0_COM0               (0x1UL << LCD_FCR_BLINK_POS)               /**< 0x00010000 */
#define LCD_FCR_MODE_SEG0_ALLCOM             (0x2UL << LCD_FCR_BLINK_POS)               /**< 0x00020000 */
#define LCD_FCR_MODE_ALLSEG_ALLCOM           (0x3UL << LCD_FCR_BLINK_POS)               /**< 0x00030000 */

#define LCD_FCR_DIV_POS                      (18U)     
#define LCD_FCR_DIV_MASK                     (0xFUL << LCD_FCR_DIV_POS)                 /**< 0x003C0000 */
#define LCD_FCR_DIV                          LCD_FCR_DIV_MASK                           /**< DIV[3:0] bits (divider) */
#define LCD_FCR_DIV16                        (0x0 << LCD_FCR_DIV_POS)                   /**< 00000000 */
#define LCD_FCR_DIV17                        (0x1 << LCD_FCR_DIV_POS)                   /**< 00040000 */
#define LCD_FCR_DIV18                        (0x2 << LCD_FCR_DIV_POS)                   /**< 00080000 */
#define LCD_FCR_DIV19                        (0x3 << LCD_FCR_DIV_POS)                   /**< 000C0000 */
#define LCD_FCR_DIV20                        (0x4 << LCD_FCR_DIV_POS)                   /**< 00100000 */
#define LCD_FCR_DIV21                        (0x5 << LCD_FCR_DIV_POS)                   /**< 00140000 */
#define LCD_FCR_DIV22                        (0x6 << LCD_FCR_DIV_POS)                   /**< 00180000 */
#define LCD_FCR_DIV23                        (0x7 << LCD_FCR_DIV_POS)                   /**< 001C0000 */
#define LCD_FCR_DIV24                        (0x8 << LCD_FCR_DIV_POS)                   /**< 00200000 */
#define LCD_FCR_DIV25                        (0x9 << LCD_FCR_DIV_POS)                   /**< 00240000 */
#define LCD_FCR_DIV26                        (0xA << LCD_FCR_DIV_POS)                   /**< 00280000 */
#define LCD_FCR_DIV27                        (0xB << LCD_FCR_DIV_POS)                   /**< 002C0000 */
#define LCD_FCR_DIV28                        (0xC << LCD_FCR_DIV_POS)                   /**< 00300000 */
#define LCD_FCR_DIV29                        (0xD << LCD_FCR_DIV_POS)                   /**< 00340000 */
#define LCD_FCR_DIV30                        (0xE << LCD_FCR_DIV_POS)                   /**< 00380000 */
#define LCD_FCR_DIV31                        (0xF << LCD_FCR_DIV_POS)                   /**< 003C0000 */

#define LCD_FCR_PS_POS                       (22U)     
#define LCD_FCR_PS_MASK                      (0x7UL << LCD_FCR_PS_POS)                  /**< 0x01C00000 */
#define LCD_FCR_PS                           LCD_FCR_PS_MASK                            /**< PS[2:0] bits (prescaler) */
#define LCD_FCR_PS_1                         (0x0 << LCD_FCR_PS_POS)                    /**< 00000000 */
#define LCD_FCR_PS_2                         (0x1 << LCD_FCR_PS_POS)                    /**< 00400000 */
#define LCD_FCR_PS_4                         (0x2 << LCD_FCR_PS_POS)                    /**< 00800000 */
#define LCD_FCR_PS_8                         (0x3 << LCD_FCR_PS_POS)                    /**< 00C00000 */
#define LCD_FCR_PS_16                        (0x4 << LCD_FCR_PS_POS)                    /**< 01000000 */
#define LCD_FCR_PS_32                        (0x5 << LCD_FCR_PS_POS)                    /**< 01400000 */
#define LCD_FCR_PS_64                        (0x6 << LCD_FCR_PS_POS)                    /**< 01800000 */
#define LCD_FCR_PS_128                       (0x7 << LCD_FCR_PS_POS)                    /**< 01C00000 */

#define LCD_FCR_SCOC_POS                     (25U)      
#define LCD_FCR_SCOC_MASK                    (0x1UL << LCD_FCR_SCOC_POS)                /**< 0x02000000 */
#define LCD_FCR_SCOC                         LCD_FCR_SCOC_MASK                          /**< SEG and COM output conrtol bit */

#define LCD_FCR_ANTI_POLAR_POS               (26U)      
#define LCD_FCR_ANTI_POLAR_MASK              (0x1UL << LCD_FCR_ANTI_POLAR_POS)          /**< 0x04000000 */
#define LCD_FCR_ANTI_POLAR                   LCD_FCR_ANTI_POLAR_MASK                    /**< anti polar conrtol bit */

#define LCD_FCR_CC_POS                       (27U)     
#define LCD_FCR_CC_MASK                      (0x1FUL << LCD_FCR_CC_POS)                 /**< 0xF8000000 */
#define LCD_FCR_CC                           LCD_FCR_CC_MASK                            /**< CC[4:0] bits (contrast control) */
#define LCD_FCR_CC_LV0                       (0x0UL << LCD_FCR_CC_POS)                  /**< 0x00000000 */
#define LCD_FCR_CC_LV1                       (0x1UL << LCD_FCR_CC_POS)                  /**< 0x08000000 */
#define LCD_FCR_CC_LV2                       (0x2UL << LCD_FCR_CC_POS)                  /**< 0x10000000 */
#define LCD_FCR_CC_LV3                       (0x3UL << LCD_FCR_CC_POS)                  /**< 0x18000000 */
#define LCD_FCR_CC_LV4                       (0x4UL << LCD_FCR_CC_POS)                  /**< 0x20000000 */
#define LCD_FCR_CC_LV5                       (0x5UL << LCD_FCR_CC_POS)                  /**< 0x28000000 */
#define LCD_FCR_CC_LV6                       (0x6UL << LCD_FCR_CC_POS)                  /**< 0x30000000 */
#define LCD_FCR_CC_LV7                       (0x7UL << LCD_FCR_CC_POS)                  /**< 0x38000000 */
#define LCD_FCR_CC_LV8                       (0x8UL << LCD_FCR_CC_POS)                  /**< 0x40000000 */
#define LCD_FCR_CC_LV9                       (0x9UL << LCD_FCR_CC_POS)                  /**< 0x48000000 */
#define LCD_FCR_CC_LV10                      (0xAUL << LCD_FCR_CC_POS)                  /**< 0x50000000 */
#define LCD_FCR_CC_LV11                      (0xBUL << LCD_FCR_CC_POS)                  /**< 0x58000000 */
#define LCD_FCR_CC_LV12                      (0xCUL << LCD_FCR_CC_POS)                  /**< 0x60000000 */
#define LCD_FCR_CC_LV13                      (0xDUL << LCD_FCR_CC_POS)                  /**< 0x68000000 */
#define LCD_FCR_CC_LV14                      (0xEUL << LCD_FCR_CC_POS)                  /**< 0x70000000 */
#define LCD_FCR_CC_LV15                      (0xFUL << LCD_FCR_CC_POS)                  /**< 0x78000000 */
#define LCD_FCR_CC_LV16                      (0x10UL << LCD_FCR_CC_POS)                 /**< 0x80000000 */
#define LCD_FCR_CC_LV17                      (0x11UL << LCD_FCR_CC_POS)                 /**< 0x88000000 */
#define LCD_FCR_CC_LV18                      (0x12UL << LCD_FCR_CC_POS)                 /**< 0x90000000 */

/* Bits for LCD_SR */
#define LCD_SR_ENS_POS                       (0U)      
#define LCD_SR_ENS_MASK                      (0x1UL << LCD_SR_ENS_POS)                  /**< 0x00000001 */
#define LCD_SR_ENS                           LCD_SR_ENS_MASK                            /**< LCD enabled bit */
#define LCD_SR_SOF_POS                       (1U)      
#define LCD_SR_SOF_MASK                      (0x1UL << LCD_SR_SOF_POS)                  /**< 0x00000002 */
#define LCD_SR_SOF                           LCD_SR_SOF_MASK                            /**< Start of frame flag bit */
                   
/* Bits for LCD_CLR */
#define LCD_CLR_SOFC_POS                     (1U)      
#define LCD_CLR_SOFC_MASK                    (0x1UL << LCD_CLR_SOFC_POS)                /**< 0x00000002 */
#define LCD_CLR_SOFC                         LCD_CLR_SOFC_MASK                          /**< Start of frame flag clear bit */

/* Bits for LCD_RAM */
#define LCD_RAM_SEGMENT_DATA_POS             (0U)      
#define LCD_RAM_SEGMENT_DATA_MASK            (0xFFFFFFFFUL << LCD_RAM_SEGMENT_DATA_POS) /**< 0xFFFFFFFF */
#define LCD_RAM_SEGMENT_DATA                 LCD_RAM_SEGMENT_DATA_MASK                  /**< Segment data bits */


/*-----------------------------------------------------------------------------------------------
                                       LPTimer Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for LPTIM_ISR */
#define LPTIM_ISR_CMPM_POS               (0U)
#define LPTIM_ISR_CMPM_MASK              (0x1UL << LPTIM_ISR_CMPM_POS)             /**< 0x00000001 */
#define LPTIM_ISR_CMPM                   LPTIM_ISR_CMPM_MASK                       /**< Compare match */
#define LPTIM_ISR_ARRM_POS               (1U)
#define LPTIM_ISR_ARRM_MASK              (0x1UL << LPTIM_ISR_ARRM_POS)             /**< 0x00000002 */
#define LPTIM_ISR_ARRM                   LPTIM_ISR_ARRM_MASK                       /**< Autoreload match */
#define LPTIM_ISR_EXTTRIG_POS            (2U)
#define LPTIM_ISR_EXTTRIG_MASK           (0x1UL << LPTIM_ISR_EXTTRIG_POS)          /**< 0x00000004 */
#define LPTIM_ISR_EXTTRIG                LPTIM_ISR_EXTTRIG_MASK                    /**< External trigger edge event */
#define LPTIM_ISR_UP_POS                 (5U)
#define LPTIM_ISR_UP_MASK                (0x1UL << LPTIM_ISR_UP_POS)               /**< 0x00000020 */
#define LPTIM_ISR_UP                     LPTIM_ISR_UP_MASK                         /**< Counter direction change down to up */
#define LPTIM_ISR_DOWN_POS               (6U)
#define LPTIM_ISR_DOWN_MASK              (0x1UL << LPTIM_ISR_DOWN_POS)             /**< 0x00000040 */
#define LPTIM_ISR_DOWN                   LPTIM_ISR_DOWN_MASK                       /**< Counter direction change up to down */

/* Bits for LPTIM_ICR */
#define LPTIM_ICR_CMPM_CF_POS            (0U)
#define LPTIM_ICR_CMPM_CF_MASK           (0x1UL << LPTIM_ICR_CMPM_CF_POS)          /**< 0x00000001 */
#define LPTIM_ICR_CMPM_CF                LPTIM_ICR_CMPM_CF_MASK                    /**< Compare match clear flag */
#define LPTIM_ICR_ARRM_CF_POS            (1U)
#define LPTIM_ICR_ARRM_CF_MASK           (0x1UL << LPTIM_ICR_ARRM_CF_POS)          /**< 0x00000002 */
#define LPTIM_ICR_ARRM_CF                LPTIM_ICR_ARRM_CF_MASK                    /**< Autoreload match clear flag */
#define LPTIM_ICR_EXTTRIG_CF_POS         (2U)
#define LPTIM_ICR_EXTTRIG_CF_MASK        (0x1UL << LPTIM_ICR_EXTTRIG_CF_POS)       /**< 0x00000004 */
#define LPTIM_ICR_EXTTRIG_CF             LPTIM_ICR_EXTTRIG_CF_MASK                 /**< External trigger edge event clear flag */
#define LPTIM_ICR_UP_CF_POS              (5U)
#define LPTIM_ICR_UP_CF_MASK             (0x1UL << LPTIM_ICR_UP_CF_POS)            /**< 0x00000020 */
#define LPTIM_ICR_UP_CF                  LPTIM_ICR_UP_CF_MASK                      /**< Counter direction change down to up clear flag */
#define LPTIM_ICR_DOWN_CF_POS            (6U)
#define LPTIM_ICR_DOWN_CF_MASK           (0x1UL << LPTIM_ICR_DOWN_CF_POS)          /**< 0x00000040 */
#define LPTIM_ICR_DOWN_CF                LPTIM_ICR_DOWN_CF_MASK                    /**< Counter direction change up to down clear flag */

/* Bits for LPTIM_IER */
#define LPTIM_IER_CMPM_IE_POS            (0U)
#define LPTIM_IER_CMPM_IE_MASK           (0x1UL << LPTIM_IER_CMPM_IE_POS)          /**< 0x00000001 */
#define LPTIM_IER_CMPM_IE                LPTIM_IER_CMPM_IE_MASK                    /**< Compare match interrupt enable */
#define LPTIM_IER_ARRM_IE_POS            (1U)
#define LPTIM_IER_ARRM_IE_MASK           (0x1UL << LPTIM_IER_ARRM_IE_POS)          /**< 0x00000002 */
#define LPTIM_IER_ARRM_IE                LPTIM_IER_ARRM_IE_MASK                    /**< Autoreload match interrupt enable */
#define LPTIM_IER_EXTTRIG_IE_POS         (2U)
#define LPTIM_IER_EXTTRIG_IE_MASK        (0x1UL << LPTIM_IER_EXTTRIG_IE_POS)       /**< 0x00000004 */
#define LPTIM_IER_EXTTRIG_IE             LPTIM_IER_EXTTRIG_IE_MASK                 /**< External trigger edge event interrupt enable */
#define LPTIM_IER_UP_IE_POS              (5U)
#define LPTIM_IER_UP_IE_MASK             (0x1UL << LPTIM_IER_UP_IE_POS)            /**< 0x00000020 */
#define LPTIM_IER_UP_IE                  LPTIM_IER_UP_IE_MASK                      /**< Counter direction change down to up interrupt enable */
#define LPTIM_IER_DOWN_IE_POS            (6U)
#define LPTIM_IER_DOWN_IE_MASK           (0x1UL << LPTIM_IER_DOWN_IE_POS)          /**< 0x00000040 */
#define LPTIM_IER_DOWN_IE                LPTIM_IER_DOWN_IE_MASK                    /**< Counter direction change up to down interrupt enable */
#define LPTIM_IER_CMP_DMAEN_POS          (12U)
#define LPTIM_IER_CMP_DMAEN_MASK         (0x1UL << LPTIM_IER_CMP_DMAEN_POS)        /**< 0x00001000 */
#define LPTIM_IER_CMP_DMAEN              LPTIM_IER_CMP_DMAEN_MASK                  /**< Compare match interrupt apply for DMA enable */
#define LPTIM_IER_ARR_DMAEN_POS          (13U)
#define LPTIM_IER_ARR_DMAEN_MASK         (0x1UL << LPTIM_IER_ARR_DMAEN_POS)        /**< 0x00002000 */
#define LPTIM_IER_ARR_DMAEN              LPTIM_IER_ARR_DMAEN_MASK                  /**< Autoreload match interrupt apply for DMA enable */

/* Bits for LPTIM_CFG */
#define LPTIM_CFG_CKSEL_POS               (0U)
#define LPTIM_CFG_CKSEL_MASK              (0x1UL << LPTIM_CFG_CKSEL_POS)           /**< 0x00000001 */
#define LPTIM_CFG_CKSEL                   LPTIM_CFG_CKSEL_MASK                     /**< Clock selector */
#define LPTIM_CFG_CKPOL_POS               (1U)
#define LPTIM_CFG_CKPOL_MASK              (0x3UL << LPTIM_CFG_CKPOL_POS)           /**< 0x00000006 */
#define LPTIM_CFG_CKPOL                   LPTIM_CFG_CKPOL_MASK                     /**< CKPOL[1:0] bits (clock polarity) */
#define LPTIM_CFG_CKPOL_RISING            (0x0UL << LPTIM_CFG_CKPOL_POS)           /**< 0x00000000 */ 
#define LPTIM_CFG_CKPOL_FALLING           (0x1UL << LPTIM_CFG_CKPOL_POS)           /**< 0x00000002 */
#define LPTIM_CFG_CKPOL_RISING_FALLING    (0x2UL << LPTIM_CFG_CKPOL_POS)           /**< 0x00000004 */
#define LPTIM_CFG_CKFLT_POS               (3U)
#define LPTIM_CFG_CKFLT_MASK              (0x3UL << LPTIM_CFG_CKFLT_POS)           /**< 0x00000018 */
#define LPTIM_CFG_CKFLT                   LPTIM_CFG_CKFLT_MASK                     /**< CKFLT[1:0] bits (configurable digital filter for external clock) */
#define LPTIM_CFG_CKFLT_NONE              (0x0UL << LPTIM_CFG_CKFLT_POS)           /**< 0x00000000 */
#define LPTIM_CFG_CKFLT_2                 (0x1UL << LPTIM_CFG_CKFLT_POS)           /**< 0x00000008 */
#define LPTIM_CFG_CKFLT_4                 (0x2UL << LPTIM_CFG_CKFLT_POS)           /**< 0x00000010 */
#define LPTIM_CFG_CKFLT_8                 (0x3UL << LPTIM_CFG_CKFLT_POS)           /**< 0x00000018 */
#define LPTIM_CFG_TRIG_FLT_POS            (6U)
#define LPTIM_CFG_TRIG_FLT_MASK           (0x3UL << LPTIM_CFG_TRIG_FLT_POS)        /**< 0x000000C0 */
#define LPTIM_CFG_TRIG_FLT                LPTIM_CFG_TRIG_FLT_MASK                  /**< TRGFLT[1:0] bits (configurable digital filter for trigger) */
#define LPTIM_CFG_TRIG_FLT_NONE           (0x0UL << LPTIM_CFG_TRIG_FLT_POS)        /**< 0x00000000 */
#define LPTIM_CFG_TRIG_FLT_2              (0x1UL << LPTIM_CFG_TRIG_FLT_POS)        /**< 0x00000040 */
#define LPTIM_CFG_TRIG_FLT_4              (0x2UL << LPTIM_CFG_TRIG_FLT_POS)        /**< 0x00000080 */
#define LPTIM_CFG_TRIG_FLT_8              (0x3UL << LPTIM_CFG_TRIG_FLT_POS)        /**< 0x000000C0 */
#define LPTIM_CFG_PRESC_POS               (9U)
#define LPTIM_CFG_PRESC_MASK              (0x7UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000E00 */
#define LPTIM_CFG_PRESC                   LPTIM_CFG_PRESC_MASK                     /**< PRESC[2:0] bits (clock prescaler) */
#define LPTIM_CFG_PRESC_1                 (0x0UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000000 */
#define LPTIM_CFG_PRESC_2                 (0x1UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000200 */
#define LPTIM_CFG_PRESC_4                 (0x2UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000400 */
#define LPTIM_CFG_PRESC_8                 (0x3UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000600 */
#define LPTIM_CFG_PRESC_16                (0x4UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000800 */
#define LPTIM_CFG_PRESC_32                (0x5UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000A00 */
#define LPTIM_CFG_PRESC_64                (0x6UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000C00 */
#define LPTIM_CFG_PRESC_128               (0x7UL << LPTIM_CFG_PRESC_POS)           /**< 0x00000E00 */
#define LPTIM_CFG_TRIG_SEL_POS            (13U)
#define LPTIM_CFG_TRIG_SEL_MASK           (0x7UL << LPTIM_CFG_TRIG_SEL_POS)        /**< 0x0000E000 */
#define LPTIM_CFG_TRIG_SEL                LPTIM_CFG_TRIG_SEL_MASK                  /**< TRIGSEL[2:0]] bits (trigger selector) */
#define LPTIM_CFG_TRIG_SEL_ETR            (0x0UL << LPTIM_CFG_TRIG_SEL_POS)        /**< 0x00000000 */
#define LPTIM_CFG_TRIG_SEL_RTCALARM       (0x1UL << LPTIM_CFG_TRIG_SEL_POS)        /**< 0x00002000 */
#define LPTIM_CFG_TRIG_SEL_COMP1          (0x6UL << LPTIM_CFG_TRIG_SEL_POS)        /**< 0x0000C000 */
#define LPTIM_CFG_TRIG_SEL_COMP2          (0x7UL << LPTIM_CFG_TRIG_SEL_POS)        /**< 0x0000E000 */
#define LPTIM_CFG_TRIG_EN_POS             (17U)
#define LPTIM_CFG_TRIG_EN_MASK            (0x3UL << LPTIM_CFG_TRIG_EN_POS)         /**< 0x00060000 */
#define LPTIM_CFG_TRIG_EN                 LPTIM_CFG_TRIG_EN_MASK                   /**< TRIGEN[1:0] bits (trigger enable and polarity) */
#define LPTIM_CFG_TRIG_EN_SOFTWARE        (0x0UL << LPTIM_CFG_TRIG_EN_POS)         /**< 0x00000000 */
#define LPTIM_CFG_TRIG_EN_RISING          (0x1UL << LPTIM_CFG_TRIG_EN_POS)         /**< 0x00020000 */
#define LPTIM_CFG_TRIG_EN_FALLING         (0x2UL << LPTIM_CFG_TRIG_EN_POS)         /**< 0x00040000 */
#define LPTIM_CFG_TRIG_EN_RISING_FALLING  (0x3UL << LPTIM_CFG_TRIG_EN_POS)         /**< 0x00060000 */
#define LPTIM_CFG_TIMOUT_POS              (19U)
#define LPTIM_CFG_TIMOUT_MASK             (0x1UL << LPTIM_CFG_TIMOUT_POS)          /**< 0x00080000 */
#define LPTIM_CFG_TIMOUT                  LPTIM_CFG_TIMOUT_MASK                    /**< Timout enable */
#define LPTIM_CFG_WAVPOL_POS              (21U)
#define LPTIM_CFG_WAVPOL_MASK             (0x1UL << LPTIM_CFG_WAVPOL_POS)          /**< 0x00200000 */
#define LPTIM_CFG_WAVPOL                  LPTIM_CFG_WAVPOL_MASK                    /**< Waveform shape polarity */
#define LPTIM_CFG_COUNT_MODE_POS          (23U)
#define LPTIM_CFG_COUNT_MODE_MASK         (0x1UL << LPTIM_CFG_COUNT_MODE_POS)      /**< 0x00800000 */
#define LPTIM_CFG_COUNT_MODE              LPTIM_CFG_COUNT_MODE_MASK                /**< Counter mode enable */
#define LPTIM_CFG_ENC_POS                 (24U)
#define LPTIM_CFG_ENC_MASK                (0x1UL << LPTIM_CFG_ENC_POS)             /**< 0x01000000 */
#define LPTIM_CFG_ENC                     LPTIM_CFG_ENC_MASK                       /**< Encoder mode enable */

/* Bits for LPTIM_CR */
#define LPTIM_CR_ENABLE_POS               (0U)
#define LPTIM_CR_ENABLE_MASK              (0x1UL << LPTIM_CR_ENABLE_POS)           /**< 0x00000001   */
#define LPTIM_CR_ENABLE                   LPTIM_CR_ENABLE_MASK                     /**< LPTIM enable */
#define LPTIM_CR_SNGSTRT_POS              (1U)
#define LPTIM_CR_SNGSTRT_MASK             (0x1UL << LPTIM_CR_SNGSTRT_POS)          /**< 0x00000002 */
#define LPTIM_CR_SNGSTRT                  LPTIM_CR_SNGSTRT_MASK                    /**< Timer start in single mode */
#define LPTIM_CR_CNTSTRT_POS              (2U)
#define LPTIM_CR_CNTSTRT_MASK             (0x1UL << LPTIM_CR_CNTSTRT_POS)          /**< 0x00000004 */
#define LPTIM_CR_CNTSTRT                  LPTIM_CR_CNTSTRT_MASK                    /**< Timer start in continuous mode */

/* Bits for LPTIM_CMP */
#define LPTIM_CMP_CMP_POS                 (0U)
#define LPTIM_CMP_CMP_MASK                (0xFFFFUL << LPTIM_CMP_CMP_POS)          /**< 0x0000FFFF */
#define LPTIM_CMP_CMP                     LPTIM_CMP_CMP_MASK                       /**< Compare register */

/* Bits for LPTIM_ARR */
#define LPTIM_ARR_ARR_POS                 (0U)
#define LPTIM_ARR_ARR_MASK                (0xFFFFUL << LPTIM_ARR_ARR_POS)          /**< 0x0000FFFF */
#define LPTIM_ARR_ARR                     LPTIM_ARR_ARR_MASK                       /**< Auto reload register */

/* Bits for LPTIM_CNT */
#define LPTIM_CNT_CNT_POS                 (0U)
#define LPTIM_CNT_CNT_MASK                (0xFFFFUL << LPTIM_CNT_CNT_POS)          /**< 0x0000FFFF */
#define LPTIM_CNT_CNT                     LPTIM_CNT_CNT_MASK                       /**< Counter register */

/* Bits for LPTIM_CFG2 */
#define LPTIM_CFG2_IN1_SEL_POS            (0U)
#define LPTIM_CFG2_IN1_SEL_MASK           (0x3UL << LPTIM_CFG2_IN1_SEL_POS)        /**< 0x00000003 */
#define LPTIM_CFG2_IN1_SEL                LPTIM_CFG2_IN1_SEL_MASK                  /**< CFG2[1:0] bits (INPUT1 selection) */
#define LPTIM_CFG2_IN1_SEL_IN1            (0x0UL << LPTIM_CFG2_IN1_SEL_POS)        /**< 0x00000000 */
#define LPTIM_CFG2_IN1_SEL_COMP1          (0x1UL << LPTIM_CFG2_IN1_SEL_POS)        /**< 0x00000001 */
#define LPTIM_CFG2_IN2_SEL_POS            (4U)
#define LPTIM_CFG2_IN2_SEL_MASK           (0x3UL << LPTIM_CFG2_IN2_SEL_POS)        /**< 0x00000030 */
#define LPTIM_CFG2_IN2_SEL                LPTIM_CFG2_IN2_SEL_MASK                  /**< CFG2[5:4] bits (INPUT2 selection) */
#define LPTIM_CFG2_IN2_SEL_IN2            (0x0UL << LPTIM_CFG2_IN2_SEL_POS)        /**< 0x00000000 */
#define LPTIM_CFG2_IN2_SEL_COMP2          (0x1UL << LPTIM_CFG2_IN2_SEL_POS)        /**< 0x00000010 */


/*-----------------------------------------------------------------------------------------------
                                       PMU Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for PMU_CR1 */
#define PMU_CR1_VAON_WEN_POS               (8U)
#define PMU_CR1_VAON_WEN_MASK              (0x1UL << PMU_CR1_VAON_WEN_POS)                 /**< 0x00000100 */
#define PMU_CR1_VAON_WEN                   PMU_CR1_VAON_WEN_MASK                           /**< VCORE_AON domain write protection control */

#define PMU_CR1_BGR_EN_POS                 (15U)
#define PMU_CR1_BGR_EN_MASK                (0x1UL << PMU_CR1_BGR_EN_POS)                   /**< 0x00008000 */
#define PMU_CR1_BGR_EN                     PMU_CR1_BGR_EN_MASK                             /**< BGR enable */
  
/* Bits for PMU_CR2 */  
#define PMU_CR2_PVD_EN_POS                 (0U)
#define PMU_CR2_PVD_EN_MASK                (0x1UL << PMU_CR2_PVD_EN_POS)                   /**< 0x00000001 */
#define PMU_CR2_PVD_EN                     PMU_CR2_PVD_EN_MASK                             /**< PVD enable */

#define PMU_CR2_PVD_LEVEL_POS              (1U)
#define PMU_CR2_PVD_LEVEL_MASK             (0x7UL << PMU_CR2_PVD_LEVEL_POS)                /**< 0x0000001E */
#define PMU_CR2_PVD_LEVEL                  PMU_CR2_PVD_LEVEL_MASK                          /**< PVD threshold selection(raising/falling) */

#define PMU_CR2_FILTER_TIME_POS            (7U)
#define PMU_CR2_FILTER_TIME_MASK           (0x7UL << PMU_CR2_FILTER_TIME_POS)              /**< 0x00000380 */
#define PMU_CR2_FILTER_TIME                PMU_CR2_FILTER_TIME_MASK                        /**< PVD filter time */

#define PMU_CR2_FILTER_EN_POS              (10U)
#define PMU_CR2_FILTER_EN_MASK             (0x1UL << PMU_CR2_FILTER_EN_POS)                /**< 0x00000400 */
#define PMU_CR2_FILTER_EN                  PMU_CR2_FILTER_EN_MASK                          /**< PVD filter enable */

#define PMU_CR2_RT_EN_POS                  (11U)
#define PMU_CR2_RT_EN_MASK                 (0x1UL << PMU_CR2_RT_EN_POS)                    /**< 0x00000800 */
#define PMU_CR2_RT_EN                      PMU_CR2_RT_EN_MASK                              /**< PVD from below threshold to above threshold alarm enable */
#define PMU_CR2_FT_EN_POS                  (12U)
#define PMU_CR2_FT_EN_MASK                 (0x1UL << PMU_CR2_FT_EN_POS)                    /**< 0x00001000 */
#define PMU_CR2_FT_EN                      PMU_CR2_FT_EN_MASK                              /**< PVD from above threshold to below threshold alarm enable */
#define PMU_CR2_LT_EN_POS                  (13U)
#define PMU_CR2_LT_EN_MASK                 (0x1UL << PMU_CR2_LT_EN_POS)                    /**< 0x00002000 */
#define PMU_CR2_LT_EN                      PMU_CR2_LT_EN_MASK                              /**< PVD below threshold alarm enable */
#define PMU_CR2_HT_EN_POS                  (14U)
#define PMU_CR2_HT_EN_MASK                 (0x1UL << PMU_CR2_HT_EN_POS)                    /**< 0x00004000 */
#define PMU_CR2_HT_EN                      PMU_CR2_HT_EN_MASK                              /**< PVD above threshold alarm enable */

#define PMU_CR2_PVD_IE_POS                 (15U)
#define PMU_CR2_PVD_IE_MASK                (0x1UL << PMU_CR2_PVD_IE_POS)                   /**< 0x00008000 */
#define PMU_CR2_PVD_IE                     PMU_CR2_PVD_IE_MASK                             /**< PVD interrupt enable */

/* Bits for PMU_CR3 */
#define PMU_CR3_ULP_EN_POS                 (9U)
#define PMU_CR3_ULP_EN_MASK                (0x1UL << PMU_CR3_ULP_EN_POS)                   /**< 0x00000200 */
#define PMU_CR3_ULP_EN                     PMU_CR3_ULP_EN_MASK                             /**< Enable periodical sampling of supply voltage for  PDR and BOR in stop and standby */

/* Bits for PMU_SR */               
#define PMU_SR_BGR_READY_POS               (10U)
#define PMU_SR_BGR_READY_MASK              (0x1UL << PMU_SR_BGR_READY_POS)                 /**< 0x00000400 */
#define PMU_SR_BGR_READY                   PMU_SR_BGR_READY_MASK                           /**< BGR ready  */

#define PMU_SR_PVD_STATUS_POS              (11U)
#define PMU_SR_PVD_STATUS_MASK             (0x1UL << PMU_SR_PVD_STATUS_POS)                /**< 0x00000800 */
#define PMU_SR_PVD_STATUS                  PMU_SR_PVD_STATUS_MASK                          /**< PVD output status*/

#define PMU_SR_PVD_INTF_POS                (12U)
#define PMU_SR_PVD_INTF_MASK               (0x1UL << PMU_SR_PVD_INTF_POS)                  /**< 0x00001000 */
#define PMU_SR_PVD_INTF                    PMU_SR_PVD_INTF_MASK                            /**< PVD interrupt flag */

/* Bits for PMU_CLR */
#define PMU_CLR_PVD_INTF_CLR_POS           (12U)
#define PMU_CLR_PVD_INTF_CLR_MASK          (0x1UL << PMU_CLR_PVD_INTF_CLR_POS)             /**< 0x00001000 */
#define PMU_CLR_PVD_INTF_CLR               PMU_CLR_PVD_INTF_CLR_MASK                       /**< Clear pvd interrupt flag  */

/*-----------------------------------------------------------------------------------------------
                                       RCC Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for RCC_CSR1 */
#define RCC_CSR1_RCHON_POS                 (8U)
#define RCC_CSR1_RCHON_MASK                (0x1UL << RCC_CSR1_RCHON_POS)            /**< 0x00000100 */
#define RCC_CSR1_RCHON                     RCC_CSR1_RCHON_MASK                      /**< RCH enable */

#define RCC_CSR1_RCH_AWON_POS              (9U)
#define RCC_CSR1_RCH_AWON_MASK             (0x1UL << RCC_CSR1_RCH_AWON_POS)         /**< 0x00000200 */
#define RCC_CSR1_RCH_AWON                  RCC_CSR1_RCH_AWON_MASK                   /**< RCH always on */

#define RCC_CSR1_RCHRDY_POS                (10U)
#define RCC_CSR1_RCHRDY_MASK               (0x1UL << RCC_CSR1_RCHRDY_POS)           /**< 0x00000400 */
#define RCC_CSR1_RCHRDY                    RCC_CSR1_RCHRDY_MASK                     /**< RCH ready flag */

#define RCC_CSR1_RCHDIV_POS                (11U)
#define RCC_CSR1_RCHDIV_MASK               (0x3UL << RCC_CSR1_RCHDIV_POS)           /**< 0x00001800 */
#define RCC_CSR1_RCHDIV                    RCC_CSR1_RCHDIV_MASK                     /**< RCHDIV[1:0] RCH division factor */
#define RCC_CSR1_RCHDIV_1                  (0x0UL << RCC_CSR1_RCHDIV_POS)           /**< 0x00000000 */
#define RCC_CSR1_RCHDIV_2                  (0x1UL << RCC_CSR1_RCHDIV_POS)           /**< 0x00000800 */
#define RCC_CSR1_RCHDIV_4                  (0x2UL << RCC_CSR1_RCHDIV_POS)           /**< 0x00001000 */
#define RCC_CSR1_RCHDIV_8                  (0x3UL << RCC_CSR1_RCHDIV_POS)           /**< 0x00001800 */

#define RCC_CSR1_HXTALON_POS               (16U)
#define RCC_CSR1_HXTALON_MASK              (0x1UL << RCC_CSR1_HXTALON_POS)          /**< 0x00010000 */
#define RCC_CSR1_HXTALON                   RCC_CSR1_HXTALON_MASK                    /**< HXTAL enable */

#define RCC_CSR1_HXTALBYP_POS              (17U)
#define RCC_CSR1_HXTALBYP_MASK             (0x1UL << RCC_CSR1_HXTALBYP_POS)         /**< 0x00020000 */
#define RCC_CSR1_HXTALBYP                  RCC_CSR1_HXTALBYP_MASK                   /**< HXTAL bypass */

#define RCC_CSR1_HXTALRDY_POS              (18U)
#define RCC_CSR1_HXTALRDY_MASK             (0x1UL << RCC_CSR1_HXTALRDY_POS)         /**< 0x00040000 */
#define RCC_CSR1_HXTALRDY                  RCC_CSR1_HXTALRDY_MASK                   /**< HXTAL ready flag */

#define RCC_CSR1_HXTAL_CSSON_POS           (19U)
#define RCC_CSR1_HXTAL_CSSON_MASK          (0x1UL << RCC_CSR1_HXTAL_CSSON_POS)      /**< 0x00080000 */
#define RCC_CSR1_HXTAL_CSSON               RCC_CSR1_HXTAL_CSSON_MASK                /**< HXTAL clock security system enable */

#define RCC_CSR1_HXTAL_DRV_POS             (20U)
#define RCC_CSR1_HXTAL_DRV_MASK            (0x3UL << RCC_CSR1_HXTAL_DRV_POS)        /**< 0x00300000 */
#define RCC_CSR1_HXTAL_DRV                 RCC_CSR1_HXTAL_DRV_MASK                  /**< HXTALCDRV[1:0] HXTAL drive capability control */
#define RCC_CSR1_HXTAL_DRV_0               (0x0UL << RCC_CSR1_HXTAL_DRV_POS)        /**< 0x00000000 */
#define RCC_CSR1_HXTAL_DRV_1               (0x1UL << RCC_CSR1_HXTAL_DRV_POS)        /**< 0x00100000 */
#define RCC_CSR1_HXTAL_DRV_2               (0x2UL << RCC_CSR1_HXTAL_DRV_POS)        /**< 0x00200000 */
#define RCC_CSR1_HXTAL_DRV_3               (0x3UL << RCC_CSR1_HXTAL_DRV_POS)        /**< 0x00300000 */

#define RCC_CSR1_PLLON_POS                 (24U)
#define RCC_CSR1_PLLON_MASK                (0x1UL << RCC_CSR1_PLLON_POS)            /**< 0x01000000 */
#define RCC_CSR1_PLLON                     RCC_CSR1_PLLON_MASK                      /**< PLL enable */

#define RCC_CSR1_PLLRDY_POS                (25U)
#define RCC_CSR1_PLLRDY_MASK               (0x1UL << RCC_CSR1_PLLRDY_POS)           /**< 0x02000000 */
#define RCC_CSR1_PLLRDY                    RCC_CSR1_PLLRDY_MASK                     /**< PLL ready */

/* Bits for RCC_STABC */
#define RCC_STABC_HXTAL_STAB_SEL_POS       (0U)
#define RCC_STABC_HXTAL_STAB_SEL_MASK      (0x3UL << RCC_STABC_HXTAL_STAB_SEL_POS)  /**< 0x00000003 */
#define RCC_STABC_HXTAL_STAB_SEL           RCC_STABC_HXTAL_STAB_SEL_MASK            /**< HXTAL_STAB_SEL[1:0] number of HXTAL stable clock cycles */

/* Bits for RCC_CFG */
#define RCC_CFG_SYSW_POS                   (0U)
#define RCC_CFG_SYSW_MASK                  (0x7UL << RCC_CFG_SYSW_POS)                 /**< 0x00000007 */
#define RCC_CFG_SYSW                       RCC_CFG_SYSW_MASK                           /**< SYSW[2:0] system clock selection */
#define RCC_CFG_SYSW_RCHSYS                (0x0UL << RCC_CFG_SYSW_POS)                 /**< 0x00000000 */
#define RCC_CFG_SYSW_HXTAL                 (0x1UL << RCC_CFG_SYSW_POS)                 /**< 0x00000001 */
#define RCC_CFG_SYSW_PLL                   (0x2UL << RCC_CFG_SYSW_POS)                 /**< 0x00000002 */
#define RCC_CFG_SYSW_RCL                   (0x3UL << RCC_CFG_SYSW_POS)                 /**< 0x00000003 */
#define RCC_CFG_SYSW_LXTAL                 (0x4UL << RCC_CFG_SYSW_POS)                 /**< 0x00000004 */
                                                                                
#define RCC_CFG_SYSWS_POS                  (3U)                                     
#define RCC_CFG_SYSWS_MASK                 (0x7UL << RCC_CFG_SYSWS_POS)                /**< 0x00000038 */
#define RCC_CFG_SYSWS                      RCC_CFG_SYSWS_MASK                          /**< SYSWS[2:0] system clock select status */
#define RCC_CFG_SYSWS_RCHSYS               (0x0UL << RCC_CFG_SYSWS_POS)                /**< 0x00000000 RCHSYS used as system clock */
#define RCC_CFG_SYSWS_HXTAL                (0x1UL << RCC_CFG_SYSWS_POS)                /**< 0x00000008 HXTAL used as system clock */
#define RCC_CFG_SYSWS_PLL                  (0x2UL << RCC_CFG_SYSWS_POS)                /**< 0x00000010 PLL used as system clock */
#define RCC_CFG_SYSWS_RCL                  (0x3UL << RCC_CFG_SYSWS_POS)                /**< 0x00000018 RCL used as system clock */
#define RCC_CFG_SYSWS_LXTAL                (0x4UL << RCC_CFG_SYSWS_POS)                /**< 0x00000020 LXTAL used as system clock */
                                                                                                                                                                     
#define RCC_CFG_HPRE_POS                   (8U)                                       
#define RCC_CFG_HPRE_MASK                  (0x7UL << RCC_CFG_HPRE_POS)                 /**< 0x00000700 */
#define RCC_CFG_HPRE                       RCC_CFG_HPRE_MASK                           /**< HPRE[2:0] AHB clock division factor */
#define RCC_CFG_HPRE_1                     (0x0UL << RCC_CFG_HPRE_POS)                 /**< 0x00000000 */
#define RCC_CFG_HPRE_2                     (0x1UL << RCC_CFG_HPRE_POS)                 /**< 0x00000100 */
#define RCC_CFG_HPRE_4                     (0x2UL << RCC_CFG_HPRE_POS)                 /**< 0x00000200 */
#define RCC_CFG_HPRE_8                     (0x3UL << RCC_CFG_HPRE_POS)                 /**< 0x00000300 */
#define RCC_CFG_HPRE_16                    (0x4UL << RCC_CFG_HPRE_POS)                 /**< 0x00000400 */
#define RCC_CFG_HPRE_32                    (0x5UL << RCC_CFG_HPRE_POS)                 /**< 0x00000500 */
#define RCC_CFG_HPRE_64                    (0x6UL << RCC_CFG_HPRE_POS)                 /**< 0x00000600 */
#define RCC_CFG_HPRE_128                   (0x7UL << RCC_CFG_HPRE_POS)                 /**< 0x00000700 */
                                                                                    
#define RCC_CFG_P1PRE_POS                  (12U)                                      
#define RCC_CFG_P1PRE_MASK                 (0x7UL << RCC_CFG_P1PRE_POS)                /**< 0x00007000 */
#define RCC_CFG_P1PRE                      RCC_CFG_P1PRE_MASK                          /**< P1PRE[2:0] APB1 clock division factor */
#define RCC_CFG_P1PRE_1                    (0x0UL << RCC_CFG_P1PRE_POS)                /**< 0x00000000 */
#define RCC_CFG_P1PRE_2                    (0x4UL << RCC_CFG_P1PRE_POS)                /**< 0x00004000 */
#define RCC_CFG_P1PRE_4                    (0x5UL << RCC_CFG_P1PRE_POS)                /**< 0x00005000 */
#define RCC_CFG_P1PRE_8                    (0x6UL << RCC_CFG_P1PRE_POS)                /**< 0x00006000 */
#define RCC_CFG_P1PRE_16                   (0x7UL << RCC_CFG_P1PRE_POS)                /**< 0x00007000 */
                                                                                    
#define RCC_CFG_P2PRE_POS                  (16U)                                      
#define RCC_CFG_P2PRE_MASK                 (0x7UL << RCC_CFG_P2PRE_POS)                /**< 0x00070000 */
#define RCC_CFG_P2PRE                      RCC_CFG_P2PRE_MASK                          /**< P2PRE[2:0] APB2 clock division factor */
#define RCC_CFG_P2PRE_1                    (0x0UL << RCC_CFG_P2PRE_POS)                /**< 0x00000000 */
#define RCC_CFG_P2PRE_2                    (0x4UL << RCC_CFG_P2PRE_POS)                /**< 0x00040000 */
#define RCC_CFG_P2PRE_4                    (0x5UL << RCC_CFG_P2PRE_POS)                /**< 0x00050000 */
#define RCC_CFG_P2PRE_8                    (0x6UL << RCC_CFG_P2PRE_POS)                /**< 0x00060000 */
#define RCC_CFG_P2PRE_16                   (0x7UL << RCC_CFG_P2PRE_POS)                /**< 0x00070000 */
                                                                                    
#define RCC_CFG_MCOSEL_POS                 (24U)                                      
#define RCC_CFG_MCOSEL_MASK                (0x7UL << RCC_CFG_MCOSEL_POS)               /**< 0x07000000 */
#define RCC_CFG_MCOSEL                     RCC_CFG_MCOSEL_MASK                         /**< MCOSEL [2:0] MCO clock output selection */
#define RCC_CFG_MCOSEL_DISABLE             (0x0UL << RCC_CFG_MCOSEL_POS)               /**< 0x00000000 */
#define RCC_CFG_MCOSEL_SYSCLK              (0x1UL << RCC_CFG_MCOSEL_POS)               /**< 0x01000000 */
#define RCC_CFG_MCOSEL_RCH                 (0x3UL << RCC_CFG_MCOSEL_POS)               /**< 0x03000000 */
#define RCC_CFG_MCOSEL_HXTAL               (0x4UL << RCC_CFG_MCOSEL_POS)               /**< 0x04000000 */
#define RCC_CFG_MCOSEL_PLLCLK              (0x5UL << RCC_CFG_MCOSEL_POS)               /**< 0x05000000 */
#define RCC_CFG_MCOSEL_RCL                 (0x6UL << RCC_CFG_MCOSEL_POS)               /**< 0x06000000 */
#define RCC_CFG_MCOSEL_LXTAL               (0x7UL << RCC_CFG_MCOSEL_POS)               /**< 0x07000000 */
                                                                                    
#define RCC_CFG_MCOPRE_POS                 (28U)                                      
#define RCC_CFG_MCOPRE_MASK                (0x7UL << RCC_CFG_MCOPRE_POS)               /**< 0x70000000 */
#define RCC_CFG_MCOPRE                     RCC_CFG_MCOPRE_MASK                         /**< MCOPRE[2:0] MCO output clock division factor */
#define RCC_CFG_MCOPRE_DIV1                (0x0UL << RCC_CFG_MCOPRE_POS)               /**< 0x00000000 */
#define RCC_CFG_MCOPRE_DIV2                (0x1UL << RCC_CFG_MCOPRE_POS)               /**< 0x10000000 */
#define RCC_CFG_MCOPRE_DIV4                (0x2UL << RCC_CFG_MCOPRE_POS)               /**< 0x20000000 */
#define RCC_CFG_MCOPRE_DIV8                (0x3UL << RCC_CFG_MCOPRE_POS)               /**< 0x30000000 */
#define RCC_CFG_MCOPRE_DIV16               (0x4UL << RCC_CFG_MCOPRE_POS)               /**< 0x40000000 */
#define RCC_CFG_MCOPRE_DIV32               (0x5UL << RCC_CFG_MCOPRE_POS)               /**< 0x50000000 */
#define RCC_CFG_MCOPRE_DIV64               (0x6UL << RCC_CFG_MCOPRE_POS)               /**< 0x60000000 */
#define RCC_CFG_MCOPRE_DIV128              (0x7UL << RCC_CFG_MCOPRE_POS)               /**< 0x70000000 */
                                                                                    
/* Bits for RCC_PLLCFG */                                                           
#define RCC_PLLCFG_PLLSRC_POS              (0U)                                       
#define RCC_PLLCFG_PLLSRC_MASK             (0x1UL << RCC_PLLCFG_PLLSRC_POS)            /**< 0x00000003 */
#define RCC_PLLCFG_PLLSRC                  RCC_PLLCFG_PLLSRC_MASK                      /**< PLLSRC PLL input clock selection */
#define RCC_PLLCFG_PLLSRC_RCH              (0x0UL << RCC_PLLCFG_PLLSRC_POS)            /**< 0x00000000 */
#define RCC_PLLCFG_PLLSRC_HXTAL            (0x1UL << RCC_PLLCFG_PLLSRC_POS)            /**< 0x00000001 */
         
#define RCC_PLLCFG_PLLM_POS                (3U)                                       
#define RCC_PLLCFG_PLLM_MASK               (0x1FUL << RCC_PLLCFG_PLLM_POS)             /**< 0x000000F8 */
#define RCC_PLLCFG_PLLM                    RCC_PLLCFG_PLLM_MASK   

#define RCC_PLLCFG_PLLN_POS                (8U)                                       
#define RCC_PLLCFG_PLLN_MASK               (0x7UL << RCC_PLLCFG_PLLN_POS)              /**< 0x00000700 */
#define RCC_PLLCFG_PLLN                    RCC_PLLCFG_PLLN_MASK                                                                        

#define RCC_PLLCFG_PLLEN_POS               (16)                                       
#define RCC_PLLCFG_PLLEN_MASK              (0x1UL << RCC_PLLCFG_PLLEN_POS)             /**< 0x00010000 */
#define RCC_PLLCFG_PLLEN                   RCC_PLLCFG_PLLEN_MASK                       /**< PLL clock output enable */                                                                                 

#define RCC_PLLCFG_PLLDIV_POS              (17U)                                      
#define RCC_PLLCFG_PLLDIV_MASK             (0x3UL << RCC_PLLCFG_PLLDIV_POS)            /**< 0x00060000 */
#define RCC_PLLCFG_PLLDIV                  RCC_PLLCFG_PLLDIV_MASK                      /**< PLL output clock division factor */
#define RCC_PLLCFG_PLLDIV_1                (0x0UL << RCC_PLLCFG_PLLDIV_POS)            /**< 0x00000000 */
#define RCC_PLLCFG_PLLDIV_2                (0x1UL << RCC_PLLCFG_PLLDIV_POS)            /**< 0x00020000 */
#define RCC_PLLCFG_PLLDIV_4                (0x2UL << RCC_PLLCFG_PLLDIV_POS)            /**< 0x00040000 */
#define RCC_PLLCFG_PLLDIV_8                (0x3UL << RCC_PLLCFG_PLLDIV_POS)            /**< 0x00060000 */
                                      
/* Bits for RCC_IER */                
#define RCC_IER_RCL_RDYIE_POS              (0U)
#define RCC_IER_RCL_RDYIE_MASK             (0x1UL << RCC_IER_RCL_RDYIE_POS)            /**< 0x00000001 */
#define RCC_IER_RCL_RDYIE                  RCC_IER_RCL_RDYIE_MASK                      /**< RCL ready interrupt enable   */

#define RCC_IER_LXTAL_RDYIE_POS            (1U)                                       
#define RCC_IER_LXTAL_RDYIE_MASK           (0x1UL << RCC_IER_LXTAL_RDYIE_POS)          /**< 0x00000002 */
#define RCC_IER_LXTAL_RDYIE                RCC_IER_LXTAL_RDYIE_MASK                    /**< LXTAL ready interrupt enable */

#define RCC_IER_RCH_RDYIE_POS              (3U)                                       
#define RCC_IER_RCH_RDYIE_MASK             (0x1UL << RCC_IER_RCH_RDYIE_POS)            /**< 0x00000008 */
#define RCC_IER_RCH_RDYIE                  RCC_IER_RCH_RDYIE_MASK                      /**< RCH ready interrupt enable   */

#define RCC_IER_HXTAL_RDYIE_POS            (4U)                                       
#define RCC_IER_HXTAL_RDYIE_MASK           (0x1UL << RCC_IER_HXTAL_RDYIE_POS)          /**< 0x00000010 */
#define RCC_IER_HXTAL_RDYIE                RCC_IER_HXTAL_RDYIE_MASK                    /**< HXTAL ready interrupt enable */

#define RCC_IER_PLL_RDYIE_POS              (5U)                                       
#define RCC_IER_PLL_RDYIE_MASK             (0x1UL << RCC_IER_PLL_RDYIE_POS)            /**< 0x00000020 */
#define RCC_IER_PLL_RDYIE                  RCC_IER_PLL_RDYIE_MASK                      /**< PLL ready interrupt enable   */
                                                                                    
/* Bits for RCC_ISR */                                                              
#define RCC_ISR_RCL_RDYF_POS               (0U)                                        
#define RCC_ISR_RCL_RDYF_MASK              (0x1UL << RCC_ISR_RCL_RDYF_POS)             /**< 0x00000001 */
#define RCC_ISR_RCL_RDYF                   RCC_ISR_RCL_RDYF_MASK                       /**< RCL ready interrupt flag   */

#define RCC_ISR_LXTAL_RDYF_POS             (1U)                                        
#define RCC_ISR_LXTAL_RDYF_MASK            (0x1UL << RCC_ISR_LXTAL_RDYF_POS)           /**< 0x00000002 */
#define RCC_ISR_LXTAL_RDYF                 RCC_ISR_LXTAL_RDYF_MASK                     /**< LXTAL ready interrupt flag */

#define RCC_ISR_RCH_RDYF_POS               (3U)                                        
#define RCC_ISR_RCH_RDYF_MASK              (0x1UL << RCC_ISR_RCH_RDYF_POS)             /**< 0x00000008 */
#define RCC_ISR_RCH_RDYF                   RCC_ISR_RCH_RDYF_MASK                       /**< RCH ready interrupt flag   */

#define RCC_ISR_HXTAL_RDYF_POS             (4U)                                        
#define RCC_ISR_HXTAL_RDYF_MASK            (0x1UL << RCC_ISR_HXTAL_RDYF_POS)           /**< 0x00000010 */
#define RCC_ISR_HXTAL_RDYF                 RCC_ISR_HXTAL_RDYF_MASK                     /**< HXTAL ready interrupt flag */

#define RCC_ISR_PLL_RDYF_POS               (5U)                                        
#define RCC_ISR_PLL_RDYF_MASK              (0x1UL << RCC_ISR_PLL_RDYF_POS)             /**< 0x00000020 */
#define RCC_ISR_PLL_RDYF                   RCC_ISR_PLL_RDYF_MASK                       /**< PLL ready interrupt flag   */                                        

#define RCC_ISR_HXTAL_CSSF_POS             (8U)                                        
#define RCC_ISR_HXTAL_CSSF_MASK            (0x1UL << RCC_ISR_HXTAL_CSSF_POS)           /**< 0x00000100 */
#define RCC_ISR_HXTAL_CSSF                 RCC_ISR_HXTAL_CSSF_MASK                     /**< HXTAL CSS interrupt flag   */    
                                                                                   
/* Bits for RCC_ICR */                                                              
#define RCC_ICR_RCL_RDYC_POS               (0U)                                        
#define RCC_ICR_RCL_RDYC_MASK              (0x1UL << RCC_ICR_RCL_RDYC_POS)             /**< 0x00000001 */
#define RCC_ICR_RCL_RDYC                   RCC_ICR_RCL_RDYC_MASK                       /**< Clear RCL ready interrupt flag   */

#define RCC_ICR_LXTAL_RDYC_POS             (1U)                                        
#define RCC_ICR_LXTAL_RDYC_MASK            (0x1UL << RCC_ICR_LXTAL_RDYC_POS)           /**< 0x00000002 */
#define RCC_ICR_LXTAL_RDYC                 RCC_ICR_LXTAL_RDYC_MASK                     /**< Clear LXTAL ready interrupt flag */

#define RCC_ICR_RCH_RDYC_POS               (3U)                                        
#define RCC_ICR_RCH_RDYC_MASK              (0x1UL << RCC_ICR_RCH_RDYC_POS)             /**< 0x00000008 */
#define RCC_ICR_RCH_RDYC                   RCC_ICR_RCH_RDYC_MASK                       /**< Clear RCH ready interrupt flag   */

#define RCC_ICR_HXTAL_RDYC_POS             (4U)                                        
#define RCC_ICR_HXTAL_RDYC_MASK            (0x1UL << RCC_ICR_HXTAL_RDYC_POS)           /**< 0x00000010 */
#define RCC_ICR_HXTAL_RDYC                 RCC_ICR_HXTAL_RDYC_MASK                     /**< Clear HXTAL ready interrupt flag */

#define RCC_ICR_PLL_RDYC_POS               (5U)                                        
#define RCC_ICR_PLL_RDYC_MASK              (0x1UL << RCC_ICR_PLL_RDYC_POS)             /**< 0x00000020 */
#define RCC_ICR_PLL_RDYC                   RCC_ICR_PLL_RDYC_MASK                       /**< Clear PLL ready interrupt flag   */                                                                                                                       

#define RCC_ICR_HXTAL_CSSC_POS             (8U)                                        
#define RCC_ICR_HXTAL_CSSC_MASK            (0x1UL << RCC_ICR_HXTAL_CSSC_POS)           /**< 0x00000100 */
#define RCC_ICR_HXTAL_CSSC                 RCC_ICR_HXTAL_CSSC_MASK                     /**< Clear HXTAL CSS interrupt flag   */    

/* Bits for RCC_IOPRST */                                                           
#define RCC_IOPRST_GPIOA_RST_POS           (0U)                                        
#define RCC_IOPRST_GPIOA_RST_MASK          (0x1UL << RCC_IOPRST_GPIOA_RST_POS)         /**< 0x00000001 */
#define RCC_IOPRST_GPIOA_RST               RCC_IOPRST_GPIOA_RST_MASK                   /**< GPIOA reset control   */
#define RCC_IOPRST_GPIOB_RST_POS           (1U)                                        
#define RCC_IOPRST_GPIOB_RST_MASK          (0x1UL << RCC_IOPRST_GPIOB_RST_POS)         /**< 0x00000002 */
#define RCC_IOPRST_GPIOB_RST               RCC_IOPRST_GPIOB_RST_MASK                   /**< GPIOB reset control   */
#define RCC_IOPRST_GPIOC_RST_POS           (2U)                                        
#define RCC_IOPRST_GPIOC_RST_MASK          (0x1UL << RCC_IOPRST_GPIOC_RST_POS)         /**< 0x00000004 */
#define RCC_IOPRST_GPIOC_RST               RCC_IOPRST_GPIOC_RST_MASK                   /**< GPIOC reset control   */
#define RCC_IOPRST_GPIOD_RST_POS           (3U)                                        
#define RCC_IOPRST_GPIOD_RST_MASK          (0x1UL << RCC_IOPRST_GPIOD_RST_POS)         /**< 0x00000008 */
#define RCC_IOPRST_GPIOD_RST               RCC_IOPRST_GPIOD_RST_MASK                   /**< GPIOD reset control   */                      
#define RCC_IOPRST_GPIOF_RST_POS           (5U)                                        
#define RCC_IOPRST_GPIOF_RST_MASK          (0x1UL << RCC_IOPRST_GPIOF_RST_POS)         /**< 0x00000020 */
#define RCC_IOPRST_GPIOF_RST               RCC_IOPRST_GPIOF_RST_MASK                   /**< GPIOF reset control   */
                                                                                    
/* Bits for RCC_AHBRST */                                                           
#define RCC_AHBRST_DMA_RST_POS             (0U)                                        
#define RCC_AHBRST_DMA_RST_MASK            (0x1UL << RCC_AHBRST_DMA_RST_POS)           /**< 0x00000001 */
#define RCC_AHBRST_DMA_RST                 RCC_AHBRST_DMA_RST_MASK                     /**< DMA reset control     */

#define RCC_AHBRST_CRC_RST_POS             (12U)                                       
#define RCC_AHBRST_CRC_RST_MASK            (0x1UL << RCC_AHBRST_CRC_RST_POS)           /**< 0x00001000 */
#define RCC_AHBRST_CRC_RST                 RCC_AHBRST_CRC_RST_MASK                     /**< CRC reset control     */                                        

#define RCC_AHBRST_AES_RST_POS             (16U)                                       
#define RCC_AHBRST_AES_RST_MASK            (0x1UL << RCC_AHBRST_AES_RST_POS)           /**< 0x00010000 */
#define RCC_AHBRST_AES_RST                 RCC_AHBRST_AES_RST_MASK                     /**< AES reset control     */     
                                                                                    
/* Bits for RCC_APB1RSTR */                                                         
#define RCC_APB1RST_TIM3_RST_POS           (1U)                                        
#define RCC_APB1RST_TIM3_RST_MASK          (0x1UL << RCC_APB1RST_TIM3_RST_POS)         /**< 0x00000002 */
#define RCC_APB1RST_TIM3_RST               RCC_APB1RST_TIM3_RST_MASK                   /**< TIM3 reset control     */

#define RCC_APB1RST_TIM4_RST_POS           (2U)                                        
#define RCC_APB1RST_TIM4_RST_MASK          (0x1UL << RCC_APB1RST_TIM4_RST_POS)         /**< 0x00000004 */
#define RCC_APB1RST_TIM4_RST               RCC_APB1RST_TIM4_RST_MASK                   /**< TIM4 reset control     */

#define RCC_APB1RST_TIM5_RST_POS           (3U)                                        
#define RCC_APB1RST_TIM5_RST_MASK          (0x1UL << RCC_APB1RST_TIM5_RST_POS)         /**< 0x00000008 */
#define RCC_APB1RST_TIM5_RST               RCC_APB1RST_TIM5_RST_MASK                   /**< TIM5 reset control     */

#define RCC_APB1RST_TIM8_RST_POS           (6U)                                        
#define RCC_APB1RST_TIM8_RST_MASK          (0x1UL << RCC_APB1RST_TIM8_RST_POS)         /**< 0x00000040 */
#define RCC_APB1RST_TIM8_RST               RCC_APB1RST_TIM8_RST_MASK                   /**< TIM8 reset control     */                                                                             

#define RCC_APB1RST_LCD_RST_POS            (8U)                                        
#define RCC_APB1RST_LCD_RST_MASK           (0x1UL << RCC_APB1RST_LCD_RST_POS)          /**< 0x00000100 */
#define RCC_APB1RST_LCD_RST                RCC_APB1RST_LCD_RST_MASK                    /**< LCD reset control      */                                                                                                                                                

#define RCC_APB1RST_SPI2_RST_POS           (14U)                                        
#define RCC_APB1RST_SPI2_RST_MASK          (0x1UL << RCC_APB1RST_SPI2_RST_POS)         /**< 0x00004000 */
#define RCC_APB1RST_SPI2_RST               RCC_APB1RST_SPI2_RST_MASK                   /**< SPI2 reset control     */                                                                                                                                                

#define RCC_APB1RST_UART2_RST_POS          (17U)                                       
#define RCC_APB1RST_UART2_RST_MASK         (0x1UL << RCC_APB1RST_UART2_RST_POS)        /**< 0x00020000 */
#define RCC_APB1RST_UART2_RST              RCC_APB1RST_UART2_RST_MASK                  /**< UART2 reset control    */                     

#define RCC_APB1RST_UART3_RST_POS          (18U)                                       
#define RCC_APB1RST_UART3_RST_MASK         (0x1UL << RCC_APB1RST_UART3_RST_POS)        /**< 0x00040000 */
#define RCC_APB1RST_UART3_RST              RCC_APB1RST_UART3_RST_MASK                  /**< UART3 reset control    */ 

#define RCC_APB1RST_UART4_RST_POS         (19U)                                       
#define RCC_APB1RST_UART4_RST_MASK        (0x1UL << RCC_APB1RST_UART4_RST_POS)         /**< 0x00080000 */
#define RCC_APB1RST_UART4_RST             RCC_APB1RST_UART4_RST_MASK                   /**< UART4 reset control    */ 

#define RCC_APB1RST_LPUART1_RST_POS        (20U)                                       
#define RCC_APB1RST_LPUART1_RST_MASK       (0x1UL << RCC_APB1RST_LPUART1_RST_POS)      /**< 0x00100000 */
#define RCC_APB1RST_LPUART1_RST            RCC_APB1RST_LPUART1_RST_MASK                /**< LPUART1 reset control  */                                                                            

#define RCC_APB1RST_I2C1_RST_POS           (21U)                                       
#define RCC_APB1RST_I2C1_RST_MASK          (0x1UL << RCC_APB1RST_I2C1_RST_POS)         /**< 0x00200000 */
#define RCC_APB1RST_I2C1_RST               RCC_APB1RST_I2C1_RST_MASK                   /**< I2C1 reset control     */

#define RCC_APB1RST_LPUART2_RST_POS        (23U)                                       
#define RCC_APB1RST_LPUART2_RST_MASK       (0x1UL << RCC_APB1RST_LPUART2_RST_POS)      /**< 0x00800000 */
#define RCC_APB1RST_LPUART2_RST            RCC_APB1RST_LPUART2_RST_MASK                /**< LPUART2 reset control  */                                                                                                                                                                                                   

#define RCC_APB1RST_LPTIM2_RST_POS          (30U)                                       
#define RCC_APB1RST_LPTIM2_RST_MASK        (0x1UL << RCC_APB1RST_LPTIM2_RST_POS)       /**< 0x40000000 */
#define RCC_APB1RST_LPTIM2_RST             RCC_APB1RST_LPTIM2_RST_MASK                 /**< LPTIM2 reset control   */

#define RCC_APB1RST_LPTIM1_RST_POS          (31U)                                       
#define RCC_APB1RST_LPTIM1_RST_MASK        (0x1UL << RCC_APB1RST_LPTIM1_RST_POS)       /**< 0x80000000 */
#define RCC_APB1RST_LPTIM1_RST             RCC_APB1RST_LPTIM1_RST_MASK                 /**< LPTIM1 reset control   */
                                                                                    
/* Bits for RCC_APB2RST */                                                          
#define RCC_APB2RST_SYSCFG_RST_POS         (0U)                                        
#define RCC_APB2RST_SYSCFG_RST_MASK        (0x1UL << RCC_APB2RST_SYSCFG_RST_POS)       /**< 0x00000001 */
#define RCC_APB2RST_SYSCFG_RST             RCC_APB2RST_SYSCFG_RST_MASK                 /**< SYSCFG reset control   */

#define RCC_APB2RST_TRNG_RST_POS           (4U)                                        
#define RCC_APB2RST_TRNG_RST_MASK          (0x1UL << RCC_APB2RST_TRNG_RST_POS)         /**< 0x00000010 */
#define RCC_APB2RST_TRNG_RST               RCC_APB2RST_TRNG_RST_MASK                   /**< TRNG reset control     */                                                               

#define RCC_APB2RST_SPI1_RST_POS           (12U)                                       
#define RCC_APB2RST_SPI1_RST_MASK          (0x1UL << RCC_APB2RST_SPI1_RST_POS)         /**< 0x00001000 */
#define RCC_APB2RST_SPI1_RST               RCC_APB2RST_SPI1_RST_MASK                   /**< SPI1 reset control     */

#define RCC_APB2RST_USART1_RST_POS         (14U)                                       
#define RCC_APB2RST_USART1_RST_MASK        (0x1UL << RCC_APB2RST_USART1_RST_POS)       /**< 0x00004000 */
#define RCC_APB2RST_USART1_RST             RCC_APB2RST_USART1_RST_MASK                 /**< USART1 reset control   */                                                                      

#define RCC_APB2RST_ADC_RST_POS            (20U)                                       
#define RCC_APB2RST_ADC_RST_MASK           (0x1UL << RCC_APB2RST_ADC_RST_POS)          /**< 0x00100000 */
#define RCC_APB2RST_ADC_RST                RCC_APB2RST_ADC_RST_MASK                    /**< ADC reset control      */

#define RCC_APB2RST_DBG_RST_POS            (27U)                                       
#define RCC_APB2RST_DBG_RST_MASK           (0x1UL << RCC_APB2RST_DBG_RST_POS)          /**< 0x08000000 */
#define RCC_APB2RST_DBG_RST                RCC_APB2RST_DBG_RST_MASK                    /**< DBG reset control      */
                                                                                    
/* Bits for RCC_IOPEN */                                                           
#define RCC_IOPEN_GPIOAEN_POS              (0U)                                        
#define RCC_IOPEN_GPIOAEN_MASK             (0x1UL << RCC_IOPEN_GPIOAEN_POS)            /**< 0x00000001 */
#define RCC_IOPEN_GPIOAEN                  RCC_IOPEN_GPIOAEN_MASK                      /**< GPIOA clock enable     */
#define RCC_IOPEN_GPIOBEN_POS              (1U)                                        
#define RCC_IOPEN_GPIOBEN_MASK             (0x1UL << RCC_IOPEN_GPIOBEN_POS)            /**< 0x00000002 */
#define RCC_IOPEN_GPIOBEN                  RCC_IOPEN_GPIOBEN_MASK                      /**< GPIOB clock enable     */
#define RCC_IOPEN_GPIOCEN_POS              (2U)                                        
#define RCC_IOPEN_GPIOCEN_MASK             (0x1UL << RCC_IOPEN_GPIOCEN_POS)            /**< 0x00000004 */
#define RCC_IOPEN_GPIOCEN                  RCC_IOPEN_GPIOCEN_MASK                      /**< GPIOC clock enable     */
#define RCC_IOPEN_GPIODEN_POS              (3U)                                        
#define RCC_IOPEN_GPIODEN_MASK             (0x1UL << RCC_IOPEN_GPIODEN_POS)            /**< 0x00000008 */
#define RCC_IOPEN_GPIODEN                  RCC_IOPEN_GPIODEN_MASK                      /**< GPIOD clock enable     */

#define RCC_IOPEN_GPIOFEN_POS              (5U)                                        
#define RCC_IOPEN_GPIOFEN_MASK             (0x1UL << RCC_IOPEN_GPIOFEN_POS)            /**< 0x00000020 */
#define RCC_IOPEN_GPIOFEN                  RCC_IOPEN_GPIOFEN_MASK                      /**< GPIOF clock enable     */
                                                                                    
/* Bits for RCC_AHBEN */                                                            
#define RCC_AHBEN_DMAEN_POS                (0U)                                        
#define RCC_AHBEN_DMAEN_MASK               (0x1UL << RCC_AHBEN_DMAEN_POS)              /**< 0x00000001 */
#define RCC_AHBEN_DMAEN                    RCC_AHBEN_DMAEN_MASK                        /**< DMA clock enable       */

#define RCC_AHBEN_FLASHEN_POS              (8U)                                        
#define RCC_AHBEN_FLASHEN_MASK             (0x1UL << RCC_AHBEN_FLASHEN_POS)            /**< 0x00000100 */
#define RCC_AHBEN_FLASHEN                  RCC_AHBEN_FLASHEN_MASK                      /**< FLASH clock enable     */

#define RCC_AHBEN_CRCEN_POS                (12U)                                       
#define RCC_AHBEN_CRCEN_MASK               (0x1UL << RCC_AHBEN_CRCEN_POS)              /**< 0x00001000 */
#define RCC_AHBEN_CRCEN                    RCC_AHBEN_CRCEN_MASK                        /**< CRC clock enable       */

#define RCC_AHBEN_AESEN_POS                (16U)                                       
#define RCC_AHBEN_AESEN_MASK               (0x1UL << RCC_AHBEN_AESEN_POS)              /**< 0x00010000 */
#define RCC_AHBEN_AESEN                    RCC_AHBEN_AESEN_MASK                        /**< AES clock enable       */
                                                                                    
/* Bits for RCC_APB1EN */                                                           
#define RCC_APB1EN_TIM3EN_POS              (1U)                                        
#define RCC_APB1EN_TIM3EN_MASK             (0x1UL << RCC_APB1EN_TIM3EN_POS)            /**< 0x00000002 */
#define RCC_APB1EN_TIM3EN                  RCC_APB1EN_TIM3EN_MASK                      /**< TIM3 clock enable      */

#define RCC_APB1EN_TIM4EN_POS              (2U)
#define RCC_APB1EN_TIM4EN_MASK             (0x1UL << RCC_APB1EN_TIM4EN_POS)            /**< 0x00000004 */
#define RCC_APB1EN_TIM4EN                  RCC_APB1EN_TIM4EN_MASK                      /**< TIM4 clock enable      */

#define RCC_APB1EN_TIM5EN_POS              (3U)                                         
#define RCC_APB1EN_TIM5EN_MASK             (0x1UL << RCC_APB1EN_TIM5EN_POS)            /**< 0x00000008*/
#define RCC_APB1EN_TIM5EN                  RCC_APB1EN_TIM5EN_MASK                      /**< TIM5 clock enable      */

#define RCC_APB1EN_TIM8EN_POS              (6U)                                         
#define RCC_APB1EN_TIM8EN_MASK             (0x1UL << RCC_APB1EN_TIM8EN_POS)            /**< 0x00000040 */
#define RCC_APB1EN_TIM8EN                  RCC_APB1EN_TIM8EN_MASK                      /**< TIM8 clock enable      */                                                      

#define RCC_APB1EN_LCDEN_POS               (8U)                                         
#define RCC_APB1EN_LCDEN_MASK              (0x1UL << RCC_APB1EN_LCDEN_POS)             /**< 0x00000100 */
#define RCC_APB1EN_LCDEN                   RCC_APB1EN_LCDEN_MASK                       /**< LCD clock enable       */                                                        

#define RCC_APB1EN_RTCAPBEN_POS            (10U)                                     
#define RCC_APB1EN_RTCAPBEN_MASK           (0x1UL << RCC_APB1EN_RTCAPBEN_POS)          /**< 0x00000400 */
#define RCC_APB1EN_RTCAPBEN                RCC_APB1EN_RTCAPBEN_MASK                    /**< RTC clock enable       */

#define RCC_APB1EN_WWDGEN_POS              (11U)                                     
#define RCC_APB1EN_WWDGEN_MASK             (0x1UL << RCC_APB1EN_WWDGEN_POS)            /**< 0x00000800 */
#define RCC_APB1EN_WWDGEN                  RCC_APB1EN_WWDGEN_MASK                      /**< WWDG clock enable      */

#define RCC_APB1EN_SPI2EN_POS              (14U)                                     
#define RCC_APB1EN_SPI2EN_MASK             (0x1UL << RCC_APB1EN_SPI2EN_POS)            /**< 0x00004000 */
#define RCC_APB1EN_SPI2EN                  RCC_APB1EN_SPI2EN_MASK                      /**< SPI2 clock enable      */

#define RCC_APB1EN_UART2EN_POS             (17U)                                     
#define RCC_APB1EN_UART2EN_MASK            (0x1UL << RCC_APB1EN_UART2EN_POS)          /**< 0x00020000 */
#define RCC_APB1EN_UART2EN                 RCC_APB1EN_UART2EN_MASK                    /**< UART2 clock enable     */

#define RCC_APB1EN_UART3EN_POS             (18U)                                     
#define RCC_APB1EN_UART3EN_MASK            (0x1UL << RCC_APB1EN_UART3EN_POS)          /**< 0x00040000 */
#define RCC_APB1EN_UART3EN                 RCC_APB1EN_UART3EN_MASK                    /**< UART3 clock enable     */

#define RCC_APB1EN_UART4EN_POS             (19U)                                     
#define RCC_APB1EN_UART4EN_MASK            (0x1UL << RCC_APB1EN_UART4EN_POS)          /**< 0x00080000 */
#define RCC_APB1EN_UART4EN                 RCC_APB1EN_UART4EN_MASK                    /**< UART4 clock enable     */

#define RCC_APB1EN_LPUART1EN_POS           (20U)                                     
#define RCC_APB1EN_LPUART1EN_MASK          (0x1UL << RCC_APB1EN_LPUART1EN_POS)         /**< 0x00100000 */
#define RCC_APB1EN_LPUART1EN               RCC_APB1EN_LPUART1EN_MASK                   /**< LPUART1 clock enable   */

#define RCC_APB1EN_I2C1EN_POS              (21U)                                     
#define RCC_APB1EN_I2C1EN_MASK             (0x1UL << RCC_APB1EN_I2C1EN_POS)            /**< 0x00200000 */
#define RCC_APB1EN_I2C1EN                  RCC_APB1EN_I2C1EN_MASK                      /**< I2C1 clock enable      */

#define RCC_APB1EN_LPUART2EN_POS           (23U)                                     
#define RCC_APB1EN_LPUART2EN_MASK          (0x1UL << RCC_APB1EN_LPUART2EN_POS)         /**< 0x00800000 */
#define RCC_APB1EN_LPUART2EN               RCC_APB1EN_LPUART2EN_MASK                   /**< LPUART2 clock enable   */

#define RCC_APB1EN_PMUEN_POS               (28U)                                     
#define RCC_APB1EN_PMUEN_MASK              (0x1UL << RCC_APB1EN_PMUEN_POS)             /**< 0x10000000 */
#define RCC_APB1EN_PMUEN                   RCC_APB1EN_PMUEN_MASK                       /**< PMU clock enable       */                                                                        

#define RCC_APB1EN_LPTIM2EN_POS            (30U)                                     
#define RCC_APB1EN_LPTIM2EN_MASK           (0x1UL << RCC_APB1EN_LPTIM2EN_POS)          /**< 0x40000000 */
#define RCC_APB1EN_LPTIM2EN                RCC_APB1EN_LPTIM2EN_MASK                    /**< LPTIM2 clock enable    */

#define RCC_APB1EN_LPTIM1EN_POS            (31U)                                     
#define RCC_APB1EN_LPTIM1EN_MASK           (0x1UL << RCC_APB1EN_LPTIM1EN_POS)          /**< 0x80000000 */
#define RCC_APB1EN_LPTIM1EN                RCC_APB1EN_LPTIM1EN_MASK                    /**< LPTIM1 clock enable    */

/* Bits for RCC_APB2EN */
#define RCC_APB2EN_SYSCFGEN_POS            (0U)
#define RCC_APB2EN_SYSCFGEN_MASK           (0x1UL << RCC_APB2EN_SYSCFGEN_POS)          /**< 0x00000001 */
#define RCC_APB2EN_SYSCFGEN                RCC_APB2EN_SYSCFGEN_MASK                    /**< SYSCFG clock enable    */

#define RCC_APB2EN_TRNGEN_POS              (4U)                                         
#define RCC_APB2EN_TRNGEN_MASK             (0x1UL << RCC_APB2EN_TRNGEN_POS)            /**< 0x00000010 */
#define RCC_APB2EN_TRNGEN                  RCC_APB2EN_TRNGEN_MASK                      /**< TRNG clock enable      */

#define RCC_APB2EN_SPI1EN_POS              (12U)                                        
#define RCC_APB2EN_SPI1EN_MASK             (0x1UL << RCC_APB2EN_SPI1EN_POS)            /**< 0x00001000 */
#define RCC_APB2EN_SPI1EN                  RCC_APB2EN_SPI1EN_MASK                      /**< SPI1 clock enable      */

#define RCC_APB2EN_USART1EN_POS            (14U)                                        
#define RCC_APB2EN_USART1EN_MASK           (0x1UL << RCC_APB2EN_USART1EN_POS)          /**< 0x00004000 */
#define RCC_APB2EN_USART1EN                RCC_APB2EN_USART1EN_MASK                    /**< USART1 clock enable    */

#define RCC_APB2EN_ADCEN_POS               (20U)                                        
#define RCC_APB2EN_ADCEN_MASK              (0x1UL << RCC_APB2EN_ADCEN_POS)             /**< 0x00100000 */
#define RCC_APB2EN_ADCEN                   RCC_APB2EN_ADCEN_MASK                       /**< ADC clock enable       */

#define RCC_APB2EN_DBGEN_POS               (27U)                                        
#define RCC_APB2EN_DBGEN_MASK              (0x1UL << RCC_APB2EN_DBGEN_POS)             /**< 0x08000000 */
#define RCC_APB2EN_DBGEN                   RCC_APB2EN_DBGEN_MASK                       /**< DBG clock enable       */
                                                                                     
/* Bits for RCC_CLKSEL */                                                              
#define RCC_CLKSEL_LPUART2_SEL_POS         (8U)                                        
#define RCC_CLKSEL_LPUART2_SEL_MASK        (0x3UL << RCC_CLKSEL_LPUART2_SEL_POS)       /**< 0x00000300 */
#define RCC_CLKSEL_LPUART2_SEL             RCC_CLKSEL_LPUART2_SEL_MASK                 /**< LPUART2 KCLK selection */ 
#define RCC_CLKSEL_LPUART2_SEL_PCLK        (0x0UL << RCC_CLKSEL_LPUART2_SEL_POS)       /**< 0x00000000 */
#define RCC_CLKSEL_LPUART2_SEL_SYSCLK      (0x1UL << RCC_CLKSEL_LPUART2_SEL_POS)       /**< 0x00000100 */
#define RCC_CLKSEL_LPUART2_SEL_RCH         (0x2UL << RCC_CLKSEL_LPUART2_SEL_POS)       /**< 0x00000200 */
#define RCC_CLKSEL_LPUART2_SEL_LXTAL       (0x3UL << RCC_CLKSEL_LPUART2_SEL_POS)       /**< 0x00000300 */  

#define RCC_CLKSEL_LPUART1_SEL_POS         (10U)                                        
#define RCC_CLKSEL_LPUART1_SEL_MASK        (0x3UL << RCC_CLKSEL_LPUART1_SEL_POS)       /**< 0x00000C00 */
#define RCC_CLKSEL_LPUART1_SEL             RCC_CLKSEL_LPUART1_SEL_MASK                 /**< LPUART1 KCLK selection */ 
#define RCC_CLKSEL_LPUART1_SEL_PCLK        (0x0UL << RCC_CLKSEL_LPUART1_SEL_POS)       /**< 0x00000000 */
#define RCC_CLKSEL_LPUART1_SEL_SYSCLK      (0x1UL << RCC_CLKSEL_LPUART1_SEL_POS)       /**< 0x00000400 */
#define RCC_CLKSEL_LPUART1_SEL_RCH         (0x2UL << RCC_CLKSEL_LPUART1_SEL_POS)       /**< 0x00000800 */
#define RCC_CLKSEL_LPUART1_SEL_LXTAL       (0x3UL << RCC_CLKSEL_LPUART1_SEL_POS)       /**< 0x00000C00 */   

#define RCC_CLKSEL_I2C1_SEL_POS            (12U)                                        
#define RCC_CLKSEL_I2C1_SEL_MASK           (0x3UL << RCC_CLKSEL_I2C1_SEL_POS)          /**< 0x00003000 */
#define RCC_CLKSEL_I2C1_SEL                RCC_CLKSEL_I2C1_SEL_MASK                    /**< I2C1 KCLK selection    */ 
#define RCC_CLKSEL_I2C1_SEL_PCLK           (0x0UL << RCC_CLKSEL_I2C1_SEL_POS)          /**< 0x00000000 */
#define RCC_CLKSEL_I2C1_SEL_SYSCLK         (0x1UL << RCC_CLKSEL_I2C1_SEL_POS)          /**< 0x00001000 */
#define RCC_CLKSEL_I2C1_SEL_RCH            (0x2UL << RCC_CLKSEL_I2C1_SEL_POS)          /**< 0x00002000 */  

#define RCC_CLKSEL_LPTIM1_SEL_POS          (18U)                                        
#define RCC_CLKSEL_LPTIM1_SEL_MASK         (0x3UL << RCC_CLKSEL_LPTIM1_SEL_POS)        /**< 0x000C0000 */
#define RCC_CLKSEL_LPTIM1_SEL              RCC_CLKSEL_LPTIM1_SEL_MASK                  /**< LPTIM1 KCLK selection  */  
#define RCC_CLKSEL_LPTIM1_SEL_PCLK         (0x0UL << RCC_CLKSEL_LPTIM1_SEL_POS)        /**< 0x00000000 */
#define RCC_CLKSEL_LPTIM1_SEL_RCL          (0x1UL << RCC_CLKSEL_LPTIM1_SEL_POS)        /**< 0x00040000 */
#define RCC_CLKSEL_LPTIM1_SEL_RCH          (0x2UL << RCC_CLKSEL_LPTIM1_SEL_POS)        /**< 0x00080000 */
#define RCC_CLKSEL_LPTIM1_SEL_LXTAL        (0x3UL << RCC_CLKSEL_LPTIM1_SEL_POS)        /**< 0x000C0000 */   

#define RCC_CLKSEL_LPTIM2_SEL_POS          (20U)                                        
#define RCC_CLKSEL_LPTIM2_SEL_MASK         (0x3UL << RCC_CLKSEL_LPTIM2_SEL_POS)        /**< 0x00300000 */
#define RCC_CLKSEL_LPTIM2_SEL              RCC_CLKSEL_LPTIM2_SEL_MASK                  /**< LPTIM2 KCLK selection  */  

#define RCC_CLKSEL_LPTIM2_SEL_PCLK         (0x0UL << RCC_CLKSEL_LPTIM2_SEL_POS)        /**< 0x00000000 */
#define RCC_CLKSEL_LPTIM2_SEL_RCL          (0x1UL << RCC_CLKSEL_LPTIM2_SEL_POS)        /**< 0x00100000 */
#define RCC_CLKSEL_LPTIM2_SEL_RCH          (0x2UL << RCC_CLKSEL_LPTIM2_SEL_POS)        /**< 0x00200000 */
#define RCC_CLKSEL_LPTIM2_SEL_LXTAL        (0x3UL << RCC_CLKSEL_LPTIM2_SEL_POS)        /**< 0x00300000 */   

#define RCC_CLKSEL_ADC_SEL_POS             (30U)                                        
#define RCC_CLKSEL_ADC_SEL_MASK            (0x3UL << RCC_CLKSEL_ADC_SEL_POS)           /**< 0xC0000000 */
#define RCC_CLKSEL_ADC_SEL                 RCC_CLKSEL_ADC_SEL_MASK                     /**< ADC KCLK selection     */ 
#define RCC_CLKSEL_ADC_SEL_SYSCLK          (0x0UL << RCC_CLKSEL_ADC_SEL_POS)           /**< 0x00000000 */
#define RCC_CLKSEL_ADC_SEL_SYSCLK_DIV2     (0x1UL << RCC_CLKSEL_ADC_SEL_POS)           /**< 0x40000000 */
#define RCC_CLKSEL_ADC_SEL_SYSCLK_DIV4     (0x2UL << RCC_CLKSEL_ADC_SEL_POS)           /**< 0x80000000 */
#define RCC_CLKSEL_ADC_SEL_RCH             (0x3UL << RCC_CLKSEL_ADC_SEL_POS)           /**< 0xC0000000 */

/* Bits for RCC_AWCR */
#define RCC_AWCR_LXTALON_POS               (0U)
#define RCC_AWCR_LXTALON_MASK              (0x1UL << RCC_AWCR_LXTALON_POS)             /**< 0x00000001 */
#define RCC_AWCR_LXTALON                   RCC_AWCR_LXTALON_MASK                       /**< LXTAL enable     */
#define RCC_AWCR_LXTAL_DRV_MODE_POS        (1U)                                       
#define RCC_AWCR_LXTAL_DRV_MODE_MASK       (0x1UL << RCC_AWCR_LXTAL_DRV_MODE_POS)      /**< 0x00000002 */
#define RCC_AWCR_LXTAL_DRV_MODE            RCC_AWCR_LXTAL_DRV_MODE_MASK                /**< LXTAL drive mode */
#define RCC_AWCR_LXTALRDY_POS              (2U)                                       
#define RCC_AWCR_LXTALRDY_MASK             (0x1UL << RCC_AWCR_LXTALRDY_POS)            /**< 0x00000004 */
#define RCC_AWCR_LXTALRDY                  RCC_AWCR_LXTALRDY_MASK                      /**< LXTAL ready flag */

#define RCC_AWCR_LXTAL_DRV_POS             (3U)                                       
#define RCC_AWCR_LXTAL_DRV_MASK            (0x3UL << RCC_AWCR_LXTAL_DRV_POS)           /**< 0x00000018 */
#define RCC_AWCR_LXTAL_DRV                 RCC_AWCR_LXTAL_DRV_MASK                     /**< LXTAL_DRV[1:0] LXTAL drive capability control */
#define RCC_AWCR_LXTAL_DRV_0               (0x0UL << RCC_AWCR_LXTAL_DRV_POS)           /**< 0x00000000 */
#define RCC_AWCR_LXTAL_DRV_1               (0x1UL << RCC_AWCR_LXTAL_DRV_POS)           /**< 0x00000008 */
#define RCC_AWCR_LXTAL_DRV_2               (0x2UL << RCC_AWCR_LXTAL_DRV_POS)           /**< 0x00000010 */
#define RCC_AWCR_LXTAL_DRV_3               (0x3UL << RCC_AWCR_LXTAL_DRV_POS)           /**< 0x00000018 */
                                                                                   
#define RCC_AWCR_RTCSEL_POS                (8U)
#define RCC_AWCR_RTCSEL_MASK               (0x3UL << RCC_AWCR_RTCSEL_POS)              /**< 0x00000300 */
#define RCC_AWCR_RTCSEL                    RCC_AWCR_RTCSEL_MASK                        /**< RTCSEL[1:0] RTC clock selection  */
#define RCC_AWCR_RTCSEL_NONE               (0x0UL << RCC_AWCR_RTCSEL_POS)              /**< 0x00000000 */
#define RCC_AWCR_RTCSEL_LXTAL              (0x1UL << RCC_AWCR_RTCSEL_POS)              /**< 0x00000100 */
#define RCC_AWCR_RTCSEL_RCL                (0x2UL << RCC_AWCR_RTCSEL_POS)              /**< 0x00000200 */

#define RCC_AWCR_RTCEN_POS                 (15U)                                       
#define RCC_AWCR_RTCEN_MASK                (0x1UL << RCC_AWCR_RTCEN_POS)               /**< 0x00008000 */
#define RCC_AWCR_RTCEN                     RCC_AWCR_RTCEN_MASK                         /**< RTC KCLK enable */

#define RCC_AWCR_AW_RST_POS                (16U)                                       
#define RCC_AWCR_AW_RST_MASK               (0x1UL << RCC_AWCR_AW_RST_POS)              /**< 0x00010000 */
#define RCC_AWCR_AW_RST                    RCC_AWCR_AW_RST_MASK                        /**< AON domain reset */

#define RCC_AWCR_LXTAL_STAB_SEL_POS        (20U)
#define RCC_AWCR_LXTAL_STAB_SEL_MASK       (0x3UL << RCC_AWCR_LXTAL_STAB_SEL_POS)      /**< 0x00300000 */
#define RCC_AWCR_LXTAL_STAB_SEL            RCC_AWCR_LXTAL_STAB_SEL_MASK                /**< LXTAL_STAB_SEL[1:0] number of LXTAL stable clock cycles */

/* Bits for RCC_CSR2 */
#define RCC_CSR2_RCLON_POS                 (0U)
#define RCC_CSR2_RCLON_MASK                (0x1UL << RCC_CSR2_RCLON_POS)               /**< 0x00000001 */
#define RCC_CSR2_RCLON                     RCC_CSR2_RCLON_MASK                         /**< RCL enable */
#define RCC_CSR2_RCLRDY_POS                (1U)                                       
#define RCC_CSR2_RCLRDY_MASK               (0x1UL << RCC_CSR2_RCLRDY_POS)              /**< 0x00000002 */
#define RCC_CSR2_RCLRDY                    RCC_CSR2_RCLRDY_MASK                        /**< RCL ready flag */

#define RCC_CSR2_LOCKUP_RSTEN_POS          (8U)                                       
#define RCC_CSR2_LOCKUP_RSTEN_MASK         (0x1UL << RCC_CSR2_LOCKUP_RSTEN_POS)        /**< 0x00000100 */
#define RCC_CSR2_LOCKUP_RSTEN              RCC_CSR2_LOCKUP_RSTEN_MASK                  /**< LOCKUP reset enable */

#define RCC_CSR2_RMVF_POS                  (16U)                                      
#define RCC_CSR2_RMVF_MASK                 (0x1UL << RCC_CSR2_RMVF_POS)                /**< 0x00010000 */
#define RCC_CSR2_RMVF                      RCC_CSR2_RMVF_MASK                          /**< Clear reset flag */
                                                           
#define RCC_CSR2_LOCKUP_RSTF_POS           (24U)                                      
#define RCC_CSR2_LOCKUP_RSTF_MASK          (0x1UL << RCC_CSR2_LOCKUP_RSTF_POS)         /**< 0x01000000 */
#define RCC_CSR2_LOCKUP_RSTF               RCC_CSR2_LOCKUP_RSTF_MASK                   /**< LOCKUP reset flag */
#define RCC_CSR2_OBL_RSTF_POS              (25U)                                      
#define RCC_CSR2_OBL_RSTF_MASK             (0x1UL << RCC_CSR2_OBL_RSTF_POS)            /**< 0x02000000 */
#define RCC_CSR2_OBL_RSTF                  RCC_CSR2_OBL_RSTF_MASK                      /**< Option load reset flag */
#define RCC_CSR2_NRST_RSTF_POS             (26U)                                      
#define RCC_CSR2_NRST_RSTF_MASK            (0x1UL << RCC_CSR2_NRST_RSTF_POS)           /**< 0x04000000 */
#define RCC_CSR2_NRST_RSTF                 RCC_CSR2_NRST_RSTF_MASK                     /**< NRST pin reset flag */ 
#define RCC_CSR2_PMU_RSTF_POS              (27U)                                      
#define RCC_CSR2_PMU_RSTF_MASK             (0x1UL << RCC_CSR2_PMU_RSTF_POS)            /**< 0x08000000 */
#define RCC_CSR2_PMU_RSTF                  RCC_CSR2_PMU_RSTF_MASK                      /**< POR or BOR reset flag */
#define RCC_CSR2_SW_RSTF_POS               (28U)                                      
#define RCC_CSR2_SW_RSTF_MASK              (0x1UL << RCC_CSR2_SW_RSTF_POS)             /**< 0x10000000 */
#define RCC_CSR2_SW_RSTF                   RCC_CSR2_SW_RSTF_MASK                       /**< Software reset flag */ 
#define RCC_CSR2_IWDG_RSTF_POS             (29U)                                      
#define RCC_CSR2_IWDG_RSTF_MASK            (0x1UL << RCC_CSR2_IWDG_RSTF_POS)           /**< 0x20000000 */
#define RCC_CSR2_IWDG_RSTF                 RCC_CSR2_IWDG_RSTF_MASK                     /**< IWDG  reset flag */
#define RCC_CSR2_WWDG_RSTF_POS             (30U)                                      
#define RCC_CSR2_WWDG_RSTF_MASK            (0x1UL << RCC_CSR2_WWDG_RSTF_POS)           /**< 0x40000000 */
#define RCC_CSR2_WWDG_RSTF                 RCC_CSR2_WWDG_RSTF_MASK                     /**< WWDG  reset flag */
#define RCC_CSR2_LPM_RSTF_POS              (31U)                                      
#define RCC_CSR2_LPM_RSTF_MASK             (0x1UL << RCC_CSR2_LPM_RSTF_POS)            /**< 0x80000000 */
#define RCC_CSR2_LPM_RSTF                  RCC_CSR2_LPM_RSTF_MASK                      /**< Low power mode reset flag  */

/* Bits for RCC_RCL_CAL */
#define RCC_RCLCAL_RCL_CAL_POS             (0U)
#define RCC_RCLCAL_RCL_CAL_MASK            (0x1FUL << RCC_RCLCAL_RCL_CAL_POS)          /**< 0x0000001F */
#define RCC_RCLCAL_RCL_CAL                 RCC_RCLCAL_RCL_CAL_MASK  

/* Bits for RCC_RCH_CAL */
#define RCC_RCHCAL_RCH_CAL_POS             (0U)
#define RCC_RCHCAL_RCH_CAL_MASK            (0x7FUL << RCC_RCHCAL_RCH_CAL_POS)          /**< 0x0000007F */
#define RCC_RCHCAL_RCH_CAL                 RCC_RCHCAL_RCH_CAL_MASK  

/* Bits for RCC_VRBUFCAL */
#define RCC_VRBUFCAL_VRBUF_CAL_POS         (0U)
#define RCC_VRBUFCAL_VRBUF_CAL_MASK        (0x7FUL << RCC_VRBUFCAL_VRBUF_CAL_POS)      /**< 0x0000007F */
#define RCC_VRBUFCAL_VRBUF_CAL             RCC_VRBUFCAL_VRBUF_CAL_MASK


/*-----------------------------------------------------------------------------------------------
                                       RTC Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for RTC_TR */
#define RTC_TR_SU_POS                (0U)
#define RTC_TR_SU_MASK               (0xFUL << RTC_TR_SU_POS)                   /**< 0x0000000F */
#define RTC_TR_SU                    RTC_TR_SU_MASK
#define RTC_TR_ST_POS                (4U)
#define RTC_TR_ST_MASK               (0x7UL << RTC_TR_ST_POS)                   /**< 0x00000070 */
#define RTC_TR_ST                    RTC_TR_ST_MASK
#define RTC_TR_MNU_POS               (8U)
#define RTC_TR_MNU_MASK              (0xFUL << RTC_TR_MNU_POS)                  /**< 0x00000F00 */
#define RTC_TR_MNU                   RTC_TR_MNU_MASK
#define RTC_TR_MNT_POS               (12U)
#define RTC_TR_MNT_MASK              (0x7UL << RTC_TR_MNT_POS)                  /**< 0x00007000 */
#define RTC_TR_MNT                   RTC_TR_MNT_MASK
#define RTC_TR_HU_POS                (16U)
#define RTC_TR_HU_MASK               (0xFUL << RTC_TR_HU_POS)                   /**< 0x000F0000 */
#define RTC_TR_HU                    RTC_TR_HU_MASK
#define RTC_TR_HT_POS                (20U)
#define RTC_TR_HT_MASK               (0x3UL << RTC_TR_HT_POS)                   /**< 0x00300000 */
#define RTC_TR_HT                    RTC_TR_HT_MASK

/* Bits for RTC_DR */
#define RTC_DR_DU_POS                (0U)
#define RTC_DR_DU_MASK               (0xFUL << RTC_DR_DU_POS)                   /**< 0x0000000F */
#define RTC_DR_DU                    RTC_DR_DU_MASK
#define RTC_DR_DT_POS                (4U)
#define RTC_DR_DT_MASK               (0x3UL << RTC_DR_DT_POS)                   /**< 0x00000030 */
#define RTC_DR_DT                    RTC_DR_DT_MASK
#define RTC_DR_MU_POS                (8U)
#define RTC_DR_MU_MASK               (0xFUL << RTC_DR_MU_POS)                   /**< 0x00000F00 */
#define RTC_DR_MU                    RTC_DR_MU_MASK
#define RTC_DR_MT_POS                (12U)
#define RTC_DR_MT_MASK               (0x1UL << RTC_DR_MT_POS)                   /**< 0x00001000 */
#define RTC_DR_MT                    RTC_DR_MT_MASK
#define RTC_DR_WDU_POS               (13U)
#define RTC_DR_WDU_MASK              (0x7UL << RTC_DR_WDU_POS)                  /**< 0x0000E000 */
#define RTC_DR_WDU                   RTC_DR_WDU_MASK
#define RTC_DR_YU_POS                (16U)
#define RTC_DR_YU_MASK               (0xFUL << RTC_DR_YU_POS)                   /**< 0x000F0000 */
#define RTC_DR_YU                    RTC_DR_YU_MASK
#define RTC_DR_YT_POS                (20U)
#define RTC_DR_YT_MASK               (0xFUL << RTC_DR_YT_POS)                   /**< 0x00F00000 */
#define RTC_DR_YT                    RTC_DR_YT_MASK

/* Bits for RTC_SSR */
#define RTC_SSR_SS_POS               (0U)
#define RTC_SSR_SS_MASK              (0xFFUL << RTC_SSR_SS_POS)                 /**< 0x000000FF */
#define RTC_SSR_SS                   RTC_SSR_SS_MASK

/* Bits for RTC_CSR */
#define RTC_CSR_MODSTA_POS           (6U)
#define RTC_CSR_MODSTA_MASK          (0x1UL << RTC_CSR_MODSTA_POS)              /**< 0x00000040 */
#define RTC_CSR_MODSTA               RTC_CSR_MODSTA_MASK
#define RTC_CSR_MODSEL_POS           (7U)
#define RTC_CSR_MODSEL_MASK          (0x1UL << RTC_CSR_MODSEL_POS)              /**< 0x00000080 */
#define RTC_CSR_MODSEL               RTC_CSR_MODSEL_MASK
#define RTC_CSR_CALSTA_POS           (16U)
#define RTC_CSR_CALSTA_MASK          (0x1UL << RTC_CSR_CALSTA_POS)              /**< 0x00010000 */
#define RTC_CSR_CALSTA               RTC_CSR_CALSTA_MASK

/* Bits for RTC_WUT */
#define RTC_WUT_DAYIE_POS            (0U)
#define RTC_WUT_DAYIE_MASK           (0x1UL << RTC_WUT_DAYIE_POS)               /**< 0x00000001 */
#define RTC_WUT_DAYIE                RTC_WUT_DAYIE_MASK                       
#define RTC_WUT_HOURIE_POS           (1U)
#define RTC_WUT_HOURIE_MASK          (0x1UL << RTC_WUT_HOURIE_POS)              /**< 0x00000002 */
#define RTC_WUT_HOURIE               RTC_WUT_HOURIE_MASK                       
#define RTC_WUT_MINIE_POS            (2U)
#define RTC_WUT_MINIE_MASK           (0x1UL << RTC_WUT_MINIE_POS)               /**< 0x00000004 */
#define RTC_WUT_MINIE                RTC_WUT_MINIE_MASK                       
#define RTC_WUT_SECIE_POS            (3U)
#define RTC_WUT_SECIE_MASK           (0x1UL << RTC_WUT_SECIE_POS)               /**< 0x00000008 */
#define RTC_WUT_SECIE                RTC_WUT_SECIE_MASK                       
#define RTC_WUT_2HZIE_POS            (4U)
#define RTC_WUT_2HZIE_MASK           (0x1UL << RTC_WUT_2HZIE_POS)               /**< 0x00000010 */
#define RTC_WUT_2HZIE                RTC_WUT_2HZIE_MASK                       
#define RTC_WUT_4HZIE_POS            (5U)
#define RTC_WUT_4HZIE_MASK           (0x1UL << RTC_WUT_4HZIE_POS)               /**< 0x00000020 */
#define RTC_WUT_4HZIE                RTC_WUT_4HZIE_MASK                       
#define RTC_WUT_8HZIE_POS            (6U)
#define RTC_WUT_8HZIE_MASK           (0x1UL << RTC_WUT_8HZIE_POS)               /**< 0x00000040 */
#define RTC_WUT_8HZIE                RTC_WUT_8HZIE_MASK                       
#define RTC_WUT_16HZIE_POS           (7U)
#define RTC_WUT_16HZIE_MASK          (0x1UL << RTC_WUT_16HZIE_POS)              /**< 0x00000080 */
#define RTC_WUT_16HZIE               RTC_WUT_16HZIE_MASK                       
#define RTC_WUT_64HZIE_POS           (8U)
#define RTC_WUT_64HZIE_MASK          (0x1UL << RTC_WUT_64HZIE_POS)              /**< 0x00000100 */
#define RTC_WUT_64HZIE               RTC_WUT_64HZIE_MASK                       
#define RTC_WUT_256HZIE_POS          (9U)
#define RTC_WUT_256HZIE_MASK         (0x1UL << RTC_WUT_256HZIE_POS)             /**< 0x00000200 */
#define RTC_WUT_256HZIE              RTC_WUT_256HZIE_MASK                       
#define RTC_WUT_1024HZIE_POS         (10U)
#define RTC_WUT_1024HZIE_MASK        (0x1UL << RTC_WUT_1024HZIE_POS)            /**< 0x00000400 */
#define RTC_WUT_1024HZIE             RTC_WUT_1024HZIE_MASK                       

/* Bits for RTC_CR */
#define RTC_CR_ALARME_POS            (8U)
#define RTC_CR_ALARME_MASK           (0x1UL << RTC_CR_ALARME_POS)               /**< 0x00000100 */
#define RTC_CR_ALARME                RTC_CR_ALARME_MASK
#define RTC_CR_ALARMIE_POS           (12U)
#define RTC_CR_ALARMIE_MASK          (0x1UL << RTC_CR_ALARMIE_POS)              /**< 0x00001000 */
#define RTC_CR_ALARMIE               RTC_CR_ALARMIE_MASK
#define RTC_CR_CALIE_POS             (13U)
#define RTC_CR_CALIE_MASK            (0x1UL << RTC_CR_CALIE_POS)                /**< 0x00002000 */
#define RTC_CR_CALIE                 RTC_CR_CALIE_MASK    
#define RTC_CR_OUTEN_POS             (19U)
#define RTC_CR_OUTEN_MASK            (0x1UL << RTC_CR_OUTEN_POS)                /**< 0x00080000 */
#define RTC_CR_OUTEN                 RTC_CR_OUTEN_MASK
#define RTC_CR_POL_POS               (20U)
#define RTC_CR_POL_MASK              (0x1UL << RTC_CR_POL_POS)                  /**< 0x00100000 */
#define RTC_CR_POL                   RTC_CR_POL_MASK
#define RTC_CR_OUT_SEL_POS           (21U)
#define RTC_CR_OUT_SEL_MASK          (0x7UL << RTC_CR_OUT_SEL_POS)              /**< 0x00E00000 */
#define RTC_CR_OUT_SEL               RTC_CR_OUT_SEL_MASK
#define RTC_CR_OUT_SEL_APRE          (0x0UL << RTC_CR_OUT_SEL_POS)              /**< 0x00000000 */
#define RTC_CR_OUT_SEL_SPRE          (0x1UL << RTC_CR_OUT_SEL_POS)              /**< 0x00200000 */
#define RTC_CR_OUT_SEL_ALARMF        (0x2UL << RTC_CR_OUT_SEL_POS)              /**< 0x00400000 */
#define RTC_CR_OUT_SEL_MIN           (0x4UL << RTC_CR_OUT_SEL_POS)              /**< 0x00800000 */
#define RTC_CR_OUT_SEL_HOUR          (0x5UL << RTC_CR_OUT_SEL_POS)              /**< 0x00A00000 */
#define RTC_CR_OUT_SEL_DAY           (0x6UL << RTC_CR_OUT_SEL_POS)              /**< 0x00C00000 */
#define RTC_CR_OUT_SEL_CAL           (0x7UL << RTC_CR_OUT_SEL_POS)              /**< 0x00E00000 */
            
/* Bits for RTC_WPR */
#define RTC_WPR_KEY_POS              (0U)
#define RTC_WPR_KEY_MASK             (0xFFUL << RTC_WPR_KEY_POS)                /**< 0x000000FF */
#define RTC_WPR_KEY                  RTC_WPR_KEY_MASK

/* Bits for RTC_CALR */
#define RTC_CALR_CALM_POS            (0U)
#define RTC_CALR_CALM_MASK           (0x1FFUL << RTC_CALR_CALM_POS)             /**< 0x000001FF */
#define RTC_CALR_CALM                RTC_CALR_CALM_MASK
#define RTC_CALR_CALP_POS            (15U)
#define RTC_CALR_CALP_MASK           (0x1UL << RTC_CALR_CALP_POS)               /**< 0x00008000 */
#define RTC_CALR_CALP                RTC_CALR_CALP_MASK

/* Bits for RTC_TSTR */
#define RTC_TSTR_SU_POS              (0U)
#define RTC_TSTR_SU_MASK             (0xFUL << RTC_TSTR_SU_POS)                 /**< 0x0000000F */
#define RTC_TSTR_SU                  RTC_TSTR_SU_MASK
#define RTC_TSTR_ST_POS              (4U)
#define RTC_TSTR_ST_MASK             (0x7UL << RTC_TSTR_ST_POS)                 /**< 0x00000070 */
#define RTC_TSTR_ST                  RTC_TSTR_ST_MASK
#define RTC_TSTR_MNU_POS             (8U)
#define RTC_TSTR_MNU_MASK            (0xFUL << RTC_TSTR_MNU_POS)                /**< 0x00000F00 */
#define RTC_TSTR_MNU                 RTC_TSTR_MNU_MASK
#define RTC_TSTR_MNT_POS             (12U)
#define RTC_TSTR_MNT_MASK            (0x7UL << RTC_TSTR_MNT_POS)                /**< 0x00007000 */
#define RTC_TSTR_MNT                 RTC_TSTR_MNT_MASK 
#define RTC_TSTR_HU_POS              (16U)
#define RTC_TSTR_HU_MASK             (0xFUL << RTC_TSTR_HU_POS)                 /**< 0x000F0000 */
#define RTC_TSTR_HU                  RTC_TSTR_HU_MASK
#define RTC_TSTR_HT_POS              (20U)
#define RTC_TSTR_HT_MASK             (0x3UL << RTC_TSTR_HT_POS)                 /**< 0x00300000 */
#define RTC_TSTR_HT                  RTC_TSTR_HT_MASK

/* Bits for RTC_TSDR */
#define RTC_TSDR_DU_POS              (0U)
#define RTC_TSDR_DU_MASK             (0xFUL << RTC_TSDR_DU_POS)                 /**< 0x0000000F */
#define RTC_TSDR_DU                  RTC_TSDR_DU_MASK
#define RTC_TSDR_DT_POS              (4U)
#define RTC_TSDR_DT_MASK             (0x3UL << RTC_TSDR_DT_POS)                 /**< 0x00000030 */
#define RTC_TSDR_DT                  RTC_TSDR_DT_MASK 
#define RTC_TSDR_MU_POS              (8U)
#define RTC_TSDR_MU_MASK             (0xFUL << RTC_TSDR_MU_POS)                 /**< 0x00000F00 */
#define RTC_TSDR_MU                  RTC_TSDR_MU_MASK 
#define RTC_TSDR_MT_POS              (12U)
#define RTC_TSDR_MT_MASK             (0x1UL << RTC_TSDR_MT_POS)                 /**< 0x00001000 */
#define RTC_TSDR_MT                  RTC_TSDR_MT_MASK

/* Bits for RTC_ALARMR */
#define RTC_ALARMR_SU_POS            (0U)
#define RTC_ALARMR_SU_MASK           (0xFUL << RTC_ALARMR_SU_POS)               /**< 0x0000000F */
#define RTC_ALARMR_SU                RTC_ALARMR_SU_MASK 
#define RTC_ALARMR_ST_POS            (4U)
#define RTC_ALARMR_ST_MASK           (0x7UL << RTC_ALARMR_ST_POS)               /**< 0x00000070 */
#define RTC_ALARMR_ST                RTC_ALARMR_ST_MASK
#define RTC_ALARMR_MSK1_POS          (7U)
#define RTC_ALARMR_MSK1_MASK         (0x1UL << RTC_ALARMR_MSK1_POS)             /**< 0x00000080 */
#define RTC_ALARMR_MSK1              RTC_ALARMR_MSK1_MASK
#define RTC_ALARMR_MNU_POS           (8U)
#define RTC_ALARMR_MNU_MASK          (0xFUL << RTC_ALARMR_MNU_POS)              /**< 0x00000F00 */
#define RTC_ALARMR_MNU               RTC_ALARMR_MNU_MASK 
#define RTC_ALARMR_MNT_POS           (12U)
#define RTC_ALARMR_MNT_MASK          (0x7UL << RTC_ALARMR_MNT_POS)              /**< 0x00007000 */
#define RTC_ALARMR_MNT               RTC_ALARMR_MNT_MASK
#define RTC_ALARMR_MSK2_POS          (15U)
#define RTC_ALARMR_MSK2_MASK         (0x1UL << RTC_ALARMR_MSK2_POS)             /**< 0x00008000 */
#define RTC_ALARMR_MSK2              RTC_ALARMR_MSK2_MASK
#define RTC_ALARMR_HU_POS            (16U)
#define RTC_ALARMR_HU_MASK           (0xFUL << RTC_ALARMR_HU_POS)               /**< 0x000F0000 */
#define RTC_ALARMR_HU                RTC_ALARMR_HU_MASK
#define RTC_ALARMR_HT_POS            (20U)
#define RTC_ALARMR_HT_MASK           (0x3UL << RTC_ALARMR_HT_POS)               /**< 0x00300000 */
#define RTC_ALARMR_HT                RTC_ALARMR_HT_MASK
#define RTC_ALARMR_MSK3_POS          (23U)
#define RTC_ALARMR_MSK3_MASK         (0x1UL << RTC_ALARMR_MSK3_POS)             /**< 0x00800000 */
#define RTC_ALARMR_MSK3              RTC_ALARMR_MSK3_MASK
#define RTC_ALARMR_MSKALL            (RTC_ALARMR_MSK1  | RTC_ALARMR_MSK2 \
                                                       | RTC_ALARMR_MSK3)       /**< 0x00808080 */

/* Bits for RTC_SR */
#define RTC_SR_ALARMF_POS            (0U)
#define RTC_SR_ALARMF_MASK           (0x1UL << RTC_SR_ALARMF_POS)               /**< 0x00000001 */
#define RTC_SR_ALARMF                RTC_SR_ALARMF_MASK
#define RTC_SR_CALF_POS              (1U)
#define RTC_SR_CALF_MASK             (0x1UL << RTC_SR_CALF_POS)                 /**< 0x00000002 */
#define RTC_SR_CALF                  RTC_SR_CALF_MASK   
#define RTC_SR_TSF_POS               (3U)
#define RTC_SR_TSF_MASK              (0x1UL << RTC_SR_TSF_POS)                  /**< 0x00000008 */
#define RTC_SR_TSF                   RTC_SR_TSF_MASK   
#define RTC_SR_DAYF_POS              (16U)
#define RTC_SR_DAYF_MASK             (0x1UL << RTC_SR_DAYF_POS)                 /**< 0x00010000 */
#define RTC_SR_DAYF                  RTC_SR_DAYF_MASK                       
#define RTC_SR_HOURF_POS             (17U)
#define RTC_SR_HOURF_MASK            (0x1UL << RTC_SR_HOURF_POS)                /**< 0x00020000 */
#define RTC_SR_HOURF                 RTC_SR_HOURF_MASK                       
#define RTC_SR_MINF_POS              (18U)
#define RTC_SR_MINF_MASK             (0x1UL << RTC_SR_MINF_POS)                 /**< 0x00040000 */
#define RTC_SR_MINF                  RTC_SR_MINF_MASK                       
#define RTC_SR_SECF_POS              (19U)
#define RTC_SR_SECF_MASK             (0x1UL << RTC_SR_SECF_POS)                 /**< 0x00080000 */
#define RTC_SR_SECF                  RTC_SR_SECF_MASK                       
#define RTC_SR_2HZF_POS              (20U)
#define RTC_SR_2HZF_MASK             (0x1UL << RTC_SR_2HZF_POS)                 /**< 0x00100000 */
#define RTC_SR_2HZF                  RTC_SR_2HZF_MASK                       
#define RTC_SR_4HZF_POS              (21U)
#define RTC_SR_4HZF_MASK             (0x1UL << RTC_SR_4HZF_POS)                 /**< 0x00200000 */
#define RTC_SR_4HZF                  RTC_SR_4HZF_MASK                       
#define RTC_SR_8HZF_POS              (22U)
#define RTC_SR_8HZF_MASK             (0x1UL << RTC_SR_8HZF_POS)                 /**< 0x00400000 */
#define RTC_SR_8HZF                  RTC_SR_8HZF_MASK                       
#define RTC_SR_16HZF_POS             (23U)
#define RTC_SR_16HZF_MASK            (0x1UL << RTC_SR_16HZF_POS)                /**< 0x00800000 */
#define RTC_SR_16HZF                 RTC_SR_16HZF_MASK                       
#define RTC_SR_64HZF_POS             (24U)
#define RTC_SR_64HZF_MASK            (0x1UL << RTC_SR_64HZF_POS)                /**< 0x01000000 */
#define RTC_SR_64HZF                 RTC_SR_64HZF_MASK                       
#define RTC_SR_256HZF_POS            (25U)
#define RTC_SR_256HZF_MASK           (0x1UL << RTC_SR_256HZF_POS)               /**< 0x02000000 */
#define RTC_SR_256HZF                RTC_SR_256HZF_MASK                       
#define RTC_SR_1024HZF_POS           (26U)
#define RTC_SR_1024HZF_MASK          (0x1UL << RTC_SR_1024HZF_POS)              /**< 0x04000000 */
#define RTC_SR_1024HZF               RTC_SR_1024HZF_MASK                       
                      
/* Bits for RTC_ISR */
#define RTC_ISR_ALARMIF_POS          (0U)
#define RTC_ISR_ALARMIF_MASK         (0x1UL << RTC_ISR_ALARMIF_POS)             /**< 0x00000001 */
#define RTC_ISR_ALARMIF              RTC_ISR_ALARMIF_MASK
#define RTC_ISR_CALIF_POS            (1U)
#define RTC_ISR_CALIF_MASK           (0x1UL << RTC_ISR_CALIF_POS)               /**< 0x00000002 */
#define RTC_ISR_CALIIF               RTC_ISR_CALIF_MASK   
#define RTC_ISR_DAYIF_POS            (16U)
#define RTC_ISR_DAYIF_MASK           (0x1UL << RTC_ISR_DAYIF_POS)               /**< 0x00010000 */
#define RTC_ISR_DAYIF                RTC_ISR_DAYIF_MASK                       
#define RTC_ISR_HOURIF_POS           (17U)
#define RTC_ISR_HOURIF_MASK          (0x1UL << RTC_ISR_HOURIF_POS)              /**< 0x00020000 */
#define RTC_ISR_HOURIF               RTC_ISR_HOURIF_MASK                       
#define RTC_ISR_MINIF_POS            (18U)
#define RTC_ISR_MINIF_MASK           (0x1UL << RTC_ISR_MINIF_POS)               /**< 0x00040000 */
#define RTC_ISR_MINIF                RTC_ISR_MINIF_MASK                       
#define RTC_ISR_SECIF_POS            (19U)
#define RTC_ISR_SECIF_MASK           (0x1UL << RTC_ISR_SECIF_POS)               /**< 0x00080000 */
#define RTC_ISR_SECIF                RTC_ISR_SECIF_MASK                       
#define RTC_ISR_2HZIF_POS            (20U)
#define RTC_ISR_2HZIF_MASK           (0x1UL << RTC_ISR_2HZIF_POS)               /**< 0x00100000 */
#define RTC_ISR_2HZIF                RTC_ISR_2HZIF_MASK                       
#define RTC_ISR_4HZIF_POS            (21U)
#define RTC_ISR_4HZIF_MASK           (0x1UL << RTC_ISR_4HZIF_POS)               /**< 0x00200000 */
#define RTC_ISR_4HZIF                RTC_ISR_4HZIF_MASK                       
#define RTC_ISR_8HZIF_POS            (22U)
#define RTC_ISR_8HZIF_MASK           (0x1UL << RTC_ISR_8HZIF_POS)               /**< 0x00400000 */
#define RTC_ISR_8HZIF                RTC_ISR_8HZIF_MASK                       
#define RTC_ISR_16HZIF_POS           (23U)
#define RTC_ISR_16HZIF_MASK          (0x1UL << RTC_ISR_16HZIF_POS)              /**< 0x00800000 */
#define RTC_ISR_16HZIF               RTC_ISR_16HZIF_MASK                       
#define RTC_ISR_64HZIF_POS           (24U)
#define RTC_ISR_64HZIF_MASK          (0x1UL << RTC_ISR_64HZIF_POS)              /**< 0x01000000 */
#define RTC_ISR_64HZIF               RTC_ISR_64HZIF_MASK                       
#define RTC_ISR_256HZIF_POS          (25U)
#define RTC_ISR_256HZIF_MASK         (0x1UL << RTC_ISR_256HZIF_POS)             /**< 0x02000000 */
#define RTC_ISR_256HZIF              RTC_ISR_256HZIF_MASK                       
#define RTC_ISR_1024HZIF_POS         (26U)
#define RTC_ISR_1024HZIF_MASK        (0x1UL << RTC_ISR_1024HZIF_POS)            /**< 0x04000000 */
#define RTC_ISR_1024HZIF             RTC_ISR_1024HZIF_MASK                       
                     
/* Bits for RTC_CLR */
#define RTC_CLR_CALARMF_POS          (0U)
#define RTC_CLR_CALARMF_MASK         (0x1UL << RTC_CLR_CALARMF_POS)             /**< 0x00000001 */
#define RTC_CLR_CALARMF              RTC_CLR_CALARMF_MASK
#define RTC_CLR_CCALF_POS            (1U)
#define RTC_CLR_CCALF_MASK           (0x1UL << RTC_CLR_CCALF_POS)               /**< 0x00000002 */
#define RTC_CLR_CCALF                RTC_CLR_CCALF_MASK
#define RTC_CLR_CTSF_POS             (3U)
#define RTC_CLR_CTSF_MASK            (0x1UL << RTC_CLR_CTSF_POS)                /**< 0x00000008 */
#define RTC_CLR_CTSF                 RTC_CLR_CTSF_MASK    
#define RTC_CLR_CDAYF_POS            (16U)
#define RTC_CLR_CDAYF_MASK           (0x1UL << RTC_CLR_CDAYF_POS)                /**< 0x00010000 */
#define RTC_CLR_CDAYF                RTC_CLR_CDAYF_MASK                       
#define RTC_CLR_CHOURF_POS           (17U)
#define RTC_CLR_CHOURF_MASK          (0x1UL << RTC_CLR_CHOURF_POS)               /**< 0x00020000 */
#define RTC_CLR_CHOURF               RTC_CLR_CHOURF_MASK                       
#define RTC_CLR_CMINF_POS            (18U)
#define RTC_CLR_CMINF_MASK           (0x1UL << RTC_CLR_CMINF_POS)                /**< 0x00040000 */
#define RTC_CLR_CMINF                RTC_CLR_CMINF_MASK                       
#define RTC_CLR_CSECF_POS            (19U)
#define RTC_CLR_CSECF_MASK           (0x1UL << RTC_CLR_CSECF_POS)                /**< 0x00080000 */
#define RTC_CLR_CSECF                RTC_CLR_CSECF_MASK                       
#define RTC_CLR_C2HZF_POS            (20U)
#define RTC_CLR_C2HZF_MASK           (0x1UL << RTC_CLR_C2HZF_POS)                /**< 0x00100000 */
#define RTC_CLR_C2HZF                RTC_CLR_C2HZF_MASK                       
#define RTC_CLR_C4HZF_POS            (21U)
#define RTC_CLR_C4HZF_MASK           (0x1UL << RTC_CLR_C4HZF_POS)                /**< 0x00200000 */
#define RTC_CLR_C4HZF                RTC_CLR_C4HZF_MASK                       
#define RTC_CLR_C8HZF_POS            (22U)
#define RTC_CLR_C8HZF_MASK           (0x1UL << RTC_CLR_C8HZF_POS)                /**< 0x00400000 */
#define RTC_CLR_C8HZF                RTC_CLR_C8HZF_MASK                       
#define RTC_CLR_C16HZF_POS           (23U)
#define RTC_CLR_C16HZF_MASK          (0x1UL << RTC_CLR_C16HZF_POS)               /**< 0x00800000 */
#define RTC_CLR_C16HZF               RTC_CLR_C16HZF_MASK                       
#define RTC_CLR_C64HZF_POS           (24U)
#define RTC_CLR_C64HZF_MASK          (0x1UL << RTC_CLR_C64HZF_POS)               /**< 0x01000000 */
#define RTC_CLR_C64HZF               RTC_CLR_C64HZF_MASK                       
#define RTC_CLR_C256HZF_POS          (25U)
#define RTC_CLR_C256HZF_MASK         (0x1UL << RTC_CLR_C256HZF_POS)              /**< 0x02000000 */
#define RTC_CLR_C256HZF              RTC_CLR_C256HZF_MASK                       
#define RTC_CLR_C1024HZF_POS         (26U)
#define RTC_CLR_C1024HZF_MASK        (0x1UL << RTC_CLR_C1024HZF_POS)             /**< 0x04000000 */
#define RTC_CLR_C1024HZF             RTC_CLR_C1024HZF_MASK                       


/*-----------------------------------------------------------------------------------------------
                                       SM4 Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for  SM4_DR */
#define SM4_DR_POS                     (0U)
#define SM4_DR_MASK                    (0xFFFFFFFFUL << SM4_DR_POS)             /**< 0xFFFFFFFF */
#define SM4_DR                         SM4_DR_MASK                              /**< SM4 data register */

/* Bits for  SM4_RDR */
#define SM4_RDR_POS                     (0U)
#define SM4_RDR_MASK                    (0xFFFFFFFFUL << SM4_RDR_POS)           /**< 0xFFFFFFFF */
#define SM4_RDR                         SM4_RDR_MASK                            /**< SM4 result register */

/*-----------------------------------------------------------------------------------------------
                                       SPI Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for SPI_CR1 */
#define SPI_CR1_SPE_POS                (0U)
#define SPI_CR1_SPE_MASK               (0x1UL << SPI_CR1_SPE_POS)                 /**< 0x00000001 */
#define SPI_CR1_SPE                    SPI_CR1_SPE_MASK                           /**< SPI enable */

#define SPI_CR1_BR_POS                 (1U)
#define SPI_CR1_BR_MASK                (0x7UL << SPI_CR1_BR_POS)                  /**< 0x0000000E */
#define SPI_CR1_BR                     SPI_CR1_BR_MASK                            /**< BR[2:0] bits (baud rate control) */
#define SPI_CR1_BR_PCLK_DIV_2          (0x0UL << SPI_CR1_BR_POS)                  /**< 0x00000000 */
#define SPI_CR1_BR_PCLK_DIV_4          (0x1UL << SPI_CR1_BR_POS)                  /**< 0x00000002 */
#define SPI_CR1_BR_PCLK_DIV_8          (0x2UL << SPI_CR1_BR_POS)                  /**< 0x00000004 */
#define SPI_CR1_BR_PCLK_DIV_16         (0x3UL << SPI_CR1_BR_POS)                  /**< 0x00000006 */
#define SPI_CR1_BR_PCLK_DIV_32         (0x4UL << SPI_CR1_BR_POS)                  /**< 0x00000008 */
#define SPI_CR1_BR_PCLK_DIV_64         (0x5UL << SPI_CR1_BR_POS)                  /**< 0x0000000A */
#define SPI_CR1_BR_PCLK_DIV_128        (0x6UL << SPI_CR1_BR_POS)                  /**< 0x0000000C */

#define SPI_CR1_CPHA_POS               (4U)
#define SPI_CR1_CPHA_MASK              (0x1UL << SPI_CR1_CPHA_POS)                /**< 0x00000010 */
#define SPI_CR1_CPHA                   SPI_CR1_CPHA_MASK                          /**< Clock phase */

#define SPI_CR1_CPOL_POS               (5U)
#define SPI_CR1_CPOL_MASK              (0x1UL << SPI_CR1_CPOL_POS)                /**< 0x00000020 */
#define SPI_CR1_CPOL                   SPI_CR1_CPOL_MASK                          /**< Clock polarity */

#define SPI_CR1_MSTR_POS               (6U)
#define SPI_CR1_MSTR_MASK              (0x1UL << SPI_CR1_MSTR_POS)                /**< 0x00000040 */
#define SPI_CR1_MSTR                   SPI_CR1_MSTR_MASK                          /**< Master mode selection */

#define SPI_CR1_LSBFIRST_POS           (8U)
#define SPI_CR1_LSBFIRST_MASK          (0x1UL << SPI_CR1_LSBFIRST_POS)            /**< 0x00000100 */
#define SPI_CR1_LSBFIRST               SPI_CR1_LSBFIRST_MASK                      /**< Frame format   */

#define SPI_CR1_NSSOE_POS              (10U)
#define SPI_CR1_NSSOE_MASK             (0x1UL << SPI_CR1_NSSOE_POS)               /**< 0x00000400 */
#define SPI_CR1_NSSOE                  SPI_CR1_NSSOE_MASK                         /**< NSS out enable */

#define SPI_CR1_SSM_POS                (11U)
#define SPI_CR1_SSM_MASK               (0x1UL << SPI_CR1_SSM_POS)                 /**< 0x00000800 */
#define SPI_CR1_SSM                    SPI_CR1_SSM_MASK                           /**< Slave Software NSS */

#define SPI_CR1_DMAR_POS               (16U)
#define SPI_CR1_DMAR_MASK              (0x1UL << SPI_CR1_DMAR_POS)                /**< 0x00010000 */
#define SPI_CR1_DMAR                   SPI_CR1_DMAR_MASK                          /**< RX DMA request */

#define SPI_CR1_DMAT_POS               (17U)
#define SPI_CR1_DMAT_MASK              (0x1UL << SPI_CR1_DMAT_POS)                /**< 0x00020000 */
#define SPI_CR1_DMAT                   SPI_CR1_DMAT_MASK                          /**< TX DMA request */

#define SPI_CR1_ERRIE_POS              (18U)
#define SPI_CR1_ERRIE_MASK             (0x1UL << SPI_CR1_ERRIE_POS)               /**< 0x00040000 */
#define SPI_CR1_ERRIE                  SPI_CR1_ERRIE_MASK                         /**< Error interrupt enable */

#define SPI_CR1_RXFNEIE_POS            (20U)
#define SPI_CR1_RXFNEIE_MASK           (0x1UL << SPI_CR1_RXFNEIE_POS)             /**< 0x00100000 */
#define SPI_CR1_RXFNEIE                SPI_CR1_RXFNEIE_MASK                       /**< RX data register not empty interrupt enable */

#define SPI_CR1_TXFEIE_POS             (25U)
#define SPI_CR1_TXFEIE_MASK            (0x1UL << SPI_CR1_TXFEIE_POS)              /**< 0x02000000 */
#define SPI_CR1_TXFEIE                 SPI_CR1_TXFEIE_MASK                        /**< TX data register empty interrupt enable */

/* Bits for SPI_CR2 */
#define SPI_CR2_NSSO_POS               (0U)
#define SPI_CR2_NSSO_MASK              (0x1UL << SPI_CR2_NSSO_POS)                /**< 0x00000001 */
#define SPI_CR2_NSSO                   SPI_CR2_NSSO_MASK                          /**< NSS out level */

/* Bits for SPI_DATACLR */
#define SPI_DATACLR_RXCLR_POS          (0U)
#define SPI_DATACLR_RXCLR_MASK         (0x1UL << SPI_DATACLR_RXCLR_POS)           /**< 0x00000001 */
#define SPI_DATACLR_RXCLR              SPI_DATACLR_RXCLR_MASK                     /**< RX Data register clear */

#define SPI_DATACLR_TXCLR_POS          (1U)
#define SPI_DATACLR_TXCLR_MASK         (0x1UL << SPI_DATACLR_TXCLR_POS)           /**< 0x00000002 */
#define SPI_DATACLR_TXCLR              SPI_DATACLR_TXCLR_MASK                     /**< TX Data register clear */

/* Bits for SPI_ISR */
#define SPI_ISR_MMF_POS                (0U)
#define SPI_ISR_MMF_MASK               (0x1UL << SPI_ISR_MMF_POS)                 /**< 0x00000001 */
#define SPI_ISR_MMF                    SPI_ISR_MMF_MASK                           /**< Master mode confilct flag */

#define SPI_ISR_OVR_POS                (2U)
#define SPI_ISR_OVR_MASK               (0x1UL << SPI_ISR_OVR_POS)                 /**< 0x00000004 */
#define SPI_ISR_OVR                    SPI_ISR_OVR_MASK                           /**< RX FIFO overrun flag */

#define SPI_ISR_BUSY_POS               (4U)
#define SPI_ISR_BUSY_MASK              (0x1UL << SPI_ISR_BUSY_POS)                /**< 0x00000010 */
#define SPI_ISR_BUSY                   SPI_ISR_BUSY_MASK                          /**< Busy flag */

#define SPI_ISR_RXFNE_POS              (6U)
#define SPI_ISR_RXFNE_MASK             (0x1UL << SPI_ISR_RXFNE_POS)               /**< 0x00000040 */
#define SPI_ISR_RXFNE                  SPI_ISR_RXFNE_MASK                         /**< RX data register not empty flag */

#define SPI_ISR_TXFE_POS               (8U)
#define SPI_ISR_TXFE_MASK              (0x1UL << SPI_ISR_TXFE_POS)                /**< 0x00000100 */
#define SPI_ISR_TXFE                   SPI_ISR_TXFE_MASK                          /**< TX data register empty flag */

/* Bits for SPI_ICR */
#define SPI_ICR_MMFCF_POS              (0U)
#define SPI_ICR_MMFCF_MASK             (0x1UL << SPI_ICR_MMFCF_POS)               /**< 0x00000001 */
#define SPI_ICR_MMFCF                  SPI_ICR_MMFCF_MASK                         /**< Master mode confilct clear flag */

#define SPI_ICR_OVRCF_POS              (2U)
#define SPI_ICR_OVRCF_MASK             (0x1UL << SPI_ICR_OVRCF_POS)               /**< 0x00000004 */
#define SPI_ICR_OVRCF                  SPI_ICR_OVRCF_MASK                         /**< RX data register overrun clear flag */

/* Bits for SPI_DR */
#define SPI_DR_DR_POS                  (0U)
#define SPI_DR_DR_MASK                 (0xFFUL << SPI_DR_DR_POS)                  /**< 0x000000FF */
#define SPI_DR_DR                      SPI_DR_DR_MASK                             /**< 8 bits transmit or receive data */

/*-----------------------------------------------------------------------------------------------
                                       SYSCFG Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for SYSCFG_CR */
#define SYSCFG_CR_MEM_MODE_POS             (0U)
#define SYSCFG_CR_MEM_MODE_MASK            (0x3UL << SYSCFG_CR_MEM_MODE_POS)      /**< 0x00000003 */
#define SYSCFG_CR_MEM_MODE                 SYSCFG_CR_MEM_MODE_MASK                /**< SYSCFG memory remap config */

#define SYSCFG_CR_MEM_MODE_USER_FLASH      (0x0UL << SYSCFG_CR_MEM_MODE_POS)      /**< 0x00000000 */
#define SYSCFG_CR_MEM_MODE_SYS_MEM         (0x2UL << SYSCFG_CR_MEM_MODE_POS)      /**< 0x00000002 */
#define SYSCFG_CR_MEM_MODE_SRAM            (0x3UL << SYSCFG_CR_MEM_MODE_POS)      /**< 0x00000003 */

#define SYSCFG_CR_IR_POL_POS               (2U)
#define SYSCFG_CR_IR_POL_MASK              (0x1UL << SYSCFG_CR_IR_POL_POS)        /**< 0x00000004 */
#define SYSCFG_CR_IR_POL                   SYSCFG_CR_IR_POL_MASK                  /**< SYSCFG IRTIM out polarity config */

#define SYSCFG_CR_IR_MODE_POS              (3U)
#define SYSCFG_CR_IR_MODE_MASK             (0x3UL << SYSCFG_CR_IR_MODE_POS)       /**< 0x00000018 */
#define SYSCFG_CR_IR_MODE                  SYSCFG_CR_IR_MODE_MASK                 /**< SYSCFG IRTIM mode config */

#define SYSCFG_CR_IR_MODE_TIM5_OC1         (0x0UL << SYSCFG_CR_IR_MODE_POS)       /**< 0x00000000 */
#define SYSCFG_CR_IR_MODE_USART1_TX        (0x1UL << SYSCFG_CR_IR_MODE_POS)       /**< 0x00000008 */
#define SYSCFG_CR_IR_MODE_UART4_TX         (0x2UL << SYSCFG_CR_IR_MODE_POS)       /**< 0x00000010 */

#define SYSCFG_CR_6BIT_DAC_DIV_POS         (16U)
#define SYSCFG_CR_6BIT_DAC_DIV_MASK        (0x3FUL << SYSCFG_CR_6BIT_DAC_DIV_POS) /**< 0x003F0000 */
#define SYSCFG_CR_6BIT_DAC_DIV             SYSCFG_CR_6BIT_DAC_DIV_MASK            /**< SYSCFG 6bit DAC voltage config */

#define SYSCFG_CR_6BIT_DAC_EN_POS          (24U)
#define SYSCFG_CR_6BIT_DAC_EN_MASK         (0x1UL << SYSCFG_CR_6BIT_DAC_EN_POS)   /**< 0x01000000 */
#define SYSCFG_CR_6BIT_DAC_EN              SYSCFG_CR_6BIT_DAC_EN_MASK             /**< SYSCFG 6bit DAC enable config */

#define SYSCFG_CR_6BIT_DAC_REF_POS         (25U)
#define SYSCFG_CR_6BIT_DAC_REF_MASK        (0x1UL << SYSCFG_CR_6BIT_DAC_REF_POS)  /**< 0x02000000 */
#define SYSCFG_CR_6BIT_DAC_REF             SYSCFG_CR_6BIT_DAC_REF_MASK            /**< SYSCFG 6bit DAC reference voltage config */

/* Bits for SYSCFG_SECCR */
#define SYSCFG_SECCR_PVD_LOCK_POS          (5U)
#define SYSCFG_SECCR_PVD_LOCK_MASK         (0x1UL << SYSCFG_SECCR_PVD_LOCK_POS)   /**< 0x00000020 */
#define SYSCFG_SECCR_PVD_LOCK              SYSCFG_SECCR_PVD_LOCK_MASK             /**< Lock PVD config and enable PVD connection with TIM1_BKIN */

/*-----------------------------------------------------------------------------------------------
                                       TAMP Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for TAMP_ENR */
#define TAMP_ENR_TAMPEN_POS          (0U)
#define TAMP_ENR_TAMPEN_MASK         (0x1UL << TAMP_ENR_TAMPEN_POS)             /**< 0x00000001 */
#define TAMP_ENR_TAMPEN              TAMP_ENR_TAMPEN_MASK

/* Bits for TAMP_CR */
#define TAMP_CR_TAMPNOER_POS         (0U)
#define TAMP_CR_TAMPNOER_MASK        (0x1UL << TAMP_CR_TAMPNOER_POS)            /**< 0x00000001 */
#define TAMP_CR_TAMPNOER             TAMP_CR_TAMPNOER_MASK
#define TAMP_CR_TAMPTRIG_POS         (24U)
#define TAMP_CR_TAMPTRIG_MASK        (0x1UL << TAMP_CR_TAMPTRIG_POS)            /**< 0x01000000 */
#define TAMP_CR_TAMPTRIG             TAMP_CR_TAMPTRIG_MASK

/* Bits for TAMP_FLTCR */
#define TAMP_FLTCR_TAMPFLT_POS        (3U)
#define TAMP_FLTCR_TAMPFLT_MASK       (0x3UL << TAMP_FLTCR_TAMPFLT_POS)         /**< 0x00000018 */
#define TAMP_FLTCR_TAMPFLT            TAMP_FLTCR_TAMPFLT_MASK
#define TAMP_FLTCR_2SAMPLE            (0x1UL << TAMP_FLTCR_TAMPFLT_POS)         /**< 0x00000008 */
#define TAMP_FLTCR_4SAMPLE            (0x2UL << TAMP_FLTCR_TAMPFLT_POS)         /**< 0x00000010 */
#define TAMP_FLTCR_8SAMPLE            (0x3UL << TAMP_FLTCR_TAMPFLT_POS)         /**< 0x00000018 */
#define TAMP_FLTCR_TAMPPUEN_POS       (7U)
#define TAMP_FLTCR_TAMPPUEN_MASK      (0x1UL << TAMP_FLTCR_TAMPPUEN_POS)        /**< 0x00000080 */
#define TAMP_FLTCR_TAMPPUEN           TAMP_FLTCR_TAMPPUEN_MASK

/* Bits for TAMP_IER */
#define TAMP_IER_TAMPIE_POS          (0U)
#define TAMP_IER_TAMPIE_MASK         (0x1UL << TAMP_IER_TAMPIE_POS)             /**< 0x00000001 */
#define TAMP_IER_TAMPIE              TAMP_IER_TAMPIE_MASK

/* Bits for TAMP_SR */
#define TAMP_SR_TAMPF_POS            (0U)
#define TAMP_SR_TAMPF_MASK           (0x1UL << TAMP_SR_TAMPF_POS)               /**< 0x00000001 */
#define TAMP_SR_TAMPF                TAMP_SR_TAMPF_MASK

/* Bits for TAMP_ISR */
#define TAMP_ISR_TAMPIF_POS          (0U)
#define TAMP_ISR_TAMPIF_MASK         (0x1UL << TAMP_ISR_TAMPIF_POS)             /**< 0x00000001 */
#define TAMP_ISR_TAMPIF              TAMP_ISR_TAMPIF_MASK

/* Bits for TAMP_CLR */
#define TAMP_CLR_CTAMPF_POS          (0U)
#define TAMP_CLR_CTAMPF_MASK         (0x1UL << TAMP_CLR_CTAMPF_POS)             /**< 0x00000001 */
#define TAMP_CLR_CTAMPF              TAMP_CLR_CTAMPF_MASK

/* Bits for TAMP_BKP0R */
#define TAMP_BKP0R_POS                (0U)
#define TAMP_BKP0R_MASK               (0xFFFFFFFFUL << TAMP_BKP0R_POS)            /**< 0xFFFFFFFF */
#define TAMP_BKP0R                    TAMP_BKP0R_MASK

/* Bits for TAMP_BKP1R */
#define TAMP_BKP1R_POS                (0U)
#define TAMP_BKP1R_MASK               (0xFFFFFFFFUL << TAMP_BKP1R_POS)            /**< 0xFFFFFFFF */
#define TAMP_BKP1R                    TAMP_BKP1R_MASK

/* Bits for TAMP_BKP2R */
#define TAMP_BKP2R_POS                (0U)
#define TAMP_BKP2R_MASK               (0xFFFFFFFFUL << TAMP_BKP2R_POS)            /**< 0xFFFFFFFF */
#define TAMP_BKP2R                    TAMP_BKP2R_MASK

/* Bits for TAMP_BKP3R */
#define TAMP_BKP3R_POS                (0U)
#define TAMP_BKP3R_MASK               (0xFFFFFFFFUL << TAMP_BKP3R_POS)            /**< 0xFFFFFFFF */
#define TAMP_BKP3R                    TAMP_BKP3R_MASK

/* Bits for TAMP_BKP4R */
#define TAMP_BKP4R_POS                (0U)
#define TAMP_BKP4R_MASK               (0xFFFFFFFFUL << TAMP_BKP4R_POS)            /**< 0xFFFFFFFF */
#define TAMP_BKP4R                    TAMP_BKP4R_MASK



/*-----------------------------------------------------------------------------------------------
                                       Timer Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for TIM_CR1 */
#define TIM_CR1_CEN_POS                   (0U)
#define TIM_CR1_CEN_MASK                  (0x1UL << TIM_CR1_CEN_POS)                   /**< 0x00000001 */
#define TIM_CR1_CEN                       TIM_CR1_CEN_MASK                             /**< Counter enable */

#define TIM_CR1_UDIS_POS                  (1U)
#define TIM_CR1_UDIS_MASK                 (0x1UL << TIM_CR1_UDIS_POS)                  /**< 0x00000002 */
#define TIM_CR1_UDIS                      TIM_CR1_UDIS_MASK                            /**< Update disable */

#define TIM_CR1_URS_POS                   (2U)
#define TIM_CR1_URS_MASK                  (0x1UL << TIM_CR1_URS_POS)                   /**< 0x00000004 */
#define TIM_CR1_URS                       TIM_CR1_URS_MASK                             /**< Update request source */

#define TIM_CR1_OPM_POS                   (3U)
#define TIM_CR1_OPM_MASK                  (0x1UL << TIM_CR1_OPM_POS)                   /**< 0x00000008 */
#define TIM_CR1_OPM                       TIM_CR1_OPM_MASK                             /**< One pulse mode */

#define TIM_CR1_DIR_POS                   (4U)
#define TIM_CR1_DIR_MASK                  (0x1UL << TIM_CR1_DIR_POS)                   /**< 0x00000010 */
#define TIM_CR1_DIR                       TIM_CR1_DIR_MASK                             /**< Direction */
                                          
#define TIM_CR1_CMS_POS                   (5U)
#define TIM_CR1_CMS_MASK                  (0x3UL << TIM_CR1_CMS_POS)                   /**< 0x00000060 */
#define TIM_CR1_CMS                       TIM_CR1_CMS_MASK                             /**< CMS[1:0] bits (center-aligned mode selection) */
#define TIM_CR1_CMS_CENTER_UP             (0x1UL << TIM_CR1_CMS_POS)                   /**< 0x00000020 */
#define TIM_CR1_CMS_CENTER_DOWN           (0x2UL << TIM_CR1_CMS_POS)                   /**< 0x00000040 */
#define TIM_CR1_CMS_CENTER_UP_DOWN        (0x3UL << TIM_CR1_CMS_POS)                   /**< 0x00000060 */
                                          
#define TIM_CR1_ARPE_POS                  (7U)
#define TIM_CR1_ARPE_MASK                 (0x1UL << TIM_CR1_ARPE_POS)                  /**< 0x00000080 */
#define TIM_CR1_ARPE                      TIM_CR1_ARPE_MASK                            /**< Auto-reload preload enable */
                                          
#define TIM_CR1_CLK_DIV_POS               (8U)
#define TIM_CR1_CLK_DIV_MASK              (0x3UL << TIM_CR1_CLK_DIV_POS)               /**< 0x00000300 */
#define TIM_CR1_CLK_DIV                   TIM_CR1_CLK_DIV_MASK                         /**< CLK_DIV[1:0] bits (clock division) */
#define TIM_CR1_CLK_DIV1                  (0x0UL << TIM_CR1_CLK_DIV_POS)               /**< 0x00000000 */
#define TIM_CR1_CLK_DIV2                  (0x1UL << TIM_CR1_CLK_DIV_POS)               /**< 0x00000100 */
#define TIM_CR1_CLK_DIV4                  (0x2UL << TIM_CR1_CLK_DIV_POS)               /**< 0x00000200 */
                                                                               
/* Bits for TIM_CR2 */                    
#define TIM_CR2_CC_DMASEL_POS             (3U)
#define TIM_CR2_CC_DMASEL_MASK            (0x1UL << TIM_CR2_CC_DMASEL_POS)             /**< 0x00000008 */
#define TIM_CR2_CC_DMASEL                 TIM_CR2_CC_DMASEL_MASK                       /**< Capture/Compare DMA selection */
                                          
#define TIM_CR2_MM_SEL_POS                (4U)
#define TIM_CR2_MM_SEL_MASK               (0x7UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000070 */
#define TIM_CR2_MM_SEL                    TIM_CR2_MM_SEL_MASK                          /**< MM_SEL[2:0] bits (master mode melection) */
#define TIM_CR2_MM_SEL_RESET              (0x0UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000000 */
#define TIM_CR2_MM_SEL_ENABLE             (0x1UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000010 */  
#define TIM_CR2_MM_SEL_UPDATE             (0x2UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000020 */  
#define TIM_CR2_MM_SEL_CC1IF              (0x3UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000030 */  
#define TIM_CR2_MM_SEL_OC1REF             (0x4UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000040 */  
#define TIM_CR2_MM_SEL_OC2REF             (0x5UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000050 */  
#define TIM_CR2_MM_SEL_OC3REF             (0x6UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000060 */  
#define TIM_CR2_MM_SEL_OC4REF             (0x7UL << TIM_CR2_MM_SEL_POS)                /**< 0x00000070 */  
                                          
#define TIM_CR2_TI1_XOR_SEL_POS           (7U)
#define TIM_CR2_TI1_XOR_SEL_MASK          (0x1UL << TIM_CR2_TI1_XOR_SEL_POS)           /**< 0x00000080 */
#define TIM_CR2_TI1_XOR_SEL               TIM_CR2_TI1_XOR_SEL_MASK                     /**< TI1 selection */                                                                              
                                    
/* Bits for TIM_SMC */               
#define TIM_SMC_SM_SEL_POS                (0U)
#define TIM_SMC_SM_SEL_MASK               (0x7UL << TIM_SMC_SM_SEL_POS)                /**< 0x00000007 */
#define TIM_SMC_SM_SEL                    TIM_SMC_SM_SEL_MASK                          /**< SM_SEL[2:0] bits (slave mode selection) */
#define TIM_SMC_SM_SEL_NONE               (0x00UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000000 */  
#define TIM_SMC_SM_SEL_ENCODE_TI1         (0x01UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000001 */  
#define TIM_SMC_SM_SEL_ENCODE_TI2         (0x02UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000002 */  
#define TIM_SMC_SM_SEL_ENCODE_TI12        (0x03UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000003 */  
#define TIM_SMC_SM_SEL_RESET              (0x04UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000004 */  
#define TIM_SMC_SM_SEL_GATED              (0x05UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000005 */ 
#define TIM_SMC_SM_SEL_TRIG               (0x06UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000006 */ 
#define TIM_SMC_SM_SEL_EXT_MODE1          (0x07UL << TIM_SMC_SM_SEL_POS)               /**< 0x00000007 */
                                     
#define TIM_SMC_OCCS_POS                  (3U)
#define TIM_SMC_OCCS_MASK                 (0x1UL << TIM_SMC_OCCS_POS)                  /**< 0x00000008 */
#define TIM_SMC_OCCS                      TIM_SMC_OCCS_MASK                            /**< OCREF clear selection */
                                          
#define TIM_SMC_TS_POS                    (4U)
#define TIM_SMC_TS_MASK                   (0x7UL << TIM_SMC_TS_POS)                    /**< 0x00000070 */
#define TIM_SMC_TS                        TIM_SMC_TS_MASK                              /**< TS[2:0] bits (trigger selection) */
#define TIM_SMC_TS_ITR0                   (0x00UL << TIM_SMC_TS_POS)                   /**< 0x00000000 */
#define TIM_SMC_TS_ITR1                   (0x01UL << TIM_SMC_TS_POS)                   /**< 0x00000010 */
#define TIM_SMC_TS_ITR2                   (0x02UL << TIM_SMC_TS_POS)                   /**< 0x00000020 */
#define TIM_SMC_TS_ITR3                   (0x03UL << TIM_SMC_TS_POS)                   /**< 0x00000030 */
#define TIM_SMC_TS_TI1F_ED                (0x04UL << TIM_SMC_TS_POS)                   /**< 0x00000040 */
#define TIM_SMC_TS_TI1FP1                 (0x05UL << TIM_SMC_TS_POS)                   /**< 0x00000050 */
#define TIM_SMC_TS_TI2FP2                 (0x06UL << TIM_SMC_TS_POS)                   /**< 0x00000060 */
#define TIM_SMC_TS_ETRF                   (0x07UL << TIM_SMC_TS_POS)                   /**< 0x00000070 */
                                          
#define TIM_SMC_MS_MOD_POS                (7U)
#define TIM_SMC_MS_MOD_MASK               (0x1UL << TIM_SMC_MS_MOD_POS)                /**< 0x00000080 */
#define TIM_SMC_MS_MOD                    TIM_SMC_MS_MOD_MASK                          /**< Master/Slave mode */
                                          
#define TIM_SMC_ETF_POS                   (8U)
#define TIM_SMC_ETF_MASK                  (0x7UL << TIM_SMC_ETF_POS)                   /**< 0x00000700 */
#define TIM_SMC_ETF                       TIM_SMC_ETF_MASK                             /**< ETF[2:0] bits (external trigger filter) */
#define TIM_SMC_ETF_FILT_DIV1             (0x01UL << TIM_SMC_ETF_POS)                  /**< 0x00000100 */  
#define TIM_SMC_ETF_FILT_DIV2             (0x02UL << TIM_SMC_ETF_POS)                  /**< 0x00000200 */  
#define TIM_SMC_ETF_FILT_DIV4             (0x03UL << TIM_SMC_ETF_POS)                  /**< 0x00000300 */  
#define TIM_SMC_ETF_FILT_DIV8             (0x04UL << TIM_SMC_ETF_POS)                  /**< 0x00000400 */  
#define TIM_SMC_ETF_FILT_DIV16            (0x05UL << TIM_SMC_ETF_POS)                  /**< 0x00000500 */  
#define TIM_SMC_ETF_FILT_DIV32            (0x06UL << TIM_SMC_ETF_POS)                  /**< 0x00000600 */  
                                          
#define TIM_SMC_ET_PRE_POS                (12U)
#define TIM_SMC_ET_PRE_MASK               (0x3UL << TIM_SMC_ET_PRE_POS)                /**< 0x00003000 */
#define TIM_SMC_ET_PRE                    TIM_SMC_ET_PRE_MASK                          /**< ETPS[1:0] bits (external trigger prescaler) */
#define TIM_SMC_ET_PRE_DIV1               (0x0UL << TIM_SMC_ET_PRE_POS)                /**< 0x00000000 */
#define TIM_SMC_ET_PRE_DIV2               (0x1UL << TIM_SMC_ET_PRE_POS)                /**< 0x00001000 */
#define TIM_SMC_ET_PRE_DIV4               (0x2UL << TIM_SMC_ET_PRE_POS)                /**< 0x00002000 */
#define TIM_SMC_ET_PRE_DIV8               (0x3UL << TIM_SMC_ET_PRE_POS)                /**< 0x00003000 */
                                          
#define TIM_SMC_ECEN_POS                  (14U)
#define TIM_SMC_ECEN_MASK                 (0x1UL << TIM_SMC_ECEN_POS)                  /**< 0x00004000 */
#define TIM_SMC_ECEN                      TIM_SMC_ECEN_MASK                            /**< External clock enable */

#define TIM_SMC_ETP_POS                   (15U)
#define TIM_SMC_ETP_MASK                  (0x1UL << TIM_SMC_ETP_POS)                   /**< 0x00008000 */
#define TIM_SMC_ETP                       TIM_SMC_ETP_MASK                             /**< External trigger polarity */
                                          
/* Bits for TIM_DIER */                   
#define TIM_DIER_UIE_POS                  (0U)
#define TIM_DIER_UIE_MASK                 (0x1UL << TIM_DIER_UIE_POS)                  /**< 0x00000001 */
#define TIM_DIER_UIE                      TIM_DIER_UIE_MASK                            /**< Update interrupt enable */

#define TIM_DIER_CC1IE_POS                (1U)
#define TIM_DIER_CC1IE_MASK               (0x1UL << TIM_DIER_CC1IE_POS)                /**< 0x00000002 */
#define TIM_DIER_CC1IE                    TIM_DIER_CC1IE_MASK                          /**< Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_POS                (2U)
#define TIM_DIER_CC2IE_MASK               (0x1UL << TIM_DIER_CC2IE_POS)                /**< 0x00000004 */
#define TIM_DIER_CC2IE                    TIM_DIER_CC2IE_MASK                          /**< Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_POS                (3U)
#define TIM_DIER_CC3IE_MASK               (0x1UL << TIM_DIER_CC3IE_POS)                /**< 0x00000008 */
#define TIM_DIER_CC3IE                    TIM_DIER_CC3IE_MASK                          /**< Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_POS                (4U)
#define TIM_DIER_CC4IE_MASK               (0x1UL << TIM_DIER_CC4IE_POS)                /**< 0x00000010 */
#define TIM_DIER_CC4IE                    TIM_DIER_CC4IE_MASK                          /**< Capture/Compare 4 interrupt enable */

#define TIM_DIER_TIE_POS                  (6U)
#define TIM_DIER_TIE_MASK                 (0x1UL << TIM_DIER_TIE_POS)                  /**< 0x00000040 */
#define TIM_DIER_TIE                      TIM_DIER_TIE_MASK                            /**< Trigger interrupt enable */
                                       
#define TIM_DIER_UDMAEN_POS               (8U)
#define TIM_DIER_UDMAEN_MASK              (0x1UL << TIM_DIER_UDMAEN_POS)                  /**< 0x00000100 */
#define TIM_DIER_UDMAEN                   TIM_DIER_UDMAEN_MASK                            /**< Update DMA request enable */

#define TIM_DIER_CC1_DMAEN_POS            (9U)
#define TIM_DIER_CC1_DMAEN_MASK           (0x1UL << TIM_DIER_CC1_DMAEN_POS)               /**< 0x00000200 */
#define TIM_DIER_CC1_DMAEN                TIM_DIER_CC1_DMAEN_MASK                         /**< Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2_DMAEN_POS            (10U)
#define TIM_DIER_CC2_DMAEN_MASK           (0x1UL << TIM_DIER_CC2_DMAEN_POS)               /**< 0x00000400 */
#define TIM_DIER_CC2_DMAEN                TIM_DIER_CC2_DMAEN_MASK                         /**< Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3_DMAEN_POS            (11U)
#define TIM_DIER_CC3_DMAEN_MASK           (0x1UL << TIM_DIER_CC3_DMAEN_POS)               /**< 0x00000800 */
#define TIM_DIER_CC3_DMAEN                TIM_DIER_CC3_DMAEN_MASK                         /**< Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4_DMAEN_POS            (12U)
#define TIM_DIER_CC4_DMAEN_MASK           (0x1UL << TIM_DIER_CC4_DMAEN_POS)               /**< 0x00001000 */
#define TIM_DIER_CC4_DMAEN                TIM_DIER_CC4_DMAEN_MASK                         /**< Capture/Compare 4 DMA request enable */

#define TIM_DIER_TDMAEN_POS               (14U)
#define TIM_DIER_TDMAEN_MASK              (0x1UL << TIM_DIER_TDMAEN_POS)                  /**< 0x00004000 */
#define TIM_DIER_TDMAEN                   TIM_DIER_TDMAEN_MASK                            /**< Trigger DMA request enable */
                                          
/* Bits for TIM_SR */                     
#define TIM_SR_UIF_POS                    (0U)
#define TIM_SR_UIF_MASK                   (0x1UL << TIM_SR_UIF_POS)                    /**< 0x00000001 */
#define TIM_SR_UIF                        TIM_SR_UIF_MASK                              /**< Update interrupt flag */

#define TIM_SR_CC1IF_POS                  (1U)
#define TIM_SR_CC1IF_MASK                 (0x1UL << TIM_SR_CC1IF_POS)                  /**< 0x00000002 */
#define TIM_SR_CC1IF                      TIM_SR_CC1IF_MASK                            /**< Capture/Compare 1 interrupt flag */
#define TIM_SR_CC2IF_POS                  (2U)
#define TIM_SR_CC2IF_MASK                 (0x1UL << TIM_SR_CC2IF_POS)                  /**< 0x00000004 */
#define TIM_SR_CC2IF                      TIM_SR_CC2IF_MASK                            /**< Capture/Compare 2 interrupt flag */
#define TIM_SR_CC3IF_POS                  (3U)
#define TIM_SR_CC3IF_MASK                 (0x1UL << TIM_SR_CC3IF_POS)                  /**< 0x00000008 */
#define TIM_SR_CC3IF                      TIM_SR_CC3IF_MASK                            /**< Capture/Compare 3 interrupt flag */
#define TIM_SR_CC4IF_POS                  (4U)
#define TIM_SR_CC4IF_MASK                 (0x1UL << TIM_SR_CC4IF_POS)                  /**< 0x00000010 */
#define TIM_SR_CC4IF                      TIM_SR_CC4IF_MASK                            /**< Capture/Compare 4 interrupt flag */

#define TIM_SR_TIF_POS                    (6U)
#define TIM_SR_TIF_MASK                   (0x1UL << TIM_SR_TIF_POS)                    /**< 0x00000040 */
#define TIM_SR_TIF                        TIM_SR_TIF_MASK                              /**< Trigger interrupt flag */

#define TIM_SR_CC1OF_POS                  (9U)
#define TIM_SR_CC1OF_MASK                 (0x1UL << TIM_SR_CC1OF_POS)                  /**< 0x00000200 */
#define TIM_SR_CC1OF                      TIM_SR_CC1OF_MASK                            /**< Capture/Compare 1 overcapture flag */
#define TIM_SR_CC2OF_POS                  (10U)
#define TIM_SR_CC2OF_MASK                 (0x1UL << TIM_SR_CC2OF_POS)                  /**< 0x00000400 */
#define TIM_SR_CC2OF                      TIM_SR_CC2OF_MASK                            /**< Capture/Compare 2 overcapture flag */
#define TIM_SR_CC3OF_POS                  (11U)
#define TIM_SR_CC3OF_MASK                 (0x1UL << TIM_SR_CC3OF_POS)                  /**< 0x00000800 */
#define TIM_SR_CC3OF                      TIM_SR_CC3OF_MASK                            /**< Capture/Compare 3 overcapture flag */
#define TIM_SR_CC4OF_POS                  (12U)
#define TIM_SR_CC4OF_MASK                 (0x1UL << TIM_SR_CC4OF_POS)                  /**< 0x00001000 */
#define TIM_SR_CC4OF                      TIM_SR_CC4OF_MASK                            /**< Capture/Compare 4 overcapture flag */
                                        
/* Bits for TIM_EVTG */                   
#define TIM_EVTG_UG_POS                   (0U)
#define TIM_EVTG_UG_MASK                  (0x1UL << TIM_EVTG_UG_POS)                  /**< 0x00000001 */
#define TIM_EVTG_UG                       TIM_EVTG_UG_MASK                            /**< Update generation */

#define TIM_EVTG_CC1G_POS                 (1U)
#define TIM_EVTG_CC1G_MASK                (0x1UL << TIM_EVTG_CC1G_POS)                /**< 0x00000002 */
#define TIM_EVTG_CC1G                     TIM_EVTG_CC1G_MASK                          /**< Capture/Compare 1 generation */
#define TIM_EVTG_CC2G_POS                 (2U)
#define TIM_EVTG_CC2G_MASK                (0x1UL << TIM_EVTG_CC2G_POS)                /**< 0x00000004 */
#define TIM_EVTG_CC2G                     TIM_EVTG_CC2G_MASK                          /**< Capture/Compare 2 generation */
#define TIM_EVTG_CC3G_POS                 (3U)
#define TIM_EVTG_CC3G_MASK                (0x1UL << TIM_EVTG_CC3G_POS)                /**< 0x00000008 */
#define TIM_EVTG_CC3G                     TIM_EVTG_CC3G_MASK                          /**< Capture/Compare 3 generation */
#define TIM_EVTG_CC4G_POS                 (4U)
#define TIM_EVTG_CC4G_MASK                (0x1UL << TIM_EVTG_CC4G_POS)                /**< 0x00000010 */
#define TIM_EVTG_CC4G                     TIM_EVTG_CC4G_MASK                          /**< Capture/Compare 4 generation */

#define TIM_EVTG_TG_POS                   (6U)
#define TIM_EVTG_TG_MASK                  (0x1UL << TIM_EVTG_TG_POS)                  /**< 0x00000040 */
#define TIM_EVTG_TG                       TIM_EVTG_TG_MASK                            /**< Trigger generation */

/* Bits for TIM_CCM1 */
#define TIM_CCM1_CC1S_POS                 (0U)
#define TIM_CCM1_CC1S_MASK                (0x3UL << TIM_CCM1_CC1S_POS)                /**< 0x00000003 */
#define TIM_CCM1_CC1S                     TIM_CCM1_CC1S_MASK                          /**< CC1S[1:0] bits (Capture/Compare 1 selection) */
#define TIM_CCM1_CC1S_DIRECTTI            (0x1UL << TIM_CCM1_CC1S_POS)                /**< 0x00000001 */
#define TIM_CCM1_CC1S_INDIRECTTI          (0x2UL << TIM_CCM1_CC1S_POS)                /**< 0x00000002 */
#define TIM_CCM1_CC1S_TRC                 (0x3UL << TIM_CCM1_CC1S_POS)                /**< 0x00000003 */
                                          
#define TIM_CCM1_OC1FE_POS                (2U)
#define TIM_CCM1_OC1FE_MASK               (0x1UL << TIM_CCM1_OC1FE_POS)               /**< 0x00000004 */
#define TIM_CCM1_OC1FE                    TIM_CCM1_OC1FE_MASK                         /**< Output Compare 1 fast enable */
#define TIM_CCM1_OC1PE_POS                (3U)
#define TIM_CCM1_OC1PE_MASK               (0x1UL << TIM_CCM1_OC1PE_POS)               /**< 0x00000008 */
#define TIM_CCM1_OC1PE                    TIM_CCM1_OC1PE_MASK                         /**< Output Compare 1 preload enable */
                                     
#define TIM_CCM1_OC1M_POS                 (4U)
#define TIM_CCM1_OC1M_MASK                (0x7UL << TIM_CCM1_OC1M_POS)                /**< 0x00000070 */
#define TIM_CCM1_OC1M                     TIM_CCM1_OC1M_MASK                          /**< OC1M[2:0] bits (output compare 1 mode) */
#define TIM_CCM1_OC1M_FROZEN              (0x00UL << TIM_CCM1_OC1M_POS)               /**< 0x00000000 */ 
#define TIM_CCM1_OC1M_ACTIVE              (0x01UL << TIM_CCM1_OC1M_POS)               /**< 0x00000010 */ 
#define TIM_CCM1_OC1M_INACTIVE            (0x02UL << TIM_CCM1_OC1M_POS)               /**< 0x00000020 */ 
#define TIM_CCM1_OC1M_TOGGLE              (0x03UL << TIM_CCM1_OC1M_POS)               /**< 0x00000030 */ 
#define TIM_CCM1_OC1M_FORCED_INACTIVE     (0x04UL << TIM_CCM1_OC1M_POS)               /**< 0x00000040 */ 
#define TIM_CCM1_OC1M_FORCED_ACTIVE       (0x05UL << TIM_CCM1_OC1M_POS)               /**< 0x00000050 */ 
#define TIM_CCM1_OC1M_PWM1                (0x06UL << TIM_CCM1_OC1M_POS)               /**< 0x00000060 */ 
#define TIM_CCM1_OC1M_PWM2                (0x07UL << TIM_CCM1_OC1M_POS)               /**< 0x00000070 */ 
                                     
#define TIM_CCM1_OC1CE_POS                (7U)
#define TIM_CCM1_OC1CE_MASK               (0x1UL << TIM_CCM1_OC1CE_POS)               /**< 0x00000080 */
#define TIM_CCM1_OC1CE                    TIM_CCM1_OC1CE_MASK                         /**<Output compare 1 clear enable */
                                          
#define TIM_CCM1_CC2S_POS                 (8U)
#define TIM_CCM1_CC2S_MASK                (0x3UL << TIM_CCM1_CC2S_POS)                /**< 0x00000300 */
#define TIM_CCM1_CC2S                     TIM_CCM1_CC2S_MASK                          /**< CC2S[1:0] bits (Capture/Compare 2 selection) */
#define TIM_CCM1_CC2S_DIRECTTI            (0x1UL << TIM_CCM1_CC2S_POS)                /**< 0x00000100 */
#define TIM_CCM1_CC2S_INDIRECTTI          (0x2UL << TIM_CCM1_CC2S_POS)                /**< 0x00000200 */
#define TIM_CCM1_CC2S_TRC                 (0x3UL << TIM_CCM1_CC2S_POS)                /**< 0x00000300 */
                                          
#define TIM_CCM1_OC2FE_POS                (10U)
#define TIM_CCM1_OC2FE_MASK               (0x1UL << TIM_CCM1_OC2FE_POS)               /**< 0x00000400 */
#define TIM_CCM1_OC2FE                    TIM_CCM1_OC2FE_MASK                         /**<Output compare 2 fast enable */
#define TIM_CCM1_OC2PE_POS                (11U)
#define TIM_CCM1_OC2PE_MASK               (0x1UL << TIM_CCM1_OC2PE_POS)               /**< 0x00000800 */
#define TIM_CCM1_OC2PE                    TIM_CCM1_OC2PE_MASK                         /**<Output compare 2 preload enable */
                                     
#define TIM_CCM1_OC2M_POS                 (12U)
#define TIM_CCM1_OC2M_MASK                (0x7UL << TIM_CCM1_OC2M_POS)                /**< 0x00007000 */
#define TIM_CCM1_OC2M                     TIM_CCM1_OC2M_MASK                          /**< OC2M[2:0] bits (Output compare 2 mode) */
#define TIM_CCM1_OC2M_FROZEN              (0x00UL << TIM_CCM1_OC2M_POS)               /**< 0x00000000 */ 
#define TIM_CCM1_OC2M_ACTIVE              (0x01UL << TIM_CCM1_OC2M_POS)               /**< 0x00001000 */ 
#define TIM_CCM1_OC2M_INACTIVE            (0x02UL << TIM_CCM1_OC2M_POS)               /**< 0x00002000 */ 
#define TIM_CCM1_OC2M_TOGGLE              (0x03UL << TIM_CCM1_OC2M_POS)               /**< 0x00003000 */ 
#define TIM_CCM1_OC2M_FORCED_INACTIVE     (0x04UL << TIM_CCM1_OC2M_POS)               /**< 0x00004000 */ 
#define TIM_CCM1_OC2M_FORCED_ACTIVE       (0x05UL << TIM_CCM1_OC2M_POS)               /**< 0x00005000 */ 
#define TIM_CCM1_OC2M_PWM1                (0x06UL << TIM_CCM1_OC2M_POS)               /**< 0x00006000 */ 
#define TIM_CCM1_OC2M_PWM2                (0x07UL << TIM_CCM1_OC2M_POS)               /**< 0x00007000 */ 
                                     
#define TIM_CCM1_OC2CE_POS                (15U)
#define TIM_CCM1_OC2CE_MASK               (0x1UL << TIM_CCM1_OC2CE_POS)               /**< 0x00008000 */
#define TIM_CCM1_OC2CE                    TIM_CCM1_OC2CE_MASK                         /**< Output compare 2 clear enable */
                                     
/* input and output multiplex*/      
#define TIM_CCM1_IC1PSC_POS               (2U)
#define TIM_CCM1_IC1PSC_MASK              (0x3UL << TIM_CCM1_IC1PSC_POS)              /**< 0x0000000C */
#define TIM_CCM1_IC1PSC                   TIM_CCM1_IC1PSC_MASK                        /**< IC1PSC[1:0] bits (Input capture 1 prescaler) */
#define TIM_CCM1_IC1PSC_DIV1              (0x0UL << TIM_CCM1_IC1PSC_POS)              /**< 0x00000000 */
#define TIM_CCM1_IC1PSC_DIV2              (0x1UL << TIM_CCM1_IC1PSC_POS)              /**< 0x00000004 */
#define TIM_CCM1_IC1PSC_DIV4              (0x2UL << TIM_CCM1_IC1PSC_POS)              /**< 0x00000008 */
#define TIM_CCM1_IC1PSC_DIV8              (0x3UL << TIM_CCM1_IC1PSC_POS)              /**< 0x0000000C */
                                          
#define TIM_CCM1_IC1F_POS                 (4U)
#define TIM_CCM1_IC1F_MASK                (0x7UL << TIM_CCM1_IC1F_POS)                /**< 0x00000070 */
#define TIM_CCM1_IC1F                     TIM_CCM1_IC1F_MASK                          /**< IC1F[2:0] bits (Input capture 1 filter) */
#define TIM_CCM1_IC1F_FILT_DIV1           (0x01UL << TIM_CCM1_IC1F_POS)               /**< 0x00000010 */
#define TIM_CCM1_IC1F_FILT_DIV2           (0x02UL << TIM_CCM1_IC1F_POS)               /**< 0x00000020 */
#define TIM_CCM1_IC1F_FILT_DIV4           (0x03UL << TIM_CCM1_IC1F_POS)               /**< 0x00000030 */
#define TIM_CCM1_IC1F_FILT_DIV8           (0x04UL << TIM_CCM1_IC1F_POS)               /**< 0x00000040 */
#define TIM_CCM1_IC1F_FILT_DIV16          (0x05UL << TIM_CCM1_IC1F_POS)               /**< 0x00000050 */
#define TIM_CCM1_IC1F_FILT_DIV32          (0x06UL << TIM_CCM1_IC1F_POS)               /**< 0x00000060 */
                                     
#define TIM_CCM1_IC2PSC_POS               (10U)
#define TIM_CCM1_IC2PSC_MASK              (0x3UL << TIM_CCM1_IC2PSC_POS)              /**< 0x00000C00 */
#define TIM_CCM1_IC2PSC                   TIM_CCM1_IC2PSC_MASK                        /**< IC2PSC[1:0] bits (Input capture 2 prescaler) */
#define TIM_CCM1_IC2PSC_DIV1              (0x0UL << TIM_CCM1_IC2PSC_POS)              /**< 0x00000000 */
#define TIM_CCM1_IC2PSC_DIV2              (0x1UL << TIM_CCM1_IC2PSC_POS)              /**< 0x00000400 */
#define TIM_CCM1_IC2PSC_DIV4              (0x2UL << TIM_CCM1_IC2PSC_POS)              /**< 0x00000800 */
#define TIM_CCM1_IC2PSC_DIV8              (0x3UL << TIM_CCM1_IC2PSC_POS)              /**< 0x00000C00 */
                                          
#define TIM_CCM1_IC2F_POS                 (12U)
#define TIM_CCM1_IC2F_MASK                (0x7UL << TIM_CCM1_IC2F_POS)                /**< 0x0000F000 */
#define TIM_CCM1_IC2F                     TIM_CCM1_IC2F_MASK                          /**< IC2F[2:0] bits (Input capture 2 filter) */
#define TIM_CCM1_IC2F_FILT_DIV1           (0x01UL << TIM_CCM1_IC2F_POS)               /**< 0x00001000 */
#define TIM_CCM1_IC2F_FILT_DIV2           (0x02UL << TIM_CCM1_IC2F_POS)               /**< 0x00002000 */
#define TIM_CCM1_IC2F_FILT_DIV4           (0x03UL << TIM_CCM1_IC2F_POS)               /**< 0x00003000 */
#define TIM_CCM1_IC2F_FILT_DIV8           (0x04UL << TIM_CCM1_IC2F_POS)               /**< 0x00004000 */
#define TIM_CCM1_IC2F_FILT_DIV16          (0x05UL << TIM_CCM1_IC2F_POS)               /**< 0x00005000 */
#define TIM_CCM1_IC2F_FILT_DIV32          (0x06UL << TIM_CCM1_IC2F_POS)               /**< 0x00006000 */
                                     
/* Bits for TIM_CCM2 */              
#define TIM_CCM2_CC3S_POS                 (0U)
#define TIM_CCM2_CC3S_MASK                (0x3UL << TIM_CCM2_CC3S_POS)                /**< 0x00000003 */
#define TIM_CCM2_CC3S                     TIM_CCM2_CC3S_MASK                          /**< CC3S[1:0] bits (Capture/Compare 3 selection) */
#define TIM_CCM2_CC3S_DIRECTTI            (0x1UL << TIM_CCM2_CC3S_POS)                /**< 0x00000001 */
#define TIM_CCM2_CC3S_INDIRECTTI          (0x2UL << TIM_CCM2_CC3S_POS)                /**< 0x00000002 */
#define TIM_CCM2_CC3S_TRC                 (0x3UL << TIM_CCM2_CC3S_POS)                /**< 0x00000003 */
                                          
#define TIM_CCM2_OC3FE_POS                (2U)
#define TIM_CCM2_OC3FE_MASK               (0x1UL << TIM_CCM2_OC3FE_POS)               /**< 0x00000004 */
#define TIM_CCM2_OC3FE                    TIM_CCM2_OC3FE_MASK                         /**< Output Compare 3 fast enable */
#define TIM_CCM2_OC3PE_POS                (3U)
#define TIM_CCM2_OC3PE_MASK               (0x1UL << TIM_CCM2_OC3PE_POS)               /**< 0x00000008 */
#define TIM_CCM2_OC3PE                    TIM_CCM2_OC3PE_MASK                         /**< Output Compare 3 preload enable */
                                     
#define TIM_CCM2_OC3M_POS                 (4U)
#define TIM_CCM2_OC3M_MASK                (0x7UL << TIM_CCM2_OC3M_POS)                /**< 0x00010070 */
#define TIM_CCM2_OC3M                     TIM_CCM2_OC3M_MASK                          /**< OC3M[2:0] bits (Output compare 3 mode) */
#define TIM_CCM2_OC3M_FROZEN              (0x00UL << TIM_CCM2_OC3M_POS)               /**< 0x00000000 */ 
#define TIM_CCM2_OC3M_ACTIVE              (0x01UL << TIM_CCM2_OC3M_POS)               /**< 0x00000010 */ 
#define TIM_CCM2_OC3M_INACTIVE            (0x02UL << TIM_CCM2_OC3M_POS)               /**< 0x00000020 */ 
#define TIM_CCM2_OC3M_TOGGLE              (0x03UL << TIM_CCM2_OC3M_POS)               /**< 0x00000030 */ 
#define TIM_CCM2_OC3M_FORCED_INACTIVE     (0x04UL << TIM_CCM2_OC3M_POS)               /**< 0x00000040 */ 
#define TIM_CCM2_OC3M_FORCED_ACTIVE       (0x05UL << TIM_CCM2_OC3M_POS)               /**< 0x00000050 */ 
#define TIM_CCM2_OC3M_PWM1                (0x06UL << TIM_CCM2_OC3M_POS)               /**< 0x00000060 */ 
#define TIM_CCM2_OC3M_PWM2                (0x07UL << TIM_CCM2_OC3M_POS)               /**< 0x00000070 */ 
                                     
#define TIM_CCM2_OC3CE_POS                (7U)
#define TIM_CCM2_OC3CE_MASK               (0x1UL << TIM_CCM2_OC3CE_POS)               /**< 0x00000080 */
#define TIM_CCM2_OC3CE                    TIM_CCM2_OC3CE_MASK                         /**< Output compare 3 clear enable */
                                          
#define TIM_CCM2_CC4S_POS                 (8U)
#define TIM_CCM2_CC4S_MASK                (0x3UL << TIM_CCM2_CC4S_POS)                /**< 0x00000300 */
#define TIM_CCM2_CC4S                     TIM_CCM2_CC4S_MASK                          /**< CC4S[1:0] bits (Capture/Compare 4 selection) */
#define TIM_CCM2_CC4S_DIRECTTI            (0x1UL << TIM_CCM2_CC4S_POS)                /**< 0x00000100 */
#define TIM_CCM2_CC4S_INDIRECTTI          (0x2UL << TIM_CCM2_CC4S_POS)                /**< 0x00000200 */
#define TIM_CCM2_CC4S_TRC                 (0x3UL << TIM_CCM2_CC4S_POS)                /**< 0x00000300 */
                                          
#define TIM_CCM2_OC4FE_POS                (10U)
#define TIM_CCM2_OC4FE_MASK               (0x1UL << TIM_CCM2_OC4FE_POS)               /**< 0x00000400 */
#define TIM_CCM2_OC4FE                    TIM_CCM2_OC4FE_MASK                         /**< Output compare 4 fast enable */
#define TIM_CCM2_OC4PE_POS                (11U)
#define TIM_CCM2_OC4PE_MASK               (0x1UL << TIM_CCM2_OC4PE_POS)               /**< 0x00000800 */
#define TIM_CCM2_OC4PE                    TIM_CCM2_OC4PE_MASK                         /**< Output compare 4 preload enable */
                                     
#define TIM_CCM2_OC4M_POS                 (12U)
#define TIM_CCM2_OC4M_MASK                (0x7UL << TIM_CCM2_OC4M_POS)                /**< 0x01007000 */
#define TIM_CCM2_OC4M                     TIM_CCM2_OC4M_MASK                          /**< OC4M[2:0] bits (Output compare 4 mode) */
#define TIM_CCM2_OC4M_FROZEN              (0x00UL << TIM_CCM2_OC4M_POS)               /**< 0x00000000 */ 
#define TIM_CCM2_OC4M_ACTIVE              (0x01UL << TIM_CCM2_OC4M_POS)               /**< 0x00001000 */ 
#define TIM_CCM2_OC4M_INACTIVE            (0x02UL << TIM_CCM2_OC4M_POS)               /**< 0x00002000 */ 
#define TIM_CCM2_OC4M_TOGGLE              (0x03UL << TIM_CCM2_OC4M_POS)               /**< 0x00003000 */ 
#define TIM_CCM2_OC4M_FORCED_INACTIVE     (0x04UL << TIM_CCM2_OC4M_POS)               /**< 0x00004000 */ 
#define TIM_CCM2_OC4M_FORCED_ACTIVE       (0x05UL << TIM_CCM2_OC4M_POS)               /**< 0x00005000 */ 
#define TIM_CCM2_OC4M_PWM1                (0x06UL << TIM_CCM2_OC4M_POS)               /**< 0x00006000 */ 
#define TIM_CCM2_OC4M_PWM2                (0x07UL << TIM_CCM2_OC4M_POS)               /**< 0x00007000 */ 
                                     
#define TIM_CCM2_OC4CE_POS                (15U)
#define TIM_CCM2_OC4CE_MASK               (0x1UL << TIM_CCM2_OC4CE_POS)               /**< 0x00008000 */
#define TIM_CCM2_OC4CE                    TIM_CCM2_OC4CE_MASK                         /**<Output compare 4 clear enable */
                                     
/* input and output multiplex*/      
#define TIM_CCM2_IC3PSC_POS               (2U)
#define TIM_CCM2_IC3PSC_MASK              (0x3UL << TIM_CCM2_IC3PSC_POS)              /**< 0x0000000C */
#define TIM_CCM2_IC3PSC                   TIM_CCM2_IC3PSC_MASK                        /**< IC3PSC[1:0] bits (Input capture 3 prescaler) */
#define TIM_CCM2_IC3PSC_DIV1              (0x0UL << TIM_CCM2_IC3PSC_POS)              /**< 0x00000000 */   
#define TIM_CCM2_IC3PSC_DIV2              (0x1UL << TIM_CCM2_IC3PSC_POS)              /**< 0x00000004 */   
#define TIM_CCM2_IC3PSC_DIV4              (0x2UL << TIM_CCM2_IC3PSC_POS)              /**< 0x00000008 */   
#define TIM_CCM2_IC3PSC_DIV8              (0x3UL << TIM_CCM2_IC3PSC_POS)              /**< 0x0000000C */   
                                     
#define TIM_CCM2_IC3F_POS                 (4U)
#define TIM_CCM2_IC3F_MASK                (0x7UL << TIM_CCM2_IC3F_POS)                /**< 0x000000F0 */
#define TIM_CCM2_IC3F                     TIM_CCM2_IC3F_MASK                          /**< IC3F[2:0] bits (Input capture 3 filter) */
#define TIM_CCM2_IC3F_FILT_DIV1           (0x01UL << TIM_CCM2_IC3F_POS)               /**< 0x00000010 */
#define TIM_CCM2_IC3F_FILT_DIV2           (0x02UL << TIM_CCM2_IC3F_POS)               /**< 0x00000020 */
#define TIM_CCM2_IC3F_FILT_DIV4           (0x03UL << TIM_CCM2_IC3F_POS)               /**< 0x00000030 */
#define TIM_CCM2_IC3F_FILT_DIV8           (0x04UL << TIM_CCM2_IC3F_POS)               /**< 0x00000040 */
#define TIM_CCM2_IC3F_FILT_DIV16          (0x05UL << TIM_CCM2_IC3F_POS)               /**< 0x00000050 */
#define TIM_CCM2_IC3F_FILT_DIV32          (0x06UL << TIM_CCM2_IC3F_POS)               /**< 0x00000060 */
                                     
#define TIM_CCM2_IC4PSC_POS               (10U)
#define TIM_CCM2_IC4PSC_MASK              (0x3UL << TIM_CCM2_IC4PSC_POS)              /**< 0x00000C00 */
#define TIM_CCM2_IC4PSC                   TIM_CCM2_IC4PSC_MASK                        /**< IC4PSC[1:0] bits (Input capture 4 prescaler) */
#define TIM_CCM2_IC4PSC_DIV1              (0x0UL << TIM_CCM2_IC4PSC_POS)              /**< 0x00000000 */   
#define TIM_CCM2_IC4PSC_DIV2              (0x1UL << TIM_CCM2_IC4PSC_POS)              /**< 0x00000400 */   
#define TIM_CCM2_IC4PSC_DIV4              (0x2UL << TIM_CCM2_IC4PSC_POS)              /**< 0x00000800 */   
#define TIM_CCM2_IC4PSC_DIV8              (0x3UL << TIM_CCM2_IC4PSC_POS)              /**< 0x00000C00 */  
                                     
#define TIM_CCM2_IC4F_POS                 (12U)
#define TIM_CCM2_IC4F_MASK                (0x7UL << TIM_CCM2_IC4F_POS)                /**< 0x0000F000 */
#define TIM_CCM2_IC4F                     TIM_CCM2_IC4F_MASK                          /**< IC4F[2:0] bits (Input capture 4 filter) */
#define TIM_CCM2_IC4F_FILT_DIV1           (0x01UL << TIM_CCM2_IC4F_POS)               /**< 0x00001000 */
#define TIM_CCM2_IC4F_FILT_DIV2           (0x02UL << TIM_CCM2_IC4F_POS)               /**< 0x00002000 */
#define TIM_CCM2_IC4F_FILT_DIV4           (0x03UL << TIM_CCM2_IC4F_POS)               /**< 0x00003000 */
#define TIM_CCM2_IC4F_FILT_DIV8           (0x04UL << TIM_CCM2_IC4F_POS)               /**< 0x00004000 */
#define TIM_CCM2_IC4F_FILT_DIV16          (0x05UL << TIM_CCM2_IC4F_POS)               /**< 0x00005000 */
#define TIM_CCM2_IC4F_FILT_DIV32          (0x06UL << TIM_CCM2_IC4F_POS)               /**< 0x00006000 */                                   

/* Bits for TIM_CCEN */
#define TIM_CCEN_CC1E_POS                 (0U)
#define TIM_CCEN_CC1E_MASK                (0x1UL << TIM_CCEN_CC1E_POS)                 /**< 0x00000001 */
#define TIM_CCEN_CC1E                     TIM_CCEN_CC1E_MASK                           /**<Capture/Compare 1 output enable */
#define TIM_CCEN_CC1P_POS                 (1U)
#define TIM_CCEN_CC1P_MASK                (0x1UL << TIM_CCEN_CC1P_POS)                 /**< 0x00000002 */
#define TIM_CCEN_CC1P                     TIM_CCEN_CC1P_MASK                           /**<Capture/Compare 1 output Polarity */
#define TIM_CCEN_CC1NE_POS                (2U)
#define TIM_CCEN_CC1NE_MASK               (0x1UL << TIM_CCEN_CC1NE_POS)                /**< 0x00000004 */
#define TIM_CCEN_CC1NE                    TIM_CCEN_CC1NE_MASK                          /**<Capture/Compare 1 complementary output enable */
#define TIM_CCEN_CC1NP_POS                (3U)
#define TIM_CCEN_CC1NP_MASK               (0x1UL << TIM_CCEN_CC1NP_POS)                /**< 0x00000008 */
#define TIM_CCEN_CC1NP                    TIM_CCEN_CC1NP_MASK                          /**<Capture/Compare 1 complementary output Polarity */

#define TIM_CCEN_CC2E_POS                 (4U)
#define TIM_CCEN_CC2E_MASK                (0x1UL << TIM_CCEN_CC2E_POS)                 /**< 0x00000010 */
#define TIM_CCEN_CC2E                     TIM_CCEN_CC2E_MASK                           /**<Capture/Compare 2 output enable */
#define TIM_CCEN_CC2P_POS                 (5U)
#define TIM_CCEN_CC2P_MASK                (0x1UL << TIM_CCEN_CC2P_POS)                 /**< 0x00000020 */
#define TIM_CCEN_CC2P                     TIM_CCEN_CC2P_MASK                           /**<Capture/Compare 2 output Polarity */
#define TIM_CCEN_CC2NE_POS                (6U)
#define TIM_CCEN_CC2NE_MASK               (0x1UL << TIM_CCEN_CC2NE_POS)                /**< 0x00000040 */
#define TIM_CCEN_CC2NE                    TIM_CCEN_CC2NE_MASK                          /**<Capture/Compare 2 complementary output enable */
#define TIM_CCEN_CC2NP_POS                (7U)
#define TIM_CCEN_CC2NP_MASK               (0x1UL << TIM_CCEN_CC2NP_POS)                /**< 0x00000080 */
#define TIM_CCEN_CC2NP                    TIM_CCEN_CC2NP_MASK                          /**<Capture/Compare 2 complementary output Polarity */

#define TIM_CCEN_CC3E_POS                 (8U)
#define TIM_CCEN_CC3E_MASK                (0x1UL << TIM_CCEN_CC3E_POS)                 /**< 0x00000100 */
#define TIM_CCEN_CC3E                     TIM_CCEN_CC3E_MASK                           /**<Capture/Compare 3 output enable */
#define TIM_CCEN_CC3P_POS                 (9U)
#define TIM_CCEN_CC3P_MASK                (0x1UL << TIM_CCEN_CC3P_POS)                 /**< 0x00000200 */
#define TIM_CCEN_CC3P                     TIM_CCEN_CC3P_MASK                           /**<Capture/Compare 3 output Polarity */
#define TIM_CCEN_CC3NE_POS                (10U)
#define TIM_CCEN_CC3NE_MASK               (0x1UL << TIM_CCEN_CC3NE_POS)                /**< 0x00000400 */
#define TIM_CCEN_CC3NE                    TIM_CCEN_CC3NE_MASK                          /**<Capture/Compare 3 complementary output enable */
#define TIM_CCEN_CC3NP_POS                (11U)
#define TIM_CCEN_CC3NP_MASK               (0x1UL << TIM_CCEN_CC3NP_POS)                /**< 0x00000800 */
#define TIM_CCEN_CC3NP                    TIM_CCEN_CC3NP_MASK                          /**<Capture/Compare 3 complementary output polarity */

#define TIM_CCEN_CC4E_POS                 (12U)
#define TIM_CCEN_CC4E_MASK                (0x1UL << TIM_CCEN_CC4E_POS)                 /**< 0x00001000 */
#define TIM_CCEN_CC4E                     TIM_CCEN_CC4E_MASK                           /**<Capture/Compare 4 output enable */
#define TIM_CCEN_CC4P_POS                 (13U)
#define TIM_CCEN_CC4P_MASK                (0x1UL << TIM_CCEN_CC4P_POS)                 /**< 0x00002000 */
#define TIM_CCEN_CC4P                     TIM_CCEN_CC4P_MASK                           /**<Capture/Compare 4 output Polarity */                                         
#define TIM_CCEN_CC4NP_POS                (15U)
#define TIM_CCEN_CC4NP_MASK               (0x1UL << TIM_CCEN_CC4NP_POS)                /**< 0x00008000 */
#define TIM_CCEN_CC4NP                    TIM_CCEN_CC4NP_MASK                          /**<Capture/Compare 4 complementary output polarity */

/* Bits for TIM_CNT */                    
#define TIM_CNT_CNT_POS                   (0U)
#define TIM_CNT_CNT_MASK                  (0xFFFFUL << TIM_CNT_CNT_POS)                /**< 0x0000FFFF */
#define TIM_CNT_CNT                       TIM_CNT_CNT_MASK                             /**<Counter value */
                                        
/* Bits for TIM_PSC */                    
#define TIM_PSC_PSC_POS                   (0U)
#define TIM_PSC_PSC_MASK                  (0xFFFFUL << TIM_PSC_PSC_POS)                /**< 0x0000FFFF */
#define TIM_PSC_PSC                       TIM_PSC_PSC_MASK                             /**<Prescaler value */
                                          
/* Bits for TIM_ARR */                    
#define TIM_ARR_ARR_POS                   (0U)
#define TIM_ARR_ARR_MASK                  (0xFFFFUL << TIM_ARR_ARR_POS)                /**< 0x0000FFFF */
#define TIM_ARR_ARR                       TIM_ARR_ARR_MASK                             /**<Actual auto-reload value */
                                                                                  
/* Bits for TIM_CC1 */                    
#define TIM_CC1_CC1_POS                   (0U) 
#define TIM_CC1_CC1_MASK                  (0xFFFFUL << TIM_CC1_CC1_POS)                /**< 0x0000FFFF */
#define TIM_CC1_CC1                       TIM_CC1_CC1_MASK                             /**<Capture/Compare 1 value */
                                          
/* Bits for TIM_CC2 */                    
#define TIM_CC2_CC2_POS                   (0U)
#define TIM_CC2_CC2_MASK                  (0xFFFFUL << TIM_CC2_CC2_POS)                /**< 0x0000FFFF */
#define TIM_CC2_CC2                       TIM_CC2_CC2_MASK                             /**<Capture/Compare 2 value */
                                          
/* Bits for TIM_CC3 */                    
#define TIM_CC3_CC3_POS                   (0U)
#define TIM_CC3_CC3_MASK                  (0xFFFFUL << TIM_CC3_CC3_POS)                /**< 0x0000FFFF */
#define TIM_CC3_CC3                       TIM_CC3_CC3_MASK                             /**<Capture/Compare 3 value */
                                          
/* Bits for TIM_CC4 */                    
#define TIM_CC4_CC4_POS                   (0U)
#define TIM_CC4_CC4_MASK                  (0xFFFFUL << TIM_CC4_CC4_POS)                /**< 0x0000FFFF */
#define TIM_CC4_CC4                       TIM_CC4_CC4_MASK                             /**<Capture/Compare 4 value */
                                                                                                                          
/* Bits for TIM_CFG */                    
#define TIM_CFG_OCREF_CLR_POS             (0U)
#define TIM_CFG_OCREF_CLR_MASK            (0x1UL << TIM_CFG_OCREF_CLR_POS)             /**< 0x00000001 */
#define TIM_CFG_OCREF_CLR                 TIM_CFG_OCREF_CLR_MASK                       /**<OCREF clear input selection */
                                          
/* BK Bits for TIM_AF1_ETR_SEL */         
#define TIM_AF1_ETR_SEL_POS               (14U)
#define TIM_AF1_ETR_SEL_MASK              (0x7UL << TIM_AF1_ETR_SEL_POS)               /**< 0x0003C000 */
#define TIM_AF1_ETR_SEL                   TIM_AF1_ETR_SEL_MASK                         /**<ETR_SEL[2:0] bits (TIM1 ETR source selection) */

/* Bits for TIM3_ETR_SEL */                                            
#define TIM3_AF1_ETR_SEL_GPIO             (0x0UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00000000 */
#define TIM3_AF1_ETR_SEL_COMP1            (0x1UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00004000 */
#define TIM3_AF1_ETR_SEL_COMP2            (0x2UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00008000 */
#define TIM3_AF1_ETR_SEL_LXTAL            (0x3UL << TIM_AF1_ETR_SEL_POS)               /**< 0x0000C000 */
#define TIM3_AF1_ETR_SEL_HXTAL            (0x4UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00010000 */
#define TIM3_AF1_ETR_SEL_MCO              (0x5UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00014000 */
#define TIM3_AF1_ETR_SEL_RCL              (0x6UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00018000 */

/* Bits for TIM4_ETR_SEL */                                            
#define TIM4_AF1_ETR_SEL_GPIO             (0x0UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00000000 */
#define TIM4_AF1_ETR_SEL_COMP1            (0x1UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00004000 */
#define TIM4_AF1_ETR_SEL_COMP2            (0x2UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00008000 */

/* Bits for TIM5_ETR_SEL */                                            
#define TIM5_AF1_ETR_SEL_GPIO             (0x0UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00000000 */
#define TIM5_AF1_ETR_SEL_COMP1            (0x1UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00004000 */
#define TIM5_AF1_ETR_SEL_COMP2            (0x2UL << TIM_AF1_ETR_SEL_POS)               /**< 0x00008000 */
                                          
/* Bits for TIM_TISEL */                  
#define TIM_TISEL_TI1_SEL_POS             (0U)
#define TIM_TISEL_TI1_SEL_MASK            (0x3UL << TIM_TISEL_TI1_SEL_POS)             /**< 0x0000000F */
#define TIM_TISEL_TI1_SEL                 TIM_TISEL_TI1_SEL_MASK                       /**<TI1_SEL[3:0] bits (TIM1 TI1 SEL)*/
#define TIM_TISEL_TI1_SEL_CH1             (0x0UL << TIM_TISEL_TI1_SEL_POS)             /**< 0x00000000 */
#define TIM_TISEL_TI1_SEL_COMP1           (0x1UL << TIM_TISEL_TI1_SEL_POS)             /**< 0x00000001 */                                          
                                          
#define TIM_TISEL_TI2_SEL_POS             (8U)
#define TIM_TISEL_TI2_SEL_MASK            (0x3UL << TIM_TISEL_TI2_SEL_POS)             /**< 0x00000F00 */
#define TIM_TISEL_TI2_SEL                 TIM_TISEL_TI2_SEL_MASK                       /**<TI2_SEL[3:0] bits (TIM1 TI2 SEL)*/                                        
#define TIM_TISEL_TI2_SEL_CH2             (0x0UL << TIM_TISEL_TI2_SEL_POS)             /**< 0x00000000 */
#define TIM_TISEL_TI2_SEL_COMP2           (0x1UL << TIM_TISEL_TI2_SEL_POS)             /**< 0x00000001 */    
                                          
#define TIM_TISEL_TI4_SEL_POS             (24U)
#define TIM_TISEL_TI4_SEL_MASK            (0x7UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x0F000000 */
#define TIM_TISEL_TI4_SEL                 TIM_TISEL_TI4_SEL_MASK                       /**<TI4_SEL[3:0] bits (TIM1 TI4 SEL)*/

/* Bits for TIM3_TI4_SEL */ 
#define TIM3_TISEL_TI4_SEL_CH4            (0x0UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x00000000 */
#define TIM3_TISEL_TI4_SEL_LXTAL          (0x1UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x01000000 */
#define TIM3_TISEL_TI4_SEL_HXTAL          (0x2UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x02000000 */
#define TIM3_TISEL_TI4_SEL_MCO            (0x3UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x03000000 */
#define TIM3_TISEL_TI4_SEL_RCL            (0x4UL << TIM_TISEL_TI4_SEL_POS)             /**< 0x04000000 */


/*-----------------------------------------------------------------------------------------------
                                       TRNG Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for TRNG_CR1 */
#define TRNG_CR1_RDYIE_POS               (0U)
#define TRNG_CR1_RDYIE_MASK              (0x1UL << TRNG_CR1_RDYIE_POS)                 /**< 0x00000001 */
#define TRNG_CR1_RDYIE                   TRNG_CR1_RDYIE_MASK                           /**< TRNG ready interrupt enable */

#define TRNG_CR1_TYPE_SEL_POS            (4U)
#define TRNG_CR1_TYPE_SEL_MASK           (0x1UL << TRNG_CR1_TYPE_SEL_POS)              /**< 0x00000010 */
#define TRNG_CR1_TYPE_SEL                TRNG_CR1_TYPE_SEL_MASK                        /**< TRNG type select */
#define TRNG_CR1_TYPE_SEL_TRUE           (0x0UL << TRNG_CR1_TYPE_SEL_POS)              /**< 0x00000000 */
#define TRNG_CR1_TYPE_SEL_PSEUDO         (0x1UL << TRNG_CR1_TYPE_SEL_POS)              /**< 0x00000010 */

/* Bits for TRNG_SR */
#define TRNG_SR_RDY_POS                  (0U)
#define TRNG_SR_RDY_MASK                 (0x1UL << TRNG_SR_RDY_POS)                    /**< 0x00000001 */
#define TRNG_SR_RDY                      TRNG_SR_RDY_MASK                              /**< TRNG data ready flag */

/* Bits for TRNG_DR */
#define TRNG_DR_POS                      (0U)
#define TRNG_DR_MASK                     (0xFFFFFFFFUL << TRNG_DR_POS)                 /**< 0xFFFFFFFF */
#define TRNG_DR                          TRNG_DR_MASK                                  /**< TRNG data register */

/*-----------------------------------------------------------------------------------------------
                                       USART Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for USART_CR1 */
#define USART_CR1_UE_POS               (0U)
#define USART_CR1_UE_MASK              (0x1UL << USART_CR1_UE_POS)                     /**< 0x00000001 */
#define USART_CR1_UE                   USART_CR1_UE_MASK                               /**< USART enable */
#define USART_CR1_UEWK_POS             (1U)                                         
#define USART_CR1_UEWK_MASK            (0x1UL << USART_CR1_UEWK_POS)                   /**< 0x00000002 */
#define USART_CR1_UEWK                 USART_CR1_UEWK_MASK                             /**< USART enable wakeup from STOP mode */
#define USART_CR1_RE_POS               (2U)                                         
#define USART_CR1_RE_MASK              (0x1UL << USART_CR1_RE_POS)                     /**< 0x00000004 */
#define USART_CR1_RE                   USART_CR1_RE_MASK                               /**< Receiver enable */
#define USART_CR1_TE_POS               (3U)                                         
#define USART_CR1_TE_MASK              (0x1UL << USART_CR1_TE_POS)                     /**< 0x00000008 */
#define USART_CR1_TE                   USART_CR1_TE_MASK                               /**< Transmitter enable */
#define USART_CR1_IDLEIE_POS           (4U)                                         
#define USART_CR1_IDLEIE_MASK          (0x1UL << USART_CR1_IDLEIE_POS)                 /**< 0x00000010 */
#define USART_CR1_IDLEIE               USART_CR1_IDLEIE_MASK                           /**< IDLE interrupt enable */
#define USART_CR1_RXNEIE_POS           (5U)                                         
#define USART_CR1_RXNEIE_MASK          (0x1UL << USART_CR1_RXNEIE_POS)                 /**< 0x00000020 */
#define USART_CR1_RXNEIE               USART_CR1_RXNEIE_MASK                           /**< Read data register not empty interrupt enable */
#define USART_CR1_TCIE_POS             (6U)                                         
#define USART_CR1_TCIE_MASK            (0x1UL << USART_CR1_TCIE_POS)                   /**< 0x00000040 */
#define USART_CR1_TCIE                 USART_CR1_TCIE_MASK                             /**< Transmission Complete interrupt enable */
#define USART_CR1_TXEIE_POS            (7U)                                         
#define USART_CR1_TXEIE_MASK           (0x1UL << USART_CR1_TXEIE_POS)                  /**< 0x00000080 */
#define USART_CR1_TXEIE                USART_CR1_TXEIE_MASK                            /**< Transmit Data Register empty interrupt enable */
#define USART_CR1_PEIE_POS             (8U)                                         
#define USART_CR1_PEIE_MASK            (0x1UL << USART_CR1_PEIE_POS)                   /**< 0x00000100 */
#define USART_CR1_PEIE                 USART_CR1_PEIE_MASK                             /**< PE interrupt enable */
#define USART_CR1_PTS_POS              (9U)                                         
#define USART_CR1_PTS_MASK             (0x1UL << USART_CR1_PTS_POS)                    /**< 0x00000200 */
#define USART_CR1_PTS                  USART_CR1_PTS_MASK                              /**< Parity selection */
#define USART_CR1_PEN_POS              (10U)                                        
#define USART_CR1_PEN_MASK             (0x1UL << USART_CR1_PEN_POS)                    /**< 0x00000400 */
#define USART_CR1_PEN                  USART_CR1_PEN_MASK                              /**< Parity control enable */
#define USART_CR1_RXWKUP_POS           (11U)                                        
#define USART_CR1_RXWKUP_MASK          (0x1UL << USART_CR1_RXWKUP_POS)                 /**< 0x00000800 */
#define USART_CR1_RXWKUP               USART_CR1_RXWKUP_MASK                           /**< Receiver wakeup method */

#define USART_CR1_WL_POS               (12U)                                        
#define USART_CR1_WL_MASK              (0x1UL << USART_CR1_WL_POS)                     
#define USART_CR1_WL                   USART_CR1_WL_MASK                               /**< Word length */
#define USART_CR1_WL8BITS              (0x0UL << USART_CR1_WL_POS)                     /**< 0x00000000 */
#define USART_CR1_WL9BITS              USART_CR1_WL_MASK                               /**< 0x00001000 */
     
#define USART_CR1_RXMME_POS            (13U)                                        
#define USART_CR1_RXMME_MASK           (0x1UL << USART_CR1_RXMME_POS)                  /**< 0x00002000 */
#define USART_CR1_RXMME                USART_CR1_RXMME_MASK                            /**< Mute mode enable */
#define USART_CR1_CMIE_POS             (14U)                                        
#define USART_CR1_CMIE_MASK            (0x1UL << USART_CR1_CMIE_POS)                   /**< 0x00004000 */
#define USART_CR1_CMIE                 USART_CR1_CMIE_MASK                             /**< Character match interrupt enable */
#define USART_CR1_OVS8_POS             (15U)                                        
#define USART_CR1_OVS8_MASK            (0x1UL << USART_CR1_OVS8_POS)                   /**< 0x00008000 */
#define USART_CR1_OVS8                 USART_CR1_OVS8_MASK                             /**< Oversampling by 8-bit or 16-bit mode */

#define USART_CR1_DEHT_POS             (16U)                                        
#define USART_CR1_DEHT_MASK            (0x1FUL << USART_CR1_DEHT_POS)                  /**< 0x001F0000 */
#define USART_CR1_DEHT                 USART_CR1_DEHT_MASK                             /**< DEHT[4:0] bits (Driver enable hold time) */

#define USART_CR1_DEHT_0               (0x01UL << USART_CR1_DEHT_POS)                  /**< 0x00010000 */
#define USART_CR1_DEHT_1               (0x02UL << USART_CR1_DEHT_POS)                  /**< 0x00020000 */
#define USART_CR1_DEHT_2               (0x04UL << USART_CR1_DEHT_POS)                  /**< 0x00040000 */
#define USART_CR1_DEHT_3               (0x08UL << USART_CR1_DEHT_POS)                  /**< 0x00080000 */
#define USART_CR1_DEHT_4               (0x10UL << USART_CR1_DEHT_POS)                  /**< 0x00100000 */

#define USART_CR1_DEST_POS             (21U)                                        
#define USART_CR1_DEST_MASK            (0x1FUL << USART_CR1_DEST_POS)                  /**< 0x03E00000 */
#define USART_CR1_DEST                 USART_CR1_DEST_MASK                             /**< DEST[4:0] bits (Driver enable set time) */
   
#define USART_CR1_DEST_0               (0x01UL << USART_CR1_DEST_POS)                  /**< 0x00200000 */
#define USART_CR1_DEST_1               (0x02UL << USART_CR1_DEST_POS)                  /**< 0x00400000 */
#define USART_CR1_DEST_2               (0x04UL << USART_CR1_DEST_POS)                  /**< 0x00800000 */
#define USART_CR1_DEST_3               (0x08UL << USART_CR1_DEST_POS)                  /**< 0x01000000 */
#define USART_CR1_DEST_4               (0x10UL << USART_CR1_DEST_POS)                  /**< 0x02000000 */

#define USART_CR1_RTOIE_POS            (26U)
#define USART_CR1_RTOIE_MASK           (0x1UL << USART_CR1_RTOIE_POS)                  /**< 0x040000000 */
#define USART_CR1_RTOIE                USART_CR1_RTOIE_MASK                            /**< Receive timeout interrupt enable */
                          
#define USART_CR1_EBIE_POS             (27U)                                       
#define USART_CR1_EBIE_MASK            (0x1UL << USART_CR1_EBIE_POS)                   /**< 0x080000000 */
#define USART_CR1_EBIE                 USART_CR1_EBIE_MASK                             /**< End of Block interrupt enable */
                          
/* Bits for USART_CR2 */                                                           
#define USART_CR2_ADDRM_POS            (4U)                                        
#define USART_CR2_ADDRM_MASK           (0x1UL << USART_CR2_ADDRM_POS)                  /**< 0x00000010 */
#define USART_CR2_ADDRM                USART_CR2_ADDRM_MASK                            /**< 7-bit or 4-bit address detection */
#define USART_CR2_LBDL_POS             (5U)                                        
#define USART_CR2_LBDL_MASK            (0x1UL << USART_CR2_LBDL_POS)                   /**< 0x00000020 */
#define USART_CR2_LBDL                 USART_CR2_LBDL_MASK                             /**< LIN bus break frame detection length */
#define USART_CR2_LBDIE_POS            (6U)                                        
#define USART_CR2_LBDIE_MASK           (0x1UL << USART_CR2_LBDIE_POS)                  /**< 0x00000040 */
#define USART_CR2_LBDIE                USART_CR2_LBDIE_MASK                            /**< LIN bus break frame detection interrupt enable */
#define USART_CR2_CPHA_POS             (9U)                                        
#define USART_CR2_CPHA_MASK            (0x1UL << USART_CR2_CPHA_POS)                   /**< 0x00000200 */
#define USART_CR2_CPHA                 USART_CR2_CPHA_MASK                             /**< Clock Phase */
#define USART_CR2_CPOL_POS             (10U)                                       
#define USART_CR2_CPOL_MASK            (0x1UL << USART_CR2_CPOL_POS)                   /**< 0x00000400 */
#define USART_CR2_CPOL                 USART_CR2_CPOL_MASK                             /**< Clock polarity */
#define USART_CR2_CLKEN_POS            (11U)                                       
#define USART_CR2_CLKEN_MASK           (0x1UL << USART_CR2_CLKEN_POS)                  /**< 0x00000800 */
#define USART_CR2_CLKEN                USART_CR2_CLKEN_MASK                            /**< Clock enable */
                          
#define USART_CR2_STOPBIT_POS          (12U)                                       
#define USART_CR2_STOPBIT_MASK         (0x3UL << USART_CR2_STOPBIT_POS)                /**< 0x00003000 */
#define USART_CR2_STOPBIT              USART_CR2_STOPBIT_MASK                          /**< STOP[1:0] bits (STOP bits) */
                          
#define USART_CR2_STOPBIT_1            (0x0UL << USART_CR2_STOPBIT_POS)                /**< 0x00000000 */
#define USART_CR2_STOPBIT_0_5          (0x1UL << USART_CR2_STOPBIT_POS)                /**< 0x00001000 */
#define USART_CR2_STOPBIT_2            (0x2UL << USART_CR2_STOPBIT_POS)                /**< 0x00002000 */
#define USART_CR2_STOPBIT_1_5          (0x3UL << USART_CR2_STOPBIT_POS)                /**< 0x00003000 */
                          
#define USART_CR2_LINEN_POS            (14U)                                       
#define USART_CR2_LINEN_MASK           (0x1UL << USART_CR2_LINEN_POS)                  /**< 0x00004000 */
#define USART_CR2_LINEN                USART_CR2_LINEN_MASK                            /**< LIN bus enable */
#define USART_CR2_SWAP_POS             (15U)                                       
#define USART_CR2_SWAP_MASK            (0x1UL << USART_CR2_SWAP_POS)                   /**< 0x00008000 */
#define USART_CR2_SWAP                 USART_CR2_SWAP_MASK                             /**< SWAP TX/RX pins */
#define USART_CR2_RXIVC_POS            (16U)                                       
#define USART_CR2_RXIVC_MASK           (0x1UL << USART_CR2_RXIVC_POS)                  /**< 0x00010000 */
#define USART_CR2_RXIVC                USART_CR2_RXIVC_MASK                            /**< RX pin active level inversion */
#define USART_CR2_TXIVC_POS            (17U)                                       
#define USART_CR2_TXIVC_MASK           (0x1UL << USART_CR2_TXIVC_POS)                  /**< 0x00020000 */
#define USART_CR2_TXIVC                USART_CR2_TXIVC_MASK                            /**< TX pin active level inversion */
#define USART_CR2_DATAIVC_POS          (18U)                                       
#define USART_CR2_DATAIVC_MASK         (0x1UL << USART_CR2_DATAIVC_POS)                /**< 0x00040000 */
#define USART_CR2_DATAIVC              USART_CR2_DATAIVC_MASK                          /**< Binary data inversion */
#define USART_CR2_MSBFIRST_POS         (19U)                                       
#define USART_CR2_MSBFIRST_MASK        (0x1UL << USART_CR2_MSBFIRST_POS)               /**< 0x00080000 */
#define USART_CR2_MSBFIRST             USART_CR2_MSBFIRST_MASK                         /**< Most significant bit first */
#define USART_CR2_RTOEN_POS            (23U)                                       
#define USART_CR2_RTOEN_MASK           (0x1UL << USART_CR2_RTOEN_POS)                  /**< 0x00800000 */
#define USART_CR2_RTOEN                USART_CR2_RTOEN_MASK                            /**< Receive timeout enable */
#define USART_CR2_ADDR_POS             (24U)                                       
#define USART_CR2_ADDR_MASK            (0xFFUL << USART_CR2_ADDR_POS)                  /**< 0xFF000000 */
#define USART_CR2_ADDR                 USART_CR2_ADDR_MASK                             /**< Address of the USART node */
#define USART_CR2_LPUART_CMFD_POS      (24U)                                       
#define USART_CR2_LPUART_CMFD_MASK     (0xFFUL << USART_CR2_LPUART_CMFD_POS)           /**< 0xFF000000 */
#define USART_CR2_LPUART_CMFD          USART_CR2_LPUART_CMFD_MASK                      /**< Match Character of LPUART */
                          
/* Bits for USART_CR3 */                                                           
#define USART_CR3_EIE_POS              (0U)                                        
#define USART_CR3_EIE_MASK             (0x1UL << USART_CR3_EIE_POS)                    /**< 0x00000001 */
#define USART_CR3_EIE                  USART_CR3_EIE_MASK                              /**< Error interrupt enable */
#define USART_CR3_IREN_POS             (1U)                                        
#define USART_CR3_IREN_MASK            (0x1UL << USART_CR3_IREN_POS)                   /**< 0x00000002 */
#define USART_CR3_IREN                 USART_CR3_IREN_MASK                             /**< IrDA mode enable */
#define USART_CR3_IRLP_POS             (2U)                                        
#define USART_CR3_IRLP_MASK            (0x1UL << USART_CR3_IRLP_POS)                   /**< 0x00000004 */
#define USART_CR3_IRLP                 USART_CR3_IRLP_MASK                             /**< IrDA low power mode enable */
#define USART_CR3_HDEN_POS             (3U)                                        
#define USART_CR3_HDEN_MASK            (0x1UL << USART_CR3_HDEN_POS)                   /**< 0x00000008 */
#define USART_CR3_HDEN                 USART_CR3_HDEN_MASK                             /**< Half-Duplex selection */
#define USART_CR3_SCNAK_POS            (4U)                                        
#define USART_CR3_SCNAK_MASK           (0x1UL << USART_CR3_SCNAK_POS)                  /**< 0x00000010 */
#define USART_CR3_SCNAK                USART_CR3_SCNAK_MASK                            /**< SmartCard NACK selection */
#define USART_CR3_SCEN_POS             (5U)                                        
#define USART_CR3_SCEN_MASK            (0x1UL << USART_CR3_SCEN_POS)                   /**< 0x00000020 */
#define USART_CR3_SCEN                 USART_CR3_SCEN_MASK                             /**< SmartCard mode enable */
#define USART_CR3_DMAR_POS             (6U)                                        
#define USART_CR3_DMAR_MASK            (0x1UL << USART_CR3_DMAR_POS)                   /**< 0x00000040 */
#define USART_CR3_DMAR                 USART_CR3_DMAR_MASK                             /**< DMA enable receiver */
#define USART_CR3_DMAT_POS             (7U)                                        
#define USART_CR3_DMAT_MASK            (0x1UL << USART_CR3_DMAT_POS)                   /**< 0x00000080 */
#define USART_CR3_DMAT                 USART_CR3_DMAT_MASK                             /**< DMA enable transmitter */
#define USART_CR3_RTSE_POS             (8U)                                        
#define USART_CR3_RTSE_MASK            (0x1UL << USART_CR3_RTSE_POS)                   /**< 0x00000100 */
#define USART_CR3_RTSE                 USART_CR3_RTSE_MASK                             /**< RTS enable */
#define USART_CR3_CTSE_POS             (9U)                                        
#define USART_CR3_CTSE_MASK            (0x1UL << USART_CR3_CTSE_POS)                   /**< 0x00000200 */
#define USART_CR3_CTSE                 USART_CR3_CTSE_MASK                             /**< CTS enable */
#define USART_CR3_CTSIE_POS            (10U)                                       
#define USART_CR3_CTSIE_MASK           (0x1UL << USART_CR3_CTSIE_POS)                  /**< 0x00000400 */
#define USART_CR3_CTSIE                USART_CR3_CTSIE_MASK                            /**< CTS interrupt enable */
#define USART_CR3_OBS_POS              (11U)                                       
#define USART_CR3_OBS_MASK             (0x1UL << USART_CR3_OBS_POS)                    /**< 0x00000800 */
#define USART_CR3_OBS                  USART_CR3_OBS_MASK                              /**< One sample bit method enable */
#define USART_CR3_ORED_POS             (12U)                                       
#define USART_CR3_ORED_MASK            (0x1UL << USART_CR3_ORED_POS)                   /**< 0x00001000 */
#define USART_CR3_ORED                 USART_CR3_ORED_MASK                             /**< Overrun disable */
#define USART_CR3_DDRE_POS             (13U)                                       
#define USART_CR3_DDRE_MASK            (0x1UL << USART_CR3_DDRE_POS)                   /**< 0x00002000 */
#define USART_CR3_DDRE                 USART_CR3_DDRE_MASK                             /**< DMA disable on reception error */
#define USART_CR3_DEM_POS              (14U)                                       
#define USART_CR3_DEM_MASK             (0x1UL << USART_CR3_DEM_POS)                    /**< 0x00004000 */
#define USART_CR3_DEM                  USART_CR3_DEM_MASK                              /**< Driver enable mode */
#define USART_CR3_DEP_POS              (15U)                                       
#define USART_CR3_DEP_MASK             (0x1UL << USART_CR3_DEP_POS)                    /**< 0x00008000 */
#define USART_CR3_DEP                  USART_CR3_DEP_MASK                              /**< Driver enable polarity selection */
                          
#define USART_CR3_SCRETRY_POS          (17U)                                       
#define USART_CR3_SCRETRY_MASK         (0x07UL << USART_CR3_SCRETRY_POS)               /**< 0x000E0000 */
#define USART_CR3_SCRETRY              USART_CR3_SCRETRY_MASK                          /**< SmartCard Retry count */
                          
#define USART_CR3_SCRETRY_0            (0x01UL << USART_CR3_SCRETRY_POS)               /**< 0x00020000 */
#define USART_CR3_SCRETRY_1            (0x02UL << USART_CR3_SCRETRY_POS)               /**< 0x00040000 */
#define USART_CR3_SCRETRY_2            (0x04UL << USART_CR3_SCRETRY_POS)               /**< 0x00080000 */
                          
#define USART_CR3_LPWKS_POS            (20U)                                       
#define USART_CR3_LPWKS_MASK           (0x1UL << USART_CR3_LPWKS_POS)                  /**< 0x00100000 */
#define USART_CR3_LPWKS                USART_CR3_LPWKS_MASK                            /**< LPWKS bit (Wake up interrupt flag selection) */
                          
#define USART_CR3_LPWKIE_POS           (22U)                                       
#define USART_CR3_LPWKIE_MASK          (0x1UL << USART_CR3_LPWKIE_POS)                 /**< 0x00400000 */
#define USART_CR3_LPWKIE               USART_CR3_LPWKIE_MASK                           /**< Wake up interrupt enable */
                          
#define USART_CR3_TCBGTIE_POS          (24U)                                       
#define USART_CR3_TCBGTIE_MASK         (0x1UL << USART_CR3_TCBGTIE_POS)                /**< 0x01000000 */
#define USART_CR3_TCBGTIE              USART_CR3_TCBGTIE_MASK                          /**< Transfer complete before guardtime interrupt enable */
                          
/* Bits for USART_BRR */                                                           
#define USART_BRR_LPUART_POS           (0U)                                        
#define USART_BRR_LPUART_MASK          (0xFFFFFUL << USART_BRR_LPUART_POS)             /**< 0x000FFFFF */
#define USART_BRR_LPUART               USART_BRR_LPUART_MASK                           /**< LPUART baud rate register [19:0] */
#define USART_BRR_BRR                  ((uint16_t)0xFFFF)                              /**< USART  baud rate register [15:0] */
                          
/* Bits for USART_GTPR */                                                          
#define USART_GTPR_PSV_POS             (0U)                                        
#define USART_GTPR_PSV_MASK            (0xFFUL << USART_GTPR_PSV_POS)                  /**< 0x000000FF */
#define USART_GTPR_PSV                 USART_GTPR_PSV_MASK                             /**< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_POS              (8U)                                        
#define USART_GTPR_GT_MASK             (0xFFUL << USART_GTPR_GT_POS)                   /**< 0x0000FF00 */
#define USART_GTPR_GT                  USART_GTPR_GT_MASK                              /**< GT[7:0] bits (Guard time value) */
                          
/* Bits for USART_RQR */                                                           
#define USART_RQR_BKSENDQ_POS          (1U)                                        
#define USART_RQR_BKSENDQ_MASK         (0x1UL << USART_RQR_BKSENDQ_POS)                /**< 0x00000002 */
#define USART_RQR_BKSENDQ              USART_RQR_BKSENDQ_MASK                          /**< Send break request */
#define USART_RQR_MUTEQ_POS            (2U)                                        
#define USART_RQR_MUTEQ_MASK           (0x1UL << USART_RQR_MUTEQ_POS)                  /**< 0x00000004 */
#define USART_RQR_MUTEQ                USART_RQR_MUTEQ_MASK                            /**< Enter mute mode request */
#define USART_RQR_RXFLUQ_POS           (3U)                                        
#define USART_RQR_RXFLUQ_MASK          (0x1UL << USART_RQR_RXFLUQ_POS)                 /**< 0x00000008 */
#define USART_RQR_RXFLUQ               USART_RQR_RXFLUQ_MASK                           /**< Receive data flush request */
#define USART_RQR_TXFLUQ_POS           (4U)                                        
#define USART_RQR_TXFLUQ_MASK          (0x1UL << USART_RQR_TXFLUQ_POS)                 /**< 0x00000010 */
#define USART_RQR_TXFLUQ               USART_RQR_TXFLUQ_MASK                           /**< Transmit data flush request */
                          
/* Bits for USART_RTO */                                                           
#define USART_RTO_RTOV_POS             (0U)                                        
#define USART_RTO_RTOV_MASK            (0xFFFFFFUL << USART_RTO_RTOV_POS)              /**< 0x00FFFFFF */
#define USART_RTO_RTOV                 USART_RTO_RTOV_MASK                             /**< Receiver timeout Value */
#define USART_RTO_BLKN_POS             (24U)                                       
#define USART_RTO_BLKN_MASK            (0xFFUL << USART_RTO_BLKN_POS)                  /**< 0xFF000000 */
#define USART_RTO_BLKN                 USART_RTO_BLKN_MASK                             /**< Block Length */
                          
/* Bits for USART_ISR */
#define USART_ISR_PE_POS               (0U)
#define USART_ISR_PE_MASK              (0x1UL << USART_ISR_PE_POS)                     /**< 0x00000001 */
#define USART_ISR_PE                   USART_ISR_PE_MASK                               /**< Parity error */
#define USART_ISR_FE_POS               (1U)                                          
#define USART_ISR_FE_MASK              (0x1UL << USART_ISR_FE_POS)                     /**< 0x00000002 */
#define USART_ISR_FE                   USART_ISR_FE_MASK                               /**< Framing error */
#define USART_ISR_NOISE_POS            (2U)                                          
#define USART_ISR_NOISE_MASK           (0x1UL << USART_ISR_NOISE_POS)                  /**< 0x00000004 */
#define USART_ISR_NOISE                USART_ISR_NOISE_MASK                            /**< Noise detected flag */
#define USART_ISR_ORE_POS              (3U)                                          
#define USART_ISR_ORE_MASK             (0x1UL << USART_ISR_ORE_POS)                    /**< 0x00000008 */
#define USART_ISR_ORE                  USART_ISR_ORE_MASK                              /**< OverRun error */
#define USART_ISR_IDLE_POS             (4U)                                          
#define USART_ISR_IDLE_MASK            (0x1UL << USART_ISR_IDLE_POS)                   /**< 0x00000010 */
#define USART_ISR_IDLE                 USART_ISR_IDLE_MASK                             /**< IDLE line detected */
#define USART_ISR_RXNE_POS             (5U)                                          
#define USART_ISR_RXNE_MASK            (0x1UL << USART_ISR_RXNE_POS)                   /**< 0x00000020 */
#define USART_ISR_RXNE                 USART_ISR_RXNE_MASK                             /**< Read data register not empty */
#define USART_ISR_TC_POS               (6U)                                          
#define USART_ISR_TC_MASK              (0x1UL << USART_ISR_TC_POS)                     /**< 0x00000040 */
#define USART_ISR_TC                   USART_ISR_TC_MASK                               /**< Transmission complete */
#define USART_ISR_TXE_POS              (7U)                                          
#define USART_ISR_TXE_MASK             (0x1UL << USART_ISR_TXE_POS)                    /**< 0x00000080 */
#define USART_ISR_TXE                   USART_ISR_TXE_MASK                             /**< Transmit data register empty */
#define USART_ISR_LBD_POS              (8U)                                          
#define USART_ISR_LBD_MASK             (0x1UL << USART_ISR_LBD_POS)                    /**< 0x00000200 */
#define USART_ISR_LBD                   USART_ISR_LBD_MASK                             /**< Break Frame detected interrupt flag */
#define USART_ISR_CTSIF_POS            (9U)                                          
#define USART_ISR_CTSIF_MASK           (0x1UL << USART_ISR_CTSIF_POS)                  /**< 0x00000200 */
#define USART_ISR_CTSIF                USART_ISR_CTSIF_MASK                            /**< CTS interrupt flag */
#define USART_ISR_CTS_POS              (10U)                                         
#define USART_ISR_CTS_MASK             (0x1UL << USART_ISR_CTS_POS)                    /**< 0x00000400 */
#define USART_ISR_CTS                  USART_ISR_CTS_MASK                              /**< CTS flag */
#define USART_ISR_RTOF_POS             (11U)                                         
#define USART_ISR_RTOF_MASK            (0x1UL << USART_ISR_RTOF_POS)                   /**< 0x00000800 */
#define USART_ISR_RTOF                 USART_ISR_RTOF_MASK                             /**< Receive timeout flag */
#define USART_ISR_EBF_POS              (12U)                                         
#define USART_ISR_EBF_MASK             (0x1UL << USART_ISR_EBF_POS)                    /**< 0x00001000 */
#define USART_ISR_EBF                  USART_ISR_EBF_MASK                              /**< End of Block flag */
#define USART_ISR_BUSY_POS             (16U)                                         
#define USART_ISR_BUSY_MASK            (0x1UL << USART_ISR_BUSY_POS)                   /**< 0x00010000 */
#define USART_ISR_BUSY                 USART_ISR_BUSY_MASK                             /**< Busy flag */
#define USART_ISR_CMF_POS              (17U)                                         
#define USART_ISR_CMF_MASK             (0x1UL << USART_ISR_CMF_POS)                    /**< 0x00020000 */
#define USART_ISR_CMF                  USART_ISR_CMF_MASK                              /**< Character match flag */
#define USART_ISR_BKSEND_POS           (18U)                                         
#define USART_ISR_BKSEND_MASK          (0x1UL << USART_ISR_BKSEND_POS)                 /**< 0x00040000 */
#define USART_ISR_BKSEND               USART_ISR_BKSEND_MASK                           /**< Send break flag */
#define USART_ISR_RWU_POS              (19U)                                         
#define USART_ISR_RWU_MASK             (0x1UL << USART_ISR_RWU_POS)                    /**< 0x00080000 */
#define USART_ISR_RWU                  USART_ISR_RWU_MASK                              /**< Receive wake up from mute mode flag */
#define USART_ISR_LPWK_POS             (20U)                                         
#define USART_ISR_LPWK_MASK            (0x1UL << USART_ISR_LPWK_POS)                   /**< 0x00100000 */
#define USART_ISR_LPWK                 USART_ISR_LPWK_MASK                             /**< Wake up from stop mode flag */
#define USART_ISR_TEACK_POS            (21U)                                         
#define USART_ISR_TEACK_MASK           (0x1UL << USART_ISR_TEACK_POS)                  /**< 0x00200000 */
#define USART_ISR_TEACK                USART_ISR_TEACK_MASK                            /**< Transmit enable acknowledge flag */
#define USART_ISR_REACK_POS            (22U)                                         
#define USART_ISR_REACK_MASK           (0x1UL << USART_ISR_REACK_POS)                  /**< 0x00400000 */
#define USART_ISR_REACK                USART_ISR_REACK_MASK                            /**< Receive enable acknowledge flag */
#define USART_ISR_TCBGT_POS            (25U)                                         
#define USART_ISR_TCBGT_MASK           (0x1UL << USART_ISR_TCBGT_POS)                  /**< 0x02000000 */
#define USART_ISR_TCBGT                USART_ISR_TCBGT_MASK                            /**< Transfer complete before Guardtime flag */
                        
/* Bits for USART_ICR */                                                             
#define USART_ICR_PECF_POS             (0U)                                          
#define USART_ICR_PECF_MASK            (0x1UL << USART_ICR_PECF_POS)                   /**< 0x00000001 */
#define USART_ICR_PECF                 USART_ICR_PECF_MASK                             /**< Parity error clear flag */
#define USART_ICR_FECF_POS             (1U)                                          
#define USART_ICR_FECF_MASK            (0x1UL << USART_ICR_FECF_POS)                   /**< 0x00000002 */
#define USART_ICR_FECF                 USART_ICR_FECF_MASK                             /**< Framing error clear flag */
#define USART_ICR_NOISECF_POS          (2U)                                          
#define USART_ICR_NOISECF_MASK         (0x1UL << USART_ICR_NOISECF_POS)                /**< 0x00000004 */
#define USART_ICR_NOISECF              USART_ICR_NOISECF_MASK                          /**< Noise error detected clear flag */
#define USART_ICR_ORECF_POS            (3U)                                          
#define USART_ICR_ORECF_MASK           (0x1UL << USART_ICR_ORECF_POS)                  /**< 0x00000008 */
#define USART_ICR_ORECF                USART_ICR_ORECF_MASK                            /**< OverRun error clear flag*/
#define USART_ICR_IDLECF_POS           (4U)                                          
#define USART_ICR_IDLECF_MASK          (0x1UL << USART_ICR_IDLECF_POS)                 /**< 0x00000010 */
#define USART_ICR_IDLECF               USART_ICR_IDLECF_MASK                           /**< IDLE line detected clear flag */
#define USART_ICR_TCCF_POS             (6U)                                          
#define USART_ICR_TCCF_MASK            (0x1UL << USART_ICR_TCCF_POS)                   /**< 0x00000040 */
#define USART_ICR_TCCF                 USART_ICR_TCCF_MASK                             /**< Transmission complete clear flag */
#define USART_ICR_TCBGTCF_POS          (7U)                                          
#define USART_ICR_TCBGTCF_MASK         (0x1UL << USART_ICR_TCBGTCF_POS)                /**< 0x00000080 */
#define USART_ICR_TCBGTCF              USART_ICR_TCBGTCF_MASK                          /**< Transfer complete before guardtime clear flag */
#define USART_ICR_LBDCF_POS            (8U)                                          
#define USART_ICR_LBDCF_MASK           (0x1UL << USART_ICR_LBDCF_POS)                  /**< 0x00000100 */
#define USART_ICR_LBDCF                USART_ICR_LBDCF_MASK                            /**< Break Frame Detected clear flag */
#define USART_ICR_CTSCF_POS            (9U)                                          
#define USART_ICR_CTSCF_MASK           (0x1UL << USART_ICR_CTSCF_POS)                  /**< 0x00000200 */
#define USART_ICR_CTSCF                USART_ICR_CTSCF_MASK                            /**< CTS interrupt clear flag */
#define USART_ICR_RTOCF_POS            (11U)                                         
#define USART_ICR_RTOCF_MASK           (0x1UL << USART_ICR_RTOCF_POS)                  /**< 0x00000800 */
#define USART_ICR_RTOCF                USART_ICR_RTOCF_MASK                            /**< Receive timeout clear flag */
#define USART_ICR_EBCF_POS             (12U)                                         
#define USART_ICR_EBCF_MASK            (0x1UL << USART_ICR_EBCF_POS)                   /**< 0x00001000 */
#define USART_ICR_EBCF                 USART_ICR_EBCF_MASK                             /**< End of block clear flag */
#define USART_ICR_CMCF_POS             (17U)                                         
#define USART_ICR_CMCF_MASK            (0x1UL << USART_ICR_CMCF_POS)                   /**< 0x00020000 */
#define USART_ICR_CMCF                 USART_ICR_CMCF_MASK                             /**< Character match clear flag */
#define USART_ICR_LPWKCF_POS           (20U)                                         
#define USART_ICR_LPWKCF_MASK          (0x1UL << USART_ICR_LPWKCF_POS)                 /**< 0x00100000 */
#define USART_ICR_LPWKCF               USART_ICR_LPWKCF_MASK                           /**< Wake up from stop mode clear flag */
                        
/* Bits for USART_RDR */                                                             
#define USART_RDR_RDR_POS              (0U)                                          
#define USART_RDR_RDR_MASK             (0x1FFUL << USART_RDR_RDR_POS)                  /**< 0x000001FF */
#define USART_RDR_RDR                  USART_RDR_RDR_MASK                              /**< RDR[8:0] bits (Receive data value) */
                        
/* Bits for USART_TDR */                                                             
#define USART_TDR_TDR_POS              (0U)                                          
#define USART_TDR_TDR_MASK             (0x1FFUL << USART_TDR_TDR_POS)                  /**< 0x000001FF */
#define USART_TDR_TDR                  USART_TDR_TDR_MASK                              /**< TDR[8:0] bits (Transmit data value) */
                        
/* Bits for USART_PRESC */                                                           
#define USART_PRESC_PRESCALER_POS      (0U)                                          
#define USART_PRESC_PRESCALER_MASK     (0xFUL << USART_PRESC_PRESCALER_POS)            /**< 0x0000000F */
#define USART_PRESC_PRESCALER          USART_PRESC_PRESCALER_MASK                      /**< PRESCALER[3:0] bits (Clock prescaler) */

/*-----------------------------------------------------------------------------------------------
                                       VREFBUF Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for VREFBUF_CSR */
#define VREFBUF_CSR_EN_POS             (0U)
#define VREFBUF_CSR_EN_MASK            (0x1UL << VREFBUF_CSR_EN_POS)             /**< 0x00000001 */
#define VREFBUF_CSR_EN                 VREFBUF_CSR_EN_MASK                       /**< Voltage reference buffer enable */

#define VREFBUF_CSR_VRS_POS            (2U)
#define VREFBUF_CSR_VRS_MASK           (0x3UL << VREFBUF_CSR_VRS_POS)            /**< 0x0000000C */
#define VREFBUF_CSR_VRS                VREFBUF_CSR_VRS_MASK                      /**< Voltage reference output */
#define VREFBUF_CSR_VRS_2048           (0x0UL << VREFBUF_CSR_VRS_POS)            /**< 0x00000000 */
#define VREFBUF_CSR_VRS_2500           (0x1UL << VREFBUF_CSR_VRS_POS)            /**< 0x00000004 */ 
#define VREFBUF_CSR_VRS_3000           (0x2UL << VREFBUF_CSR_VRS_POS)            /**< 0x00000008 */

#define VREFBUF_CSR_RDY_POS            (4U)
#define VREFBUF_CSR_RDY_MASK           (0x1UL << VREFBUF_CSR_RDY_POS)            /**< 0x00000010 */
#define VREFBUF_CSR_RDY                VREFBUF_CSR_RDY_MASK                      /**< Voltage reference buffer ready */

/*-----------------------------------------------------------------------------------------------
                                       WWDG Registers Bits  
------------------------------------------------------------------------------------------------*/
/* Bits for WWDG_CR */
#define WWDG_CR_CNT_POS                (0U)
#define WWDG_CR_CNT_MASK               (0x7FUL << WWDG_CR_CNT_POS)               /**< 0x0000007F */
#define WWDG_CR_CNT                    WWDG_CR_CNT_MASK                          /**< CNT[6:0] bits (7-Bit counter (MSB to LSB)) */

#define WWDG_CR_WDGEN_POS              (7U)
#define WWDG_CR_WDGEN_MASK             (0x1UL << WWDG_CR_WDGEN_POS)              /**< 0x00000080 */
#define WWDG_CR_WDGEN                  WWDG_CR_WDGEN_MASK                        /**< Activation bit */

/* Bits for WWDG_CFG */
#define WWDG_CFG_WIN_POS               (0U)
#define WWDG_CFG_WIN_MASK              (0x7FUL << WWDG_CFG_WIN_POS)              /**< 0x0000007F */
#define WWDG_CFG_WIN                   WWDG_CFG_WIN_MASK                         /**< WIN[6:0] bits (7-bit window value) */

#define WWDG_CFG_EWI_POS               (9U)
#define WWDG_CFG_EWI_MASK              (0x1UL << WWDG_CFG_EWI_POS)               /**< 0x00000200 */
#define WWDG_CFG_EWI                   WWDG_CFG_EWI_MASK                         /**< Early wakeup interrupt */

#define WWDG_CFG_WDGPR_POS             (11U)
#define WWDG_CFG_WDGPR_MASK            (0x7UL << WWDG_CFG_WDGPR_POS)             /**< 0x00003800 */
#define WWDG_CFG_WDGPR                 WWDG_CFG_WDGPR_MASK                       /**< WDGPR[2:0] bits (Timer bse) */
#define WWDG_CFG_WDGPR_DIV1            (0x0UL << WWDG_CFG_WDGPR_POS)             /**< 0x00000000 */
#define WWDG_CFG_WDGPR_DIV2            (0x1UL << WWDG_CFG_WDGPR_POS)             /**< 0x00000800 */
#define WWDG_CFG_WDGPR_DIV4            (0x2UL << WWDG_CFG_WDGPR_POS)             /**< 0x00001000 */
#define WWDG_CFG_WDGPR_DIV8            (0x3UL << WWDG_CFG_WDGPR_POS)             /**< 0x00001800 */
#define WWDG_CFG_WDGPR_DIV16           (0x4UL << WWDG_CFG_WDGPR_POS)             /**< 0x00002000 */
#define WWDG_CFG_WDGPR_DIV32           (0x5UL << WWDG_CFG_WDGPR_POS)             /**< 0x00002800 */
#define WWDG_CFG_WDGPR_DIV64           (0x6UL << WWDG_CFG_WDGPR_POS)             /**< 0x00003000 */
#define WWDG_CFG_WDGPR_DIV128          (0x7UL << WWDG_CFG_WDGPR_POS)             /**< 0x00003800 */

/* Bits for WWDG_SR */
#define WWDG_SR_EWIF_POS               (0U)
#define WWDG_SR_EWIF_MASK              (0x1UL << WWDG_SR_EWIF_POS)               /**< 0x00000001 */
#define WWDG_SR_EWIF                   WWDG_SR_EWIF_MASK                         /**< Early wakeup interrupt flag */

                                            

/**
* @}
*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
* @}
*/

/**
* @}
*/

#endif /* CIU32L051_H */

