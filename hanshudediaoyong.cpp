#include<iostream>
using namespace std;

//�����Ķ���
//�﷨��
//����ֵ���� ������ �������б�{��������� return���ʽ}

//�ӷ�������ʵ������������ӣ�������ӵĽ�����з���
int add(int num1, int num2)
//num1��num2ֻ����ʽ��������û����ʵ����
{
	int sum = num1 + num2;
	return sum;
}

int main() {

	//main�����е���add����
	int a = 10;
	int b = 20;

	//���������﷨���������ƣ�������
	int c = add(a, b);

	cout << "c=" << c << endl;

	a = 100;
	b = 1000;

	c = add(a, b);

	cout << "c=" << c << endl;

	system("pause");

	return 0;
}