#ifndef IMU_H_
#define IMU_H_

#include "stdio.h"
#include <string.h>
#include "stdint.h"
#include "jy901.h"
#define RXBUFFER_LEN 99		//����9�����ݣ�һ��99λ,Ŀǰ��4��
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


typedef struct//��Ԫ��
{ float q[4];
}SQ;

typedef struct//�ų����
{
	float h[3];
}SMag;

typedef struct//��ѹ�߶�
{
	float lPressure;
	float lAltitude;
}SPress;

typedef struct//��γ��
{
	float lLon;
	float lLat;
}SLonLat;

typedef struct
{
		uint8_t Rx_flag;											
		uint8_t Rx_len;												
		uint8_t frame_head;					//֡ͷ
		uint8_t RxBuffer[RXBUFFER_LEN];		//���ջ���
		Angle angle;						//�Ƕ�
		Acc acc;								//���ٶ�
		SGyro w;								//���ٶ�
		SMag h;									//�ų�
		SPress lPressure;   	  //��ѹ
		SPress lAltitude;     	//�߶�
		SLonLat lLon;						//����
		SLonLat lLat;						//ά��
		SQ q; 									//��Ԫ��
}User_USART;
void User_USART_Init(User_USART *Data);
void JY901_Process(void);

#endif /* IMU_H_ */