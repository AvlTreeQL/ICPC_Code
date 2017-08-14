#include<stdio.h>
int main()
{
	char a[10],b;
	void fun(char a[],char b);
	gets(a);
	b=getchar();
	fun(a,b);
	puts(a);
	return 0;
}
void fun(char a[],char b)
{
	int i,t;
	for(i=0,t=0;a[i]!='\0';i++)
		if(a[i]!=b) a[t++]=a[i];
	a[t]='\0';
}
/*
	ÔÚ×Ö·û´®ÖÐÉ¾³ý Ä³¸ö×Ö·û
*/