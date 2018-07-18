#include<stdio.h>
#include<string.h>
#include<windows.h>
//创建、打印单/双向链表

//事先定义好的字符串处理函数，程序中要用到
//字符串比较函数，形参为两字符串的首地址，相同返回值为 1，否则返回 0
int sbj(char* x, char* y)
{
	for (int i = 0; x[i] == y[i]; i++)					//只要两字符串对应字符相同，就继续循环
		if (x[i] == '\0' && y[i] == '\0')				//若能读到 '\0' ，代表相同，同时，长度也相同
			return 1;									//相同，返回值为 1
	return 0;											//循环未读完字符串，不相同，返回值为 0
}
//字符串复制函数，将 y 复制到 x 中，size 是最大长度
void scp(char *x, char *y, int size)
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

/*
**单向链表创建思路：
链表是完全利用指针来进行操作的，通常起码要创建两个结构体（称为表头、表尾）并设置指针指向它们，分别称为头指针、尾指针，头指针指向表头，
尾指针总是指向表尾，因此要记得经常更新尾指针的指向。
一般每个结点被分为数据域、指针域，数据域存储各种数据，单向链表的指针域只有一个指针成员，一般命名为 next
**注意点：
1. 每次创建的新结点都要初始化 next 成员为 NULL。
2. 始终保持尾指针在表的末尾，即每次将新结点连接到表尾后都要更新尾指针指向新结点
*/
/*
//单向链表
typedef struct std {								//定义结点结构体类型
	char number[21];								//编号
	struct std *next;								//指向下个结点
}s;													//将结构体类型名称简化为 s

s *head, *tail;										//声明头指针、尾指针

s *New(char *number);								//作用是创建一个新结点并赋值，返回其地址

void pri(s *x);										//打印整个链表，形参是头指针

int main()
{
	head = (s*)malloc(sizeof(s));					//创建表头
	head->next = NULL;								//初始化表头 next
	char number[21];								//临时的 *number 字符串
	for (int pd = 1; pd;)
	{
		for (int pd2 = 1; pd2;)						//循环新建结点
		{
			printf("\n  新建一个结点，请输入结点编号： ");
			gets_s(number, 21);						//获取结点编号
			if (head->next == NULL)					//如果表是空的，将新结点连接在表头后
			{
				head->next = New(number);
				tail = head->next;					//将尾指针指向新结点
			}
			else
			{
				tail->next = New(number);			//表不是空的，将新结点连接在表尾后
				tail = tail->next;					//更新尾指针指向
			}
			printf("\n\n  若要结束新建结点请输入 0，否则输入任意数字: ");
			scanf_s("%d", &pd2);		getchar();
		}
		system("cls");
		pri(head);									//打印整个表
		printf("\n\n  若要结束程序，请输入 0，否则输入任意数字: ");
		scanf_s("%d", &pd);		getchar();			//获取用户指令，并用 getchar() 消除回车符对后边 gets_s() 的影响
		system("cls");
	}
	printf("\n  ");
	return 0;
}

s* New(char *number)								//创建一个新结点并赋值，返回其地址（单向）
{
	s *y = (s*)malloc(sizeof(s));					//创建一个新结点并将其地址赋给一个临时声明的指针
	scp(y->number, number, 21);						//执行赋值操作
	y->next = NULL;									//初始化新结点的 next
	return y;										//返回结点地址
}

//打印整个链表
//思路：每次打印完一个结点后，更新指针 x 指向下一个结点，即 x = x -> next，如果当前结点 next 为 NULL，代表打印完毕，跳出循环
void pri(s *x)
{
	printf("\n  打印整个表：\n\n");
	if (x->next == NULL)
		printf("  表是空的\n\n  ");
	else
		for (x = x->next; 1; x = x->next)
		{
			printf("  %s", x->number);
			if (x->next == NULL) break;
		}
}
/**/

/*
**双向链表创建思路：
双向链表操作数据比单向链表要方便的多，但其区别几乎只有一个：双向链表指针域有两个指针成员，一般命名为 next、last
实际操作时，经常要用到某结点上个结点的地址（如排序、删除、确定范围等），如果使用单向链表就很麻烦，下面用查找结点来演示双向链表的方便之处
*/

//双向链表
typedef struct std {								//定义结点结构体
	char number[21];								//编号
	struct std *last;								//指向上个结点
	struct std *next;								//指向下个结点
}s;													//将结构体类型名称简化为 s

s *head, *tail;										//声明头指针、尾指针

s *New(char *number, s*last);						//作用是创建一个新结点并赋值，返回其地址（双向）

void pri(s *x);										//打印整个链表，形参是头指针

int main()
{
	head = (s*)malloc(sizeof(s));					//创建表头
	head->last = head->next = NULL;					//初始化表头指针域
	char number[21];								//临时的 *number 字符串
	for (int pd = 1; pd;)
	{
		for (int pd2 = 1; pd2;)						//循环新建结点
		{
			printf("\n  新建一个结点，请输入结点编号： ");
			gets_s(number, 21);						//获取结点编号
			if (head->next == NULL)					//如果表是空的，将新结点连接在表头后
			{
				head->next = New(number, head);
				tail = head->next;					//将尾指针指向新结点
			}
			else
			{
				tail->next = New(number, tail);		//表不是空的，将新结点连接在表尾后
				tail = tail->next;					//更新尾指针指向
			}
			printf("\n\n  若要结束新建结点请输入 0，否则输入任意数字: ");
			scanf_s("%d", &pd2);		getchar();
		}
		system("cls");
		pri(head);									//打印整个表
		for (int pd3 = 1; pd3;)						//循环查找
		{
			s *cz;		char temp[21];
			printf("\n\n  请输入要查找结点的编号： ");
			gets_s(temp, 21);
			for (cz = head; 1;)
				if (sbj(temp, cz->number) == 1)		break;
				else if (cz->next == NULL)	break;
				else	cz = cz->next;
				if (cz->next == NULL && (sbj(temp, cz->number) == 0))
					printf("\n  未查找到该结点");
				else if (cz->last->last != NULL)
					printf("\n  查找到结点： %s\t\t前一结点编号： %s", cz->number, cz->last->number);
				else
					printf("\n  查找到结点： %s\t\t前一结点是表头", cz->number);
				printf("\n\n  若要结束查找请输入 0，否则输入任意数字: ");
				scanf_s("%d", &pd3);		getchar();	//获取用户指令，并用 getchar() 消除回车符对后边 gets_s() 的影响
		}
		printf("\n\n  若要结束程序，请输入 0，否则输入任意数字: ");
		scanf_s("%d", &pd);		getchar();				//获取用户指令，并用 getchar() 消除回车符对后边 gets_s() 的影响
		system("cls");
	}
	printf("\n  ");
	return 0;
}

s *New(char *number, s *last)							//作用是创建一个新结点并赋值，返回其地址（双向）
{
	s *y = (s*)malloc(sizeof(s));						//创建一个新结点并将其地址赋给一个临时声明的指针
	scp(y->number, number, 21);							//执行赋值操作
	y->next = NULL;										//初始化新结点的 next
	y->last = last;										//上个结点的地址 last
	return y;											//返回结点地址
}
void pri(s *x)
{
	printf("\n  打印整个表：\n\n");
	if (x->next == NULL)
		printf("  表是空的\n\n  ");
	else
		for (x = x->next; 1; x = x->next)
		{
			printf("  %s", x->number);
			if (x->next == NULL) break;
		}
}
/**/