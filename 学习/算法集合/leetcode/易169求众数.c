#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 n / 2 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

int majorityElement(int *ums, int numsSize)
{
	int max, count, i;											//结果 rt、计数 count、循环变量 i
	for (i = 1, count = 1, max = ums[0]; i < numsSize; i++)		//循环计数
	{
		if (max == ums[i])		count++;						//相同数字，自增
		else	count--;										//不同，自减
		if (count <= 0)											//等于 0，更新
		{
			max = ums[i];
			count = 1;
		}
	}
	return max;
}

int main()
{
	int n[1000] = { 2,2,1,1,1,2,2 }, s = 7;
	printf("%d", majorityElement(n, s));
	return 0;
}
/*
思路：
注意题目的大于 n / 2 这个条件，这意味着众数出现的次数比其它所有数字加起来都要大，也就是 众数个数 - 其它所有数个数 > 0，利用这一点，可
以设置一个变量专门用来计数，初始次数为 1，遇到相同数字就自增，遇到不同数字就自减，当自减到 0 就更新数字，遍历一次就能找到众数。
*/