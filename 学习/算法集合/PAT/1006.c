#include<stdio.h>
//�õ�һ�� 1000 ���ڵ����֣��ֱ���ݰ�λ��ʮλ���������� B �� S����󽫸�λ������ 123...n ����ʽ��ʾ���� 234 ��ʾΪ BBSSS1234
int main()
{
	int n, b, s, g, i;
	scanf("%d", &n);
	b = n / 100 % 10;
	s = n / 10 % 10;
	g = n % 10;
	for (i = 0; i < b; i++)
		printf("B");
	for (i = 0; i < s; i++)
		printf("S");
	for (i = 0; i < g; i++)
		printf("%d", i + 1);
	return 0;
}
/*
˼·����ȡ��λ���֣�����ѭ���������ָ���ַ���
*/