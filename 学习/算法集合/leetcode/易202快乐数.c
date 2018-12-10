#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始
终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例:

输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

bool isHappy(int n)
{
	int rcd[1000], next, len, i;						//出现过的 rcd，下一个数 next，长度 len，循环变量 i
	for (rcd[0] = n, len = 1; 1; rcd[len++] = n = next)	//循环推导
	{
		for (next = 0; n; n /= 10)						//推导一次
			next += (n % 10)*(n % 10);
		if (next == 1)	return true;					//是
		else											//不是
			for (i = 0; i < len; i++)					//查询该数是否出现过
				if (rcd[i] == next)	return false;		//该数出现过，陷入循环，结束
	}
	return false;
}

int main()
{
	printf("%d", isHappy(2));
	return 0;
}
/*
思路：
不断推导下一个数，过程中记录出现过的数字，只要有重复便证明会无限循环下去，若其不为 1 便不是快乐数
*/