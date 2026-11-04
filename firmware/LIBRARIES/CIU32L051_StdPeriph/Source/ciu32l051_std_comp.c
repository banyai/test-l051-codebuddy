/************************************************************************************************/
/**
* @file               ciu32l051_std_comp.c
* @author             MCU Ecosystem Development Team
* @brief              COMP STD库驱动。
*                     实现COMP初始化配置等功能API。
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
* @addtogroup COMP 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_COMP_PERIPHERAL_USED
/*------------------------------------------functions-------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup COMP_External_Functions 
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  COMP初始化
* @param  compx COMP外设
* @param  comp_init_param COMP初始化结构体
* @retval 无
*/
void std_comp_init(COMP_t *compx, std_comp_init_t *comp_init_param)
{
    /* 设置COMP正相输入 */
    std_comp_set_input_plus(compx, comp_init_param->inpsel);
    /* 设置COMP反相输入 */
    std_comp_set_input_minus(compx, comp_init_param->inmsel);
    /* 设置COMP响应速度 */
    std_comp_set_speed_mode(compx, comp_init_param->speed);
    /* 设置COMP迟滞模式 */
    std_comp_set_input_hysteresis(compx, comp_init_param->hyst);
    /* 输出极性配置 */
    std_comp_set_output_polarity(compx, comp_init_param->outpol);
}


/** 
* @brief  COMP结构体初始化
* @param  comp_init_struct COMP初始化结构体
* @retval 无
*/
void std_comp_struct_init(std_comp_init_t *comp_init_struct)
{
    comp_init_struct->inpsel = COMP_INPSEL_IO1;
    comp_init_struct->inmsel = COMP_INMSEL_VBGR;
    comp_init_struct->speed  = COMP_VERYLOWSPEED;
    comp_init_struct->hyst   = COMP_HYST_NONE;
    comp_init_struct->outpol = COMP_OUTPOL_INVERTED;
}


/** 
* @brief  COMP去初始化
* @param  compx COMP外设
* @retval 无
*/
void std_comp_deinit(COMP_t *compx)
{
    /* 禁止COMP */
    std_comp_disable(compx);
    /* 复位COMP外设 */
    compx->CSR = 0x00000000U;
}

/** 
* @} 
*/

#endif /* STD_COMP_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
