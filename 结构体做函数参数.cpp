#include<iostream>
using namespace std;
#include<string>

//����ѧ���ṹ��
struct student
{
	string name;
	int age;
	int score;
};
//��ӡѧ����Ϣ����
//1.ֵ����
void printStudent1(struct student s)
{
	s.age = 30;
	cout << "�Ӻ����� ������" << s.name << " ���䣺" << s.age << " ������" << s.score << endl;
}
//2.��ַ����
void printStudent2(struct student *p)
{
	cout << "�Ӻ���2�� ������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;
}

int main() {

	//�ṹ������������
	//��ѧ�����뵽һ�������У���ӡѧ�����ϵ�������Ϣ

	//�����ṹ�����
	struct student s;
	s.name = "����";
	s.age = 20;
	s.score = 100;

	printStudent1(s);
	printStudent2(&s);
	cout << "main�����д�ӡ ������" << s.name << " ���䣺" << s.age << " ������" << s.score << endl;

	return 0;
}