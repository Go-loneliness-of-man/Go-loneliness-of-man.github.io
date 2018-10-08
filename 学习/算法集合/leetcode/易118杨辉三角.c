#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
*/

int **generate(int numRows, int **columnSizes)
{
	int i, j, k, **x;										//ѭ������ i��j��k���洢����� x
	*columnSizes = (int*)malloc(sizeof(int)*numRows);		//�洢ÿ�г��ȵ����飬Ϊ������ռ�
	x = (int**)malloc(sizeof(int*)*numRows);				//������̬��ά����
	for (i = 0; i < numRows; i++)
		x[i] = malloc(sizeof(int)*numRows);
	for (i = j = 0; i < numRows; i++, j++)					//ѭ������ numRows ���������
	{
		(*columnSizes)[i] = i + 1;							//�洢����
		x[i][0] = x[i][j] = 1;								//���е�һ�������һ��Ԫ��
		if (i > 1)											//��������
			for (k = 1; k < j; k++)							//���м�Ԫ�ز���ֵ
				x[i][k] = x[i - 1][k - 1] + x[i - 1][k];	//��Ԫ�ص�����һ������ӦԪ�صĺ�
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
˼·��
�ܼ򵥣�ÿ�е�һ�������һ��Ԫ�ض���ֵΪ 1����ӵ����п�ʼ��ÿ���м�����ֶ�������һ�ж�Ӧ�����������Ƴ����ɡ�
ע��leetcode ���ĺ���ԭ���У�columnSizes ��������������洢ÿ�����ֵĸ����ģ������������صġ�
*/