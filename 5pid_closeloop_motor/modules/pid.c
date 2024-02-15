#include "pid.h"

tpid pid1;
tpid pid2;
tpid pid3;
tpid pid4;
//40 0.05 0

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
	
	pid_set(&pid1,40,0.05,0);
	pid_set(&pid2,40,0.05,0);
	pid_set(&pid3,40,0.05,0);
	pid_set(&pid4,40,0.05,0);
	
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
	pid->err_sum+=	pid->err;
	pid->out=pid->kp*pid->err + pid->ki*pid->err_sum + pid->kd*(pid->err-pid->err_last);
	pid->err_last=pid->err;
	return pid->out;
}

