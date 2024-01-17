#include<stdio.h>

int main(void) {
	int i;
	int j; 
	int a[10][10] = {};
	for (i = 0; i < 10; i++) {
		for (j = 0; j <= i; j++) {
			if (i == j||j == 0) {
				a[i][j] = 1;
			}
		}
		printf("\n");
	}

	for (i = 0; i < 10; i++) {
		for (j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j <= i; j++) {
			printf("%-4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}