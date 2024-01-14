//��������Ԫ�أ�������п������������

#include<stdio.h>
#include<stdlib.h>

void quickSort(int[], int, int);
int partition(int[], int, int);

// ��������������Ԫ�ص�λ��
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

// partition ���������ػ�׼ֵ������
int partition(int arr[], int low, int high) {
    // ѡ�����Ҳ�Ԫ����Ϊ��׼ֵ
    int pivot = arr[high];
    // ��¼С�ڻ�׼ֵ��Ԫ�ص�λ��
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        // �����ǰԪ��С�ڵ��ڻ�׼ֵ���򽻻�λ��
        if (arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    // ����׼ֵ�ŵ���ȷ��λ��
    swap(&arr[i + 1], &arr[high]);

    // ���ػ�׼ֵ������
    return i + 1;
}
int main() {

    int n, i;
    printf("Enter the number of elements:");
    scanf_s("%d", &n);
    //���䶯̬�ڴ�
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("�ڴ����ʧ��\n");
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