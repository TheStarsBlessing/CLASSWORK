#include "reg52.h"
#include "SMGled0.h"

void main(void)
{
    unsigned int result;
    unsigned char a = 75; // ʾ��ֵ
    unsigned char b = 133; // ʾ��ֵ
    result = (unsigned int)a * a + (unsigned int)b * b; // ���� a^2 + b^2
    P1 = smg_code[result%4096/256]; // ��ʾ9-12λ
    P1 &= ~0x80; // ���� P1.7 Ϊ 0����Ӱ������λ
    P1 = smg_code[result/4096] & 0x7F; // ��ʾ13-16λ�������� P1.7 Ϊ 0
    P0 = smg_code[result%16]; // ��ʾ1-4λ 
    P0 &= ~0x80; // ���� P0.7 Ϊ 0����Ӱ������λ
    P0 = smg_code[result%256/16] & 0x7F; // ��ʾ5-8λ�������� P0.7 Ϊ 0
    while (1);
}
//74hc573��LE��Ϊ�͵�ƽʱ�����ݱ����浽����ˣ���ʱ���Ըı�����˵����ݣ�������Ӱ������˵����ݡ�
//�����ڸߵ�ƽ�л����͵�ƽ��Ҫʱ�䣬��������Ӧ��ǰ��LE�����ͣ��Ա�����������������б��ı䡣
