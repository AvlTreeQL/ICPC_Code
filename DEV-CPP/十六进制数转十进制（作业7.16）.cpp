#include<stdio.h>
int main()
{
	char a[20];
	int fun(char a[]);
	gets(a);
	printf("%d",fun(a));
	return 0;
}
int fun(char a[])
{
	int i,t,n=0;
	for(i=0;a[i]!='\0';i++)
	{
		switch(a[i])
		{
			case 'A':case 'a':t=10;break;
			case 'B':case 'b':t=11;break;
			case 'C':case 'c':t=12;break;
			case 'D':case 'd':t=13;break;
			case 'E':case 'e':t=14;break;
			case 'F':case 'f':t=15;break;
			case 'G':case 'g':t=16;break;
			default:t=a[i]-'0';
		}
		n=n*16+t;
	}
	return n;
}