#include<stdio.h>
char a[100];
int main()
{
	printf("请输入字符: ");
	gets_s(a, 100);					// get_s() 需要额外一个参数指出字符串的长度
	printf("%s\n", a);
	return 0;
}