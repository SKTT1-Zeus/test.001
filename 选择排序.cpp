//输入数组元素，对其进行选择排序并输出

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n, i, j, min, temp;
	printf("Enter the number of elements");
	scanf_s("%d", &n);
	//分配动态内存
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	printf("Enter %d integers:", n);
	for (i = 0; i < n - 1; ++i) {
		min = i;
		for (j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	printf("Sorted array:");
	for (i = 0; i < n; ++i) {
		printf("%d", arr[i]);
	}
	return 0;
}