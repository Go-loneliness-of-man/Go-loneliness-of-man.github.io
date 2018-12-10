#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct x
{
	int nums[200000];
	int top;
}x;

bool isPalindrome(struct ListNode *head)
{
	if (head == NULL || (head != NULL && head->next == NULL))	return true;	//特殊情况
	struct ListNode *temp = head;	x n;				//快指针、栈
	for (n.top = -1; 1; head = head->next)				//将前半段压入栈中
	{
		n.nums[++n.top] = head->val;					//压栈
		temp = temp->next;								//快指针前进一步
		if (temp != NULL&&temp->next == NULL) 			//长度为偶数
		{
			head = head->next;							//向前跳一次
			break;
		}
		temp = temp->next;								//再前进一步
		if (temp != NULL&&temp->next == NULL)			//长度为奇数
		{
			head = head->next->next;					//向前跳两次
			break;
		}
	}
	for (; n.top != -1; head = head->next)				//循环出栈比较
		if (n.nums[n.top--] != head->val)				//不等，返回 false
			return false;
	return true;										//相等
}

int main()
{

	return 0;
}

/*
思路：
快慢指针，快指针前进速度是慢指针的两倍，初始状态二者都在起点，每次循环时，若快指针前进一次便到链表末尾，则代表链表长度为偶数，若两次到
末尾则代表长度为奇数。据此控制入栈、出栈。
*/