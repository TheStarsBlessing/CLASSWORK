#include "SST89x5x4.H"
#define uchar unsigned char
#define unit unsigned int		 //���¶���ؼ���
sbit in = P1^0;
sbit out = P1^7;			     //��P1.0��P1.7���ж���

void main(void)
{
	while(1)					 //����ѭ��
	{
		in = 1;					 //��P1.0������λ���ų�����
		if (in == 0)			 
			out = 0;			 //����������ʱ����LED��
		else
			out = 1;   			 //�������LED����Ϩ��
	}
}								 //������