#include <stdio.h>
#pragma warning(disable:4996)

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // ���target�������������У���ʱleft��Ϊ����λ��
    return left;
}

int main() {
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target;

    printf("������Ŀ��ֵ: ");
    scanf("%d", &target);

    int result = searchInsert(nums, numsSize, target);

    printf("Ŀ��ֵ %d �������е������������λ�ã�Ϊ: %d\n", target, result);

    return 0;
}