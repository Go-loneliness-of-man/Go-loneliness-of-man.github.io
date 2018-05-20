#include <stdio.h>
//对结构体数组排序
struct xinxi { long long bh; char name[21]; char xb[3]; char addr[51]; };
struct xinxi bg[3] = {
	{ 201707020129,"小明","男", "陕西省 西安市 鄂邑" },
	{ 201707020106 ,"小王" ,"男","陕西省 榆林市 神木县" },
	{ 201707020103 ,"小美" ,"女","北京市 朝阳区" }
};
void order();												//声明排序函数 order()
int i, i2;													//循环变量i，i2
int main()
{
	printf("根据学号排序，请依次输入学号，用空格分隔: ");
	for (i = 0; i < 3; i++) { scanf_s("%lld", &bg[i].bh); };//获取学号
	order();												//排序
	for (i = 0, i2 = 0; i < 3; i++, i2++)
	{
		printf("\n 学号: %lld\t 姓名: %s\t 性别: %s\t 居住地: %s\n ", bg[i].bh, bg[i].name, bg[i].xb, bg[i].addr);
	}
	return 0;
}

void order()												//定义排序函数 order()
{
	struct xinxi ls;										//用于临时存储的结构体变量 ls
	for (i = 0; i < 2; i++)									//共遍历 2 次
	{
		for (i2 = 0; i2 < 2 - i; i2++)						//每次遍历交换 2 - i 次
		{
			if (bg[i2].bh > bg[i2 + 1].bh)					//比较学号的大小
			{
				ls = bg[i2 + 1];							//存储 bg[i+1] 的所有值到 ls 上
				bg[i2 + 1] = bg[i2];						//将 bg[i] 的值转到 bg[i+1] 上
				bg[i2] = ls;								//将 bg[i+1] 的值转到 bg[i] 上
			}												//完成一次交换
		}
	}
}
//要注意比较的是学号，但交换的是整个结构体变量。/t 表示制表符，相当于 8 个空格