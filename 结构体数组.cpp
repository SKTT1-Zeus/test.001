#include<iostream>
using namespace std;
#include<string>

//�ṹ������
//1.����ṹ��
struct Student
{
	//����
	string name;
	//����
	int age;
	//����
	int score;
};
int main() {
//2.�����ṹ������
	struct Student stuArray[3] =
	{
		{"����",18,100},
		{"����",28,99},
		{"����",38,98},
	};
//3.���ṹ�������е�Ԫ�ظ�ֵ
	stuArray[2].name = "����";
	stuArray[2].age = 40;
	stuArray[2].score = 80;

//4.�����ṹ������
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << stuArray[i].name << " ���䣺" << stuArray[i].age << " ������" << stuArray[i].score << endl;
	}

	return 0;
}