#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	void fun(char *p);
	gets(a);
	fun(a);
	return 0;
}
void fun(char *p)
{
	int a=0,b=1,max=0;
	char d[20],f[20];
	for(;*p!='\0';p++)
	{
		if(*p==' '||*p=='.')
		{
			b=0;		
		}
		else 
		{
			if(b==0)
			{	
				b=1;		
				a=0;
			}
			d[a++]=*p;
			if(a>max) 
			{
				max=a;
				f[a]=d[a]='\0';
				strcpy(f,d);
			}
		}
	}
	printf("%s",f);
}
/*
问题描述
写一函数，输入一行字符，将此字符串中最长的单词输出。在主函数中输入和输出字符串。
输入形式
输入一行，包括一个不大于80的字符串。
输出形式
输出一行，输出字符串中最长单词，对于最长长度相同的单词，输出第一个出现单词。
样例输入
There is a nice mouse.
样例输出
There
*/