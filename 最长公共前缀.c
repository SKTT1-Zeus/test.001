#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

// 查找字符串数组中的最长公共前缀
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // 以第一个字符串为基准
    char* prefix = strs[0];
    int prefixLen = strlen(prefix);

    // 遍历每个字符串，逐个比较字符
    for (int i = 1; i < strsSize; ++i) {
        int j = 0;
        while (j < prefixLen && j < strlen(strs[i]) && prefix[j] == strs[i][j]) {
            ++j;
        }

        // 更新最长公共前缀的长度
        prefixLen = j;

        // 如果最长公共前缀为空，即没有公共前缀，直接返回
        if (prefixLen == 0) {
            return "";
        }
    }

    // 根据最长公共前缀的长度创建一个新字符串
    char* result = (char*)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';

    return result;
}

int main() {
    // 示例字符串数组
    char* strs[] = { "flower", "flow", "flight" };
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    // 查找最长公共前缀
    char* result = longestCommonPrefix(strs, strsSize);

    // 打印结果
    printf("Longest Common Prefix: %s\n", result);

    // 释放内存
    free(result);

    return 0;
}