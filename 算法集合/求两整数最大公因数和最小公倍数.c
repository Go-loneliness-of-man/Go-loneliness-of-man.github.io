#include<stdio.h>
//求两正整数 m 、n 的最大公因数和最小公倍数
//辗转相除法:用除数除以余数，直到余数为0，则最后一次的除数为最大公因数

/*
//辗转相除法算法一:
int m, n, r1 , r2;								//声明两整数的变量、辗转相除法变量
int same(int x, int y);							//声明求最大公因数的same()函数
int main()
{
	printf("请输入m: ");
	scanf_s("%d", &m);
	printf("请输入n: ");
	scanf_s("%d", &n);
	r1 = same(m, n);							//求最大公因数
	printf("最大公因数: %d\n", r1);
	printf("最小公倍数: %d\n", (m*n) / r1);		//两数的乘积除以最大公因数为最小公倍数
}

int same(int x, int y)							//定义same函数()
{
	for (r1 = x % y; r1 != 0; r1 = r2 % r1)		//x%y 赋值给r1，只要 r1 != 0 则继续循环，循环后将 r2%r1 赋值给r1
	{
		r2 = y;									//将上一次运算的除数赋值给 r2，作为这次的被除数来除以上一次的余数 r1
		y = r1;									//利用 y 保存上一次运算的除数 r1 的值
	}
	if (r1 == 0)								//若第一次运算就跳出循环，即 x%y 后 r1 == 0，则取第一次的除数 y
		return y;
	else
		return r1;								//非第一次运算，y 未保存除数就跳出循环，除数为 r1
}
*/

/*
//辗转相除法算法二:
#include<stdio.h>
int maxfactor(int x, int y);										//求最大公因数
int m, n, max, r1;													//正整数m、n，最大公因数max，余数r1
int main()
{
	printf("依次输入两个整数，用一个空格隔开，输入法英文: ");
	scanf_s("%d %d", &m,&n);
	max = maxfactor(m, n);
	printf("\n最大公因数为: %d\n\n最小公倍数为: %d\n\n", max, m*n / max);
	return 0;
}
int maxfactor(int x, int y)
{
	if (x > y)
	{
		r1 = x%y;
		r1 == 0 ? r1 = y : maxfactor(y, r1);						//只要大的取余小的余数不为零，就再次用除数对余数取余
		return r1;
	}
	else
	{
		r1 = y%x;
		r1 == 0 ? r1 = x : maxfactor(x, r1);
		return r1;
	}
}
*/

/*
//更相减损法:


*/