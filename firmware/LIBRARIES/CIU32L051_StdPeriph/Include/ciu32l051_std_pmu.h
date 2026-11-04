/************************************************************************************************/
/**
* @file               ciu32l051_std_pmu.h
* @author             MCU Ecosystem Development Team
* @brief              PMU STD库驱动头文件。
*                     提供PMU相关STD库操作函数声明、数据类型以及常量的定义。 
*                      
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* 避免头文件重复引用 */
#ifndef CIU32L051_STD_PMU_H
#define CIU32L051_STD_PMU_H

/************************************************************************************************/
/** 
* @addtogroup CIU32L051_STD_Driver
* @{
*/

/**
* @defgroup PMU PMU
* @brief 电源管理单元的STD库驱动
* @{
*/
/************************************************************************************************/

#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32l051_std_common.h"


/*-----------------------------------------type define------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup PMU_Types PMU Types
* @brief PMU数据类型定义
* @{
*/
/************************************************************************************************/

/**
* @brief  PVD参数配置结构体定义
*/
typedef struct
{
    uint32_t level;                           /**< PVD 电压阈值:
                                                       @arg PMU_PVD_LEVEL_0 ...        */
    uint32_t alarm_type;                      /**< PVD 有效信号边沿报警配置:
                                                       @arg PMU_PVD_RISING ...         */ 
    uint32_t filter_enable;                   /**< PVD 数字滤波使能:
                                                       @arg PVD_FILTER_TIME_ENABLE
                                                       @arg PVD_FILTER_TIME_DISABLE    */
    uint32_t filter_time;                     /**< PVD 数字滤波时间配置:
                                                       @arg PVD_FILTER_TIME_2PCLK ...  */
}std_pvd_init_t;

/**
* @}
*/


/*--------------------------------------------define--------------------------------------------*/
/************************************************************************************************/
/** 
* @defgroup PMU_Constants PMU Constants
* @brief PMU常量定义及宏定义
* @{
*/
/************************************************************************************************/

/* 寄存器复位值定义 */
#define PMU_CR3_DEFAULT_VALUE               (0x00000000UL)                          /**< 电源管理控制寄存器3的复位值    */
#define PMU_CLR_FLAG_VALUE                  (0x00001000UL)                         /**< 电源管理状态清除寄存器的复位值 */


/* PVD的电压阈值配置值有关定义 */
#define PMU_PVD_LEVEL_0                     (0x00UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级0: 2.1/2.0V（上升/下降） */
#define PMU_PVD_LEVEL_1                     (0x01UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级1: 2.3/2.2V（上升/下降） */
#define PMU_PVD_LEVEL_2                     (0x02UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级2: 2.5/2.4V（上升/下降） */
#define PMU_PVD_LEVEL_3                     (0x03UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级3: 2.6/2.5V（上升/下降） */
#define PMU_PVD_LEVEL_4                     (0x04UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级4: 2.7/2.6V（上升/下降） */
#define PMU_PVD_LEVEL_5                     (0x05UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级5: 2.9/2.8V（上升/下降） */
#define PMU_PVD_LEVEL_6                     (0x06UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级6: 3.0/2.9V（上升/下降） */
#define PMU_PVD_LEVEL_7                     (0x07UL << PMU_CR2_PVD_LEVEL_POS)        /**< PVD阈值等级7: 3.1/3.0V（上升/下降） */

/* PVD中断有效信号定义 */
#define PMU_PVD_RISING                      (PMU_CR2_RT_EN)                       /**< 表示当监测电压从低于阈值到高于阈值变化时报警使能  */
#define PMU_PVD_FALLING                     (PMU_CR2_FT_EN)                       /**< 表示当监测电压从高于阈值到低于阈值变化时报警使能  */
#define PMU_PVD_LOWER_THRESHOLD             (PMU_CR2_LT_EN)                       /**< 表示当监测电压低于阈值报警使能                    */
#define PMU_PVD_HIGHER_THRESHOLD            (PMU_CR2_HT_EN)                       /**< 表示当监测电压高于阈值报警使能                    */
#define PMU_PVD_EDGE_TYPE                   (PMU_CR2_RT_EN | PMU_CR2_FT_EN | PMU_CR2_LT_EN | PMU_CR2_HT_EN)

/* PVD 数字滤波使能定义 */
#define PVD_FILTER_TIME_DISABLE             (0x00000000UL)
#define PVD_FILTER_TIME_ENABLE              (PMU_CR2_FILTER_EN)

/* PVD 数字滤波时间定义 */
#define PVD_FILTER_TIME_2PCLK               (0x00UL)                              /**< PVD检测时信号数字滤波时间为：2*PCLK      */
#define PVD_FILTER_TIME_4PCLK               (0x01UL)                              /**< PVD检测时信号数字滤波时间为：4*PCLK      */
#define PVD_FILTER_TIME_8PCLK               (0x02UL)                              /**< PVD检测时信号数字滤波时间为：8*PCLK      */
#define PVD_FILTER_TIME_16PCLK              (0x03UL)                              /**< PVD检测时信号数字滤波时间为：16*PCLK     */
#define PVD_FILTER_TIME_32PCLK              (0x04UL)                              /**< PVD检测时信号数字滤波时间为：32*PCLK     */
#define PVD_FILTER_TIME_64PCLK              (0x05UL)                              /**< PVD检测时信号数字滤波时间为：64*PCLK     */
#define PVD_FILTER_TIME_128PCLK             (0x06UL)                              /**< PVD检测时信号数字滤波时间为：128*PCLK    */
#define PVD_FILTER_TIME_256PCLK             (0x07UL)                              /**< PVD检测时信号数字滤波时间为：256*PCLK    */

/* 低功耗进入方式定义 */
#define PMU_ENTRY_LOWPOWER_MODE_WFI         (0x00UL)                              /**< WFI方式进入低功耗模式                    */     
#define PMU_ENTRY_LOWPOWER_MODE_WFE         (0x01UL)                              /**< WFE方式进入低功耗模式                    */


/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/
/************************************************************************************************/
/**
* @defgroup PMU_External_Functions PMU External Functions
* @brief    PMU对外函数
* @{
*/
/************************************************************************************************/
/**
* @brief  使能BGR
* @retval 无
*/
__STATIC_INLINE void std_pmu_bgr_enable(void)
{
    PMU->CR1 |= PMU_CR1_BGR_EN;
}


/**
* @brief  禁止BGR
* @retval 无
*/
__STATIC_INLINE void std_pmu_bgr_disable(void)
{
    PMU->CR1 &= (~PMU_CR1_BGR_EN);
}


/** 
* @brief  获取BGR Ready状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true：表示BGR已稳定
*             @arg false：表示BGR未稳定
*/
__STATIC_INLINE bool std_pmu_get_bgr_status(void)
{
    return ((PMU->SR & (PMU_SR_BGR_READY)) == (PMU_SR_BGR_READY));
}


/**
* @brief  使能VCORE_AON域的写操作
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_vaon_write_enable(void)
{
    PMU->CR1 |= PMU_CR1_VAON_WEN;
}


/**
* @brief  禁止VCORE_AON域的写操作
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_vaon_write_disable(void)
{
    PMU->CR1 &= (~PMU_CR1_VAON_WEN);
}


/**
* @brief  使能PVD数字过滤
* @note   进入Stop模式前，应禁止PVD数字滤波功能
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_filter_enable(void)
{
    PMU->CR2 |= PMU_CR2_FILTER_EN;
}

/**
* @brief  禁止PVD数字过滤
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_filter_disable(void)           
{
    PMU->CR2 &= (~PMU_CR2_FILTER_EN);
}


/**
* @brief  配置PVD监测信号数字滤波时间
* @param  filter_value 数字滤波时间参数
*             @arg PVD_FILTER_TIME_2PCLK
*             @arg PVD_FILTER_TIME_4PCLK
*             @arg ...
*             @arg PVD_FILTER_TIME_256PCLK
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_filter_config(uint32_t filter_value)
{
    MODIFY_REG(PMU->CR2, PMU_CR2_FILTER_TIME, (filter_value << PMU_CR2_FILTER_TIME_POS)); 
}


/**
* @brief  配置PVD阈值等级
* @param  pvd_level PVD阈值等级选择
*             @arg PMU_PVD_LEVEL_0
*             @arg PMU_PVD_LEVEL_1
*             @arg ...
*             @arg PMU_PVD_LEVEL_7
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_level_config(uint32_t pvd_level)
{
    MODIFY_REG(PMU->CR2, PMU_CR2_PVD_LEVEL, pvd_level); 
}


/**
* @brief  使能PVD
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_enable(void)
{
    PMU->CR2 |= PMU_CR2_PVD_EN; 
}

/**
* @brief  禁止PVD
* @retval 无
*/                                                           
__STATIC_INLINE void std_pmu_pvd_disable(void)
{
    PMU->CR2 &= (~PMU_CR2_PVD_EN);
}


/** 
* @brief  获取PVD状态标志
* @retval bool 返回逻辑表达式的判断结果
*             @arg true： 表示监测电压低于PVD阈值
*             @arg false：表示监测电压高于PVD阈值
*/
__STATIC_INLINE bool std_pmu_get_pvd_status(void)
{
    return ((PMU->SR & (PMU_SR_PVD_STATUS)) == (PMU_SR_PVD_STATUS));
}


/**
* @brief  使能PVD中断
* @retval 无
*/
__STATIC_INLINE void std_pmu_pvd_interrupt_enable(void)         
{
    PMU->CR2 |= PMU_CR2_PVD_IE;
}

/**
* @brief  禁止PVD中断
* @retval 无
*/
__STATIC_INLINE void std_pmu_pvd_interrupt_disable(void)        
{
    PMU->CR2 &= (~PMU_CR2_PVD_IE);
}


/** 
* @brief  检查PVD中断状态
* @retval bool 返回逻辑表达式的判断结果
*             @arg true：表示PVD中断状态置位 
*             @arg false：表示PVD中断状态未置位
*/
__STATIC_INLINE bool std_pmu_get_pvd_interrupt_flag(void)
{
    return ((PMU->SR & (PMU_SR_PVD_INTF)) == (PMU_SR_PVD_INTF));
}



/**
* @brief  清除PVD中断标志
* @retval 无
*/
__STATIC_INLINE void std_pmu_clear_pvd_interrupt_flag(void)
{
    PMU->CLR = PMU_CLR_PVD_INTF_CLR;
}


/**
* @brief  使能监测电压报警功能
* @param  alarm_mode 监测电压报警类型
*             @arg PMU_PVD_RISING
*             @arg PMU_PVD_FALLING
*             @arg PMU_PVD_LOWER_THRESHOLD
*             @arg PMU_PVD_HIGHER_THRESHOLD
*             @arg PMU_PVD_EDGE_TYPE
* @retval 无
*/
__STATIC_INLINE void std_pmu_pvd_alarm_enable(uint32_t alarm_mode)         
{
    PMU->CR2 |= (alarm_mode);
}


/**
* @brief  禁止监测电压报警功能
* @param  alarm_mode 监测电压报警类型
*             @arg PMU_PVD_RISING
*             @arg PMU_PVD_FALLING
*             @arg PMU_PVD_LOWER_THRESHOLD
*             @arg PMU_PVD_HIGHER_THRESHOLD
*             @arg PMU_PVD_EDGE_TYPE
* @retval 无
*/
__STATIC_INLINE void std_pmu_pvd_alarm_disable(uint32_t alarm_mode)            
{
    PMU->CR2 &= (~(alarm_mode));
}

/**
* @brief  获取监测电压报警状态
* @param  flag 监测电压报警类型
*             @arg PMU_PVD_RISING
*             @arg PMU_PVD_FALLING
*             @arg PMU_PVD_LOWER_THRESHOLD
*             @arg PMU_PVD_HIGHER_THRESHOLD
*             @arg PMU_PVD_EDGE_TYPE
* @retval bool 返回标志的状态 
*             @arg true： 当前标志为置起状态 
*             @arg false：当前标志为清除状态
*/
__STATIC_INLINE bool std_pmu_get_pvd_alarm_flag(uint32_t flag)      
{
    return ((PMU->CR2 &(flag)) == (flag));    
}


/**
* @brief  使能超低功耗配置
* @note   在Stop和Standby模式下，使能PDR/BOR周期性采样，从而降低功耗
* @retval 无
*/
__STATIC_INLINE void std_pmu_ultra_lowpower_enable(void)
{
    PMU->CR3 |= PMU_CR3_ULP_EN;
}

/**
* @brief  禁止超低功耗配置
* @retval 无
*/
__STATIC_INLINE void std_pmu_ultra_lowpower_disable(void)
{
    PMU->CR3 &= (~PMU_CR3_ULP_EN);
}



/* PMU寄存器复位函数 */
void std_pmu_reg_reset(void);

/* PVD初始化函数 */
void std_pmu_pvd_init(std_pvd_init_t *pvd_init_param);
void std_pmu_struct_init(std_pvd_init_t *pvd_init_struct);

/* PMU低功耗模式相关函数 */
void std_pmu_enter_sleep(uint32_t mode_entry);
void std_pmu_enter_stop(uint32_t mode_entry);

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

#endif /* CIU32L051_STD_PMU_H */

