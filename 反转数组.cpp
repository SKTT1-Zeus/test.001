//��������Ԫ�أ����䷴ת�����

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n,i,temp;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
    // ʹ��malloc��̬�����ڴ�
    int* arr = (int*)malloc(n * sizeof(int));

    // ����ڴ�����Ƿ�ɹ�
    if (arr == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1; // ���ط���ֵ��ʾ�����쳣�˳�
    }
    printf("Enter %d integers:", n);
    for (i = 0; i < n; ++i)
    {
        scanf_s("%d", &arr[i]);
    }
    for (i = 0; i < n / 2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    printf("Reversed array:");
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}