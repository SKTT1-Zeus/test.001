//输入数组元素，将其反转并输出

#include<stdio.h>
#include<stdlib.h>

int main() {

	int n,i,temp;
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
    // 使用malloc动态分配内存
    int* arr = (int*)malloc(n * sizeof(int));

    // 检查内存分配是否成功
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1; // 返回非零值表示程序异常退出
    }
    printf("Enter %d integers:", n);
    for (i = 0; i < n; ++i)
    {
        scanf_s("%d", &arr[i]);
    }
    for (i = 0; i < n / 2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    printf("Reversed array:");
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}