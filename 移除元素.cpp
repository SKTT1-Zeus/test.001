#include <stdio.h>
#pragma warning(disable:4996)

int removeElement(int* nums, int numsSize, int val) {
    int newIndex = 0; // 新数组的索引，用于记录不等于val的元素

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[newIndex++] = nums[i];
        }
    }

    return newIndex;
}

int main() {
    int nums[100]; // 假设数组最大长度为100
    int numsSize, val;

    // 获取用户输入数组的大小
    printf("请输入数组的大小: ");
    scanf("%d", &numsSize);

    // 获取用户输入数组的元素
    printf("请输入%d个整数作为数组元素:\n", numsSize);
    for (int i = 0; i < numsSize; ++i) {
        scanf("%d", &nums[i]);
    }

    // 获取用户输入要移除的值
    printf("请输入要移除的值: ");
    scanf("%d", &val);

    printf("原始数组：");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newLength = removeElement(nums, numsSize, val);

    printf("移除元素后的数组：");
    for (int i = 0; i < newLength; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("新数组的长度：%d\n", newLength);

    return 0;
}