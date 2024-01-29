#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s);

int main() {
    char inputString[100];  // ����������ַ������Ȳ�����100���ַ�

    printf("������һ���ַ���: ");
    fgets(inputString, sizeof(inputString), stdin);

    // �Ƴ������ַ����еĻ��з�
    inputString[strcspn(inputString, "\n")] = 0;

    int result = lengthOfLastWord(inputString);

    printf("���һ�����ʵĳ�����: %d\n", result);

    return 0;
}

int lengthOfLastWord(char* s) {
    int sum = 0;

    for (int str = strlen(s) - 1; str >= 0; str--) {
        if (s[str] != 32)
            sum += 1;
        if (s[str] == 32 && sum != 0)
            return sum;
    }

    return sum;
}