#include<stdio.h>
#include<string.h>
void fun(char a[1000],int n,char b[100][100]);
int main()
{
	char a[1000],b[100][100];
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)	
		gets(b[i]);
	gets(a);
	fun(a,n,b);
	puts(a);
	return 0;
}
void fun(char a[],char b[])
{
	int i,j,t,p,k,o=0;
	int f(char a,char b);
		for(i=0;a[i]!='\0';i++)
		{	k=i;
			for(j=0;b[j]!='\0';k++,j++)//找到b[]对应字符串在 a[] 的位置
			{	
				if(f(a[k],b[j])==1) 
				{	
					p=1;	
				}
				else
				{
					p=0;
					break;
				}
			}		 
			if(p==1)//是要替换的字符  将字符串 c[] 赋给 d[80]
			{
				d[o++]=a[i];
				i=i+strlen(b)-1;
				for(t=1;t<strlen(b);t++)
					d[o++]='*';
				
			} 
			else	// 不是要替换的字符 把原来的字符串a[] 赋给 d[80]
			{
				d[o++]=a[i];
			}
		}
		d[o]='\0';
}
int f(char a,char b)
{
	if(a==b||a+32==b||a-32==b||b+32==a||b-32==a) return 1;
	else return 0;
}
/*
void fun(char a[1000],int n,char b[100][100])
{
	int i,j;
	char *p;
	for(i=0;i<n;i++)
	{
		while(strstr(a,b[i]))
		{	p=strstr(a,b[i]);
			j=0;
			while(b[i][++j]!='\0')
			{
				*(++p)='*';
			}
		}
	}
}

/*
题目描述
为了网络文明并避免一些敏感词汇，BBS的聊天中不能出现某些违禁用语。
所以你的系统设计为由管理员输入若干的违禁词汇，对于帖子中的违禁词汇，系统只显示第一个字符，其他字符全部用*代替。
注意查找违禁词汇时是不考虑大小写的，但修改时则要保留大小写。
比如love是违禁词汇，则Love、love都是违禁词语，而帖子中的love被输出为l***，而Love输出L***。
现在就看你的啦！
输入
输入数据只有一组，第一行为一个正整数n（n<=1000），接下来有n行，每行有一个英文单词，由若干个英文字母组成，不含空格（单词长度不超过20）。

接下来有若干段需要处理的文字，处理到文件结束为止，字符个数不超过10000个。

输出
输出处理后的文字，除了违禁用语，其他文字和格式不变。

样例输入
2
Love
sylu
I love ShenYang,and love sylu more
样例输出
I l*** ShenYang,and l*** s*** more
*/