#include<stdio.h>
//冒泡排序法

/*
//实现一:	这个写的较为复杂一些，是我自己设计的，比较烂
int max2(int x, int y);										//声明找出两数中较大者的 max2() 函数
int main()
{
	int nums[10], nums2[10], max = 0, maxs, i, i2;
	//依次定义存储数字的数组、依次打印的数组、每次存储最大数的变量、临时保存 max 值的变量、控制循环次数的变量 i 和 i2
	printf("请输入 10 个数字,每输入一个按一次回车键:\n");
	for (i = 0; i < 10; i++) { scanf_s("%d", &nums[i]); }	//将数字读入数组
	for (i = 0; i < 10; i++)
	{
		for (i2 = 0; i2 < 10; i2++)
		{
			if (i == 0)										//特殊情况，第一次遍历 nums[] 时 nums2[0] 还没有被赋值
			{
				max = max2(max, nums[i2]);					//比较 max 与 nums[i] 的大小，将较大者赋值给 max
			}
			else
			{
				maxs = max;									//临时储存 max 的值						
				max = max2(max, nums[i2]);					//比较 max 与 nums[i] 的大小，将较大者赋值给 max
				if (max >= nums2[i - 1])
				{
					max = maxs;								//还原 max 的值
					continue;
				}											//在遍历中跳过上次找到的最大者 nums[i-1]
			}
		}													//遍历数组 nums[] 一次，找出其中小于 上次遍历最大者 的最大者
		nums2[i] = max;										//将本次循环找到的最大者赋值给 nums2[i]
		max = 0;											//清零 max 的值，用来找到下一个最大者
	}
	for (i = 0; i < 10; i++) { printf("%d > ", nums2[i]); }	//打印排序后的数组
	printf("\n");
	return 0;
}
int max2(int x, int y)										//定义 max2() 函数
{
	if (x > y)
		return x;
	else
		return y;
}

/*
花了五个小时，改了无数次Bug终于搞定了,以下是思路
思路:
首先,将所有数字读入数组 nums[];	（11、12行）
定义函数 max2() 找出两数中的较大者，即存储每次遍历最大值的变量 max 和 被遍历数组的每个数组元素 nums[i]，然后将二者中的较大者重新赋值给max;	（39 ~ 45行，在 19、25 行处被调用）
将 max2() 放入一个 for 循环中，使其遍历数组 nums[] 一次，找出其中的最大者赋值给 max;	（15 ~ 31行）
将遍历一次 nums[] 后找出的最大者存储在打印数组 nums2[] 中，每次存储后清零 max 的值;	(32、33行)
将以上步骤（遍历 nums[] 一次找出其中最大者赋给 nums2[]）放入一个 for 循环中，这样只要保证每次遍历 nums[] 后的 max 小于上一次遍历的 max，再依
次存储到nums2[]中，就可以实现从大到小的排列数组 nums[];	（13 ~ 34行）

保证每次遍历 nums[] 后的 max 小于上一次遍历的 max 的方法:
上一次遍历的 max 一定大于这次遍历的 max，反过来说，这次遍历的 max 是一定小于等于上次的 max 的，所以只要在比较二者大小后跳过上次遍历的 max 的
值就可以了。而上次遍历的 max 值被存储在 nums2[i-1]（遍历后 i++ 了一次）中，所以只要 max >= nums2[i-1] ,就跳出一次，直到遍历完 nums[] 即可。
具体可以用 if 和 continue 搭配实现	;	(19~25行)
一句话总结: 将每次遍历的最大值依次打印。

该算法中还有两个小问题:
1. 排序后每个最大值都只打印一次，如果被排序的数组中有重复数字，会导致排序后的数字数量少于排序前的数量。
2. 读入数组时太麻烦，要输一个数字按一下回车，但如果写成用空格分隔的话代码又太长，有没有代码既短，又能一次性读入的方法......
而这两个问题目前我还解决不了......
*/

//实现二:	正宗冒泡排序法,完全看完解析后写的
/*
int nums[10], i, i2, x;										//定义存储数字的数组 nums[]、循环变量 i和i2、临时变量x
int main()
{
	printf("请输入 10 个数字,每输入一个按一次回车键:\n");
	for (i = 0; i < 10; i++) { scanf_s("%d", &nums[i]); }	//将数字读入数组
	for (i = 0; i < 10; i++)
	{
		for (i2 = 0; i2 < 9; i2++)							//注意，一共交换9次
		{
			if (nums[i2] > nums[i2 + 1])
			{
				x = nums[i2 + 1];
				nums[i2 + 1] = nums[i2];
				nums[i2] = x;
			}												//比较相邻的两个数组元素，若前者大于后者，交换位置
		}													//遍历数组一次，将一个最大值交换到数组的末尾
	}														//遍历数组十次，将所有数组元素交换排序
	for (i = 0; i < 10; i++) { printf("%d < ", nums[i]); }	//依次打印数组元素
	printf("\n");
}

/*
思路:
读入、打印就不说了。
核心思想是，比较两个数组元素，若前者大于后者，则交换位置，用 if 实现;	( 80 ~ 85行 )
将 if 放入一个 for 中遍历 nums[] 一次，将此次遍历找到的数组最大者交换到数组的末尾;	( 78 ~ 86行 )
将以上步骤（遍历 nums[] 一次将数组中最大者交换到末尾）再放入一个 for 中，循环十次，就可以将所有的数组元素交换排序	（ 76 ~ 87行 ）
一句话总结:逐个、依次交换排序
*/