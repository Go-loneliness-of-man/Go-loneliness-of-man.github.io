#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 2 的 0 次方等于 1
示例 2:

输入: 16
输出: true
解释: 2 的 4 次方等于 16
示例 3:

输入: 218
输出: false
*/

bool isPowerOfTwo(int n)
{
	if (n < 1)	return false;						//特殊情况
	else if (n <= 2)	return true;
	for (int x = 2; n > x; x <<= 1)					//依次取余 2 的幂次
		if (n%x != 0)	return false;
	return true;
}

int main()
{
	printf("%d", isPowerOfTwo());
	return 0;
}

/*
思路：
素数的幂次方都能整除小于它的幂次。
*/