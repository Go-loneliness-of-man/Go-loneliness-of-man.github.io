#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��

ʾ�� 1:

����: [1,2,3,1]
���: true
ʾ�� 2:

����: [1,2,3,4]
���: false
ʾ�� 3:

����: [1,1,1,3,3,4,3,2,4,2]
���: true
*/

bool containsDuplicate(int *nums, int numsSize)
{
	int i, j;
	//if (numsSize < 2 || numsSize > 30000)	return false;	//ȡ������
	if (numsSize < 2)	return false;
	for (i = 0; i < numsSize - 1; i++)					//ѭ�������Ƿ����ظ�
		for (j = i + 1; j < numsSize; j++)				//��鵱ǰԪ���Ƿ����ظ�
			if (nums[i] == nums[j])	return true;		//�ظ���true
	return false;
}

int main()
{
	int nums[100] = { 1,2,3,123456789 }, numsSize;
	for (numsSize = 0; nums[numsSize] != 123456789; numsSize++);
	printf("%d", containsDuplicate(nums, numsSize));
	return 0;
}

/*
˼·��
ֱ�ӿ�ÿ��Ԫ�غ��Ƿ�����ͬԪ�ؼ��ɣ�ֻ��������ʱ���� 1700 ms ���ң�ԭ���� leetcode ���һ�������� 5 �������ֺܷ�ʱ�䣬����ȡ�ɵ�
�������ж� numsSize �Ƿ���� 3 ��������ֱ�ӷ��� false �����Ͳ����ж�����Ǹ������ˣ�������ʱ���� 62 ms �����ٷ�֮��ʮ����
*/