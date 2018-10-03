#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]
*/

void merge(int *nums1, int m, int *nums2, int n)
{
	int i, j, min, temp;
	for (i = m, j = 0; j < n; nums1[i++] = nums2[j++]);			//�� nums2 ������ nums1 ��
	for (i = 0; i < m + n; i++)									//����
	{
		for (j = min = i; j < m + n; j++)
			if (nums1[min] > nums1[j])		min = j;
		if (min == i)		continue;
		temp = nums1[i];
		nums1[i] = nums1[min];
		nums1[min] = temp;
	}
}

int main()
{
	int m = 3, n = 3, nums1[100] = { 1, 2, 3, 0, 0, 0 }, nums2[100] = { 2, 5, 6 };
	merge(nums1, m, nums2, n);
	for (int i = 0; i < m + n; i++)
		printf("%d", nums1[i]);
	return 0;
}

/*
˼·��
�ܼ򵥣��� nums2 ������ nums1 ��Ȼ������ nums1 ���ɡ�
*/