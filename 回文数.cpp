#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // �������ǻ�������ֱ�ӷ��� false
    if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    // �����ַ�ת
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // �жϷ�ת���������ԭʼ�����Ƿ����
    return original == reversed;
}

int main() {
    int num;

    // �û���������
    printf("������һ������: ");
    scanf_s("%d", &num);

    // �ж��Ƿ��ǻ�����
    if (isPalindrome(num)) {
        printf("%d �ǻ�����\n", num);
    }
    else {
        printf("%d ���ǻ�����\n", num);
    }

    return 0;
}