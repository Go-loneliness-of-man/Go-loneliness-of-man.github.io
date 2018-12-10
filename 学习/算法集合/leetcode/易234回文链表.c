#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
���ף�
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
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
	if (head == NULL || (head != NULL && head->next == NULL))	return true;	//�������
	struct ListNode *temp = head;	x n;				//��ָ�롢ջ
	for (n.top = -1; 1; head = head->next)				//��ǰ���ѹ��ջ��
	{
		n.nums[++n.top] = head->val;					//ѹջ
		temp = temp->next;								//��ָ��ǰ��һ��
		if (temp != NULL&&temp->next == NULL) 			//����Ϊż��
		{
			head = head->next;							//��ǰ��һ��
			break;
		}
		temp = temp->next;								//��ǰ��һ��
		if (temp != NULL&&temp->next == NULL)			//����Ϊ����
		{
			head = head->next->next;					//��ǰ������
			break;
		}
	}
	for (; n.top != -1; head = head->next)				//ѭ����ջ�Ƚ�
		if (n.nums[n.top--] != head->val)				//���ȣ����� false
			return false;
	return true;										//���
}

int main()
{

	return 0;
}

/*
˼·��
����ָ�룬��ָ��ǰ���ٶ�����ָ�����������ʼ״̬���߶�����㣬ÿ��ѭ��ʱ������ָ��ǰ��һ�α㵽����ĩβ�������������Ϊż���������ε�
ĩβ�������Ϊ�������ݴ˿�����ջ����ջ��
*/