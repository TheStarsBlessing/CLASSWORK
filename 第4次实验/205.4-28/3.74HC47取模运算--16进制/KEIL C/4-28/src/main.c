#include "reg52.h"

unsigned int square_sum(unsigned char a, unsigned char b);
void main(void)
{
    unsigned int result;
    result=square_sum(75, 133); // ʾ��ֵ
    P1 = result/256; // �߰�λ����P1��
    P0 = result%256; // �Ͱ�λ����P0��
    while (1);
}

unsigned int square_sum(unsigned char a, unsigned char b)
{
    return (unsigned int)a * a + (unsigned int)b * b; // ����ƽ����
}   
