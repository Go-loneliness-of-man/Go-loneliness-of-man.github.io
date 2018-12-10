#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ��һ����ĸ��λ�ʡ�

ʾ�� 1:

����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:

����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
*/

/*
//����һ������ʵʵ������ϣ������ʱ�� 8ms
typedef struct jg
{
	char c;
	int count;
}jg;

void sort(jg *s, int len)								//ѡ������
{
	int min, i, j;	jg temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = min = i; j < len; j++)					//�ҵ��󷽵���С��
			if (s[min].c > s[j].c)	min = j;
		if (min == i)	continue;						//δ�ҵ���������
		temp = s[min];
		s[min] = s[i];
		s[i] = temp;
	}
}

bool isAnagram(char *s, char *t)
{
	int i, j, k, len1, len2;	jg x[1000], y[1000];	//ѭ������ i �� j �� k���ַ����� len���ַ��� x
	for (i = 0; i < 1000; i++)							//��ʼ������
		x[i].count = y[i].count = 1;
	for (i = len1 = 0; s[i] != '\0'; i++)				//�����ַ��� s �õ����ַ��� x
	{
		for (j = 0; j < len1; j++)						//�����ַ��Ƿ��ѳ��ֹ�
			if (x[j].c == s[i])							//�ѳ��ֹ��������� 1 ������
			{
				x[j].count++;
				break;
			}
		if (j == len1)	x[len1++].c = s[i];				//�洢���ַ����ַ�����
	}
	for (i = len2 = 0; t[i] != '\0'; i++)				//�����ַ��� t �õ����ַ��� y
	{
		for (j = 0; j < len2; j++)						//�����ַ��Ƿ��ѳ��ֹ�
			if (y[j].c == t[i])							//�ѳ��ֹ��������� 1 ������
			{
				y[j].count++;
				break;
			}
		if (j == len2)	y[len2++].c = t[i];				//�洢���ַ����ַ�����
	}
	sort(x, len1);	sort(y, len2);						//���ַ����������
	if (len1 != len2)	return false;					//�ж��ַ��������Ƿ���ͬ
	for (i = 0; i < len1; i++)							//�ж����ࡢÿ�ֵĸ����Ƿ���ͬ
		if (x[i].c != y[i].c)							//�ж�����
			return false;
		else if (x[i].count != y[i].count)				//�жϸ���
			return false;
	return true;										//���ࡢ��������ͬ
}
*/

//������������ leetcode ������ֻ����ĸ������ȡ�ɣ�����ʱ�� 0 ms
bool isAnagram(char *s, char *t)
{
	int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++)	x[s[i] - 'a']++;	//���� s ���ַ��� x
	for (i = 0; t[i] != '\0'; i++)	y[t[i] - 'a']++;	//���� t ���ַ��� y
	for (i = 0; i < 26; i++)							//�Ƚ����ַ����Ƿ���ͬ
		if (x[i] != y[i])	return false;
	return true;										//���ࡢ��������ͬ
}

int main()
{
	char s[1000] = "anagram", t[1000] = "nagaram";
	printf("%d", isAnagram(s, t));
	return 0;
}

/*
˼·��
��ĸ��λ������ĸ���ࡢ����ĸ���ִ���������ͬ�ģ�ֻ������˳��ͬ��
�������ַ����ֱ�����ϣ��ȶԼ��ɣ����� leetcode ������ֻ����ĸ�����Կɽ���ȡ�ɣ����ó���Ϊ 26 λ����������ʾ������ĸ�ĳ��ִ�������
���ڽ�����ϣ��ʱ��ÿ����ĸ��ȥ 'a'���õõ���ֵ��Ϊ�±���м������ɡ�
��ʵ����ϣ��ͱȽ��鷳����Ҫ��������һ���ַ� c���������� count �Ľṹ�������ṹ�����飬ÿ���ַ�ֻ�������ڴ�һ�Σ��´���������ֻ���Ӽ�
�����������ַ����Ĺ�ϣ����ٶԶ��߽�����������ٱȽϼ��ɡ�
*/