#include "SST89x5x4.H"
void main(void)
{
	unsigned char data i;		   //dataΪ�洢������˵��
	while(1)
	{
	P3 = P3 | 0x0F ;			   //����P3�ڵ�4λΪ����
	i = P3;						   //��ȡP3����λ״̬
	P2 = (i<<4) & 0xF0;			   //��P3����λ�������������λ�������������P2�����
	}
}												 