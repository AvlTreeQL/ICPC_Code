#include<stdio.h>
int main()
{
	char a[50],b[50],*t=a,*p=b;
	void fun(char *p,char *t);
	gets(a);
	fun(t,p);
	puts(b);

	return 0;
}
void fun(char *t,char *p)
{
	for(;*t!='\0';t++)
	if(*t=='A'||*t=='E'||*t=='I'||*t=='O'||*t=='U'||*t=='a'||*t=='e'||*t=='i'||*t=='o'||*t=='u')
	{
		*(p++)=*t;
	}
	*p='\0';
}
/*
	
问题描述
写一函数，将一个字符串中的元音字母复制到另一字符串。在主函数中输入和输出字符串。
输入形式
输入一行，包括一个字符串。
输出形式
输出一行，输出复制后的字符串。
样例输入
I am a student.
样例输出
Iaaue
*/