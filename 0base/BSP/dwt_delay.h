#ifndef DWT_STM32_DELAY_H
#define DWT_STM32_DELAY_H
 
#ifdef __cplusplus
extern "C" {
#endif
 
#include "stm32f1xx_hal.h"
 
/**
 * @brief  Initializes DWT_Cycle_Count for DWT_Delay_us function
 * @return Error DWT counter
 *         1: DWT counter Error
 *         0: DWT counter works
 */
uint32_t DWT_Delay_Init(void);
 
/**
 * @brief  This function provides a delay (in microseconds)
 * @param  microseconds: delay in microseconds
 */
__STATIC_INLINE void DWT_Delay_us(volatile uint32_t microseconds)
{
  uint32_t clk_cycle_start = DWT->CYCCNT;
 
  /* Go to number of cycles for system */
  microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
 
  /* Delay till end */
  while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}
 
typedef struct
{
    uint32_t s;
    uint16_t ms;
    uint16_t us;
} DWT_Time_t;


/**
 * @brief ��ʼ��DWT,�������ΪCPUƵ��,��λMHz
 * 
 * @param CPU_Freq_mHz c��Ϊ168MHz,A��Ϊ180MHz
 */
void DWT_Init(uint32_t CPU_Freq_mHz);

/**
 * @brief ��ȡ���ε���֮���ʱ����,��λΪ��/s
 * 
 * @param cnt_last ��һ�ε��õ�ʱ���
 * @return float ʱ����,��λΪ��/s
 */
float DWT_GetDeltaT(uint32_t *cnt_last);

/**
 * @brief ��ȡ���ε���֮���ʱ����,��λΪ��/s,�߾���
 * 
 * @param cnt_last ��һ�ε��õ�ʱ���
 * @return double ʱ����,��λΪ��/s
 */
double DWT_GetDeltaT64(uint32_t *cnt_last);

/**
 * @brief ��ȡ��ǰʱ��,��λΪ��/s,����ʼ�����ʱ��
 * 
 * @return float ʱ����
 */
float DWT_GetTimeline_s(void);

/**
 * @brief ��ȡ��ǰʱ��,��λΪ����/ms,����ʼ�����ʱ��
 * 
 * @return float 
 */
float DWT_GetTimeline_ms(void);

/**
 * @brief ��ȡ��ǰʱ��,��λΪ΢��/us,����ʼ�����ʱ��
 * 
 * @return uint64_t 
 */
uint64_t DWT_GetTimeline_us(void);

/**
 * @brief DWT��ʱ����,��λΪ��/s
 * @attention �ú��������ж��Ƿ�����Ӱ��,�������ٽ����͹ر��ж�ʱʹ��
 * @note ��ֹ��__disable_irq()��__enable_irq()֮��ʹ��HAL_Delay()����,Ӧʹ�ñ�����
 * 
 * @param Delay ��ʱʱ��,��λΪ��/s
 */
void DWT_Delay(float Delay);

/**
 * @brief DWT����ʱ���ắ��,�ᱻ����timeline��������
 * @attention �����ʱ�䲻����timeline����,����Ҫ�ֶ����øú�������ʱ����,����CYCCNT�����ʱ��ʱ���᲻׼ȷ
 */
void DWT_SysTimeUpdate(void);


#ifdef __cplusplus
}
#endif
 
#endif