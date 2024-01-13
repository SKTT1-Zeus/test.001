//让用户输入一个二进制数，将其转换为十进制数并输出

#include<stdio.h>
#include<math.h>
int main() {
	long long n;
	int decimal = 0, i = 0, rem;
	printf("Enter a binary number:");
	scanf_s("%lld", &n);
	while (n != 0) {
		rem = n % 10;
		n /= 10;
		decimal += rem * pow(2, i);
		++i;
	}
	printf("Decimal number=%d", decimal);
	return 0;
}