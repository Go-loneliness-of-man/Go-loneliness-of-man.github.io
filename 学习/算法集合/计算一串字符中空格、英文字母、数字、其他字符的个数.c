#include<stdio.h>
char c;													//�洢�ַ����ı���
int words = 0, space = 0, num = 0, it = 0;				//�������ַ����ı���
int count(char x);										//��������ַ������ĺ��� count()
int main()
{
	printf("������һ������: ");
	count(c);											//�����ַ����� count() ����
	printf("��ĸ��:%d\n�ո���:%d\n������:%d\n�����ַ���:%d\n", words, space, num, it / 2);		//һ�������൱��2���ַ�
	return 0;
}
int count(char x)
{
	if (x >= 'a'&&x <= 'z' || x >= 'A'&&x <= 'Z')
		words++;
	else if (x == ' ')
		space++;
	else if (x >= '0' && x <= '9')
		num++;
	else
		it++;
	return (x = getchar()) == '\n' ? 0 : count(x);		//(x=getchar()) == '\n';ÿ�δӻ�������ȡһ���ַ���ֻҪû�����س�
}