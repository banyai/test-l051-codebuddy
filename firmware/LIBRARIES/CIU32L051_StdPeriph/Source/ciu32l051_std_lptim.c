/************************************************************************************************/
/**
* @file               ciu32l051_std_lptim.c
* @author             MCU Ecosystem Development Team
* @brief              LPTIM STD库驱动。
*                     实现LPTIM初始化等API。
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
* @addtogroup LPTIM 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_LPTIM_PERIPHERAL_USED


/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup LPTIM_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  LPTIM初始化
* @param  lptimx LPTIM外设
* @param  lptim_init_param LPTIM初始化结构体指针
* @retval 无
*/
void std_lptim_init(LPTIM_t *lptimx, std_lptim_init_t *lptim_init_param)
{
    /* 设置工作时钟     */
    /* 设置时钟分频系数 */
    /* 设置输出波形极性 */
    /* 设置计数时钟源   */
    MODIFY_REG(lptimx->CFG, (LPTIM_CFG_CKSEL | LPTIM_CFG_PRESC | LPTIM_CFG_COUNT_MODE | LPTIM_CFG_WAVPOL),
                            (lptim_init_param->clock_source | lptim_init_param->prescaler | lptim_init_param->count_source | lptim_init_param->out_polarity));
    
}

/**
* @brief  LPTIM去初始化
* @param  lptimx LPTIM外设
* @retval 无
*/
void std_lptim_deinit(LPTIM_t *lptimx)
{
    if (lptimx == LPTIM1)
    {
        /* 复位LPTIM1并关闭时钟 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_LPTIM1);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_LPTIM1);
    }
    else if (lptimx == LPTIM2)
    {
        /* 复位LPTIM2并关闭时钟 */
        std_rcc_apb1_reset(RCC_PERIPH_RESET_LPTIM2);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_LPTIM2);
    }
    else
    {
        /* 无操作 */
    }
}

/**
* @brief  设置std_lptim_init_t结构体成员变量为默认值
* @param  lptim_init_struct 初始化结构体指针
* @retval 无
*/
void std_lptim_struct_init(std_lptim_init_t *lptim_init_struct)
{
    lptim_init_struct->clock_source = LPTIM_CLK_SRC_INT;
    lptim_init_struct->prescaler = LPTIM_PRESCALER_DIV1;
    lptim_init_struct->count_source = LPTIM_COUNTER_CLK_INT;
    lptim_init_struct->out_polarity = LPTIM_OUTPUT_POLARITY_REGULAR;
}

/** 
* @} 
*/

#endif /* STD_LPTIM_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
