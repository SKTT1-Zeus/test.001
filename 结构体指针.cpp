#include<iostream>
using namespace std;
#include<string>

//结构体指针
struct student//定义学生结构体
{
	string name;//姓名
	int age;//年龄
	int score;//分数
};

int main() {

	//创建学生结构体变量
	struct student s = { "张三",18,100 };

	//通过指针指向结构体变量
	student* p =&s;

	//通过指针访问结构体变量中的数据
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

	return 0;
}