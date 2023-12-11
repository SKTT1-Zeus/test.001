#include<iostream>
using namespace std;

//实现两个数字进行交换
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01a=" << a << endl;
	cout << "swap01b=" << b << endl;
}

void swap02(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {

	//指针和函数
	//1.值传递
	int a = 10;
	int b = 20;
	//swap01(a, b);

	//2.地址传递
	//如果是地址传递，可以修饰实参
	swap02(&a, &b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	system("pause");

	return 0;
}