#include<stdio.h>
#include<stdlib.h>
/*
原题：
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

typedef struct
{
	int x[8000];										//入栈数字
	int top;											//栈顶指针
	int min[4000];										//最小数字栈
	int top2;											//最小数栈顶指针
}MinStack;

MinStack *minStackCreate(int maxSize)					//创建栈
{
	MinStack *x = (MinStack*)malloc(sizeof(MinStack));
	x->top = -1;
	x->top2 = -1;
	return x;
}

void minStackPush(MinStack *obj, int x)					//压栈
{
	obj->x[++obj->top] = x;								//压栈
	if (obj->top == 0)									//将第一个数字也压入最小数字栈
		obj->min[++obj->top2] = x;
	else if (obj->x[obj->top] <= obj->min[obj->top2])	//检测是否向最小数字栈压入
		obj->min[++obj->top2] = obj->x[obj->top];
}

void minStackPop(MinStack* obj)							//出栈
{
	if (obj->min[obj->top2] == obj->x[obj->top])		//如果栈顶等于最小数字栈的栈顶，均出栈
	{
		obj->top--;
		obj->top2--;
	}
	else
	obj->top--;
}

int minStackTop(MinStack* obj)							//获取栈顶元素值
{
	return obj->x[obj->top];
}

int minStackGetMin(MinStack* obj)						//找到最小元素
{
	return obj->min[obj->top2];
}

void minStackFree(MinStack* obj)						//释放栈
{
	free(obj);
}

int main()
{
	
	return 0;
}
/*
思路：
很简单，用两个栈，数字栈、最小数字栈，每次当压入的数小于栈内所有数时便压入最小数字栈，每次出栈时检测栈顶是否与最小数字栈的栈顶相同，若
是则都出栈，否则只有数字栈出栈。
*/