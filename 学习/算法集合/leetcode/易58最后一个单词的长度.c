#include<stdio.h>
#include<stdlib.h>
/*
原题：
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/

int lengthOfLastWord(char* s)
{
	int len;
	for (len = 0; *s != '\0';)
	{
		for (; *s == ' '; s++);						//跳过空格
		if (*s != '\0')								//如果未到末尾，开始计算
			for (len = 0; *s != ' ' && *s != '\0'; len++, s++);
	}
	return len;
}

int main()
{
	char s[100] = "a ";
	printf("%d", lengthOfLastWord(s));
	return 0;
}
/*
思路：
遍历字符串，先跳过空格，然后判断是否到字符串末尾，若是则结束，否则开始数单词长度，循环该过程。
*/