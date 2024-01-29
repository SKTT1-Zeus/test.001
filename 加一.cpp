#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // �������飬�����һλ��ʼ��һ
    for (int i = digitsSize - 1; i >= 0; i--) {
        // �����ǰλС��9��ֱ�Ӽ�һ����
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        else {
            // �����ǰλ��9������ǰλ��Ϊ0��������ǰ��λ
            digits[i] = 0;
        }
    }

    // ���������������Ȼ��Ҫ��λ��˵�����λ�����˽�λ����Ҫ������ǰ����һλ1
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = digits[i - 1];
    }

    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    int digits[] = { 9, 9, 9 };  // ʾ������
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("��һ��Ľ����");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);  // �ͷŶ�̬������ڴ�
    return 0;
}