#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if((n-2)%4!=0)
		printf("no\n");
	else
		printf("yes\n");
	return 0;
}