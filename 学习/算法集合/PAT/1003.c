#include<stdio.h>
int main()
{
	int i, j, flag, x, y, z;			char a[101], *b, P, A, T;
	//循环次数 i、循环变量 j、其它字符标记 flag、P前，PT间，T后 A 的数量 x，y，z、
	//字符串 a、字符指针 b、统计 P、T 两字符数量的变量 PT
	scanf("%d", &i);		getchar();										//获取字符串数量
	for (j = 0; j < i; j++)
	{
		gets(a);														//获取一个字符串
		for (b = a, flag = x = y = z = P = A = T = 0; *b != '\0'; b++)		//判断一个字符串
		{
			if (*b != 'P' && *b != 'A' && *b != 'T')			//检测其它字符
			{
				flag = 1;
				break;
			}
			if (*b == 'P') P++;									//检测是否含有 P、A、T 三个字符，并计不同位置 A 的数量
			if (*b == 'T') T++;
			if (*b == 'A' && P != 1 && T != 1)		x++;		//P 前 A 的数量
			else if (*b == 'A' && P == 1 && T != 1)		y++;	//P、T 间 A 的数量
			else if (*b == 'A' && P == 1 && T == 1)		z++;	//T 后 A 的数量
		}
		if (x != 0 || y != 0 || z != 0)		A = 1;
		if (x*y != z)	printf("NO\n");							//如果 A 的数量与位置不满足这个关系，不通过
		else if (flag == 1 || P != 1 || A == 0 || T != 1)	printf("NO\n");
		//有其它字符、没有 A、P 或 T 的数量不等于 1，不通过
		else	printf("YES\n");
	}
	return 0;
}

/*
思路：
这是个数学题，要先根据题中给出的提示进行逻辑推理求解出字符串的格式才行，不仅仅是写代码而已。
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
那么正确的有这些：
PAT
APATA
AAPATAA
...
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
拿上面正确的几个推导：
PAT —— 对于 aPbTc 来说ac是空，b是A。所以 PAAT 是正确的。同理 PAAAAAT 中间加多少个A都是正确的。
APATA —— 对于aPbTc来说，abc都是A。所以 APAATAA 是正确的。再类推一下，那么 APAAATAAA 是正确的。
AAPATAA —— 对于aPbTc来说，a和c是AA，b是A。所以AAPAATAAAA是正确的，再类推，AAPAAATAAAAAA 是正确的。
注意看 aPbTc 和 aPbATca 这两个式子，初始式子都是 xPATx 形式，由前者到后者是在 P、T 中间和 T 后加 A，并且方式是在 T 后加上 a 个 A，再在 P、T 中间
加上一个 A，又因为初始式子恒有 a = c，所以往后的式子将始终满足 a * b = c，换句话说，P 前面的 A 乘 P、T 之间的 A 的数量要等于 T 后 A 的数量。

一句话总结字符串格式：只能有一个 P 和一个 T，中间、末尾、开头可插入 A。但必须满足开头 A 的个数 * 中间的 A 的个数 = 结尾的 A 的个数·
*/