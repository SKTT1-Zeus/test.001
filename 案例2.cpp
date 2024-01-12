#include<stdio.h>

//二分查找函数
int binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		//如果目标在数组的左侧
		if (arr[mid] == target) {
			return mid;//找到目标值，返回索引
		}
		else if (arr[mid] < target) {
			left = mid + 1;//在右半部分查找
		}
		else {
			right = mid - 1;//在左半部分查找
		}
	}
	return -1;//目标不存在
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int target;
	printf("请输入要查找的目标值：");
	if (scanf_s("%d", &target) != 1) {
		printf("输入无效。\n");
		return 1;//返回错误码
	}
	
	int result = binarySearch(arr, size, target);

	if (result != -1) {
		printf("目标值%d在数组中，索引为%d。\n", target, result);
	}
	else {
		printf("目标值%d不在数组中。\n", target);
	}
	return 0;
}