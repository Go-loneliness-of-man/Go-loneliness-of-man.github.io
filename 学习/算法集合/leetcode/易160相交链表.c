#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

���磬�������������

A:		a1 �� a2
				�K
				c1 �� c2 �� c3
				�J
B:  b1 �� b2 �� b3

�ڽڵ� c1 ��ʼ�ཻ��

ע�⣺
�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
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
		for (len1 = 0; headA != NULL; headA = headA->next, len1++);			//�󳤶�
		for (len2 = 0; headB != NULL; headB = headB->next, len2++);
		headA = A;		headB = B;
		if (len1 > len2)	for (len1 = len1 - len2; len1 != 0; headA = headA->next, len1--);//�ƶ�ָ�뵽���߲�ֵ��
		else if(len1 < len2)	for (len2 = len2 - len1; len2 != 0; headB = headB->next, len2--);
		for (; 1; headA = headA->next, headB = headB->next)					//���αȽ����ڵ��ַ�Ƿ���ͬ
			if (headA == headB)		return headA;
			else if ((headA != NULL && headB != NULL) && (headA->next == NULL || headB->next == NULL))
				break;														//����һ�߱������꣬����
	}
	return NULL;
}

int main()
{
	
	return 0;
}
/*
˼·��
�����жϳ��ȣ����߳�����������αȽ�������ڵ��ַ�Ƿ���ȼ��ɣ������Ȳ��ȣ���������ָ��ӱ�ͷ���ƶ����߲�ֵ�����ȣ����ظ��������Ĳ���
�� OK �ˡ�
*/