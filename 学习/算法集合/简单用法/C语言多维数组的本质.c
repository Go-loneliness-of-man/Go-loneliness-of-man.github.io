#include<stdio.h>
#include<stdlib.h>
//C 语言多维数组的本质
/*
	C 语言多维数组在本质上利用的是多级指针，例如二维数组 a[i][j]，引用时也可以写成 (*(a + 偏移量))[N] 这种形式，这里的偏移量就是
	行，每一个偏移量向下移动一行，之所以这样的原因是二维数组的数组名就是个二级指针（不是二级指针变量，是二级指针常量，其本身的值不能改
	变），其指向每一行的首个数组元素，因此进行一次取值后就相当于一维数组的数组名。下面是基于此对二维数组的示例，注意看其中是如何表示二
	维数组的。
注意：
	数组下标 [] 优先级高于取值运算符 *，因此要加上圆括号。
*/

#define N 6

void o(int (*a)[N]);								//打印二维数组一次

int main()
{
	int a[N][N], i, j, x = 1;						//声明二维数组、循环变量 i 和 j、偏移量 x
	for (i = 0; i < N; i++)							//为二维数组赋值
		for (j = 0; j < N; j++)
			(*(a + i))[j] = rand() % 100;
	printf("\n  整个二维数组如下：\n\n");
	o(a);											//打印整个二维数组
	printf("\n  二维数组第 %d 行如下：\n\n", x + 1);
	for (int j = 0; j < N; j++)						//打印具体的某一行
	{
		printf("%6d", (*(a + x))[j]);
		if (j + 1 == N) printf("\n");
	}
	printf("\n  ");
	printf("二维数组名基类型的长度： %zd\n\n  ", sizeof(*a));	//测量二维数组名的基类型
	printf("对二维数组名进行两次取值的结果： %d\n\n  ", **a);		//测量
	return 0;
}

void o(int (*a)[N])									//打印二维数组一次
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			printf("%6d", (*(a + i))[j]);
			if (j + 1 == N) printf("\n");
		}
}
/*
结尾：
	二维数组的数组名是个二级指针，其指向第一列数组元素（即每行的首个数组元素）构成的数组，这个结论可由程序中测量得出的二维数组名基类
	型长度得出（基类型就是它所指向的那一行数组）。
	最后，以上讨论的都是逻辑概念上的意义，在空间上，多维数组在内存中都是线性连续存储的一整条数据。
*/