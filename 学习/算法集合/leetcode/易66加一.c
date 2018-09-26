#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

int *jin(int *x)									//递归进位
{
	*(x--) = 0;										//重置当前位并移动到前一位
	if (*x < 9)										//该位小于 9
		(*x) += 1;									//进 1
	else
		return jin(x);
	return x;
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int *x = NULL, bj, i;							//新数组 x，标记 bj、循环变量 i
	for (i = 0, bj = 1; bj && i < digitsSize; i++)	//判断是否所有位为 9
		if (digits[i] != 9)		bj = 0;
	if (bj)											//所有位均为 9 的情况
	{
		*returnSize = digitsSize + 1;				//位数加 1
		x = (int*)malloc(sizeof(int) * (*returnSize));
		for (x[0] = 1, i = 1; i < *returnSize; i++)	//第一位为 1，其它位为 0
			x[i] = 0;
	}
	else											//并非所有位均为 9
	{
		*returnSize = digitsSize;					//位数不变
		x = (int*)malloc(sizeof(int) * (*returnSize));
		if (digits[digitsSize - 1] < 9)				//最后一位小于 9
			digits[digitsSize - 1] += 1;			//加一
		else	jin(&digits[digitsSize - 1]);		//最后一位等于 9，进行递归进位
		for (i = 0; i < digitsSize; i++)			//复制
			x[i] = digits[i];
	}
	return x;										//返回数组
}

int main()
{
	int a[30], i, n, *x = NULL, n3, *n2 = &n3;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)		scanf_s("%d", &a[i]);
	x = plusOne(a, n, n2);
	for (i = 0; i < *n2; i++)		printf("  %d", x[i]);
	return 0;
}
/*
思路：
对初始数组最后一位加一，如果最后一位是 9，则重置该位为 0，前一位加一，以此类推。
进位：可采用递归，若当前位小于 9，则加一即可，若等于 9 则递归。
注意：当遇到第一位也满了的情况（即所有位均为 9 的情况），便整体向后退一位并重置为 0，第一位设为 1。
*/