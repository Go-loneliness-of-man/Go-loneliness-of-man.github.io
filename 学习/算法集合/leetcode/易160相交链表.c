#include<stdio.h>
#include<stdlib.h>
/*
原题：
编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:		a1 → a2
				↘
				c1 → c2 → c3
				↗
B:  b1 → b2 → b3

在节点 c1 开始相交。

注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int len1, len2;		struct ListNode *A = headA, *B = headB;
	if (headA != NULL && headB != NULL)
	{
		for (len1 = 0; headA != NULL; headA = headA->next, len1++);			//求长度
		for (len2 = 0; headB != NULL; headB = headB->next, len2++);
		headA = A;		headB = B;
		if (len1 > len2)	for (len1 = len1 - len2; len1 != 0; headA = headA->next, len1--);//移动指针到二者差值处
		else if(len1 < len2)	for (len2 = len2 - len1; len2 != 0; headB = headB->next, len2--);
		for (; 1; headA = headA->next, headB = headB->next)					//依次比较两节点地址是否相同
			if (headA == headB)		return headA;
			else if ((headA != NULL && headB != NULL) && (headA->next == NULL || headB->next == NULL))
				break;														//任意一者被遍历完，跳出
	}
	return NULL;
}

int main()
{
	
	return 0;
}
/*
思路：
首先判断长度，二者长度相等则依次比较两链表节点地址是否相等即可，若长度不等，将长链表指针从表头处移动二者差值个长度，再重复相等情况的操作
就 OK 了。
*/