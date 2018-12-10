#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/

/*
//方法一，老老实实建立哈希表，运行时间 8ms
typedef struct jg
{
	char c;
	int count;
}jg;

void sort(jg *s, int len)								//选择排序
{
	int min, i, j;	jg temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = min = i; j < len; j++)					//找到后方的最小数
			if (s[min].c > s[j].c)	min = j;
		if (min == i)	continue;						//未找到，不交换
		temp = s[min];
		s[min] = s[i];
		s[i] = temp;
	}
}

bool isAnagram(char *s, char *t)
{
	int i, j, k, len1, len2;	jg x[1000], y[1000];	//循环变量 i 和 j 和 k、字符表长度 len、字符表 x
	for (i = 0; i < 1000; i++)							//初始化计数
		x[i].count = y[i].count = 1;
	for (i = len1 = 0; s[i] != '\0'; i++)				//遍历字符串 s 得到其字符表 x
	{
		for (j = 0; j < len1; j++)						//检测该字符是否已出现过
			if (x[j].c == s[i])							//已出现过，计数加 1 并跳出
			{
				x[j].count++;
				break;
			}
		if (j == len1)	x[len1++].c = s[i];				//存储该字符到字符表中
	}
	for (i = len2 = 0; t[i] != '\0'; i++)				//遍历字符串 t 得到其字符表 y
	{
		for (j = 0; j < len2; j++)						//检测该字符是否已出现过
			if (y[j].c == t[i])							//已出现过，计数加 1 并跳出
			{
				y[j].count++;
				break;
			}
		if (j == len2)	y[len2++].c = t[i];				//存储该字符到字符表中
	}
	sort(x, len1);	sort(y, len2);						//对字符表进行排序
	if (len1 != len2)	return false;					//判断字符种类数是否相同
	for (i = 0; i < len1; i++)							//判断种类、每种的个数是否相同
		if (x[i].c != y[i].c)							//判断种类
			return false;
		else if (x[i].count != y[i].count)				//判断个数
			return false;
	return true;										//种类、个数均相同
}
*/

//方法二：利用 leetcode 的样例只有字母而进行取巧，运行时间 0 ms
bool isAnagram(char *s, char *t)
{
	int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++)	x[s[i] - 'a']++;	//建立 s 的字符表 x
	for (i = 0; t[i] != '\0'; i++)	y[t[i] - 'a']++;	//建立 t 的字符表 y
	for (i = 0; i < 26; i++)							//比较两字符表是否相同
		if (x[i] != y[i])	return false;
	return true;										//种类、个数均相同
}

int main()
{
	char s[1000] = "anagram", t[1000] = "nagaram";
	printf("%d", isAnagram(s, t));
	return 0;
}

/*
思路：
字母异位，即字母种类、各字母出现次数都是相同的，只是排列顺序不同。
根据两字符串分别建立哈希表比对即可，由于 leetcode 的样例只有字母，所以可进行取巧，即用长度为 26 位的数组来表示各个字母的出现次数，这
样在建立哈希表时给每个字母减去 'a'，用得到的值作为下标进行计数即可。
老实建哈希表就比较麻烦，需要建立包含一个字符 c、计数变量 count 的结构，声明结构体数组，每种字符只在数组内存一次，下次再碰到就只增加计
数，做好两字符串的哈希表后再对二者进行排序，最后再比较即可。
*/