#include "SST89x5x4.h"
#include "Intrins.h"

void delay(void)				 //��ʱ����
{
	unsigned int x;
	for(x=0; x<0xFFFF; x++);
}

void int0_isr() interrupt 0		 //INT0 �жϣ��ⲿ�ж�0 ���жϺ�Ϊ0
{
	unsigned char j;
	for(j=0; j<4; j++)
	{
		P1 = 0xFF; 
		delay();
		P1 = 0x00;
		delay();				 //ʹLED ��˸
	}	
}

void int2_isr() interrupt 2		 //INT1 �жϣ��ⲿ�ж�1 ���жϺ�Ϊ2
{
	unsigned char i=0x03, j;
	for(j=0; j<16; j++)
	{
		P1 = i; 
		i = _crol_(i, 2);
		delay();
	}							 //ʹLED ��ˮ��ʾ
	P1 = 0x00;					 //������Ϩ��LED
}

void main()
{
	P1 = 0x00;
	IP=0x04;					//�ⲿ�ж�1����Ϊ�����ȼ�
	IT0 = 1; EX0 = 1; 			//�ж�0������Ϊ���ش���
	IT1 = 1; EX1 = 1; 			//�ж�1������Ϊ���ش���
	EA = 1;						//CPU�����ж�
	while(1);					//�ȴ��ж�ָ��
}
