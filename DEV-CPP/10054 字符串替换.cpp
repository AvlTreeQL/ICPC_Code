#include<stdio.h>
#include<string.h>
char d[80];
int main()
{
	char a[80],b[20],c[20];
	void fun(char *a,char*b,char *c);
	gets(a);
	do
	{
		scanf("%s%s",b,c);
		fun(a,b,c);
		strcpy(a,d);
	}while(b[0]!='0'||c[0]!='0');
	puts(d);
	return 0;
}
void fun(char *a,char*b,char *c)
{	int i,j,o=0,k,p;
	for(i=0;a[i]!='\0';i++)
	{	
		for(j=0,k=i;b[j]!='\0';j++,k++)
		{
			if(a[k]==b[j]) p=1;
			else {p=0;break;}
		}
		if(p==1)
		{
			i=i+strlen(b)-1;
			for(j=0;c[j]!='\0';j++)
			d[o++]=c[j];
		}
		else
		{
			d[o++]=a[i];
		}

	}
	d[o]='\0';
}
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