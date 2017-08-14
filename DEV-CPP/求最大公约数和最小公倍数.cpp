#include <stdio.h>
int main()
{
	int m,n,i,a,b;
	scanf("%d%d",&m,&n);
	for(i=1;i<m||i<n;i++)
		if(m%i==0&&n%i==0) a=i;
	for(m>=n?i=n:i=m;;i++)
		if(i%m==0&&i%n==0) 
		{
			b=i;
			break;
		}
	printf("%d %d",a,b);

	return 0;
}