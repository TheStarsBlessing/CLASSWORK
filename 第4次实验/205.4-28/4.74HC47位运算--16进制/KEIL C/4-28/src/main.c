#include "reg52.h"

void main(void)
{
    unsigned char a = 75;   // ʾ��ֵ
    unsigned char b = 133;   // ʾ��ֵ
    unsigned int result;

    result = (unsigned int)a * a + (unsigned int)b * b;

    P1 = (unsigned char)((result >> 8) & 0xFF); // �߰�λ����P1��
    P0 = (unsigned char)(result & 0xFF);        // �Ͱ�λ����P0��

    while (1);
}

//result ��һ�� unsigned int ���ͣ�ͨ����16λ������������8λ�󣬵õ����Ǹ�8λ��
//��Ϊ��ȷ��ֻ������8λ����������Ҫ�ĸ�8λ���ݣ���ʹ�� & 0xFF �������ε�����λ��Ӱ�졣