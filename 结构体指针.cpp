#include<iostream>
using namespace std;
#include<string>

//�ṹ��ָ��
struct student//����ѧ���ṹ��
{
	string name;//����
	int age;//����
	int score;//����
};

int main() {

	//����ѧ���ṹ�����
	struct student s = { "����",18,100 };

	//ͨ��ָ��ָ��ṹ�����
	student* p =&s;

	//ͨ��ָ����ʽṹ������е�����
	cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;

	return 0;
}