#include<stdio.h>
//շת����������������:�ó�������������ֱ������Ϊ0�������һ�εĳ���Ϊ�������

/*
//շת������㷨һ:
int same(int x, int y);							//����������� same() ����

int main()
{
	int m, n, r1;								//�����������������������
	printf("\n �������������������ÿո����: ");
	scanf_s("%d %d", &m, &n);
	r1 = same(m, n);							//���������������
	printf(" �������: %d\n", r1);
	printf(" ��С������: %d\n ", (m*n) / r1);		//�����ĳ˻������������Ϊ��С������
}
int same(int x, int y)							//����same����()
{
	int r1, r2;
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	for (; r1 != 0; r1 = r2 % r1)		//x%y ��ֵ��r1��ֻҪ r1 != 0 �����ѭ����ѭ���� r2%r1 ��ֵ��r1
	{
		r2 = y;									//����һ������ĳ�����ֵ�� r2����Ϊ��εı�������������һ�ε����� r1
		y = r1;									//���� y ������һ������ĳ��� r1 ��ֵ
	}
	return y;									//���س��� y
}
/**/

/*
//շת������㷨��:���õݹ飬������
#include<stdio.h>
int m, n, max, r1, maxfactor(int x, int y);				//����������������� max������ r1������������ĺ���
int main()
{
	printf("\n ���������������������ÿո����: ");
	scanf_s("%d %d", &m,&n);
	max = maxfactor(m, n);								//�����������������
	printf("\n�������Ϊ: %d\n\n��С������Ϊ: %d\n\n", max, m*n / max);
	return 0;
}
int maxfactor(int x, int y)
{
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	r1 == 0 ? r1 = x : maxfactor(x, r1);			//�ݹ�
	return r1;										//�ݹ���Ϻ󷵻س��� r1
}
/**/


//շת������㷨��:���õݹ飬������������
int m, n,maxfactor(int x,int y);					//������ m �� n��������������� maxfactor()
int  main()
{
	printf("\n �������������� ");
	scanf_s("%d %d",&m,&n);							//��ȡ���� m �� n
	printf(" ���������%d\n ��С������: %d\n ", maxfactor(m, n), (m*n) / maxfactor(m, n));
	return 0;
}
int maxfactor(int x, int y)
{
	int r1;
	if (x > y)
		r1 = x % y;
	else
	{
		r1 = y % x;
		y = x;
	}
	return (x%y) == 0 ? y : maxfactor(y, (x%y));	//�ݹ飬������Ϊ 0����ֹͣ���������
}
/**/

/*
//�������:


*/