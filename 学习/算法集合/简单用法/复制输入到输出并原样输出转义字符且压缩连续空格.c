#include<stdio.h>
//�����븴�Ƶ����������ת���ַ�ԭ��������������е������ո�ѹ��Ϊһ���ո�
#define NONE 0;
int main()
{
	int i;
	char c[100] = "213         12 321 \b        t\b\tt\\tt\t\            b\\\\         \\t\\\b\\t\b"
		 , bj = NONE;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == ' ')
			for (bj = c[i]; c[i] == ' '; i++);			//��� c ������һ�οո񣬲����������������ո�ȫ����������
		if (bj == ' ')									//��� c �������ո����һ���ո�
		{
			putchar(bj);								//�� c �������ո����һ���ո�
			bj = NONE;									//���� bj ��ֵ
		}
		if (c[i] == '\t')
			printf("\\t");
		else if (c[i] == '\b')
			printf("\\b");
		else if (c[i] == '\\')
			printf("\\\\");
		else
			putchar(c[i]);								//��������ַ�
	}
	return 0;
}