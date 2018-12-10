#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。
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
思路：
将数组分为左边、右边两部分，左边是不移出边界的部分，右边是会移出边界的部分，将左边、右边、整体都分别逆置一次，即可达到效果。
*/