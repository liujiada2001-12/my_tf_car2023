#ifndef __ENCODER_H
#define __ENCODER_H

#include "bsp_motor.h"


void Set_Pwm(void);
int myabs(int a);
extern int Encoder1,Encoder2,Encoder3,Encoder4;
int Incremental_PI_4 (int Encoder,int Target);
int Incremental_PI_3 (int Encoder,int Target);
int Incremental_PI_2 (int Encoder,int Target);
int Incremental_PI_1 (int Encoder,int Target);
void TIM2_Config(void);
void TIM3_Config(void);
void TIM4_Config(void);
void TIM5_Config(void);
void TIM6_Int_Init(u16 arr,u16 psc);
int xf(int x);
void PID_init(void);
void Move_Straight(int speed);//均已初始（草标）为准
void Move_Left(int speed);
void Move_Right(int speed);
void Tiao_Left(int speed1,int speed2);
void Tiao_Right(int speed1,int speed2);
void setspeed(int t1,int t2,int t3,int t4);
void pid_control(void);

#endif




















