#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=1;c<=9;c++)
			{	if(a*100+b*10+c+c*100+b*10+a==1333)
				printf("%d %d %d\n",a,b,c);
			}
	return 0;
}
/* 
已知abc+abc=1333  求出a,b,c 
4 1 9
5 1 8
6 1 7
7 1 6
8 1 5
9 1 4

*/