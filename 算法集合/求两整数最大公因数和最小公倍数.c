#include<stdio.h>
//���������� m ��n �������������С������
//շת�����:�ó�������������ֱ������Ϊ0�������һ�εĳ���Ϊ�������

/*
//շת������㷨һ:
int m, n, r1 , r2;								//�����������ı�����շת���������
int same(int x, int y);							//���������������same()����
int main()
{
	printf("������m: ");
	scanf_s("%d", &m);
	printf("������n: ");
	scanf_s("%d", &n);
	r1 = same(m, n);							//���������
	printf("�������: %d\n", r1);
	printf("��С������: %d\n", (m*n) / r1);		//�����ĳ˻������������Ϊ��С������
}

int same(int x, int y)							//����same����()
{
	for (r1 = x % y; r1 != 0; r1 = r2 % r1)		//x%y ��ֵ��r1��ֻҪ r1 != 0 �����ѭ����ѭ���� r2%r1 ��ֵ��r1
	{
		r2 = y;									//����һ������ĳ�����ֵ�� r2����Ϊ��εı�������������һ�ε����� r1
		y = r1;									//���� y ������һ������ĳ��� r1 ��ֵ
	}
	if (r1 == 0)								//����һ�����������ѭ������ x%y �� r1 == 0����ȡ��һ�εĳ��� y
		return y;
	else
		return r1;								//�ǵ�һ�����㣬y δ�������������ѭ��������Ϊ r1
}
*/

/*
//շת������㷨��:
#include<stdio.h>
int maxfactor(int x, int y);										//���������
int m, n, max, r1;													//������m��n���������max������r1
int main()
{
	printf("��������������������һ���ո���������뷨Ӣ��: ");
	scanf_s("%d %d", &m,&n);
	max = maxfactor(m, n);
	printf("\n�������Ϊ: %d\n\n��С������Ϊ: %d\n\n", max, m*n / max);
	return 0;
}
int maxfactor(int x, int y)
{
	if (x > y)
	{
		r1 = x%y;
		r1 == 0 ? r1 = y : maxfactor(y, r1);						//ֻҪ���ȡ��С��������Ϊ�㣬���ٴ��ó���������ȡ��
		return r1;
	}
	else
	{
		r1 = y%x;
		r1 == 0 ? r1 = x : maxfactor(x, r1);
		return r1;
	}
}
*/

/*
//�������:


*/