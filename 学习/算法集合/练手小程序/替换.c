#include<stdio.h>
#include<stdlib.h>
//该程序将 txt 文件中的 < 和 > 替换为 &lt; 和 & gt;，相当于实现了文本编辑器里最简单的“替换”功能，纯属练手，没什么实用意义。

int main()
{
	FILE *f = fopen("替换.txt", "ab+"), *f2 = fopen("替换 2.txt", "wb+");
	char a[100000], pd;		int i, j;
	if (f != NULL && f2 != NULL)
	{
		printf("\n  替换结果：\n\n");
		for (; 1;)										//将文件 1 替换字符再赋值到替换 2
		{
			if (fread(&pd, sizeof(char), 1, f) == 0)	//读取失败，已到文件末尾，跳出
				break;
			fseek(f, -1, 1);
			for (i = 0; 1; i++)							//读取一段内容直到 < 或 >
			{
				fread(&a[i], sizeof(char), 1, f);		//从文件中读取一个字符
				if (a[i] == EOF || a[i] == '<' || a[i] == '>')	break;
			}
			if (a[i] == '<')							//替换末尾的 < 或 >
			{
				a[i++] = '&';	a[i++] = 'l';
				a[i++] = 't';	a[i] = ';';
			}
			else if (a[i] == '>')
			{
				a[i++] = '&';	a[i++] = 'g';
				a[i++] = 't';	a[i] = ';';
			}
			a[i + 1] = '\0';	printf("%s", a);
			for (j = 0; j < i + 1; j++)					//写入数组当前值
				fwrite(&a[j], sizeof(char), 1, f2);		//写入一个字符
		}
		printf("\n\n  替换完毕\n\n  ");
		fclose(f);					fclose(f2);
	}
	else printf("\n  打开文件失败\n\n  ");
	return 0;
}

/*
思路：
打开文件 "替换.txt"，创建文件 "替换2.txt"，读取文件 "替换" 内容到字符数组中直到遇到 < 或 >，将数组末尾的 < 或 > 替换为 &lt; 或
&gt;，然后把数组写入到文件 "替换 2" 中，循环这个过程直到读完文件。
注：判断文件是否读取到末尾可以通过判断文件读写函数的返回值来确定，返回值为 0 则代表已经读取到末尾了。
*/