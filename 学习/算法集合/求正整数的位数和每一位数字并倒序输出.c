#include<stdio.h>
//����������λ����ÿһλ�����ֲ��������
int x, a, b, c, d, e;										//��ȡ�����ֵ�x����a��e�������򵽸�λ����
int judge(int x1);											//�ж�x�Ǽ�λ��
int inverted_order(int x2);									//�� x �ĸ�λ���ֵ�������
int main()
{
	printf("\n  ������һ����λ���ڵ�����: ");
	scanf_s(" %d", &x);
	printf("\n  ��������һ�� %d λ��\n\n", judge(x));
	printf("  ��λ������: %d\n\n  ǧλ������: %d\n\n  ��λ������: %d\n\n  ʮλ������: %d\n\n  ��λ������: %d\n\n", a, b, c, d, e);
	printf("  �������: %05d\n\n  ", inverted_order(x));		//�������λ������ȫ 0
	return 0;
}
int judge(int x1)											//����judge()����
{
	a = (x1 / 10000) % 10;
	b = (x1 / 1000) % 10;
	c = (x1 / 100) % 10;
	d = (x1 / 10) % 10;
	e = x1 % 10;
	if (a == 0 && b == 0 && c == 0 && d == 0)
		return 1;
	else if (a == 0 && b == 0 && c == 0)
		return 2;
	else if (a == 0 && b == 0)
		return 3;
	else if (a == 0)
		return 4;
	else if (a != 0)
		return 5;
	return 0;												//�ṹ��Ҫ������
}
int inverted_order(int x2)									//����inverted_order()����
{
	switch (judge(x))
	{
	case 1:
		return e;
		break;
	case 2:
		return 10 * e + d;
		break;
	case 3:
		return 100 * e + 10 * d + c;
		break;
	case 4:
		return 1000 * e + 100 * d + 10 * c + b;
		break;
	case 5:
		return 10000 * e + 1000 * d + 100 * c + 10 * b + a;
		break;
	}
	return 0;										//�ṹ��Ҫ������
}