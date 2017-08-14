#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	void fun(char a[]);
	gets(a);
	fun(a);
	puts(a);
	return 0;
}
void fun(char a[])
{
	int i,t;
	char b;
	for(i=0,t=strlen(a)-1;i<t;i++,t--)
	{	b=a[i];
		a[i]=a[t];
		a[t]=b;
	}
}
/*
	µßµ¹×Ö·û´®
*/