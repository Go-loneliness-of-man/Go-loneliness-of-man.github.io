#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���

ʾ�� 1:

����: 1
���: true
����: 2 �� 0 �η����� 1
ʾ�� 2:

����: 16
���: true
����: 2 �� 4 �η����� 16
ʾ�� 3:

����: 218
���: false
*/

bool isPowerOfTwo(int n)
{
	if (n < 1)	return false;						//�������
	else if (n <= 2)	return true;
	for (int x = 2; n > x; x <<= 1)					//����ȡ�� 2 ���ݴ�
		if (n%x != 0)	return false;
	return true;
}

int main()
{
	printf("%d", isPowerOfTwo());
	return 0;
}

/*
˼·��
�������ݴη���������С�������ݴΡ�
*/