#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

typedef struct ListNode { int val; struct ListNode *next; };

#define F (head!=NULL && head->next!=NULL)

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode *head2 = head, *p;								//保存表头地址
	for (p = NULL; F; head = head->next)							//遍历链表
		if (F && head->val == head->next->val)						//当下一结点相同时
		{
			for (p = head; F && head->val == head->next->val; head = head->next)	//跳过接下来所有相同结点
				if (head != NULL && head->next == NULL)				//到达末尾，直接置起始处为空
					p->next = NULL;
			p->next = head->next;									//连接
		}
	return head2;
}

/*
思路：
因为链表是有序的，所以问题就变得很简单，遍历一次链表，遍历时检测下个结点的值，若相同则跳过接下来所有相同结点。
注意：
leetcode 编译器对语法要求比较严格死板，对于链表，判断条件不仅要判断 head->next 不为空，还要判断 head 本身也不为空。
*/