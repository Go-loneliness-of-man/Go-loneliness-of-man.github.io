#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
ԭ�⣺
ͳ������С�ڷǸ����� n ��������������

ʾ��:

����: 10
���: 4
����: С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��
*/

int countPrimes(int n)
{
	int nums[120000] = { 0 }, i, j, temp, x, len;	//�������顢ѭ������ i �� j����ʱ���� temp����� x���������� len
	for (i = nums[0] = 2, len = 0; i < n; i++)		//�ҳ� n ����������
	{
		for (j = 0, x = 1, temp = (int)sqrt(i) + 1; nums[j] < temp; j++)	//�������������ж� i �Ƿ�������
			if (i%nums[j] == 0)						//���ǣ��ı���
			{
				x = 0;
				break;
			}
		if (x)	nums[++len] = i;					//�ǣ���ӵ���������
	}
	return len;
}

int main()
{
	printf("%d", countPrimes(10));
	return 0;
}

/*
˼·��
����ɸ����ÿ����С�ڸ�������ƽ����������ɸѡ 2 ~ n ����������
*/