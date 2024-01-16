//利用递归方法求阶乘

#include<stdio.h>

long f(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * f(n - 1);
	}
	return f(n);
}

int main() {
	long f(int n);
	int m = 20;
	printf("20!=%d\n", f(m));

	return 0;
}