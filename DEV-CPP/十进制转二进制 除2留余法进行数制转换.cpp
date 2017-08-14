#include <stdio.h>
void main()
{	int n,a[20];
	printf("n=");
	scanf("%d",&n);
	printf("对应的二进制数:");
	for(int i=0;n!=0;i++)
	{	a[i]=n%2;
		n=n/2;
	}
	for(int j=i-1;j>=0;j--)
		printf("%d ",a[j]);
	printf("\n");
}
