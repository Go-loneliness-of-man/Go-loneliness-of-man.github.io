#include<stdio.h>
//得到一个 1000 以内的数字，分别根据百位、十位数字输出多个 B 和 S，最后将个位数字以 123...n 的形式表示，如 234 表示为 BBSSS1234
int main()
{
	int n, b, s, g, i;
	scanf("%d", &n);
	b = n / 100 % 10;
	s = n / 10 % 10;
	g = n % 10;
	for (i = 0; i < b; i++)
		printf("B");
	for (i = 0; i < s; i++)
		printf("S");
	for (i = 0; i < g; i++)
		printf("%d", i + 1);
	return 0;
}
/*
思路：获取各位数字，利用循环依次输出指定字符。
*/