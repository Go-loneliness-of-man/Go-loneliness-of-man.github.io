#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
原题：
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。
*/

int x(int *nums, char *s)							//求出一个字符串的通项公式并存储到数组中，返回数组长度
{
	int i, j, k, len;	char x[129];				//循环变量 i 和 j 和 k、字符表长度 len、字符表 x
	for (i = len = 0; s[i] != '\0'; i++)			//遍历字符串得到字符表
	{
		for (j = 0; j < len; j++)					//检测该字符是否已出现过
			if (x[j] == s[i])	break;
		if (j == len)	x[len++] = s[i];			//存储该字符到字符表中
	}
	for (i = k = 0; s[i] != '\0'; i++)				//通过字符表求该字符串的通项公式
		for (j = 0; j < len; j++)					//在字符表中查询该字符的字符编码并存储
			if (x[j] == s[i])
			{
				nums[k++] = j;
				break;
			}
	return k;
}

bool isIsomorphic(char* s, char* t)
{
	int nums1[100000], nums2[100000], i, len1, len2;
	len1 = x(nums1, s);		len2 = x(nums2, t);
	if (len1 != len2)	return false;				//长度不同，通项公式肯定不同
	for (i = 0; i < len1; i++)						//比较两个通项公式是否完全相同
		if (nums1[i] != nums2[i])					//有不同编号，不同
			return false;
	return true;									//完全相同
}

int main()
{
	printf("%d", isIsomorphic("aba","cda"));
	return 0;
}

/*
思路：
从题中可得出，同构即：字符的变化相同。字符的变化是指，随着位置的改变，一个字符变化到另一个字符的规律相同。
假如用数字代表一个位置的字符，那么形如 aba、hsh、ubu 这样的字符串就可以统一表示为 121，可以称这串数字为这类字符串的通项公式，那么本题
的解法便出来了，分别求两个字符串的通项公式，比较通项公式是否相同即可。
求通项公式：
可以先遍历一次字符串，将每种字符依次存储一次（只存储一次），若将每个字符在数组中的下标作为该字符在该字符串内的编号，便得到了该字符串的字符
表，接下来再遍历一次字符串，按字符表将字符串用字符编码排列一遍，便得到了该字符串的通项公式。
*/