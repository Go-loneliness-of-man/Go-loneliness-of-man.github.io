#include <stdio.h>
//ʹ�û�������ͬһ�����δ��ݲ�ͬ���ַ���
int  main()
{
	char c[100];
	int pd;
	for (pd = 1; pd;)
	{
		printf("\n �������ַ���: ");
		gets_s(c, 100);
		printf(" ��������ַ�����: %s\n", c);
		printf(" ��Ҫ���¸�ֵ������ 0 ������������: ");
		scanf_s("%d", &pd);
		getchar();					//scanf_s() ��������Ļس������룬���������س������´�ѭ��ʱ�� gets_s()��Ӱ��
	}
	return 0;
}