//��1 2 3 4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ���Ҷ��Ƕ���

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