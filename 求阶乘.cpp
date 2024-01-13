//让用户输入一个非负整数，计算它的阶乘并输出

#include<stdio.h>
int main() {

	int n, i;
	unsigned long long factorial = 1;
	printf("Enter a positive integer:");
	scanf_s("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	printf("Factorial of %d=%llu", n, factorial);
	return 0;
}