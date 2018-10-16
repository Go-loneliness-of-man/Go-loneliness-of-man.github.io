#include<stdio.h>
#include<stdlib.h>
//C语言动态数组，利用 malloc() 和指针实现动态数组

//一维动态数组
int main()
{
	int *a, b;
	scanf_s("%d", &b);
	a = (int *)malloc(b * sizeof(char));
	free(a);
	return 0;
}
/*
思路：C 语言的一维数组就是一整块内存，编译器会根据元素类型的长度进行访问，所以不用担心访问的问题。上面代码创建了一个长度为 b 的字符数组。
*/
/**/

//二维动态数组，第一种：利用循环声明第二维
int main()
{
	int **a, b, c, i;
	scanf_s("%d%d", &b, &c);
	a = (int **)malloc(b * sizeof(char*));						//申请第一维内存及地址
	for (i = 0; i < b; i++)										//申请第二维内存及地址
		a[i] = (int *)malloc(c * sizeof(char));
	for (i = 0; i < b; i++)	free(a[i]);							//释放
	free(a);
	return 0;
}
/*
思路：二维数组名是个二级指针，指向一个一级指针数组，而指针数组的每个元素又指向一个数组，这就是二维数组。上面的代码就是据此创建的二维数
组。
*/
/**/

//二维动态数组，第二种：直接指定第二维长度，第一维由编译器自动计算
int main()
{
	int b;
	scanf_s("%d", &b);
	int (*a)[10] = (int (*)[10])malloc(b * sizeof(char*) * 10);	//一次性申请第一维和第二维
	free(a);
	return 0;
}
/*
思路：这种方法的缺点是第二维长度不变，优点是只需要申请一次，释放也只需要一次。声明多维数组，除最高维外，其它维都要指明长度。
*/
/**/