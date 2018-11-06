#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
*/

#define PD(x,y,z) ((numbers[x]+numbers[y])==z)

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
	int *b = (int*)malloc(sizeof(int) * 2);b[0] = b[1] = 10000;	//�������ؽ���Ķ�̬���� b
	int i, l, r, mid;	*returnSize = 2;
	//ѭ������ i �� j������ min����ʱ���� temp�������������С��Ҷ˵� l �� mid �� r
	for (i = 0; numbers[i] + numbers[numbersSize - 1] < target; i++);		//����ǰ�ν�С�Ĳ���
	if (i != 0)	i--;											//�����й���Ծ��i--
	for (; i < numbersSize; i++)								//���ζ�����Ԫ�ؽ��ж��ֲ���
	{
		b[0] = i + 1;		r = numbersSize - 1;
		if (PD(i, r, target)) { b[1] = r + 1; break; }			//�ж��Ҷ˵�
		for (l = i, mid = (l + r) / 2; mid != l; mid = (l + r) / 2)			//�� numbers[i] ����һ�ζ��ֲ��ҡ�
		{
			if (PD(i, mid, target) && mid != l) { b[1] = mid + 1; break; }	//�ж��е�
			if (numbers[i] + numbers[mid] > target)	r = mid;	//�ʹ���Ŀ�꣬�����Ҷ˵�
			else	l = mid;									//��С��Ŀ�꣬������˵�
		}
		if (PD(b[0] - 1, b[1] - 1, target))		break;			//�ж��Ƿ��Ѳ��ҵ�����������
	}
	return b;
}

int main()
{
	int nums[4] = { 2, 3, 4 }, target = 6, *a, *b = (int*)malloc(sizeof(int));
	a = twoSum(nums, 3, target, b);
	printf("%d %d", a[0], a[1]);
	free(a);
	return 0;
}
/*
˼·����Ȼ���Ѿ������������ˣ��Ǻ����Կ���ʹ�ö��ַ������ҡ�
����ǰ������������ǰ�ι���С�Ĳ��֣�Ȼ���ÿһ��Ԫ�ؽ��ж��ֲ��ң�����������Ƿ��������������һ���֡�
���ֲ��ң���ʼ�����Ը�Ԫ���±�Ϊ��˵㣬����ĩβΪ�Ҷ˵㡣ÿ���ж������е㣬������������������������㡣�Ƚ϶���֮����Ҫ�����ֵĴ�С����
������ȡ�ұ����������һ��ѭ��������ȡ����������ѭ����
*/