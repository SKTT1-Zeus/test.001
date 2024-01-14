//输入数组元素，对其进行快速排序输出。

#include<stdio.h>
#include<stdlib.h>

void quickSort(int[], int, int);
int partition(int[], int, int);

// 交换数组中两个元素的位置
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void quickSort(int arr[], int low, int high) {

	int pi;
	if (low < high) {
		pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// partition 函数，返回基准值的索引
int partition(int arr[], int low, int high) {
    // 选择最右侧元素作为基准值
    int pivot = arr[high];
    // 记录小于基准值的元素的位置
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        // 如果当前元素小于等于基准值，则交换位置
        if (arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    // 将基准值放到正确的位置
    swap(&arr[i + 1], &arr[high]);

    // 返回基准值的索引
    return i + 1;
}
int main() {

    int n, i;
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
        scanf_s("%d", arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array:");
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}