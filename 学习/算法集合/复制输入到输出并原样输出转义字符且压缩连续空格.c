#include<stdio.h>
//将输入复制到输出，并将转义字符原样输出，但将其中的连续空格压缩为一个空格
#define NONE 0;
int main()
{
	int i;
	char c[100] = "213         12 321 \b        t\b\tt\\tt\t\            b\\\\         \\t\\\b\\t\b"
		 , bj = NONE;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == ' ')
			for (bj = c[i]; c[i] == ' '; i++);			//标记 c 遇到过一次空格，并将接下来的连续空格全部读入消除
		if (bj == ' ')									//如果 c 遇到过空格，输出一个空格
		{
			putchar(bj);								//若 c 遇到过空格，输出一个空格
			bj = NONE;									//重置 bj 的值
		}
		if (c[i] == '\t')
			printf("\\t");
		else if (c[i] == '\b')
			printf("\\b");
		else if (c[i] == '\\')
			printf("\\\\");
		else
			putchar(c[i]);								//输出正常字符
	}
	return 0;
}