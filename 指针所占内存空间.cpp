#include<iostream>
using namespace std;

int main() {
	//指针所占内存空间大小
	int a = 10;
	int * p;
	p = &a;

	//32位系统占用4个字节空间，64位占8个
	cout << "sizeof (int *)=" << sizeof(int *) << endl;
	cout << "sizeof (flaot *)=" << sizeof(float *) << endl;
	cout << "sizeof (double *)=" << sizeof(double *) << endl;
	cout << "sizeof (char *)=" << sizeof(char *) << endl;

	system("pause");

	return 0;
}