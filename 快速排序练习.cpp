#include <stdio.h>

// ��������Ԫ�ص�ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ����ѡ������ŦԪ�ؽ����黮��Ϊ�����֣���������ŦԪ�ص�����
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // ѡ����������һ��Ԫ����Ϊ��ŦԪ��
    int i = low - 1;  // i��С����ŦԪ�صĲ��ֵ����һ��Ԫ�ص�����

    for (int j = low; j < high; j++) {
        // �����ǰԪ��С�ڵ�����ŦԪ�أ����佻����С�ڲ���
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // ����ŦԪ�ؽ������ʵ���λ��
    swap(&arr[i + 1], &arr[high]);

    return i + 1;  // ������ŦԪ�ص���������
}

// ��������ݹ麯��
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // �������鲢��ȡ��ŦԪ�ص�����
        int pivotIndex = partition(arr, low, high);

        // ����ŦԪ����ߵ���������еݹ�����
        quickSort(arr, low, pivotIndex - 1);

        // ����ŦԪ���ұߵ���������еݹ�����
        quickSort(arr, pivotIndex + 1, high);
    }
}

// ��ӡ����Ԫ��
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 12, 7, 11, 8, 5, 2, 6, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("ԭʼ����: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("����������: ");
    printArray(arr, n);

    return 0;
}