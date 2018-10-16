#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (head == NULL)	return false;						//空链表，不存在环
	struct ListNode *head2 = head;
	if (head != NULL && head->next != NULL)					//确保不造成访问空指针
		for (head = head->next; (head != NULL) && (head->next != NULL); head2 = head2->next, head = head->next->next)
			if (head2 == head)	return true;				//存在环
	return false;
}

int main()
{
	
	return 0;
}
/*
思路：
快慢指针法，两个指针同时遍历，一个每次前进两个，一个每次前进一个，当快指针遇到环时会停留在环中，当慢指针也进入环二者相遇时，证明链表存
在环，返回 true。
*/