#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/
//该题有多种解法，这里列三种：简单相除、枚举、用最大次方整除


//简单相除
bool isPowerOfThree(int n)
{
	if (n <= 0)	return false;						//特殊情况
	else if (n == 1)	return true;
	for (; n != 1; n /= 3)							//循环取余 3，除 3
		if (n%3 != 0)	return false;
	return true;
}
/*
思路：
3 的幂次一定是 3 * 3 * 3 ... * 3 的格式，则从 3 的 1 次方开始取余，取余为 0 便将 n 除 3 再取余，中途只要取余不为 0 便 false。
*/

/*
//对数
bool isPowerOfThree(int n)
{
	if (n <= 0 || n > 1162261467)	return false;	//特殊情况
	for (int i = 1; i <= n; i *= 3)					//以 3 的整数倍幂次方进行比较
		if (n == i)		return true;
	return false;
}
/*
思路：
若一个数是 3 的幂次方，则对其求对数，真数一定为整数。上面的代码并不是最高效的，还可以分情况优化。
注：int 能存储的最大 3 的幂次方数是 1162261467，给 1162261467 再乘 3 会溢出。
*/

/*
//用最大次方整除
bool isPowerOfThree(int n)
{
	return n > 0 ? !(1162261467 % n) : false;
}
/*
思路：
对任意一个素数 x 的幂次方进行彻底因式分解，都是 x * x ... * x，即其因数中只有 x 或 x 的幂次，不包含任何其它数字，所以 x 的幂次不能
整除任何非 x 幂次的数。则用 int 下最大的 x 的幂次方（例如 3 是 1162261467）取余，若结果不是 0 便证明不是 x 的幂次。这种方法只适用
于像素数这种本身不可再分的数字，不适用于合数。
*/

int main()
{
	printf("%d", isPowerOfThree(243));
	return 0;
}