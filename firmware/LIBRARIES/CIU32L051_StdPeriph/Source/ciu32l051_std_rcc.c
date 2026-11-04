/************************************************************************************************/
/**
* @file               ciu32l051_std_rcc.c
* @author             MCU Ecosystem Development Team
* @brief              RCC STD库驱动。
*                     实现RCC时钟频率获取等API。
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
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @addtogroup RCC 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup RCC_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  获取当前系统时钟频率（SYSCLK）
* @retval 返回系统时钟频率（Hz）
*/
uint32_t std_rcc_get_sysclkfreq(void)
{
    uint32_t frequency = 0;
    uint32_t tmp = 0;
    
    /* 获取当前系统时钟源 */
    switch(std_rcc_get_sysclk_source())
    {
        /* 系统时钟为HXTAL，HXTAL默认8MHz */
        case RCC_SYSCLK_SRC_STATUS_HXTAL:
        {
            frequency = HXTAL_VALUE;
        }break;
        
        /* 系统时钟为PLL */
        case RCC_SYSCLK_SRC_STATUS_PLLCLK:
        {
            frequency = std_rcc_get_pllfreq();
        }break;
        
        /* 系统时钟为RCL */
        case RCC_SYSCLK_SRC_STATUS_RCL:
        {
            frequency = RCL_VALUE;
        }break;
        
        /* 系统时钟为LXTAL */
        case RCC_SYSCLK_SRC_STATUS_LXTAL:
        {
            frequency = LXTAL_VALUE;
        }break;
        
        /* 系统时钟为RCHSYS */
        case RCC_SYSCLK_SRC_STATUS_RCHSYS:
        default:
        {
            tmp = (1UL << ((RCC->CSR1 & (RCC_CSR1_RCHDIV_MASK))>> RCC_CSR1_RCHDIV_POS));
            frequency = RCH_VALUE/tmp;
        }break;
    }
    return frequency;
}

/**
* @brief  获取PLL时钟频率（SYSCLK）
* @retval 返回PLL时钟频率（Hz）
*/
uint32_t std_rcc_get_pllfreq(void)
{
    uint32_t frequency = 0;
    uint32_t tmp = 0;
    uint32_t pllm, plln, plldiv;
    
    /* 获取当前系统时钟源 */
    if(std_rcc_get_pllsource() == RCC_PLLSRC_HXTAL)
    {      
        /* PLL时钟源为HXTAL */
         tmp = HXTAL_VALUE;
    }
    else
    {   
        /* PLL时钟源为RCH */
        tmp = RCH_VALUE;
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
    frequency = tmp/(1UL<<plldiv);
    
    return frequency;
}

/**
* @brief  获取AHB时钟频率（HCLK）
* @retval 返回HCLK时钟频率（Hz）
*/
uint32_t std_rcc_get_hclkfreq(void)
{
    uint32_t frequency = 0;
    uint32_t tmp, hclk_div;
    
    tmp = std_rcc_get_sysclkfreq();
    
    /* 获取AHB分频因子 */
    hclk_div = std_rcc_get_ahbdiv()>>RCC_CFG_HPRE_POS;
    frequency = tmp >> hclk_div;    

    return frequency;
}

/**
* @brief  获取APB1时钟频率（PCLK1）
* @retval 返回PCLK1时钟频率（Hz）
*/
uint32_t std_rcc_get_pclk1freq(void)
{
    uint32_t frequency = 0;
    uint32_t tmp, pclk1_div;
    
    tmp = std_rcc_get_hclkfreq();
    
    /* 获取APB1分频因子 */
    pclk1_div = std_rcc_get_apb1div()>>RCC_CFG_P1PRE_POS;
    
    if (pclk1_div < 3)
    {
        frequency = tmp;
    }
    else
    {
        pclk1_div -= 3;
        frequency = tmp >> pclk1_div;
    }
    
    return frequency;
}

/**
* @brief  获取APB2时钟频率（PCLK2）
* @retval 返回PCLK2时钟频率（Hz）
*/
uint32_t std_rcc_get_pclk2freq(void)
{
    uint32_t frequency = 0;
    uint32_t tmp, pclk2_div;
    
    tmp = std_rcc_get_hclkfreq();
    
    /* 获取APB2分频因子 */
    pclk2_div = std_rcc_get_apb2div()>>RCC_CFG_P2PRE_POS;

    if (pclk2_div < 3)
    {
        frequency = tmp;
    }
    else
    {
        pclk2_div -= 3;
        frequency = tmp >> pclk2_div;
    }    
    
    return frequency;
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
