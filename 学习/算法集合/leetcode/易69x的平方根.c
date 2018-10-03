#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
ʵ�� int sqrt(int x) ������

���㲢���� x ��ƽ���������� x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842...,
���ڷ���������������С�����ֽ�����ȥ��
*/

int mySqrt(int x)
{
	if (x*x == x)	return x;
	long long left = 0, right = x, mid = x / 2;								//��������
	for (; mid != left; mid = (left + right) / 2)							//ѭ������
		if (mid*mid == x || ((mid + 1)*(mid + 1) > x) && mid*mid < x)
			return mid;
		else if (mid*mid > x)	right = mid;
		else if (mid*mid < x)	left = mid;
	return 0;																//��ʡ�ԣ�ֻ���Ժ� leetcode ��������ͨ��
}

int main()
{
	printf("%d", mySqrt(2147395599));
	return 0;
}

/*
˼·��
ƽ����һ��λ�� 0 ��������������ڣ���Ȼ�����䱾���������ģ��������ö��ֲ��Ҽ��ɡ�
����������mid ƽ������Ŀ��� mid ƽ��С��Ŀ�굫 mid + 1 ��ƽ���ִ���Ŀ�꣬�򷵻� mid��
*/