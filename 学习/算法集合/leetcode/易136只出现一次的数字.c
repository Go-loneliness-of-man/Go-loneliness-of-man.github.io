#include<stdio.h>
#include<stdlib.h>
/*
原题：只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/
//两种方法，一种很好想，另一种利用了位运算的特性大大简化了算法。

/*
//第一种，一般方法。
int singleNumber(int *nums, int numsSize)
{
	int i, j, min, temp;
	for (i = 0; i < numsSize - 1; i++)							//选择排序
	{
		for (j = min = i; j < numsSize; j++)
			if (nums[j] < nums[min])	min = j;
		if (i == min)	continue;
		temp = nums[min];
		nums[min] = nums[i];
		nums[i] = temp;
	}
	if (nums[numsSize - 1] != nums[numsSize - 2])				//末尾的情况
		return nums[numsSize - 1];
	for (i = 0; i < numsSize - 1; i += 2)						//判断中间元素是否只出现一次
		if (nums[i] != nums[i + 1])		return nums[i];
	return 0;
}
/*
思路：
很简单，排序，然后因为其它数字均只出现一次，所以判断前后两个元素是否相等即可，即 nums[i] != nums[i+1]。
*/


//第二种，利用了位运算的特性。
int singleNumber(int *nums, int numsSize)
{
	int i, x;
	for (i = x = 0; i < numsSize; i++)	x ^= nums[i];		//初值为 0，遍历一次，全部异或
	return x;
}
/*
思路：
异或运算符的特性：0 ^ N = N ， N ^ N = 0
所以，如果数字 A(n) 在数组 a 中只出现一次，则：
	  A(1) ^ A(2) ^ A(1) ^ A(3) ^ A(2) ...... ^ A(n) ^ A(n+1) ^ A(n+1)
	= (A(1) ^ A(1)) ^ (A(2) ^ A(2)) ...... ^ ( A(n+1) ^ A(n+1) ) ^ A(n)
	= 0 ^ 0 ^ 0 ^ ...... ^ 0 ^ A(n)
	=A(n)
所以遍历一次数组即可找到目标数字，这方法是我后来百度的，真的是骚操作 ......
*/

int main()
{
	int nums[100] = { 4,1,2,1,2 }, numsSize = 5;
	printf("%d", singleNumber(nums, numsSize));
	return 0;
}