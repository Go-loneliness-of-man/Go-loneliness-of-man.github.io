#include<stdio.h>
#include<Windows.h>
//模仿日历，假设一月一日是星期一，采用逐行打印思想，打印出任意年份全年的日历
int y, i, j, p, week, day, yue[12] = { 31,28,31,30,31,30,31,31,31,30,31,30 };
//依次是年 y、月 i、日 j、星期 week、一年的第几天 day、判断是否结束程序 p、每个月的天数 yue[]
char year[3];
void switchs(int x);														//作用是打印每月的第一天
int main()
{
	for (p = 1; p;)
	{
		printf("\n  请输入年份： ");
		scanf_s("%d", &y);
		y % 4 == 0 ? strcpy_s(year, 3, "闰") : strcpy_s(year, 3, "平");		//判断输入年份是“闰”年还是“平年”
		if (y % 4 == 0) yue[1] = 29;										//重置二月的天数为“闰”年
		printf("\n  %d 年是 %s 年，若假设一月一日是星期一，则其日历如下：\n\n", y, year);
		for (week = 1, day = 1, i = 0; i < 12; i++)							//打印一整年的日历
		{
			printf("  %d 月\t\t日\t一\t二\t三\t四\t五\t六\n", i + 1);			//输出每个月的首部
			for (j = 1; j <= yue[i]; j++, week++, day++)					//打印一个月的日期
			{
				if (j == 1) switchs(day);									//确定该月份第一天的位置
				if (j != 1) printf("%d\t", j);								//打印该月份剩下的日期
				if (week == 8) week = 1;									//重置星期号
				if (week == 6) printf("\n    \t\t");						//换行、缩进
			}
			printf("\n\n");													//月份间换行
		}
		printf("是否继续？若是，输入任意数字，若否，输入 0：");						//询问是否继续
		scanf_s("%d", &p);
		system("cls");														//清屏
	}
	return 0;
}
void switchs(int x)															//确定每月第一天的位置
{
	printf("    \t\t");														//打印开头部分
	for (int n = x % 7; n; n--) printf("  \t");								//打印中间的部分
	printf("%d\t", j);														//打印日期
}