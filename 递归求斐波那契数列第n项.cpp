#include <stdio.h>

// �ݹ���쳲��������е�n��
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    }
    else {
        int result = fibonacci(n);
        printf("Fibonacci(%d) = %d\n", n, result);
    }

    return 0;
}