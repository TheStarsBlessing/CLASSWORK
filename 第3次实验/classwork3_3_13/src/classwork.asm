ORG 0000H          ; ����洢���ӵ�ַ0000H��ʼ
    SJMP START     ; ��ת������ʼ��

START:
    MOV 20H, #01H   ; ��01H����20H��ַ�����ں�������
    MOV 21H, #02H   ; ��02H����21H��ַ�����ں�������    
    MOV 22H, #03H   ; ��03H����22H��ַ�����ں�������
    MOV 23H, #0DH   ; ��0DH����23H��ַ����Ϊ������־

    MOV DPTR, #7E01H ; ����DPTRΪ�ⲿ���ݴ洢������ʼ��ַ

    MOV R0, #20H     ; ����R0Ϊ�ڲ�RAM���ݿ����ʼ��ַ
    MOV R1, #00H     ; ��ʼ��R2Ϊ���ȼ�����

COUNT_LENGTH:
    MOV A, @R0       ; ��ȡ�ڲ�RAM��ǰ��ַ������
    CJNE A, #0DH, COPY_DATA ; ������ݲ��ǽ�����־0DH����ת��COPY_DATA
    SJMP STORE_LENGTH ; ��������ǽ�����־0DH����ת��STORE_LENGTH

COPY_DATA:
    MOVX @DPTR, A    ; ������д���ⲿ���ݴ洢��
    INC R0           ; �ڲ�RAM��ַ��1
    INC DPTR         ; �ⲿ���ݴ洢����ַ��1
    INC R1           ; ���ȼ�������1
    SJMP COUNT_LENGTH ; ����ѭ��

STORE_LENGTH:
	MOVX @DPTR, A    ; ������д���ⲿ���ݴ洢��
    INC R1           ; ���ȼ�������1
    MOV DPTR, #7E00H ; ����DPTRΪ�ⲿ���ݴ洢���ĳ��ȴ洢��ַ
    MOV A, R1        ; �����ȼ�������ֵ�����ۼ���A
    MOVX @DPTR, A    ; ������д���ⲿ���ݴ洢����7E00H��ַ
	
END_PROGRAM:
    SJMP $          ; ����ѭ��
END  ; �������