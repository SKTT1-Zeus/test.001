//����һ���ַ������Ȳ����

#include<cstdio>
#include<string.h>

int main() {
	char str[100];
	int len;
	printf("Enter a string:");
	scanf_s("%s", str);
	len = strlen(str);
	printf("Length of '%s'=%d", str, len);
	return 0;
}