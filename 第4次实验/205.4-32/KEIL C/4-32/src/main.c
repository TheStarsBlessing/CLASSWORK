#include "reg52.h"

void main(void) {
    // ����һ��3x3����
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int primaryDiagonalSum = 0;  // ���Խ��ߺ�
    int secondaryDiagonalSum = 0; // ���Խ��ߺ�
    int totalDiagonalSum;       // �ܶԽ��ߺ�
    int i; // ѭ������

    // �������Խ��ߺ͸��Խ��ߵĺ�
    for (i = 0; i < 3; i++) {
        primaryDiagonalSum += matrix[i][i];          // ���Խ���Ԫ��
        secondaryDiagonalSum += matrix[i][2 - i];     // ���Խ���Ԫ��
    }

    // �ܺ�Ϊ�����Խ���Ԫ��֮��
    totalDiagonalSum = primaryDiagonalSum + secondaryDiagonalSum-matrix[1][1];

    // ���������һ������������������LED���ߴ��ڵ��豸
    // displayResult(totalDiagonalSum);  

    while (1) {
        // �ȴ�ѭ��
    }
}