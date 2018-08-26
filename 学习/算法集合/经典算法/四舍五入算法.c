#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//四舍五入算法，下面以保留两位小数为例

double sswr(double a);								//对三位小数进行四舍五入

int main()
{
	double a;
	srand((unsigned int)time(NULL));				//利用时间戳作为随机数种子
	for (; 1;)										//产生一个符合要求的三位小数
	{
		a = (((double)(rand() % 100000)) / 1000);	//产生一个随机的三位小数
		if (((a * 1000) > 10000) && (int)(a * 1000) % 10 != 0)
			break;									//起始随机数大于 10000 且个位不为 0，符合要求，跳出
	}
	printf("\n  准备进行四舍五入的随机数： %g", a);
	printf("\n\n  保留两位小数并四舍五入后： %g\n\n  ", sswr(a));
	return 0;
}

double sswr(double a)								//对三位小数进行四舍五入
{
	int temp = (int)(a * 1000 + 5) / 10;			//四舍五入算法，利用加 5 筛选，再用整型除 10 去掉尾部
	return ((double)temp) / 100;
}
//核心思想：先将小数扩大为整数，然后利用加 5 达到四舍五入的效果，再利用整型的特性去掉最后一位小数（也可以很多位）