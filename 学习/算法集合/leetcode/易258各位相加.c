#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

int q(int num)								//求出各位之和
{
	int sum;
	for (sum = 0; num; num /= 10)
		sum += num % 10;					//取出一位相加
	return sum;
}

int addDigits(int num)
{
	for (; num > 9; num = q(num));			//循环求值
	return num;
}

int main()
{
	printf("%d", addDigits(999999674));
	return 0;
}

/*
思路：
循环求值，只要大于 9 便继续，求值可用取余加相除的办法求得各位之和。
*/