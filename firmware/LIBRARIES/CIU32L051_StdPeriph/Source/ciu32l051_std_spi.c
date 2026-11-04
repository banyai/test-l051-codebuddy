/************************************************************************************************/
/**
* @file               ciu32l051_std_spi.c
* @author             MCU Ecosystem Development Team
* @brief              SPI STD库驱动。
*                     实现SPI初始化等API。
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
* @addtogroup SPI 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_SPI_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup SPI_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
   
/** 
* @brief  SPI初始化
* @param  spix SPI外设
* @param  spi_init_param SPI初始化结构体   
* @retval 无
*/
void std_spi_init(SPI_t *spix, std_spi_init_t *spi_init_param)
{
    /* 配置SPI通信速率 */
    std_spi_set_baud_rate(spix,spi_init_param->baud_rate_prescaler);

    /* 配置SPI时钟极性 */
    std_spi_set_polarity(spix,spi_init_param->clk_polarity);

    /* 配置SPI相位 */
    std_spi_set_phase(spix,spi_init_param->clk_phase);
    
    /* 配置SPI模式 */
    std_spi_set_mode(spix,spi_init_param->mode);
}

/**
* @brief  SPI去初始化
* @param  spix SPI外设
* @retval 无
*/
void std_spi_deinit(SPI_t *spix)
{
    std_spi_disable(spix);
    
    if(spix == SPI1)
    {
        std_rcc_apb2_reset(RCC_PERIPH_RESET_SPI1);
        std_rcc_apb2_clk_disable(RCC_PERIPH_CLK_SPI1);
    }
    else if (spix == SPI2)
    {
        std_rcc_apb1_reset(RCC_PERIPH_RESET_SPI2);
        std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_SPI2);
    }
    else
    {
        /* 无操作 */
    }
} 

/**
* @brief  SPI结构体初始化
* @param  spi_init_struct SPI初始化结构体 
* @retval 无
*/
void std_spi_struct_init(std_spi_init_t *spi_init_struct)
{
    spi_init_struct->mode = SPI_MODE_MASTER;
    spi_init_struct->baud_rate_prescaler = SPI_BAUDRATEPRESCALER_128;
    spi_init_struct->clk_polarity = SPI_POLARITY_LOW;
    spi_init_struct->clk_phase = SPI_PHASE_1EDGE;
}

/** 
* @} 
*/

#endif /* STD_SPI_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/

