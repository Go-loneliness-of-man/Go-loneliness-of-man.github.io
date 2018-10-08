#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/

int *getRow(int rowIndex, int *returnSize)
{
	int *x = (int*)malloc(sizeof(int)*rowIndex + 1), *y = (int*)malloc(sizeof(int)*rowIndex + 1), i, j;
	for (i = 0; i < rowIndex + 1; i++)						//循环推出第 rowIndex 行
	{
		y[0] = y[i] = 1;									//赋值第一个和最后一个为 1
		for (j = 1; j < i; j++)	y[j] = x[j - 1] + x[j];		//推导该行
		for (j = 0; j <= i; x[j] = y[j], j++);				//保存本次 y 以便推导下一行
	}
	*returnSize = rowIndex + 1;
	return y;
}

int main()
{
	int rowIndex, x, *size = &x, i, *y;
	scanf_s("%d", &rowIndex);
	y = getRow(rowIndex, size);
	for (i = 0; i < *size; i++)		printf("  %d", y[i]);
	return 0;
}

/*
思路：
很简单，只要指定行，用两个数组循环推导即可。
*/