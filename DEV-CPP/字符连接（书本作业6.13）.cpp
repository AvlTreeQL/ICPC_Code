#include <stdio.h>
#include <string.h>
int main()
{
	char a[2][20],i;
	int min(int x,int y);
	gets(a[0]);	
	gets(a[1]);
	for(i=0;i<strlen(a[0]);i++)
		printf("%c",a[0][i]);
	for(i=0;i<min(strlen(a[2]),5);i++)
		printf("%c",a[1][i]);
	return 0;
}
int min(int x,int y)
{
	int min;
	if(x>y) min=y;
	else min=x;
	return min;
}
/*	
问题描述

从键盘输入两个字符串a和b，要求不用库函数strcat把串b的前五个字符连接到串a中；如果b的长度小于5，则把b的所有元素都连接到a中。并输出连接后的字符串a。(字符串中可能含有空格）

输入形式

输入两行，两个字符串a和b，（两个字符串的长度小于80）。

输出形式

输出一行，输出字符串a。

样例输入

student

and I

样例输出

studentand I
*/