#include<stdio.h>
#include<stdlib.h>
/*
原题：
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

char* longestCommonPrefix(char** strs, int strsSize)
{
	char *a = (char*)malloc(200 * sizeof(char));	int i, j;
	for (i = 0, a[i] = '\0'; strs[0][i] >= 'a'&& strs[0][i] <= 'z'; a[i] = strs[0][i], a[i + 1] = '\0', i++)
		for (j = 0; j < strsSize - 1; j++)
			if (strs[j][i] != strs[j + 1][i])
				return a;
	return a;
}

char *scp(char *x, char *y)
{
	for (*x = *y; *y != '\0'; *(++x) = *(++y));
}

int main()
{
	char *str[3], **strs = str;		int i;
	for (i = 0; i < 3; i++)		str[i] = (char*)malloc(100 * sizeof(char));
	scp(str[0], "dog");
	scp(str[1], "racecar");
	scp(str[2], "car");
	printf("%s", longestCommonPrefix(strs, 3));
	return 0;
}

/*
思路：双层循环，每次比较一列是否相同，相同存入该字符，否则返回字符串。
*/