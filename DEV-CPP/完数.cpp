#include<stdio.h>
int main()
{
	int n;
	int r(int m);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(r(i)==1) 
			printf("%d ",i);
	return 0;
}
int r(int m)
{
	int a=0,n,sum=0,i;
	n=m;
	for(i=1;i<m;i++)
		if(m%i==0)
			sum=sum+i;
	if(n==sum) a=1; 
	return a;
}