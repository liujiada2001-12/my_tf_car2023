#ifndef IMU_H_
#define IMU_H_

#include "stdio.h"
#include <string.h>
#include "stdint.h"
#include "jy901.h"
#define RXBUFFER_LEN 99		//接收9类数据，一共99位,目前收4类
typedef struct
{
	float angle[3];
}Angle;

typedef struct
{
	float a[3];
}Acc;

typedef struct
{
	float w[3];
}SGyro;


typedef struct//四元数
{ float q[4];
}SQ;

typedef struct//磁场输出
{
	float h[3];
}SMag;

typedef struct//气压高度
{
	float lPressure;
	float lAltitude;
}SPress;

typedef struct//经纬度
{
	float lLon;
	float lLat;
}SLonLat;

typedef struct
{
		uint8_t Rx_flag;											
		uint8_t Rx_len;												
		uint8_t frame_head;					//帧头
		uint8_t RxBuffer[RXBUFFER_LEN];		//接收缓冲
		Angle angle;						//角度
		Acc acc;								//加速度
		SGyro w;								//角速度
		SMag h;									//磁场
		SPress lPressure;   	  //气压
		SPress lAltitude;     	//高度
		SLonLat lLon;						//经度
		SLonLat lLat;						//维度
		SQ q; 									//四元数
}User_USART;
void User_USART_Init(User_USART *Data);
void JY901_Process(void);

#endif /* IMU_H_ */