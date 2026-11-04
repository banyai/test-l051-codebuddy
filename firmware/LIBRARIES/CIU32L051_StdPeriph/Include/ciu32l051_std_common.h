/************************************************************************************************/
/**
* @file               ciu32l051_std_common.h
* @author             MCU Ecosystem Development Team
* @brief              STD库通用的相关定义。  
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_COMMON_H
#define CIU32L051_STD_COMMON_H

/************************************************************************************************/
/**
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @addtogroup STD
* @{
*
*/
/************************************************************************************************/ 


#ifdef __cplusplus
extern "C" {
#endif


       
/*-----------------------------------------type define------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup STD_Types STD Types
* @brief STD库通用数据类型定义
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  bit位状态定义
*/
typedef enum
{
    RESET = 0,
    SET = !RESET
}bit_status_t;


/**
* @brief  STD库API返回值类型定义
*/
typedef enum
{
    STD_OK                   = 0x00U,
    STD_ERR                  = 0x01U,
    STD_ERR_PARAM            = 0x02U,
    STD_ERR_BUSY             = 0x03U,
    STD_ERR_TIMEOUT          = 0x04U
} std_status_t;


/**
* @}
*/
  

/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup STD_Constants 
* @{
*
*/
/************************************************************************************************/ 

/* 避免编译警告 */
#define UNUSED(X) (void)X      


/* 编译器差异化定义 */
#if  defined ( __GNUC__ )
    #ifndef __weak
        #define __weak   __attribute__((weak))
    #endif /* __weak */
    
    #ifndef __packed
        #define __packed __attribute__((__packed__))
    #endif /* __packed */
#endif /* __GNUC__ */


/* bit operations */
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  ((REG) = (((REG) & (~(CLEARMASK))) | (SETMASK)))

/** 
* @} 
*/
                                    
                                    
/*------------------------------------------includes--------------------------------------------*/
#include <stddef.h>
#include <stdbool.h>
#include "ciu32l051.h"
#include "ciu32l051_std.h"


/*-------------------------------------------functions------------------------------------------*/

                                    
#ifdef __cplusplus
}
#endif


/**
* @} 
*/  

/**
* @}
*/


#endif /* CIU32L051_STD_COMMON_H */
