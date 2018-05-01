#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*小游戏，猜数字:生成一个随机数来猜，根据用户输入的数值，返回"太大了","太小了","接近了，再猜大些","接近了，再猜小些","大了一点点",
"小了一点点"最后根据用户猜的次数,说出结束语。*/
void pdnum(int x), end(int x);		int pdguess(int x, int y);
//根据生成随机数的大小，给用户对于随机数的描述 ; 根据用户输入的数值，返回提示 ; 根据用户猜的次数，返回结束语。
int num, guess, i, i2, end1 = 0, yes = 0;
//定义储存随机数的变量 num、存储用户输入数字的变量 guess、循环变量 i 和 i2、循环"猜、判断、提示"过程的结束变量 end1、计算猜对次数的变量 yes。
char c;												//用来判断是否开始下一次游戏的变量 c，存储一个 '\n'
int main()
{
	printf("\n     欢迎来到小游戏\"你猜\"，现在给出对一个数字的描述，你将有十次机会猜中它，加油  看好你的！\n");
	for (i2 = 0; (c == '\n') || i2 == 0; i2++)
	{
		printf(" 你已经连续玩 %d 次，共猜对 %d 次，加油!\n", i2, yes);
		srand((unsigned int)time(NULL));			//设置随机数种子
		num = rand() % 100;							//生成并存储随机数
		pdnum(num);									//判断，给出对于随机数的描述
		for (i = 0; (end1 == 0) && (i < 10); i++)	//循环"猜、判断、提示"这个过程，直到猜对或循环次数大于 10
		{
			printf(" 请输入你猜的数字吧: ");
			scanf_s("%d", &guess);					//接收用户输入的值
			end1 = pdguess(num, guess);				//对用户输入的值进行判断、提示
			if (i > 3 && i < 9 && end1 == 0)		//在第 6 次到第 10 次( 没猜对的情况下 )猜时提示次数
				printf(" 注意哦 , 这已经是第 %d 次猜了！ ", i + 2);
		}
		end(i);										//根据用户猜的次数，返回结束语。
	}
	return 0;
}
void pdnum(int x)									//pdnum() 函数,根据生成的随机数，给用户对于随机数的描述
{
	int y = 0;										//变量 y，记录随机数因数的个数
	for (i = 1; i <= x; i++)
	{
		if ((x%i == 0))
			y++;
	}												//计算随机数因数的个数
	printf("\n 这个数字属于 0 ~ 99 ， 共有 %d 个因数 , ", y);
	if (x % 3 == 0)
		printf(" 并且是 3 的倍数\n");
	else if (x % 5 == 0)
		printf(" 并且是 5 的倍数\n");
	else if (x % 7 == 0)
		printf(" 并且是 7 的倍数\n");
	else
		printf(" 并且不是 3、5、7 的倍数\n");			//输出因数提示
}
int pdguess(int x, int y)							//pdguess() 函数，根据用户输入的数值，返回提示
{
	if (y >= 100)
	{
		printf(" 请输入 0 ~ 99 范围内的数字\n\n");
		return 0;
	}
	else if ((x - y) >= 35)
	{
		printf(" 太小了！\n\n");
		return 0;
	}
	else if ((x - y) >= 10 && (x - y) < 35)
	{
		printf(" 接近了，再猜大些 ^_^\n\n");
		return 0;
	}
	else if ((x - y) < 10 && (x - y) > 0)
	{
		printf(" 小了一点点哦~~\n\n");
		return 0;
	}
	else if ((y - x) >= 35)
	{
		printf(" 太大了！\n\n");
		return 0;
	}
	else if ((y - x) >= 10 && (y - x) < 35)
	{
		printf(" 接近了，再猜小些 ^_^\n\n");
		return 0;
	}
	else if ((y - x) < 10 && (y - x) > 0)
	{
		printf(" 大了一点点哦~~\n\n");
		return 0;
	}
	else if ((x == y))								//输出猜对后的部分回答
	{
		printf(" 哦耶，猜对了！");
		yes++;										//记一次猜对的次数
		return 1;									//把 1 赋给 end1，结束游戏。
	}
}
void end(int x)										//end() 函数，根据用户猜对所用的次数返回结束语
{
	switch (x)
	{
	case 1:
		printf(" 哇！你太厉害了，一次就中！\n\n ");
		break;
	case 2:
		printf(" 不错哦,两次就猜对了！\n\n ");
		break;
	case 3:
		printf(" 不错哦,三次就猜对了！\n\n ");
		break;
	case 4:
		printf(" 可以的，猜的挺快的，加油！\n\n ");
		break;
	case 5:
		printf(" 可以的，猜的挺快的，加油！\n\n ");
		break;
	case 6:
		printf(" 猜的有点慢哦~~\n\n ");
		break;
	case 7:
		printf(" 猜的有点慢哦~~\n\n ");
		break;
	case 8:
		printf(" 我可以说，你猜的很慢么...\n\n ");
		break;
	case 9:
		printf(" 我可以说，你猜的很慢么...\n\n ");
		break;
	}
	if (num == guess && x == 10)
		printf(" 平时可得多动动脑子了，要不然是会生锈的。\n\n ");
	else if (x == 10)
		printf(" Game over! 正确数字是 %d ,你猜的太慢了~\n\n ", num);
	printf("若要继续游戏，请按一下回车键，若要关闭游戏，点击右上角红叉。\n");
	c = getchar();										//读取用户操作
	end1 = 0;											//初始化 end1 的值
	getchar();											//确定开始下一次游戏
}