#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ�������ж��������Ƿ��л���

���ף�
���ܷ�ʹ�ö���ռ������⣿
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (head == NULL)	return false;						//�����������ڻ�
	struct ListNode *head2 = head;
	if (head != NULL && head->next != NULL)					//ȷ������ɷ��ʿ�ָ��
		for (head = head->next; (head != NULL) && (head->next != NULL); head2 = head2->next, head = head->next->next)
			if (head2 == head)	return true;				//���ڻ�
	return false;
}

int main()
{
	
	return 0;
}
/*
˼·��
����ָ�뷨������ָ��ͬʱ������һ��ÿ��ǰ��������һ��ÿ��ǰ��һ��������ָ��������ʱ��ͣ���ڻ��У�����ָ��Ҳ���뻷��������ʱ��֤�������
�ڻ������� true��
*/