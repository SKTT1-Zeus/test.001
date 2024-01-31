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

    // 如果target不存在于数组中，此时left即为插入位置
    return left;
}

int main() {
    int nums[] = { 1, 3, 5, 6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target;

    printf("请输入目标值: ");
    scanf("%d", &target);

    int result = searchInsert(nums, numsSize, target);

    printf("目标值 %d 在数组中的索引（或插入位置）为: %d\n", target, result);

    return 0;
}