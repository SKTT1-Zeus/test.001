//��������Ԫ�أ�������Ͳ����

#include <stdio.h>
#include<stdlib.h>

int main() {
    int n, i, sum = 0;

    // ��ʾ�û�����Ԫ�ص�����
    printf("Enter the number of elements: ");
    scanf_s("%d", &n);

    // ʹ�ö�̬�ڴ��������������
    int* arr = (int*)malloc(n * sizeof(int));

    // ����ڴ��Ƿ����ɹ�
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // ���ط���ֵ��ʾ����ִ��ʧ��
    }

    // ��ʾ�û���������Ԫ��
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; ++i) {
        scanf_s("%d", &arr[i]);
        sum += arr[i];
    }

    // ��ӡ����Ԫ�صĺ�
    printf("Sum = %d\n", sum);

    // �ͷŶ�̬������ڴ�
    free(arr);

    return 0;
}