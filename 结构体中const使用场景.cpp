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

//�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬�Ҳ��Ḵ���¸���
void printStudents(const student *s)
{
	//s->age = 30;//����const��һ���޸ľͻᱨ����ֹ�����
	cout << "������" << s->name << " ���䣺" << s->age << " ������" << s->score << endl;
}

int main() {

	//�����ṹ�����
	struct student s = { "����",15,70 };

	//ͨ��������ӡ�ṹ�������Ϣ
	printStudents(&s);

	cout << "main����������������Ϊ��" << s.age << endl;

	return 0;
}