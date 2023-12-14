#include<iostream>
using namespace std;
#include<string>

//1.设计英雄结构体
struct Hero {
	//英雄名称
	string name;
	//分路
	int position;
	string position1;
	//性别
	string sex;
};

//冒泡排序 实现分路升序排列
void bubbleSort(struct Hero heroArray[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			//如果j下标元素分路大于j+1下标的元素的分路，交换元素
			if (heroArray[j].position > heroArray[j + 1].position)
			{
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

//打印排序后的所有信息
void printHero(struct Hero heroArray[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << " 英雄名称：" << heroArray[i].name << " 分路：" << heroArray[i].position1
				<< " 性别" << heroArray[i].sex << endl;
	}
}

int main() {

	//2.创建数组存放五名英雄
	struct Hero heroArray[5] =
	{
		{"厄斐琉斯",4,"ADC","男"},
		{"辛德拉", 3, "MID","女"},
		{"佛耶戈", 2, "JUG","男"},
		{"艾瑞利娅", 1, "TOP","女"},
		{"萨勒芬妮", 5, "SUP","女"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	
	//3.对数组进行排序，按照分路进行升序排序
	bubbleSort(heroArray, len);

	//4.将排序后的结果打印输出
	printHero(heroArray, len);

	return 0;
}