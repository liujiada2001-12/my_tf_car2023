#include "gm37_520.h"
#include "stdlib.h"
#include "gpio.h"
#include "tim.h"
#include "stm32f1xx_hal_def.h"
gm37_520motor_s motor_LF,motor_LB,motor_RF,motor_RB;
void gm37_520motor_init()
{
	//IN口初始化
	//PE0,1 		3,2 	5,4	7,6
	motor_LF.IN1_GPIOx=LFmotor_IN1_GPIO_Port;
	motor_LF.IN1_GPIO_Pin=LFmotor_IN1_Pin;
	motor_LF.IN2_GPIOx=LFmotor_IN2_GPIO_Port;
	motor_LF.IN2_GPIO_Pin=LFmotor_IN2_Pin;
	
	motor_LB.IN1_GPIOx=LBmotor_IN1_GPIO_Port;
	motor_LB.IN1_GPIO_Pin=LBmotor_IN1_Pin;
	motor_LB.IN2_GPIOx=LBmotor_IN2_GPIO_Port;
	motor_LB.IN2_GPIO_Pin=LBmotor_IN2_Pin;
	
	motor_RF.IN1_GPIOx=RFmotor_IN1_GPIO_Port;
	motor_RF.IN1_GPIO_Pin=RFmotor_IN1_Pin;
	motor_RF.IN2_GPIOx=RFmotor_IN2_GPIO_Port;
	motor_RF.IN2_GPIO_Pin=RFmotor_IN2_Pin;
	
	motor_RB.IN1_GPIOx=RBmotor_IN1_GPIO_Port;
	motor_RB.IN1_GPIO_Pin=RBmotor_IN1_Pin;
	motor_RB.IN2_GPIOx=RBmotor_IN2_GPIO_Port;
	motor_RB.IN2_GPIO_Pin=RBmotor_IN2_Pin;
	//PWM初始化
	HAL_TIM_Base_Start(&htim1);
	
	motor_LF.pwmhtim=&htim1;
	motor_LF.pwmchannel=TIM_CHANNEL_2;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	
	motor_LB.pwmhtim=&htim1;
	motor_LB.pwmchannel=TIM_CHANNEL_3;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	
	motor_RF.pwmhtim=&htim1;
	motor_RF.pwmchannel=TIM_CHANNEL_1;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	
	motor_RB.pwmhtim=&htim1;
	motor_RB.pwmchannel=TIM_CHANNEL_4;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);	
	//编码器初始化
	motor_LF.encoderhtim=&htim3;
	motor_LF.encoderchannel=TIM_CHANNEL_2 | TIM_CHANNEL_1;
	HAL_TIM_Encoder_Start(motor_LF.encoderhtim,motor_LF.encoderchannel);
	
	motor_LB.encoderhtim=&htim4;
	motor_LB.encoderchannel=TIM_CHANNEL_1 | TIM_CHANNEL_2;
	HAL_TIM_Encoder_Start(motor_LB.encoderhtim,motor_LB.encoderchannel);
	
	motor_RF.encoderhtim=&htim2;
	motor_RF.encoderchannel=TIM_CHANNEL_1 | TIM_CHANNEL_2;
	HAL_TIM_Encoder_Start(motor_RF.encoderhtim,motor_RF.encoderchannel);
	
	motor_RB.encoderhtim=&htim5;
	motor_RB.encoderchannel=TIM_CHANNEL_1 | TIM_CHANNEL_2;
	HAL_TIM_Encoder_Start(motor_RB.encoderhtim,motor_RB.encoderchannel);
}
//将有符号速度转为电机带方向的无符号速度
void in_and_speed_set(gm37_520motor_s motor,int speed)
{
	if(speed>0)
	{
		motor.set_speed=abs(speed);
		motor.IN1_GPIO_Pin_state=1;
		motor.IN2_GPIO_Pin_state=0;
	}
	else if(speed==0)
	{
		motor.set_speed=0;
		motor.IN1_GPIO_Pin_state=0;
		motor.IN2_GPIO_Pin_state=0;
	}
	else
	{
		motor.set_speed=abs(speed);
		motor.IN1_GPIO_Pin_state=0;
		motor.IN2_GPIO_Pin_state=1;
	}
}
void set_motor_speed(int LF,int LB, int RF, int RB)
{
	in_and_speed_set(motor_LF,LF);
	in_and_speed_set(motor_LB,LB);
	in_and_speed_set(motor_RF,RF);
	in_and_speed_set(motor_RB,RB);
}

void send_IN_motor(gm37_520motor_s motor)
{
	//IN口
	HAL_GPIO_WritePin(motor.IN1_GPIOx,motor.IN1_GPIO_Pin,motor.IN1_GPIO_Pin_state);
	HAL_GPIO_WritePin(motor.IN2_GPIOx,motor.IN2_GPIO_Pin,motor.IN2_GPIO_Pin_state);
	//PWM口
}

void send_motor_cmd(gm37_520motor_s motor1,gm37_520motor_s motor2,gm37_520motor_s motor3,gm37_520motor_s motor4)
{
	send_IN_motor(motor1);
	send_IN_motor(motor2);
	send_IN_motor(motor3);
	send_IN_motor(motor4);
	TIM1->CCR2=motor1.set_speed;
	TIM1->CCR3=motor2.set_speed;
	TIM1->CCR1=motor3.set_speed;
	TIM1->CCR4=motor4.set_speed;
}

//static uint8_t idx;
//static GPIOInstance *gpio_instance[GPIO_MX_DEVICE_NUM] = {NULL};

///**
// * @brief EXTI中断回调函数,根据GPIO_Pin找到对应的GPIOInstance,并调用模块回调函数(如果有)
// * @note 如何判断具体是哪一个GPIO的引脚连接到这个EXTI中断线上?
// *       一个EXTI中断线只能连接一个GPIO引脚,因此可以通过GPIO_Pin来判断,PinX对应EXTIX
// *       一个Pin号只会对应一个EXTI,详情见gpio.md
// * @param GPIO_Pin 发生中断的GPIO_Pin
// */
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//    // 如有必要,可以根据pinstate和HAL_GPIO_ReadPin来判断是上升沿还是下降沿/rise&fall等
//    static GPIOInstance *gpio;
//    for (size_t i = 0; i < idx; i++)
//    {
//        gpio = gpio_instance[i];
//        if (gpio->GPIO_Pin == GPIO_Pin && gpio->gpio_model_callback != NULL)
//        {
//            gpio->gpio_model_callback(gpio);
//            return;
//        }
//    }
//}

//GPIOInstance *GPIORegister(GPIO_Init_Config_s *GPIO_config)
//{
//    GPIOInstance *ins = (GPIOInstance *)malloc(sizeof(GPIOInstance));
//    memset(ins, 0, sizeof(GPIOInstance));

//    ins->GPIOx = GPIO_config->GPIOx;
//    ins->GPIO_Pin = GPIO_config->GPIO_Pin;
//    ins->pin_state = GPIO_config->pin_state;
//    ins->exti_mode = GPIO_config->exti_mode;
//    ins->id = GPIO_config->id;
//    ins->gpio_model_callback = GPIO_config->gpio_model_callback;
//    gpio_instance[idx++] = ins;
//    return ins;
//}

//// ----------------- GPIO API -----------------
//// 都是对HAL的形式上的封装,后续考虑增加GPIO state变量,可以直接读取state

//void GPIOToggel(GPIOInstance *_instance)
//{
//    HAL_GPIO_TogglePin(_instance->GPIOx, _instance->GPIO_Pin);
//}

//void GPIOSet(GPIOInstance *_instance)
//{
//    HAL_GPIO_WritePin(_instance->GPIOx, _instance->GPIO_Pin, GPIO_PIN_SET);
//}

//void GPIOReset(GPIOInstance *_instance)
//{
//    HAL_GPIO_WritePin(_instance->GPIOx, _instance->GPIO_Pin, GPIO_PIN_RESET);
//}

//GPIO_PinState GPIORead(GPIOInstance *_instance)
//{
//    return HAL_GPIO_ReadPin(_instance->GPIOx, _instance->GPIO_Pin);
//}
