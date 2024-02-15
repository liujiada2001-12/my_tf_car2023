#include "pid.h"

tpid pid1,pid1s;
tpid pid2;
tpid pid3;
tpid pid4;
//10,0.01,0

void pid_init()
{
	pid1.actual_val=0.0;
	pid1.target_val=0.00;
	pid1.err=0.0;
	pid1.err_last=0.0;
	pid1.err_sum=0.0;
	pid1.kp=0;
	pid1.ki=0;
	pid1.kd=0;
	pid1.out=0;
	
	pid2.actual_val=0.0;
	pid2.target_val=0.00;
	pid2.err=0.0;
	pid2.err_last=0.0;
	pid2.err_sum=0.0;
	pid2.kp=0;
	pid2.ki=0;
	pid2.kd=0;
	pid2.out=0;
	
	pid3.actual_val=0.0;
	pid3.target_val=0.00;
	pid3.err=0.0;
	pid3.err_last=0.0;
	pid3.err_sum=0.0;
	pid3.kp=0;
	pid3.ki=0;
	pid3.kd=0;
	pid3.out=0;
	
	pid4.actual_val=0.0;
	pid4.target_val=0.00;
	pid4.err=0.0;
	pid4.err_last=0.0;
	pid4.err_sum=0.0;
	pid4.kp=0;
	pid4.ki=0;
	pid4.kd=0;
	pid4.out=0;
	
	pid1s.actual_val=0.0;
	pid1s.target_val=0.00;
	pid1s.err=0.0;
	pid1s.err_last=0.0;
	pid1s.err_sum=0.0;
	pid1s.kp=0;
	pid1s.ki=0;
	pid1s.kd=0;
	pid1s.out=0;
	
	pid_set(&pid1,10,0,0);
	pid_set(&pid2,10,0,0);
	pid_set(&pid3,10,0,0);
	pid_set(&pid4,10,0,0);
	pid_set(&pid1s,10,0,0.01);
}

void pid_set(tpid *pid,float kp,float ki,float kd)
{
	pid->kp=kp;
	pid->ki=ki;
	pid->kd=kd;
}

float p_realize(tpid *pid,float actual_val)
{
	pid->actual_val=actual_val;
	pid->err=pid->target_val-pid->actual_val;
	pid->out=pid->kp*pid->err;
	return pid->out;
}

float pi_realize(tpid *pid,float actual_val)
{
	pid->actual_val=actual_val;
	pid->err=pid->target_val-pid->actual_val;
	pid->err_sum+=	pid->err;
	pid->out=pid->kp*pid->err + pid->ki*pid->err_sum;
	return pid->out;
}

float pid_realize(tpid *pid,float actual_val)
{
	pid->actual_val=actual_val;
	pid->err=pid->target_val-pid->actual_val;
//	if(pid->err<10&&pid->err>-10) pid->err=0;
	pid->err_sum+=	pid->err;
	pid->out=pid->kp*pid->err + pid->ki*pid->err_sum + pid->kd*(pid->err-pid->err_last);
	pid->err_last=pid->err;
	return pid->out;
}

float pid_realize_s(tpid *pid,float actual_val)
{
	pid->actual_val=actual_val;
	pid->err=pid->target_val-pid->actual_val;
	if(pid->err<10&&pid->err>-10) pid->err=0;
	pid->err_sum+=	pid->err;
	pid->out=pid->kp*pid->err + pid->ki*pid->err_sum + pid->kd*(pid->err-pid->err_last);
	pid->err_last=pid->err;
	if(pid->out>80) pid->out=80;
	if(pid->out<-80) pid->out=-80;
	if(pid->out>-5&&pid->out<5) pid->out=0;
	return pid->out;
}