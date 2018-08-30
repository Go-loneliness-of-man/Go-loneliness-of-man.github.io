#include<stdio.h>
//将输入数字的所有位相加，将结果用汉语拼音表示出来

char *czs(long long x)									            //数值数字转字符数字
{
	static char sc[21];								              	//声明字符数字，由于主函数要引用其地址，所以定义为静态
																	//开始取出每位上的数字
	long long pst[20], i, bit;        						  	//数组 pst[] 存储每位的数字、i 控制位置、bit 是 x 的位数
	for (i = 0; i < 20; pst[i] = 0, i++);	  			    //初始化 pst[] 内所有元素的值为 0
	i = 0;												                    //重置 i = 0
	for (long long j = 1; i < 20; i++, j *= 10) 			//循环，取出所有位上对应的数字
		pst[i] = ((unsigned int)x / j) % 10;		        //利用取余取出数字
															//取出每位数字结束
	for (i = 19, bit = 20; pst[i] == 0; i--, bit--);	//判断数值数字的位数
	if (bit == 0) bit = 1;					        			    //如果数值数字是 0，将位数确定为 1
	long long *pst2 = pst + bit - 1;				        	//创建 pst2 指向 pst[]
	for (i = 0; i < bit; i++, pst2--)       					//将取出的有效位数值数字转化为字符数字
		sc[i] = *pst2 + 48;								              //循环赋值
	sc[i] = '\0';									          	        //添加结束符
	return sc;
	/*这里返回字符数字，但注意，该局部字符串是静态存储，所以才能被传回，不过需要在父函数创建一个字符数组进行一次转存，否则下次调用会
	覆盖掉上次调用得到的字符串*/
}

void scp(char *x, char *y, int size)					       //字符串复制，将 y 复制到 x 中，size 是最大长度
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

int main()
{
	char a[103], *b;	int nums = 0;
	gets(a);										             //读入样例
	for (b = a; *b != '\0'; b++)						//循环相加
		nums += (*b - 48);
	scp(a, czs(nums), 103);								  //转换为字符数字
	for (b = a; *b != '\0'; b++)						//循环读出结果
	{
		switch (*b)
		{
		case '1':	printf("yi");	break;
		case '2':	printf("er");	break;
		case '3':	printf("san");	break;
		case '4':	printf("si");	break;
		case '5':	printf("wu");	break;
		case '6':	printf("liu");	break;
		case '7':	printf("qi");	break;
		case '8':	printf("ba");	break;
		case '9':	printf("jiu");	break;
		case '0':	printf("ling");	break;
		}
		if (*(b + 1) != '\0')	printf(" ");
	}
	return 0;
}
/*
思路：
以字符形式读入，将各位循环相加到 nums 中，再将 nums 转为字符数字，用 switch() 实现以拼音输出
*/

/*
原题：
1002 写出这个数（20 分）
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10 的 100 次方。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/