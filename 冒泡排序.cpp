//输入数组元素，对其进行冒泡排序并输出

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n, i, j, temp;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	//检查内存是否分配成功
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}
	printf("Enter %d integers:", n);
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("Sorted array:");
	for (i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}