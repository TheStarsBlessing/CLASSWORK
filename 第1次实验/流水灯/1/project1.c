#include "SST89x5x4.H"
#include "intrins.h"			  //���ͷ�ļ����������ƺ���_crol_()
#define LED_PORT P2				  //����P2��
unsigned char n;
void Delay_t_100ms(unsigned char t)	//@11.0592MHz
{
	while(t--)
	{
		unsigned char i, j;

		i = 180;
		j = 73;
		do
		{
			while (--j);
		} while (--i);
	}
}
						  //100ms��ʱ��������������STC-ISP����
void main()
{
	LED_PORT=0xFE;				  //����P2.0LED��
	while(1)									//ѭ���ƶ�
	{
		for(n=0;n<8;n++)						
		{
			LED_PORT=_crol_(LED_PORT,1);		//��������0~8λ��������������ƺ���
			Delay_t_100ms(5);					//�����ʱ
		}						  //����ѭ��
	}
}