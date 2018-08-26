#include<stdio.h>
char c;													//存储字符串的变量
int words = 0, space = 0, num = 0, it = 0;				//计量各字符数的变量
int count(char x);										//计算各个字符数量的函数 count()
int main()
{
	printf("请输入一行文字: ");
	count(c);											//传递字符串给 count() 函数
	printf("字母数:%d\n空格数:%d\n数字数:%d\n其它字符数:%d\n", words, space, num, it / 2);		//一个汉字相当于2个字符
	return 0;
}
int count(char x)
{
	if (x >= 'a'&&x <= 'z' || x >= 'A'&&x <= 'Z')
		words++;
	else if (x == ' ')
		space++;
	else if (x >= '0' && x <= '9')
		num++;
	else
		it++;
	return (x = getchar()) == '\n' ? 0 : count(x);		//(x=getchar()) == '\n';每次从缓冲区读取一个字符，只要没读到回车
}