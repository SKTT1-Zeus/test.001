#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s);

int main() {
    char inputString[100];  // 假设输入的字符串长度不超过100个字符

    printf("请输入一个字符串: ");
    fgets(inputString, sizeof(inputString), stdin);

    // 移除输入字符串中的换行符
    inputString[strcspn(inputString, "\n")] = 0;

    int result = lengthOfLastWord(inputString);

    printf("最后一个单词的长度是: %d\n", result);

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