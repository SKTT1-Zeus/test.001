#include<iostream>
using namespace std;
#include<string>

struct student
{
	string name;//����
	int age;//����
	int score;//����
};

struct teacher
{
	int id;//��ʦ���
	string name;//����
	int age;//����
	struct student stu;//ѧ��
};

int main() {
    //�ṹ��Ƕ�׽ṹ��
	//������ʦ
	teacher t;
	t.id = 10000;
	t.name = "����";
	t.age = 40;
	t.stu.name = "����";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "��ʦ������" << t.name << " ��ʦid��" << t.id << " ��ʦ���䣺" << t.age
		<< " ѧ��������" << t.stu.name << " ѧ�����䣺" << t.stu.age << " ѧ��������" << t.stu.score << endl;

	return 0;
}