/*
���������ÿ���ַ������������е������ĸ���ڸ���ĸ��������ַ�����(max)���� 
Input
�������ݰ����������ʵ����ÿ��ʵ����һ�г��Ȳ�����100���ַ�����ɣ��ַ������ɴ�Сд��ĸ���ɡ� 
Output
����ÿ������ʵ�����һ���ַ���������Ľ���ǲ����ַ�����(max)����Ľ����������ڶ��������ĸ������ÿһ�������ĸ���涼����"(max)"�� 
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
