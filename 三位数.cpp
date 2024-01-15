//有1 2 3 4个数字，能组成多少个互不相同且勿重复数字的三位数且都是多少

#include<stdio.h>

int main(int argc, const char* argv[]) {

	int g,b,s;
	
	for (b = 1; b < 5; b++) {
		for (s = 1; s < 5; s++) {
			for (g = 1; g < 5; g++) {
				if (g != s && s != b && g != b) {
					printf("%d,%d,%d\n", b, s, g);
				}
			}
		}
	}
	return 0;
}