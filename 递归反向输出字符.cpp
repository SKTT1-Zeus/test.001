//���õݹ麯���ĵ��÷�ʽ����������ַ������ӡ����

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