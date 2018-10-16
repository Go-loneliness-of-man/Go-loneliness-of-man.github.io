#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
    ������ջ�෴�������Ƚ��ȳ��ģ�ͬ��Ҳ����˵���㲻��һ�����ݽṹ����Ҳͬ��������������⡣������ջһ�����ڴ洢��ʽ�Ͻ�Ҳ������ʵ��
��ʽ������ͬ�������ַ�ʽ��ʾ��ʵ�ֺͻ���������
�����飺������λ��ָ��ֱ��ʶ���ס���β��
������״����ֻʹ��βָ�롣
������������ӡ����ӡ��ÿա�
*/

typedef struct s								//��״����
{
	int num;
	struct s *next;
}s;

typedef struct s2								//����
{
	int num[1000];
	int hd;										//����
	int tl;										//��β
}s2;

//****************************************************************** ��״����

s *it(s *tail);									//���

void ot(s *tail);								//����

s *em(s *tail);									//�ÿ�

//****************************************************************** ����

void it2(s2 *x);								//���

void ot2(s2 *x);								//����

//****************************************************************** ������

int main()
{
	int f, f2;
	printf("\n  ��״����������� 0 ���֣��������� 0�� ");
	scanf_s("%d", &f);
	if (f)
	{
		s *tail = (s*)malloc(sizeof(s));	tail->next = NULL;
		for (f2 = 1; f2;)
		{
			printf("\n  ��ӡ����ӡ��ÿ���ֱ����� 1��2��3������������ 0�� ");
			scanf_s("%d", &f2);
			switch (f2)
			{
			case 1:									//���
				tail = it(tail);
				break;
			case 2:									//����
				ot(tail);
				break;
			case 3:									//�ÿ�
				tail = em(tail);
				break;
			}
			system("cls");
		}
	}
	else
	{
		s2 nums;	nums.hd = nums.tl = -1;			//��������
		for (f2 = 1; f2;)
		{
			printf("\n  ��ӡ����ӡ��ÿ���ֱ����� 1��2��3������������ 0�� ");
			scanf_s("%d", &f2);
			switch (f2)
			{
			case 1:									//���
				it2(&nums);
				break;
			case 2:									//����
				ot2(&nums);
				break;
			case 3:									//�ÿ�
				nums.hd = nums.tl = -1;
				printf("\n  �������ÿ�");
				break;
			}
			system("cls");
		}
	}
	return 0;
}

//****************************************************************** ��״����

s *it(s *tail)										//���
{
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n  ���������֣� ");
		if (tail->next == NULL)
		{
			scanf_s("%d", &tail->num);	getchar();
			tail->next = tail;						//���ֿն�
		}
		else
		{
			s *temp = (s*)malloc(sizeof(s));
			scanf_s("%d", &temp->num);	getchar();
			temp->next = tail->next;				//��״
			tail->next = temp;						//����
			tail = tail->next;						//����ָ��
		}
		printf("\n  Ҫ����������� 0 ���֣� ");
		scanf_s("%d", &pd);	getchar();
	}
	return tail;
}

void ot(s *tail)									//����
{
	int pd;		s *temp;
	for (pd = 1; pd;)
	{
		if (tail->next == NULL)
		{
			printf("\n  �ն���");
			getchar();
		}
		else
			if (tail->next == tail)					//���һ�������ѳ�ջ���ն���
			{
				printf("\n  �������֣� %d �ѳ���", tail->next->num);
				tail->next = NULL;
			}
			else
			{
				temp = tail->next;
				printf("\n  �������֣� %d �ѳ���", temp->num);
				tail->next = temp->next;			//ɾ������
				free(temp);
			}
		printf("\n  Ҫ����������� 0 ���֣� ");
		scanf_s("%d", &pd);		getchar();
	}
}

s *em(s *tail)										//�ÿ�
{
	s *x, *temp;
	if (tail->next != NULL)
		for (x = tail; tail->next != x;)
		{
			temp = tail->next;
			tail->next = temp->next;				//ɾ������
			free(temp);
		}
	tail->next = NULL;
	printf("\n  �������ÿգ����س�����");
	getchar();	getchar();
	return tail;
}
/*
�������⣺
1�����ֵ��ڵ�Ϳն������⣬����������ڵ��ڵ�ʱ�Լ�ָ���Լ����ն�Ϊ NULL��
2������ʱɾ���ѳ�ջ�ڵ����⣬�������������һ����ʱָ��ָ���ջ�ڵ������ͷ��ڴ档
3�����ӵ����һ���ڵ�����⣬ָ������ָ�������ڵ㣬ֱ������Ϊ NULL��
*/

//****************************************************************** ����

void it2(s2 *x)								//���
{
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n  ������Ҫ��ӵ����֣� ");
		if (x->hd == -1 && x->tl == -1)		//�ն�
		{
			scanf_s("%d", &x->num[++x->tl]);
			x->hd = 0;						//���¶���״̬
		}
		else
			scanf_s("%d", &x->num[++x->tl]);
		printf("\n  �������������� 0 ���֣� ");
		scanf_s("%d", &pd);
	}
}

void ot2(s2 *x)								//����
{
	int pd;
	for (pd = 1; pd && x->tl != -1;)		//����Ϊ��ʱֹͣ
	{
		if (x->hd == x->tl && x->tl != -1)	//����ֻʣһ������
		{
			printf("\n  ���֣� %d �ѳ���", x->num[x->hd]);
			x->hd = x->tl = -1;				//���ö��׶�β
		}
		else
			printf("\n  ���֣� %d �ѳ���", x->num[x->hd++]);
		printf("\n  �������������� 0 ���֣� ");
		scanf_s("%d", &pd);	getchar();
	}
	if (x->tl == -1)
	{
		printf("\n  ����Ϊ��");
		getchar();
	}
}