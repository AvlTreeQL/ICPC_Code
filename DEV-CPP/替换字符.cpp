/*
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。 
Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。 
Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。 
Sample Input
abcdefgfedcba
xxxxx
Sample Output
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char fun(char *s);
int main()
{
	char s[100],t[100],*p,*q;
	int i=0,j=0;
	while(~scanf("%s",s))
	{	strcpy(t,s);
		do
		{	
			q=strchr(s,fun(s));
			if(p=strchr(t,fun(t)))
			{
				*(++p)='_';
				*(p+1)='\0';
				strcat(t,q+1);
			}
		}while(p);
	puts(t);
	}

	return 0;
}

char fun(char *s)
{
	int i;
	char max=s[0];
	for(i=1;i<strlen(s);i++)
	{
		if(s[i]>max) max=s[i];
	}
	return max;
}
