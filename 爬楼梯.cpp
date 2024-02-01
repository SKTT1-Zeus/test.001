//������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

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

    // ��ȡ�û�����
    printf("������¥�ݵĽ���: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("������һ�����������������\n");
        return 1; // ���ش������
    }

    int result = climbStairs(n);
    printf("������ %d ��¥�ݵĲ�ͬ������Ϊ %d\n", n, result);

    return 0;
}