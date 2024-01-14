//输入数组元素，对其求和并输出

#include <stdio.h>
#include<stdlib.h>

int main() {
    int n, i, sum = 0;

    // 提示用户输入元素的数量
    printf("Enter the number of elements: ");
    scanf_s("%d", &n);

    // 使用动态内存分配来声明数组
    int* arr = (int*)malloc(n * sizeof(int));

    // 检查内存是否分配成功
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // 返回非零值表示程序执行失败
    }

    // 提示用户输入数组元素
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; ++i) {
        scanf_s("%d", &arr[i]);
        sum += arr[i];
    }

    // 打印数组元素的和
    printf("Sum = %d\n", sum);

    // 释放动态分配的内存
    free(arr);

    return 0;
}