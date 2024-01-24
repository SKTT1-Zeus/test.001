#include <stdio.h>

// 生成斐波那契数列的前 n 个数字
void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series for %d terms: ", n);

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        }

        printf("%d ", next);
    }

    printf("\n");
}

int main() {
    int n;

    // 获取用户输入
    printf("Enter the number of terms for Fibonacci Series: ");
    scanf_s("%d", &n);

    generateFibonacci(n);

    return 0;
}