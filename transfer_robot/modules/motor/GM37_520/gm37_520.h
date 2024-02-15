#include "tim.h"
#include "stdint.h"

typedef struct
{
		uint16_t last_ecd;        // 上一次读取的编码器值
    uint16_t ecd;             // 0-8191,刻度总共有8192格
    float angle_single_round; // 单圈角度
    float speed_aps;          // 角速度,单位为:度/秒 rpm:rounds per minute
    int16_t real_current;     // 实际电流
    uint8_t temperate;        // 温度 Celsius

    float total_angle;   // 总角度,注意方向
    int32_t total_round; // 总圈数,注意方向
}motor_measure;
typedef struct
{
	//电机IN1
    GPIO_TypeDef *IN1_GPIOx;        // GPIOA,GPIOB,GPIOC...
    uint16_t IN1_GPIO_Pin;          // 引脚号,@note 这里的引脚号是GPIO_PIN_0,GPIO_PIN_1..
		int IN1_GPIO_Pin_state;					//电平
	//电机IN2
    GPIO_TypeDef *IN2_GPIOx;        // GPIOA,GPIOB,GPIOC...
    GPIO_PinState IN2_pin_state;    // 引脚状态,Set,Reset not frequently useded
    uint16_t IN2_GPIO_Pin;          // 引脚号,@note 这里的引脚号是GPIO_PIN_0,GPIO_PIN_1...
	  int IN2_GPIO_Pin_state;					//电平
    // 这些引脚是stm32f4xx_hal_gpio.h中定义的宏!!! 一定要注意
	//PWM
	  TIM_HandleTypeDef *pwmhtim;                 // TIM句柄
    uint32_t pwmchannel;                        // 通道
    uint32_t set_speed;                          // 脉宽(速度)
	//编码器
	  TIM_HandleTypeDef *encoderhtim;                 // TIM句柄
		uint32_t encoderchannel;
	//反馈
		motor_measure *motor_feedback;             //反馈数据
} gm37_520motor_s;

void gm37_520motor_init();//参数赋值

void set_motor_speed(int LF,int LB, int RF, int RB);
void send_motor_cmd(gm37_520motor_s motor1,gm37_520motor_s motor2,gm37_520motor_s motor3,gm37_520motor_s motor4);//发送电机报文
//#define GPIO_MX_DEVICE_NUM 10

///**
// * @brief 用于判断中断来源,注意和CUBEMX中配置一致
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
// * @brief GPIO实例结构体定义
// *
// */
//typedef struct tmpgpio
//{
//    GPIO_TypeDef *GPIOx;        // GPIOA,GPIOB,GPIOC...
//    GPIO_PinState pin_state;    // 引脚状态,Set,Reset;not frequently used
//    GPIO_EXTI_MODE_e exti_mode; // 外部中断模式 not frequently used
//    uint16_t GPIO_Pin;          // 引脚号,
//    // 这些引脚是stm32f4xx_hal_gpio.h中定义的宏!!! 一定要注意
//    // 随便取个名字当临时声明
//    void (*gpio_model_callback)(struct tmpgpio *); // exti中断回调函数
//    void *id;                                      // 区分不同的GPIO实例

//} GPIOInstance;

///**
// * @brief GPIO初始化配置结构体定义
// *
// */
//typedef struct
//{
//    GPIO_TypeDef *GPIOx;        // GPIOA,GPIOB,GPIOC...
//    GPIO_PinState pin_state;    // 引脚状态,Set,Reset not frequently used
//    GPIO_EXTI_MODE_e exti_mode; // 外部中断模式 not frequently used
//    uint16_t GPIO_Pin;          // 引脚号,@note 这里的引脚号是GPIO_PIN_0,GPIO_PIN_1...
//    // 这些引脚是stm32f4xx_hal_gpio.h中定义的宏!!! 一定要注意

//    void (*gpio_model_callback)(GPIOInstance *); // exti中断回调函数
//    void *id;                                    // 区分不同的GPIO实例

//} GPIO_Init_Config_s;

///**
// * @brief 注册GPIO实例
// *
// * @param GPIO_config
// * @return GPIOInstance*
// */
//GPIOInstance *GPIORegister(GPIO_Init_Config_s *GPIO_config);

///**
// * @brief GPIO API,切换GPIO电平
// *
// * @param _instance
// */
//void GPIOToggel(GPIOInstance *_instance);

///**
// * @brief 设置GPIO电平
// *
// * @param _instance
// */
//void GPIOSet(GPIOInstance *_instance);

///**
// * @brief 复位GPIO电平
// *
// * @param _instance
// */
//void GPIOReset(GPIOInstance *_instance);

///**
// * @brief 读取GPIO电平
// *
// * @param _instance
// * @return GPIO_PinState
// */
//GPIO_PinState GPIORead(GPIOInstance *_instance);