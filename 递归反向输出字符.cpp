//利用递归函数的调用方式，将输入的字符反向打印出来

#include<stdio.h>

void f(int n) {
	char c;
	if (n==1) {
		c = getchar();
		putchar(c);
	}
	else {
		c = getchar();
		f(n - 1);
		putchar(c);
	}
}

int main() {
	void f(int n);
	f(5);

	return 0;
}