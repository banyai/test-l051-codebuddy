/************************************************************************************************/
/**
* @file               ciu32l051_std_lcd.c
* @author             MCU Ecosystem Development Team
* @brief              LCD STD库驱动。
*                     实现LCD初始化等API。
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
* @addtogroup LCD 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"


#ifdef STD_LCD_PERIPHERAL_USED

/*------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @addtogroup LCD_External_Functions 
* @{
*
*/
/************************************************************************************************/ 
/**
* @brief  LCD初始化
* @param  lcd_init_param LCD 初始化结构体 
* @retval 无
*/   
void std_lcd_init(std_lcd_init_t *lcd_init_param)
{    
    /* 禁止LCD */
    std_lcd_disable();
    /* 判断LCD为禁止状态 */
    while(std_lcd_get_flag(LCD_FLAG_ENS))
    {
    }

    /* 配置LCD区段多路复用
       配置LCD占空比 
       配置LCD偏置 
       配置LCD驱动模式 
    */
    MODIFY_REG(LCD->CR,
              (LCD_CR_MUX_SEG | LCD_CR_DUTY | LCD_CR_BIAS | LCD_CR_MDSET),
              (lcd_init_param->mux_segment | lcd_init_param->duty | lcd_init_param->bias | lcd_init_param->driver_mode));
    
    /* LCD显示帧速率：PS和DIV
       配置LCD驱动能力 
       配置LCD脉冲持续时间 
       配置VLCD输出电压档位 
    */
    MODIFY_REG(LCD->FCR, 
              (LCD_FCR_PS | LCD_FCR_DIV | LCD_FCR_HD | LCD_FCR_PON | LCD_FCR_CC),
              (lcd_init_param->prescaler | lcd_init_param->divider | lcd_init_param->high_drive | lcd_init_param->pulse_on_duration | lcd_init_param->vlcd_voltage));  

    /* LCD外设使能 */
    std_lcd_enable();
}

/**
* @brief  LCD去初始化
* @retval 无
*/   
void std_lcd_deinit(void)
{
    /* LCD外设禁止 */
    std_lcd_disable();
    /* 判断LCD外设禁止状态*/
    while(std_lcd_get_flag(LCD_FLAG_ENS))
    {
    }
            
    /* 复位LCD */    
    std_rcc_apb1_reset(RCC_PERIPH_RESET_LCD);

    /* 禁止LCD外设时钟 */
    std_rcc_apb1_clk_disable(RCC_PERIPH_CLK_LCD); 
}

/**
* @brief  LCD 结构体初始化
* @param  lcd_init_struct LCD 初始化结构体 
* @retval 无
*/
void std_lcd_struct_init(std_lcd_init_t *lcd_init_struct)
{
    lcd_init_struct->duty = LCD_DUTY_1_6;
    lcd_init_struct->bias = LCD_BIAS_1_3;   
    lcd_init_struct->prescaler = LCD_PRESCALER_4;
    lcd_init_struct->divider = LCD_FCR_DIV21;
    lcd_init_struct->driver_mode = LCD_DRIVER_MODE_CHARGE_PUMP;
    lcd_init_struct->vlcd_voltage = LCD_CHAGE_PUMP_1_3_BIAS_2_55V;
    lcd_init_struct->high_drive = LCD_LOW_DRIVE; 
    lcd_init_struct->pulse_on_duration = LCD_PULSE_ON_DURATION_0;
    lcd_init_struct->mux_segment = LCD_MUX_SEGMENT_DISABLE;
}
 
/** 
* @} 
*/

#endif /* STD_LCD_PERIPHERAL_USED */
/** 
* @} 
*/

/** 
* @} 
*/
