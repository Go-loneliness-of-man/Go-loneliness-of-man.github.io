#include<stdio.h>
#include<stdlib.h>
/*
原题：
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/
struct ListNode
{
	int val;
	struct ListNode *next;
};

#define T head != NULL &&

struct ListNode *removeElements(struct ListNode* head, int val)
{
	struct ListNode *t, *t2;										//新表头 t、临时指针 t2
	for (t = head; T head->val == val; head = head->next);			//跳过开头相同的部分
	t = head;														//保存跳过后的表头
	for (t2 = head; T head->next != NULL; head = head->next)		//跳过中间部分
		if (T head->val == val)	t2->next = head->next;				//绕过中间节点
		else	t2 = head;											//遇到不等 val 的节点则更新，等 val 节点不更新
	if (T head->val == val)	t2->next = NULL;						//检测删除末尾节点
	return t;
}

int main()
{
	printf("%d", isHappy(2));
	return 0;
}
/*
思路：
针对不同位置的删除有不同的方法。
表头：返回表头之后的节点作为表头，循环跳过开头连续相同的部分。
中间：绕过，双指针法，相等操作指针且不更新（实现连续删除）前一指针，不相等则正常更新。
末尾：直接设置前一节点为 NULL。
*/