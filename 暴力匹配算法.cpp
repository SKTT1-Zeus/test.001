//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 - 1 。

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int strStr(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    // 特殊情况处理
    if (needle_len == 0) {
        return 0;
    }

    // 遍历 haystack
    for (int i = 0; i <= haystack_len - needle_len; ++i) {
        // 在当前位置尝试匹配 needle
        int j;
        for (j = 0; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;  // 不匹配，终止内循环
            }
        }

        // 如果内循环完整执行，说明匹配成功
        if (j == needle_len) {
            return i;  // 返回匹配的起始下标
        }
    }

    return -1;  // 未找到匹配项
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";

    int result = strStr(haystack, needle);

    if (result != -1) {
        printf("匹配项的起始下标是 %d\n", result);
    }
    else {
        printf("未找到匹配项\n");
    }

    return 0;
}