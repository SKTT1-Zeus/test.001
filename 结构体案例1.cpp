#include<iostream>
using namespace std;
#include<string>
#include<ctime>

//学生的结构体定义
struct student {
	string sName;
	int age;
	int score;
};

//老师的结构体定义
struct teacher {
	//姓名
	string tName;
	//学生数组
	struct student sArray[5];

};

//给老师和学生赋值的函数
void allocateSpace(struct teacher tArray[],int len) {
	string nameSeed = "ABCDE";
	//给老师赋值
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "teacher";
		tArray[i].tName += nameSeed[i];

		//通过循环给每名老师的学生赋值
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "student_";
			tArray[i].sArray[j].sName += nameSeed[j];

			int random = rand() % 60+40;//随机40—99
			tArray[i].sArray[j].score = random;
		}
	}
}

//打印所有信息
void printInfo(struct teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tArray[i].tName << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << tArray[i].sArray[j].sName <<
				" 考试分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建三名老师的数组
	struct teacher tArray[3];

	//通过函数对老师的信息赋值，并给老师带的学生信息赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, 3);

	//打印所有老师及所带的学生信息
	printInfo(tArray, len);

	return 0;
}