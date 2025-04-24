#include<SST89x5x4.H>

unsigned char code table[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};	  //�������

void delay(unsigned char delay_time) 	   //��ʱ����
{
	unsigned char i,j;

	for(i=0;i<=delay_time;i++) 
	{
		for(j=0;j<=200;j++);
	}
}

void init_tx() 								//�жϺ�������
{
	EA=1; EX0=1; IP=0x00;	//CPU�����жϣ��ⲿ�ж�0���ţ������ж�Դ����Ϊ�����ȼ�
}

void main()
{
	unsigned char i;
	init_tx();				 //�����жϺ���
	while(1)
	{
		for(i=0;i<6;i++)
		{
			P1=table[i]; 
			delay(200);
		}
	}						 //�ж�δ����ʱ����ѭ���������
}

void tx0() interrupt 0		   //�����жϺ���øú���
{
	unsigned char i;
	P1=0x00;
	delay(200);
	for(i=0;i<=15;i++)//ע�⣬��˸8��Ӧ�ý���16�ε�ƽ��ת P1=~P1;
	{
		P1=~P1;
		delay(200);			  //��˸8��
	}
}