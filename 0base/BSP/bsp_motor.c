//#include "bsp_led.h"
#include "dwt_delay.h"
#include "sys.h"
#include "gpio.h"
#include "tim.h"
#include "bsp_motor.h"
#include "bsp_openmv.h"
#include "arm_task.h"
//#include "usart.h"
//#include "tim.h"
//#include "setspeed.h"

//#include "init.h"

///*------------使能PE0-PE7控制电机方向-------------------*/
u8 greencount=0,redcount=0;

void motor_IO_init(void)
{
	
	 GPIO_InitTypeDef  GPIO_InitStruct;
 	
  __HAL_RCC_GPIOE_CLK_ENABLE();
	
 GPIO_InitStruct.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;				 //LED0-->PB.5 端口配置
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;		 //推挽输出
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;		 //IO口速度为50MHz
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);				 //根据设定参数初始化GPIOB.5
}




///*       G9-G10灰度传感器         */
	
	void xunji_init(void)
{
	 GPIO_InitTypeDef  GPIO_InitStruct;
 	
  __HAL_RCC_GPIOG_CLK_ENABLE();
	
 GPIO_InitStruct.Pin=GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;				 //7，8右左循迹 9，10左右两侧，11光电
 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;         //输入模式
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;		 //IO口速度为50MHz
 HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);				 //根据设定参数初始化GPIOB.5	
}
//	


/*-----------------TIM1_pwm 初始化   PE9,E11，E13,E14-------------------*/
void tim1_pwm_init()
{
	//MX_TIM1
//	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
//  TIM_MasterConfigTypeDef sMasterConfig = {0};
//  TIM_OC_InitTypeDef sConfigOC = {0};
//  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

//  /* USER CODE BEGIN TIM1_Init 1 */

//  /* USER CODE END TIM1_Init 1 */
//  htim1.Instance = TIM1;
//  htim1.Init.Prescaler = 7200-1;
//  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
//  htim1.Init.Period = 10000-1;
//  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
//  htim1.Init.RepetitionCounter = 0;
//  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
//  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
//  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_TIM_OC_Init(&htim1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
//  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
//  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  sConfigOC.OCMode = TIM_OCMODE_TIMING;
//  sConfigOC.Pulse = 0;
//  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
//  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
//  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
//  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
//  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
//  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
//  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
//  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
//  sBreakDeadTimeConfig.DeadTime = 0;
//  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
//  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
//  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
//  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN TIM1_Init 2 */

//  /* USER CODE END TIM1_Init 2 */
//  HAL_TIM_MspPostInit(&htim1);
//	
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure; 
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//使能定时器1时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设
//	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);

//	
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
//	
////	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14;//输出PWM引脚
//	GPIO_Init(GPIOE,&GPIO_InitStructure);

//	
////初始化timer1
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructure.TIM_Period = arr;
//	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
//	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);

////初始化 timer1 pwm
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;	//???????????????????????????
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	TIM_OC1Init(TIM1,&TIM_OCInitStructure);
//	TIM_OC2Init(TIM1,&TIM_OCInitStructure);
//	TIM_OC3Init(TIM1,&TIM_OCInitStructure);
//	TIM_OC4Init(TIM1,&TIM_OCInitStructure);
//	

//	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
//	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
//	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);
//	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);	
//	
//	TIM_ARRPreloadConfig(TIM1,ENABLE);
//	TIM_CtrlPWMOutputs(TIM1,ENABLE);
//	TIM_SetCounter(TIM1,0);
//	

//	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);

//	TIM_Cmd(TIM1,ENABLE);
}



void zz()
{
  PEout(0)=0;
	PEout(1)=1;
	PEout(2)=0;
	PEout(3)=1;
	PEout(4)=0;
	PEout(5)=1;
	PEout(6)=0;
	PEout(7)=1;


}
void WanTiaoDD()
{
   if(xunji_l == 1&& xunji_r == 0)//左调
		{ 
			DWT_Delay(10);
			if(xunji_l == 1&& xunji_r == 0)
			{
			setspeed(40,10,10,40);
			DWT_Delay(100);
			setspeed(40,40,40,40);
			}
		}
		if(xunji_l == 0 &&xunji_r == 1)//右调
		{ 
			DWT_Delay(10);
			if(xunji_l == 0 &&xunji_r == 1)
			{
			setspeed(10,40,40,10);
			DWT_Delay(100);
			setspeed(40,40,40,40);
			}
		}
		if((xunji_l == 0 && xunji_r == 0)||(xunji_l == 1&& xunji_r == 1))//直走
		{
			DWT_Delay(10);
			if((xunji_l == 0 && xunji_r == 0)||(xunji_l == 1&& xunji_r == 1))
			{
				setspeed(40,40,40,40);
				DWT_Delay(50);

			 }
		}

}
void Right()
{
			 setspeed(-40,40,40,-40);//右转
			 DWT_Delay(1000);
			 DWT_Delay(1500);//转弯完成   90
	     DWT_Delay(900);
	     setspeed(40,40,40,40);
	     DWT_Delay(300);
}

void Left()
{
			 setspeed(40,-40,-40,40);//左转
			 DWT_Delay(1000);
			 DWT_Delay(1700);//转弯完成    90
			 DWT_Delay(500);
	     setspeed(40,40,40,40);
	     DWT_Delay(750);
}
void Leftgo(void)
{
while(1)
{
	setspeed(40,40,40,40);
  WanTiaoDD();
	if(xunji_l1==0)
	{
		DWT_Delay(20);
		if(xunji_l1==0)
		{
			Left();
			break;
		}
	
	}
}
}
void leftgozhong(void)
{
	while(1)
{
	setspeed(40,40,40,40);
  WanTiaoDD();
	if(xunji_l1==0&&xunji_r1==0)
	{
		DWT_Delay(20);
		if(xunji_l1==0&&xunji_r1==0)
		{
			Left();
			break;
		}
	
	}
}
}
void fang(u8 wt)
{
  int n;
	for(n=0;n<wt;n++)
		{
		WanTiaoDD();
		
		}
		 setspeed(0,0,0,0);
		stop();
		DWT_Delay(1000);
		controlarm(2);
  	DWT_Delay(1500);
		DWT_Delay(1500);
		DWT_Delay(1500);
//		stopActionGroup();
//		MoveStepper(1,750);

}
void stop(void)
{
  PEout(0)=0;
	PEout(1)=0;
	PEout(2)=0;
	PEout(3)=0;
	PEout(4)=0;
	PEout(5)=0;
	PEout(6)=0;
	PEout(7)=0;
	TIM1->CCR1=0;
	TIM1->CCR2=0;
	TIM1->CCR3=0;
	TIM1->CCR4=0;
}

void delay_s(u8 delay)
{
int delay_s;
for(delay_s=0;delay_s<delay;delay_s++)
{
DWT_Delay(1000);
}
}

void stopys(u8 ys)
{
	u8 k=0;
while(1)
{
	for(k=0;k<ys;k++)
	{
		stop();
		DWT_Delay(50);
	}
break;
}
}

void kuayue(void)
{
 while(1)
{
 WanTiaoDD();
 if(xunji_l1==0&&xunji_r1==1)
 {
  DWT_Delay(1000);
	break;
 }
}
}

void fz()
{
  PEout(0)=0;
	PEout(1)=1;
	PEout(2)=0;
	PEout(3)=1;
	PEout(4)=0;
	PEout(5)=1;
	PEout(6)=0;
	PEout(7)=1;


}
void Go(int i ,int j)
{
	if(i>0)
	{
	PEout(0)=0;
	PEout(1)=1;
	PEout(2)=0;
	PEout(3)=1;
	}
	if(i<0)
	{
	PEout(0)=1;
	PEout(1)=0;
	PEout(2)=1;
	PEout(3)=0;
		i=-i;
	}
	if(j>0)
	{
	PEout(4)=0;
	PEout(5)=1;
	PEout(6)=0;
	PEout(7)=1;
	}
	if(j<0)
	{
	PEout(4)=1;
	PEout(5)=0;
	PEout(6)=1;
	PEout(7)=0;
		j=-j;
	}
	TIM1->CCR1=i;
	TIM1->CCR2=i;
	TIM1->CCR3=j;
	TIM1->CCR4=j;
	
}

void dancizhuaqu(u8 jishu)
{
   setspeed(40,40,40,40);
	 flagr=flagg=0;
   while(1)
  { 
		WanTiaoDD();
		if(guangdian==0)
		{
			DWT_Delay(20);//消抖
			if(guangdian==0)
			{
			stop();
			DWT_Delay(200);
			DWT_Delay(1000);
      controlarm(6);                   // 转过去识别
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			printf("%d falgr\n\r",flagr);
		  printf("%d falgg\n\r",flagg);
			if(flagr)
			{redcount++;}
			if(flagg) 
			{greencount++;}
			DWT_Delay(1000);
			controlarm(1);                  //  抓取和回中
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			DWT_Delay(1000);
			break;
			}
		}		
  }
stopys(40);
if(jishu+1<=5&&flagg)
{
 flagg=0;
 Leftgo();
 Leftgo();
 fang(greencount*30);
 stopys(100);
 Leftgo();
 DWT_Delay(750);
}
if(jishu+1>5&&flagg)
{
 flagg=0;
 Leftgo();
 Leftgo();
 kuayue();
 fang(greencount*30);
 stopys(100);
 Leftgo();
 DWT_Delay(750);
}
//if((jishu+1==6) && flagg)
//{
// flagg=0;
//// kuayue();
// Leftgo();
// Leftgo();
//// kuayue();
// fang(greencount*12);
// stopys(40);////////////////////gaigaigai
// init_all();
// Leftgo();
//}
if(flagr && jishu+1<=5)
{
 flagr=0;
 kuayue();
 Leftgo();
 Leftgo();
 fang(redcount*30);/////////传参传参传参传参传参传参
 stopys(100);///////////////////gaigaigai
 kuayue();
 Leftgo();
 DWT_Delay(750);
}

if(flagr && jishu+1>5 && jishu+1<=9)
{
 flagr=0;
 Leftgo();
 Leftgo();
 fang(redcount*30);/////////传参传参传参传参传参传参
 stopys(100); //////////////////gaigaigai
// kuayue();/////////////////12.17
 Leftgo();
	DWT_Delay(750);
}
//if(flagr && jishu+1==6)
//{
// flagr=0;
// kuayue();
// Leftgo();
// Leftgo();
// fang(redcount*12);/////////传参传参传参传参传参传参
// stopys(40); //////////////////gaigaigai
// init_all();
//// kuayue();/////////////////12.17
// Leftgo();
//}
if(flagr && jishu+1==10)//最后一个是红色
{
 flagr=0;
 Leftgo();
 Leftgo();
 fang(redcount*30);
 stopys(100);
	kuayue();
 Leftgo();
	DWT_Delay(750);
}
if(flagg && jishu+1==10)//最后一个是绿的
{
	 flagg=0;
	 Leftgo();
	 Leftgo();
	 kuayue();
	 fang(greencount*30);
	 stopys(100);////////////////////gaigaigai
	 Leftgo();
	DWT_Delay(750);
}
}









