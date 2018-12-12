#include<stdio.h>
//辗转相除法计算最大公因数:用除数除以余数，直到余数为0，则最后一次的除数为最大公因数

/*
//辗转相除法算法一:
int same(int x, int y);							//求最大公因数的 same() 函数

int main()
{
	int m, n, r1;								//声明两整数变量、最大公因数
	printf("\n 请依次输入两个数，用空格隔开: ");
	scanf_s("%d %d", &m, &n);
	r1 = same(m, n);							//求两数的最大公因数
	printf(" 最大公因数: %d\n", r1);
	printf(" 最小公倍数: %d\n ", (m*n) / r1);		//两数的乘积除以最大公因数为最小公倍数
}
int same(int x, int y)							//定义same函数()
{
	int r1, r2;
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	for (; r1 != 0; r1 = r2 % r1)		//x%y 赋值给r1，只要 r1 != 0 则继续循环，循环后将 r2%r1 赋值给r1
	{
		r2 = y;									//将上一次运算的除数赋值给 r2，作为这次的被除数来除以上一次的余数 r1
		y = r1;									//利用 y 保存上一次运算的除数 r1 的值
	}
	return y;									//返回除数 y
}
/**/

/*
//辗转相除法算法二:利用递归，易理解版
#include<stdio.h>
int m, n, max, r1, maxfactor(int x, int y);				//两正整数、最大公因数 max、余数 r1、求最大公因数的函数
int main()
{
	printf("\n 请依次输入两个整数，用空格隔开: ");
	scanf_s("%d %d", &m,&n);
	max = maxfactor(m, n);								//计算两数的最大公因数
	printf("\n最大公因数为: %d\n\n最小公倍数为: %d\n\n", max, m*n / max);
	return 0;
}
int maxfactor(int x, int y)
{
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	r1 == 0 ? r1 = x : maxfactor(x, r1);			//递归
	return r1;										//递归完毕后返回除数 r1
}
/**/


//辗转相除法算法三:利用递归，代码量缩减版
int m, n,maxfactor(int x,int y);					//被求数 m 和 n，求最大公因数函数 maxfactor()
int  main()
{
	printf("\n 请输入两个数： ");
	scanf_s("%d %d",&m,&n);							//获取数字 m 和 n
	printf(" 最大公因数：%d\n 最小公倍数: %d\n ", maxfactor(m, n), (m*n) / maxfactor(m, n));
	return 0;
}
int maxfactor(int x, int y)
{
	int r1;
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	return (x%y) == 0 ? y : maxfactor(y, (x%y));	//递归，若余数为 0，则停止，否则继续
}
/**/

/*
//更相减损法:


*/