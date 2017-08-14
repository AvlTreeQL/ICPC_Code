#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	char s[8000];
	int i,j,t=0,p,flag=0,q;
	long sum=0;
	scanf("%d",&i);
	getchar();
	gets(s);
	q=strlen(s);
//	i=q;
//	i=(q+1)/2-1;
	for(i=0;i!=(q+1)/2-1;i++)
	{
	/*	if(strchr(s,s[i])==&s[i]) 
		{
			j=i;
			while(j!=(q+1)/2-1)
			{
				swap(&s[j],&s[j+1]),j++;
			} 
			continue;
			
		}*/
		for(j=q-1-i+t;s[i]!=s[j];j--);
//		if(i<j)sum+=q-1-i-j;
		if(i==j) {t++,p=i;continue;}
		if(t==1&&q%2==0||t>=2) {flag=1;break;}
		while(j!=q-1-i+t)
		{
			swap(&s[j],&s[j+1]),j++,sum++;
		}
	}
	if(t==1&&q==4||t>=2) flag=1;
	if(flag!=1)
	{
		if(t==1)
		{
			while(p!=(q+1)/2-1)
			{
				swap(&s[p],&s[p+1]),p++,sum++;
			}
		}
//		puts(s);
		printf("%d",sum);
	}
	else printf("Impossible");
	return 0;
}
/*
问题描述
　　回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。
	小龙龙认为回文串才是完美的。
	现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
　　交换的定义是：交换两个相邻的字符
　　例如mamad
　　第一次交换 ad : mamda
　　第二次交换 md : madma
　　第三次交换 ma : madam (回文！完美！)
输入格式
　　第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
　　第二行是一个字符串，长度为N.只包含小写字母
输出格式
　　如果可能，输出最少的交换次数。
　　否则输出Impossible
样例输入
5
mamad
样例输出
3
*/

