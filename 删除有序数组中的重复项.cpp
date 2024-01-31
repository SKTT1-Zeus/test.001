#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int uniqueCount = 1; // 初始化为1，因为第一个元素肯定是唯一的
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount++] = nums[i];
        }
    }

    return uniqueCount;
}

int main() {
    int nums[100]; // 假设数组最大长度为100
    int numsSize;

    // 获取用户输入数组的大小
    printf("请输入数组的大小: ");
    scanf_s("%d", &numsSize);

    // 获取用户输入数组的元素
    printf("请输入%d个整数作为数组元素:\n", numsSize);
    for (int i = 0; i < numsSize; ++i) {
        scanf_s("%d", &nums[i]);
    }

    printf("原始数组：");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newLength = removeDuplicates(nums, numsSize);

    printf("删除重复元素后的数组：");
    for (int i = 0; i < newLength; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("唯一元素的个数：%d\n", newLength);

    return 0;
}