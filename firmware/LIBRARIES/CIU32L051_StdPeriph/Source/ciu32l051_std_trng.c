/************************************************************************************************/
/**
* @file               ciu32l051_std_trng.c
* @author             MCU Ecosystem Development Team
* @brief              TRNG STD库驱动。
*                     实现TRNG模块的参数配置、获取32位随机数等功能API。
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
* @addtogroup TRNG 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------includes--------------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_TRNG_PERIPHERAL_USED

/*------------------------------------functions-------------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup TRNG_External_Functions
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  TRNG去初始化
* @retval 无 
*/
void std_trng_deinit(void)
{        
    /* 复位TRNG */
    std_rcc_apb2_reset(RCC_PERIPH_RESET_TRNG);
    /* TRNG时钟禁止 */
    std_rcc_apb2_clk_disable(RCC_PERIPH_CLK_TRNG);
}

/**
* @brief  获取32位随机数
* @param  rng_data32  生成的32位随机数
* @retval std_status_t 返回API执行结果
*/
std_status_t std_trng_get_random_number(uint32_t *rng_data32)
{
    /* 等待随机数生成完成 */
    while (!std_trng_get_flag_ready());

    /* 读取随机数 */
    *rng_data32 = std_trng_read_data();
    return STD_OK;  
}

/**
* @}
*/

/**
* @}
*/

#endif /* STD_TRNG_PERIPHERAL_USED */

/**
* @}
*/
