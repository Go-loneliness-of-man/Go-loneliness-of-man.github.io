#include<stdio.h>
//计算从阶乘 1!+2!+.....20! 的值
int c, d = 0, i = 0;
unsigned long a = 0, b = 1;
int main()
{
	for (a, b, i, d; d <= 20; d++, i = 0)				//每次循环初始化 i 的值
	{
		b = d;											//初始化b的值，使其等于for循环的次数
		c = b;											//保留b这次对于while循环的值用来限定次数
		while (i < c)
		{
			i++;
			b = b*i;
		}
		a = a + b;
	}
	printf("%u\n", a);
	return 0;
}