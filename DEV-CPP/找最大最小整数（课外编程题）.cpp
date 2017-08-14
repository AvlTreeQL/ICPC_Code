#include <stdio.h>
int main()
{	
	int n,i,a[100],min,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i>0&&a[i]>a[i-1]) max=a[i];
		if(i>0&&a[i]<a[i-1]) min=a[i];
	}
	printf("%d %d",max,min);
	return 0;
}
