#include<stdio.h>
#include<stdlib.h>
/*
原题：
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

int strStr(char* haystack, char* needle)
{
	if (*needle == '\0')	return 0;
	for (int i = 0; *haystack != '\0'; haystack++, i++)	//遍历 haystack
		if (*haystack == *needle)						//查找到首字符
			if (sbj(haystack, needle))					//比较后方字符是否相等
				return i;								//返回下标
	return -1;											//不存在
}

int sbj(char *x, char *y)
{
	for (; *x != '\0'&&*y != '\0'; x++, y++)			//比较其后字符是否相同
		if (*x != *y)	return 0;						//不同
	if (*y != '\0')	return 0;							//y 未比较完 x 已结束，不同
	return 1;
}

int main()
{
	char a[100] = "babsabba", b[100] = "bb";
	printf("%d", strStr(a, b));
	return 0;
}

/*
思路：
从 haystack 中查找 needle 的首个字符，若相等，则比较其后字符是否也相等，若是，则找到，否则继续向后查找
注意：
*/