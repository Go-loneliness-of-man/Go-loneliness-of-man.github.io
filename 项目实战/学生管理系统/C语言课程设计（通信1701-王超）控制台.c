#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
/*
**�������ƣ�							����ѧ����Ϣ����ϵͳ������̨�棩

********************************************** ���� *********************************************************

	¼�롢��ӡ����ѧ����Ϣ			���ң���ѧ�š�������ѧ��			�޸ġ�ɾ��������ѧ����Ϣ			�˳�ϵͳ

	�������Ŀƽ���֡�ͳ�Ƽ����ʣ�����ֿ��Զ��壩���������������		����ѧ�Ŵ�С����Ŀ�ɼ��ȶ�ѧ����������
	
	ϵͳ�����˻��������룬���޸ģ����һ�

	*** ��ʼ�˻�����123 ***			*** ��ʼ���룺123 ***

************************************************************************************************************

**���뻷����			Visual Studio 2015	&&	Win 7
**�����ߣ�			����ʯ�ʹ�ѧ����ͨ��1701��������
**Ӧ��֪ʶ��			C ���ԡ�Windows API������̨��δӦ�ã������ݽṹ��˫������
**��һ��������ڣ�		1.0 ��	2018 �� 7 �� 2 ��
**��ǰ�汾�ţ�			1.1 ��
**���£�				������Ŀ���ݽṹΪ˫����������΢������������
**��Ȩ������			������ɱ��˶���������δ������������������ҵ��;��������Ȩ����ͨ���Ϸ�;��άȨ��
*/

typedef struct students {			//ѧ����Ϣ 
	char id[31];					//ѧ��
	char name[21];					//����
	char xb[9];						//�Ա�
	char age[10];					//����
	char sfz[31];					//���֤����
	char addr[101];					//��ͥסַ
	char phone[21];					//�ֻ���
	char class[41];					//�꼶���༶
	double score[11];				//���ƿ��Գɼ�,˳���������Ӣ����������������ʷ���ء��ܷ֡�ƽ����
	struct students *next;			//ָ����һ�����
	struct students *last;			//ָ����һ�����
}s;

s *head,*tail;						//ͷָ�롢βָ�룬�ֱ�ָ���ͷ��β���

//********************************************************************************** �����ͺ�������

int strbj(char* x, char* y);						//�ַ����ȽϺ�������ͬ����ֵΪ 1����ͬ����ֵΪ 0

void ui();											//��ӡ�û� UI

s *new(char *id, char *name, char *xb,char *age, char *sfz, char *addr, char* phone, char* class, double *score);
													//�½�һ��ѧ���ṹ�壬�������ݣ������½��Ľṹ���ַ

void scp(char* x, char* y, int size);				//�ַ������ƺ������� y ���Ƶ� x �У�size ����󳤶�

int write(s *x);									//�洢��������һ��

int strc(char *x);									//����һ���ַ����ĳ��ȣ������� '\0'������ֵ������

s *cz(s *x, char *y);								//�����������ؾ���ָ��ѧ�ŵĽ���ַ

//���ؾ���ָ��������ѧ����Ϣ����ָ����㿪ʼ�����������������ҵ��ĵ�һ��ƥ����ĵ�ַ
s *czn(s *x, char *y);

void opoint(s *x);									//��ӡһ������������Ϣ

int scbj(char *x, char *y);							//�Ƚ����ַ������ֵĴ�С����ǰ�ߴ��ں��߷��� 1������ 0

void jh(s* x, s *y);								//����������������

s *lbcz(s *x, int y);								//��ָ����������ң��������������/��Сѧ�ŵĽ���ַ��1 ���2��С

void order(s *x, int y);							//���������������ַ� 1 ���򣨴Ӵ�С�����ַ� 2 ���򣨴�С����

s* lbcz2(s* x, int y, int z);						//����Ŀ���ҡ�ͷָ�롢�����򡢿�Ŀ����

void order2(s *x, int y, int z);					//����Ŀ����ͷָ�롢�����򡢿�Ŀ����

double pjz(s *x, int y);							//����һ�ſ�Ŀ��ƽ��ֵ

//************************************************************************************* �ṹ�ͺ�������

void login(), read(s *x), get(), del(), reset(), czmk(), out(s *x), orders(), tj(), infix(), revise()
	 , exits(), lfor();
/*
  �����ǵ�¼ģ�顢��ȡ�����ļ�����������ģ�顢����ѧ����Ϣģ�顢��ѧ��ɾ��ģ�顢�޸�ѧ����Ϣģ�顢����������ģ�顢
  ��ӡ������Ϣģ�顢����������ģ�顢ͳ��ģ�顢����ѧ����Ϣģ�顢�޸��˻�������ģ�顢�˳�ϵͳģ�顢
  �ܱ����������˻�������ģ�顢
*/
char user[101] = "123", password[101] = "123\r";		//��ʼ�˻���������

//************************************************************************************ ��������ʼ

int main()
{
	head = (s*)malloc(sizeof(s));						//������ͷ
	head->next = NULL;									//��ʼ����ͷ next ��Ա
	system("mode con cols=130");						//���ڿ��
	system("mode con lines=600");						//���ڸ߶ȣ��ɹ�����
	system("color F6 ");								//ǰ��ɫ������ɫ
	login();											//��¼ģ��
	read(head);											//��ȡ�����ļ�ģ��
	for (; 1;)
	{
		int pd;
		ui();
		scanf_s("%d", &pd);								//���û��жϹ���ѡ��ģ��
		getchar();										//�����س����Խ������������е�Ӱ��
		system("cls");									//���������´�ӡһ��
		switch (pd)
		{
			case 1:	get();	break;						//��������ģ��
			case 2: del();	break;						//����ɾ��ģ��
			case 3: reset();  break;					//�����޸�ģ��
			case 4: czmk();	break;						//���ò���ģ��
			case 5: out(head);	break;					//�������ȫ����Ϣģ��
			case 6: orders();  break;					//��������ģ��
			case 7: tj();	break;						//����ͳ��ģ��
			case 8: infix();  break;					//���ò���ģ��
			case 9: revise();	break;					//�����޸��˻�ģ��
			case 0: exits(); break;						//�����˳�ģ��
		}
		system("cls");									//���������´�ӡһ��
	}
	return 0;
}

//*********************************************************************************** �����ͺ�������

void ui()													//��ӡһ���û� UI
{
	printf("\n\n                                 ��Ȩ������ ������ɱ��˶���������δ�����������ֹ������ҵ��;����\n            "
		   "                                ����Ȩ����ͨ������;��άȨ��");
	printf("\n\n                                 �汾�ţ�1.0 | ����̨�� | ͼ�ν���Ŀǰ������ . . .");
	printf("\n\n                                 ��������ߣ� ����ʯ�ʹ�ѧ ���� ͨ�� 1701 ���� ����");
	printf("\n\n                                      �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n"
		   "                                      ��                                     ��\n"
		   "                                      ��        ����ѧ����Ϣ����ϵͳ         ��\n"
		   "                                      ��                                     ��\n"
		   "                                      �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n\n"
		   "                                        ����ѡ�\n\n"
		   "                                         1. ����ѧ����Ϣ\n\n"
		   "                                         2. ������ɾ��ѧ����Ϣ\n\n"
		   "                                         3. �޸�ĳѧ����Ϣ\n\n"
		   "                                         4. ����������ѧ����Ϣ\n\n"
		   "                                         5. ��ӡ�������ѧ����Ϣ\n\n"
		   "                                         6. ������������ѧ����Ϣ��������\n\n"
		   "                                         7. ��ƽ���֡������ʡ�����������\n\n"
		   "                                         8. ��ĳѧ�������ѧ����Ϣ\n\n"
		   "                                         9. �޸��˻���������\n\n"
		   "                                         0. �˳�\n\n"
		   "                                 ע���벻Ҫֱ�ӵ�����ڹرճ���ͨ��������ر����ͷų���ռ�õ���\n"
		   "                                     �棬�ܱ����˷ѵ����ڴ�ռ�\n\n"
		   "                                        �밴�¶�Ӧ����ѡ���ܣ� ");
}

int strbj(char* x, char* y)									//�ַ����ȽϺ���
{
	int i;													//����ѭ������
	for (i = 0; x[i] == y[i]; i++)							//ֻҪ���ַ�����Ӧ�ַ���ͬ���ͼ���ѭ��
		if (x[i] == '\0' && y[i] == '\0')					//������ '\0' ʱ��������ͬ��ͬʱ������Ҳ��ͬ
			return 1;										//��ͬ������ֵΪ 1
	return 0;												//ѭ����δ�����ַ���ʱ����������ͬ������ֵΪ 0
}

void scp(char *x, char *y, int size)						//�ַ������ƺ������� y ���Ƶ� x �У�size ����󳤶�
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

//�½�һ����㣬�������ݣ������½��Ľ���ַ
s *new(char *id, char *name, char *xb,char *age, char *sfz, char *addr, char* phone, char* class, double *score)
{
	s *stdp = (s*)malloc(sizeof(s));						//����һ���½�㣬�洢���ַ�� stdp
	stdp->next = NULL;										//��ʼ���½��� next
	stdp->last = NULL;										//��ʼ���½��� last
	scp(stdp->id, id, 31);
	scp(stdp->name, name, 21);
	scp(stdp->xb, xb, 9);
	scp(stdp->age, age, 10);
	scp(stdp->sfz, sfz, 31);
	scp(stdp->addr, addr, 101);
	scp(stdp->phone, phone, 21);
	scp(stdp->class, class, 41);
	for (int i = 0; i < 11; i++)
		stdp->score[i] = score[i];
	return stdp;
}

int write(s *x)												//������������һ��
{
	FILE *f;												//�����ļ�ָ��
	f = fopen("data.txt", "wb+");							//���´������������ļ�
	if ((x->next) == NULL)									//����Ϊ�գ�ֹͣд��
	{
		fclose(f);											//�ر��ļ�
		return 0;
	}
	for (x = x->next; 1; x = x->next)						//ѭ��������������д���ļ�
	{
		fwrite(x, sizeof(s), 1, f);							//д��һ�����
		if (x->next == NULL) break;							//��������Ƿ�д����ϣ����ǣ�����
	}
	fclose(f);												//�ر��ļ�
	return 0;
}

int strc(char *x)											//����һ���ַ����ĳ��ȣ������� '\0'
{
	int i;
	for (i = 0; x[i] != '\0'; i++);
	return i;
}

s *cz(s *x, char *y)										//�����������ؾ���ָ��ѧ�ŵĽ���ַ���ָ��
{
	if (x->next == NULL)	return NULL;					//��ͷ next ��Ա��Ϊ�գ����� NULL
	for (x = x->next; 1; x = x->next)						//ѭ�����������������������
	{
		if (strbj(x->id, y)) break;							//����Ƿ������ָ����㣬���ǣ�����
		if (x->next == NULL) break;							//�ѵ�β��㣬����
	}
	if (x->next == NULL && !(strbj(x->id, y)))				//��������һ�������ѧ�Ų�ͬ��ָ��ѧ�ţ����� NULL
		return NULL;
	else													//���ѧ����ָ��ѧ����ͬ�����ؽ���ַ
		return x;											//���ز��ҵ��Ľ������һ�����ĵ�ַ
}

s *czn(s *x, char *y)
{
	if (strbj(x->id, "0"))	return NULL;					//�����ļ�Ϊ�գ����� NULL
	for (x = x->next; x->next != NULL; x = x->next)			//ѭ�����������������������δ�ҵ�ƥ���㣬����
	{
		if (strbj(x->name, y)) break;						//����Ƿ������ָ����㣬���ǣ�����
	}
	if (x->next == NULL && !(strbj(x->name, y)))			//��������һ�������������ͬ��ָ������������ NULL
		return NULL;
	else													//���������ָ��������ͬ�����ؽ���ַ
		return x;											//���ز��ҵ��Ľ������һ�����ĵ�ַ
}

void opoint(s *x)											//��ӡһ������������Ϣ
{
	int i;													//���ڴ�ӡ��ѭ������ i
	printf("\n  ѧ�ţ�%s\n  ������%s\t�Ա�%s\t���䣺%s\n  ���֤���룺%s\n  ��ͥסַ��%s\n  �ֻ��ţ�%s\t\t�꼶���༶��%s\n"
			, x->id, x->name, x->xb, x->age, x->sfz, x->addr, x->phone, x->class);
	printf("  ����  ��ѧ  Ӣ��  ����  ��ѧ  ����  ����  ��ʷ  ����  �� ��  ƽ �� ��\n   ");
	for (i = 0; i < 10; i++)
	{
		if (x->score[i] < 10)
			printf("0%g    ", x->score[i]);
		else
			printf("%g    ", x->score[i]);
	}
	printf(" %.1lf", x->score[i]);
}

int scbj(char *x, char *y)									//�Ƚ����ַ������ֵĴ�С����ǰ�ߴ��ں��߷��� 1������ 0
{
	if (strc(x) > strc(y))	return 1;						//ǰ�߳��ȴ��ں��ߣ�ǰ�ߴ󣬷��� 1
	else if(strc(x) < strc(y))  return 0;					//ǰ�߳���С�ں��ߣ����ߴ󣬷��� 0
	else													//ǰ������߳�����ȣ�������ѭ���Ƚ�ÿһλ�����ֵĴ�С
	{
		char a = *x, b = *y;
		for (; x != '\0'&&y != '\0';x++,y++,a = *x,b = *y)  //������һλ��ʼ�Ƚ�
		{
			if (a > b)
				return 1;
			else if (a < b)
				return 0;
			else if (a == b && (*(x + 1)) == (*(y + 1)))
				return 0;
		}
	}
}

void jh(s *x,s *y)											//��������������򣬵����ı� next ��Ա
{
	s *temp = (s*)malloc(sizeof(s)), *a = x->next, *b = y->next;
	*temp = *y;
	*y = *x;
	*x = *temp;
	x->next = a;
	y->next = b;
	free(temp);
}

//��ָ����������ң��������������/��Сѧ�ŵĽ��ĵ�ַ��1 ���2��С
s *lbcz(s *x,int y)
{
	s *cz, *bj;													//���ڲ��ҵ�ָ��
	if (x->next == NULL)	return NULL;						//�����ѵ��յ㣬����
	cz = x;														//����ָ�뿪ʼ������ʼ���
	if (y == 1)													//�ҳ������
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (scbj(cz->id, bj->id))	bj = cz;				//����ǽ��С�ڲ��ҽ�㣬����ָ���ָ��
			if (cz->next == NULL)	break;						//�����ѵ��յ㣬����
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
	else if (y == 2)											//�ҳ���С��
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (scbj(bj->id, cz->id))	bj = cz;				//����ǽ����ڲ��ҽ�㣬����ָ���ָ��
			if (cz->next == NULL)	break;						//�����ѵ��յ㣬����
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
}

//ѡ������
void order(s *x, int y)										//����������������ֵ 1 ���򣨴Ӵ�С����2 ���򣨴�С����
{
	s *jhstd;												//���ڽ�����ָ��
	x = x->next;											// x ָ���ƶ�����һ���洢��Ϣ�Ľ��
	for (jhstd = x; 1;x = x->next)							//ÿ��ͷָ�봦�ڴ�������㣬jhstd ���ҳ�ʣ�ಿ�������
	{
		if (x->next == NULL)
		{
			tail = x;										//����βָ��
			break;											//����ĩβ������
		}
		jhstd = lbcz(x, y);									//���ҳ� x ���󷽵ľ������ѧ�ŵĽ��
		if (jhstd != NULL)	jh(x, jhstd);					//���ҵ����򽻻������������
	}
}

//��ָ����������ң��������������/��Сֵ�Ľ��ĵ�ַ��1 ���2��С
s* lbcz2(s* x, int y, int z)									//����Ŀ���ң�ͷָ�롢�����򡢿�Ŀ����
{
	s *cz, *bj;													//���ڲ��ҵ�ָ��
	if (x->next == NULL)	return NULL;						//�����ѵ��յ㣬����
	cz = x;														//���ҽ�㿪ʼ������ʼ���
	if (y == 1)													//�ҳ������
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (bj->score[z] < cz->score[z])	bj = cz;		//����ǽ��С�ڲ��ҽ�㣬����ָ���ָ��
			if (cz->next == NULL)	break;						//�����ѵ��յ㣬����
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
	else if (y == 2)											//�ҳ���С��
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (bj->score[z] > cz->score[z])	bj = cz;		//����ǽ����ڲ��ҽ�㣬����ָ���ָ��
			if (cz->next == NULL)	break;						//�����ѵ��յ㣬����
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
}

//����������������ֵ 1 ���򣨴Ӵ�С����2 ���򣨴�С����
void order2(s *x, int y, int z)								//����Ŀ����ͷָ�롢�����򡢿�Ŀ����
{
	s *jhstd;												//���ڽ�����ָ��
	x = x->next;											// x ָ���ƶ�����һ���洢��Ϣ�Ľ��
	for (jhstd = x; 1; x = x->next)							//ÿ��ͷָ�봦�ڴ�������㣬jhstd ���ҳ�ʣ�ಿ�������
	{
		if (x->next == NULL)
		{
			tail = x;										//����βָ��
			break;											//����ĩβ������
		}
		jhstd = lbcz2(x, y, z);								//���ҳ� x ���󷽵ľ������ѧ�ŵĽ��
		if (jhstd != NULL)	jh(x, jhstd);					//���ҵ����򽻻������������
	}
}

double pjz(s *x, int y)										//����һ�ſ�Ŀ��ƽ��ֵ
{
	int i;	 double add;									//ѭ����������
	for (i = 0, add = 0, x = x->next; 1; x = x->next)		//ѭ�����
	{
		add += x->score[y];
		i++;
		if (x->next == NULL)	break;
	}
	return (add / i);										//����ƽ��ֵ������
}

//***************************************************************************************** �ṹ�ͺ�������

void login()													//��¼ģ��
{
	char user2[101], password2[101];		int a, b, bj = 1;
	FILE *f;													//�����ļ�ָ��
	f = fopen("user.txt", "rb");								//��ֻ����ʽ���û��ļ���
	fread(&a, sizeof(int), 1, f);								//��ȡ�˻����ĳ���
	fread(&b, sizeof(int), 1, f);								//��ȡ����ĳ���
	fread(user, sizeof(char), a, f);							//��ȡ�˻���
	fread(password, sizeof(char), b, f);						//��ȡ����
	fclose(f);
	printf("\n\n\n\n\n\n\n                                 ��¼����Ա�˻�����ʼ�˻����������Ϊ 123��������ֻ��һ�������룬�����˸�\n\n"
		   "                                 �������˻����� ");
	gets_s(user2, 101);
	if (strbj(user, user2))
		printf("\n                                 �˻���������ȷ\n");
	else
	{
		int pd;
		printf("\n                                 �˻���������ʹ���ܱ����������˻������� 1�������˳��� ");
		scanf_s("%d", &pd);		getchar();
		if (pd == 1)
		{
			lfor();
			bj = 0;
		}
		else
			exit(0);
	}
	if (bj != 0)
	{
		printf("\n                                 ���������룺");
		for (int i = 0; 1; i++)
		{
			password2[i] = _getch();
			if (password2[i] == '\r')
			{
				password2[i + 1] = '\0';
				break;
			}
			printf("*");
		}
		if (strbj(password, password2))
			printf("\n\n                                 ����������ȷ\n\n                                 ��¼ . . .");
		else
		{
			int pd;
			printf("\n\n                                 ���������ʹ���ܱ����������˻������� 1�������˳��� ");
			scanf_s("%d", &pd);		getchar();
			if (pd == 1)
				lfor();
			else
				exit(0);
		}
	}
	Sleep(500);
	system("cls");
}

void read(s *x)													//��ȡ�����ļ�ģ��
{
	FILE *f;													//�����ļ�ָ��
	if ((f = fopen("data.txt", "ab+")) != NULL)					//�򿪻��½������ļ�
		printf("\n\n\n\n\n                                 �������ļ� . . .");
	Sleep(500);
	printf("\n\n                                 ���������ļ� . . .");
	Sleep(500);
	x->next = (s*)malloc(sizeof(s));							//�ڱ�ͷ���½�һ���ս��
	scp((x->next)->id, "0", 2);									//��ǿս�㣬���ڽ������ж������ļ��Ƿ�Ϊ��
	//ÿ��ѭ���ڱ�β����һ���ս�㲢����ָ��ָ��ս�㣬ѭ����ȡ��������
	s *xq = head;												//��ǰ����ǰһ���
	for (x = x->next; 1; xq = x, x = x->next)
	{
		fread(x, sizeof(s), 1, f);								//��ȡһ���ṹ�壬�������ս����
		x->last = xq;											//ָ����һ���
		if (x->next == NULL) break;								//��������Ƿ��ȡ��ϣ����ǣ�����
		x->next = (s*)malloc(sizeof(s));						//�ڱ�β���һ���ս�㣬�Ա��´�ѭ����ֵ
	}
	tail = x;													//��βָ��ָ���β
	if (strbj(tail->id, "0"))									//����ͬ������ֵΪ 1�������ļ�Ϊ��
		printf("\n\n                                 �����ļ�Ϊ��");
	else
		printf("\n\n                                 ��ȡ�����ļ����");
	fclose(f);
	Sleep(1000);
	system("cls");
}

void get()														//����ѧ����Ϣģ��
{
	int pd;														//�ж��Ƿ����¼��
	for (pd = 1; pd;)
	{
		//ѭ������ i��������ʱ��㲢�����ַ���ظ� std������ָ�� temp
		int i;	s *std = (s*)malloc(sizeof(s)), *temp;
		//��ʼ��ȡ����
		printf("\n  ����¼��һ��ѧ������Ϣ��ÿ����һ�һ�λس�����\n\n");
		for (; 1;)
		{
			printf("  ѧ�ţ� ");
			gets_s(std->id, 31);
			if (cz(head, std->id) != NULL)
				printf("\n  ѧ��������ѧ���ظ������������룡\n\n");
			else if (strc(std->id) == 0)
			{
				printf("\n  ѧ�Ų���Ϊ�գ����������룡\n\n");
				printf("  ѧ�ţ� ");
				gets_s(std->id, 31);
			}
			else
				break;
		}
		printf("  ������ ");
		gets_s(std->name, 21);
		printf("  �Ա� ");
		gets_s(std->xb, 9);
		printf("  ���䣺 ");
		gets_s(std->age, 10);
		printf("  ���֤�� ");
		gets_s(std->sfz, 31);
		printf("  ��ͥסַ�� ");
		gets_s(std->addr, 101);
		printf("  �ֻ��ţ� ");
		gets_s(std->phone, 21);
		printf("  �꼶���༶�� ");
		gets_s(std->class, 41);
		printf("  ���ڿ�ʼ¼��ѧ�����Գɼ���\n");
		printf("\n  ���ģ� ");
		scanf_s("%lf", &std->score[0]);	getchar();
		printf("\n  ��ѧ�� ");
		scanf_s("%lf", &std->score[1]);	getchar();
		printf("\n  Ӣ� ");
		scanf_s("%lf", &std->score[2]);	getchar();
		printf("\n  ���� ");
		scanf_s("%lf", &std->score[3]);	getchar();
		printf("\n  ��ѧ�� ");
		scanf_s("%lf", &std->score[4]);	getchar();
		printf("\n  ��� ");
		scanf_s("%lf", &std->score[5]);	getchar();
		printf("\n  ���Σ� ");
		scanf_s("%lf", &std->score[6]);	getchar();
		printf("\n  ��ʷ�� ");
		scanf_s("%lf", &std->score[7]);	getchar();
		printf("\n  ���� ");
		scanf_s("%lf", &std->score[8]);	getchar();
		for (i = 0, std->score[9] = 0; i < 9; i++) std->score[9] += std->score[i];		//�����ܷ�
		std->score[10] = std->score[9] / 6.0;											//����ƽ����
		//��ȡ������ϣ�����������һ���½�㱣����ʱ����������ݣ��ٽӵ�����ĩβ
		if (strbj((head->next)->id, "0"))
		//�������ģ�������������ļ�ʱ�������Ŀ�β������⣬��������ǣ�������������յ�β��㣬�½�һ����㲢��ֵ���ڱ�ͷ��
		{
			head->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
			tail = head->next;									//����β����ַ
			tail->last = head;									//last ָ���ͷ
		}
		else
		{
			tail->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
			temp = tail;										//��ʱ���浱ǰ����ַ
			tail = tail->next;									//����βָ��ָ��
			tail->last = temp;									//last ָ����һ���
		}
		free(std);												//¼����ϣ��ͷ���ʱ���ռ�õ��ڴ�
		printf("\n\n  ��Ҫ����¼����һ��ѧ����Ϣ�������������֣���Ҫ���������������� 0�� ");
		scanf_s("%d", &pd);		getchar();
		system("cls");
	}
	write(head);												//����һ����������
	printf("\n\n  ����������ѧ����Ϣ�ѱ��棬1 ��󷵻�������");
	Sleep(1000);
}

void out(s *x)													//��ӡģ��
{
	int i;														//���ڴ�ӡ��ѭ������ i
	printf("\n  ����ѧ����Ϣ����:");
	if (strbj((x->next)->id, "0"))								//�ж��������ļ��Ƿ�Ϊ�գ����ǣ�����ӡ
		printf("\n\n  ����û��¼��ѧ����Ϣ\n  ");
	else if (x->next == NULL)
		printf("\n\n  ����û��¼��ѧ����Ϣ\n  ");
	else														//�����ļ���Ϊ�գ���ӡ
	{
		int count;												//ͳ������
		for (x = x->next, count = 1; 1; x = x->next, count++)	//ѭ������ӡ������������н��
		{
			printf("\n\n  ѧ�ţ�%s\n  ������%s\t�Ա�%s\t���䣺%s\n  ���֤���룺%s\n  ��ͥסַ��%s\n  �ֻ��ţ�%s\t\t�꼶���༶��%s\n"
					, x->id, x->name, x->xb, x->age, x->sfz, x->addr, x->phone, x->class);
			printf("  ����  ��ѧ  Ӣ��  ����  ��ѧ  ����  ����  ��ʷ  ����  �� ��  ƽ �� ��\n   ");
			for (i = 0; i < 10; i++)
			{
				if (x->score[i] < 10)
					printf("0%g    ", x->score[i]);
				else
					printf("%g    ", x->score[i]);
			}
			printf(" %.1lf", x->score[i]);
			if (x->next == NULL) break;							//����Ƿ��Ѵ�ӡ�������������ǣ�����
		}
		printf("\n\n  ���� %d ��", count);
	}
	printf("\n\n  ���س�������������");
	getchar();
}

void revise()													//�޸��˻���������ģ��
{
	char user2[101], password2[101], ques[101], as[101];
	printf("\n  �޸ĺ�������˻��������룡");
	for (; 1;)													//�Աȵ�ǰ�˻���
	{
		printf("\n\n  �����뵱ǰ�˻����� ");
		gets_s(user2, 101);
		if (strbj(user, user2))
		{
			printf("\n  �˻���������ȷ");							//��ȷ����������ʼ�޸�
			break;
		}
		else
		{
			printf("\n  �˻��������������������\n\n  ");
			system("cls");
		}
	}
	printf("\n\n  �������޸ĺ���˻������ɰ��������ַ����� ");
	gets_s(user, 101);
	printf("\n  �޸ĳɹ�����ǰ�˻����ǣ�%s", user);
	for (; 1;)
	{
		printf("\n\n  �����뵱ǰ���룬ֻ��һ�������룬�����˸�");
		for (int i = 0; 1; i++)
		{
			password2[i] = _getch();
			if (password2[i] == '\r')
			{
				password2[i + 1] = '\0';
				break;
			}
			printf("*");
		}
		if (strbj(password, password2))							//�Ƚ������Ƿ���ȷ
		{
			printf("\n\n  ����������ȷ\n\n  ");
			break;
		}
		else
			printf("\n\n  ���������������������\n\n  ");
	}
	printf("�������޸ĺ�����루�ɰ��������ַ�����ֻ��һ�������룬�����˸� ");
	for (int i = 0; 1; i++)
	{
		password[i] = _getch();
		if (password[i] == '\r')
		{
			password[i + 1] = '\0';
			break;
		}
		printf("*");
	}
	printf("\n\n  �޸�����ɹ�!\n\n");
	printf("  �����������ܱ����⣬����������������˻��������룺\n\n  ");
	gets_s(ques, 101);
	printf("\n  �����������ܱ�����Ĵ𰸣�\n\n  ");
	gets_s(as, 101);
	printf("\n  ���óɹ�!");
	FILE *f;													//�����ļ�ָ��
	f = fopen("user.txt", "wb+");								//���´����û��ļ���
	int a = strc(user), b = strc(password);						//�ֱ��������߳���
	int c = strc(ques), d = strc(as);							//�ܱ�����ʹ𰸵ĳ���
	fwrite(&a, sizeof(int), 1, f);								//�������˻�������
	fwrite(&b, sizeof(int), 1, f);								//���������볤��
	fwrite(user, sizeof(char), strc(user), f);					//д�����˻���
	fwrite(password, sizeof(char), strc(password), f);			//д��������
	fwrite(&c, sizeof(int), 1, f);								//�����ܱ����ⳤ��
	fwrite(&d, sizeof(int), 1, f);								//����𰸳���
	fwrite(ques, sizeof(char), strc(ques), f);					//д���ܱ�����
	fwrite(as, sizeof(char), strc(as), f);						//д���
	fclose(f);
	printf("\n\n  �ѱ���������ݣ����س�������������");
	getchar();
}

void czmk()														//����ģ��
{
	int pd;
	printf("\n  ��ѡ����ҷ�ʽ�������������������� 0������ѧ�š��������� 1�� ");
	scanf_s("%d", &pd);		getchar();
	if (pd)
	{
		char id2[31];	s *czstd;								//�����Ա��ַ���������ָ��
		printf("\n  ������Ҫ���ҵ�ѧ����ѧ�ţ� ");
		gets_s(id2, 31);
		czstd = cz(head, id2);									//����ָ��ѧ�ŵ�ѧ�����ҵ����ؽ���ַ��δ�ҵ����� NULL
		if (czstd != NULL)
			opoint(czstd);										//������ҵ��ĵ������
		else
			printf("\n  δ���ҵ����и�ѧ�ŵ�ѧ���������ļ�Ϊ��");		//���δ�ҵ������
		printf("\n\n  �밴�س�������������");
		getchar();
	}
	else
	{
		char name2[21];		s *czstd = head;					//�����Ա��ַ���������ָ��
		printf("\n  ������Ҫ���ҵ�ѧ��������������ҳ�����ͬ����ѧ������ ");
		gets_s(name2, 21);
		if ((czstd = czn(head, name2)) != NULL)
		{
			printf("\n  ���ҵ����и�������ѧ�����£�\n");
			for (; czstd != NULL; czstd = czn(czstd, name2))	//ѭ����ӡ������ͬ��ѧ��
			{
				opoint(czstd);
				printf("\n");
			}
		}
		else
			printf("\n  δ���ҵ����и�������ѧ���������ļ�Ϊ��");		//���δ�ҵ������
		printf("\n  �밴�س�������������");
		getchar();
	}
}

void del()
{
	char id2[31];	int pd;		char enter[6];
	printf("\n  ɾ������ѧ����Ϣ������ 1������ɾ��ѧ����Ϣ������ 2��ɾ������ѧ����Ϣ������ 3��  ");
	scanf_s("%d", &pd);		getchar();
	if (pd == 1)												//ɾ��������ѧ����Ϣ
	{
		s *stdq;												//�洢ƥ�����ǰһ�����ĵ�ַ
		printf("\n  ������Ҫɾ����ѧ����ѧ�ţ� ");
		gets_s(id2, 31);
		stdq = (cz(head, id2))->last;							//�ҵ�ƥ�����ǰһ�����ĵ�ַ
		if (stdq == NULL)
			printf("\n  û��ƥ�䵽���и�ѧ�ŵ�ѧ��");
		else
		{
			opoint(stdq->next);
			printf("\n\n  ƥ�䵽��ѧ����ȷ��Ҫɾ��ô��"
				   "\n\n  ȷ��ɾ���������ַ�����Enter�����������������ַ������룺 ");
			gets_s(enter, 6);
			if (strbj(enter, "Enter"))
			{
				//ʹƥ�����ǰһ�����ֱ��������һ����㣬������ƥ���㣬�ﵽɾ��Ŀ��
				stdq->next = (stdq->next->next);
			}
			else
				printf("\n  ��ɾ����ѧ����Ϣ");
		}
	}
	else if (pd == 2)													//ɾ��һ����Χ�ڵ�ѧ����Ϣ
	{
		char id3[31];	s *stdq = head, *stdq2, *stdq3;
		printf("\n  ������������ʼѧ�ź���ֹѧ�ţ�һ���ո��������ֹѧ�Ų������������ѧ�ţ���\n  ���ߺ�ѧ������֮���ѧ��"
			   "��Ϣ���ᱻɾ����������ѧ�ţ�  ");
		scanf_s("%s %s", id2, 31, id3, 31);		getchar();
		order(head, 2);
		if (scbj(id3, tail->id) || scbj(id2, tail->id))
			printf("\n  ѧ�Ų����������ݷ�Χ֮�ڣ�");
		else
		{
			stdq2 = stdq = (cz(head, id2))->last;						//���� id2 ǰһ����ַ
			for (stdq = stdq->next; 1; stdq = stdq->next)
			{
				if (scbj(stdq->id, id3))								//���� id3 ��һ��㣬���棬����
				{
					stdq3 = stdq;										//���� id3 ��һ����ַ
					break;												//��ӡ�� id2 �� id3 ������ѧ��������
				}
				opoint(stdq);											//��ӡһ�������ڵĽ��
				printf("\n");
			}
			printf("\n\n  ƥ�䵽����ѧ����ȷ��Ҫɾ��ô��"
				"\n\n  ȷ��ɾ���������ַ�����Enter�����������������ַ������룺 ");
			gets_s(enter, 6);
			if (strbj(enter, "Enter"))
			{
				stdq = stdq2;											//��ԭ stdq �� id2 ��ǰһ���
				//ѭ���ͷ�Ҫɾ���Ľ��
				for (stdq = stdq->next->next; stdq != stdq3; stdq = stdq->next)
					free(stdq->last);									//�ͷ���һ����ڴ�
				stdq2->next = stdq3;									//�� id2 ǰһ����� id3 ��һ�������
			}
			else
				printf("\n  ��ɾ����Щѧ����Ϣ");
		}
	}
	else if (pd == 3)													//ɾ������ѧ����Ϣ
	{
		printf("\n  ע�⣡������ѡ����ɾ������ѧ����Ϣ��\n\n  ȷ��ɾ�������롰Enter���� ");
		gets_s(enter, 6);
		if (strbj(enter, "Enter"))
		{
			for (; 1;)													//ѭ���ͷŽ�㣬��������һ��
			{
				tail = head->next;										//�ƶ�βָ�뵽ͷָ���
				free(head);												//�ͷ�ͷָ��ָ��Ľ��
				if (tail->next == NULL)									//����Ƿ����ͷ������������ͷ�β��㲢����
				{
					free(tail);											//�ͷ�β���
					break;												//����
				}
				head = tail;											//�ƶ�ͷָ�뵽βָ���λ��
			}
			tail = (s*)malloc(sizeof(s));								//������β
			scp(tail->id, "0", 2);										//��Ǳ�β
			tail->next = NULL;											//��ʼ����β next ��Ա
			head = (s*)malloc(sizeof(s));								//������ͷ
			head->next = tail;											//��ʼ����ͷ next ��Ա
		}
		else
			printf("\n  ��ɾ��ѧ����Ϣ");
	}
	if (head->next == NULL)												//Ԥ������Ϊ�յ����
	{
		tail = (s*)malloc(sizeof(s));									//������β
		scp(tail->id, "0", 2);											//��Ǳ�β
		tail->next = NULL;												//��ʼ����β next ��Ա
		head = (s*)malloc(sizeof(s));									//������ͷ
		head->next = tail;												//��ʼ����ͷ next ��Ա
	}
	write(head);
	printf("\n\n  ������ϣ��ѱ����޸ģ��밴�س�����������");
	getchar();
}

void orders()
{
	int pd;		char xz[21];
	printf("\n  ��ѡ�������򣬽��������� 1������������ 2�� ");
	scanf_s("%d", &pd);		getchar();
	printf("\n  ��ѡ���������ѡ���С�ѧ�š��������ġ�������ѧ������Ӣ�����������\n  "
			    "����ѧ����������������Ρ�������ʷ���������������ܷ֡�����ƽ����");
	printf("\n  ��������ѡ�������� ");
	gets_s(xz, 21);
	if (strbj(xz, "ѧ��"))
		order(head, pd);									//����
	else if (strbj(xz, "����"))
		order2(head, pd, 0);
	else if (strbj(xz, "��ѧ"))
		order2(head, pd, 1);
	else if (strbj(xz, "Ӣ��"))
		order2(head, pd, 2);
	else if (strbj(xz, "����"))
		order2(head, pd, 3);
	else if (strbj(xz, "��ѧ"))
		order2(head, pd, 4);
	else if (strbj(xz, "����"))
		order2(head, pd, 5);
	else if (strbj(xz, "����"))
		order2(head, pd, 6);
	else if (strbj(xz, "��ʷ"))
		order2(head, pd, 7);
	else if (strbj(xz, "����"))
		order2(head, pd, 8);
	else if (strbj(xz, "�ܷ�"))
		order2(head, pd, 9);
	else if (strbj(xz, "ƽ��"))
		order2(head, pd, 10);
	printf("\n  ����ѧ���б��������£�\n");
	if (head->next != NULL)
		for (tail = head->next; 1; tail = tail->next)		//��ʼ��βָ�뵽��ͷ�������������
		{
			opoint(tail);									//������������һ�����
			printf("\n");									//�ڴ�ӡ�Ľ����Ϣ�任��
			if (tail->next == NULL)	break;					//�Ѵ�ӡ��������������
		}
	else
		printf("\n  �����ļ�Ϊ��");							//���δ�ҵ������
	write(head);
	printf("\n  ������ϣ��Ѵ洢�������ļ���\n\n  ");
	printf("������˳����ȷ���ٽ���һ�����򼴿ɽ��\n");
	printf("\n  �밴�س�������������");
	getchar();
}

void reset()												//�޸�ģ�飬�޸�ĳѧ����Ϣ
{
	char id2[31];	s *czstd;	char xz[21];				//�����Ա��ַ���������ָ��
	printf("\n  ������Ҫ�޸ĵ�ѧ����ѧ�ţ� ");
	gets_s(id2, 31);
	czstd = cz(head, id2);									//���ҳ�ָ��ѧ�ŵ�ѧ�����ҵ����ؽ���ַ��δ�ҵ����� NULL
	if (czstd != NULL)
		opoint(czstd);										//������ҵ��ĵ������
	else
		printf("\n  δ�ҵ����и�ѧ�ŵ�ѧ���������ļ�Ϊ��");			//���δ�ҵ������
	if (czstd != NULL)
	{
		printf("\n\n  ����Ҫ�޸ĸ�ѧ������һ�\n  ���롰ѧ�š����������������Ա𡱡������䡱�������֤���롱��"
			"  ����ͥסַ����\n  ���ֻ��š������꼶���༶���������ƿ��Գɼ�������ȫ���޸ġ�����: ");
		gets_s(xz, 21);
		if (strbj(xz, "ѧ��"))
		{
			for (; 1;)
			{
				s *temp;
				printf("\n  �������޸ĺ�ѧ�ţ� ");
				gets_s(czstd->id, 31);
				if ((temp = cz(head, czstd->id)) != NULL && temp != czstd)
					printf("\n  ѧ��������ѧ���ظ������������룡\n\n");
				else if (strc(czstd->id) == 0)
				{
					printf("\n  ѧ�Ų���Ϊ�գ����������룡\n\n");
					printf("  ѧ�ţ� ");
					gets_s(czstd->id, 31);
				}
				else
					break;
			}
		}
		else if (strbj(xz, "����"))
		{
			printf("\n  �������޸ĺ������� ");
			gets_s(czstd->name, 21);
		}
		else if (strbj(xz, "�Ա�"))
		{
			printf("\n  �������޸ĺ��Ա� ");
			gets_s(czstd->xb, 9);
		}
		else if (strbj(xz, "����"))
		{
			printf("\n  �������޸ĺ����䣺 ");
			gets_s(czstd->age, 10);
		}
		else if (strbj(xz, "���֤����"))
		{
			printf("\n  �������޸ĺ����֤���룺 ");
			gets_s(czstd->sfz, 31);
		}
		else if (strbj(xz, "��ͥסַ"))
		{
			printf("\n  �������޸ĺ��ͥ��ַ�� ");
			gets_s(czstd->addr, 101);
		}
		else if (strbj(xz, "�ֻ���"))
		{
			printf("\n  �������޸ĺ��ֻ��ţ� ");
			gets_s(czstd->phone, 21);
		}
		else if (strbj(xz, "�꼶���༶"))
		{
			printf("\n  �������޸ĺ��꼶���༶�� ");
			gets_s(czstd->class, 41);
		}
		else if (strbj(xz, "���ƿ��Գɼ�"))
		{
			printf("\n  ���ģ� ");
			scanf_s("%lf", &czstd->score[0]);	getchar();
			printf("\n  ��ѧ�� ");
			scanf_s("%lf", &czstd->score[1]);	getchar();
			printf("\n  Ӣ� ");
			scanf_s("%lf", &czstd->score[2]);	getchar();
			printf("\n  ���� ");
			scanf_s("%lf", &czstd->score[3]);	getchar();
			printf("\n  ��ѧ�� ");
			scanf_s("%lf", &czstd->score[4]);	getchar();
			printf("\n  ��� ");
			scanf_s("%lf", &czstd->score[5]);	getchar();
			printf("\n  ���Σ� ");
			scanf_s("%lf", &czstd->score[6]);	getchar();
			printf("\n  ��ʷ�� ");
			scanf_s("%lf", &czstd->score[7]);	getchar();
			printf("\n  ���� ");
			scanf_s("%lf", &czstd->score[8]);	getchar();
			int i = 0;
			for (czstd->score[9] = 0; i < 9; i++) czstd->score[9] += czstd->score[i];		//�����ܷ�
			czstd->score[10] = czstd->score[9] / 6.0;										//����ƽ����
		}
		else if (strbj(xz, "ȫ���޸�"))
		{
			printf("\n  �������޸ĺ�ѧ�ţ� ");
			gets_s(czstd->id, 31);
			printf("\n  �������޸ĺ������� ");
			gets_s(czstd->name, 21);
			printf("\n  �������޸ĺ��Ա� ");
			gets_s(czstd->xb, 9);
			printf("\n  �������޸ĺ����䣺 ");
			gets_s(czstd->age, 10);
			printf("\n  �������޸ĺ����֤���룺 ");
			gets_s(czstd->sfz, 31);
			printf("\n  �������޸ĺ��ͥ��ַ�� ");
			gets_s(czstd->addr, 101);
			printf("\n  �������޸ĺ��ֻ��ţ� ");
			gets_s(czstd->phone, 21);
			printf("\n  �������޸ĺ��꼶���༶�� ");
			gets_s(czstd->class, 41);
			printf("\n  ���ģ� ");
			scanf_s("%lf", &czstd->score[0]);	getchar();
			printf("\n  ��ѧ�� ");
			scanf_s("%lf", &czstd->score[1]);	getchar();
			printf("\n  Ӣ� ");
			scanf_s("%lf", &czstd->score[2]);	getchar();
			printf("\n  ���� ");
			scanf_s("%lf", &czstd->score[3]);	getchar();
			printf("\n  ��ѧ�� ");
			scanf_s("%lf", &czstd->score[4]);	getchar();
			printf("\n  ��� ");
			scanf_s("%lf", &czstd->score[5]);	getchar();
			printf("\n  ���Σ� ");
			scanf_s("%lf", &czstd->score[6]);	getchar();
			printf("\n  ��ʷ�� ");
			scanf_s("%lf", &czstd->score[7]);	getchar();
			printf("\n  ���� ");
			scanf_s("%lf", &czstd->score[8]);	getchar();
			int i = 0;
			for (czstd->score[9] = 0; i < 9; i++) czstd->score[9] += czstd->score[i];		//�����ܷ�
			czstd->score[10] = czstd->score[9] / 6.0;										//����ƽ����
		}
		write(head);
		printf("\n  �޸���ϣ��ѽ��޸�д�������ļ���\n");
	}
	printf("\n\n  ���س�������������");
	getchar();
}

void lfor()														//ʹ���ܱ����������˻�ģ��
{
	system("cls");
	char ques[101], as[101], as2[101];	int a, b, c, d;
	FILE *f;													//�����ļ�ָ��
	f = fopen("user.txt", "rb");								//��ֻ����ʽ���û��ļ���
	fread(&a, sizeof(int), 1, f);								//��ȡ�˻����ĳ���
	fread(&b, sizeof(int), 1, f);								//��ȡ����ĳ���
	fread(user, sizeof(char), a, f);							//��ȡ�˻���
	fread(password, sizeof(char), b, f);						//��ȡ����
	fread(&c, sizeof(int), 1, f);								//��ȡ�ܱ�����ĳ���
	fread(&d, sizeof(int), 1, f);								//��ȡ�𰸵ĳ���
	fread(ques, sizeof(char), c, f);							//��ȡ�ܱ�����
	fread(as, sizeof(char), d, f);								//��ȡ��
	fclose(f);
	ques[c] = '\0';		as[d] = '\0';
	printf("\n  �������ܱ�����𰸣�����δ�޸Ĺ��˻��������룬��ֱ���˳���\n\n");
	printf("  %s", ques);
	printf("\n\n  ������𰸣� ");
	gets_s(as2, 101);
	if (strbj(as2, as))
	{
		printf("\n  ����ȷ!���ڿ�ʼ�����˻��������룺");
		printf("\n\n  �������޸ĺ���˻������ɰ��������ַ����� ");
		gets_s(user, 101);
		printf("\n  �޸ĳɹ�����ǰ�˻����ǣ�%s", user);
		printf("\n\n  �������޸ĺ�����루�ɰ��������ַ�����ֻ��һ�������룬�����˸� ");
		for (int i = 0; 1; i++)
		{
			password[i] = _getch();
			if (password[i] == '\r')
			{
				password[i + 1] = '\0';
				break;
			}
			printf("*");
		}
		printf("\n\n  �޸�����ɹ�");
		FILE *f;													//�����ļ�ָ��
		f = fopen("user.txt", "wb+");								//���´����û��ļ���
		int a = strc(user), b = strc(password);						//�ֱ��������߳���
		fwrite(&a, sizeof(int), 1, f);								//�������˻�������
		fwrite(&b, sizeof(int), 1, f);								//���������볤��
		fwrite(user, sizeof(char), strc(user), f);					//д�����˻���
		fwrite(password, sizeof(char), strc(password), f);			//д��������
		fwrite(&c, sizeof(int), 1, f);								//�����ܱ����ⳤ��
		fwrite(&d, sizeof(int), 1, f);								//����𰸳���
		fwrite(ques, sizeof(char), strc(ques), f);					//д���ܱ�����
		fwrite(as, sizeof(char), strc(as), f);						//д���
		fclose(f);
		printf("\n\n  �ѱ������û��������룬���س�������ϵͳ");
		getchar();
	}
	else
	{
		printf("\n  �𰸴����˳� . . .\n\n  ");
		exit(0);
	}
}

void temp(int x, double line, char *xz)				//ͳ��ģ���������ʱ����
{
	s *bl;		double bjg = 0, nums = 0;			//���Ҳ��������ָ�롢������������������
	for (bl = head->next, nums++; ; bl = bl->next, nums++)
	{
		if (bl->score[x] < line)
		{
			printf("\n  ѧ�ţ�%s\n  ������%s\t\t�꼶���༶��%s\n  %s�ɼ��� %g\n"
				, bl->id, bl->name, bl->class, xz, bl->score[x]);
			bjg++;
		}
		if (bl->next == NULL)	break;
	}
	printf("\n  �����ǲ���������\n  �������� %g\t������������ %g", nums, bjg);
	printf("\n  �����ߣ� %g\n  %s�ļ������ǣ� %.2lf%%\n", line, xz, 100 * (1 - (bjg / nums)));
}
void tj()
{
	char xz[21];	double line;
	printf("\n  ��ƽ���ɼ��������ʡ���ӡȫ������������\n  "
		   "��ѡ���Ŀ����ѡ���С����ġ�������ѧ������Ӣ�����������\n  "
		   "����ѧ����������������Ρ�������ʷ���������������ܷ֡�����ȫ����(ֻ��ʾƽ����)��"
		   "\n\n  �������Ŀ���ƣ� ");
	gets_s(xz, 21);
	printf("\n  �����뼰���ߣ� ");
	scanf_s("%lf", &line);	getchar();
	system("cls");
	if (strbj(xz, "����") || strbj(xz, "��ѧ") || strbj(xz, "Ӣ��") || strbj(xz, "����") || strbj(xz, "��ѧ")
		|| strbj(xz, "����") || strbj(xz, "����") || strbj(xz, "��ʷ") || strbj(xz, "����") || strbj(xz, "�ܷ�"))
	{
		double value;
		void temp(int x,double line);					//���庯�������ݲ���ѡ���Ŀ�����㼰���ʲ��������������
		if (strbj(xz, "����"))
		{
			value = pjz(head, 0);						//����ƽ��ֵ
			temp(0, line, xz);
		}
		else if (strbj(xz, "��ѧ"))
		{
			value = pjz(head, 1);
			temp(1, line, xz);
		}
		else if (strbj(xz, "Ӣ��"))
		{
			value = pjz(head, 2);
			temp(2, line, xz);
		}
		else if (strbj(xz, "����"))
		{
			value = pjz(head, 3);
			temp(3, line, xz);
		}
		else if (strbj(xz, "��ѧ"))
		{
			value = pjz(head, 4);
			temp(4, line, xz);
		}
		else if (strbj(xz, "����"))
		{
			value = pjz(head, 5);
			temp(5, line, xz);
		}
		else if (strbj(xz, "����"))
		{
			value = pjz(head, 6);
			temp(6, line, xz);
		}
		else if (strbj(xz, "��ʷ"))
		{
			value = pjz(head, 7);
			temp(7, line, xz);
		}
		else if (strbj(xz, "����"))
		{
			value = pjz(head, 8);
			temp(8, line, xz);
		}
		else if (strbj(xz, "�ܷ�"))
		{
			value = pjz(head, 9);
			temp(9, line, xz);
		}
		printf("  %s��ƽ���ɼ��ǣ� %g", xz, value);
	}
	else if (strbj(xz, "ȫ��"))
	{
		double value[10];	int i;
		for (i = 0; i < 10; i++)
			value[i] = pjz(head, i);
		printf("\n  ���ģ�%g\n  ��ѧ��%g\n  Ӣ�%g\n  ����%g\n  ��ѧ��%g\n  ���%g\n  ���Σ�%g\n  ��ʷ��%g\n  "
			   "����%g\n  �ܷ֣�%g"
		, value[0], value[1], value[2], value[3], value[4], value[5], value[6], value[7], value[8], value[9]);
	}
	printf("\n\n  ���س�������������");
	getchar();
}

void infix()												//����ģ�飬��ĳ�������һ�����
{
	char id2[31];	s *czstd, *temp;						//�����Ա��ַ���������ָ��
	int i;		s *std = (s*)malloc(sizeof(s));				//ѭ������ i��������ʱ��㲢�����ַ���ظ� std
	printf("\n  ������һ������ѧ����ѧ�ţ�������������ѧ������Ϣ�� ");
	gets_s(id2, 31);
	czstd = cz(head, id2);									//����ָ��ѧ�ŵ�ѧ�����ҵ����ؽ���ַ��δ�ҵ����� NULL
	if (czstd != NULL)
		opoint(czstd);										//������ҵ��ĵ������
	else
		printf("\n  δ���ҵ����и�ѧ�ŵ�ѧ���������ļ�Ϊ��");		//���δ�ҵ������
	printf("\n\n  ���ڿ�ʼ����Ҫ�����ѧ������Ϣ��\n");
	//��ʼ��ȡ����
	for (; 1;)
	{
		printf("  ѧ�ţ� ");
		gets_s(std->id, 31);
		if (cz(head, std->id) != NULL)
			printf("\n  ѧ��������ѧ���ظ������������룡\n\n");
		else if (strc(std->id) == 0)
		{
			printf("\n  ѧ�Ų���Ϊ�գ����������룡\n\n");
			printf("  ѧ�ţ� ");
			gets_s(std->id, 31);
		}
		else
			break;
	}
	printf("  ������ ");
	gets_s(std->name, 21);
	printf("  �Ա� ");
	gets_s(std->xb, 9);
	printf("  ���䣺 ");
	gets_s(std->age, 10);
	printf("  ���֤�� ");
	gets_s(std->sfz, 31);
	printf("  ��ͥסַ�� ");
	gets_s(std->addr, 101);
	printf("  �ֻ��ţ� ");
	gets_s(std->phone, 21);
	printf("  �꼶���༶�� ");
	gets_s(std->class, 41);
	printf("  ���ڿ�ʼ¼��ѧ�����Գɼ���\n");
	printf("\n  ���ģ� ");
	scanf_s("%lf", &std->score[0]);	getchar();
	printf("\n  ��ѧ�� ");
	scanf_s("%lf", &std->score[1]);	getchar();
	printf("\n  Ӣ� ");
	scanf_s("%lf", &std->score[2]);	getchar();
	printf("\n  ���� ");
	scanf_s("%lf", &std->score[3]);	getchar();
	printf("\n  ��ѧ�� ");
	scanf_s("%lf", &std->score[4]);	getchar();
	printf("\n  ��� ");
	scanf_s("%lf", &std->score[5]);	getchar();
	printf("\n  ���Σ� ");
	scanf_s("%lf", &std->score[6]);	getchar();
	printf("\n  ��ʷ�� ");
	scanf_s("%lf", &std->score[7]);	getchar();
	printf("\n  ���� ");
	scanf_s("%lf", &std->score[8]);	getchar();
	for (i = 0, std->score[9] = 0; i < 9; i++) std->score[9] += std->score[i];		//�����ܷ�
	std->score[10] = std->score[9] / 6.0;											//����ƽ����
	//��ȡ������ϣ�����һ���½�㱣����ʱ����������ݣ����뵽ָ��λ��
	temp = czstd->next;											//������ҽ����һ���ĵ�ַ
	czstd->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
	czstd->next->next = temp;									//ʹ�½��� next ָ������һ���
	czstd->next->last = czstd;									//ʹ�½��� last ָ������һ���
	write(head);
	printf("\n\n  �ѽ���ѧ����Ϣ���뵽�����ļ���");
	printf("\n\n  �밴�س�������������");
	getchar();
}

void exits()													//�ڹرճ���ʱ���ͷ����д洢������ռ�õ��ڴ�ռ�
{
	for (; 1;)													//ѭ���ͷŽ�㣬��������һ��
	{
		tail = head->next;										//�ƶ�βָ�뵽ͷָ���
		free(head);												//�ͷ�ͷָ��ָ��Ľ��
		if (tail->next == NULL)									//����Ƿ����ͷ������������ͷ�β��㲢����
		{
			free(tail);											//�ͷ�β���
			break;												//����
		}
		head = tail;											//�ƶ�ͷָ�뵽βָ���λ��
	}
	printf("\n\n\n\n\n\n                                 �� �� �� �� �� �� �� �� �� ռ �� �� �� ��\n\n"
		   "                                 �� �� �� �� . . .\n\n                                 ");
	Sleep(1000);
	exit(0);
}

/*
����: 1. ���������Ҫ�õ� gets_s() ��������ÿ��ʹ�� scanf_s() ������Ҫ�� getchr() ���������Ļس���
	 2. ʹ������ʱ��ʱ��Ҫ�ǵø���βָ��ָ��β���
	 3. ����ÿ���´����Ľ�㣬�� next ��ԱҪ��ʼ��Ϊ NULL
	 4. �����ַ��������� gets_s()��������ֵ�������� scanf_s()
	 5. ��Ч���㷨Ҳ�����Ǽ��ģ����Ļ���ԭ������Ǽ�������򵥵ģ���Ȼ�����޷�����˼������ԭ��ͺܸ��ӵ��㷨��BUG ̫��
*/