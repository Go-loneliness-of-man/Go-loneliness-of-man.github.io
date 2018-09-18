#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺

����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1:

���� nums = [3,2,2,3], val = 3,

����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2:

���� nums = [0,1,2,2,3,0,4,2], val = 2,

����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��

ע�������Ԫ�ؿ�Ϊ����˳��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

˵��:

Ϊʲô������ֵ��������������Ĵ���������?

��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�

����������ڲ���������:

// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeElement(nums, val);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
for (int i = 0; i < len; i++)
{
	print(nums[i]);
}
*/

//����˼·����һ��������Ȼ�������ƶ����ڶ����Ǳ���һ�Σ�ÿ���������޳���Ԫ��

//��һ�֣�
int removeElement(int* nums, int numsSize, int val)
{
	if (numsSize == 0)		return 0;
	int i, j, min, temp, c;
	for (i = 0; i < numsSize; i++)							//ѡ�����򣬴�С����
	{
		for (j = min = i; j < numsSize; j++)
			if (nums[min] > nums[j])	min = j;
		if (min == i)		continue;
		temp = nums[i];
		nums[i] = nums[min];
		nums[min] = temp;
	}
	for (i = 0, j = numsSize - 1; i < numsSize; i++)		//�� val �����ƶ�������ĩβ
		if (nums[i] == val)
		{
			for (; nums[i] == val && j > i; j--, i++)		//�������� val �� j <= i ʱֹͣ
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
			break;											//�ƶ���ϣ�����
		}
	for (i = numsSize - 1; nums[i] == val && i != 0; i--);	//ȷ�������� val �ĳ���
	if(nums[i]!=val)	return i + 1;						//���س���
	else return 0;
}
/*
˼·��
����Ȼ���ҵ� val ���������ƶ�������ĩβ���ٷ���ȥ����ĳ��ȼ��ɡ�
ע�⣺
*/
/*
//�ڶ��֣�
int removeElement(int *nums, int numsSize, int val)
{
	if (numsSize == 0)		return 0;
	int i, j;
	for (i = 0; i < numsSize; i++)							//��������
		if (nums[i] == val && i == numsSize - 1)			//���������һ��Ԫ�ص����
			return i;
		else if (nums[i] == val)							//��ƥ�䵽��ֵ�������Ԫ�ؽ�������ǰ��
		{
			for (j = i + 1; j < numsSize; j++)				//����ǰ��
				nums[j - 1] = nums[j];
			numsSize--;		i--;							//����ǰ��һλ��i ҲҪ��Ӧ��ǰ��һλ
		}
	return numsSize;
}
/*
˼·��
�������飬ÿ��ƥ�䵽��ֵ��������Ԫ��������ǰ��һλ����ƥ�䵽���һλ��������� val�����ȼ� 1 ���ؼ��ɡ�
ע�⣺
*/

int main()
{
	int x[100] = { 0, 1, 2, 2, 3, 0, 4, 2 }, val = 2;
	printf("%d", removeElement(x, 8, val));
	return 0;
}