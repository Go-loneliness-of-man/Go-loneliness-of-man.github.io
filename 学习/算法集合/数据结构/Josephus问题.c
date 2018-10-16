#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
原题：
1 对元素类型为整型的顺序存储的线性表进行插入、删除和查找操作。
2、编写一个求解 Josephus 问题的函数。用整数序列 1, 2, 3, ……, n表示顺序围坐在圆桌周围的人。

问题分析：
Josephus 环问题，假设有 n 个人排成一个圈。从第 s 个人开始报数，数到第 m 个人的时候这个人从队列里出列。然后继续在环里数后面第 m 个
人，让其出列直到所有人都出列。求所有这些人出列的排列顺序。
*/

//建立双向环状链表解决所有问题
typedef struct s {									//定义结点结构体
	int id;											//编号
	struct s *last;									//指向上个结点
	struct s *next;									//指向下个结点
}s;													//将结构体类型名称简化为 s

s *head, *tail, *temp;								//声明头指针、尾指针

void pri(s *x);										//打印整个链表，形参是头指针

void czn(s *head, int cz);							//查找指定编号

void d(s *head, int del);							//删除指定编号

void add(s *head, int ad);							//在某结点后插入结点

void Josephus(s *head, int n, int s2, int m);		//演示 Josephus 问题过程

int main()
{
	int n, i;
	head = (s*)malloc(sizeof(s));					//创建表头
	head->last = head->next = NULL;					//初始化表头指针域
	printf("\n  请输入要创建的定长链表的长度： ");
	scanf_s("%d",&n);
	for (i = 1; i <= n; i++)						//循环建立定长链表
		if (head->next == NULL)						//如果表是空的，将新结点连接在表头后
		{
			head->id = i;							//获取编号
			tail = (s*)malloc(sizeof(s));			//创建新结点
			tail->next = head;						//环状
			head->next = tail;						//连到表头
			tail->last = head;						//指向表头
		}
		else
		{
			tail->id = i;							//获取编号
			temp = (s*)malloc(sizeof(s));			//创建新结点
			temp->next = head;						//环状链表
			head->last = temp;
			tail->next = temp;						//连到表尾
			temp->last = tail;						//指向上一结点
			tail = temp;							//更新尾指针指向
		}
	pri(head);										//打印整个表
	printf("\n\n  要继续请按回车");
	getchar();	getchar();	system("cls");
	for (int pd = 0; 1;)
	{
		printf("\n  查找、删除、插入功能请输入 1、2、3，Josephus 环问题输入 4，退出输入 0： ");
		scanf_s("%d", &pd);
		if (pd == 0)	break;
		if (pd == 1)								//查找
		{
			int cz;
			printf("\n  请输入要查找的编号： ");
			scanf_s("%d", &cz);
			czn(head, cz);
			printf("\n\n  按回车返回");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 2)
		{
			int del;
			printf("\n  请输入要删除的编号： ");
			scanf_s("%d", &del);
			d(head, del);
			printf("\n\n  按回车返回");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 3)
		{
			int ad;
			printf("\n  在某结点 x 后插入结点，请输入结点 x 编号： ");
			scanf_s("%d", &ad);
			add(head, ad);
			printf("\n\n  按回车返回");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 4)
		{
			int n2, s2, m;	s *head2, *tail2, *temp2;				//总人数 n2、起始编号 s2、周期 m
			head2 = (s*)malloc(sizeof(s));
			tail2 = (s*)malloc(sizeof(s));
			temp2 = (s*)malloc(sizeof(s));
			head2->next = NULL;
			printf("\n  请依次输入 n、s、m，空格隔开： ");
			scanf_s("%d%d%d", &n2, &s2, &m);
			for (int i = 1; i <= n2; i++)							//循环建立定长链表
				if (head2->next == NULL)							//如果表是空的，将新结点连接在表头后
				{
					head2->id = i;									//获取编号
					tail2 = (s*)malloc(sizeof(s));					//创建新结点
					tail2->next = head2;							//环状
					head2->next = tail2;							//连到表头
					tail2->last = head2;							//指向表头
				}
				else
				{
					tail2->id = i;									//获取编号
					temp2 = (s*)malloc(sizeof(s));					//创建新结点
					temp2->next = head2;							//环状链表
					head2->last = temp2;
					tail2->next = temp2;							//连到表尾
					temp2->last = tail2;							//指向上一结点
					tail2 = temp2;									//更新尾指针指向
				}
			pri(head2);												//打印整个表
			tail2 = tail2->last;
			free(tail2->next);
			tail2->next = head2;
			head2->last = tail2;
			Josephus(head2, n2, s2, m);								//演示解决 Josephus 问题的过程
			printf("\n\n  要继续请按回车");
			getchar();	system("cls");
		}
	}
	printf("\n\n  ");
	return 0;
}

void pri(s *x)														//输出整个链表
{
	s *temp;
	printf("\n  现打印整个表： ");
	if (x->next == NULL)
		printf("  表是空的");
	else
		for (temp = x; x->next != temp; x = x->next)
			printf("  %d", x->id);
}

void czn(s *head, int cz)											//查找指定编号结点
{
	s *temp;
	for (temp = head; head->next != temp; head = head->next)
		if (head->id == cz)
		{
			printf("\n  查找到结点编号： %d", head->id);
			break;
		}
	if (temp == head->next)		printf("\n  未查找到该结点");
}

void d(s *head, int del)											//删除指定编号
{
	s *head2 = head, *temp;
	for (temp = head; temp != head->next; head = head->next)
		if (head->id == del)
		{
			printf("\n  删除具有编号 %d 的结点\n", head->id);
			head->last->next = head->next;							//绕过该结点，达到删除目的
			head->next->last = head->last;
			free(head);
			break;
		}
	if (temp == head->next)		printf("\n  该结点不存在");
	pri(head2);
}

void add(s *head, int ad)											//在某结点后插入结点
{
	int ad2;			s *head2 = head, *temp, *temp2;
	printf("\n  请输入要插入的结点编号： ");
	scanf_s("%d", &ad2);
	for (temp2 = head; temp2 != head->next; head = head->next)
		if (head->id == ad)
		{
			printf("\n  向结点 %d 后插入结点 %d\n", head->id, ad2);
			temp = (s*)malloc(sizeof(s));							//创建新结点
			temp->id = ad2;
			temp->last = head;										//开始插入指定结点后方
			temp->next = head->next;
			head->next->last = temp;
			head->next = temp;										//插入完毕
			break;
		}
	if (temp2 == head->next)	printf("\n  该结点不存在");
	pri(head2);
}

void Josephus(s *head, int n, int s2, int m)						//演示 Josephus 解题运行过程
{
	s *temp, *temp2;		int bj, i, temp3 = m - 1;
	for (i = 1, m = m + s2 - 1; 1; head = head->next, i++)
	{
		if (head->next == head) break;
		if (i == m)													//达到周期数，去掉一个人。
		{
			head->last->next = head->next;							//绕过该结点，达到删除目的
			head->next->last = head->last;
			printf("\n  去掉%3d，目前状态： ", head->id);
			head = head->next;
			for (temp = temp2 = head, bj = 1; temp != temp2 || bj; temp = temp->next, bj = 0)
				printf("%4d", temp->id);
			m += temp3;
		}
	}
	printf("\n  已去掉所有人，按回车返回。");
	getchar();
}

/*
思路：闭合的环装链表，每当到达一定次数，删除一个结点。
*/