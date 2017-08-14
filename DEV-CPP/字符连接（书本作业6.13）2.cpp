#include<stdio.h>
#include<string.h>
int main()
{
	char a[2][20];
	void fun(char a[][20]);
	gets(a[0]);
	gets(a[1]);
	fun(a);
	puts(a[0]);
	return 0;
}
void fun(char a[][20])
{
	int i,t;
	for(i=0,t=strlen(a[0]);a[1][i]!='\0';i++)
		a[0][t++]=a[1][i];
	a[0][t]='\0';
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