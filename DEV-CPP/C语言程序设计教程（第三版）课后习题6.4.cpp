#include<stdio.h>
int main()
{
	long long sum=0;
	int n,i;
	long long f(int n);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum+=f(i);
	printf("%lld",sum);
	return 0;
}
long long f(int n)
{
	int i;
	long long sum=1;
	for(i=1;i<=n;i++)
		sum=sum*i;
	return sum;
}