#include<stdio.h>
int main()
{
	int a;
	int r(int m);
	scanf("%d",&a);
	printf("The jie chen shu is %d\n",r(a));
	
	return 0;
}
int r(int m)
{
	int n=1,i;
	for(i=1;i<=m;i++)
		n*=i;
	
	return n;
}