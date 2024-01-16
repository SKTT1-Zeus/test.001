//输入某年某月某日，判断这是这一年的第几天

#include<stdio.h>

int main(int argc, const char* argv[]) {
	int day, month, year;
	int sum = 0;
	printf("请输入年月日：");
	scanf_s("%d,%d,%d", &year, &month, &day);
	printf("year=%d,month=%d,day=%d\n",year,month,day);

	switch (month){
	case 1:printf("一月"); sum = 0; break;
	case 2:printf("二月"); sum = 31; break;
	case 3:printf("三月"); sum = 59; break;
	case 4:printf("四月"); sum = 90; break;
	case 5:printf("五月"); sum = 120; break;
	case 6:printf("六月"); sum = 151; break;
	case 7:printf("七月"); sum = 181; break;
	case 8:printf("八月"); sum = 212; break;
	case 9:printf("九月"); sum = 242; break;
	case 10:printf("十月"); sum = 273; break;
	case 11:printf("十一月"); sum = 304; break;
	case 12:printf("十二月"); sum = 334; break;
	}

	sum = sum + day;
	printf("总天数是%d\n", sum);
                                                       
	return 0;
}