#include<stdio.h>

int main() {
	int a, b, sum;
	printf("Ent two integers:");
	scanf_s("%d%d",&a,&b);
	sum = a + b;
	printf("%d+%d=%d", a, b, sum);
	return 0;
}