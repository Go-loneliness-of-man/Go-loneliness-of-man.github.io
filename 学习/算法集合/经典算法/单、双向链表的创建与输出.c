#include<stdio.h>
#include<string.h>
#include<windows.h>
//��������ӡ��/˫������

//���ȶ���õ��ַ�����������������Ҫ�õ�
//�ַ����ȽϺ������β�Ϊ���ַ������׵�ַ����ͬ����ֵΪ 1�����򷵻� 0
int sbj(char* x, char* y)
{
	for (int i = 0; x[i] == y[i]; i++)					//ֻҪ���ַ�����Ӧ�ַ���ͬ���ͼ���ѭ��
		if (x[i] == '\0' && y[i] == '\0')				//���ܶ��� '\0' ��������ͬ��ͬʱ������Ҳ��ͬ
			return 1;									//��ͬ������ֵΪ 1
	return 0;											//ѭ��δ�����ַ���������ͬ������ֵΪ 0
}
//�ַ������ƺ������� y ���Ƶ� x �У�size ����󳤶�
void scp(char *x, char *y, int size)
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

/*
**����������˼·��
��������ȫ����ָ�������в����ģ�ͨ������Ҫ���������ṹ�壨��Ϊ��ͷ����β��������ָ��ָ�����ǣ��ֱ��Ϊͷָ�롢βָ�룬ͷָ��ָ���ͷ��
βָ������ָ���β�����Ҫ�ǵþ�������βָ���ָ��
һ��ÿ����㱻��Ϊ������ָ����������洢�������ݣ����������ָ����ֻ��һ��ָ���Ա��һ������Ϊ next
**ע��㣺
1. ÿ�δ������½�㶼Ҫ��ʼ�� next ��ԱΪ NULL��
2. ʼ�ձ���βָ���ڱ��ĩβ����ÿ�ν��½�����ӵ���β��Ҫ����βָ��ָ���½��
*/
/*
//��������
typedef struct std {								//������ṹ������
	char number[21];								//���
	struct std *next;								//ָ���¸����
}s;													//���ṹ���������Ƽ�Ϊ s

s *head, *tail;										//����ͷָ�롢βָ��

s *New(char *number);								//�����Ǵ���һ���½�㲢��ֵ���������ַ

void pri(s *x);										//��ӡ���������β���ͷָ��

int main()
{
	head = (s*)malloc(sizeof(s));					//������ͷ
	head->next = NULL;								//��ʼ����ͷ next
	char number[21];								//��ʱ�� *number �ַ���
	for (int pd = 1; pd;)
	{
		for (int pd2 = 1; pd2;)						//ѭ���½����
		{
			printf("\n  �½�һ����㣬���������ţ� ");
			gets_s(number, 21);						//��ȡ�����
			if (head->next == NULL)					//������ǿյģ����½�������ڱ�ͷ��
			{
				head->next = New(number);
				tail = head->next;					//��βָ��ָ���½��
			}
			else
			{
				tail->next = New(number);			//���ǿյģ����½�������ڱ�β��
				tail = tail->next;					//����βָ��ָ��
			}
			printf("\n\n  ��Ҫ�����½���������� 0������������������: ");
			scanf_s("%d", &pd2);		getchar();
		}
		system("cls");
		pri(head);									//��ӡ������
		printf("\n\n  ��Ҫ�������������� 0������������������: ");
		scanf_s("%d", &pd);		getchar();			//��ȡ�û�ָ����� getchar() �����س����Ժ�� gets_s() ��Ӱ��
		system("cls");
	}
	printf("\n  ");
	return 0;
}

s* New(char *number)								//����һ���½�㲢��ֵ���������ַ������
{
	s *y = (s*)malloc(sizeof(s));					//����һ���½�㲢�����ַ����һ����ʱ������ָ��
	scp(y->number, number, 21);						//ִ�и�ֵ����
	y->next = NULL;									//��ʼ���½��� next
	return y;										//���ؽ���ַ
}

//��ӡ��������
//˼·��ÿ�δ�ӡ��һ�����󣬸���ָ�� x ָ����һ����㣬�� x = x -> next�������ǰ��� next Ϊ NULL�������ӡ��ϣ�����ѭ��
void pri(s *x)
{
	printf("\n  ��ӡ������\n\n");
	if (x->next == NULL)
		printf("  ���ǿյ�\n\n  ");
	else
		for (x = x->next; 1; x = x->next)
		{
			printf("  %s", x->number);
			if (x->next == NULL) break;
		}
}
/**/

/*
**˫��������˼·��
˫������������ݱȵ�������Ҫ����Ķ࣬�������𼸺�ֻ��һ����˫������ָ����������ָ���Ա��һ������Ϊ next��last
ʵ�ʲ���ʱ������Ҫ�õ�ĳ����ϸ����ĵ�ַ��������ɾ����ȷ����Χ�ȣ������ʹ�õ�������ͺ��鷳�������ò��ҽ������ʾ˫������ķ���֮��
*/

//˫������
typedef struct std {								//������ṹ��
	char number[21];								//���
	struct std *last;								//ָ���ϸ����
	struct std *next;								//ָ���¸����
}s;													//���ṹ���������Ƽ�Ϊ s

s *head, *tail;										//����ͷָ�롢βָ��

s *New(char *number, s*last);						//�����Ǵ���һ���½�㲢��ֵ���������ַ��˫��

void pri(s *x);										//��ӡ���������β���ͷָ��

int main()
{
	head = (s*)malloc(sizeof(s));					//������ͷ
	head->last = head->next = NULL;					//��ʼ����ͷָ����
	char number[21];								//��ʱ�� *number �ַ���
	for (int pd = 1; pd;)
	{
		for (int pd2 = 1; pd2;)						//ѭ���½����
		{
			printf("\n  �½�һ����㣬���������ţ� ");
			gets_s(number, 21);						//��ȡ�����
			if (head->next == NULL)					//������ǿյģ����½�������ڱ�ͷ��
			{
				head->next = New(number, head);
				tail = head->next;					//��βָ��ָ���½��
			}
			else
			{
				tail->next = New(number, tail);		//���ǿյģ����½�������ڱ�β��
				tail = tail->next;					//����βָ��ָ��
			}
			printf("\n\n  ��Ҫ�����½���������� 0������������������: ");
			scanf_s("%d", &pd2);		getchar();
		}
		system("cls");
		pri(head);									//��ӡ������
		for (int pd3 = 1; pd3;)						//ѭ������
		{
			s *cz;		char temp[21];
			printf("\n\n  ������Ҫ���ҽ��ı�ţ� ");
			gets_s(temp, 21);
			for (cz = head; 1;)
				if (sbj(temp, cz->number) == 1)		break;
				else if (cz->next == NULL)	break;
				else	cz = cz->next;
				if (cz->next == NULL && (sbj(temp, cz->number) == 0))
					printf("\n  δ���ҵ��ý��");
				else if (cz->last->last != NULL)
					printf("\n  ���ҵ���㣺 %s\t\tǰһ����ţ� %s", cz->number, cz->last->number);
				else
					printf("\n  ���ҵ���㣺 %s\t\tǰһ����Ǳ�ͷ", cz->number);
				printf("\n\n  ��Ҫ�������������� 0������������������: ");
				scanf_s("%d", &pd3);		getchar();	//��ȡ�û�ָ����� getchar() �����س����Ժ�� gets_s() ��Ӱ��
		}
		printf("\n\n  ��Ҫ�������������� 0������������������: ");
		scanf_s("%d", &pd);		getchar();				//��ȡ�û�ָ����� getchar() �����س����Ժ�� gets_s() ��Ӱ��
		system("cls");
	}
	printf("\n  ");
	return 0;
}

s *New(char *number, s *last)							//�����Ǵ���һ���½�㲢��ֵ���������ַ��˫��
{
	s *y = (s*)malloc(sizeof(s));						//����һ���½�㲢�����ַ����һ����ʱ������ָ��
	scp(y->number, number, 21);							//ִ�и�ֵ����
	y->next = NULL;										//��ʼ���½��� next
	y->last = last;										//�ϸ����ĵ�ַ last
	return y;											//���ؽ���ַ
}
void pri(s *x)
{
	printf("\n  ��ӡ������\n\n");
	if (x->next == NULL)
		printf("  ���ǿյ�\n\n  ");
	else
		for (x = x->next; 1; x = x->next)
		{
			printf("  %s", x->number);
			if (x->next == NULL) break;
		}
}
/**/