//输入数组元素，对其求最大值和最小值并输出

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
	int max,min;
	int* arr = (int*)malloc(n * sizeof(int));

	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	printf("Enter %d integers:", n);
	for (i = 0; i < n; ++i)
	{
		scanf_s("%d", &arr[i]);
	}
	max = min = arr[0];
	for (i = 1; i < n; ++i)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("Maximum element=%d\n", max);
	printf("Mininum element=%d", min);

	free(arr);

	return 0;
}