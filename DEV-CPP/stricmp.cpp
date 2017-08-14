#include<stdio.h>
#include<string.h>
int main()
{
	char a[30],b[30];
	int p;
	gets(a);
	gets(b);
	p=stricmp(a,b);
	printf("%d\n",p);

	return 0;
}

