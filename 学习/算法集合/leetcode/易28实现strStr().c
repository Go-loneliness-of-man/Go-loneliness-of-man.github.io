#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
*/

int strStr(char* haystack, char* needle)
{
	if (*needle == '\0')	return 0;
	for (int i = 0; *haystack != '\0'; haystack++, i++)	//���� haystack
		if (*haystack == *needle)						//���ҵ����ַ�
			if (sbj(haystack, needle))					//�ȽϺ��ַ��Ƿ����
				return i;								//�����±�
	return -1;											//������
}

int sbj(char *x, char *y)
{
	for (; *x != '\0'&&*y != '\0'; x++, y++)			//�Ƚ�����ַ��Ƿ���ͬ
		if (*x != *y)	return 0;						//��ͬ
	if (*y != '\0')	return 0;							//y δ�Ƚ��� x �ѽ�������ͬ
	return 1;
}

int main()
{
	char a[100] = "babsabba", b[100] = "bb";
	printf("%d", strStr(a, b));
	return 0;
}

/*
˼·��
�� haystack �в��� needle ���׸��ַ�������ȣ���Ƚ�����ַ��Ƿ�Ҳ��ȣ����ǣ����ҵ����������������
ע�⣺
*/