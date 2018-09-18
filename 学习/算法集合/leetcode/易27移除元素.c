#include<stdio.h>
#include<stdlib.h>
/*
原题：

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++)
{
	print(nums[i]);
}
*/

//两种思路：第一种是排序然后整体移动，第二种是遍历一次，每次遇到便剔除该元素

//第一种：
int removeElement(int* nums, int numsSize, int val)
{
	if (numsSize == 0)		return 0;
	int i, j, min, temp, c;
	for (i = 0; i < numsSize; i++)							//选择排序，从小到大
	{
		for (j = min = i; j < numsSize; j++)
			if (nums[min] > nums[j])	min = j;
		if (min == i)		continue;
		temp = nums[i];
		nums[i] = nums[min];
		nums[min] = temp;
	}
	for (i = 0, j = numsSize - 1; i < numsSize; i++)		//将 val 整体移动到数组末尾
		if (nums[i] == val)
		{
			for (; nums[i] == val && j > i; j--, i++)		//当交换完 val 或 j <= i 时停止
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
			break;											//移动完毕，跳出
		}
	for (i = numsSize - 1; nums[i] == val && i != 0; i--);	//确定不存在 val 的长度
	if(nums[i]!=val)	return i + 1;						//返回长度
	else return 0;
}
/*
思路：
排序，然后找到 val 将其整体移动到数组末尾，再返回去掉其的长度即可。
注意：
*/
/*
//第二种：
int removeElement(int *nums, int numsSize, int val)
{
	if (numsSize == 0)		return 0;
	int i, j;
	for (i = 0; i < numsSize; i++)							//遍历数组
		if (nums[i] == val && i == numsSize - 1)			//遍历到最后一个元素的情况
			return i;
		else if (nums[i] == val)							//当匹配到该值，对其后元素进行整体前移
		{
			for (j = i + 1; j < numsSize; j++)				//整体前移
				nums[j - 1] = nums[j];
			numsSize--;		i--;							//整体前移一位，i 也要相应的前移一位
		}
	return numsSize;
}
/*
思路：
遍历数组，每次匹配到该值，将其后的元素整体向前移一位，当匹配到最后一位，若其等于 val，长度减 1 返回即可。
注意：
*/

int main()
{
	int x[100] = { 0, 1, 2, 2, 3, 0, 4, 2 }, val = 2;
	printf("%d", removeElement(x, 8, val));
	return 0;
}