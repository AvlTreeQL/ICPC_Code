#include<stdio.h>
int fun(int n);
int main()
{
	int m,n,i=0;
	scanf("%d%d",&m,&n);
	do
	{
		if(fun(++m)==1) 
		{	printf("%11d",m);
			i++;	
		}
	}while(i!=n);
	return 0;
}
int fun(int n)
{
	int m;
	if(n%6==0) return 1;
	else 
	{
		while(n)
		{
			m=n%10;
			n=n/10;
			if(m==6) 
				return 1;
		}
		return 0;
	}
}