#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
原题：
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

int countPrimes(int n)
{
	int nums[120000] = { 0 }, i, j, temp, x, len;	//素数数组、循环变量 i 和 j、临时变量 temp、标记 x、素数个数 len
	for (i = nums[0] = 2, len = 0; i < n; i++)		//找出 n 下所有素数
	{
		for (j = 0, x = 1, temp = (int)sqrt(i) + 1; nums[j] < temp; j++)	//遍历素数数组判断 i 是否是素数
			if (i%nums[j] == 0)						//不是，改变标记
			{
				x = 0;
				break;
			}
		if (x)	nums[++len] = i;					//是，添加到素数数组
	}
	return len;
}

int main()
{
	printf("%d", countPrimes(10));
	return 0;
}

/*
思路：
埃氏筛法，每次用小于该数算术平方根的素数筛选 2 ~ n 的所有数。
*/