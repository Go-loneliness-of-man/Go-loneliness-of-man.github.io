#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
��תһ��������

ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
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
	for (i = 0; head != NULL&&head->next != NULL; head = head->next)		//���������δ�������
		a[i++] = head->val;
	a[i] = head->val;														//���һ���ڵ�
	for (head = h2; i != -1; head = head->next, i--)						//����ֵ
		head->val = a[i];
	return h2;
}

int main()
{
	printf("%d", isIsomorphic("aba","cda"));
	return 0;
}

/*
˼·��
��������洢 val �������У��ٴ�ͷ�������Ÿ�ֵ��
*/