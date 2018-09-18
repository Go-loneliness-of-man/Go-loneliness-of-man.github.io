#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

void jh(struct ListNode *x, struct ListNode *y)			//����������
{
	struct ListNode *a = x->next, *b = y->next, temp;
	temp = *x;
	*x = *y;
	*y = temp;
	x->next = a;
	y->next = b;
}

struct ListNode *cz(struct ListNode* x)					//���ҵ� x �����С���
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
	if (l1 != NULL)											//l1 ��Ϊ��
	{
		for (a = l1; a->next != NULL; a = a->next);			//������ l1 ĩβ
		a->next = l2;										//����
		for (a = l1; a->next != NULL; a = a->next)			//����
		{
			min = cz(a);
			if (min != NULL)	jh(a, min);
		}
		return l1;
	}
	else return l2;											//l1 Ϊ�գ���ƴ��
}

/*
˼·��
�����ϣ��Ƚ� l1 �� l2 �����������򼴿ɡ�
�ȱ����� l1 ��ĩβ�������� l2 �ı�ͷ������Ȼ��������������
ע�⣺
1. �� l1 Ϊ��ʱ����ƴ�ӣ�ֱ�ӷ��� l2
2. �� l1��l2 ��Ϊ��ʱ��ֱ�� return;
*/