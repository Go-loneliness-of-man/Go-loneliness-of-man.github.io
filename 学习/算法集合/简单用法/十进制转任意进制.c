#include<stdio.h>
//��ʮ��������ת��Ϊ�����������

void zh(int a, int b);

int main()
{
	int num, jz;
	printf("\n  ����������ʮ��������Ҫת���Ľ��ƣ� ");
	scanf_s("%d%d", &num, &jz);
	zh(num, jz);
	printf("\n\n  ");
	return 0;
}

void zh(int a, int b)
{
	int aa[20], i;
	for (i = 0; a; i++)
	{
		aa[i] = a%b;
		a /= b;
	}
	printf("\n  ��ʮ������תΪ %d ������Ϊ�� ", b);
	for (i -= 1; i >= 0; i--)	printf("%d", aa[i]);
}
/*
	˼·��
	ֻ��ת������������ȡ���ǳ˶�ȡ�����򷨵������㡣
*/