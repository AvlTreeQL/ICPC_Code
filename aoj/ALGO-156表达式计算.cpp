 /*
问题描述
　　输入一个只包含加减乖除和括号的合法表达式，求表达式的值。其中除表示整除。
输入格式
　　输入一行，包含一个表达式。
输出格式
　　输出这个表达式的值。
样例输入
1-2+3*(4-5)
样例输出
-4
数据规模和约定
　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
*/
#include<stdio.h>
long turn(char s[])
{
	int i;
	long n=0;
	for(i=0;i<strlen(s);i++)
	{
		n+=(s[i]-'0')*10;
	}
	return n;
}	
int main()
{	
	char s[100],a[100][100];
	int b[100],l;
	int i,j,p=0,q=0,t=0;
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[p][q++]=s[i];
		else 
		{	a[p++][q]='\0';
			if(strcmp(a[p-1],"")!=0)
				b[t++]=turn(a[p-1]);
		}
	}
	for(i=0;i<l;i++)
	{
		if(s[i]=='(')
		{
			
		}
		if(s[i]=='*')
		{
			
		}
		else if(s[i]=='/')
		{
			
		}
	}
	return 0;
}
