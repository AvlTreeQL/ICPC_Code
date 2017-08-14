#include<stdio.h>
#include<stdlib.h>

int main()
{
	void fun(int n);
	int i;
	for(i=0;i<32;i++)
		fun(i);
	return 0;
} 
void fun(int n)
{
	char a[6]={0};
	int i=4;
	while(n)
	{
		a[i--]=n%2+'0';
		n/=2;
	} 
	puts(a);
}
/*
void trans(int n)//10进制转换成b进制	
{	int i,j;
	for(i=0;n!=0;i++)
	{	
		o[i]=n%b+'0';
		n=n/b;
	}
}

/*char *fun(int n)
{
	char *p,*temp;
	p=(char *)malloc(sizeof(char)*5);
	temp=p;
	while(n)
	{
		*(p++)=n%2;
		n/=2;
	} 
	*p='\0';
	return temp;
}
/*
问题描述
对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：
00000
00001
00010
00011
00100
请按从小到大的顺序输出这32种01串。
输入格式
本试题没有输入。
输出格式
输出32行，按从小到大的顺序每行一个长度为5的01串。
样例输出
00000
00001
00010
00011
<以下部分省略>
*/
