#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false
*/

#define PD(x) ((x>47&&x<58)||(x>64&&x<91)||(x>96&&x<123))		//�ж��Ƿ�����ĸ�������ַ���������

bool isPalindrome(char* s)
{
	int len, i, j;
	for (len = 0; s[len] != '\0'; len++);						//��������
	for (i = 0, j = len - 1; i < j; i++, j--)					//��β�Ƚ�
	{
		if (!PD(s[i]))	for (; !PD(s[i]) && i<len; i++);		//����������ĸ�����ֵĲ���
		if (!PD(s[j]))	for (; !PD(s[j]) && j<len; j--);
		if (PD(s[i]) && PD(s[j]) && (!(s[i] == s[j] || (s[i] > 96 && s[i] - 32 == s[j]) || (s[j] > 96 && s[j] - 32 == s[i]))))
			return false;										//����ĸ�����
	}
	return true;
}

int main()
{
	char a[100] = "0P";
	printf("%d", isPalindrome(a));
	return 0;
}

/*
˼·��
�������ȣ�����λ��ʼ���αȽϣ�ֻ�Ƚ���ĸ�������ַ������������ַ�������
ע����������ĸ��Сд��ͨ�� ASC�� �����ʵ�֡�
*/