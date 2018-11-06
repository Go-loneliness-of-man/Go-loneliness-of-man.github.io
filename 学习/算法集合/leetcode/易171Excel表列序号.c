#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个 Excel 表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

示例 1:

输入: "A"
输出: 1

示例 2:

输入: "AB"
输出: 28

示例 3:

输入: "ZY"
输出: 701
*/

int titleToNumber(char *s)
{
	int rt, i, j;										//结果 rt、循环变量 i、进位变量 j
	for (i = 0; s[i] != '\0'; i++);						//跳到字符串末尾
	for (rt = 0, j = 1, i--; i != -1; i--, j *= 26)		//循环计算
		rt += (s[i] - 64)*j;							//进行一次累加
	return rt;
}

int main()
{
	printf("%d", titleToNumber("ZY"));
	return 0;
}
/*
思路：
这道题就比较逗比了，只是 168 的逆运算，而且这个逆运算简单的一批。
*/