#include<stdio.h>

//���ֲ��Һ���
int binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		//���Ŀ������������
		if (arr[mid] == target) {
			return mid;//�ҵ�Ŀ��ֵ����������
		}
		else if (arr[mid] < target) {
			left = mid + 1;//���Ұ벿�ֲ���
		}
		else {
			right = mid - 1;//����벿�ֲ���
		}
	}
	return -1;//Ŀ�겻����
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int target;
	printf("������Ҫ���ҵ�Ŀ��ֵ��");
	if (scanf_s("%d", &target) != 1) {
		printf("������Ч��\n");
		return 1;//���ش�����
	}
	
	int result = binarySearch(arr, size, target);

	if (result != -1) {
		printf("Ŀ��ֵ%d�������У�����Ϊ%d��\n", target, result);
	}
	else {
		printf("Ŀ��ֵ%d���������С�\n", target);
	}
	return 0;
}