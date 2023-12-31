#include<iostream>
using namespace std;

void showMenu()
{
	cout << "添加联系人" << endl;
	cout << "显示联系人" << endl;
	cout << "删除联系人" << endl;
	cout << "查找联系人" << endl;
	cout << "修改联系人" << endl;
	cout << "清空联系人" << endl;
	cout << "退出" << endl;
}

int main()
{
	int select = 0;//创建用户选择输入的变量
	//菜单调用
	showMenu();

	cin >> select;

	switch (select)
	{
	case 1://添加联系人
		break;
	case 2://显示联系人
		break;
	case 3://删除联系人
		break;
	case 4://查找联系人
		break;
	case 5://修改联系人
		break;
	case 6://清空联系人
		break;
	case 0://退出
		cout << "欢迎下次使用" << endl;
		system("pause");
		return 0;
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}