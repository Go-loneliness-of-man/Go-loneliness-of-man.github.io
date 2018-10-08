#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

#define PD(x) ((x>47&&x<58)||(x>64&&x<91)||(x>96&&x<123))		//判断是否是字母或数字字符，是则真

bool isPalindrome(char* s)
{
	int len, i, j;
	for (len = 0; s[len] != '\0'; len++);						//数出长度
	for (i = 0, j = len - 1; i < j; i++, j--)					//首尾比较
	{
		if (!PD(s[i]))	for (; !PD(s[i]) && i<len; i++);		//跳过不是字母或数字的部分
		if (!PD(s[j]))	for (; !PD(s[j]) && j<len; j--);
		if (PD(s[i]) && PD(s[j]) && (!(s[i] == s[j] || (s[i] > 96 && s[i] - 32 == s[j]) || (s[j] > 96 && s[j] - 32 == s[i]))))
			return false;										//两字母不相等
	}
	return true;
}

int main()
{
	char a[100] = "0P";
	printf("%d", isPalindrome(a));
	return 0;
}

/*
思路：
数出长度，从首位开始依次比较，只比较字母和数字字符，遇到其它字符跳过。
注：不区分字母大小写可通过 ASCⅡ 码计算实现。
*/