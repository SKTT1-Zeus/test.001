#include<iostream>
using namespace std;
#include<string>

struct student
{
	string name;//姓名
	int age;//年龄
	int score;//分数
};

struct teacher
{
	int id;//教师编号
	string name;//姓名
	int age;//年龄
	struct student stu;//学生
};

int main() {
    //结构体嵌套结构体
	//创建老师
	teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 40;
	t.stu.name = "张三";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "教师姓名：" << t.name << " 教师id：" << t.id << " 教师年龄：" << t.age
		<< " 学生姓名：" << t.stu.name << " 学生年龄：" << t.stu.age << " 学生分数：" << t.stu.score << endl;

	return 0;
}