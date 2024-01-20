#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[100];  // 假设数组大小不超过100
    int numsSize, target;

    // 获取数组大小
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    // 获取数组元素
    printf("Enter the elements of the array: ");
    for (int i = 0; i < numsSize; ++i) {
        scanf("%d", &nums[i]);
    }

    // 获取目标值
    printf("Enter the target sum: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("The indices are: [%d, %d]\n", result[0], result[1]);
    }
    else {
        printf("No solution found.\n");
    }

    // 释放动态分配的内存
    free(result);

    return 0;
}