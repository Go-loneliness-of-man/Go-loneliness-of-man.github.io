#include<stdio.h>
typedef struct sutdent {
	char name[21];
	char id[21];
	int scoure;
	struct sutdent *next;
} s;

s *head, *tail, *temp, *max, *min;		//ͷָ�롢βָ�롢��ʱָ�롢���ֵָ�롢��Сֵָ��

int main()
{
	int n, i;		head = (s*)malloc(sizeof(s));	head->next = NULL;
	//ѧ������ n��ѭ������ i��������ͷ����ʼ����ͷ next
	scanf("%d", &n);		getchar();							//��ȡѧ������
	for (i = 0; i < n; i++)
	{
		if (head->next == NULL)									//��ֵ��ͷ����������ʼ����β
		{
			scanf("%s%s%d", &(head->name), &(head->id), &(head->scoure));	getchar();
			tail = (s*)malloc(sizeof(s));		tail->next = NULL;
			head->next = tail;
		}
		else													//��ֵ��β����������ʼ���µı�β
		{
			scanf("%s%s%d", &(tail->name), &(tail->id), &(tail->scoure));	getchar();
			temp = tail;
			tail = (s*)malloc(sizeof(s));		tail->next = NULL;
			temp->next = tail;									//����β��ǰһ�������
		}
	}
	for (temp = max = min = head; 1 ; temp = temp->next)		//��������
	{
		if (temp->scoure > max->scoure)		max = temp;			//ɸѡ�������
		if (temp->scoure < min->scoure)		min = temp;			//ɸѡ����С��
		if (temp->next->next == NULL)		break;				//ĩβ����
	}
	printf("%s %s\n%s %s", max->name, max->id, min->name, min->id);
	return 0;
}

/*
˼·��
����ѧ���ṹ�� student ���� typedef ��дΪ s��������̬����������ݡ����������ҳ�����ߡ���С�ߣ������
*/