#include<stdio.h>
char a[100];
int main()
{
	printf("�������ַ�: ");
	gets_s(a, 100);					// get_s() ��Ҫ����һ������ָ���ַ����ĳ���
	printf("%s\n", a);
	return 0;
}