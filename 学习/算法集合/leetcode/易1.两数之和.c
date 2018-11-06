#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
//暂时有两种解法，暴力法、二分法，暴力法适用于数据较少的情况，二分法适用于数据非常多的情况

/*
int* twoSum(int* nums, int numsSize, int target)
{
	int i, j, *b = (int*)malloc(sizeof(int) * 2);
	for (i = 0; (i < numsSize - 1); i++)
		for (j = i + 1; j < numsSize; j++)
			if (nums[i] + nums[j] == target)
			{
				b[0] = i;
				b[1] = j;
				return b;
			}
}
int main()
{
	int nums[4] = { 0,4,3,0 }, target = 0, *a;
	a = twoSum(nums, 4, target);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
思路：暴力法
对所有组合进行判断，具体方法是，从第一个元素开始，分别与其后元素相加，判断是否与目标相等，若有则存储下标跳出。否则从第二个元素开始继续上
述过程，直到找到为止。
*/

//二分法：
#define PD(x,y,z) ((nums[x]+nums[y])==z)

int *twoSum(int *nums, int numsSize, int target)
{
	int *b = (int*)malloc(sizeof(int) * 2), *c = (int*)malloc(sizeof(int)*numsSize);b[0] = b[1] = 100000;
	//用来返回结果的动态数组 b、存储数组原顺序的动态数组 c
	int i, j, min, temp, l, r, mid;
	//循环变量 i 和 j、排序 min、临时变量 temp、二分区间左、中、右端点 l 和 mid 和 r
	for (i = 0; i < numsSize; i++)		c[i] = nums[i];			//复制 nums 到 c
	for (i = 0; i < numsSize; i++)								//从小到大排序
	{
		for (j = min = i; j < numsSize; j++)
			if (nums[min] > nums[j])	min = j;
		if (min == i)		continue;
		temp = nums[i];
		nums[i] = nums[min];
		nums[min] = temp;
	}
	for (i = 0; i < numsSize; i++)								//依次对数组元素进行二分查找
	{
		b[0] = nums[i];		r = numsSize - 1;
		if (PD(i, r, target)) { b[1] = nums[r]; break; }		//判断右端点
		for (l = i, mid = (l + r) / 2; mid != l; mid = (l + r) / 2)				//对 nums[i] 进行一次二分查找。
		{
			if (PD(i, mid, target) && mid != l) { b[1] = nums[mid]; break; }	//判断中点
			if (nums[i] + nums[mid] > target)	r = mid;		//和大于目标，更新右端点
			else	l = mid;									//和小于目标，更新左端点
		}
		if (b[0] + b[1] == target)	break;						//判断是否已查找到，是则跳出
	}
	for (i = 0; i < numsSize; i++)								//确定在原顺序下，两数的下标
		if (b[0] == c[i]) { b[0] = i; break; }
	for (i = 0; i < numsSize; i++)
		if (b[1] == c[i] && i != b[0]) { b[1] = i; break; }
	free(c);
	return b;
}

int main()
{
	int nums[4] = { -10, -1, -18, -19 }, target = -19, *a;
	a = twoSum(nums, 4, target);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
思路：二分法查找
先从小到大排序，然后遍历一遍数组。遍历时对每一个元素进行二分查找，检查数组中是否有满足题意的另一数字。
二分查找：初始区间以该元素下标为左端点，数组末尾为右端点。每次判断区间中点，若满足题意则结束，若不满足。比较二者之和与要求数字的大小，若
大于则取右边区间进行下一次循环，否则取左边区间进行循环。
*/