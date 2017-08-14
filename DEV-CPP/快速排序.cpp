#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
	return *(int *)a > *(int *)b?1:-1;
}
int main()
{
	int a[30],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
/*#include<stdio.h>
#include<iostream>  
#include<algorithm>  
using namespace std;
int cmp( const int &a, const int &b )
{
	return a<b;
}
int main()
{
	int a[30],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

*/
