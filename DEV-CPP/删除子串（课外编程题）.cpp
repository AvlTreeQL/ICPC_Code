/*
【问题描述】编写一个程序，当在一个字符串中出现子串时就删除它。
【输入形式】用户在第一行输入一个字符串，用户在第二行输入一个子串。注意：第二行输入结束时可能用回车，也可能不用回车。
【输出形式】程序在下一行输出删除其中所有子串后的字符串。如果字符串不包含子串则输出原字符串本身。
【样例输入】
 I am a boy!
 a             
【样例输出】
 I m  boy!       
【样例说明】用户首先输入字符串I am a boy!,然后输出子串a,程序会寻找字符串中的子串删除它，最后   将删除后的结果输出:I#m##boy!   #表示空格。
【评分标准】结果完全正确得20分，每个测试点4分。提交程序名为：delsubstring.c。
*/
#include<stdio.h>
#include<string.h>
void change(char str[100],char a[21])
{
	char *p,str1[100]={0};
	while(1)
	{
		p=strstr(str,a);
		if(p==NULL) break;
		*p='\0';
		strcat(str1,str);
		strcat(str1,p+strlen(a));
		strcpy(str,str1);
		str1[0]='\0';
	}
}
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	change(a,b);
	puts(a);
	return 1;
}
