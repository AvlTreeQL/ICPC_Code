#include <stdio.h>
#include <string.h>
int main()
{
	int fun(int n);
	int m,i,t=0;
	scanf("%d",&m);
	for(i=2;i<=m;i++)
	{
		if(fun(i)==1&&i%10==1) t=1,printf("%d ",i);
	}
	if(t==0) printf("-1");
	return 0;
}
int fun(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0) break;
	}
	if(i<n) return 0;
	else return 1;
}