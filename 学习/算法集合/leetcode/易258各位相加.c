#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
ԭ�⣺
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����

ʾ��:

����: 38
���: 2
����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ���� 2 ��һλ�������Է��� 2��
����:
����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������
*/

int q(int num)								//�����λ֮��
{
	int sum;
	for (sum = 0; num; num /= 10)
		sum += num % 10;					//ȡ��һλ���
	return sum;
}

int addDigits(int num)
{
	for (; num > 9; num = q(num));			//ѭ����ֵ
	return num;
}

int main()
{
	printf("%d", addDigits(999999674));
	return 0;
}

/*
˼·��
ѭ����ֵ��ֻҪ���� 9 ���������ֵ����ȡ�������İ취��ø�λ֮�͡�
*/