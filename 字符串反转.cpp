//将一个字符串反转并输出

#include<stdio.h>
#include<string.h>

int main() {
	char str[100], temp;
	int i, j;
	printf("Enter a STRING:");
	scanf_s("%s", str);
	j = strlen(str) - 1;
	for (i = 0; i < j; ++i) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		--j;
	}
	printf("Reverse of the string:%s", str);
	return 0;
}