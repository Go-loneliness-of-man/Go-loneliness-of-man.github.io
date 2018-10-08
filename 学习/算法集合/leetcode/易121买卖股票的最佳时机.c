#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

int maxProfit(int *prices, int pricesSize)
{
	int max, maxc, i, j;
	for (i = maxc = 0; i < pricesSize; i++)
	{
		for (j = i, max = prices[i]; j < pricesSize; j++)	//找出该元素后的最大元素
			if (prices[j] > max)		max = prices[j];
		if (max != prices[i])								//判断是否找到
			if (maxc < (max - prices[i]))					//判断是否大于当前值
				maxc = max - prices[i];
	}
	return maxc;
}

int main()
{
	int x[100] = { 7,1,5,3,6,4 }, len = 6, max;
	max = maxProfit(x, len);
	printf("%d", max);
	return 0;
}

/*
思路：
求出每一天的最大差价，最后比较返回最大的一个。
求最大差价：找出该元素后最大的元素，求差值，更新。
*/