#include "bsp_pid.h"
#include "motor.h"
#include "stm32f1xx_it.h"


_pid pid1,pid2,pid3,pid4,pid1s,pid1s,pid1,pid2;//pidx->�ٶ�PID����pidxs->λ��PID��
static int32_t Last_CountA = 0,Last_CountB = 0;

void speed_pid_calculate(_pid *pid)
{


	pid->err = pid->aim - pid->now;
	if((pid->err<0.02 )&&(pid->err>-0.02)) pid->err = 0.0;
	pid->sum += pid->err;
	pid->out = pid->Kp * pid->err//����PID�����ٶ�ֵ
					 + pid->Ki * pid->sum
					 + pid->Kd * (pid->err - pid->err_last);
	pid->err_last = pid->err;
}


//void location_pid_calculate(void)
//{
//	pidAs.err = pidAs.aim - pidAs.now;
//	if((pidAs.err >= -40)&&(pidAs.err <= 40))
//	{
//		pidAs.err = 0;
//		pidAs.sum = 0;
//	}
//	if((pidAs.err>-1320)&&(pidAs.err<1320))
//	{
//		pidAs.sum += pidAs.err;
//		if(pidAs.sum>2000) pidAs.sum = 2000;
//		else if(pidAs.sum<-2000) pidAs.sum = -2000;
//	}
//	pidAs.out = pidAs.Kp*pidAs.err
//						 +pidAs.Ki*pidAs.sum
//						 +pidAs.Kd*(pidAs.err-pidAs.err_last);
//	pidAs.err_last = pidAs.err;
//	
//	
//	pidBs.err = pidBs.aim - pidBs.now;
//	if((pidBs.err >= -40)&&(pidBs.err <= 40))
//	{
//		pidBs.err = 0;
//		pidBs.sum = 0;
//	}
//	if((pidBs.err>-1320)&&(pidBs.err<1320))
//	{
//		pidBs.sum += pidBs.err;
//		if(pidBs.sum>2000) pidBs.sum = 2000;
//		else if(pidBs.sum<-2000) pidBs.sum = -2000;
//	}
//	pidBs.out = pidBs.Kp*pidBs.err
//						 +pidBs.Ki*pidBs.sum
//						 +pidBs.Kd*(pidBs.err-pidBs.err_last);
//	pidBs.err_last = pidBs.err;
//}

//void turn_pid_calculate(void)
//{
//	if((pid1.err >= -20)&&(pid1.err <= 20))
//	{
//		pid1.err = 0;
//		pid1.sum = 0;
//	}
//	if((pid1.err>-150)&&(pid1.err<150))
//	{
//		pid1.sum += pid1.err;
//		if(pid1.sum>2000) pid1.sum = 2000;
//		else if(pid1.sum<-2000) pid1.sum = -2000;
//	}
//	pid1.err = pid1.aim - pid1.now;
//	pid1.sum += pid1.err;
//	pid1.out = pid1.Kp * pid1.err +
//						 pid1.Kd * (pid1.err - pid1.err_last) +
//						 pid1.Ki * pid1.sum;
//	pid1.err_last = pid1.err;
//	
//	if((pid2.err >= -20)&&(pid2.err <= 20))
//	{
//		pid2.err = 0;
//		pid2.sum = 0;
//	}
//	if((pid2.err>-150)&&(pid2.err<150))
//	{
//		pid2.sum += pid2.err;
//		if(pid2.sum>2000) pid2.sum = 2000;
//		else if(pid2.sum<-2000) pid2.sum = -2000;
//	}
//	pid2.err = pid2.aim - pid2.now;
//	pid2.sum += pid2.err;
//	pid2.out = pid2.Kp * pid2.err +
//						 pid2.Kd * (pid2.err - pid2.err_last) +
//						 pid2.Ki * pid2.sum;
//	pid2.err_last = pid2.err;
//}

////void motor_pid_control(void)
////{
////  static uint32_t location_timer = 0;    // λ�û�����
////	
////  if(pid1.enable == 1) 
////  {
////    static __IO int32_t Capture_CountA = 0,Capture_CountB = 0;    // ��ǰʱ���ܼ���ֵ
////    Capture_CountA = motorA_count;
////		Capture_CountB = motorB_count;
////    
////		if(pid1.enable==0)
////		{
////			if(location_timer++%2 == 0)
////			{
////				pidAs.now = Capture_CountA;
////				pidBs.now = Capture_CountB;
////				location_pid_calculate();    // ���� PID ����
////			}
////			
////			float now_speedA = 0,now_speedB = 0; 
////			/* ת��ת�� = ��λʱ���ڵļ���ֵ / �������ֱܷ��� * ʱ��ϵ��  */
////			now_speedA = ((float)(Capture_CountA - Last_CountA) / Fenbianlv) * 10;
////			now_speedB = ((float)(Capture_CountB - Last_CountB) / Fenbianlv) * 10;

////			Last_CountA = Capture_CountA;
////			Last_CountB = Capture_CountB;

////			pid1.now = now_speedA;
////			pid2.now = now_speedB;
////			speed_pid_calculate();  // ���� PID ����
////			
////			Load(pid1.out,pid2.out);// ���� PWM ռ�ձ� 
////		}
////		else
////		{
////			pid1.now = Capture_CountA;
////			pid2.now = Capture_CountB;
////			turn_pid_calculate();
////			Load(pid1.out,pid2.out);
////		}
////		
////    
////  }
////	else
////	{
////		Load(0,0);
////	}
////}

//void set_target(int e,float cha,float chb,float bili)
//{
//	float A=0,B=0,c1=1.5,c2=1.5;
//	if(e)//e=1��ʹ�ܴ���PID,e=0ʱ��ֻʹ�� ����������
//	{
//		if(bili>1) c2 = c2/bili;
//		else c1 = c1*bili;
//		
//		//��Ŀ��Ϊ1Ȧ������ʱ�ٶ�Ϊ1.5 r/s���ٶ����� 1.5 r/s
//		if(pidAs.out > c1) A = c1;
//		else if(pidAs.out < -c1) A = -c1;
//		else A = pidAs.out;

//		if(pidBs.out > c2) B = c2;
//		else if(pidBs.out < -c2) B = -c2;
//		else B = pidBs.out;
//	}
//	A = A + cha;
//	B = B + chb;
//	
//	pid1.aim = A ;
//	pid2.aim = B ;
//}

///********************************
//����λ�� PID �Ĳ�����Ŀ��ֵ��Ȧ��
//*********************************/
//void Pid_Wz_target(float A,float B)
//{
//	//����λ�û���Ŀ��ֵ
//	pidAs.aim = A;
//	pidBs.aim = B;
//}

//void Pid_turn_target(float A,float B)
//{
//	//����λ�û���Ŀ��ֵ
//	pid1.aim = A;
//	pid2.aim = B;
//}

///*******************************
//����Pid�����еĸ��ּ���ֵ
//*******************************/
////void Pid_Count_clear(void)
////{
////	Last_CountA = 0;//�ϴ��ܼ���ֵ
////	Last_CountB = 0;
////	
////	TIM1->CNT = 0;//��ʱ����������ֵ
////	TIM4->CNT = 0;
////	
////	ClearEncoderA();//���������ֵ
////	ClearEncoderB();
////}

void Pid_Set(_pid *pid, float p, float i, float d)
{
	pid->Kp = p;
	pid->Ki = i;
	pid->Kd = d;
	
	pid->now =0;
	pid->err =0;
	pid->err_last =0;
	pid->sum =0;
	pid->aim =0;
}


void Pid_sum_clear(_pid *pid)//����Pid�Ļ���ֵ�����ֵ
{
	pid->sum = 0;
	pid->err_last = 0;
}


//	pid1.Kp = 2500;
//	pid1.Ki = 400;
//	pid1.Kd = 0;

void PID_param_init(void)
{
	Pid_Set(&pid1,5,0.8,0);
	Pid_Set(&pid2,5,0.8,0);
	Pid_Set(&pid3,5,0.8,0);
	Pid_Set(&pid4,5,0.8,0);
}

