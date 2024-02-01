//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

#include <stdio.h>
#pragma warning(disable:4996)

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int prev1 = 1;
    int prev2 = 2;
    int current;

    for (int i = 3; i <= n; ++i) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
}

int main() {
    int n;

    // 获取用户输入
    printf("请输入楼梯的阶数: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("请输入一个大于零的正整数。\n");
        return 1; // 返回错误代码
    }

    int result = climbStairs(n);
    printf("爬到第 %d 阶楼梯的不同方法数为 %d\n", n, result);

    return 0;
}