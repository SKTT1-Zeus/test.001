#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // �����㹻�Ŀռ����洢�ϲ�����ַ���
    char* result = (char*)malloc(len1 + len2 + 1);

    // ����ڴ�����Ƿ�ɹ�
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0, k = 0;

    // ���δ������ַ�����ȡ�ַ����н������
    while (i < len1 && j < len2) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    // ��ʣ�ಿ��׷�ӵ��ϲ����ַ�����ĩβ
    while (i < len1) {
        result[k++] = word1[i++];
    }

    while (j < len2) {
        result[k++] = word2[j++];
    }

    // �ںϲ����ַ�����ĩβ��ӽ�����
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

    // �ǵ��ͷŶ�̬������ڴ�
    free(result);

    return 0;
}