#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i, j, n[100000], len, c, max;				//循环变量 i 和 j、不重复数组 n、长度 len、查重 c、下标最大差值 max
	for (i = len = max = 0; i < numsSize; i++)		//遍历 nums 进行查重并求最大值 max
	{
		for (j = 0, c = 1; j < len; j++)			//查重
			if (n[j] == nums[i])					//重复元素
			{
				if (max < i - j)	max = i - j;	//判断重复元素下标差值是否大于原值，若是则更新 max
				c = 0;								//更新查重变量状态
			}
		if (c)	n[len++] = nums[i];					//若不是重复元素，添加到数组 c
	}
	if (max != k)	return false;					//最大下标差值不等于 k
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
思路：
建立一个对每个数字只存储一次的数组，每次新添加一个元素都遍历数组查重，查到则求差值 max，最后与 k 比较判断返回值
*/