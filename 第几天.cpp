//����ĳ��ĳ��ĳ�գ��ж�������һ��ĵڼ���

#include<stdio.h>

int main(int argc, const char* argv[]) {
	int day, month, year;
	int sum = 0;
	printf("�����������գ�");
	scanf_s("%d,%d,%d", &year, &month, &day);
	printf("year=%d,month=%d,day=%d\n",year,month,day);

	switch (month){
	case 1:printf("һ��"); sum = 0; break;
	case 2:printf("����"); sum = 31; break;
	case 3:printf("����"); sum = 59; break;
	case 4:printf("����"); sum = 90; break;
	case 5:printf("����"); sum = 120; break;
	case 6:printf("����"); sum = 151; break;
	case 7:printf("����"); sum = 181; break;
	case 8:printf("����"); sum = 212; break;
	case 9:printf("����"); sum = 242; break;
	case 10:printf("ʮ��"); sum = 273; break;
	case 11:printf("ʮһ��"); sum = 304; break;
	case 12:printf("ʮ����"); sum = 334; break;
	}

	sum = sum + day;
	printf("��������%d\n", sum);
                                                       
	return 0;
}