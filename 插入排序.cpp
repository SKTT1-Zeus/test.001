//��������Ԫ�أ��������ѡ���������

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n, i, j, key;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
	//��̬�ڴ����
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("�ڴ����ʧ��\n");
		return 1;
	}
	printf("Enter %d integers:", n);
	for (i = 0; i < n; ++i) {
		scanf_s("%d", &arr[i]);
	}
	for (i = 1; i < n; ++i) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	printf("Sorted array:");
	for (i = 0; i < n; ++i) {
		printf("%d", arr[i]);
	}
	return 0;
}