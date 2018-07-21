#include<stdio.h>
#include<time.h>
/*
**计算计算机时间的终点
     昨天想着时间戳的时候突然有了这个想法，便开始写个程序用来实现，到今天晚上才写好，花了近两天时间，这是源代码。
     计算机时间是用“时间戳”这个概念标识的，它是指从 1970 年 1 月 1 日 00 : 00 : 00 （格林尼治时间）起，到目前为止经过的秒数（只考
  虑平年），它以整型的形式存储在计算机中，因此便有了极限值，即所谓的计算机时间的终点。C 语言中专门为时间戳定义了一种类型，称为时间类型，
  定义在 time.h 头文件中，不同操作系统定义可能不同，因此不同操作系统所得到的结果可能不同。现在大多数电脑随着硬件更新换代，其上的操作系
  统的时间类型已经是 8 字节，这样的存储长度可以说永远不必担心时间终点，然而有一部分比较老的电脑时间类型仍然是 4 个字节，这样时间终点就不
  那么遥远了，下面来计算 4 个字节的时间终点。
     我计算的总体思路是，先将 int 类型（4 字节）的极限值转换为年、月、日、时、分、秒的形式，然后直接加在格林尼治时间上就得到了终点值。
*/

//****************************************** 需要事先包含的自定义库函数 *******************************************

int sc(char *x)										//计算字符串长度，不包括 '\0'
{
	int i;
	for (i = 0; x[i] != '\0'; i++);
	return i;
}

void scp(char *x, char *y, int size)				//字符串复制函数，将 y 复制到 x 中，size 是最大长度
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

char *czs(long long x)								//数值数字转字符数字
{
	static char sc[21];								//声明字符数字，由于主函数要引用其地址，所以定义为静态
	//开始取出每位上的数字
	long long pst[20], i, bit;						//数组 pst[] 存储每位的数字、i 控制位置、bit 是 x 的位数
	for (i = 0; i < 20; pst[i] = 0, i++);			//初始化 pst[] 内所有元素的值为 0
	i = 0;											//重置 i = 0
	for (long long j = 1; i < 20; i++, j *= 10)		//循环，取出所有位上对应的数字
		pst[i] = ((unsigned int)x / j) % 10;		//利用取余取出数字
	//取出每位数字结束
	for (i = 19, bit = 20; pst[i] == 0; i--, bit--);//判断数值数字的位数
	if (bit == 0) bit = 1;							//如果数值数字是 0，将位数确定为 1
	long long *pst2 = pst + bit - 1;				//创建 pst2 指向 pst[]
	for (i = 0; i < bit; i++, pst2--)				//将取出的有效位数值数字转化为字符数字
		sc[i] = *pst2 + 48;							//循环赋值
	sc[i] = '\0';									//添加结束符
	return sc;										//返回字符数字
}

int szc(char *x)									//字符数字转数值数字
{
	long long pst[20], i, bit, result;				//数组 pst[] 存储每位的数字、i 控制位置、bit 是 x 的位数、结果 result
	bit = sc(x);									//计算字符数字位数
	for (i = 0, x += bit - 1; i < bit; i++, x--)	//循环，取出所有位上对应的数字
		pst[i] = *x - 48;							//将字符数字的每一位转化为数值数字并存储
	long long j;									//用于计算的变量 j
	//根据每位上的数字，计算出数值数字的大小
	for (result = i = 0, j = 1; i < bit; j *= 10, i++)
		result += pst[i] * j;
	return result;
}

//字符串拼接，将后者接到前者后，返回第一个字符串的首地址，三个版本，分别对应 2、3、4 个字符串的拼接
char *spj2(char *x, char *y)
{
	int xlen = sc(x), ylen = sc(y);					//分别计算两字符串的长度
	scp(x + xlen, y, ylen + 1);						//将 y 从 x 的 '\0' 处开始复制，即将 y 接到 x 后
	return x;										//返回 x 的地址
}
char *spj3(char *x, char *y, char *z)
{
	int xlen = sc(x), ylen = sc(y),zlen=sc(z);		//分别计算三字符串的长度
	scp(x + xlen, y, ylen + 1);						//将 y 从 x 的 '\0' 处开始复制，即将 y 接到 x 后
	scp(x + xlen + ylen, z, zlen + 1);				//将 z 从 y 的 '\0' 处开始复制
	return x;										//返回 x 的地址
}
char *spj4(char *x, char *y, char *z, char *p)
{
	int xlen = sc(x), ylen = sc(y), zlen = sc(z), plen = sc(p);
	//分别计算四字符串的长度
	scp(x + xlen, y, ylen + 1);						//将 y 从 x 的 '\0' 处开始复制，即将 y 接到 x 后
	scp(x + xlen + ylen, z, zlen + 1);				//将 z 从 y 的 '\0' 处开始复制
	scp(x + xlen + ylen + zlen, p, plen + 1);
	//将 p 从 z 的 '\0' 处开始复制
	return x;										//返回 x 的地址
}

//比较两个以字符串形式存储的数字的大小，若前者大于后者返回 1，小于返回 0，相等返回 2
int scbj(char *x, char *y)
{
	if (sc(x) > sc(y))	return 1;						//前者长度大，返回 1
	else if (sc(x) < sc(y))  return 0;					//后者长度大，返回 0
	else												//二者长度相等，接下来循环比较每一位上数字的大小
	{
		for (; *x != '\0'&&*y != '\0'; x++, y++)		//从左侧第一位开始比较
		{
			if (*x > *y)	return 1;					//该位上，前者数字大，返回 1
			else if (*x < *y)	return 0;				//该位上，后者数字大，返回 0
			else if (*x == *y && *(x + 1) == '\0' && *(y + 1) == '\0')
				return 2;								//所有位上的数字都相等，二者是同一数字，返回 2
		}
		return 0;										//避免编译器报错，只是形式，无用
	}
	return 0;											//避免编译器报错，只是形式，无用
}

//************************************************ 包含结束 **************************************************

char *zh(int y);
//将极限值转换为年、月、日、时、分、秒形式的字符串再加到格林尼治时间上并返回其地址

int main()
{
	int biggest = 0;
	biggest -= 1;									//计算出 int 类型的最大值
	printf("\n  时间类型为 4 个字节的操作系统其存储数字的极限值是： %u\n", biggest);
	printf("\n  现将其加到格林尼治时间后得到结果是：\n\n\t\t  %s\n", zh(biggest));
	printf("\n  这个时间，以硬件升级的速度来说，计算机时间的终点只是个遥不可及的幻想\n\n\n\n\n  "
		   "永远都不可能到达 . . .\n\n\n\n  ");
	return 0;
}

//将极限值转换为年、月、日、时、分、秒形式的字符串再加到格林尼治时间上并返回其地址
char *zh(int y)
{
	int year, mon, d, h, min, s;					//定义各时间变量
	char x[100];	scp(x, czs(y), 100);			//将极限值 y 转换为字符数字 x 以便于比较大小
	/*接下来开始计算年、月、日、时、分、秒。之所以不用取余，是因为我发现当数字很大时取余运算符计算出现了很奇怪的错误，所以只能重新想
	一种计算方法，另外，我还发现当数字很大时关系运算符也失效了，为了解决这个问题我将数值数字转化为字符数字，再重新定义一套方法来比较字
	符数字间的大小*/
	for (year = 0; scbj(x, czs(60 * 60 * 24 * 30 * 12)) != 0; year++, scp(x, czs(y), 100))
		y -= 60 * 60 * 24 * 30 * 12;
	for (mon = 0; scbj(x, czs(60 * 60 * 24 * 30)) != 0; mon++, scp(x, czs(y), 100))
		y -= 60 * 60 * 24 * 30;
	for (d = 0; scbj(x, czs(60 * 60 * 24)) != 0; d++, scp(x, czs(y), 100))
		y -= 60 * 60 * 24;
	for (h = 0; scbj(x, czs(60 * 60)) != 0; h++, scp(x, czs(y), 100))
		y -= 60 * 60;
	for (min = 0; scbj(x, czs(60)) != 0; min++, scp(x, czs(y), 100))
		y -= 60;
	s = y;
	//计算完毕，接下来将其全部转为字符数字
	char year2[100], mon2[100], d2[100], h2[100], min2[100], s2[100];
	scp(year2, czs(year), 100);		scp(mon2, czs(mon), 100);	 scp(d2, czs(d), 100);
	scp(h2, czs(h), 100);		scp(min2, czs(min), 100);		scp(s2, czs(s), 100);
	//转换完毕，开始进行第一次字符串拼接
	static char result[100];
	scp(result, spj3(spj4(year2, " 年 ", mon2, " 月 "), spj4(d2, " 天 ", h2, " 个小时 ")
		, spj4(min2, " 分 ", s2, " 秒 ")), 100);
	printf("\n  将极限值转换为年、月、日、时、分、秒的形式为：\n\n\t\t  %s\n"
		   "\n  格林尼治时间是：  1970 年 1 月 1 日   00 : 00 : 00\n", result);
	//第一次拼接并输出完毕，开始将其加到格林尼治时间上
	year += 1970;	mon += 1;	d += 1;
	scp(year2, czs(year), 100);		scp(mon2, czs(mon), 100);	 scp(d2, czs(d), 100);
	scp(h2, czs(h), 100);		scp(min2, czs(min), 100);		scp(s2, czs(s), 100);
	scp(result, spj3(spj4(year2, " 年 ", mon2, " 月 "), spj4(d2, " 日   0", h2, " ： ")
		, spj3(min2, " ： ", s2)), 100);
	return result;
}