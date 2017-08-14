#include<stdio.h>
int main()
{
	int n;
	long f(int n);
	scanf("%d",&n);
	printf("%ld",f(n));
	return 0;
}
long f(int n)
{
	if(n==0||n==1)
		return 1;
	else 
		return n*f(n-1);
}