#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

ʾ�� 1:

����: [1,2,3]
���: [1,2,4]
����: ���������ʾ���� 123��
ʾ�� 2:

����: [4,3,2,1]
���: [4,3,2,2]
����: ���������ʾ���� 4321��
*/

int *jin(int *x)									//�ݹ��λ
{
	*(x--) = 0;										//���õ�ǰλ���ƶ���ǰһλ
	if (*x < 9)										//��λС�� 9
		(*x) += 1;									//�� 1
	else
		return jin(x);
	return x;
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int *x = NULL, bj, i;							//������ x����� bj��ѭ������ i
	for (i = 0, bj = 1; bj && i < digitsSize; i++)	//�ж��Ƿ�����λΪ 9
		if (digits[i] != 9)		bj = 0;
	if (bj)											//����λ��Ϊ 9 �����
	{
		*returnSize = digitsSize + 1;				//λ���� 1
		x = (int*)malloc(sizeof(int) * (*returnSize));
		for (x[0] = 1, i = 1; i < *returnSize; i++)	//��һλΪ 1������λΪ 0
			x[i] = 0;
	}
	else											//��������λ��Ϊ 9
	{
		*returnSize = digitsSize;					//λ������
		x = (int*)malloc(sizeof(int) * (*returnSize));
		if (digits[digitsSize - 1] < 9)				//���һλС�� 9
			digits[digitsSize - 1] += 1;			//��һ
		else	jin(&digits[digitsSize - 1]);		//���һλ���� 9�����еݹ��λ
		for (i = 0; i < digitsSize; i++)			//����
			x[i] = digits[i];
	}
	return x;										//��������
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
˼·��
�Գ�ʼ�������һλ��һ��������һλ�� 9�������ø�λΪ 0��ǰһλ��һ���Դ����ơ�
��λ���ɲ��õݹ飬����ǰλС�� 9�����һ���ɣ������� 9 ��ݹ顣
ע�⣺��������һλҲ���˵������������λ��Ϊ 9 ��������������������һλ������Ϊ 0����һλ��Ϊ 1��
*/