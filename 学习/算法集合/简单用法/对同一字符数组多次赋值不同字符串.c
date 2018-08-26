#include <stdio.h>
//使用户可以向同一数组多次传递不同的字符串
int  main()
{
	char c[100];
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n 请输入字符串: ");
		gets_s(c, 100);
		printf(" 您输入的字符串是: %s\n", c);
		printf(" 若要重新赋值请输入 0 以外任意数字: ");
		scanf_s("%d", &pd);
		getchar();					//scanf_s() 不会把最后的回车符读入，这里消除回车符对下次循环时的 gets_s()的影响
	}
	return 0;
}