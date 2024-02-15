#include "move.h"
#include "tim.h"
#include "gpio.h"
#include "sys.h"
#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "gpio.h"
#include "main.h"
#include "cmd.h"
extern int v1,v2,v3,v4;
void track(void)
{
		if(FL_LIGHT ==0 && FR_LIGHT ==1)
		{
			v1=50;
			v3=10;
			v2=10;
			v4=50;
		}
		else if(FL_LIGHT ==1 && FR_LIGHT ==0)
		{
			v1=10;
			v3=50;
			v2=50;
			v4=10;
		}
		else
		{
			v1=50;
			v3=50;
			v2=50;
			v4=50;
		}
}