/************************************************************************************************/
/**
* @file               system_ciu32l051.h
* @author             MCU Ecosystem Development Team
* @brief              CMSIS Device System Header File for CIU32L051.  
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

#ifndef SYSTEM_CIU32L051_H
#define SYSTEM_CIU32L051_H  


/************************************************************************************************/
/** 
* @addtogroup CMSIS
* @{
*/

/**
* @defgroup Device_System Device System
* @{
*/
/************************************************************************************************/

#ifdef __cplusplus
 extern "C" {
#endif


/*--------------------------------------------variables-----------------------------------------*/
/************************************************************************************************/
/**
* @defgroup Device_System_Variables Device System Variables
* @{
*/
/************************************************************************************************/

extern uint32_t SystemCoreClock;               /**< system core clock(HCLK) frequency  */
extern const uint32_t g_ahb_divider_table[8];  /**< AHB prescalers table values */
extern const uint32_t g_apb_divider_table[8];  /**< APB prescalers table values */
/**
* @}
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup Device_System_External_Functions  Device System External Functions
* @{
*/
/************************************************************************************************/

void SystemInit(void);
void SystemCoreClockUpdate(void);

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


#endif /*SYSTEM_CIU32L051_H */

