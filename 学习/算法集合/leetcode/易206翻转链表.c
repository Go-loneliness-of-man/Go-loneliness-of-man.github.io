#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	if (head == NULL)	return NULL;
	struct ListNode *h2 = head;	int a[10000], i;
	for (i = 0; head != NULL&&head->next != NULL; head = head->next)		//将数据依次存入数组
		a[i++] = head->val;
	a[i] = head->val;														//最后一个节点
	for (head = h2; i != -1; head = head->next, i--)						//倒序赋值
		head->val = a[i];
	return h2;
}

int main()
{
	printf("%d", isIsomorphic("aba","cda"));
	return 0;
}

/*
思路：
遍历链表存储 val 到数组中，再从头给链表倒着赋值。
*/