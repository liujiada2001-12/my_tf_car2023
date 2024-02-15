#ifndef __MOTOR_H
#define __MOTOR_H
#include "sys.h"
#include "gpio.h"
extern u8 greencount,redcount;
void tim1_pwm_init(void);
void motor_IO_init(void);
void Huidu(void);
void Go(int i,int j);
void go_stright(void);
void turn_left(void);
void turn_right(void);
void go_home(void);
void first_green(void);
void first_red(void);
void second_red(void);
void second_green(void);
void jump_over(void);
void Right(void);
void Left(void);
void Leftgo(void);
void WanTiaoDD(void);
void fang(u8 wt);
void stop(void);
void stopys(u8 ys);
void delay_s(u8 delay);
void kuayue(void);
#define motor1_IN1 PEout(0)
#define motor1_IN2 PEout(1)
#define motor2_IN1 PEout(2)
#define motor2_IN2 PEout(3)

#define xunji_l  HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_7)
#define xunji_r HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_8)
#define xunji_l1 HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_9)//中间左边
#define xunji_r1 HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_10)//中间右边
#define guangdian HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_11)//  左边
void xunji_init(void);
void dancizhuaqu(u8 jishu);
#endif
