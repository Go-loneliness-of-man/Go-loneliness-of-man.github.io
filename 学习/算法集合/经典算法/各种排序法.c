#include<stdio.h>
#include<stdlib.h>
//各种排序法

/*
//冒泡排序法
void bst(int *nums, int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)			//交换
	{
		for (j = 0; j < len - 1 - i; j++)	//遍历一次，将一个最大值交换到末尾。注意，共验证 len-1-i 个数，因为需要验证的数字个数会随着遍历次数的增加而减少
			if (nums[j] > nums[j + 1])		//进行一次比较，若前者大于后者则交换
			{
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}								//比较相邻的两个数组元素，若前者大于后者，交换位置
	}										//遍历数组九次，将所有数组元素交换排序
}

int  main()
{
	int nums[100] = { 9,4,8,6,7,5,3,1,2 }, len = 9;				//数列、数列长度 len
	bst(nums, len);
	printf("排序： ");
	for (int i = 0; i < len; i++)	printf("%4d", nums[i]);		//输出数组
	printf("\n");
	return 0;
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

/*
//选择排序法
void sst(int *nums, int len)
{
	int i, j, temp, min;					//循环变量 i 和 j、临时变量 temp、储存最小数字数组下标的 min
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
}

int  main()
{
	int nums[100] = { 9,4,8,6,7,5,3,1,2 }, len = 9;				//数列、数列长度 len
	sst(nums, len);
	printf("排序： ");
	for (int i = 0; i < len; i++)	printf("%4d", nums[i]);		//输出数组
	printf("\n");
	return 0;
}
/*
思路:
一句话总结:从第一个数组元素开始，找出数组中的最小数字与它交换，若没有，则不进行操作。接着对下一个数组元素如法炮制，直到倒数第二个数组元素。
*/


//快排（Quicksort）：最快的内排序，不稳定，存在多个相同的值时，其相对位置在排序后可能会有变动，复杂度：O（nlogn） ~ O（n^2）。
void qst(int *nums, int l, int r)
{
	if (l >= r)		return;							//长度小于 1，排序完毕
	int left = l, right = r, key = nums[left];		//保存 l、r 的初值，确定基准点 key
	for (; l < r;)									//一次遍历
	{
		for (; nums[r] >= key && l < r; r--);		//向左寻找小于 key 的数
		if (nums[r] < key)	nums[l] = nums[r];		//若找到，赋值给 l
		for (; nums[l] <= key && l < r; l++);		//向右寻找大于 key 的数
		if (nums[l] > key)	nums[r] = nums[l];		//若找到，赋值给 r
	}
	nums[l] = key;									//将 key 插入到分割点
	qst(nums, left, l - 1);							//递归左边
	qst(nums, l + 1, right);						//递归右边
}

int main()
{
	int nums[100] = { 3,2,0,3,1 }, len = 5;
	qst(nums, 0, len - 1);
	printf("排序： ");
	for (int i = 0; i < len; i++)	printf("%4d", nums[i]);
	printf("\n");
	return 0;
}
/*
思路：
基本思想：
一次遍历将数据分割为两部分，一部分数据都比另一部分数据小，再对这两部分重复分割，直到整个数据变为有序序列。

一次遍历：
任取数组的一个数据（一般选第一个数组元素，但最好是随机选取，可以降低遇到最坏情况的概率）作为基准点 key，所有小于 key 的数都放到它的一
边，所有大于 key 的数都放到它的另一边，这个过程被称为一趟快速排序。

具体的交换过程是，假设从小到大排序，数组两端为 left、right。首先 right 向左寻找第一个小于 key 的数并赋值给 left，然后 left 向右
寻找第一个大于 key 的数并赋值给 right，重复该过程直到 left == right，然后将 key 赋值给 left，一次分割便完成了。

非递归实现：
使用递归实现快排比较方便，非递归实现需要用栈存储中间状态，其代码实现比递归代码要更难理解，效率也更低。非递归只适用于数据量过大，导致递归
次数过多，进而导致栈溢出的情况（其实递归的本质也是栈，非递归只是模拟递归）。非递归大致步骤如下：

1. 对原数组进行一次划分，将两部分都入栈。
2. 判断栈是否为空，空则结束，非空将栈顶取出，进行一次遍历。
3. 判断一部分的长度是否大于 1，若是则将其入栈，否则不入栈，另一部分同理。
4. 循环步骤 2、3。

实际上就是用栈保存每一个待排序子串的首尾元素下标，下一次遍历时取出这个范围，对这段子序列进行分割。
*/