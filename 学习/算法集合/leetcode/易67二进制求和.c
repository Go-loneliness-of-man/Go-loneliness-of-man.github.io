#include<stdio.h>
#include<stdlib.h>
/*
原题：

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/
//两个版本，由于 leetcode 编译器与 VS2015 的 C 字符集不同，因此提交的版本中专门定义了函数执行相加操作，使其适用于任何字符集。

/*
//版本一，只适用于 ASCⅡ 字符集
//逆置一个数组，参数：逆置起始地址 x，逆置部分总长度 size，本地版本
void huanchar(char *x, char * y)						//交换两变量一次
{
	char z = *x;
	*x = *y;
	*y = z;
}
void nzchar(char *x, int size)
{
	int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--)			//逆置
		huanchar(&x[i], &x[j]);
}

char *addBinary(char *a, char *b)
{
	int i, j, k;	char *c;							//循环变量 ijk、运算结果字符串 c
	for (i = 0; a[i] != '\0'; i++);						//计算长度
	for (j = 0; b[j] != '\0'; j++);
	if (i >= j)											//确定字符串 c 的长度
		c = (char*)malloc(sizeof(char) * 2 * i);
	else
		c = (char*)malloc(sizeof(char) * 2 * j);
	nzchar(a, i);		nzchar(b, j);					//逆置二者
	for (c[0] = '0', c[1] = '\0', k = 0; *a != '\0'&&*b != '\0'; a++, b++)
	{
		if (c[k] != '1')	c[k++] = *a + *b - 48;		//进位与不进位在相加时的运算不同
		else	c[k++] = *a + *b - 96 + c[k];
		if (c[k - 1] == '2')							//进位，当前位为 2
		{
			c[k - 1] = '0';
			c[k] = '1';
		}
		else if (c[k - 1] == '3')						//进位，当前位为 3
		{
			c[k - 1] = '1';
			c[k] = '1';
		}
	}
	if (*a != '\0')										//结合另一者未进行运算的部分进行推导
		for (; *a != '\0'; a++)
		{
			if (c[k] != '1')	c[k++] = *a;			//进位与不进位在相加时的运算不同
			else	c[k++] = *a + c[k] - 48;
			if (c[k - 1] == '2')						//进位，当前位为 2
			{
				c[k - 1] = '0';
				c[k] = '1';
			}
		}
	else
		for (; *b != '\0'; b++)
		{
			if (c[k] != '1')	c[k++] = *b;			//进位与不进位在相加时的运算不同
			else	c[k++] = *b + c[k] - 48;
			if (c[k - 1] == '2')						//进位，当前位为 2
			{
				c[k - 1] = '0';
				c[k] = '1';
			}
		}
	if (c[k] != '1')	c[k] = '\0';					//添加结束符
	else	c[++k] = '\0';
	nzchar(c, k);										//逆置
	return c;
}
*/


//版本二，适用于任何字符集
//逆置一个数组，参数：逆置起始地址 x，逆置部分总长度 size，本地版本
void huanchar(char *x, char * y)						//交换两变量一次
{
	char z = *x;
	*x = *y;
	*y = z;
}
void nzchar(char *x, int size)
{
	int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--)			//逆置
		huanchar(&x[i], &x[j]);
}

//参数依次是：两个加数的地址，存储结果的地址 z
void add(char *x, char *y, char *z)						//执行一次相加操作
{
	if (*z != '1')										//上一次未进位
		switch (*x)
		{
		case '0':
			switch (*y)
			{
			case '0':	*z = '0';	break;
			case '1':	*z = '1';	break;
			}
			break;
		case '1':
			switch (*y)
			{
			case '0':	*z = '1';	break;
			case '1':
				*z = '0';
				*(z + 1) = '1';							//进位
				break;
			}
			break;
		}
	else												//上一次有进位
		switch (*x)
		{
		case '0':
			switch (*y)
			{
			case '0':	break;							//二者均为 0，不运算
			case '1':									//其中一者为 1，进位
				*z = '0';
				*(z + 1) = '1';
				break;
			}
			break;
		case '1':
			switch (*y)
			{
			case '0':
				*z = '0';
				*(z + 1) = '1';
				break;
			case '1':									//二者均为 1，当前位置为 1
				*z = '1';
				*(z + 1) = '1';							//进位
				break;
			}
			break;
		}
}

//传入两个参数，第一个是运算结果的当前位，第二个是加数的当前位
void add2(char *x, char *y, int *k)
{
	int i;		char *f = (x - 6);
	for (; *y != '\0'; x++, y++, (*k)++)
	{
		if (*x != '1')	*x = *y;						//前一位未进位
		else											//上一次有进位，进行推导
			if (*y == '0');								//不再次进位
			else if (*y == '1')							//值为 1，再次进位
			{
				*x = '0';
				*(x + 1) = '1';
			}
	}
	if (*x != '1')	*x = '\0';
	else
	{
		(*k)++;
		*(x + 1) = '\0';
	}
}

char *addBinary(char *a, char *b)
{
	int i, j, k;	char *c;							//循环变量 ijk、运算结果字符串 c
	for (i = 0; a[i] != '\0'; i++);						//计算长度
	for (j = 0; b[j] != '\0'; j++);
	if (i >= j)											//确定字符串 c 的长度
		c = (char*)malloc(sizeof(char) * 2 * i);
	else
		c = (char*)malloc(sizeof(char) * 2 * j);
	nzchar(a, i);		nzchar(b, j);					//逆置二者
	for (c[0] = '0', c[1] = '\0', k = 0; *a != '\0'&&*b != '\0'; a++, b++, k++)		//得出参与运算的部分
		add(a, b, &c[k]);
	if (*a != '\0')										//结合另一者未参与运算的部分进行推导
		add2(&c[k], a, &k);
	else if (*b != '\0')
		add2(&c[k], b, &k);
	else if (c[k] == '1')	k++;
	nzchar(c, k);										//逆置
	return c;
}

int main()
{
	char a[100] = "10000011", b[100] = "111000";
	printf("%s", addBinary(a, b));
	return 0;
}

/*
思路：
模拟加法运算。
先逆置二者，然后相加直到一者到尽头，然后再结合另一者未参与运算的部分进行推导，算出整个字符串。
进位：当前位若大于等于 2，下一位进 1，若等于 2 当前位重置为 0，若等于 3 重置为 1。
结束符：注意结束符的添加，最后一位是否进位关乎结束符的添加位置。
*/