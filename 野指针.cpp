#include<iostream>
using namespace std;

int main() {

	//野指针：程序变量指向非法内存空间
	//程序中尽量避免野指针
	int* p = (int *)0x1100;

	cout << *p << endl;

	system("pause");

	return 0;
}