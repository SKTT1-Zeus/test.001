//让用户输入一个十进制数，将其转化为二进制后输出

#include<stdio.h>
int main() {
	int n, c, k;
	printf("Enter an integer in decimal number system:");
	scanf_s("%d", &n);
	printf("%d in binary number system is:", n);
	for (c = 31; c >= 0; c--) {
		k = n >> c;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}