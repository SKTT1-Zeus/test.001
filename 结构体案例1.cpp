#include<iostream>
using namespace std;
#include<string>
#include<ctime>

//ѧ���Ľṹ�嶨��
struct student {
	string sName;
	int age;
	int score;
};

//��ʦ�Ľṹ�嶨��
struct teacher {
	//����
	string tName;
	//ѧ������
	struct student sArray[5];

};

//����ʦ��ѧ����ֵ�ĺ���
void allocateSpace(struct teacher tArray[],int len) {
	string nameSeed = "ABCDE";
	//����ʦ��ֵ
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "teacher";
		tArray[i].tName += nameSeed[i];

		//ͨ��ѭ����ÿ����ʦ��ѧ����ֵ
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "student_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand() % 60+40;//���40��99
			tArray[i].sArray[j].score = random;
		}
	}
}

//��ӡ������Ϣ
void printInfo(struct teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������" << tArray[i].tName << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ��������" << tArray[i].sArray[j].sName <<
				" ���Է�����" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {
	//���������
	srand((unsigned int)time(NULL));

	//����������ʦ������
	struct teacher tArray[3];

	//ͨ����������ʦ����Ϣ��ֵ��������ʦ����ѧ����Ϣ��ֵ
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, 3);

	//��ӡ������ʦ��������ѧ����Ϣ
	printInfo(tArray, len);

	return 0;
}