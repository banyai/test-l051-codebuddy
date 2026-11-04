/************************************************************************************************/
/**
* @file               ciu32l051_std_flash.c
* @author             MCU Ecosystem Development Team
* @brief              FLASH STD库驱动。
*                     实现FLASH擦除、编程API。
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
* @addtogroup FLASH 
* @{
*
*/
/************************************************************************************************/


/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std.h"

#ifdef STD_FLASH_PERIPHERAL_USED

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @addtogroup FLASH_External_Functions 
* @{
*
*/
/************************************************************************************************/ 

/**
* @brief  Flash页擦除
* @param  page_index 擦除页号
* @retval std_status_t API执行结果
*/
std_status_t std_flash_page_erase(uint32_t page_index)
{
    return std_flash_erase(FLASH_ERASE_PAGE, page_index);
}

/** 
* @brief  FLASH批量擦除
* @retval std_status_t API执行结果
*/
std_status_t std_flash_mass_erase(void)
{
    return std_flash_erase(FLASH_ERASE_MASS, 0);
}

/**
* @brief  Flash擦除
* @param  mode 擦除模式
*             @arg FLASH_ERASE_PAGE
*             @arg FLASH_ERASE_MASS
* @param  index 擦除页号
* @note   擦除模式为FLASH_ERASE_MASS时，index参数无效
* @note   使用本函数前，需先调std_flash_unlock()，解锁flash
* @retval std_status_t API执行结果
*/
std_status_t std_flash_erase(uint32_t mode, uint32_t index)
{
    std_status_t status;
    uint32_t wait_time = FLASH_WAIT_MASS_ERASE;
    
    /* 检查Flash上一次操作忙状态、错误状态 */
    status = std_flash_wait_for_last_operation(FLASH_WAIT_PAGE_ERASE);
    if (status == STD_OK)
    {
        /* 设置擦除模式 */
        std_flash_set_erase_mode(mode);
        
        if (mode == FLASH_ERASE_PAGE)
        {
            /* 设置擦除页号 */
            std_flash_set_erase_index(index);
            wait_time = FLASH_WAIT_PAGE_ERASE;
        }

        /* 启动Flash擦除 */
        std_flash_erase_start();
        
        /* 查询Flash忙状态及错误状态，等待擦除完成 */
        status = std_flash_wait_for_last_operation(wait_time);
        
        /* 退出擦除模式 */
        std_flash_set_erase_mode(FLASH_ERASE_DISABLE);
    }

    return (status);
}

/**
* @brief  User Flash区与Option Byte区字编程
* @param  address   编程地址
* @param  prog_data 编程数据（4字节）
* @note   Option Byte区字编程时，需先调用std_flash_opt_unlock()，解锁选项字节
* @retval std_status_t API执行结果
*/
std_status_t std_flash_word_program(uint32_t address, uint32_t prog_data)
{
    std_status_t status;
    
    /* 检查Flash上一次操作忙状态、错误状态 */
    status = std_flash_wait_for_last_operation(FLASH_WAIT_PROGRAM);
    if (status == STD_OK)
    {
        /* 进入编程模式 */
        std_flash_program_enable();

        /* 向目标地址写入数据 */
        *(uint32_t *)address = prog_data;

        /* 查询Flash忙状态及错误状态，等待擦除完成 */
        status = std_flash_wait_for_last_operation(FLASH_WAIT_PROGRAM);
        
        /* 退出编程模式 */
        std_flash_program_disable();
    }

    return (status);
}

/**
* @brief  Flash Option Bytes区擦除
* @retval std_status_t API执行结果
*/
std_status_t std_flash_opt_erase(void)
{
    std_status_t status;
    
    /* 检查Flash上一次操作忙状态、错误状态 */
    status = std_flash_wait_for_last_operation(FLASH_WAIT_PAGE_ERASE);
    if (status == STD_OK)
    {
        /* 启动Flash选项字节擦除 */
        std_flash_opt_erase_start();
        
        /* 查询Flash忙状态及错误状态，等待擦除完成 */
        status = std_flash_wait_for_last_operation(FLASH_WAIT_PAGE_ERASE);
    }

    return (status);    
}

/**
* @brief  等待Flash操作完成，并查询错误标志
* @param  timeout 超时等待时间，单位:ms    
*             @arg FLASH_WAIT_PROGRAM
*             @arg FLASH_WAIT_PAGE_ERASE
*             @arg FLASH_WAIT_MASS_ERASE
* @retval std_status_t API执行结果
*/
std_status_t std_flash_wait_for_last_operation(uint32_t timeout)
{
    std_status_t status = STD_OK;
    uint32_t count;
    count = timeout *(SystemCoreClock / 1000U);
    
    /* 查询等待BSY标志被清除 */
    while (std_flash_get_flag(FLASH_FLAG_BSY))
    {
        if (count == 0U)
        {
            return STD_ERR_TIMEOUT;
        }
        count--;
    }

    /* 检查Flash错误标志 */
    if((FLASH->SR & FLASH_FLAG_ALL_ERR) != 0x00000000U)
    {
        status = STD_ERR;
    }
    
    /* 清除Flash标志 */
    std_flash_clear_flag(FLASH_FLAG_ALL_ERR | FLASH_SR_EOP);
    
    return status;
}

/** 
* @} 
*/

#endif /* STD_FLASH_PERIPHERAL_USED */

/** 
* @} 
*/

/** 
* @} 
*/
