#include <stdio.h>
/*
二分法解方程原理:
确定一个两端点函数值异号的起始区间，保持区间两端点的函数值异号，不断缩小区间长度，直到两端点的 函数值的差 小于允许的误差值。
二分法只适用于 在起始区间内只有一个零点 的情况，若区间内有两个及以上零点便不再适用。
*/
/*
//解法示例，解方程 2*x*x*x - 4*x*x + 3*x - 6 = 0 ， 起始区间 -10 到 10
#define DY ((2*x*x*x - 4*x*x + 3*x - 6) == 0 || (2*left*left*left - 4*left*left + 3*left - 6) == 0 || (2*right*right*right - 4*right*right + 3*right - 6) == 0)
//定义判断区间中点或端点处函数值是否直接等于零的宏
#define WC ((2*x*x*x - 4*x*x + 3*x - 6) >= 0.01) || ((2*x*x*x - 4*x*x + 3*x - 6) <= -0.01)
//定义不满足误差的条件
int  main()
{
	double x, left = -10, right = 10;												//中点变量 x、代表区间两端点的变量
	for (x = (right + left) / 2 ; WC ; x = (right + left) / 2)						//限定误差小于0.01
	{
		if (DY)																		//等于 0 的情况
		{
			printf(" 方程的解是: %lf 或 %lf 或 %lf 中的一个\n ", x, left, right);
			break;
		}
		if ((2*x*x*x - 4*x*x + 3*x - 6) * (2*left*left*left - 4*left*left + 3*left - 6) > 0)
		//判断区间中点 x 的函数值与一端点的函数值是否同号
			left = x;																//同号，更新该端点
		else
			right = x;																//不同号，更新另一端点
	}
	printf(" 方程的近似解是: %g ， 此时的函数值是: %lf\n ", x, 2*x*x*x - 4*x*x + 3*x - 6);
	return 0;
}
/*
思路:
起始区间两端点的函数值异号，令 x 等于区间中点，代入方程计算，若误差不小于 0.01 就一直循环。
循环过程:先将函数值在区间中点和端点处为零的情况用一个 if 单独挑出来。然后，判断 区间中点 和 任选的一个端点 处函数值的符号，若同号，则将该
端点的值更新为区间中点 x，若异号，则是将另一个端点的值更新为 x。
/**/

/*
//一个给出方程系数、起始区间后可以求出方程近似解的程序
double x, left, right, a, b, c, d, wc;					//区间中点和左右端点、一元三次方程的四个系数、误差
int i, i2, pd = 1;										//循环变量 i 和 i2、询问是否停止计算起始区间的变量 pd
#define DY ((a*x*x*x + b*x*x + c*x + d) == 0 || (a*left*left*left + b*left*left + c*left + d) == 0 || (a*right*right*right + b*right*right + c*right + d) == 0)
//定义判断区间中点或端点处函数值是否直接等于零的宏
#define WC ((a*x*x*x + b*x*x + c*x + d) >= wc/2) || ((a*x*x*x + b*x*x + c*x + d) <= -wc/2)
//定义不满足误差的条件
int  main()
{
	printf("\n 二分法求一元三次方程解。\n 请依次输入方程三次项、二次项、一次项、常数项的系数，用空格空开: ");
	scanf_s("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf(" 接下来帮助您判断求方程解的起始区间，输入任意区间两端点可计算出区间内每个整数的  函数值。\n");
	for (i = 0; pd != 0; i++)														//帮助判断起始区间
	{
		printf(" 请依次输入要判断的区间的左右端点 : ");
		scanf_s("%lf%lf", &left, &right);
		for (i2 = 0, x = left; left + i2 != right + 1; ++i2, x = left + i2)
			printf(" x 为 %g 时的函数值: %g\n", left + i2, a*x*x*x + b*x*x + c*x + d);
		printf(" 要继续帮助请输入任意数字，结束帮助请输入0: ");
		scanf_s("%d",&pd);
	}
	printf(" 请依次输入起始区间左、右端点、允许的误差大小: ");
	scanf_s("%lf %lf %lf", &left, &right, &wc);
	for (x = (right + left) / 2 ; WC ; x = (right + left) / 2)						//限定误差
	{
		if (DY)																		//等于 0 的情况
		{
			printf(" 方程的解是: %g 或 %g 或 %g 中的一个\n ", x, left, right);
			break;
		}
		if ((a*x*x*x + b*x*x + c*x + d) * (a*left*left*left + b*left*left + c*left + d) > 0)
		//判断区间中点 x 的函数值与一端点的函数值是否同号
			left = x;																//同号，更新该端点
		else
			right = x;																//不同号，更新另一端点
	}
	printf(" 方程的近似解是: %g ， 误差是: %lf\n ", x, a*x*x*x + b*x*x + c*x + d);
	return 0;
}
/**/