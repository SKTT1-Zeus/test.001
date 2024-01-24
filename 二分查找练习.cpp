#include<stdio.h>

// ���ֲ��Һ���
int binarySearch(int arr[], int size, int target) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // ����ҵ�Ŀ��ֵ����������
        if (arr[mid] == target) {
            return mid;
        }

        // ���Ŀ��ֵ����벿�֣���С������Χ����벿��
        if (arr[mid] > target) {
            high = mid - 1;
        }

        // ���Ŀ��ֵ���Ұ벿�֣���С������Χ���Ұ벿��
        else {
            low = mid + 1;
        }
    }

    // ���δ�ҵ�Ŀ��ֵ������-1
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