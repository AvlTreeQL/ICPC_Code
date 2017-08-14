#include<stdio.h>
#include<string.h>
int main()
{
	char str[81],a[81][20];
	int i,j,p=0,q=0,num=0,max=0;
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z')
			a[p][q++]=str[i];
		else
			a[p][q]='\0',p++,q=0;
	}
	for(i=0;i<p;i++)
	{
		if(strcmp(a[i],"")!=0)
		{	num++,puts(a[i]);
			if(strlen(a[i])>max) max=strlen(a[i]),j=i;
		}
	}
	puts(a[j]);
	printf("%d",num);
	return 0;
}
/*
输入字符串 统计其中单词数，并且打印出最长单词，和所有单词，稍加修改，也可以统计连续数字
*/