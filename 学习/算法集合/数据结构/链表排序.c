#include<stdio.h>
#include<stdlib.h>
//��������ʵ����������������һ���ģ�ֻ��Ҫ����������ֱ��װһ�±��������һ����������������ѡ������Ϊ����

typedef struct s
{
	int id;
	struct s *next;
}s;

void jh(s *x, s *y);								//����������������
s *cz(s *x);										//���Ҹý������С���
void order(s *head);								//������

int main()
{
	s *head = (s*)malloc(sizeof(s)), *tail = NULL, *temp2;		int temp;
	head->next = NULL;
	printf("\n  ��������������һ�����֣��� 0 ��β�� ");
	for (; 1;)
	{
		scanf_s("%d", &temp);
		if (temp != 0)
		{
			if (head->next == NULL)
			{
				head->id = temp;
				tail = (s*)malloc(sizeof(s));
				tail->next = NULL;
				head->next = tail;
			}
			else
			{
				tail->id = temp;
				temp2 = (s*)malloc(sizeof(s));
				temp2->next = NULL;
				tail->next = temp2;
				tail = temp2;
			}
		}
		else break;
	}
	printf("\n  ����ǰ˳��\n\n");
	for (temp2 = head; 1; temp2 = temp2->next)
		if (temp2->next != NULL)
			printf("%4d", temp2->id);
		else break;
	order(head);
	printf("\n\n  ���������\n\n");
	for (temp2 = head; 1; temp2 = temp2->next)
		if (temp2->next != NULL)
			printf("%4d", temp2->id);
		else break;
	printf("\n\n  ");
	return 0;
}

void jh(s *x, s *y)									//�������ڵ��������
{
	s *a = x->next, *b = y->next, temp;
	temp = *x;
	*x = *y;
	*y = temp;
	x->next = a;
	y->next = b;
}

s *cz(s *x)											//���Ҹý������С���
{
	s *temp, *min;
	for (temp = min = x; 1; temp = temp->next)
		if (temp->next == NULL)	break;
		else if (temp->id < min->id)		min = temp;
	if (min == x)	return NULL;
	else return min;
}

void order(s *head)									//������
{
	s *temp, *czp, *temp2;
	for (temp = head; temp->next != NULL; temp = temp->next)
	{
		czp = cz(temp);
		if (czp != NULL)		jh(temp, czp);
	}
}