//输入数组元素，对其进行希尔排序并输出

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n, i, j, gap, temp;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
	//分配动态内存
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}
	printf("Enter %d integers:", n);
	for (i = 0; i < n; ++i) {
		scanf_s("%d", &arr[i]);
	}
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; ++i) {
			temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	printf("Sorted array:");
	for (i = 0; i < n; ++i) {
		printf("%d", arr[i]);
	}
	return 0;
}