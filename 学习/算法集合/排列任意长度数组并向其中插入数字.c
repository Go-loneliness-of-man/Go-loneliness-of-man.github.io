#include<stdio.h>
int num[100], i, i4, length, pd = 1;
//存储数组 num[]、循环变量 i 和循环打印变量i4、数组长度 length、判断是否插入数字的变量 pd
void order(int *num,int length), pd1(int x);					//排序函数、询问是否插入数字的函数
int main()
{
	printf("\n 请输入一列任意长度的数列，每个数字前加一个空格(包括第一个):\n");
	for (i = 0; (getchar() != '\n'); i++) { scanf_s("%d", &num[i]); }
	//获取数组,当读到回车时停止读取
	length = i;													//保存数组第一次输入的长度
	for (i = 0; 1; i++)											//死循环，直到跳出。实现循环询问是否向数组插入数字
	{
		pd1(i);													//询问用户是否向数组插入数字
		if (pd == 0)											//根据用户的选择，确定是否跳出
			break;
		printf("\n 数列长度: %d\n", length);						//输出数组长度
		order(num,length);										//将数组排序
		for (i4 = 0; i4 < length ; i4++) { printf("%d <= ", num[i4]); }//打印排序后的数组
	}
	return 0;
}

void order(int *num,int length)									//排序函数 order()
{
	int count, i2, i3;
	//临时存储变量 count ，以便于数组元素交换数值、循环遍历数组的变量 i2、遍历数组的变量 i3
	for (i2 = 0; i2 < length - 1; i2++)							//共遍历数组 length - 1 次
	{
		for (i3 = 0; i3 < length - 1 - i2; i3++)				//本次遍历共交换 length - 1 - i2 次
		{
			if (num[i3] > num[i3 + 1])
			{
				count = num[i3 + 1];
				num[i3 + 1] = num[i3];
				num[i3] = count;
			}													//一次比较、交换
		}														//遍历数组一次，将一个最大值交换到后方
	}															//循环遍历数组，将所有数组元素进行排序
	printf(" 排序后数列: ");
}

void pd1(int x)													// pd1() 函数，作用是询问用户是否向数组插入数字
{
	if (x > 0)
	{
		printf("\n 若要向数列插入一个数字请输入 1，若要结束程序请输入 0: ");
		scanf_s("%d", &pd);
		if (pd == 1)
		{
			printf(" 请输入插入数列的一个数字: ");
			scanf_s("%d", &num[length]);
			length += 1;										//更新数组长度
		}
	}
}