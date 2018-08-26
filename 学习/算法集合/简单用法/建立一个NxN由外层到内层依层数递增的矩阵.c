#include<stdio.h>
//建立一个 N x N 、由外层到内层数字依层数递增的矩阵

#define N 9

void fz(int (*a)[N]);								//为矩阵赋值

int main()
{
	int a[N][N];
	fz(a);											//为矩阵赋值
	printf("\n");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			printf("%5d", a[i][j]);
			if ((j + 1) % N == 0)	printf("\n\n");
		}
	printf("\n    ");
	return 0;
}

void fz(int(*a)[N])
{
	int m, i, j;
	if (N % 2 == 0)		m = N / 2;						//确定矩阵的中间行
	else if (N % 2 != 0)		m = N / 2 + 1;
	for (i = 0; i < m; i++)								//赋值所有层的上下两边
	{
		for (j = i; j < N - i; j++)
			a[i][j] = a[N - i - 1][j] = i + 1;
	}
	for (i = 0; i < m; i++)								//赋值所有层的左右两边
		for (j = i + 1; j < N - i; j++)
			a[j][i] = a[j][N - i - 1] = i + 1;
}
/*
	思路：
	在纸上画个图出来，观察会发现，每层左上角的数字位于对角线上，确定了一层的一点，便可以确定该层其它点的位置。
	层数由矩阵的 N 决定，N 是奇数则层数为 N/2 + 1，N 是偶数则为 N/2，确定层数是很重要的，关乎接下来所有赋值的终止条件
*/