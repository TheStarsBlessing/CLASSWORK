ORG 0000H
// �������ݴ洢��ַ
DATA1  DATA 30H  // ���ݿ�1����ʼ��ַ
DATA2  DATA 40H  // ���ݿ�2����ʼ��ַ
LEN    DATA 50H  // �Ƚϳ��ȵĴ洢��ַ
RESULT DATA 51H  // �洢�ȽϽ���ĵ�ַ

SJMP START

START:
    // ��ʼ�����ݿ�1
    MOV DATA1, #00H  // �������ݿ�1��ֵ
    MOV 31H, #01H    
    MOV 32H, #02H
    MOV 33H, #03H
    MOV 34H, #04H

    // ��ʼ�����ݿ�2
    MOV DATA2, #00H  // �������ݿ�2��ֵ
	MOV 41H, #01H
    MOV 42H, #02H    
    MOV 43H, #03H
    MOV 44H, #04H

    // ���ñȽϳ���
    MOV LEN, #05H  // �Ƚϳ�����Ϊ5

    // ���üĴ���R0��R1ָ�����ݿ�1�����ݿ�2����ʼ��ַ
    MOV R0, #30H  // R0ָ�����ݿ�1����ʼ��ַ
    MOV R1, #40H  // R1ָ�����ݿ�2����ʼ��ַ

    // ���Ƚϳ��ȼ��ص��Ĵ���R2��
    MOV R2, LEN     // ��LEN��ֵ����R2����Ϊѭ��������

COMPARE_LOOP:
    // ����Ƿ���Ҫ���бȽ�
    CJNE R2, #0, COMPARE  // ���R2��Ϊ0������ת��COMPARE��ǩ
    MOV A, #0FFH          // ���R2Ϊ0����ʾ�Ƚ���ɣ�����AΪ0FFH
    SJMP STORE_RESULT     // ��ת��STORE_RESULT��ǩ�洢���

COMPARE:
    // �Ƚ����ݿ�1�����ݿ�2�е�ֵ
    MOV A, @R0  // ��R0ָ���ֵ���ص�A�Ĵ���
    MOV B, @R1  // ��R1ָ���ֵ���ص�B�Ĵ���
    CJNE A, B, NOT_EQUAL  // ���A��B����ȣ���ת��NOT_EQUAL��ǩ

    // �����ǰֵ��ȣ������Ƚ���һ��ֵ
    INC R0       // ����R0ָ�룬ָ����һ������
    INC R1       // ����R1ָ�룬ָ����һ������
    DEC R2       // ���ټ�����R2
    SJMP COMPARE_LOOP  // ��ת��COMPARE_LOOP�����Ƚ�

NOT_EQUAL:
    // ������ֲ���ȵ�ֵ
    MOV A, #0  // ����AΪ0����ʾ�Ƚ�ʧ��

STORE_RESULT:
    // �洢�ȽϽ��
    MOV RESULT, A  // ��A��ֵ�洢��RESULT��ַ

END_PROGRAM:
    // ���������������ѭ��
    SJMP $  // ��ת����ǰ��ַ������ֹͣ����

END