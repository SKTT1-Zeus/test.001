//����ָ�룺������һ��ָ�룬��ָ��ĵ�ַָ����һ����������������ָ������ָ�롣

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

	printf("�������ĺ���%d\n", p_add(p_add(a, b), c));

	return 0;
}