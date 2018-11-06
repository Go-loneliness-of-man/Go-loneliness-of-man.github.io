#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

#define PD(x,y,z) ((numbers[x]+numbers[y])==z)

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
	int *b = (int*)malloc(sizeof(int) * 2);b[0] = b[1] = 10000;	//用来返回结果的动态数组 b
	int i, l, r, mid;	*returnSize = 2;
	//循环变量 i 和 j、排序 min、临时变量 temp、二分区间左、中、右端点 l 和 mid 和 r
	for (i = 0; numbers[i] + numbers[numbersSize - 1] < target; i++);		//跳过前段较小的部分
	if (i != 0)	i--;											//若进行过跳跃，i--
	for (; i < numbersSize; i++)								//依次对数组元素进行二分查找
	{
		b[0] = i + 1;		r = numbersSize - 1;
		if (PD(i, r, target)) { b[1] = r + 1; break; }			//判断右端点
		for (l = i, mid = (l + r) / 2; mid != l; mid = (l + r) / 2)			//对 numbers[i] 进行一次二分查找。
		{
			if (PD(i, mid, target) && mid != l) { b[1] = mid + 1; break; }	//判断中点
			if (numbers[i] + numbers[mid] > target)	r = mid;	//和大于目标，更新右端点
			else	l = mid;									//和小于目标，更新左端点
		}
		if (PD(b[0] - 1, b[1] - 1, target))		break;			//判断是否已查找到，是则跳出
	}
	return b;
}

int main()
{
	int nums[4] = { 2, 3, 4 }, target = 6, *a, *b = (int*)malloc(sizeof(int));
	a = twoSum(nums, 3, target, b);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
思路：既然都已经是有序数组了，那很明显可以使用二分法来查找。
查找前，先跳过数组前段过于小的部分，然后对每一个元素进行二分查找，检查数组中是否有满足题意的另一数字。
二分查找：初始区间以该元素下标为左端点，数组末尾为右端点。每次判断区间中点，若满足题意则结束，若不满足。比较二者之和与要求数字的大小，若
大于则取右边区间进行下一次循环，否则取左边区间进行循环。
*/