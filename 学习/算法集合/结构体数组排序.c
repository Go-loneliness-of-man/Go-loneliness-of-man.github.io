#include <stdio.h>
//�Խṹ����������
struct xinxi { long long bh; char name[21]; char xb[3]; char addr[51]; };
struct xinxi bg[3] = {
	{ 201707020129,"С��","��", "����ʡ ������ ����" },
	{ 201707020106 ,"С��" ,"��","����ʡ ������ ��ľ��" },
	{ 201707020103 ,"С��" ,"Ů","������ ������" }
};
void order();												//���������� order()
int i, i2;													//ѭ������i��i2
int main()
{
	printf("����ѧ����������������ѧ�ţ��ÿո�ָ�: ");
	for (i = 0; i < 3; i++) { scanf_s("%lld", &bg[i].bh); };//��ȡѧ��
	order();												//����
	for (i = 0, i2 = 0; i < 3; i++, i2++)
	{
		printf("\n ѧ��: %lld\t ����: %s\t �Ա�: %s\t ��ס��: %s\n ", bg[i].bh, bg[i].name, bg[i].xb, bg[i].addr);
	}
	return 0;
}

void order()												//���������� order()
{
	struct xinxi ls;										//������ʱ�洢�Ľṹ����� ls
	for (i = 0; i < 2; i++)									//������ 2 ��
	{
		for (i2 = 0; i2 < 2 - i; i2++)						//ÿ�α������� 2 - i ��
		{
			if (bg[i2].bh > bg[i2 + 1].bh)					//�Ƚ�ѧ�ŵĴ�С
			{
				ls = bg[i2 + 1];							//�洢 bg[i+1] ������ֵ�� ls ��
				bg[i2 + 1] = bg[i2];						//�� bg[i] ��ֵת�� bg[i+1] ��
				bg[i2] = ls;								//�� bg[i+1] ��ֵת�� bg[i] ��
			}												//���һ�ν���
		}
	}
}
//Ҫע��Ƚϵ���ѧ�ţ����������������ṹ�������/t ��ʾ�Ʊ�����൱�� 8 ���ո�