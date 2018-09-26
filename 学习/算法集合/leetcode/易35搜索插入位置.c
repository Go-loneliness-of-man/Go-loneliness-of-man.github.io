#include<stdio.h>
/*
原题：
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/

int searchInsert(int* nums, int numsSize, int target)
{
	int i;
	for (i = 0; nums[i] < target && i < numsSize; i++);			//找出数组中第一个大于或等于 target 值的下标
	return i;													//返回下标
}

int main()
{
	int a[5] = { 1,3,5,6 }, target = 7;
	printf("%d", searchInsert(a, 4, target));
	return 0;
}

/*
思路：
这是道异常简单的题，题目中描述的两种情况可以合并为一种，当 nums[i] 大于或等于 target 时，返回其下标即可。
*/