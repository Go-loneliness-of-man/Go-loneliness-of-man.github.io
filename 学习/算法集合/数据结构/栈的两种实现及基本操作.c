#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
   栈是种先进后出的数据结构，也有人说栈称不上数据结构，只是种对数据节点的访问方式，我不纠结它到底是什么，只管如何使用它。从存储方式上
看，栈主要有顺序存储（数组）和链式存储（链表）两种方式。下面分别演示栈的实现及其基本操作。
栈的栈顶指针标志着此时栈的高度，当栈为空时栈顶指针为 -1。
栈在很多时候都能用到，举个例子比如程序中函数的执行就是通过栈来实现的，举个简单点的例如回文数的判断也可以通过栈来实现。
基本操作：压栈、出栈、置空、判断栈空。
*/
typedef struct s					//顺序栈
{
	int nums[1000];					//栈中元素
	int top;						//栈顶指针
}s;

typedef struct s2					//链式栈
{
	int num;						//数据域
	int top;						//节点位置
	struct s2 *last;				//指针域
}s2;

//********************************************************************* 顺序栈

void yz(s *x);						//压栈

void cz(s *x);						//出栈

void em(s *x);						//判断空栈，是则返回真

void mem(s *x);						//置空

//********************************************************************* 链式栈

s2 *yz2(s2 *x);						//压栈

s2 *cz2(s2 *x);						//出栈

void em2(s2 *x);					//判断空栈，是则返回真

s2 *mem2(s2 *x);					//置空

//********************************************************************* 主函数

int main()
{
	int f, f2;
	printf("\n  顺序栈请输入任意非 0 数字，链式栈请输入 0： ");
	scanf_s("%d", &f);		getchar();
	system("cls");
	if (f)
	{
		s x;	x.top = -1;			//声明一个顺序栈
		for (f2 = 1; f2;)
		{
			printf("\n  压栈、出栈、判断栈空、置空分别输入 1、2、3、4，结束输入 0： ");
			scanf_s("%d", &f2);
			if (f2)
				switch (f2)
				{
				case 1:
					yz(&x);
					break;
				case 2:
					cz(&x);
					break;
				case 3:
					em(&x);
					break;
				case 4:
					mem(&x);
					break;
				}
			system("cls");
		}
	}
	else
	{
		int pd;
		s2 *top = (s2*)malloc(sizeof(s2));		//创建一个链式栈节点
		top->top = -1;	top->last = NULL;		//初始化
		for (f2 = 1; f2;)
		{
			printf("\n  压栈、出栈、判断栈空、置空分别输入 1、2、3、4，结束输入 0： ");
			scanf_s("%d", &f2);
			if (f2)
				switch (f2)
				{
				case 1:
					for (pd = 1; pd;)
					{
						printf("\n  请输入要压入栈中的数字： ");
						top = yz2(top);
						printf("\n  继续压栈请输入非 0 数字： ");
						scanf_s("%d", &pd);		getchar();
					}
					break;
				case 2:
					for (pd = 1; pd && top->top != -1;)
					{
						top = cz2(top);
						printf("\n  继续出栈请输入非 0 数字： ");
						scanf_s("%d", &pd);		getchar();
					}
					if (top->top == -1)		printf("\n  空栈，无法出栈");
					getchar();
					break;
				case 3:
					em2(top);
					break;
				case 4:
					top = mem2(top);
					break;
				}
			system("cls");
		}
	}
	return 0;
}

//********************************************************************* 顺序栈

void yz(s *x)							//压栈
{
	int y, pd;
	for (pd = 1; pd;)
	{
		printf("\n  请输入要压入栈中的数字： ");
		scanf_s("%d", &y);	getchar();
		x->top++;						//更新栈顶位置
		x->nums[x->top] = y;
		printf("\n  继续压栈请输入非 0 数字： ");
		scanf_s("%d", &pd);		getchar();
	}
}

void cz(s *x)							//出栈
{
	int pd;
	if (x->top != -1)
		for (pd = 1; pd && x->top != -1;)
		{
			printf("\n  栈顶数字： %d 已出栈", x->nums[x->top]);
			x->top--;					//更新栈顶位置
			printf("\n  继续出栈请输入非 0 数字： ");
			scanf_s("%d", &pd);		getchar();
		}
	if (x->top == -1)	printf("\n  栈已空，无法出栈");
	getchar();
}

void em(s *x)							//判断空栈
{
	if (x->top == -1)
		printf("\n  空栈\n\n  按回车返回");
	else
		printf("\n  不是空栈\n\n  按回车返回");
	getchar();		getchar();
}

void mem(s *x)							//置空
{
	x->top = -1;
	printf("\n  该栈已置空\n\n  按回车返回");
	getchar();		getchar();
}

//********************************************************************* 链式栈

s2 *yz2(s2 *x)							//压栈
{
	if (x->top == -1)
	{
		scanf_s("%d", &x->num);		getchar();
		x->top++;						//更新栈顶位置
	}
	else
	{
		s2 *y = (s2*)malloc(sizeof(s2));
		scanf_s("%d", &y->num);		getchar();
		y->last = x;
		y->top = x->top + 1;			//更新栈顶位置
		return y;
	}
	return x;
}

s2 *cz2(s2 *x)							//出栈
{
	s2 *y;
	if (x->top == 0)					//栈长为 1 时
		printf("\n  栈顶数字： %d 已出栈", x->num);
	else
	{
		printf("\n  栈顶数字： %d 已出栈", x->num);
		y = x->last;					//保存下一元素地址
		free(x);
		return y;
	}
	x->top--;							//栈已空，节点位置降为 -1
	return x;
}

void em2(s2 *x)							//判断空栈，是则返回真
{
	if (x->top == -1)
		printf("\n  空栈\n\n  按回车返回");
	else
		printf("\n  不是空栈\n\n  按回车返回");
	getchar();		getchar();
}

s2 *mem2(s2 *x)							//置空
{
	s2 *y;
	if (x->top > 0)
		for (; 1; x = y)
		{
			y = x->last;
			free(x);
		}
	if (x->top == 0)	x->top--;
	printf("\n  该栈已置空\n\n  按回车返回");
	getchar();		getchar();
	return x;
}