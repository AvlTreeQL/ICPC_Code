#include<stdio.h>
#include<string.h>
int main()
{
	char a[30],b[30],c,*p,*q;
	gets(a);
	gets(b);
	scanf("%c",&c);
	p=strstr(a,b);
	q=strchr(a,c);
//	strncat(a,b,5);
	puts(p);
	puts(q);
	
	return 0;
}

