#include<stdio.h>
#include<Windows.h>
//ģ������������һ��һ��������һ���������д�ӡ˼�룬��ӡ���������ȫ�������
int y, i, j, p, week, day, yue[12] = { 31,28,31,30,31,30,31,31,31,30,31,30 };
//�������� y���� i���� j������ week��һ��ĵڼ��� day���ж��Ƿ�������� p��ÿ���µ����� yue[]
char year[3];
void switchs(int x);														//�����Ǵ�ӡÿ�µĵ�һ��
int main()
{
	for (p = 1; p;)
	{
		printf("\n  ��������ݣ� ");
		scanf_s("%d", &y);
		y % 4 == 0 ? strcpy_s(year, 3, "��") : strcpy_s(year, 3, "ƽ");		//�ж���������ǡ����껹�ǡ�ƽ�ꡱ
		if (y % 4 == 0) yue[1] = 29;										//���ö��µ�����Ϊ������
		printf("\n  %d ���� %s �꣬������һ��һ��������һ�������������£�\n\n", y, year);
		for (week = 1, day = 1, i = 0; i < 12; i++)							//��ӡһ���������
		{
			printf("  %d ��\t\t��\tһ\t��\t��\t��\t��\t��\n", i + 1);			//���ÿ���µ��ײ�
			for (j = 1; j <= yue[i]; j++, week++, day++)					//��ӡһ���µ�����
			{
				if (j == 1) switchs(day);									//ȷ�����·ݵ�һ���λ��
				if (j != 1) printf("%d\t", j);								//��ӡ���·�ʣ�µ�����
				if (week == 8) week = 1;									//�������ں�
				if (week == 6) printf("\n    \t\t");						//���С�����
			}
			printf("\n\n");													//�·ݼ任��
		}
		printf("�Ƿ���������ǣ������������֣��������� 0��");						//ѯ���Ƿ����
		scanf_s("%d", &p);
		system("cls");														//����
	}
	return 0;
}
void switchs(int x)															//ȷ��ÿ�µ�һ���λ��
{
	printf("    \t\t");														//��ӡ��ͷ����
	for (int n = x % 7; n; n--) printf("  \t");								//��ӡ�м�Ĳ���
	printf("%d\t", j);														//��ӡ����
}