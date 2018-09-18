#include<stdio.h>
#include<stdlib.h>
/*
原题：
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

void jh(struct ListNode *x, struct ListNode *y)			//交换数据域
{
	struct ListNode *a = x->next, *b = y->next, temp;
	temp = *x;
	*x = *y;
	*y = temp;
	x->next = a;
	y->next = b;
}

struct ListNode *cz(struct ListNode* x)					//查找到 x 后的最小结点
{
	struct ListNode *min = x, *chu = x;
	for (; 1; x = x->next)
	{
		if (x->val < min->val)		min = x;
		if (x->next == NULL)		break;
	}
	if (min != chu)		return min;
	else	return NULL;
}

struct ListNode *mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL && l2 == NULL)	return;
	struct ListNode *a, *min;
	if (l1 != NULL)											//l1 不为空
	{
		for (a = l1; a->next != NULL; a = a->next);			//遍历到 l1 末尾
		a->next = l2;										//相连
		for (a = l1; a->next != NULL; a = a->next)			//排序
		{
			min = cz(a);
			if (min != NULL)	jh(a, min);
		}
		return l1;
	}
	else return l2;											//l1 为空，不拼接
}

/*
思路：
总体上，先将 l1 与 l2 相连，再排序即可。
先遍历到 l1 的末尾，将其与 l2 的表头相连，然后将整个链表排序。
注意：
1. 当 l1 为空时，不拼接，直接返回 l2
2. 当 l1、l2 均为空时，直接 return;
*/