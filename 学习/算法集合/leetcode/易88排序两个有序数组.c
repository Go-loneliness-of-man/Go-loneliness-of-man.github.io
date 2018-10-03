#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

void merge(int *nums1, int m, int *nums2, int n)
{
	int i, j, min, temp;
	for (i = m, j = 0; j < n; nums1[i++] = nums2[j++]);			//将 nums2 拷贝到 nums1 后
	for (i = 0; i < m + n; i++)									//排序
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
思路：
很简单，将 nums2 拷贝到 nums1 后，然后排序 nums1 即可。
*/