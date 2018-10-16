#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
/*
四则运算的中缀表达式转后缀表达式，这个在编译器上经常用到，中缀表达式便于人类理解，而后缀表达式便于计算机计算。下面代码的功能是利用栈将
中缀表达式转为后缀表达式、计算出后缀表达式的值。
*/

typedef struct s											//顺序栈
{
	char c[1000];											//栈中元素
	int top;												//栈顶指针
}s;

typedef struct s2											//顺序栈
{
	double c[1000];											//栈中元素
	int top;												//栈顶指针
}s2;

int pdop(char x, char y);									//判断两运算符优先级，x 高返回 1，y 高或相等返回 0

int pdop2(char x, char y);									//判断两运算符优先级，x 高返回 1，y 高或相等返回 0

void zh(char *x, s *y);										//将 x 转换成后缀表达式 y

double end(char *x);										//计算一个后缀表达式的值

int main()
{
	char x[1000];	s y;	y.top = -1;
	printf("\n  请输入中缀表达式(只能含 +、-、*、/、（、）)： ");
	scanf_s("%s", x, 1000);
	zh(x, &y);
	printf("\n  转换后： %s\n\n  计算结果为： %g\n\n  ", y.c, end(y.c));
	return 0;
}

int pdop(char x, char y)									//判断两运算符优先级，x 高返回 1，y 高或相等返回 0
{
	if (x == '(' || y == '(')	return 1;
	if ((x == '*' || x == '/') && (y != '*' && y != '/'))	return 1;
	return 0;
}

int pdop2(char x, char y)									//判断两运算符优先级，x 高返回 1，y 高或相等返回 0
{
	if (x == '(' || y == '(')	return 1;
	if ((x == '*' || x == '/') && (y != '*' && y != '/'))	return 1;
	if ((x == '+' || x == '-') && (y == '+' || y == '-'))	return 1;
	return 0;
}

void zh(char *x, s *y)										//将 x 转换成后缀表达式 y
{
	s z;	int i;		z.top = -1;
	for (i = 0; x[i] != '\0'; )
	{
		if ((x[i] > 47) && (x[i] < 58))						//操作数，直接压入
			y->c[++(y->top)] = x[i++];
		else												//操作符
			if (z.top == -1)								//空栈，直接压入
				z.c[++(z.top)] = x[i++];
			else											//不是空栈
				if (x[i] == ')')							//先判断是否是右括号
				{
					for (; z.c[z.top] != '('; y->c[++(y->top)] = z.c[(z.top)--]);
					z.top--;		i++;					//跳过 (，更新 i
				}
				else if (pdop(x[i], z.c[z.top]))			//判断优先级
					z.c[++(z.top)] = x[i++];				//前者优先级高，压入
				else										//后者优先级高
				{
					if (z.c[(z.top)] != '(')				//弹出 z 中优先级 >= x[i] 的操作符压入 y 中
						for (; pdop2(z.c[z.top], x[i]) && (z.top > -1) && (z.c[z.top] != '(');)
							y->c[++(y->top)] = z.c[(z.top)--];
					z.c[++(z.top)] = x[i++];				//将读到的操作符压入 z 中
				}
	}
	if (z.top != -1)
		for (; z.top != -1;)								//弹出 z 中所有元素
			y->c[++(y->top)] = z.c[(z.top)--];
	y->c[++(y->top)] = '\0';
}

double end(char *x)											//计算一个栈中的后缀表达式
{
	s2 a;		a.top = -1;
	for (; *x != '\0'; x++)
	{
		if (*x > 47 && *x < 58)	a.c[++a.top] = (double)(*x - 48);	//压入操作数
		else
			switch (*x)
			{
			case '+':
				a.c[a.top - 1] = a.c[a.top - 1] + a.c[a.top];
				a.top--;
				break;
			case '-':
				a.c[a.top - 1] = a.c[a.top - 1] - a.c[a.top];
				a.top--;
				break;
			case '*':
				a.c[a.top - 1] = a.c[a.top - 1] * a.c[a.top];
				a.top--;
				break;
			case '/':
				a.c[a.top - 1] = a.c[a.top - 1] / a.c[a.top];
				a.top--;
				break;
			}
	}
	return a.c[0];
}

/*
思路：

转换过程需要用到栈，具体过程如下：

1）从左到右遍历中缀字符串，如果遇到操作数，直接压到栈 y 中。

2）如果遇到操作符，则压入到栈 x 中，遇到左括号同样压入栈 x 中。

3）当遇到右括号，则将栈 x 中操作符弹出压入栈 y 中直到遇到左括号为止。注意，左、右括号均不压入栈 y 中。

4）如果遇到非括号的操作符，从栈 x 中弹出操作符直到遇到更低优先级的操作符(或栈空)为止。弹出完这些操作符后，再将遇到的操作符压入到栈
x 中。有一点要注意，只有在遇到" ) "的情况下才弹出" ( "，其他情况下都不弹出" ( "，即”( ”的优先级最高。

5）当整个中缀表达式已被读完，则将栈 x 中所有元素依次弹出压入到栈 y 中，此时栈 y 中的字符串即后缀表达式。

计算就很简单了，遍历字符串，遇到操作数压入栈中，遇到操作符弹出栈顶的两个元素进行运算，再将结果压入栈中，如此循环直到计算完毕。
*/