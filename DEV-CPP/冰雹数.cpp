#include<stdio.h>
int main()
{
	int N,i,n,max=0;
	scanf("%d",&N);
	for(i=2;i<=N;i++)
	{	n=i;
		while(n!=1)
		{
			if(n%2==0) n=n/2;
			else n=n*3+1;
			if(n>max) max=n;
		}
		
	}
	printf("%d",max);

	return 0;
}
