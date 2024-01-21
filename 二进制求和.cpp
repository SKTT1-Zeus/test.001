#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLength = (lenA > lenB) ? lenA : lenB;

    char* result = (char*)malloc((maxLength + 2) * sizeof(char));
    result[maxLength + 1] = '\0';

    int carry = 0;
    int i = lenA - 1, j = lenB - 1, k = maxLength;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        result[k--] = sum % 2 + '0';
        carry = sum / 2;
    }

    if (carry > 0) {
        memmove(result + 1, result, maxLength + 1);
        result[0] = '1';
    }

    return result;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";

    char* result = addBinary(a, b);

    printf("相加结果: %s\n", result);

    // 释放动态分配的内存
    free(result);

    return 0;
}