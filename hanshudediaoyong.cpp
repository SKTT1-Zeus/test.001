#include<iostream>
using namespace std;

//函数的定义
//语法：
//返回值类型 函数名 （参数列表）{函数体语句 return表达式}

//加法函数，实现两个整型相加，并将相加的结果进行返回
int add(int num1, int num2)
//num1和num2只是形式参数，并没有真实数据
{
	int sum = num1 + num2;
	return sum;
}

int main() {

	//main函数中调用add函数
	int a = 10;
	int b = 20;

	//函数调用语法：函数名称（参数）
	int c = add(a, b);

	cout << "c=" << c << endl;

	a = 100;
	b = 1000;

	c = add(a, b);

	cout << "c=" << c << endl;

	system("pause");

	return 0;
}