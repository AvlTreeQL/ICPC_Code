#include<stdio.h>
int main()
{
	int a[20],i=0;
	int fun(int n);
	do
	{	
		scanf("%d",&a[i++]);
	}while(a[i-1]!=0);
	for(i=0;a[i]!=0;i++)
		printf("%d\n",fun(a[i]));
	return 0;
}
int fun(int n)
{
	int m=0;
	while(n!=0)
	{
		m=m+n%10;
		n=n/10;
	}
	if(m>=10)
	{
		m=fun(m);
	}
	return m;
}
/*
Êý×Ö¸ù  24  2+4=6£»
	29  3+9=12£»1+2=3£»
*/
 