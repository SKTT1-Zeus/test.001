#include<iostream>
using namespace std;

void showMenu()
{
	cout << "�����ϵ��" << endl;
	cout << "��ʾ��ϵ��" << endl;
	cout << "ɾ����ϵ��" << endl;
	cout << "������ϵ��" << endl;
	cout << "�޸���ϵ��" << endl;
	cout << "�����ϵ��" << endl;
	cout << "�˳�" << endl;
}

int main()
{
	int select = 0;//�����û�ѡ������ı���
	//�˵�����
	showMenu();

	cin >> select;

	switch (select)
	{
	case 1://�����ϵ��
		break;
	case 2://��ʾ��ϵ��
		break;
	case 3://ɾ����ϵ��
		break;
	case 4://������ϵ��
		break;
	case 5://�޸���ϵ��
		break;
	case 6://�����ϵ��
		break;
	case 0://�˳�
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		return 0;
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}