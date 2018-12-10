#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: [1,2,3,4,5,6,7] �� k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
ʾ�� 2:

����: [-1,-100,3,99] �� k = 2
���: [3,99,-1,-100]
����:
������ת 1 ��: [99,-1,-100,3]
������ת 2 ��: [3,99,-1,-100]
˵��:

�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
Ҫ��ʹ�ÿռ临�Ӷ�Ϊ O(1) ��ԭ���㷨��
*/

void rotate(int* nums, int numsSize, int k)
{
	if (nums == NULL)   return;
	int l, r, temp;
	if (k > numsSize)	k %= numsSize;
	for (l = 0, r = numsSize - k - 1; l < r; r--, l++)
	{
		temp = nums[l];
		nums[l] = nums[r];
		nums[r] = temp;
	}
	for (l = numsSize - k, r = numsSize - 1; l < r; r--, l++)
	{
		temp = nums[l];
		nums[l] = nums[r];
		nums[r] = temp;
	}
	for (l = 0, r = numsSize - 1; l < r; r--, l++)
	{
		temp = nums[l];
		nums[l] = nums[r];
		nums[r] = temp;
	}
}

int main()
{
	int a[20] = { 1,2,3,4,5,6,7,8,9,0 }, i, len = 10;
	rotate(a, len, 13);
	for (i = 0; i < len; i++)	printf("  %d",a[i]);
	return 0;
}
/*
˼·��
�������Ϊ��ߡ��ұ������֣�����ǲ��Ƴ��߽�Ĳ��֣��ұ��ǻ��Ƴ��߽�Ĳ��֣�����ߡ��ұߡ����嶼�ֱ�����һ�Σ����ɴﵽЧ����
*/