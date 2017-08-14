#include<stdio.h>
int main()
{
	int n,i;
	int r(int m);
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		if(r(i)==0) printf("%d ",i);
	return 0;
}
int r(int m)
{
	int a=0,i;
	for(i=2;i<m;i++)
		if(m%i==0) a=1;
	return a;
}