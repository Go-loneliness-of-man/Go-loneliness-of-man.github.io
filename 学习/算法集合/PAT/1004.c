#include<stdio.h>
typedef struct sutdent {
	char name[21];
	char id[21];
	int scoure;
	struct sutdent *next;
} s;

s *head, *tail, *temp, *max, *min;		//头指针、尾指针、临时指针、最大值指针、最小值指针

int main()
{
	int n, i;		head = (s*)malloc(sizeof(s));	head->next = NULL;
	//学生数量 n、循环变量 i、创建表头、初始化表头 next
	scanf("%d", &n);		getchar();							//获取学生数量
	for (i = 0; i < n; i++)
	{
		if (head->next == NULL)									//赋值表头，创建、初始化表尾
		{
			scanf("%s%s%d", &(head->name), &(head->id), &(head->scoure));	getchar();
			tail = (s*)malloc(sizeof(s));		tail->next = NULL;
			head->next = tail;
		}
		else													//赋值表尾，创建、初始化新的表尾
		{
			scanf("%s%s%d", &(tail->name), &(tail->id), &(tail->scoure));	getchar();
			temp = tail;
			tail = (s*)malloc(sizeof(s));		tail->next = NULL;
			temp->next = tail;									//将表尾与前一结点连接
		}
	}
	for (temp = max = min = head; 1 ; temp = temp->next)		//遍历链表
	{
		if (temp->scoure > max->scoure)		max = temp;			//筛选出最大者
		if (temp->scoure < min->scoure)		min = temp;			//筛选出最小者
		if (temp->next->next == NULL)		break;				//末尾跳出
	}
	printf("%s %s\n%s %s", max->name, max->id, min->name, min->id);
	return 0;
}

/*
思路：
定义学生结构体 student 并用 typedef 缩写为 s，创建动态链表读入数据。遍历链表，找出最大者、最小者，输出。
*/

/*
原题：
1004 成绩排名（20 分）
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：
每个测试输入包含 1 个测试用例，格式为

第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/