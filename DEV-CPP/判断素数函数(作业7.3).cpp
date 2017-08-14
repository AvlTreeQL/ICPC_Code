#include<stdio.h>
int main()
{
	int n;
	int fun(int n);
	scanf("%d",&n);
	if(n<=1) printf("error");
	else if(fun(n)==1) printf("YES");
	else printf("NO");
	return 0;
}
int fun(int n)
{
	int i;
	for(i=2;i<n;i++)
		if(n%i==0) break;
	if(i<n) return 0;
	else return 1;
}