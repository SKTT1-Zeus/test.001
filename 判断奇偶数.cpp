#include<stdio.h>

int main() {
	int number;
	printf("Enter an interger:");
	scanf_s("%d", &number);
	if (number % 2 == 0) {
		printf("%d is even.", number);
	}
	else {
		printf("%d is odd.", number);
	}
	return 0;
}