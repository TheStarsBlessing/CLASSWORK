#include "reg52.h"
#include "SMGled0.h"

unsigned char square_sum(unsigned char a, unsigned char b);
void main(void)
{
    unsigned char result;
    result=square_sum(3, 5); // ʾ��ֵ
    P1 = smg_code[result/10]; // ��ʾʮλ
    P0 = smg_code[result%10]; // ��ʾ��λ
    while (1);
}

unsigned char square_sum(unsigned char a, unsigned char b)
{
    return a * a + b * b; // ����ƽ����
}   
