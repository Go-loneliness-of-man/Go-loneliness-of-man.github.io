#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ�� Excel ����е������ƣ���������Ӧ������š�

���磬

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

ʾ�� 1:

����: "A"
���: 1

ʾ�� 2:

����: "AB"
���: 28

ʾ�� 3:

����: "ZY"
���: 701
*/

int titleToNumber(char *s)
{
	int rt, i, j;										//��� rt��ѭ������ i����λ���� j
	for (i = 0; s[i] != '\0'; i++);						//�����ַ���ĩβ
	for (rt = 0, j = 1, i--; i != -1; i--, j *= 26)		//ѭ������
		rt += (s[i] - 64)*j;							//����һ���ۼ�
	return rt;
}

int main()
{
	printf("%d", titleToNumber("ZY"));
	return 0;
}
/*
˼·��
�����ͱȽ϶����ˣ�ֻ�� 168 �������㣬�������������򵥵�һ����
*/