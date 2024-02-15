#include "tim.h"
#include "stdint.h"

typedef struct
{
		uint16_t last_ecd;        // ��һ�ζ�ȡ�ı�����ֵ
    uint16_t ecd;             // 0-8191,�̶��ܹ���8192��
    float angle_single_round; // ��Ȧ�Ƕ�
    float speed_aps;          // ���ٶ�,��λΪ:��/�� rpm:rounds per minute
    int16_t real_current;     // ʵ�ʵ���
    uint8_t temperate;        // �¶� Celsius

    float total_angle;   // �ܽǶ�,ע�ⷽ��
    int32_t total_round; // ��Ȧ��,ע�ⷽ��
}motor_measure;
typedef struct
{
	//���IN1
    GPIO_TypeDef *IN1_GPIOx;        // GPIOA,GPIOB,GPIOC...
    uint16_t IN1_GPIO_Pin;          // ���ź�,@note ��������ź���GPIO_PIN_0,GPIO_PIN_1..
		int IN1_GPIO_Pin_state;					//��ƽ
	//���IN2
    GPIO_TypeDef *IN2_GPIOx;        // GPIOA,GPIOB,GPIOC...
    GPIO_PinState IN2_pin_state;    // ����״̬,Set,Reset not frequently useded
    uint16_t IN2_GPIO_Pin;          // ���ź�,@note ��������ź���GPIO_PIN_0,GPIO_PIN_1...
	  int IN2_GPIO_Pin_state;					//��ƽ
    // ��Щ������stm32f4xx_hal_gpio.h�ж���ĺ�!!! һ��Ҫע��
	//PWM
	  TIM_HandleTypeDef *pwmhtim;                 // TIM���
    uint32_t pwmchannel;                        // ͨ��
    uint32_t set_speed;                          // ����(�ٶ�)
	//������
	  TIM_HandleTypeDef *encoderhtim;                 // TIM���
		uint32_t encoderchannel;
	//����
		motor_measure *motor_feedback;             //��������
} gm37_520motor_s;

void gm37_520motor_init();//������ֵ

void set_motor_speed(int LF,int LB, int RF, int RB);
void send_motor_cmd(gm37_520motor_s motor1,gm37_520motor_s motor2,gm37_520motor_s motor3,gm37_520motor_s motor4);//���͵������
//#define GPIO_MX_DEVICE_NUM 10

///**
// * @brief �����ж��ж���Դ,ע���CUBEMX������һ��
// *
// */
//typedef enum
//{
//    GPIO_EXTI_MODE_RISING,
//    GPIO_EXTI_MODE_FALLING,
//    GPIO_EXTI_MODE_RISING_FALLING,
//    GPIO_EXTI_MODE_NONE,
//} GPIO_EXTI_MODE_e;

///**
// * @brief GPIOʵ���ṹ�嶨��
// *
// */
//typedef struct tmpgpio
//{
//    GPIO_TypeDef *GPIOx;        // GPIOA,GPIOB,GPIOC...
//    GPIO_PinState pin_state;    // ����״̬,Set,Reset;not frequently used
//    GPIO_EXTI_MODE_e exti_mode; // �ⲿ�ж�ģʽ not frequently used
//    uint16_t GPIO_Pin;          // ���ź�,
//    // ��Щ������stm32f4xx_hal_gpio.h�ж���ĺ�!!! һ��Ҫע��
//    // ���ȡ�����ֵ���ʱ����
//    void (*gpio_model_callback)(struct tmpgpio *); // exti�жϻص�����
//    void *id;                                      // ���ֲ�ͬ��GPIOʵ��

//} GPIOInstance;

///**
// * @brief GPIO��ʼ�����ýṹ�嶨��
// *
// */
//typedef struct
//{
//    GPIO_TypeDef *GPIOx;        // GPIOA,GPIOB,GPIOC...
//    GPIO_PinState pin_state;    // ����״̬,Set,Reset not frequently used
//    GPIO_EXTI_MODE_e exti_mode; // �ⲿ�ж�ģʽ not frequently used
//    uint16_t GPIO_Pin;          // ���ź�,@note ��������ź���GPIO_PIN_0,GPIO_PIN_1...
//    // ��Щ������stm32f4xx_hal_gpio.h�ж���ĺ�!!! һ��Ҫע��

//    void (*gpio_model_callback)(GPIOInstance *); // exti�жϻص�����
//    void *id;                                    // ���ֲ�ͬ��GPIOʵ��

//} GPIO_Init_Config_s;

///**
// * @brief ע��GPIOʵ��
// *
// * @param GPIO_config
// * @return GPIOInstance*
// */
//GPIOInstance *GPIORegister(GPIO_Init_Config_s *GPIO_config);

///**
// * @brief GPIO API,�л�GPIO��ƽ
// *
// * @param _instance
// */
//void GPIOToggel(GPIOInstance *_instance);

///**
// * @brief ����GPIO��ƽ
// *
// * @param _instance
// */
//void GPIOSet(GPIOInstance *_instance);

///**
// * @brief ��λGPIO��ƽ
// *
// * @param _instance
// */
//void GPIOReset(GPIOInstance *_instance);

///**
// * @brief ��ȡGPIO��ƽ
// *
// * @param _instance
// * @return GPIO_PinState
// */
//GPIO_PinState GPIORead(GPIOInstance *_instance);