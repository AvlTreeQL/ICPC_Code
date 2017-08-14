#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,a[10][10];
	void fun(int a[10][10],int n);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	fun(a,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");			
	}
	return 0;
}
void fun(int a[10][10],int n)
{
	int i,t,temp;
	for(i=0;i<n;i++)
		for(t=0;t<=i;t++)
		{
			temp=a[i][t];
			a[i][t]=a[t][i];
			a[t][i]=temp;
		}
}
/*	
µßµ¹¾ØÕó
3
1 2 3
4 5 6
7 8 9
*/