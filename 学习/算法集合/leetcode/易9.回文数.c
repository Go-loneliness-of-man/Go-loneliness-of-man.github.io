#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
*/

bool isPalindrome(int x)
{
	if (x < 0 || (x % 10 == 0 && x != 0)) return false;
	int y = x, num = 0, temp;
	for (; x != 0; temp = x % 10, num = num * 10 + temp, x /= 10);
	if (num == y)	return true;
	else  return false;
}
int main()
{
	int x = 10;		bool a;
	a = isPalindrome(x);
	printf("%d", a);
	return 0;
}
/*
思路：
据题意，则将回文数的数字顺序倒序其值也不会发生变化，利用这点即可判断。
注意：根据题意，负数全不是，所以检测到负数全不通过。并且最后几位全是 0 的也全不能通过，所以能被 10 整除的也全不通过。这样可以大幅减少
不必要的运算，提升运行速度。
*/