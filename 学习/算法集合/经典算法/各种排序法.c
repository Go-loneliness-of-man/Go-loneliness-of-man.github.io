#include<stdio.h>
//冒泡排序法
/*
int nums[10], i, i2, x, len;								//定义存储数字的数组 nums[]、循环变量 i和i2、临时变量x
int main()
{
	printf("\n 请输入一列数字，每个数字前加个空格（包括第一个）: ");
	for (len = 0; getchar() != '\n'; len++)	scanf_s("%d", &nums[len]);		//将数字读入数组
	printf(" 数列长度： %d\n ", len);
	for (i = 0; i < len - 1; i++)
	{
		for (i2 = 0; i2 < len - 1 - i; i2++)				//注意，一共交换 len-1-i 次,因为需要交换的次数随着遍历次数的增加而减少了
		{
			if (nums[i2] > nums[i2 + 1])
			{
				x = nums[i2 + 1];
				nums[i2 + 1] = nums[i2];
				nums[i2] = x;
			}												//比较相邻的两个数组元素，若前者大于后者，交换位置
		}													//遍历数组一次，将一个最大值交换到数组的末尾
	}														//遍历数组九次，将所有数组元素交换排序
	printf("排序后的数列： ");
	for (i = 0; i < len; i++)	printf("%d <= ", nums[i]);	//依次打印数组元素
	printf("\n ");
}
/*
思路:
读入、打印就不说了。
核心思想是，比较两个数组元素，若前者大于后者，则交换位置，用 if 实现;
将 if 放入一个 for 中遍历 nums[] 一次，将此次遍历找到的数组最大者交换到数组的末尾;
将以上步骤（遍历 nums[] 一次将数组中最大者交换到末尾）再放入一个 for 中，循环九次，就可以将所有的数组元素交换排序
一句话总结:逐个、依次交换排序
PS:if 的条件表达式决定了排列的方向，若是 > 从小到大，反之从大到小
*/


//选择排序法
int  main()
{
	int nums[100], i, j, len, min, temp;	//数列、循环变量 i, j、字符串长度 len、储存最小数字数组下标的 min
	printf("\n 请输入一列数字，每个数字前加个空格（包括第一个）: ");
	for (len = 0; getchar() != '\n'; len++)	scanf_s("%d", &nums[len]);
	printf(" 数列长度： %d\n ", len);
	for (i = 0; i < len - 1; i++)			//一共遍历数组 len-1 次
	{
		for (j = min = i; j < len; j++)		//初始化 min、j 的值，遍历找出数组剩余部分的最小数
			if (nums[min] >= nums[j])		//判断 nums[min] 是否大于等于 nums[j]
				min = j;					//更新下标
		if (min == i)	continue;			//未找到，不进行交换，跳过
		temp = nums[i];
		nums[i] = nums[min];
		nums[min] = temp;					//交换位置
	}
	printf("排序后数列: ");
	for (i = 0; i < len; i++)				//输出数组
		printf("%d <=", nums[i]);
	printf("\n ");
	return 0;
}
/*
思路:
一句话总结:从第一个数组元素开始，找出数组中的最小数字与它交换，若没有，则不进行操作。接着对下一个数组元素如法炮制，直到倒数第二个数组元素。
*/