#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 遍历数组，从最后一位开始加一
    for (int i = digitsSize - 1; i >= 0; i--) {
        // 如果当前位小于9，直接加一返回
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        else {
            // 如果当前位是9，将当前位变为0，继续向前进位
            digits[i] = 0;
        }
    }

    // 如果遍历结束后仍然需要进位，说明最高位产生了进位，需要在数组前插入一位1
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = digits[i - 1];
    }

    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    int digits[] = { 9, 9, 9 };  // 示例输入
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("加一后的结果：");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);  // 释放动态分配的内存
    return 0;
}