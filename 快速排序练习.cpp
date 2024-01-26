#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 根据选定的枢纽元素将数组划分为两部分，并返回枢纽元素的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择数组的最后一个元素作为枢纽元素
    int i = low - 1;  // i是小于枢纽元素的部分的最后一个元素的索引

    for (int j = low; j < high; j++) {
        // 如果当前元素小于等于枢纽元素，将其交换到小于部分
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // 将枢纽元素交换到适当的位置
    swap(&arr[i + 1], &arr[high]);

    return i + 1;  // 返回枢纽元素的最终索引
}

// 快速排序递归函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 划分数组并获取枢纽元素的索引
        int pivotIndex = partition(arr, low, high);

        // 对枢纽元素左边的子数组进行递归排序
        quickSort(arr, low, pivotIndex - 1);

        // 对枢纽元素右边的子数组进行递归排序
        quickSort(arr, pivotIndex + 1, high);
    }
}

// 打印数组元素
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 12, 7, 11, 8, 5, 2, 6, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}