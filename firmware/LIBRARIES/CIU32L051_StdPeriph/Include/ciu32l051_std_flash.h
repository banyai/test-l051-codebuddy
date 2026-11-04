/************************************************************************************************/
/**
* @file               ciu32l051_std_flash.h
* @author             MCU Ecosystem Development Team
* @brief              FLASH STD库驱动头文件。
*                     提供FLASH相关的STD库操作函数声明、数据类型以及常量的定义。                         
*
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/*避免头文件重复引用*/
#ifndef CIU32L051_STD_FLASH_H
#define CIU32L051_STD_FLASH_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup FLASH FLASH
* @brief FLASH存储器的STD库驱动
* @{
*/
/************************************************************************************************/



#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"

/*-------------------------------------------define---------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup FLASH_Constants FLASH Constants 
* @brief  FLASH常量定义及宏定义
* @{
*
*/
/************************************************************************************************/

/* Flash读取访问等待周期 */      
#define FLASH_LATENCY_0CLK                FLASH_ACR_LATENCY_0CLK                     /**< 等待周期：0 HCLK         */
#define FLASH_LATENCY_1CLK                FLASH_ACR_LATENCY_1CLK                     /**< 等待周期：1 HCLK         */ 
#define FLASH_LATENCY_2CLK                FLASH_ACR_LATENCY_2CLK                     /**< 等待周期：2 HCLK         */ 
                                                                                     
/* Flash操作等待时间 */                                                              
#define FLASH_WAIT_PROGRAM                (1U)                                       /**< Flash编程等待时间（ms）  */
#define FLASH_WAIT_PAGE_ERASE             (5U)                                       /**< Flash页擦等待时间（ms）  */
#define FLASH_WAIT_MASS_ERASE             (50U)                                      /**< Flash片擦等待时间（ms）  */
                                                                                     
/* Flash控制寄存器解锁密钥 */                                                        
#define FLASH_CR_KEY1                     (0xE57A1A85U)                              /**< Flash控制寄存器解锁密钥1 */
#define FLASH_CR_KEY2                     (0x7C6E8391U)                              /**< Flash控制寄存器解锁密钥2 */
                                                                                     
/* Flash选项字节解锁密钥 */                                                          
#define FLASH_OPT_KEY1                    (0x6A894D7BU)                              /**< Flash选项字节解锁密钥1   */
#define FLASH_OPT_KEY2                    (0x7C311F5AU)                              /**< Flash选项字节解锁密钥2   */
                                                                                     
/* Flash操作状态 */                                                                  
#define FLASH_FLAG_EOP                    FLASH_SR_EOP                               /**< Flash操作完成标志        */
#define FLASH_FLAG_BSY                    FLASH_SR_BSY                               /**< Flash操作状态标志        */
#define FLASH_FLAG_WRPERR                 FLASH_SR_WRPERR                            /**< Flash写保护错误标志      */
#define FLASH_FLAG_PROGERR                FLASH_SR_PROGERR                           /**< Flash编程错误标志        */
#define FLASH_FLAG_FSTERR                 FLASH_SR_FSTERR                            /**< Flash快速编程错误标志    */
#define FLASH_FLAG_ALL_ERR                (FLASH_FLAG_PROGERR | FLASH_FLAG_WRPERR \
                                                              | FLASH_SR_FSTERR)     /**< Flash错误标志            */
                                                                                 
/* Flash中断源 */                      
#define FLASH_INTERRUPT_OPERR             FLASH_CR_OPERRIE                           /**< Flash操作异常中断        */
#define FLASH_INTERRUPT_EOP               FLASH_CR_EOPIE                             /**< Flash操作完成中断        */
                                                                                     
/* Flash擦除模式 */                                                                  
#define FLASH_ERASE_DISABLE               FLASH_CR_ER_MODE_NONE                      /**< Flash退出擦除模式        */
#define FLASH_ERASE_PAGE                  FLASH_CR_ER_MODE_PAGE                      /**< Flash页擦除模式          */
#define FLASH_ERASE_MASS                  FLASH_CR_ER_MODE_MASS                      /**< Flash批量擦除模式        */
                                                                                     
/* 选项字节1 位域使能 */                                                             
#define FLASH_BOR_ENABLE                  FLASH_OPTR1_BOR_EN                         /**< BOR使能                             */
#define FLASH_BOR_LEVEL_MASK              FLASH_OPTR1_BOR_LEVEL_MASK                 /**< BOR检测配置域                       */
#define FLASH_BOR_LEVEL_0                 FLASH_OPTR1_BOR_LEVEL_0                    /**< BOR检测电压上升/下降阈值：2.1/2.0V  */
#define FLASH_BOR_LEVEL_1                 FLASH_OPTR1_BOR_LEVEL_1                    /**< BOR检测电压上升/下降阈值：2.3/2.2V  */
#define FLASH_BOR_LEVEL_2                 FLASH_OPTR1_BOR_LEVEL_2                    /**< BOR检测电压上升/下降阈值：2.6/2.5V  */
#define FLASH_BOR_LEVEL_3                 FLASH_OPTR1_BOR_LEVEL_3                    /**< BOR检测电压上升/下降阈值：2.9/2.8V  */
                                                                                     
#define FLASH_RDP_LEVEL_MASK              FLASH_OPTR1_RDP_MASK                       /**< RDP配置域       */
#define FLASH_RDP_LEVEL_0                 (0x000000AAU)                              /**< RDP保护等级0    */
#define FLASH_RDP_LEVEL_1                 (0x00000000U)                              /**< RDP保护等级1    */
#define FLASH_RDP_LEVEL_2                 (0x00000055U)                              /**< RDP保护等级2    */

/* 选项字节2 位域使能 */
#define FLASH_BOOT_SEL_SW                 FLASH_OPTR2_BOOT_SEL                       /**< 启动条件使用选项字节BOOT0_SW配置                */
#define FLASH_BOOT0_SW_1                  FLASH_OPTR2_BOOT0_SW                       /**< 配置BOOT0_SW为1                                 */
#define FLASH_BOOT1_SW_1                  FLASH_OPTR2_BOOT1_SW                       /**< 配置BOOT1_SW为1                                 */
#define FLASH_VBAT_MODE_ENABLE            FLASH_OPTR2_VBAT_MODE_EN                   /**< VBAT模式使能                                    */
#define FLASH_IWDG_STOP_MODE_NORMAL       FLASH_OPTR2_IWDG_STOP                      /**< IWDG在Stop模式下正常计数                        */
#define FLASH_STOP_RESET_DISABLE          FLASH_OPTR2_RST_STOP                       /**< 执行进入Stop模式操作，正常进入Stop，不产生复位  */
                                                                                     
/* Option Bytes地址 */                                                               
#define FLASH_OB_OPTR1_ADDR               (0x1FFF0000)                               /**< 选项字节1存储地址           */
#define FLASH_OB_OPTR2_ADDR               (0x1FFF0004)                               /**< 选项字节2存储地址           */
#define FLASH_OB_WRP1A_START_ADDR         (0x1FFF0008)                               /**< 写保护区A起始地址存储地址   */
#define FLASH_OB_WRP1A_END_ADDR           (0x1FFF000C)                               /**< 写保护区A结束地址存储地址   */
#define FLASH_OB_WRP1B_START_ADDR         (0x1FFF0010)                               /**< 写保护区B起始地址存储地址   */
#define FLASH_OB_WRP1B_END_ADDR           (0x1FFF0014)                               /**< 写保护区B结束地址存储地址   */


/**
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup FLASH_External_Functions FLASH External Functions
* @brief    FLASH对外函数
* @{
*
*/
/************************************************************************************************/

/** 
* @brief  Flash控制寄存器解锁
* @note   FLASH控制器解锁后操作CRKEY寄存器会产生总线错误并锁定写保护，直至下次复位
* @retval 无
*/
__STATIC_INLINE void std_flash_unlock(void)
{
    if ((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK)
    {
        FLASH->CRKEY = FLASH_CR_KEY1;
        FLASH->CRKEY = FLASH_CR_KEY2; 
    }
}

/** 
* @brief  Flash控制寄存器锁定
* @retval 无
*/
__STATIC_INLINE void std_flash_lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK;
}

/** 
* @brief  读取Flash锁定状态
* @retval bool Flash锁定状态
*             @arg true  表示锁定状态
*             @arg false 表示解锁状态
*/
__STATIC_INLINE bool std_flash_get_lock_status(void)
{
    return ((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK);
}

/** 
* @brief  Flash选项字节解锁
* @note   FLASH选项字节解锁后操作OPTKEY寄存器会产生总线错误并锁定写保护，直至下次复位
* @retval 无
*/
__STATIC_INLINE void std_flash_opt_unlock(void)
{
    if ((FLASH->CR & FLASH_CR_OPTLOCK) == FLASH_CR_OPTLOCK)
    {
        FLASH->OPTKEY = FLASH_OPT_KEY1;
        FLASH->OPTKEY = FLASH_OPT_KEY2; 
    }
}

/** 
* @brief  Flash选项字节锁定
* @retval 无
*/
__STATIC_INLINE void std_flash_opt_lock(void)
{
    FLASH->CR |= FLASH_CR_OPTLOCK;
}

/** 
* @brief  读取Flash选项字节锁定状态
* @retval bool Flash选项字节锁定状态
*             @arg true  表示锁定状态
*             @arg false 表示解锁状态
*/
__STATIC_INLINE bool std_flash_get_opt_lock_status(void)
{
    return ((FLASH->CR & FLASH_CR_OPTLOCK) == FLASH_CR_OPTLOCK);
}

/**
* @brief  设置FLASH读取访问等待周期
* @param  latency 读取访问等待周期
*             @arg  FLASH_LATENCY_0CLK
*             @arg  FLASH_LATENCY_1CLK
*             @arg  FLASH_LATENCY_2CLK
* @retval 无
*/
__STATIC_INLINE void std_flash_set_latency(uint32_t latency)
{
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, latency);
} 

/**
* @brief  读取FLASH读取访问等待周期
* @retval uint32_t 读取访问等待周期
*             @arg  FLASH_LATENCY_0CLK
*             @arg  FLASH_LATENCY_1CLK
*             @arg  FLASH_LATENCY_2CLK
*/
__STATIC_INLINE uint32_t std_flash_get_latency(void)
{
    return (FLASH->ACR & FLASH_ACR_LATENCY);
} 

/**
* @brief  使能FLASH中断
* @param  interrupts 中断源
*             @arg FLASH_INTERRUPT_OPERR
*             @arg FLASH_INTERRUPT_EOP 
* @retval 无
*/
__STATIC_INLINE void std_flash_interrupt_enable(uint32_t interrupts)
{
    FLASH->CR |= interrupts;
}

/**
* @brief  禁止FLASH中断
* @param  interrupts 中断源
*             @arg FLASH_INTERRUPT_OPERR
*             @arg FLASH_INTERRUPT_EOP 
* @retval 无
*/
__STATIC_INLINE void std_flash_interrupt_disable(uint32_t interrupts)
{
    FLASH->CR &= (~interrupts);
}

/**
* @brief  读取FLASH中断使能状态
* @param  interrupt 中断源
*             @arg FLASH_INTERRUPT_OPERR
*             @arg FLASH_INTERRUPT_EOP 
* @retval bool FLASH中断使能状态
*             @arg true  表示中断已使能
*             @arg false 表示中断未使能
*/
__STATIC_INLINE bool std_flash_get_interrupt_enable(uint32_t interrupt)
{
    return ((FLASH->CR & interrupt) == interrupt);
}

/**
* @brief  读取FLASH状态标志
* @param  flag 状态标志
*             @arg FLASH_FLAG_EOP
*             @arg FLASH_FLAG_BSY
*             @arg FLASH_FLAG_WRPERR
*             @arg FLASH_FLAG_PROGERR
*             @arg FLASH_FLAG_FSTERR
*             @arg FLASH_FLAG_ALL_ERR
* @retval bool FLASH状态标志
*             @arg true  表示标志置位
*             @arg false 表示标志未置位
*/
__STATIC_INLINE bool std_flash_get_flag(uint32_t flag)
{
    return ((FLASH->SR & flag) == flag);
}

/**
* @brief  清除FLASH状态标志
* @param  flags 状态标志组合
*             @arg FLASH_FLAG_EOP
*             @arg FLASH_FLAG_WRPERR
*             @arg FLASH_FLAG_PROGERR
*             @arg FLASH_FLAG_FSTERR
*             @arg FLASH_FLAG_ALL_ERR
* @retval 无
*/
__STATIC_INLINE void std_flash_clear_flag(uint32_t flags)
{
    FLASH->SR = flags;
}

/** 
* @brief  使能Flash编程
* @retval 无
*/
__STATIC_INLINE void std_flash_program_enable(void)
{
    FLASH->CR |= FLASH_CR_PG_MODE;
}

/** 
* @brief  禁止Flash编程
* @retval 无
*/
__STATIC_INLINE void std_flash_program_disable(void)
{
    FLASH->CR &= (~FLASH_CR_PG_MODE);
}

/** 
* @brief  启动Flash擦除
* @retval 无
*/
__STATIC_INLINE void std_flash_erase_start(void)
{
    FLASH->CR |= FLASH_CR_ERASE;
}

/** 
* @brief  设置Flash擦除模式
* @param  mode 擦除模式
*             @arg FLASH_ERASE_DISABLE
*             @arg FLASH_ERASE_PAGE
*             @arg FLASH_ERASE_MASS
* @retval 无
*/
__STATIC_INLINE void std_flash_set_erase_mode(uint32_t mode)
{
    MODIFY_REG(FLASH->CR, FLASH_CR_ER_MODE, mode);
}

/** 
* @brief  设置Flash擦除页号
* @param  index 擦除页号
* @retval 无
*/
__STATIC_INLINE void std_flash_set_erase_index(uint32_t index)
{
    MODIFY_REG(FLASH->CR, FLASH_CR_PNB, (index << FLASH_CR_PNB_POS));
}

/** 
* @brief  读取Flash擦除页号
* @retval uint32_t 擦除页号
*/
__STATIC_INLINE uint32_t std_flash_get_erase_index(void)
{
    return ((FLASH->CR & FLASH_CR_PNB) >> FLASH_CR_PNB_POS);
}

/** 
* @brief  启动Flash选项字节擦除
* @note   启动Flash选项字节擦除前，将先对Flash选项字节寄存器进行解锁
* @retval 无
*/
__STATIC_INLINE void std_flash_opt_erase_start(void)
{
    FLASH->CR |= FLASH_CR_OPT_ERASE;
}

/** 
* @brief  Flash选项字节加载
* @note   执行选项字节加载操作前，将先对Flash选项字节寄存器进行解锁
*         进行选项字节加载将产生系统复位
* @retval 无
*/
__STATIC_INLINE void std_flash_opt_launch(void)
{
    FLASH->CR |= FLASH_CR_OBL_LAUNCH;
}

/** 
* @brief  使能Flash快速编程模式
* @note   快速编程程序需要在RAM中执行
* @retval 无
*/
__STATIC_INLINE void std_flash_fast_program_enable(void)
{
    FLASH->CR |= FLASH_CR_FSTPG_MODE;
}

/** 
* @brief  查询Flash快速编程状态
* @note   快速编程程序需要在RAM中执行
* @retval bool 快速编程模式控制状态标志
*             @arg true  表示快速编程进行中
*             @arg false 表示快速编程已完成
*/
__STATIC_INLINE bool std_flash_get_fstpg_state(void)
{
    return ((FLASH->CR & FLASH_CR_FSTPG_MODE) == FLASH_CR_FSTPG_MODE);
}

/**
* @brief  读取选项字节寄存器1
* @retval uint32_t 选项字节1加载值
*/
__STATIC_INLINE uint32_t std_flash_get_opt1(void)
{
    return (FLASH->OPTR1);
}

/**
* @brief  读取FLASH读保护等级
* @retval uint32_t FLASH读保护等级
*             @arg FLASH_RDP_LEVEL_0
*             @arg FLASH_RDP_LEVEL_1
*             @arg FLASH_RDP_LEVEL_2
*/
__STATIC_INLINE uint32_t std_flash_get_rdp_level(void)
{
    return (FLASH->OPTR1 & FLASH_OPTR1_RDP);
}

/**
* @brief  读取BOR阈值等级
* @retval uint32_t FLASH读保护等级
*             @arg FLASH_BOR_LEVEL_0
*             @arg ...
*             @arg FLASH_BOR_LEVEL_3
*/
__STATIC_INLINE uint32_t std_flash_get_bor_level(void)
{
    return (FLASH->OPTR1 & FLASH_OPTR1_BOR_LEVEL);
}

/** 
* @brief  读取BOR使能控制
* @retval bool BOR使能控制
*             @arg true  表示BOR使能
*             @arg false 表示BOR禁止
*/
__STATIC_INLINE bool std_flash_get_bor_en(void)
{
    return ((FLASH->OPTR1 & FLASH_OPTR1_BOR_EN) == FLASH_OPTR1_BOR_EN);
}

/**
* @brief  读取选项字节寄存器2
* @retval uint32_t 选项字节2加载值
*/
__STATIC_INLINE uint32_t std_flash_get_opt2(void)
{
    return (FLASH->OPTR2);
}

/** 
* @brief  读取芯片启动模式BOOT_SEL
* @retval bool BOOT_SEL位配置值
*             @arg true  表示BOOT_SEL为1
*             @arg false 表示BOOT_SEL为0
*/
__STATIC_INLINE bool std_flash_get_boot_sel(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_BOOT_SEL) == FLASH_OPTR2_BOOT_SEL);
}

/** 
* @brief  读取芯片启动模式BOOT0_SW
* @retval bool BOOT0_SW位配置值
*             @arg true  表示BOOT0_SW为1
*             @arg false 表示BOOT0_SW为0
*/
__STATIC_INLINE bool std_flash_get_boot0_sw(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_BOOT0_SW) == FLASH_OPTR2_BOOT0_SW);
}

/** 
* @brief  读取芯片启动模式BOOT1_SW
* @retval bool BOOT1_SW位配置值
*             @arg true  表示BOOT1_SW为1
*             @arg false 表示BOOT1_SW为0
*/
__STATIC_INLINE bool std_flash_get_boot1_sw(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_BOOT1_SW) == FLASH_OPTR2_BOOT1_SW);
}

/** 
* @brief  读取VBAT使能控制
* @retval bool VBAT模式使能控制
*             @arg true  表示VBAT模式使能
*             @arg false 表示VBAT模式禁止
*/
__STATIC_INLINE bool std_flash_get_vbat_mode(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_VBAT_MODE_EN) == FLASH_OPTR2_VBAT_MODE_EN);
}

/** 
* @brief  读取IWDG在STOP模式下计数器停止控制
* @retval bool IWDG_STOP设置
*             @arg true  IWDG在STOP模式下计数器正常运行
*             @arg false IWDG在STOP模式下计数器停止计数
*/
__STATIC_INLINE bool std_flash_get_iwdg_stop(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_IWDG_STOP) == FLASH_OPTR2_IWDG_STOP);
}

/** 
* @brief  读取进入STOP模式是否复位的配置
* @retval bool RST_STOP设置
*             @arg true  执行进入STOP模式操作，进入STOP模式
*             @arg false 执行进入STOP模式操作，产生复位
*/
__STATIC_INLINE bool std_flash_get_rst_stop(void)
{
    return ((FLASH->OPTR2 & FLASH_OPTR2_RST_STOP) == FLASH_OPTR2_RST_STOP);
}

/**
* @brief  读取写保护区A起始页号
* @retval uint32_t 写保护区A起始页号
*/
__STATIC_INLINE uint32_t std_flash_get_wrpa_start(void)
{
    return (FLASH->WRP1AS & FLASH_WRP1AS_WRP1A_START);
}

/**
* @brief  读取写保护区A结束页号
* @retval uint32_t 写保护区A结束页号
*/
__STATIC_INLINE uint32_t std_flash_get_wrpa_end(void)
{
    return (FLASH->WRP1AE & FLASH_WRP1AE_WRP1A_END);
}

/**
* @brief  读取写保护区B起始页号
* @retval uint32_t 写保护区B起始页号
*/
__STATIC_INLINE uint32_t std_flash_get_wrpb_start(void)
{
    return (FLASH->WRP1BS & FLASH_WRP1BS_WRP1B_START);
}

/**
* @brief  读取写保护区B结束页号
* @retval uint32_t 写保护区B结束页号
*/
__STATIC_INLINE uint32_t std_flash_get_wrpb_end(void)
{
    return (FLASH->WRP1BE & FLASH_WRP1BE_WRP1B_END);
}

/** 
* @brief  读取芯片型号
* @retval uint32_t 芯片型号
*/
__STATIC_INLINE uint32_t std_flash_get_device_type(void)
{
    return (*(uint32_t *)DEVICE_TYPE);
}

/** 
* @brief  读取Flash空间大小
* @retval uint32_t Flash空间大小
*/
__STATIC_INLINE uint32_t std_flash_get_flash_size(void)
{
    return (*(uint32_t *)USERFLASH_SIZE);
}

/** 
* @brief  读取SRAM空间大小
* @retval uint32_t SRAM空间大小
*/
__STATIC_INLINE uint32_t std_flash_get_sram_size(void)
{
    return (*(uint32_t *)SRAM_SIZE);
}


std_status_t std_flash_mass_erase(void);
std_status_t std_flash_page_erase(uint32_t page_index);
std_status_t std_flash_erase(uint32_t mode, uint32_t index);
std_status_t std_flash_word_program(uint32_t address, uint32_t prog_data);
std_status_t std_flash_opt_erase(void);
std_status_t std_flash_wait_for_last_operation(uint32_t timeout);

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

#endif /* CIU32L051_STD_FLASH_H */


