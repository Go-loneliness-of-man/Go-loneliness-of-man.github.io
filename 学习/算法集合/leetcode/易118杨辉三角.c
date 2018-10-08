#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
*/

int **generate(int numRows, int **columnSizes)
{
	int i, j, k, **x;										//循环变量 i、j、k、存储结果的 x
	*columnSizes = (int*)malloc(sizeof(int)*numRows);		//存储每行长度的数组，为其申请空间
	x = (int**)malloc(sizeof(int*)*numRows);				//创建动态二维数组
	for (i = 0; i < numRows; i++)
		x[i] = malloc(sizeof(int)*numRows);
	for (i = j = 0; i < numRows; i++, j++)					//循环建立 numRows 行杨辉三角
	{
		(*columnSizes)[i] = i + 1;							//存储长度
		x[i][0] = x[i][j] = 1;								//该行第一个、最后一个元素
		if (i > 1)											//第三行起
			for (k = 1; k < j; k++)							//求中间元素并赋值
				x[i][k] = x[i - 1][k - 1] + x[i - 1][k];	//该元素等于上一行两对应元素的和
	}
	return x;
}

int main()
{
	int numRows, *y, **columnSizes = &y, **x, i, j, k;
	scanf_s("%d", &numRows);
	x = generate(numRows, columnSizes);
	for (i = j = 0; i < numRows; i++, j++)
	{
		for (k = 0; k < (*columnSizes)[i] - 1; k++)
			printf("  %d", x[i][k]);
		printf("  %d\n", x[i][j]);
	}
	return 0;
}

/*
思路：
很简单，每行第一个和最后一个元素都赋值为 1，则从第三行开始，每行中间的数字都根据上一行对应的两个数字推出即可。
注：leetcode 给的函数原型中，columnSizes 这个参数是用来存储每行数字的个数的，不是用来返回的。
*/