#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.
*/

typedef struct
{
	int x[8000];										//��ջ����
	int top;											//ջ��ָ��
	int min[4000];										//��С����ջ
	int top2;											//��С��ջ��ָ��
}MinStack;

MinStack *minStackCreate(int maxSize)					//����ջ
{
	MinStack *x = (MinStack*)malloc(sizeof(MinStack));
	x->top = -1;
	x->top2 = -1;
	return x;
}

void minStackPush(MinStack *obj, int x)					//ѹջ
{
	obj->x[++obj->top] = x;								//ѹջ
	if (obj->top == 0)									//����һ������Ҳѹ����С����ջ
		obj->min[++obj->top2] = x;
	else if (obj->x[obj->top] <= obj->min[obj->top2])	//����Ƿ�����С����ջѹ��
		obj->min[++obj->top2] = obj->x[obj->top];
}

void minStackPop(MinStack* obj)							//��ջ
{
	if (obj->min[obj->top2] == obj->x[obj->top])		//���ջ��������С����ջ��ջ��������ջ
	{
		obj->top--;
		obj->top2--;
	}
	else
	obj->top--;
}

int minStackTop(MinStack* obj)							//��ȡջ��Ԫ��ֵ
{
	return obj->x[obj->top];
}

int minStackGetMin(MinStack* obj)						//�ҵ���СԪ��
{
	return obj->min[obj->top2];
}

void minStackFree(MinStack* obj)						//�ͷ�ջ
{
	free(obj);
}

int main()
{
	
	return 0;
}
/*
˼·��
�ܼ򵥣�������ջ������ջ����С����ջ��ÿ�ε�ѹ�����С��ջ��������ʱ��ѹ����С����ջ��ÿ�γ�ջʱ���ջ���Ƿ�����С����ջ��ջ����ͬ����
���򶼳�ջ������ֻ������ջ��ջ��
*/