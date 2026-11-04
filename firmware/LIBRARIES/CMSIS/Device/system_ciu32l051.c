/************************************************************************************************/
/**
* @file               system_ciu32l051.c
* @author             MCU Ecosystem Development Team
* @brief              CMSIS Device System Source File for CIU32L051.                            
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/************************************************************************************************/
/**
* @addtogroup CMSIS
* @{
*
* @addtogroup Device_System  Device System
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051.h"


/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup Device_System_Constants Device System Constants
* @{
*/
/************************************************************************************************/
                                                   
#if !defined  (HXTAL_VALUE)  
    #define HXTAL_VALUE    (8000000UL)      /**<  HXTAL clock frequency(Hz) */
#endif 

#if !defined  (LXTAL_VALUE)
    #define LXTAL_VALUE    (32768UL)        /**< LXTAL clock frequency(Hz) */
#endif 


#if !defined  (RCH_VALUE)
    #define RCH_VALUE      (16000000UL)     /**< RCH clock frequency(Hz) */
#endif 

#if !defined  (RCL_VALUE)
    #define RCL_VALUE      (32000UL)        /**< RCL clock frequency(Hz) */
#endif 

/** 
* @} 
*/

/*--------------------------------------------variables-----------------------------------------*/
/* The SystemCoreClock variable is the system core clock(HCLK) frequency.*/
uint32_t SystemCoreClock = RCH_VALUE;

const uint32_t g_ahb_divider_table[8] = {1UL, 2UL, 4UL, 8UL, 16UL, 32UL, 64UL, 128UL};
const uint32_t g_apb_divider_table[8] = {1UL, 1UL, 1UL, 1UL, 2UL, 4UL, 8UL, 16UL};


#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
    extern uint32_t __vector_table;
#endif



/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup Device_System_External_Functions 
* @{
*
*/
/************************************************************************************************/
/**
* @brief  MCU system initialization function
* @retval None
*/
void SystemInit(void)
{
    /* Configure the vector table location add offset address */
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
    SCB->VTOR = (uint32_t) &__vector_table; 
#endif
    
    SystemCoreClock = RCH_VALUE;
}

/**
* @brief  System core clock(HCLK) update function
*
* @note   This function is used to update the variable SystemCoreClock 
*         and must be called whenever HCLK is changed
* @retval None
*/
void SystemCoreClockUpdate(void)
{
    uint32_t tmp,tmp_clock;
    uint32_t pllsource;
    uint32_t pllm,plln,plldiv;
    uint32_t rchdiv;


    /* Get SYSCLK source */
    switch (RCC->CFG & RCC_CFG_SYSWS_MASK)
    {
        case RCC_CFG_SYSWS_HXTAL:  /* HXTAL used as system clock */
        {
            tmp_clock = HXTAL_VALUE;
        }break;
        
        case RCC_CFG_SYSWS_LXTAL:  /* LXTAL used as system clock */
        {
            tmp_clock = LXTAL_VALUE;
        }break;
        
        case RCC_CFG_SYSWS_RCL:    /* RCL used as system clock */
        {
            tmp_clock = RCL_VALUE;
        }break;
        
        case RCC_CFG_SYSWS_PLL:  /* PLL used as system clock */
        {
            pllsource = (RCC->PLLCFG & RCC_PLLCFG_PLLSRC_MASK);
            
            if(RCC_PLLCFG_PLLSRC_HXTAL == pllsource)
            {
                tmp = HXTAL_VALUE;
            }
            else if(RCC_PLLCFG_PLLSRC_RCH == pllsource)
            {
                tmp = RCH_VALUE;
            }
            else
            {
                tmp = 0;
            }
            
            pllm = (RCC->PLLCFG & RCC_PLLCFG_PLLM_MASK)>>RCC_PLLCFG_PLLM_POS;
            plln = (RCC->PLLCFG & RCC_PLLCFG_PLLN_MASK)>>RCC_PLLCFG_PLLN_POS;
            
            if(pllm == 0)
            {
                pllm = 32;
            }
            
            if(plln == 0)
            {
                plln = 8;
            }

            tmp = tmp*pllm/plln;
            
            plldiv = (RCC->PLLCFG & RCC_PLLCFG_PLLDIV_MASK)>>RCC_PLLCFG_PLLDIV_POS;
                        
            tmp_clock = tmp/(1UL<<plldiv);
        }break;
      
        case RCC_CFG_SYSWS_RCHSYS:  /* RCH used as system clock */
        default:                    /* RCH used as system clock */
        {
            rchdiv = (1UL << ((RCC->CSR1 & (RCC_CSR1_RCHDIV_MASK))>> RCC_CSR1_RCHDIV_POS));
            tmp_clock = (RCH_VALUE/rchdiv);
        }break;
    }
        
    /* Compute HCLK clock frequency */
    tmp = g_ahb_divider_table[((RCC->CFG & RCC_CFG_HPRE_MASK) >> RCC_CFG_HPRE_POS)];

    SystemCoreClock = tmp_clock/tmp;
}


/** 
* @} 
*/

/** 
* @} 
*/

/** 
* @} 
*/

