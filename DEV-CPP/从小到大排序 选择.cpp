#include <stdio.h>
#define SIZE 7
int main()
{ 
	int a[SIZE],i,j,k,x;
	for(i=0;i<SIZE;i++)
	scanf("%d",&a[i]);
	printf("\n");
	for(i=0;i<SIZE-1;i++)
	{ 
		k=i;
	for(j=i+1;j<=SIZE-1;j++)
	if(a[j]<a[k]) k=j;
	if(i!=k)
	{ x=a[i]; a[i]=a[k]; a[k]=x;}
	}
	printf("The sorted numbers:\n");
	for(i=0;i<SIZE;i++)
		printf("%3d",a[i]);
	return 0;
}