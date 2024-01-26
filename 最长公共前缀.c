#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

// �����ַ��������е������ǰ׺
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // �Ե�һ���ַ���Ϊ��׼
    char* prefix = strs[0];
    int prefixLen = strlen(prefix);

    // ����ÿ���ַ���������Ƚ��ַ�
    for (int i = 1; i < strsSize; ++i) {
        int j = 0;
        while (j < prefixLen && j < strlen(strs[i]) && prefix[j] == strs[i][j]) {
            ++j;
        }

        // ���������ǰ׺�ĳ���
        prefixLen = j;

        // ��������ǰ׺Ϊ�գ���û�й���ǰ׺��ֱ�ӷ���
        if (prefixLen == 0) {
            return "";
        }
    }

    // ���������ǰ׺�ĳ��ȴ���һ�����ַ���
    char* result = (char*)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';

    return result;
}

int main() {
    // ʾ���ַ�������
    char* strs[] = { "flower", "flow", "flight" };
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    // ���������ǰ׺
    char* result = longestCommonPrefix(strs, strsSize);

    // ��ӡ���
    printf("Longest Common Prefix: %s\n", result);

    // �ͷ��ڴ�
    free(result);

    return 0;
}