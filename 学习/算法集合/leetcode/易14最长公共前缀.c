#include<stdio.h>
#include<stdlib.h>
/*
ԭ�⣺
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��
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
˼·��˫��ѭ����ÿ�αȽ�һ���Ƿ���ͬ����ͬ������ַ������򷵻��ַ�����
*/