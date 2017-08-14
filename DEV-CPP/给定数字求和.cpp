#include<stdio.h>
int main()
{
	int n,a[20],i,j,sum=0;
	scanf("%d%d",&a[0],&n);
	for(i=0;i<n;i++)
		a[i+1]=a[i]*10+a[0];
	for(j=0;j<n;j++)
		sum=sum+a[j];
	printf("%d",sum);
	return 0;
}