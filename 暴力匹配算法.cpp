//���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
//��� needle ���� haystack ��һ���֣��򷵻� - 1 ��

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int strStr(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    // �����������
    if (needle_len == 0) {
        return 0;
    }

    // ���� haystack
    for (int i = 0; i <= haystack_len - needle_len; ++i) {
        // �ڵ�ǰλ�ó���ƥ�� needle
        int j;
        for (j = 0; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;  // ��ƥ�䣬��ֹ��ѭ��
            }
        }

        // �����ѭ������ִ�У�˵��ƥ��ɹ�
        if (j == needle_len) {
            return i;  // ����ƥ�����ʼ�±�
        }
    }

    return -1;  // δ�ҵ�ƥ����
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";

    int result = strStr(haystack, needle);

    if (result != -1) {
        printf("ƥ�������ʼ�±��� %d\n", result);
    }
    else {
        printf("δ�ҵ�ƥ����\n");
    }

    return 0;
}