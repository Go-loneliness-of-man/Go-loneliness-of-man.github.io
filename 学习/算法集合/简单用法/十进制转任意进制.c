#include<stdio.h>
//将十进制数字转换为任意进制数字

void zh(int a, int b);

int main()
{
	int num, jz;
	printf("\n  请依次输入十进制数和要转换的进制： ");
	scanf_s("%d%d", &num, &jz);
	zh(num, jz);
	printf("\n\n  ");
	return 0;
}

void zh(int a, int b)
{
	int aa[20], i;
	for (i = 0; a; i++)
	{
		aa[i] = a%b;
		a /= b;
	}
	printf("\n  该十进制数转为 %d 进制数为： ", b);
	for (i -= 1; i >= 0; i--)	printf("%d", aa[i]);
}
/*
	思路：
	只能转换整数，方法取的是乘二取余逆序法的逆运算。
*/