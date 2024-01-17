//函数指针：本质是一个指针，该指针的地址指向了一个函数，所以它是指向函数的指针。

#include<stdio.h>

int add(int x, int y) {
	return x + y;
}

int main(void)
{
	int add(int x, int y);

	int (*p_add)(int, int) = &add;

	int a = 10;
	int b = 20;
	int c = 30;
	int sum = 0;
	sum = p_add(a, b);

	printf("sum=%d\n", sum);

	printf("三个数的和是%d\n", p_add(p_add(a, b), c));

	return 0;
}