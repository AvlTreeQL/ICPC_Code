/*
【问题描述】将一段英文文章中字符串用给定的字符串替换。
【输入形式】输入包括多行，每一行为一段英文文章（长度不超过80）。以后每行包括2个字符串（长度不超过20），之间由空格分隔，第一个串为原串，第二个串为替换串，当遇到0 0两个串时表示输入结束，并且此行不需处理。注意：本题需要考虑原串和替换串的长度不同的三种情况。情况1：原串的长度大于替换串，如原串为are ，替换串为is。情况2：原串的长度等于替换串，如原串为h ，替换串为H。情况3：原串的长度小替换串，如原串为yes ，替换串为your。
【输出形式】输出替换后的文章。
【样例输入】
hello how are yes.
h H
es ou
0 0
【样例输出】Hello How are you.
【评分标准】本题共4个测试点，每个测试点0.25分，总分1.0分。
hello how are yes.
are a
how abc
0 0
*/
#include<stdio.h>
#include<string.h>
void change(char str[81],char a[21],char b[21]);
int main()
{
	char str[81],a[21],b[21];
	gets(str);
	do
	{
		scanf("%s%s",a,b);
		if(a[0]!='0'&&b[0]!='0') change(str,a,b);
	}while(a[0]!='0'&&b[0]!='0');
	puts(str);
	return 0;
}
void change(char str[81],char a[21],char b[21])
{
	char *p,str1[81]={0};
	while(1)
	{
		p=strstr(str,a);
		if(p==NULL) break;
		*p='\0';
		strcat(str1,str);
		strcat(str1,b);
		strcat(str1,p+strlen(a));
		strcpy(str,str1);
		str1[0]='\0';
	}
 /*	
	char *p,str1[81]={0};
	int i,t=0;
	p=strstr(str,a);
	for(i=0;str[i]!='\0';i++)
	{
		if(&str[i]==p) strcat(str1,b),t=strlen(str1),i+=strlen(a);
		str1[t++]=str[i];
	}
	str1[t]='\0';
	strcpy(str,str1);
*/
}	