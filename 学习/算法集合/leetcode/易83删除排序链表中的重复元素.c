#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:

����: 1->1->2
���: 1->2
ʾ�� 2:

����: 1->1->2->3->3
���: 1->2->3
*/

typedef struct ListNode { int val; struct ListNode *next; };

#define F (head!=NULL && head->next!=NULL)

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode *head2 = head, *p;								//�����ͷ��ַ
	for (p = NULL; F; head = head->next)							//��������
		if (F && head->val == head->next->val)						//����һ�����ͬʱ
		{
			for (p = head; F && head->val == head->next->val; head = head->next)	//����������������ͬ���
				if (head != NULL && head->next == NULL)				//����ĩβ��ֱ������ʼ��Ϊ��
					p->next = NULL;
			p->next = head->next;									//����
		}
	return head2;
}

/*
˼·��
��Ϊ����������ģ���������ͱ�úܼ򵥣�����һ����������ʱ����¸�����ֵ������ͬ������������������ͬ��㡣
ע�⣺
leetcode ���������﷨Ҫ��Ƚ��ϸ����壬���������ж���������Ҫ�ж� head->next ��Ϊ�գ���Ҫ�ж� head ����Ҳ��Ϊ�ա�
*/