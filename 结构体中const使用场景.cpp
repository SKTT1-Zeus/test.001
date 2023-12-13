#include<iostream>
using namespace std;
#include<string>

//定义学生结构体
struct student
{
	string name;
	int age;
	int score;
};

//将函数中的形参改为指针，可以减少内存空间，且不会复制新副本
void printStudents(const student *s)
{
	//s->age = 30;//加入const后一旦修改就会报错，防止误操作
	cout << "姓名：" << s->name << " 年龄：" << s->age << " 分数：" << s->score << endl;
}

int main() {

	//创建结构体变量
	struct student s = { "张三",15,70 };

	//通过函数打印结构体变量信息
	printStudents(&s);

	cout << "main函数中张三的年龄为：" << s.age << endl;

	return 0;
}