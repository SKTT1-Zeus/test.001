#include<iostream>
using namespace std;
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� �� Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addresbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int m_Size;
};
//�����ϵ��
void addPerson(Addresbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���������������������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
			//���������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

//��ʾ������ϵ��
void showPerson(Addresbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << endl;
			cout<<  "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů" )<< endl;
			cout << "���䣺" << abs->personArray[i].m_Age << endl;
			cout << "�绰��" << abs->personArray[i].m_Phone << endl;
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�����ϵ���Ƿ���ڣ��������򷵻���ϵ�����������еľ���λ�ã��������򷵻�-1
int isExist(Addresbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ�
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}
//ɾ��ָ����ϵ��
void deletePerson(Addresbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;
	//ret=-1δ�ҵ�
	//ret!=-1�ҵ�
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ��
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼��Ա����
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{

	}
}

//������ϵ��
void findPerson(Addresbooks*abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ������ͨѶ¼��
	int ret = isExist(abs, name);
	
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;

	}
	//�����������
	system("pause");
	system("cls");
}

//�˵�����
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
	//����ͨѶ¼�ṹ�����
	Addresbooks abs;
	//��ʼ����Ա����
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���
	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			/* {
				cout << "������ɾ����ϵ��������" << endl;
				string name;
				cin >> name;

				if (isExist(&abs, name) == -1)
				{
					cout << "���޴���" << endl;
				}
				else
				{
					cout << "�ҵ�����" << endl;
				}
			}*/
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
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
	}
	system("pause");
	return 0;
}