#include<stdio.h>
//����ӽ׳� 1!+2!+.....20! ��ֵ
int c, d = 0, i = 0;
unsigned long a = 0, b = 1;
int main()
{
	for (a, b, i, d; d <= 20; d++, i = 0)				//ÿ��ѭ����ʼ�� i ��ֵ
	{
		b = d;											//��ʼ��b��ֵ��ʹ�����forѭ���Ĵ���
		c = b;											//����b��ζ���whileѭ����ֵ�����޶�����
		while (i < c)
		{
			i++;
			b = b*i;
		}
		a = a + b;
	}
	printf("%u\n", a);
	return 0;
}