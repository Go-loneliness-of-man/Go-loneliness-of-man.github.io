#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
    队列与栈相反，它是先进先出的，同样也有人说它算不上一种数据结构，我也同样不讨论这个问题。队列与栈一样，在存储方式上讲也有两种实现
方式，下面同样用两种方式演示其实现和基本操作。
用数组：设两个位置指针分别标识队首、队尾。
链表：环状链表、只使用尾指针。
基本操作：入队、出队、置空。
*/

typedef struct s								//环状链表
{
	int num;
	struct s *next;
}s;

typedef struct s2								//数组
{
	int num[1000];
	int hd;										//队首
	int tl;										//队尾
}s2;

//****************************************************************** 环状链表

s *it(s *tail);									//入队

void ot(s *tail);								//出队

s *em(s *tail);									//置空

//****************************************************************** 数组

void it2(s2 *x);								//入队

void ot2(s2 *x);								//出队

//****************************************************************** 主函数

int main()
{
	int f, f2;
	printf("\n  环状链表请输入非 0 数字，数组输入 0： ");
	scanf_s("%d", &f);
	if (f)
	{
		s *tail = (s*)malloc(sizeof(s));	tail->next = NULL;
		for (f2 = 1; f2;)
		{
			printf("\n  入队、出队、置空请分别输入 1、2、3，结束请输入 0： ");
			scanf_s("%d", &f2);
			switch (f2)
			{
			case 1:									//入队
				tail = it(tail);
				break;
			case 2:									//出队
				ot(tail);
				break;
			case 3:									//置空
				tail = em(tail);
				break;
			}
			system("cls");
		}
	}
	else
	{
		s2 nums;	nums.hd = nums.tl = -1;			//创建队列
		for (f2 = 1; f2;)
		{
			printf("\n  入队、出队、置空请分别输入 1、2、3，结束请输入 0： ");
			scanf_s("%d", &f2);
			switch (f2)
			{
			case 1:									//入队
				it2(&nums);
				break;
			case 2:									//出队
				ot2(&nums);
				break;
			case 3:									//置空
				nums.hd = nums.tl = -1;
				printf("\n  队列已置空");
				break;
			}
			system("cls");
		}
	}
	return 0;
}

//****************************************************************** 环状链表

s *it(s *tail)										//入队
{
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n  请输入数字： ");
		if (tail->next == NULL)
		{
			scanf_s("%d", &tail->num);	getchar();
			tail->next = tail;						//区分空队
		}
		else
		{
			s *temp = (s*)malloc(sizeof(s));
			scanf_s("%d", &temp->num);	getchar();
			temp->next = tail->next;				//环状
			tail->next = temp;						//连接
			tail = tail->next;						//更新指向
		}
		printf("\n  要继续请输入非 0 数字： ");
		scanf_s("%d", &pd);	getchar();
	}
	return tail;
}

void ot(s *tail)									//出队
{
	int pd;		s *temp;
	for (pd = 1; pd;)
	{
		if (tail->next == NULL)
		{
			printf("\n  空队列");
			getchar();
		}
		else
			if (tail->next == tail)					//最后一个数字已出栈，空队列
			{
				printf("\n  队首数字： %d 已出队", tail->next->num);
				tail->next = NULL;
			}
			else
			{
				temp = tail->next;
				printf("\n  队首数字： %d 已出队", temp->num);
				tail->next = temp->next;			//删除队首
				free(temp);
			}
		printf("\n  要继续请输入非 0 数字： ");
		scanf_s("%d", &pd);		getchar();
	}
}

s *em(s *tail)										//置空
{
	s *x, *temp;
	if (tail->next != NULL)
		for (x = tail; tail->next != x;)
		{
			temp = tail->next;
			tail->next = temp->next;				//删除队首
			free(temp);
		}
	tail->next = NULL;
	printf("\n  队列已置空，按回车返回");
	getchar();	getchar();
	return tail;
}
/*
常见问题：
1、区分单节点和空队列问题，解决方法是在单节点时自己指向自己，空队为 NULL。
2、出队时删除已出栈节点问题，解决方法是声明一个临时指针指向出栈节点用来释放内存。
3、出队到最后一个节点的问题，指针域不再指向其它节点，直接设置为 NULL。
*/

//****************************************************************** 数组

void it2(s2 *x)								//入队
{
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n  请输入要入队的数字： ");
		if (x->hd == -1 && x->tl == -1)		//空队
		{
			scanf_s("%d", &x->num[++x->tl]);
			x->hd = 0;						//更新队首状态
		}
		else
			scanf_s("%d", &x->num[++x->tl]);
		printf("\n  继续入队请输入非 0 数字： ");
		scanf_s("%d", &pd);
	}
}

void ot2(s2 *x)								//出队
{
	int pd;
	for (pd = 1; pd && x->tl != -1;)		//队列为空时停止
	{
		if (x->hd == x->tl && x->tl != -1)	//队列只剩一个数字
		{
			printf("\n  数字： %d 已出队", x->num[x->hd]);
			x->hd = x->tl = -1;				//重置队首队尾
		}
		else
			printf("\n  数字： %d 已出队", x->num[x->hd++]);
		printf("\n  继续入队请输入非 0 数字： ");
		scanf_s("%d", &pd);	getchar();
	}
	if (x->tl == -1)
	{
		printf("\n  队列为空");
		getchar();
	}
}