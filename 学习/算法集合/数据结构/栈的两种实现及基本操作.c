#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
   ջ�����Ƚ���������ݽṹ��Ҳ����˵ջ�Ʋ������ݽṹ��ֻ���ֶ����ݽڵ�ķ��ʷ�ʽ���Ҳ�������������ʲô��ֻ�����ʹ�������Ӵ洢��ʽ��
����ջ��Ҫ��˳��洢�����飩����ʽ�洢���������ַ�ʽ������ֱ���ʾջ��ʵ�ּ������������
ջ��ջ��ָ���־�Ŵ�ʱջ�ĸ߶ȣ���ջΪ��ʱջ��ָ��Ϊ -1��
ջ�ںܶ�ʱ�����õ����ٸ����ӱ�������к�����ִ�о���ͨ��ջ��ʵ�ֵģ��ٸ��򵥵��������������ж�Ҳ����ͨ��ջ��ʵ�֡�
����������ѹջ����ջ���ÿա��ж�ջ�ա�
*/
typedef struct s					//˳��ջ
{
	int nums[1000];					//ջ��Ԫ��
	int top;						//ջ��ָ��
}s;

typedef struct s2					//��ʽջ
{
	int num;						//������
	int top;						//�ڵ�λ��
	struct s2 *last;				//ָ����
}s2;

//********************************************************************* ˳��ջ

void yz(s *x);						//ѹջ

void cz(s *x);						//��ջ

void em(s *x);						//�жϿ�ջ�����򷵻���

void mem(s *x);						//�ÿ�

//********************************************************************* ��ʽջ

s2 *yz2(s2 *x);						//ѹջ

s2 *cz2(s2 *x);						//��ջ

void em2(s2 *x);					//�жϿ�ջ�����򷵻���

s2 *mem2(s2 *x);					//�ÿ�

//********************************************************************* ������

int main()
{
	int f, f2;
	printf("\n  ˳��ջ����������� 0 ���֣���ʽջ������ 0�� ");
	scanf_s("%d", &f);		getchar();
	system("cls");
	if (f)
	{
		s x;	x.top = -1;			//����һ��˳��ջ
		for (f2 = 1; f2;)
		{
			printf("\n  ѹջ����ջ���ж�ջ�ա��ÿշֱ����� 1��2��3��4���������� 0�� ");
			scanf_s("%d", &f2);
			if (f2)
				switch (f2)
				{
				case 1:
					yz(&x);
					break;
				case 2:
					cz(&x);
					break;
				case 3:
					em(&x);
					break;
				case 4:
					mem(&x);
					break;
				}
			system("cls");
		}
	}
	else
	{
		int pd;
		s2 *top = (s2*)malloc(sizeof(s2));		//����һ����ʽջ�ڵ�
		top->top = -1;	top->last = NULL;		//��ʼ��
		for (f2 = 1; f2;)
		{
			printf("\n  ѹջ����ջ���ж�ջ�ա��ÿշֱ����� 1��2��3��4���������� 0�� ");
			scanf_s("%d", &f2);
			if (f2)
				switch (f2)
				{
				case 1:
					for (pd = 1; pd;)
					{
						printf("\n  ������Ҫѹ��ջ�е����֣� ");
						top = yz2(top);
						printf("\n  ����ѹջ������� 0 ���֣� ");
						scanf_s("%d", &pd);		getchar();
					}
					break;
				case 2:
					for (pd = 1; pd && top->top != -1;)
					{
						top = cz2(top);
						printf("\n  ������ջ������� 0 ���֣� ");
						scanf_s("%d", &pd);		getchar();
					}
					if (top->top == -1)		printf("\n  ��ջ���޷���ջ");
					getchar();
					break;
				case 3:
					em2(top);
					break;
				case 4:
					top = mem2(top);
					break;
				}
			system("cls");
		}
	}
	return 0;
}

//********************************************************************* ˳��ջ

void yz(s *x)							//ѹջ
{
	int y, pd;
	for (pd = 1; pd;)
	{
		printf("\n  ������Ҫѹ��ջ�е����֣� ");
		scanf_s("%d", &y);	getchar();
		x->top++;						//����ջ��λ��
		x->nums[x->top] = y;
		printf("\n  ����ѹջ������� 0 ���֣� ");
		scanf_s("%d", &pd);		getchar();
	}
}

void cz(s *x)							//��ջ
{
	int pd;
	if (x->top != -1)
		for (pd = 1; pd && x->top != -1;)
		{
			printf("\n  ջ�����֣� %d �ѳ�ջ", x->nums[x->top]);
			x->top--;					//����ջ��λ��
			printf("\n  ������ջ������� 0 ���֣� ");
			scanf_s("%d", &pd);		getchar();
		}
	if (x->top == -1)	printf("\n  ջ�ѿգ��޷���ջ");
	getchar();
}

void em(s *x)							//�жϿ�ջ
{
	if (x->top == -1)
		printf("\n  ��ջ\n\n  ���س�����");
	else
		printf("\n  ���ǿ�ջ\n\n  ���س�����");
	getchar();		getchar();
}

void mem(s *x)							//�ÿ�
{
	x->top = -1;
	printf("\n  ��ջ���ÿ�\n\n  ���س�����");
	getchar();		getchar();
}

//********************************************************************* ��ʽջ

s2 *yz2(s2 *x)							//ѹջ
{
	if (x->top == -1)
	{
		scanf_s("%d", &x->num);		getchar();
		x->top++;						//����ջ��λ��
	}
	else
	{
		s2 *y = (s2*)malloc(sizeof(s2));
		scanf_s("%d", &y->num);		getchar();
		y->last = x;
		y->top = x->top + 1;			//����ջ��λ��
		return y;
	}
	return x;
}

s2 *cz2(s2 *x)							//��ջ
{
	s2 *y;
	if (x->top == 0)					//ջ��Ϊ 1 ʱ
		printf("\n  ջ�����֣� %d �ѳ�ջ", x->num);
	else
	{
		printf("\n  ջ�����֣� %d �ѳ�ջ", x->num);
		y = x->last;					//������һԪ�ص�ַ
		free(x);
		return y;
	}
	x->top--;							//ջ�ѿգ��ڵ�λ�ý�Ϊ -1
	return x;
}

void em2(s2 *x)							//�жϿ�ջ�����򷵻���
{
	if (x->top == -1)
		printf("\n  ��ջ\n\n  ���س�����");
	else
		printf("\n  ���ǿ�ջ\n\n  ���س�����");
	getchar();		getchar();
}

s2 *mem2(s2 *x)							//�ÿ�
{
	s2 *y;
	if (x->top > 0)
		for (; 1; x = y)
		{
			y = x->last;
			free(x);
		}
	if (x->top == 0)	x->top--;
	printf("\n  ��ջ���ÿ�\n\n  ���س�����");
	getchar();		getchar();
	return x;
}