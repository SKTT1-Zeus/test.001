#include<iostream>
using namespace std;

int main() {
	//ָ����ռ�ڴ�ռ��С
	int a = 10;
	int * p;
	p = &a;

	//32λϵͳռ��4���ֽڿռ䣬64λռ8��
	cout << "sizeof (int *)=" << sizeof(int *) << endl;
	cout << "sizeof (flaot *)=" << sizeof(float *) << endl;
	cout << "sizeof (double *)=" << sizeof(double *) << endl;
	cout << "sizeof (char *)=" << sizeof(char *) << endl;

	system("pause");

	return 0;
}