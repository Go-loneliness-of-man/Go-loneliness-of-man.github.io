#include<stdio.h>
#include<stdlib.h>
//链表排序，实质上与数组排序是一样的，只需要将各个步骤分别封装一下便可像数组一样进行排序，下面以选择排序为例。

typedef struct s
{
	int id;
	struct s *next;
}s;

void jh(s *x, s *y);								//交换两结点的数据域
s *cz(s *x);										//查找该结点后的最小结点
void order(s *head);								//排序函数

int main()
{
	s *head = (s*)malloc(sizeof(s)), *tail = NULL, *temp2;		int temp;
	head->next = NULL;
	printf("\n  创建链表，请输入一串数字，以 0 结尾： ");
	for (; 1;)
	{
		scanf_s("%d", &temp);
		if (temp != 0)
		{
			if (head->next == NULL)
			{
				head->id = temp;
				tail = (s*)malloc(sizeof(s));
				tail->next = NULL;
				head->next = tail;
			}
			else
			{
				tail->id = temp;
				temp2 = (s*)malloc(sizeof(s));
				temp2->next = NULL;
				tail->next = temp2;
				tail = temp2;
			}
		}
		else break;
	}
	printf("\n  链表当前顺序：\n\n");
	for (temp2 = head; 1; temp2 = temp2->next)
		if (temp2->next != NULL)
			printf("%4d", temp2->id);
		else break;
	order(head);
	printf("\n\n  链表排序后：\n\n");
	for (temp2 = head; 1; temp2 = temp2->next)
		if (temp2->next != NULL)
			printf("%4d", temp2->id);
		else break;
	printf("\n\n  ");
	return 0;
}

void jh(s *x, s *y)									//交换两节点的数据域
{
	s *a = x->next, *b = y->next, temp;
	temp = *x;
	*x = *y;
	*y = temp;
	x->next = a;
	y->next = b;
}

s *cz(s *x)											//查找该结点后的最小结点
{
	s *temp, *min;
	for (temp = min = x; 1; temp = temp->next)
		if (temp->next == NULL)	break;
		else if (temp->id < min->id)		min = temp;
	if (min == x)	return NULL;
	else return min;
}

void order(s *head)									//排序函数
{
	s *temp, *czp, *temp2;
	for (temp = head; temp->next != NULL; temp = temp->next)
	{
		czp = cz(temp);
		if (czp != NULL)		jh(temp, czp);
	}
}