#include<stdio.h>

// 二分查找函数
int binarySearch(int arr[], int size, int target) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // 如果找到目标值，返回索引
        if (arr[mid] == target) {
            return mid;
        }

        // 如果目标值在左半部分，缩小搜索范围到左半部分
        if (arr[mid] > target) {
            high = mid - 1;
        }

        // 如果目标值在右半部分，缩小搜索范围到右半部分
        else {
            low = mid + 1;
        }
    }

    // 如果未找到目标值，返回-1
    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    }
    else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}