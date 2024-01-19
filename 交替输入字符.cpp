#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // 分配足够的空间来存储合并后的字符串
    char* result = (char*)malloc(len1 + len2 + 1);

    // 检查内存分配是否成功
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0, k = 0;

    // 依次从两个字符串中取字符进行交替添加
    while (i < len1 && j < len2) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    // 将剩余部分追加到合并后字符串的末尾
    while (i < len1) {
        result[k++] = word1[i++];
    }

    while (j < len2) {
        result[k++] = word2[j++];
    }

    // 在合并后字符串的末尾添加结束符
    result[k] = '\0';

    return result;
}

int main() {
    char word1[100], word2[100];

    printf("Enter the first word: ");
    scanf_s("%s", word1);

    printf("Enter the second word: ");
    scanf_s("%s", word2);

    char* result = mergeStrings(word1, word2);

    printf("Merged String: %s\n", result);

    // 记得释放动态分配的内存
    free(result);

    return 0;
}