#include "SST89x5x4.H"
void main(void)
{
	unsigned char data i;	//dataΪ�洢������˵��
	while(1)
	{
	P1 = P1 | 0xF0 ;	    //������4 λΪ����
	i = P1;					//��ȡP1����λ״̬
	P1 = (i>>4) & 0x0F;		//������λ�������������λ��������������
	}
}