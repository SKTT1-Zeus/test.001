//Çó1-20½×³ËµÄºÍ

#include<stdio.h>

int jc(int m) {
	int chengji = 1;
	int j;
	for (j = 1; j <= m; j++) {
		chengji *= j;
	}
	return chengji;
}

int main() {
	int jc(int m);

	int i;
	int sum = 0;
	for (i = 1; i <= 20; i++) {
		sum += jc(i);
	}
	printf("sum=%d\n", sum);
	return 0;
}