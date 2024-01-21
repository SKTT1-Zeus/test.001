#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // 负数不是回文数，直接返回 false
    if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    // 将数字反转
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // 判断反转后的数字与原始数字是否相等
    return original == reversed;
}

int main() {
    int num;

    // 用户输入整数
    printf("请输入一个整数: ");
    scanf_s("%d", &num);

    // 判断是否是回文数
    if (isPalindrome(num)) {
        printf("%d 是回文数\n", num);
    }
    else {
        printf("%d 不是回文数\n", num);
    }

    return 0;
}