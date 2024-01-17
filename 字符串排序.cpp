//若干个字符串，排序比较大小

#include<cstdio>
#include<cstring>
#include<stdlib.h>
#pragma warning(disable:4996)

void swap(char* str1, char* str2) {
	char temp[20];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int main(void) {
	char str1[20] = "1";
	char str2[20] = "2";

	if (str1 > str2) {
		printf("str1 is bigger\n");
	}
	else {
		swap(str1, str2);
		printf("str2 is bigger\n");
	}

	printf("%s,%s\n", str1, str2);
	return 0;
}