#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
/*
**程序名称：							高中学生信息管理系统（控制台版）

********************************************** 功能 *********************************************************

	录入、打印所有学生信息			查找（按学号、姓名）学生			修改、删除、插入学生信息			退出系统

	计算各科目平均分、统计及格率（及格分可自定义）、输出不及格名单		根据学号大小、科目成绩等对学生进行排序
	
	系统具有账户名、密码，可修改，可找回

	*** 初始账户名：123 ***			*** 初始密码：123 ***

************************************************************************************************************

**编译环境：			Visual Studio 2015	&&	Win 7
**开发者：			西安石油大学——通信1701——王超
**应用知识：			C 语言、Windows API（控制台版未应用）、数据结构（双向链表）
**第一版完成日期：		1.0 版	2018 年 7 月 2 日
**当前版本号：			1.1 版
**更新：				更新项目数据结构为双向链表，并稍微缩了缩代码量
**版权声明：			本软件由本人独立开发，未经本人允许不可用作商业用途，若有侵权，必通过合法途径维权！
*/

typedef struct students {			//学生信息 
	char id[31];					//学号
	char name[21];					//姓名
	char xb[9];						//性别
	char age[10];					//年龄
	char sfz[31];					//身份证号码
	char addr[101];					//家庭住址
	char phone[21];					//手机号
	char class[41];					//年级、班级
	double score[11];				//各科考试成绩,顺序是语、数、英、理、化、生、政、史、地、总分、平均分
	struct students *next;			//指向下一个结点
	struct students *last;			//指向上一个结点
}s;

s *head,*tail;						//头指针、尾指针，分别指向表头、尾结点

//********************************************************************************** 功能型函数声明

int strbj(char* x, char* y);						//字符串比较函数，相同返回值为 1，不同返回值为 0

void ui();											//打印用户 UI

s *new(char *id, char *name, char *xb,char *age, char *sfz, char *addr, char* phone, char* class, double *score);
													//新建一个学生结构体，储存内容，返回新建的结构体地址

void scp(char* x, char* y, int size);				//字符串复制函数，将 y 复制到 x 中，size 是最大长度

int write(s *x);									//存储整个链表一次

int strc(char *x);									//数出一个字符串的长度，不包括 '\0'，返回值即长度

s *cz(s *x, char *y);								//遍历链表，返回具有指定学号的结点地址

//返回具有指定姓名的学生信息，从指定结点开始，向后遍历链表，返回找到的第一个匹配结点的地址
s *czn(s *x, char *y);

void opoint(s *x);									//打印一个结点的所有信息

int scbj(char *x, char *y);							//比较两字符串数字的大小，若前者大于后者返回 1，否则 0

void jh(s* x, s *y);								//交换两结点的数据域

s *lbcz(s *x, int y);								//从指定结点向后查找，返回其后具有最大/最小学号的结点地址，1 最大，2最小

void order(s *x, int y);							//将链表排序，输入字符 1 升序（从大到小），字符 2 降序（从小到大）

s* lbcz2(s* x, int y, int z);						//按科目查找、头指针、排序方向、科目代号

void order2(s *x, int y, int z);					//按科目排序、头指针、排序方向、科目代号

double pjz(s *x, int y);							//计算一门科目的平均值

//************************************************************************************* 结构型函数声明

void login(), read(s *x), get(), del(), reset(), czmk(), out(s *x), orders(), tj(), infix(), revise()
	 , exits(), lfor();
/*
  依次是登录模块、读取数据文件并建立链表模块、新增学生信息模块、按学号删除模块、修改学生信息模块、按条件查找模块、
  打印所有信息模块、按条件排序模块、统计模块、插入学生信息模块、修改账户名密码模块、退出系统模块、
  密保问题重置账户名密码模块、
*/
char user[101] = "123", password[101] = "123\r";		//初始账户名、密码

//************************************************************************************ 主函数开始

int main()
{
	head = (s*)malloc(sizeof(s));						//创建表头
	head->next = NULL;									//初始化表头 next 成员
	system("mode con cols=130");						//窗口宽度
	system("mode con lines=600");						//窗口高度（可滚动）
	system("color F6 ");								//前景色、背景色
	login();											//登录模块
	read(head);											//读取数据文件模块
	for (; 1;)
	{
		int pd;
		ui();
		scanf_s("%d", &pd);								//由用户判断功能选择模块
		getchar();										//消除回车符对接下来程序运行的影响
		system("cls");									//清屏、重新打印一次
		switch (pd)
		{
			case 1:	get();	break;						//调用新增模块
			case 2: del();	break;						//调用删除模块
			case 3: reset();  break;					//调用修改模块
			case 4: czmk();	break;						//调用查找模块
			case 5: out(head);	break;					//调用输出全部信息模块
			case 6: orders();  break;					//调用排序模块
			case 7: tj();	break;						//调用统计模块
			case 8: infix();  break;					//调用插入模块
			case 9: revise();	break;					//调用修改账户模块
			case 0: exits(); break;						//调用退出模块
		}
		system("cls");									//清屏、重新打印一次
	}
	return 0;
}

//*********************************************************************************** 功能型函数定义

void ui()													//打印一次用户 UI
{
	printf("\n\n                                 版权声明： 本软件由本人独立开发，未经本人允许禁止用作商业用途！若\n            "
		   "                                有侵权，必通过法律途径维权！");
	printf("\n\n                                 版本号：1.0 | 控制台版 | 图形界面目前还在做 . . .");
	printf("\n\n                                 软件开发者： 西安石油大学 —— 通信 1701 —— 王超");
	printf("\n\n                                      ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇\n"
		   "                                      ◇                                     ◇\n"
		   "                                      ◇        高中学生信息管理系统         ◇\n"
		   "                                      ◇                                     ◇\n"
		   "                                      ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇\n\n"
		   "                                        功能选项：\n\n"
		   "                                         1. 新增学生信息\n\n"
		   "                                         2. 按条件删除学生信息\n\n"
		   "                                         3. 修改某学生信息\n\n"
		   "                                         4. 按条件查找学生信息\n\n"
		   "                                         5. 打印输出所有学生信息\n\n"
		   "                                         6. 按条件对所有学生信息进行排序\n\n"
		   "                                         7. 求平均分、及格率、不及格名单\n\n"
		   "                                         8. 在某学生后插入学生信息\n\n"
		   "                                         9. 修改账户名和密码\n\n"
		   "                                         0. 退出\n\n"
		   "                                 注：请不要直接点击窗口关闭程序，通过本程序关闭能释放程序占用的内\n"
		   "                                     存，能避免浪费电脑内存空间\n\n"
		   "                                        请按下对应数字选择功能： ");
}

int strbj(char* x, char* y)									//字符串比较函数
{
	int i;													//定义循环变量
	for (i = 0; x[i] == y[i]; i++)							//只要两字符串对应字符相同，就继续循环
		if (x[i] == '\0' && y[i] == '\0')					//当读到 '\0' 时，代表相同，同时，长度也相同
			return 1;										//相同，返回值为 1
	return 0;												//循环在未读完字符串时结束，不相同，返回值为 0
}

void scp(char *x, char *y, int size)						//字符串复制函数，将 y 复制到 x 中，size 是最大长度
{
	for (int i = 0; i < size; i++)
		x[i] = y[i];
}

//新建一个结点，储存内容，返回新建的结点地址
s *new(char *id, char *name, char *xb,char *age, char *sfz, char *addr, char* phone, char* class, double *score)
{
	s *stdp = (s*)malloc(sizeof(s));						//创建一个新结点，存储其地址在 stdp
	stdp->next = NULL;										//初始化新结点的 next
	stdp->last = NULL;										//初始化新结点的 last
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

int write(s *x)												//保存整个链表一次
{
	FILE *f;												//创建文件指针
	f = fopen("data.txt", "wb+");							//重新创建并打开数据文件
	if ((x->next) == NULL)									//链表为空，停止写入
	{
		fclose(f);											//关闭文件
		return 0;
	}
	for (x = x->next; 1; x = x->next)						//循环，将整个链表写入文件
	{
		fwrite(x, sizeof(s), 1, f);							//写入一个结点
		if (x->next == NULL) break;							//检测链表是否写入完毕，若是，跳出
	}
	fclose(f);												//关闭文件
	return 0;
}

int strc(char *x)											//数出一个字符串的长度，不包括 '\0'
{
	int i;
	for (i = 0; x[i] != '\0'; i++);
	return i;
}

s *cz(s *x, char *y)										//遍历链表，返回具有指定学号的结点地址或空指针
{
	if (x->next == NULL)	return NULL;					//表头 next 成员若为空，返回 NULL
	for (x = x->next; 1; x = x->next)						//循环，遍历完整个链表后跳出
	{
		if (strbj(x->id, y)) break;							//检测是否遍历到指定结点，若是，跳出
		if (x->next == NULL) break;							//已到尾结点，跳出
	}
	if (x->next == NULL && !(strbj(x->id, y)))				//如果是最后一个结点且学号不同于指定学号，返回 NULL
		return NULL;
	else													//结点学号与指定学号相同，返回结点地址
		return x;											//返回查找到的结点或最后一个结点的地址
}

s *czn(s *x, char *y)
{
	if (strbj(x->id, "0"))	return NULL;					//数据文件为空，返回 NULL
	for (x = x->next; x->next != NULL; x = x->next)			//循环，若遍历完整个链表后仍未找到匹配结点，跳出
	{
		if (strbj(x->name, y)) break;						//检测是否遍历到指定结点，若是，跳出
	}
	if (x->next == NULL && !(strbj(x->name, y)))			//如果是最后一个结点且姓名不同于指定姓名，返回 NULL
		return NULL;
	else													//结点姓名与指定姓名相同，返回结点地址
		return x;											//返回查找到的结点或最后一个结点的地址
}

void opoint(s *x)											//打印一个结点的所有信息
{
	int i;													//用于打印的循环变量 i
	printf("\n  学号：%s\n  姓名：%s\t性别：%s\t年龄：%s\n  身份证号码：%s\n  家庭住址：%s\n  手机号：%s\t\t年级及班级：%s\n"
			, x->id, x->name, x->xb, x->age, x->sfz, x->addr, x->phone, x->class);
	printf("  语文  数学  英语  物理  化学  生物  政治  历史  地理  总 分  平 均 分\n   ");
	for (i = 0; i < 10; i++)
	{
		if (x->score[i] < 10)
			printf("0%g    ", x->score[i]);
		else
			printf("%g    ", x->score[i]);
	}
	printf(" %.1lf", x->score[i]);
}

int scbj(char *x, char *y)									//比较两字符串数字的大小，若前者大于后者返回 1，否则 0
{
	if (strc(x) > strc(y))	return 1;						//前者长度大于后者，前者大，返回 1
	else if(strc(x) < strc(y))  return 0;					//前者长度小于后者，后者大，返回 0
	else													//前者与后者长度相等，接下来循环比较每一位上数字的大小
	{
		char a = *x, b = *y;
		for (; x != '\0'&&y != '\0';x++,y++,a = *x,b = *y)  //从左侧第一位开始比较
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

void jh(s *x,s *y)											//交换两结点数据域，但不改变 next 成员
{
	s *temp = (s*)malloc(sizeof(s)), *a = x->next, *b = y->next;
	*temp = *y;
	*y = *x;
	*x = *temp;
	x->next = a;
	y->next = b;
	free(temp);
}

//从指定结点向后查找，返回其后具有最大/最小学号的结点的地址，1 最大，2最小
s *lbcz(s *x,int y)
{
	s *cz, *bj;													//用于查找的指针
	if (x->next == NULL)	return NULL;						//链表已到终点，结束
	cz = x;														//查找指针开始处于起始结点
	if (y == 1)													//找出最大者
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (scbj(cz->id, bj->id))	bj = cz;				//若标记结点小于查找结点，更新指针的指向
			if (cz->next == NULL)	break;						//链表已到终点，跳出
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
	else if (y == 2)											//找出最小者
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (scbj(bj->id, cz->id))	bj = cz;				//若标记结点大于查找结点，更新指针的指向
			if (cz->next == NULL)	break;						//链表已到终点，跳出
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
}

//选择法排序
void order(s *x, int y)										//将链表排序，输入数值 1 升序（从大到小），2 降序（从小到大）
{
	s *jhstd;												//用于交换的指针
	x = x->next;											// x 指针移动到第一个存储信息的结点
	for (jhstd = x; 1;x = x->next)							//每次头指针处于待交换结点，jhstd 查找出剩余部分最大结点
	{
		if (x->next == NULL)
		{
			tail = x;										//更新尾指针
			break;											//链表末尾，跳出
		}
		jhstd = lbcz(x, y);									//查找出 x 结点后方的具有最大学号的结点
		if (jhstd != NULL)	jh(x, jhstd);					//若找到，则交换两结点数据域
	}
}

//从指定结点向后查找，返回其后具有最大/最小值的结点的地址，1 最大，2最小
s* lbcz2(s* x, int y, int z)									//按科目查找，头指针、排序方向、科目代号
{
	s *cz, *bj;													//用于查找的指针
	if (x->next == NULL)	return NULL;						//链表已到终点，结束
	cz = x;														//查找结点开始处于起始结点
	if (y == 1)													//找出最大者
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (bj->score[z] < cz->score[z])	bj = cz;		//若标记结点小于查找结点，更新指针的指向
			if (cz->next == NULL)	break;						//链表已到终点，跳出
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
	else if (y == 2)											//找出最小者
	{
		for (bj = cz; 1; cz = cz->next)
		{
			if (bj->score[z] > cz->score[z])	bj = cz;		//若标记结点大于查找结点，更新指针的指向
			if (cz->next == NULL)	break;						//链表已到终点，跳出
		}
		if (bj == x)	return NULL;
		else	return bj;
	}
}

//将链表排序，输入数值 1 升序（从大到小），2 降序（从小到大）
void order2(s *x, int y, int z)								//按科目排序、头指针、排序方向、科目代号
{
	s *jhstd;												//用于交换的指针
	x = x->next;											// x 指针移动到第一个存储信息的结点
	for (jhstd = x; 1; x = x->next)							//每次头指针处于待交换结点，jhstd 查找出剩余部分最大结点
	{
		if (x->next == NULL)
		{
			tail = x;										//更新尾指针
			break;											//链表末尾，跳出
		}
		jhstd = lbcz2(x, y, z);								//查找出 x 结点后方的具有最大学号的结点
		if (jhstd != NULL)	jh(x, jhstd);					//若找到，则交换两结点数据域
	}
}

double pjz(s *x, int y)										//计算一门科目的平均值
{
	int i;	 double add;									//循环变量、和
	for (i = 0, add = 0, x = x->next; 1; x = x->next)		//循环求和
	{
		add += x->score[y];
		i++;
		if (x->next == NULL)	break;
	}
	return (add / i);										//计算平均值、返回
}

//***************************************************************************************** 结构型函数定义

void login()													//登录模块
{
	char user2[101], password2[101];		int a, b, bj = 1;
	FILE *f;													//创建文件指针
	f = fopen("user.txt", "rb");								//以只读方式打开用户文件夹
	fread(&a, sizeof(int), 1, f);								//读取账户名的长度
	fread(&b, sizeof(int), 1, f);								//读取密码的长度
	fread(user, sizeof(char), a, f);							//读取账户名
	fread(password, sizeof(char), b, f);						//读取密码
	fclose(f);
	printf("\n\n\n\n\n\n\n                                 登录管理员账户（初始账户名、密码均为 123），密码只能一次性输入，不能退格\n\n"
		   "                                 请输入账户名： ");
	gets_s(user2, 101);
	if (strbj(user, user2))
		printf("\n                                 账户名输入正确\n");
	else
	{
		int pd;
		printf("\n                                 账户名错误，若使用密保问题重置账户请输入 1，否则退出： ");
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
		printf("\n                                 请输入密码：");
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
			printf("\n\n                                 密码输入正确\n\n                                 登录 . . .");
		else
		{
			int pd;
			printf("\n\n                                 密码错误，若使用密保问题重置账户请输入 1，否则退出： ");
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

void read(s *x)													//读取数据文件模块
{
	FILE *f;													//创建文件指针
	if ((f = fopen("data.txt", "ab+")) != NULL)					//打开或新建数据文件
		printf("\n\n\n\n\n                                 打开数据文件 . . .");
	Sleep(500);
	printf("\n\n                                 加载数据文件 . . .");
	Sleep(500);
	x->next = (s*)malloc(sizeof(s));							//在表头后新建一个空结点
	scp((x->next)->id, "0", 2);									//标记空结点，便于接下来判断数据文件是否为空
	//每次循环在表尾创建一个空结点并更新指针指向空结点，循环读取整个链表
	s *xq = head;												//当前结点的前一结点
	for (x = x->next; 1; xq = x, x = x->next)
	{
		fread(x, sizeof(s), 1, f);								//读取一个结构体，拷贝到空结点中
		x->last = xq;											//指向上一结点
		if (x->next == NULL) break;								//检测链表是否读取完毕，若是，跳出
		x->next = (s*)malloc(sizeof(s));						//在表尾添加一个空结点，以备下次循环赋值
	}
	tail = x;													//将尾指针指向表尾
	if (strbj(tail->id, "0"))									//若相同，返回值为 1，代表文件为空
		printf("\n\n                                 数据文件为空");
	else
		printf("\n\n                                 读取数据文件完毕");
	fclose(f);
	Sleep(1000);
	system("cls");
}

void get()														//新增学生信息模块
{
	int pd;														//判断是否继续录入
	for (pd = 1; pd;)
	{
		//循环变量 i、创建临时结点并将其地址返回给 std、交换指针 temp
		int i;	s *std = (s*)malloc(sizeof(s)), *temp;
		//开始获取数据
		printf("\n  现在录入一名学生的信息，每输入一项按一次回车键：\n\n");
		for (; 1;)
		{
			printf("  学号： ");
			gets_s(std->id, 31);
			if (cz(head, std->id) != NULL)
				printf("\n  学号与现有学生重复，请重新输入！\n\n");
			else if (strc(std->id) == 0)
			{
				printf("\n  学号不能为空，请重新输入！\n\n");
				printf("  学号： ");
				gets_s(std->id, 31);
			}
			else
				break;
		}
		printf("  姓名： ");
		gets_s(std->name, 21);
		printf("  性别： ");
		gets_s(std->xb, 9);
		printf("  年龄： ");
		gets_s(std->age, 10);
		printf("  身份证： ");
		gets_s(std->sfz, 31);
		printf("  家庭住址： ");
		gets_s(std->addr, 101);
		printf("  手机号： ");
		gets_s(std->phone, 21);
		printf("  年级及班级： ");
		gets_s(std->class, 41);
		printf("  现在开始录入学生考试成绩：\n");
		printf("\n  语文： ");
		scanf_s("%lf", &std->score[0]);	getchar();
		printf("\n  数学： ");
		scanf_s("%lf", &std->score[1]);	getchar();
		printf("\n  英语： ");
		scanf_s("%lf", &std->score[2]);	getchar();
		printf("\n  物理： ");
		scanf_s("%lf", &std->score[3]);	getchar();
		printf("\n  化学： ");
		scanf_s("%lf", &std->score[4]);	getchar();
		printf("\n  生物： ");
		scanf_s("%lf", &std->score[5]);	getchar();
		printf("\n  政治： ");
		scanf_s("%lf", &std->score[6]);	getchar();
		printf("\n  历史： ");
		scanf_s("%lf", &std->score[7]);	getchar();
		printf("\n  地理： ");
		scanf_s("%lf", &std->score[8]);	getchar();
		for (i = 0, std->score[9] = 0; i < 9; i++) std->score[9] += std->score[i];		//计算总分
		std->score[10] = std->score[9] / 6.0;											//计算平均分
		//获取数据完毕，接下来创建一个新结点保存临时结点所有数据，再接到链表末尾
		if (strbj((head->next)->id, "0"))
		//解决读入模块遇到空数据文件时，遗留的空尾结点问题，解决方法是：放弃现在这个空的尾结点，新建一个结点并赋值连在表头后
		{
			head->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
			tail = head->next;									//更新尾结点地址
			tail->last = head;									//last 指向表头
		}
		else
		{
			tail->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
			temp = tail;										//临时保存当前结点地址
			tail = tail->next;									//更新尾指针指向
			tail->last = temp;									//last 指向上一结点
		}
		free(std);												//录入完毕，释放临时结点占用的内存
		printf("\n\n  若要继续录入下一个学生信息请输入任意数字，若要返回主界面请输入 0： ");
		scanf_s("%d", &pd);		getchar();
		system("cls");
	}
	write(head);												//保存一次整个链表
	printf("\n\n  所有新增的学生信息已保存，1 秒后返回主界面");
	Sleep(1000);
}

void out(s *x)													//打印模块
{
	int i;														//用于打印的循环变量 i
	printf("\n  所有学生信息如下:");
	if (strbj((x->next)->id, "0"))								//判断若数据文件是否为空，若是，不打印
		printf("\n\n  您还没有录入学生信息\n  ");
	else if (x->next == NULL)
		printf("\n\n  您还没有录入学生信息\n  ");
	else														//数据文件不为空，打印
	{
		int count;												//统计人数
		for (x = x->next, count = 1; 1; x = x->next, count++)	//循环，打印整个链表的所有结点
		{
			printf("\n\n  学号：%s\n  姓名：%s\t性别：%s\t年龄：%s\n  身份证号码：%s\n  家庭住址：%s\n  手机号：%s\t\t年级及班级：%s\n"
					, x->id, x->name, x->xb, x->age, x->sfz, x->addr, x->phone, x->class);
			printf("  语文  数学  英语  物理  化学  生物  政治  历史  地理  总 分  平 均 分\n   ");
			for (i = 0; i < 10; i++)
			{
				if (x->score[i] < 10)
					printf("0%g    ", x->score[i]);
				else
					printf("%g    ", x->score[i]);
			}
			printf(" %.1lf", x->score[i]);
			if (x->next == NULL) break;							//检测是否已打印完整个链表，若是，跳出
		}
		printf("\n\n  共计 %d 人", count);
	}
	printf("\n\n  按回车键返回主界面");
	getchar();
}

void revise()													//修改账户名、密码模块
{
	char user2[101], password2[101], ques[101], as[101];
	printf("\n  修改后请记牢账户名和密码！");
	for (; 1;)													//对比当前账户名
	{
		printf("\n\n  请输入当前账户名： ");
		gets_s(user2, 101);
		if (strbj(user, user2))
		{
			printf("\n  账户名输入正确");							//正确，跳出，开始修改
			break;
		}
		else
		{
			printf("\n  账户名输入错误，请重新输入\n\n  ");
			system("cls");
		}
	}
	printf("\n\n  请输入修改后的账户名（可包含任意字符）： ");
	gets_s(user, 101);
	printf("\n  修改成功，当前账户名是：%s", user);
	for (; 1;)
	{
		printf("\n\n  请输入当前密码，只能一次性输入，不能退格：");
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
		if (strbj(password, password2))							//比较密码是否正确
		{
			printf("\n\n  密码输入正确\n\n  ");
			break;
		}
		else
			printf("\n\n  密码输入错误，请重新输入\n\n  ");
	}
	printf("请输入修改后的密码（可包含任意字符），只能一次性输入，不能退格： ");
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
	printf("\n\n  修改密码成功!\n\n");
	printf("  现在请设置密保问题，该问题可用于重置账户名及密码：\n\n  ");
	gets_s(ques, 101);
	printf("\n  现在请输入密保问题的答案：\n\n  ");
	gets_s(as, 101);
	printf("\n  设置成功!");
	FILE *f;													//创建文件指针
	f = fopen("user.txt", "wb+");								//重新创建用户文件夹
	int a = strc(user), b = strc(password);						//分别数出二者长度
	int c = strc(ques), d = strc(as);							//密保问题和答案的长度
	fwrite(&a, sizeof(int), 1, f);								//保存新账户名长度
	fwrite(&b, sizeof(int), 1, f);								//保存新密码长度
	fwrite(user, sizeof(char), strc(user), f);					//写入新账户名
	fwrite(password, sizeof(char), strc(password), f);			//写入新密码
	fwrite(&c, sizeof(int), 1, f);								//保存密保问题长度
	fwrite(&d, sizeof(int), 1, f);								//保存答案长度
	fwrite(ques, sizeof(char), strc(ques), f);					//写入密保问题
	fwrite(as, sizeof(char), strc(as), f);						//写入答案
	fclose(f);
	printf("\n\n  已保存相关数据，按回车键返回主界面");
	getchar();
}

void czmk()														//查找模块
{
	int pd;
	printf("\n  请选择查找方式，按“姓名”查找输入 0，按“学号”查找输入 1： ");
	scanf_s("%d", &pd);		getchar();
	if (pd)
	{
		char id2[31];	s *czstd;								//创建对比字符串、查找指针
		printf("\n  请输入要查找的学生的学号： ");
		gets_s(id2, 31);
		czstd = cz(head, id2);									//查找指定学号的学生，找到返回结点地址，未找到返回 NULL
		if (czstd != NULL)
			opoint(czstd);										//输出查找到的单个结点
		else
			printf("\n  未查找到具有该学号的学生或数据文件为空");		//输出未找到的情况
		printf("\n\n  请按回车键返回主界面");
		getchar();
	}
	else
	{
		char name2[21];		s *czstd = head;					//创建对比字符串、查找指针
		printf("\n  请输入要查找的学生的姓名（会查找出所有同名的学生）： ");
		gets_s(name2, 21);
		if ((czstd = czn(head, name2)) != NULL)
		{
			printf("\n  查找到具有该姓名的学生如下：\n");
			for (; czstd != NULL; czstd = czn(czstd, name2))	//循环打印出所有同名学生
			{
				opoint(czstd);
				printf("\n");
			}
		}
		else
			printf("\n  未查找到具有该姓名的学生或数据文件为空");		//输出未找到的情况
		printf("\n  请按回车键返回主界面");
		getchar();
	}
}

void del()
{
	char id2[31];	int pd;		char enter[6];
	printf("\n  删除单个学生信息请输入 1，批量删除学生信息请输入 2，删除所有学生信息请输入 3：  ");
	scanf_s("%d", &pd);		getchar();
	if (pd == 1)												//删除单个的学生信息
	{
		s *stdq;												//存储匹配结点的前一个结点的地址
		printf("\n  请输入要删除的学生的学号： ");
		gets_s(id2, 31);
		stdq = (cz(head, id2))->last;							//找到匹配结点的前一个结点的地址
		if (stdq == NULL)
			printf("\n  没有匹配到具有该学号的学生");
		else
		{
			opoint(stdq->next);
			printf("\n\n  匹配到该学生，确定要删除么？"
				   "\n\n  确定删除请输入字符串“Enter”，否则输入任意字符或不输入： ");
			gets_s(enter, 6);
			if (strbj(enter, "Enter"))
			{
				//使匹配结点的前一个结点直接连到后一个结点，即跳过匹配结点，达到删除目的
				stdq->next = (stdq->next->next);
			}
			else
				printf("\n  不删除该学生信息");
		}
	}
	else if (pd == 2)													//删除一定范围内的学生信息
	{
		char id3[31];	s *stdq = head, *stdq2, *stdq3;
		printf("\n  请依次输入起始学号和终止学号（一个空格隔开，终止学号不能是已有最大学号），\n  二者和学号在其之间的学生"
			   "信息都会被删除，请输入学号：  ");
		scanf_s("%s %s", id2, 31, id3, 31);		getchar();
		order(head, 2);
		if (scbj(id3, tail->id) || scbj(id2, tail->id))
			printf("\n  学号不在已有数据范围之内！");
		else
		{
			stdq2 = stdq = (cz(head, id2))->last;						//保存 id2 前一结点地址
			for (stdq = stdq->next; 1; stdq = stdq->next)
			{
				if (scbj(stdq->id, id3))								//到达 id3 后一结点，保存，跳出
				{
					stdq3 = stdq;										//保存 id3 后一结点地址
					break;												//打印了 id2 到 id3 的所有学生，跳出
				}
				opoint(stdq);											//打印一个区间内的结点
				printf("\n");
			}
			printf("\n\n  匹配到以上学生，确定要删除么？"
				"\n\n  确定删除请输入字符串“Enter”，否则输入任意字符或不输入： ");
			gets_s(enter, 6);
			if (strbj(enter, "Enter"))
			{
				stdq = stdq2;											//还原 stdq 到 id2 的前一结点
				//循环释放要删除的结点
				for (stdq = stdq->next->next; stdq != stdq3; stdq = stdq->next)
					free(stdq->last);									//释放上一结点内存
				stdq2->next = stdq3;									//将 id2 前一结点与 id3 后一结点相连
			}
			else
				printf("\n  不删除这些学生信息");
		}
	}
	else if (pd == 3)													//删除所有学生信息
	{
		printf("\n  注意！你现在选择了删除所有学生信息！\n\n  确定删除请输入“Enter”： ");
		gets_s(enter, 6);
		if (strbj(enter, "Enter"))
		{
			for (; 1;)													//循环释放结点，遍历链表一次
			{
				tail = head->next;										//移动尾指针到头指针后
				free(head);												//释放头指针指向的结点
				if (tail->next == NULL)									//检测是否已释放完链表，若是释放尾结点并跳出
				{
					free(tail);											//释放尾结点
					break;												//跳出
				}
				head = tail;											//移动头指针到尾指针的位置
			}
			tail = (s*)malloc(sizeof(s));								//创建表尾
			scp(tail->id, "0", 2);										//标记表尾
			tail->next = NULL;											//初始化表尾 next 成员
			head = (s*)malloc(sizeof(s));								//创建表头
			head->next = tail;											//初始化表头 next 成员
		}
		else
			printf("\n  不删除学生信息");
	}
	if (head->next == NULL)												//预防链表为空的情况
	{
		tail = (s*)malloc(sizeof(s));									//创建表尾
		scp(tail->id, "0", 2);											//标记表尾
		tail->next = NULL;												//初始化表尾 next 成员
		head = (s*)malloc(sizeof(s));									//创建表头
		head->next = tail;												//初始化表头 next 成员
	}
	write(head);
	printf("\n\n  操作完毕，已保存修改，请按回车返回主界面");
	getchar();
}

void orders()
{
	int pd;		char xz[21];
	printf("\n  请选择排序方向，降序请输入 1，升序请输入 2： ");
	scanf_s("%d", &pd);		getchar();
	printf("\n  请选择排序项，可选的有“学号”、“语文”、“数学”、“英语”、“物理”、\n  "
			    "“化学”、“生物”、“政治”、“历史”、“地理”、“总分”、“平均”");
	printf("\n  请输入你选择的排序项： ");
	gets_s(xz, 21);
	if (strbj(xz, "学号"))
		order(head, pd);									//排序
	else if (strbj(xz, "语文"))
		order2(head, pd, 0);
	else if (strbj(xz, "数学"))
		order2(head, pd, 1);
	else if (strbj(xz, "英语"))
		order2(head, pd, 2);
	else if (strbj(xz, "物理"))
		order2(head, pd, 3);
	else if (strbj(xz, "化学"))
		order2(head, pd, 4);
	else if (strbj(xz, "生物"))
		order2(head, pd, 5);
	else if (strbj(xz, "政治"))
		order2(head, pd, 6);
	else if (strbj(xz, "历史"))
		order2(head, pd, 7);
	else if (strbj(xz, "地理"))
		order2(head, pd, 8);
	else if (strbj(xz, "总分"))
		order2(head, pd, 9);
	else if (strbj(xz, "平均"))
		order2(head, pd, 10);
	printf("\n  整个学生列表排序如下：\n");
	if (head->next != NULL)
		for (tail = head->next; 1; tail = tail->next)		//初始化尾指针到表头后，输出整个链表
		{
			opoint(tail);									//输出查找链表的一个结点
			printf("\n");									//在打印的结点信息间换行
			if (tail->next == NULL)	break;					//已打印完整个链表，跳出
		}
	else
		printf("\n  数据文件为空");							//输出未找到的情况
	write(head);
	printf("\n  排序完毕，已存储到数据文件中\n\n  ");
	printf("若个别顺序不正确，再进行一次排序即可解决\n");
	printf("\n  请按回车键返回主界面");
	getchar();
}

void reset()												//修改模块，修改某学生信息
{
	char id2[31];	s *czstd;	char xz[21];				//创建对比字符串、查找指针
	printf("\n  请输入要修改的学生的学号： ");
	gets_s(id2, 31);
	czstd = cz(head, id2);									//查找出指定学号的学生，找到返回结点地址，未找到返回 NULL
	if (czstd != NULL)
		opoint(czstd);										//输出查找到的单个结点
	else
		printf("\n  未找到具有该学号的学生或数据文件为空");			//输出未找到的情况
	if (czstd != NULL)
	{
		printf("\n\n  请问要修改该学生的哪一项？\n  输入“学号”、“姓名”、“性别”、“年龄”、“身份证号码”、"
			"  “家庭住址”、\n  “手机号”、“年级及班级”、“各科考试成绩”、“全部修改”即可: ");
		gets_s(xz, 21);
		if (strbj(xz, "学号"))
		{
			for (; 1;)
			{
				s *temp;
				printf("\n  请输入修改后学号： ");
				gets_s(czstd->id, 31);
				if ((temp = cz(head, czstd->id)) != NULL && temp != czstd)
					printf("\n  学号与现有学生重复，请重新输入！\n\n");
				else if (strc(czstd->id) == 0)
				{
					printf("\n  学号不能为空，请重新输入！\n\n");
					printf("  学号： ");
					gets_s(czstd->id, 31);
				}
				else
					break;
			}
		}
		else if (strbj(xz, "姓名"))
		{
			printf("\n  请输入修改后姓名： ");
			gets_s(czstd->name, 21);
		}
		else if (strbj(xz, "性别"))
		{
			printf("\n  请输入修改后性别： ");
			gets_s(czstd->xb, 9);
		}
		else if (strbj(xz, "年龄"))
		{
			printf("\n  请输入修改后年龄： ");
			gets_s(czstd->age, 10);
		}
		else if (strbj(xz, "身份证号码"))
		{
			printf("\n  请输入修改后身份证号码： ");
			gets_s(czstd->sfz, 31);
		}
		else if (strbj(xz, "家庭住址"))
		{
			printf("\n  请输入修改后家庭地址： ");
			gets_s(czstd->addr, 101);
		}
		else if (strbj(xz, "手机号"))
		{
			printf("\n  请输入修改后手机号： ");
			gets_s(czstd->phone, 21);
		}
		else if (strbj(xz, "年级及班级"))
		{
			printf("\n  请输入修改后年级及班级： ");
			gets_s(czstd->class, 41);
		}
		else if (strbj(xz, "各科考试成绩"))
		{
			printf("\n  语文： ");
			scanf_s("%lf", &czstd->score[0]);	getchar();
			printf("\n  数学： ");
			scanf_s("%lf", &czstd->score[1]);	getchar();
			printf("\n  英语： ");
			scanf_s("%lf", &czstd->score[2]);	getchar();
			printf("\n  物理： ");
			scanf_s("%lf", &czstd->score[3]);	getchar();
			printf("\n  化学： ");
			scanf_s("%lf", &czstd->score[4]);	getchar();
			printf("\n  生物： ");
			scanf_s("%lf", &czstd->score[5]);	getchar();
			printf("\n  政治： ");
			scanf_s("%lf", &czstd->score[6]);	getchar();
			printf("\n  历史： ");
			scanf_s("%lf", &czstd->score[7]);	getchar();
			printf("\n  地理： ");
			scanf_s("%lf", &czstd->score[8]);	getchar();
			int i = 0;
			for (czstd->score[9] = 0; i < 9; i++) czstd->score[9] += czstd->score[i];		//计算总分
			czstd->score[10] = czstd->score[9] / 6.0;										//计算平均分
		}
		else if (strbj(xz, "全部修改"))
		{
			printf("\n  请输入修改后学号： ");
			gets_s(czstd->id, 31);
			printf("\n  请输入修改后姓名： ");
			gets_s(czstd->name, 21);
			printf("\n  请输入修改后性别： ");
			gets_s(czstd->xb, 9);
			printf("\n  请输入修改后年龄： ");
			gets_s(czstd->age, 10);
			printf("\n  请输入修改后身份证号码： ");
			gets_s(czstd->sfz, 31);
			printf("\n  请输入修改后家庭地址： ");
			gets_s(czstd->addr, 101);
			printf("\n  请输入修改后手机号： ");
			gets_s(czstd->phone, 21);
			printf("\n  请输入修改后年级及班级： ");
			gets_s(czstd->class, 41);
			printf("\n  语文： ");
			scanf_s("%lf", &czstd->score[0]);	getchar();
			printf("\n  数学： ");
			scanf_s("%lf", &czstd->score[1]);	getchar();
			printf("\n  英语： ");
			scanf_s("%lf", &czstd->score[2]);	getchar();
			printf("\n  物理： ");
			scanf_s("%lf", &czstd->score[3]);	getchar();
			printf("\n  化学： ");
			scanf_s("%lf", &czstd->score[4]);	getchar();
			printf("\n  生物： ");
			scanf_s("%lf", &czstd->score[5]);	getchar();
			printf("\n  政治： ");
			scanf_s("%lf", &czstd->score[6]);	getchar();
			printf("\n  历史： ");
			scanf_s("%lf", &czstd->score[7]);	getchar();
			printf("\n  地理： ");
			scanf_s("%lf", &czstd->score[8]);	getchar();
			int i = 0;
			for (czstd->score[9] = 0; i < 9; i++) czstd->score[9] += czstd->score[i];		//计算总分
			czstd->score[10] = czstd->score[9] / 6.0;										//计算平均分
		}
		write(head);
		printf("\n  修改完毕，已将修改写入数据文件中\n");
	}
	printf("\n\n  按回车键返回主界面");
	getchar();
}

void lfor()														//使用密保问题重置账户模块
{
	system("cls");
	char ques[101], as[101], as2[101];	int a, b, c, d;
	FILE *f;													//创建文件指针
	f = fopen("user.txt", "rb");								//以只读方式打开用户文件夹
	fread(&a, sizeof(int), 1, f);								//读取账户名的长度
	fread(&b, sizeof(int), 1, f);								//读取密码的长度
	fread(user, sizeof(char), a, f);							//读取账户名
	fread(password, sizeof(char), b, f);						//读取密码
	fread(&c, sizeof(int), 1, f);								//读取密保问题的长度
	fread(&d, sizeof(int), 1, f);								//读取答案的长度
	fread(ques, sizeof(char), c, f);							//读取密保问题
	fread(as, sizeof(char), d, f);								//读取答案
	fclose(f);
	ques[c] = '\0';		as[d] = '\0';
	printf("\n  请输入密保问题答案：（若未修改过账户名和密码，请直接退出）\n\n");
	printf("  %s", ques);
	printf("\n\n  请输入答案： ");
	gets_s(as2, 101);
	if (strbj(as2, as))
	{
		printf("\n  答案正确!现在开始重置账户名和密码：");
		printf("\n\n  请输入修改后的账户名（可包含任意字符）： ");
		gets_s(user, 101);
		printf("\n  修改成功，当前账户名是：%s", user);
		printf("\n\n  请输入修改后的密码（可包含任意字符），只能一次性输入，不能退格： ");
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
		printf("\n\n  修改密码成功");
		FILE *f;													//创建文件指针
		f = fopen("user.txt", "wb+");								//重新创建用户文件夹
		int a = strc(user), b = strc(password);						//分别数出二者长度
		fwrite(&a, sizeof(int), 1, f);								//保存新账户名长度
		fwrite(&b, sizeof(int), 1, f);								//保存新密码长度
		fwrite(user, sizeof(char), strc(user), f);					//写入新账户名
		fwrite(password, sizeof(char), strc(password), f);			//写入新密码
		fwrite(&c, sizeof(int), 1, f);								//保存密保问题长度
		fwrite(&d, sizeof(int), 1, f);								//保存答案长度
		fwrite(ques, sizeof(char), strc(ques), f);					//写入密保问题
		fwrite(as, sizeof(char), strc(as), f);						//写入答案
		fclose(f);
		printf("\n\n  已保存新用户名和密码，按回车键进入系统");
		getchar();
	}
	else
	{
		printf("\n  答案错误，退出 . . .\n\n  ");
		exit(0);
	}
}

void temp(int x, double line, char *xz)				//统计模块所需的临时函数
{
	s *bl;		double bjg = 0, nums = 0;			//查找不及格结点的指针、不及格人数、总人数
	for (bl = head->next, nums++; ; bl = bl->next, nums++)
	{
		if (bl->score[x] < line)
		{
			printf("\n  学号：%s\n  姓名：%s\t\t年级及班级：%s\n  %s成绩： %g\n"
				, bl->id, bl->name, bl->class, xz, bl->score[x]);
			bjg++;
		}
		if (bl->next == NULL)	break;
	}
	printf("\n  以上是不及格名单\n  总人数： %g\t不及格人数： %g", nums, bjg);
	printf("\n  及格线： %g\n  %s的及格率是： %.2lf%%\n", line, xz, 100 * (1 - (bjg / nums)));
}
void tj()
{
	char xz[21];	double line;
	printf("\n  求平均成绩、及格率、打印全部不及格名单\n  "
		   "请选择科目，可选的有“语文”、“数学”、“英语”、“物理”、\n  "
		   "“化学”、“生物”、“政治”、“历史”、“地理”、“总分”、“全部”(只显示平均分)。"
		   "\n\n  请输入科目名称： ");
	gets_s(xz, 21);
	printf("\n  请输入及格线： ");
	scanf_s("%lf", &line);	getchar();
	system("cls");
	if (strbj(xz, "语文") || strbj(xz, "数学") || strbj(xz, "英语") || strbj(xz, "物理") || strbj(xz, "化学")
		|| strbj(xz, "生物") || strbj(xz, "政治") || strbj(xz, "历史") || strbj(xz, "地理") || strbj(xz, "总分"))
	{
		double value;
		void temp(int x,double line);					//定义函数，根据参数选择科目，计算及格率并输出不及格名单
		if (strbj(xz, "语文"))
		{
			value = pjz(head, 0);						//计算平均值
			temp(0, line, xz);
		}
		else if (strbj(xz, "数学"))
		{
			value = pjz(head, 1);
			temp(1, line, xz);
		}
		else if (strbj(xz, "英语"))
		{
			value = pjz(head, 2);
			temp(2, line, xz);
		}
		else if (strbj(xz, "物理"))
		{
			value = pjz(head, 3);
			temp(3, line, xz);
		}
		else if (strbj(xz, "化学"))
		{
			value = pjz(head, 4);
			temp(4, line, xz);
		}
		else if (strbj(xz, "生物"))
		{
			value = pjz(head, 5);
			temp(5, line, xz);
		}
		else if (strbj(xz, "政治"))
		{
			value = pjz(head, 6);
			temp(6, line, xz);
		}
		else if (strbj(xz, "历史"))
		{
			value = pjz(head, 7);
			temp(7, line, xz);
		}
		else if (strbj(xz, "地理"))
		{
			value = pjz(head, 8);
			temp(8, line, xz);
		}
		else if (strbj(xz, "总分"))
		{
			value = pjz(head, 9);
			temp(9, line, xz);
		}
		printf("  %s的平均成绩是： %g", xz, value);
	}
	else if (strbj(xz, "全部"))
	{
		double value[10];	int i;
		for (i = 0; i < 10; i++)
			value[i] = pjz(head, i);
		printf("\n  语文：%g\n  数学：%g\n  英语：%g\n  物理：%g\n  化学：%g\n  生物：%g\n  政治：%g\n  历史：%g\n  "
			   "地理：%g\n  总分：%g"
		, value[0], value[1], value[2], value[3], value[4], value[5], value[6], value[7], value[8], value[9]);
	}
	printf("\n\n  按回车键返回主界面");
	getchar();
}

void infix()												//插入模块，在某结点后插入一个结点
{
	char id2[31];	s *czstd, *temp;						//创建对比字符串、查找指针
	int i;		s *std = (s*)malloc(sizeof(s));				//循环变量 i、创建临时结点并将其地址返回给 std
	printf("\n  请输入一个已有学生的学号，将在其后插入新学生的信息： ");
	gets_s(id2, 31);
	czstd = cz(head, id2);									//查找指定学号的学生，找到返回结点地址，未找到返回 NULL
	if (czstd != NULL)
		opoint(czstd);										//输出查找到的单个结点
	else
		printf("\n  未查找到具有该学号的学生或数据文件为空");		//输出未找到的情况
	printf("\n\n  现在开始输入要插入的学生的信息：\n");
	//开始获取数据
	for (; 1;)
	{
		printf("  学号： ");
		gets_s(std->id, 31);
		if (cz(head, std->id) != NULL)
			printf("\n  学号与现有学生重复，请重新输入！\n\n");
		else if (strc(std->id) == 0)
		{
			printf("\n  学号不能为空，请重新输入！\n\n");
			printf("  学号： ");
			gets_s(std->id, 31);
		}
		else
			break;
	}
	printf("  姓名： ");
	gets_s(std->name, 21);
	printf("  性别： ");
	gets_s(std->xb, 9);
	printf("  年龄： ");
	gets_s(std->age, 10);
	printf("  身份证： ");
	gets_s(std->sfz, 31);
	printf("  家庭住址： ");
	gets_s(std->addr, 101);
	printf("  手机号： ");
	gets_s(std->phone, 21);
	printf("  年级及班级： ");
	gets_s(std->class, 41);
	printf("  现在开始录入学生考试成绩：\n");
	printf("\n  语文： ");
	scanf_s("%lf", &std->score[0]);	getchar();
	printf("\n  数学： ");
	scanf_s("%lf", &std->score[1]);	getchar();
	printf("\n  英语： ");
	scanf_s("%lf", &std->score[2]);	getchar();
	printf("\n  物理： ");
	scanf_s("%lf", &std->score[3]);	getchar();
	printf("\n  化学： ");
	scanf_s("%lf", &std->score[4]);	getchar();
	printf("\n  生物： ");
	scanf_s("%lf", &std->score[5]);	getchar();
	printf("\n  政治： ");
	scanf_s("%lf", &std->score[6]);	getchar();
	printf("\n  历史： ");
	scanf_s("%lf", &std->score[7]);	getchar();
	printf("\n  地理： ");
	scanf_s("%lf", &std->score[8]);	getchar();
	for (i = 0, std->score[9] = 0; i < 9; i++) std->score[9] += std->score[i];		//计算总分
	std->score[10] = std->score[9] / 6.0;											//计算平均分
	//获取数据完毕，创建一个新结点保存临时结点所有数据，插入到指定位置
	temp = czstd->next;											//保存查找结点下一结点的地址
	czstd->next = new(std->id, std->name, std->xb, std->age, std->sfz, std->addr, std->phone, std->class, std->score);
	czstd->next->next = temp;									//使新结点的 next 指向其下一结点
	czstd->next->last = czstd;									//使新结点的 last 指向其上一结点
	write(head);
	printf("\n\n  已将该学生信息插入到数据文件中");
	printf("\n\n  请按回车键返回主界面");
	getchar();
}

void exits()													//在关闭程序时，释放所有存储链表所占用的内存空间
{
	for (; 1;)													//循环释放结点，遍历链表一次
	{
		tail = head->next;										//移动尾指针到头指针后
		free(head);												//释放头指针指向的结点
		if (tail->next == NULL)									//检测是否已释放完链表，若是释放尾结点并跳出
		{
			free(tail);											//释放尾结点
			break;												//跳出
		}
		head = tail;											//移动头指针到尾指针的位置
	}
	printf("\n\n\n\n\n\n                                 已 释 放 所 有 链 表 结 点 占 用 的 内 存\n\n"
		   "                                 退 出 程 序 . . .\n\n                                 ");
	Sleep(1000);
	exit(0);
}

/*
经验: 1. 如果程序中要用到 gets_s() 函数，那每次使用 scanf_s() 函数后要跟 getchr() 消除遗留的回车符
	 2. 使用链表时，时刻要记得更新尾指针指向尾结点
	 3. 链表每个新创建的结点，其 next 成员要初始化为 NULL
	 4. 所有字符型数据用 gets_s()，所有数值型数据用 scanf_s()
	 5. 高效的算法也往往是简洁的，它的基本原理必须是简洁甚至简单的，不然人类无法做到思考基本原理就很复杂的算法，BUG 太多
*/