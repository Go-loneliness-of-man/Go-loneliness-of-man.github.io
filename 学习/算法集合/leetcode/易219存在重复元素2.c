#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums [i] = nums [j]������ i �� j �Ĳ�ľ���ֵ���Ϊ k��

ʾ�� 1:

����: nums = [1,2,3,1], k = 3
���: true

ʾ�� 2:

����: nums = [1,2,3,1,2,3], k = 2
���: false
*/

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i, j, n[100000], len, c, max;				//ѭ������ i �� j�����ظ����� n������ len������ c���±�����ֵ max
	for (i = len = max = 0; i < numsSize; i++)		//���� nums ���в��ز������ֵ max
	{
		for (j = 0, c = 1; j < len; j++)			//����
			if (n[j] == nums[i])					//�ظ�Ԫ��
			{
				if (max < i - j)	max = i - j;	//�ж��ظ�Ԫ���±��ֵ�Ƿ����ԭֵ����������� max
				c = 0;								//���²��ر���״̬
			}
		if (c)	n[len++] = nums[i];					//�������ظ�Ԫ�أ���ӵ����� c
	}
	if (max != k)	return false;					//����±��ֵ������ k
	return true;
}

int main()
{
	int nums[100] = { 1,0,1,1,123456789 }, numsSize, k = 1;
	for (numsSize = 0; nums[numsSize] != 123456789; numsSize++);
	printf("%d", containsNearbyDuplicate(nums, numsSize, k));
	return 0;
}

/*
˼·��
����һ����ÿ������ֻ�洢һ�ε����飬ÿ�������һ��Ԫ�ض�����������أ��鵽�����ֵ max������� k �Ƚ��жϷ���ֵ
*/