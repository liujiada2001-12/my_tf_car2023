#include "encoder.h"
#include "bsp_motor.h"
#include "usart.h"
#include "tim.h"
//I1    KP  40  KI 0.05

//I2    KP  40  KI 0.05

//I3    KP  40  KI 0.05

//I4    KP  40  KI 0.05
float Kpp=100,Kip=30,Kid=0;	


int Pwm2=0,Bias2=0,Last_Bias2=0,Second_Bias2=0;
int Encoder1,Encoder2,Encoder3,Encoder4;
int Moto1,Moto2,Moto3,Moto4;
int Target_1=0,Target_2=0,Target_3=0,Target_4=0;
int max=9000;
int i=0;

void Move_Straight(int speed)
{
setspeed(speed,speed,speed,speed);
}

void Move_Left(int speed)
{
setspeed(speed,-speed,-speed,speed);
}

void Move_Right(int speed)
{
setspeed(-speed,speed,speed,-speed);
}	


void Tiao_Left(int speed1,int speed2)
{
setspeed(speed1,speed2,speed2,speed1);
}	

void Tiao_Right(int speed1,int speed2)
{
setspeed(speed2,speed1,speed1,speed2);
}	


struct err{
 
	double errp;
	double erri;
	double errd;
	double last_err;

};
struct err err1,err2,err3,err4;

struct PID{
		double kp,ki,kd;
		
			

};

struct PID pid1,pid2,pid3,pid4;




void setspeed(int t1,int t2,int t3,int t4){
	
	Target_1=t1;
	Target_2=t2;
	Target_3=t3;
	Target_4=t4;
}










void tianjia(struct PID i,double a,double b,double c){

i.kp=a;
i.ki=b;
i.kd=c;



}



void PID_init(){

  tianjia(pid1,40,0.05,0);
	tianjia(pid2,40,0.05,0);
	tianjia(pid3,40,0.05,0);
	tianjia(pid4,40,0.05,0);



}
int pwm1,pwm2,pwm3,pwm4;//  需要输出的量




struct PID pid1,pid2,pid3,pid4;



//A15  B3


//void TIM2_Config(void)			
//{
////	
////	/* USER CODE BEGIN TIM2_Init 0 */

////  /* USER CODE END TIM2_Init 0 */

////  TIM_Encoder_InitTypeDef sConfig = {0};
////  TIM_MasterConfigTypeDef sMasterConfig = {0};

////  /* USER CODE BEGIN TIM2_Init 1 */

////  /* USER CODE END TIM2_Init 1 */
////  htim2.Instance = TIM2;
////  htim2.Init.Prescaler = 0;
////  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
////  htim2.Init.Period = 65535;
////  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
////  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
////  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
////  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
////  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
////  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
////  sConfig.IC1Filter = 0;
////  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
////  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
////  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
////  sConfig.IC2Filter = 0;
////  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
////  {
////    Error_Handler();
////  }
////  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
////  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
////  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
////  {
////    Error_Handler();
////  }
////  /* USER CODE BEGIN TIM2_Init 2 */

////  /* USER CODE END TIM2_Init 2 */
//	
//	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_1|TIM_CHANNEL_2);
//	
//	
//	
//	
//	
//	
//	
////	GPIO_InitTypeDef GPIO_InitStructure;
////	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
////	NVIC_InitTypeDef NVIC_InitStructure;
////	TIM_ICInitTypeDef TIM2_ICInitStructure;

////	//使能TIM2时钟
////	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
////	
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
////	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
////	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2 , ENABLE);	//全映射


////	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;                  
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////	GPIO_Init(GPIOA, &GPIO_InitStructure);
////	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
////	GPIO_Init(GPIOB, &GPIO_InitStructure);
////	   
////	TIM_TimeBaseStructure.TIM_Period = 60000; 
////	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;        
////	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
////	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
////	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

////	TIM2_ICInitStructure.TIM_Channel = TIM_Channel_1|TIM_Channel_2; //CC1S=01      
////	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;   
////	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
////	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;  
////	TIM2_ICInitStructure.TIM_ICFilter = 6;
////	TIM_ICInit(TIM2,&TIM2_ICInitStructure);

////	//设置为编码器模式
////	TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
////	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
////	TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
////	TIM_SetCounter(TIM2, 30000);
////	TIM_Cmd(TIM2, ENABLE);
////	TIM2 -> CNT = 0;   //设置CNT为30000，arr 60000
//		 
//}





void TIM3_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	TIM_ICInitTypeDef TIM3_ICInitStructure;

//	//使能TIM3时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;                   
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
// 
//	TIM_DeInit(TIM3);
//	TIM_TimeBaseStructure.TIM_Period = 60000;  
//	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;        
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

//	TIM3_ICInitStructure.TIM_Channel = TIM_Channel_1|TIM_Channel_2;       
//	TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;   
//	TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
//	TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;  
//	TIM3_ICInitStructure.TIM_ICFilter = 6;
//	TIM_ICInit(TIM3,&TIM3_ICInitStructure);

//	//设置为编码器模式
//	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
//	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
//	TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);	//没有使能
//	TIM_SetCounter(TIM3, 0);
//	TIM_Cmd(TIM3, ENABLE);

	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1|TIM_CHANNEL_2);
		 
}


void TIM4_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	TIM_ICInitTypeDef TIM4_ICInitStructure;

//	//使能TIM4时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

//	/* GPIOB clock enable */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 

////	//优先级
////	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure); 

//	/*GPIOA Configuration: TIM4 channel 1 and 2 as alternate function push-pull */
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);


//	//   
//	TIM_DeInit(TIM4);
//	TIM_TimeBaseStructure.TIM_Period = 60000; 
//	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;         // 
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

//	//
//	TIM4_ICInitStructure.TIM_Channel = TIM_Channel_1|TIM_Channel_2; //CC1S=01      
//	TIM4_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;   
//	TIM4_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
//	TIM4_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;  
//	TIM4_ICInitStructure.TIM_ICFilter = 6;
//	TIM_ICInit(TIM4,&TIM4_ICInitStructure);

//	TIM_EncoderInterfaceConfig(TIM4,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
//	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
//	TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);	//没有使能
//	TIM_SetCounter(TIM4, 0);
//	TIM_Cmd(TIM4, ENABLE);
HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_1|TIM_CHANNEL_2);
		 
}


/*
	PA0 PA1	
*/
void TIM5_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	TIM_ICInitTypeDef TIM5_ICInitStructure;

//	//使能TIM5时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
//	/* GPIOA clock enable */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
//	//优先级
//	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure); 
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	TIM_DeInit(TIM5);
//	TIM_TimeBaseStructure.TIM_Period = 60000; 
//	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;        
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

//	//
//	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1|TIM_Channel_2; //CC1S=01      
//	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;   
//	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
//	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;  
//	TIM5_ICInitStructure.TIM_ICFilter = 6;
//	TIM_ICInit(TIM5,&TIM5_ICInitStructure);

//	//设置为编码器模式
//	TIM_EncoderInterfaceConfig(TIM5,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
//	TIM_ClearFlag(TIM5, TIM_FLAG_Update);
//	TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);	//没有使能
//	TIM_SetCounter(TIM5, 0);
//	TIM_Cmd(TIM5, ENABLE);
HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_1|TIM_CHANNEL_2);
}


void TIM6_Int_Init(u16 arr,u16 psc)
{
	HAL_TIM_Base_Start_IT(&htim3);			 
}





int Read_Encoder(u8 TIMX)
{
   int Encoder_TIM;    
   switch(TIMX)
	 {
		 case 2:  Encoder_TIM= TIM2 -> CNT; 
							if (Encoder_TIM> 50000)
							Encoder_TIM=-(60000-(TIM2 -> CNT));
							
							TIM2 -> CNT = 0;  break;
							
							
							
							
							
		 case 3:  Encoder_TIM= TIM3-> CNT; 
							if (Encoder_TIM> 50000)
							Encoder_TIM=-(60000-(TIM3 -> CNT));
							
							TIM3 -> CNT = 0;  break;
		 
							
		 case 4:  Encoder_TIM= TIM4 -> CNT; 
							if (Encoder_TIM> 50000)
							Encoder_TIM=-(60000-(TIM4 -> CNT));
							
							TIM4 -> CNT = 0;  break;
							
							
		 case 5:	Encoder_TIM= TIM5 -> CNT; 
							if (Encoder_TIM> 50000)
							Encoder_TIM=-(60000-(TIM5 -> CNT));
							
							TIM5 -> CNT = 0;  break; 
		 
							
							
							default:  Encoder_TIM=0;
	 }
		 return (Encoder_TIM);
}


int Incremental_PI_1 (int Encoder,int Target)
{ 	

	
	  err1.errp=Target_1-Encoder;                //计算偏差
	  err1.erri+=err1.errp;
	  err1.errd=err1.errp-err1.last_err;
  	pwm1 = 40*err1.errp+0.15*err1.erri;
		err1.last_err=err1.errp      ;            //保存上一次偏差 
  	return pwm1;                         //增量输出
}


//int Incremental_PI_2 (int Encoder,int Target)
//{ 	

//	
//	Bias2=Target-Encoder;                //计算偏差
//	pwm2+=Kpp*(Bias2-Last_Bias2+20*Bias2/Kip\
//	                    +Kid*(Bias2-2*Last_Bias2+Second_Bias2));
//	Second_Bias2=Last_Bias2;             //保存上上次偏差
//	Last_Bias2=Bias2;	                   //保存上一次偏差 
//	return pwm2;                         //增量输出
//}

int Incremental_PI_2 (int Encoder,int Target)
{ 	

	
		err2.errp=Target_2-Encoder;                //计算偏差
	 
  	err2.erri+=err2.errp;
	  
	  err2.errd=err2.errp-err2.last_err;
	
  	pwm2 = 40*err2.errp   +  0.15*err2.erri  + 0*err2.errd;
		err2.last_err=err2.errp      ;            //保存上一次偏差 
  	return pwm2;                         //增量输出                      //增量输出
}


int Incremental_PI_3 (int Encoder,int Target)
{ 	

	
    err3.errp=Target_3-Encoder;                //计算偏差
	 
  	err3.erri+=err3.errp;
	  
	  err3.errd=err3.errp-err3.last_err;
	
  	pwm3 = 40*err3.errp   +  0.15*err3.erri  +  0*err3.errd;
		err3.last_err=err3.errp      ;            //保存上一次偏差 
  	return pwm3;                         //增量输出                      //增量输出                     //增量输出
}

int Incremental_PI_4 (int Encoder,int Target)
{ 	

    err4.errp=Target_4-Encoder;                //计算偏差
	 
  	err4.erri+=err4.errp;
	  
	  err4.errd=err4.errp-err2.last_err;
	
  	pwm4 = 40*err4.errp   +  0.15*err4.erri  +  0*err2.errd;
		err4.last_err=err4.errp      ;            //保存上一次偏差 
  	return pwm4;                         //增量输出                      //增量输出
}



void pid_control()
{


		
			Encoder1=Read_Encoder(2);       //读取timer2对应的  读取编码器的值，M法测速，输出为每10ms的脉冲数
			Encoder2=Read_Encoder(3);				//读取timer3对应的  读取编码器的值，M法测速，输出为每10ms的脉冲数
			Encoder3=Read_Encoder(4);				//读取timer4对应的  读取编码器的值，M法测速，输出为每10ms的脉冲数
			Encoder4=Read_Encoder(5);				//读取timer5对应的  读取编码器的值，M法测速，输出为每10ms的脉冲数
			Moto1+=Incremental_PI_1(Encoder1,Target_1);	                              
			Moto2+=Incremental_PI_2(Encoder2,Target_2);		
			Moto3+=Incremental_PI_3(Encoder3,Target_3);	                          
			Moto4+=Incremental_PI_4(Encoder4,Target_4);	
//			printf("%daaaaaaaaaaaaaaaaaaaaa",Moto1);
//			printf("%dbbbbbbbbbbbbbbbbbbbbb",Moto2);
//			printf("%dccccccccccccccccccccc",Moto3);
//			printf("%deeeeeeeeeeeeeeeeeeeee",Moto4);
			Moto1=xf(Moto1);
			Moto2=xf(Moto2);
			Moto3=xf(Moto3);
			Moto4=xf(Moto4);						
}

int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}



void Set_Pwm(void)
{
	
	if(Moto1>0)			{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,1);
//	PEout(0)=0;			PEout(1)=1;
		}
	else 	          	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,0);
//	PEout(0)=1;			PEout(1)=0;
	}
	
	if(Moto2>0)			{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,1);
//	PEout(2)=0;			PEout(3)=1;
	}
	else 	          	{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,1);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,0);
//	PEout(2)=1;			PEout(3)=0;
	}
	
	if(Moto3>0)			{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,0);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,1);	
//	PEout(4)=0;			PEout(5)=1;
	}
	else 	          	{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,1);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,0);
//	PEout(4)=1;			PEout(5)=0;
	}
	if(Moto4>0)			{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,0);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
//	PEout(6)=0;			PEout(7)=1;
	}
	else 	          	{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,1);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//	PEout(6)=1;			PEout(7)=0;
	}
	
	
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,myabs(Moto1));
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,myabs(Moto2));
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,myabs(Moto3));
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,myabs(Moto4));
	
	
}


int xf(int x){

	if (x<-max)x=-max;
	if (x>max)x=max;
	
	return x;
	
	
}




