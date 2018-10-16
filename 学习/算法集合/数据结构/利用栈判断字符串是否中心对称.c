#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//判断字符串是否中心对称，利用了栈先进后出的特性

typedef struct s									//顺序栈
{
	char c[1000];									//栈中元素
	int top;										//栈顶指针
}s;

int main()
{
	char y[1000], i, len, flag = 0;		s x;
	printf("\n  请输入字符串： ");
	scanf("%s", &y);		getchar();
	for (len = 0; y[len] != '\0'; len++);
	if (len % 2 == 1)								//确定要压入的长度
	{
		len /= 2;
		flag = 1;
	}
	else	len /= 2;
	for (i = 0, x.top = -1; i < len; i++)			//将字符串的前半段压入栈中
	{
		x.top++;									//更新栈顶位置
		x.c[x.top] = y[i];
	}
	if (flag)	i = len + 1;						//跳过奇数长度时的中间字符
	else	i = len;
	for (; (y[i] != '\0') || (x.top != -1); i++)	//依次出栈比较
		if (y[i] != x.c[x.top--])
		{
			printf("\n  不是中心对称的字符串\n\n  ");
			return 0;
		}
	printf("\n  该字符串是中心对称的\n\n  ");
	return 0;
}

/*
思路：
判断中心对称，刚好可以利用栈的先进后出特性，将字符串前半段压入栈中，再依次出栈与字符串的后半段元素进行比较，只要不相等便输出结果结束。
唯一要注意的是，当字符串元素为奇数个时，读入的便不是字符串的一半，而是一半减一，出栈比较时，要跳过字符串中心的那个元素。
*/