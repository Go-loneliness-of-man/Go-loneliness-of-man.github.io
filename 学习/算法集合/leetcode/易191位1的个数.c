#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
/*
原题：
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

示例 :

输入: 11
输出: 3
解释: 整数 11 的二进制表示为 00000000000000000000000000001011


示例 2:

输入: 128
输出: 1
解释: 整数 128 的二进制表示为 00000000000000000000000010000000
*/

int hammingWeight(uint32_t n)
{
	int i;
	for (i = 0; n; n /= 2)	if (n % 2 == 1)		i++;	//余数为 1，计数
	return i;
}

int main()
{
	printf("%d", hammingWeight(128));
	return 0;
}
/*
思路：
很简单，在转换的同时计数就可以了。
*/