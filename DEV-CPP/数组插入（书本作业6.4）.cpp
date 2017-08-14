#include<stdio.h>
int main()
{
	int i,t,j,k,a[15];
	for(i=0;;i++)
	{
		scanf("%d",&a[i]);		
		if(a[i]==0) break;
	}
	t=i;
	scanf("%d",&a[i]);
	for(i=0;i<t;i++)
		for(j=0;j<t-i;j++)
			if(a[j]>a[j+1]) 
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
	for(i=0;i<=t;i++)
		printf("%d ",a[i]);
	return 0;
}

