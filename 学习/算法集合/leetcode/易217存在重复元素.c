#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/

bool containsDuplicate(int *nums, int numsSize)
{
	int i, j;
	//if (numsSize < 2 || numsSize > 30000)	return false;	//取巧做法
	if (numsSize < 2)	return false;
	for (i = 0; i < numsSize - 1; i++)					//循环查找是否有重复
		for (j = i + 1; j < numsSize; j++)				//检查当前元素是否有重复
			if (nums[i] == nums[j])	return true;		//重复，true
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
思路：
直接看每个元素后是否有相同元素即可，只是这样做时间是 1700 ms 左右，原因是 leetcode 最后一个样例有 5 万多个数字很费时间，可以取巧的
做法是判断 numsSize 是否大于 3 万，若是则直接返回 false 这样就不用判断最后那个样例了，这样做时间是 62 ms 超过百分之七十的人
*/