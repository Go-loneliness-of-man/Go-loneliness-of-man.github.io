#include<stdio.h>
//求正整数的位数和每一位的数字并倒序输出
int x, a, b, c, d, e;										//获取该数字的x，从a到e依次是万到个位数字
int judge(int x1);											//判断x是几位数
int inverted_order(int x2);									//将 x 的各位数字倒序排列
int main()
{
	printf("\n  请输入一个五位以内的数字: ");
	scanf_s(" %d", &x);
	printf("\n  该数字是一个 %d 位数\n\n", judge(x));
	printf("  万位数字是: %d\n\n  千位数字是: %d\n\n  百位数字是: %d\n\n  十位数字是: %d\n\n  个位数字是: %d\n\n", a, b, c, d, e);
	printf("  逆序输出: %05d\n\n  ", inverted_order(x));		//限制输出位数，补全 0
	return 0;
}
int judge(int x1)											//定义judge()函数
{
	a = (x1 / 10000) % 10;
	b = (x1 / 1000) % 10;
	c = (x1 / 100) % 10;
	d = (x1 / 10) % 10;
	e = x1 % 10;
	if (a == 0 && b == 0 && c == 0 && d == 0)
		return 1;
	else if (a == 0 && b == 0 && c == 0)
		return 2;
	else if (a == 0 && b == 0)
		return 3;
	else if (a == 0)
		return 4;
	else if (a != 0)
		return 5;
	return 0;												//结构需要，无用
}
int inverted_order(int x2)									//定义inverted_order()函数
{
	switch (judge(x))
	{
	case 1:
		return e;
		break;
	case 2:
		return 10 * e + d;
		break;
	case 3:
		return 100 * e + 10 * d + c;
		break;
	case 4:
		return 1000 * e + 100 * d + 10 * c + b;
		break;
	case 5:
		return 10000 * e + 1000 * d + 100 * c + 10 * b + a;
		break;
	}
	return 0;										//结构需要，无用
}