#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//ת�� N x N �Ķ�ά���飬������������Ԫ�����л���
#define N 5

void zz(int a[N][N]);								//ת�ö�ά����һ��

void o(int a[N][N]);								//��ӡ��ά����һ��

int main()
{
	int a[N][N], i, j;
	srand((unsigned int)time(NULL));				//����ʱ�����Ϊ���������
	for (i = 0; i < N; i++)							//Ϊ��ά���������ֵ
		for (j = 0; j < N; j++)
			a[i][j] = rand() % 100;
	printf("\n  ��ʼ��ά�������£�\n\n");
	o(a);
	zz(a);
	printf("\n  ת�ú��ά�������£�\n\n");
	o(a);
	printf("\n  ");
	return 0;
}

void zz(int a[N][N])								//ת�ö�ά����һ��
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

void o(int a[N][N])									//��ӡ��ά����һ��
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			printf("%5d", a[i][j]);
			if (j + 1 == N) printf("\n");
		}
}
/*
˼·�����л���ֻ�轫һ������Ԫ������һ������Ԫ�ؽ���λ�ã�ÿ�Ի���������Ԫ�ؼ�������������������պ��෴��������������ڶԽ��߶Գƣ�
���ڴˣ��Խ�������Ԫ�ز�����ֻ��Ҫ���Խ���һ�������Ԫ������һ�������Ԫ�ذ��ն�Ӧ��ϵһһ�������������ת�á�
*/