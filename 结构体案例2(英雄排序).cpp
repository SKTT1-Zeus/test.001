#include<iostream>
using namespace std;
#include<string>

//1.���Ӣ�۽ṹ��
struct Hero {
	//Ӣ������
	string name;
	//��·
	int position;
	string position1;
	//�Ա�
	string sex;
};

//ð������ ʵ�ַ�·��������
void bubbleSort(struct Hero heroArray[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			//���j�±�Ԫ�ط�·����j+1�±��Ԫ�صķ�·������Ԫ��
			if (heroArray[j].position > heroArray[j + 1].position)
			{
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

//��ӡ������������Ϣ
void printHero(struct Hero heroArray[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << " Ӣ�����ƣ�" << heroArray[i].name << " ��·��" << heroArray[i].position1
				<< " �Ա�" << heroArray[i].sex << endl;
	}
}

int main() {

	//2.��������������Ӣ��
	struct Hero heroArray[5] =
	{
		{"�����˹",4,"ADC","��"},
		{"������", 3, "MID","Ů"},
		{"��Ү��", 2, "JUG","��"},
		{"�������", 1, "TOP","Ů"},
		{"���շ���", 5, "SUP","Ů"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	
	//3.������������򣬰��շ�·������������
	bubbleSort(heroArray, len);

	//4.�������Ľ����ӡ���
	printHero(heroArray, len);

	return 0;
}