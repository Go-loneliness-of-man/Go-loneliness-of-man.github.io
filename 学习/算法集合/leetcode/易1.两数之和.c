#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/
//��ʱ�����ֽⷨ�������������ַ������������������ݽ��ٵ���������ַ����������ݷǳ�������

/*
int* twoSum(int* nums, int numsSize, int target)
{
	int i, j, *b = (int*)malloc(sizeof(int) * 2);
	for (i = 0; (i < numsSize - 1); i++)
		for (j = i + 1; j < numsSize; j++)
			if (nums[i] + nums[j] == target)
			{
				b[0] = i;
				b[1] = j;
				return b;
			}
}
int main()
{
	int nums[4] = { 0,4,3,0 }, target = 0, *a;
	a = twoSum(nums, 4, target);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
˼·��������
��������Ͻ����жϣ����巽���ǣ��ӵ�һ��Ԫ�ؿ�ʼ���ֱ������Ԫ����ӣ��ж��Ƿ���Ŀ����ȣ�������洢�±�����������ӵڶ���Ԫ�ؿ�ʼ������
�����̣�ֱ���ҵ�Ϊֹ��
*/

//���ַ���
#define PD(x,y,z) ((nums[x]+nums[y])==z)

int *twoSum(int *nums, int numsSize, int target)
{
	int *b = (int*)malloc(sizeof(int) * 2), *c = (int*)malloc(sizeof(int)*numsSize);b[0] = b[1] = 100000;
	//�������ؽ���Ķ�̬���� b���洢����ԭ˳��Ķ�̬���� c
	int i, j, min, temp, l, r, mid;
	//ѭ������ i �� j������ min����ʱ���� temp�������������С��Ҷ˵� l �� mid �� r
	for (i = 0; i < numsSize; i++)		c[i] = nums[i];			//���� nums �� c
	for (i = 0; i < numsSize; i++)								//��С��������
	{
		for (j = min = i; j < numsSize; j++)
			if (nums[min] > nums[j])	min = j;
		if (min == i)		continue;
		temp = nums[i];
		nums[i] = nums[min];
		nums[min] = temp;
	}
	for (i = 0; i < numsSize; i++)								//���ζ�����Ԫ�ؽ��ж��ֲ���
	{
		b[0] = nums[i];		r = numsSize - 1;
		if (PD(i, r, target)) { b[1] = nums[r]; break; }		//�ж��Ҷ˵�
		for (l = i, mid = (l + r) / 2; mid != l; mid = (l + r) / 2)				//�� nums[i] ����һ�ζ��ֲ��ҡ�
		{
			if (PD(i, mid, target) && mid != l) { b[1] = nums[mid]; break; }	//�ж��е�
			if (nums[i] + nums[mid] > target)	r = mid;		//�ʹ���Ŀ�꣬�����Ҷ˵�
			else	l = mid;									//��С��Ŀ�꣬������˵�
		}
		if (b[0] + b[1] == target)	break;						//�ж��Ƿ��Ѳ��ҵ�����������
	}
	for (i = 0; i < numsSize; i++)								//ȷ����ԭ˳���£��������±�
		if (b[0] == c[i]) { b[0] = i; break; }
	for (i = 0; i < numsSize; i++)
		if (b[1] == c[i] && i != b[0]) { b[1] = i; break; }
	free(c);
	return b;
}

int main()
{
	int nums[4] = { -10, -1, -18, -19 }, target = -19, *a;
	a = twoSum(nums, 4, target);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
˼·�����ַ�����
�ȴ�С��������Ȼ�����һ�����顣����ʱ��ÿһ��Ԫ�ؽ��ж��ֲ��ң�����������Ƿ��������������һ���֡�
���ֲ��ң���ʼ�����Ը�Ԫ���±�Ϊ��˵㣬����ĩβΪ�Ҷ˵㡣ÿ���ж������е㣬������������������������㡣�Ƚ϶���֮����Ҫ�����ֵĴ�С����
������ȡ�ұ����������һ��ѭ��������ȡ����������ѭ����
*/