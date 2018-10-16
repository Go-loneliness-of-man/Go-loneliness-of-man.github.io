#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
ԭ�⣺
1 ��Ԫ������Ϊ���͵�˳��洢�����Ա���в��롢ɾ���Ͳ��Ҳ�����
2����дһ����� Josephus ����ĺ��������������� 1, 2, 3, ����, n��ʾ˳��Χ����Բ����Χ���ˡ�

���������
Josephus �����⣬������ n �����ų�һ��Ȧ���ӵ� s ���˿�ʼ������������ m ���˵�ʱ������˴Ӷ�������С�Ȼ������ڻ���������� m ��
�ˣ��������ֱ�������˶����С���������Щ�˳��е�����˳��
*/

//����˫��״��������������
typedef struct s {									//������ṹ��
	int id;											//���
	struct s *last;									//ָ���ϸ����
	struct s *next;									//ָ���¸����
}s;													//���ṹ���������Ƽ�Ϊ s

s *head, *tail, *temp;								//����ͷָ�롢βָ��

void pri(s *x);										//��ӡ���������β���ͷָ��

void czn(s *head, int cz);							//����ָ�����

void d(s *head, int del);							//ɾ��ָ�����

void add(s *head, int ad);							//��ĳ���������

void Josephus(s *head, int n, int s2, int m);		//��ʾ Josephus �������

int main()
{
	int n, i;
	head = (s*)malloc(sizeof(s));					//������ͷ
	head->last = head->next = NULL;					//��ʼ����ͷָ����
	printf("\n  ������Ҫ�����Ķ�������ĳ��ȣ� ");
	scanf_s("%d",&n);
	for (i = 1; i <= n; i++)						//ѭ��������������
		if (head->next == NULL)						//������ǿյģ����½�������ڱ�ͷ��
		{
			head->id = i;							//��ȡ���
			tail = (s*)malloc(sizeof(s));			//�����½��
			tail->next = head;						//��״
			head->next = tail;						//������ͷ
			tail->last = head;						//ָ���ͷ
		}
		else
		{
			tail->id = i;							//��ȡ���
			temp = (s*)malloc(sizeof(s));			//�����½��
			temp->next = head;						//��״����
			head->last = temp;
			tail->next = temp;						//������β
			temp->last = tail;						//ָ����һ���
			tail = temp;							//����βָ��ָ��
		}
	pri(head);										//��ӡ������
	printf("\n\n  Ҫ�����밴�س�");
	getchar();	getchar();	system("cls");
	for (int pd = 0; 1;)
	{
		printf("\n  ���ҡ�ɾ�������빦�������� 1��2��3��Josephus ���������� 4���˳����� 0�� ");
		scanf_s("%d", &pd);
		if (pd == 0)	break;
		if (pd == 1)								//����
		{
			int cz;
			printf("\n  ������Ҫ���ҵı�ţ� ");
			scanf_s("%d", &cz);
			czn(head, cz);
			printf("\n\n  ���س�����");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 2)
		{
			int del;
			printf("\n  ������Ҫɾ���ı�ţ� ");
			scanf_s("%d", &del);
			d(head, del);
			printf("\n\n  ���س�����");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 3)
		{
			int ad;
			printf("\n  ��ĳ��� x ������㣬�������� x ��ţ� ");
			scanf_s("%d", &ad);
			add(head, ad);
			printf("\n\n  ���س�����");
			getchar();		getchar();
			system("cls");
		}
		else if (pd == 4)
		{
			int n2, s2, m;	s *head2, *tail2, *temp2;				//������ n2����ʼ��� s2������ m
			head2 = (s*)malloc(sizeof(s));
			tail2 = (s*)malloc(sizeof(s));
			temp2 = (s*)malloc(sizeof(s));
			head2->next = NULL;
			printf("\n  ���������� n��s��m���ո������ ");
			scanf_s("%d%d%d", &n2, &s2, &m);
			for (int i = 1; i <= n2; i++)							//ѭ��������������
				if (head2->next == NULL)							//������ǿյģ����½�������ڱ�ͷ��
				{
					head2->id = i;									//��ȡ���
					tail2 = (s*)malloc(sizeof(s));					//�����½��
					tail2->next = head2;							//��״
					head2->next = tail2;							//������ͷ
					tail2->last = head2;							//ָ���ͷ
				}
				else
				{
					tail2->id = i;									//��ȡ���
					temp2 = (s*)malloc(sizeof(s));					//�����½��
					temp2->next = head2;							//��״����
					head2->last = temp2;
					tail2->next = temp2;							//������β
					temp2->last = tail2;							//ָ����һ���
					tail2 = temp2;									//����βָ��ָ��
				}
			pri(head2);												//��ӡ������
			tail2 = tail2->last;
			free(tail2->next);
			tail2->next = head2;
			head2->last = tail2;
			Josephus(head2, n2, s2, m);								//��ʾ��� Josephus ����Ĺ���
			printf("\n\n  Ҫ�����밴�س�");
			getchar();	system("cls");
		}
	}
	printf("\n\n  ");
	return 0;
}

void pri(s *x)														//�����������
{
	s *temp;
	printf("\n  �ִ�ӡ������ ");
	if (x->next == NULL)
		printf("  ���ǿյ�");
	else
		for (temp = x; x->next != temp; x = x->next)
			printf("  %d", x->id);
}

void czn(s *head, int cz)											//����ָ����Ž��
{
	s *temp;
	for (temp = head; head->next != temp; head = head->next)
		if (head->id == cz)
		{
			printf("\n  ���ҵ�����ţ� %d", head->id);
			break;
		}
	if (temp == head->next)		printf("\n  δ���ҵ��ý��");
}

void d(s *head, int del)											//ɾ��ָ�����
{
	s *head2 = head, *temp;
	for (temp = head; temp != head->next; head = head->next)
		if (head->id == del)
		{
			printf("\n  ɾ�����б�� %d �Ľ��\n", head->id);
			head->last->next = head->next;							//�ƹ��ý�㣬�ﵽɾ��Ŀ��
			head->next->last = head->last;
			free(head);
			break;
		}
	if (temp == head->next)		printf("\n  �ý�㲻����");
	pri(head2);
}

void add(s *head, int ad)											//��ĳ���������
{
	int ad2;			s *head2 = head, *temp, *temp2;
	printf("\n  ������Ҫ����Ľ���ţ� ");
	scanf_s("%d", &ad2);
	for (temp2 = head; temp2 != head->next; head = head->next)
		if (head->id == ad)
		{
			printf("\n  ���� %d ������� %d\n", head->id, ad2);
			temp = (s*)malloc(sizeof(s));							//�����½��
			temp->id = ad2;
			temp->last = head;										//��ʼ����ָ������
			temp->next = head->next;
			head->next->last = temp;
			head->next = temp;										//�������
			break;
		}
	if (temp2 == head->next)	printf("\n  �ý�㲻����");
	pri(head2);
}

void Josephus(s *head, int n, int s2, int m)						//��ʾ Josephus �������й���
{
	s *temp, *temp2;		int bj, i, temp3 = m - 1;
	for (i = 1, m = m + s2 - 1; 1; head = head->next, i++)
	{
		if (head->next == head) break;
		if (i == m)													//�ﵽ��������ȥ��һ���ˡ�
		{
			head->last->next = head->next;							//�ƹ��ý�㣬�ﵽɾ��Ŀ��
			head->next->last = head->last;
			printf("\n  ȥ��%3d��Ŀǰ״̬�� ", head->id);
			head = head->next;
			for (temp = temp2 = head, bj = 1; temp != temp2 || bj; temp = temp->next, bj = 0)
				printf("%4d", temp->id);
			m += temp3;
		}
	}
	printf("\n  ��ȥ�������ˣ����س����ء�");
	getchar();
}

/*
˼·���պϵĻ�װ����ÿ������һ��������ɾ��һ����㡣
*/