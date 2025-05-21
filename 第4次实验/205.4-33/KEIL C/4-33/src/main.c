#include <reg51.h>

// �����ⲿRAM����ʼ��ַ
#define EXT_RAM_START 0x70

void main(void) {
    unsigned char i;
    // ʹ��xdata�ؼ���ָ��ָ��ָ���ⲿRAM
    unsigned char xdata *ext_ram = (unsigned char xdata *)EXT_RAM_START;

    // ��֪ǰ������Ԫ����Ϊ1
    ext_ram[0] = 1;  // ��ʼ��
    ext_ram[1] = 1;  // ��ʼ��

    // �����������8��쳲����������洢�ں�����ַ��
    for (i = 2; i < 10; i++) {
        ext_ram[i] = ext_ram[i - 1] + ext_ram[i - 2];
    }

    // ��������󱣳�ѭ��
    while (1);
}