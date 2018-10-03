#include<stdio.h>
#include<stdlib.h>
/*
原题：
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
由于返回类型是整数，小数部分将被舍去。
*/

int mySqrt(int x)
{
	if (x*x == x)	return x;
	long long left = 0, right = x, mid = x / 2;								//区间三点
	for (; mid != left; mid = (left + right) / 2)							//循环查找
		if (mid*mid == x || ((mid + 1)*(mid + 1) > x) && mid*mid < x)
			return mid;
		else if (mid*mid > x)	right = mid;
		else if (mid*mid < x)	left = mid;
	return 0;																//可省略，只是略后 leetcode 编译器不通过
}

int main()
{
	printf("%d", mySqrt(2147395599));
	return 0;
}

/*
思路：
平方根一定位于 0 到本身这个区间内，自然数区间本身就是有序的，所以利用二分查找即可。
结束条件：mid 平方等于目标或 mid 平方小于目标但 mid + 1 的平方又大于目标，则返回 mid。
*/