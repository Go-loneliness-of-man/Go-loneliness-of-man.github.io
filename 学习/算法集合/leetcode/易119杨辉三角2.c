#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�

ʾ��:

����: 3
���: [1,3,3,1]
���ף�

������Ż�����㷨�� O(k) �ռ临�Ӷ���
*/

int *getRow(int rowIndex, int *returnSize)
{
	int *x = (int*)malloc(sizeof(int)*rowIndex + 1), *y = (int*)malloc(sizeof(int)*rowIndex + 1), i, j;
	for (i = 0; i < rowIndex + 1; i++)						//ѭ���Ƴ��� rowIndex ��
	{
		y[0] = y[i] = 1;									//��ֵ��һ�������һ��Ϊ 1
		for (j = 1; j < i; j++)	y[j] = x[j - 1] + x[j];		//�Ƶ�����
		for (j = 0; j <= i; x[j] = y[j], j++);				//���汾�� y �Ա��Ƶ���һ��
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
˼·��
�ܼ򵥣�ֻҪָ���У�����������ѭ���Ƶ����ɡ�
*/