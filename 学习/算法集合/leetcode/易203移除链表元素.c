#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/
struct ListNode
{
	int val;
	struct ListNode *next;
};

#define T head != NULL &&

struct ListNode *removeElements(struct ListNode* head, int val)
{
	struct ListNode *t, *t2;										//�±�ͷ t����ʱָ�� t2
	for (t = head; T head->val == val; head = head->next);			//������ͷ��ͬ�Ĳ���
	t = head;														//����������ı�ͷ
	for (t2 = head; T head->next != NULL; head = head->next)		//�����м䲿��
		if (T head->val == val)	t2->next = head->next;				//�ƹ��м�ڵ�
		else	t2 = head;											//�������� val �Ľڵ�����£��� val �ڵ㲻����
	if (T head->val == val)	t2->next = NULL;						//���ɾ��ĩβ�ڵ�
	return t;
}

int main()
{
	printf("%d", isHappy(2));
	return 0;
}
/*
˼·��
��Բ�ͬλ�õ�ɾ���в�ͬ�ķ�����
��ͷ�����ر�ͷ֮��Ľڵ���Ϊ��ͷ��ѭ��������ͷ������ͬ�Ĳ��֡�
�м䣺�ƹ���˫ָ�뷨����Ȳ���ָ���Ҳ����£�ʵ������ɾ����ǰһָ�룬��������������¡�
ĩβ��ֱ������ǰһ�ڵ�Ϊ NULL��
*/