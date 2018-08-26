#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//转置 N x N 的二维数组，即令所有数组元素行列互换
#define N 5

void zz(int a[N][N]);								//转置二维数组一次

void o(int a[N][N]);								//打印二维数组一次

int main()
{
	int a[N][N], i, j;
	srand((unsigned int)time(NULL));				//利用时间戳作为随机数种子
	for (i = 0; i < N; i++)							//为二维数组随机赋值
		for (j = 0; j < N; j++)
			a[i][j] = rand() % 100;
	printf("\n  起始二维数组如下：\n\n");
	o(a);
	zz(a);
	printf("\n  转置后二维数组如下：\n\n");
	o(a);
	printf("\n  ");
	return 0;
}

void zz(int a[N][N])								//转置二维数组一次
{
	int temp, i, j;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
}

void o(int a[N][N])									//打印二维数组一次
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			printf("%5d", a[i][j]);
			if (j + 1 == N) printf("\n");
		}
}
/*
思路：行列互换只需将一半数组元素与另一半数组元素交换位置，每对互换的数组元素间的特性是行数、列数刚好相反，因此这两数关于对角线对称，
基于此，对角线数组元素不动，只需要将对角线一侧的数组元素与另一侧的数组元素按照对应关系一一互换，即可完成转置。
*/