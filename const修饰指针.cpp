#include<iostream>
using namespace std;

int main() {

	//1.const����ָ�� ����ָ��
	int a = 10;
	int b = 10;

	const int* p = &a;
	//ָ��ָ���ֵ�����Ըģ�ָ��ɸ�
	//*p = 20;����
	p = &b;//��ȷ

	//2.const���γ��� ָ�볣��
	int* const p2 = &a;
	//ָ��ָ���ֵ���Ըģ�ָ�򲻿��Ը�
	*p2 = 100;//��ȷ
	//p2 = &b;����

	//3.const����ָ��ͳ���
	const int* const p3 = &a;
	//ָ���Լ�ָ���ֵ�����ɸ�

	system("pause");
	return 0;
}