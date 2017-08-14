#include<stdio.h>
int main()
{
	int n,i;
	int r(int m);
	scanf("%d",&n);
	for(i=2;i<=n/2;i++)
		if(r(i)==1&&r(n-i)==1) 
			printf("%d %d\n",i,n-i);
	return 0;
}
int r(int m)
{
	int i;
	for(i=2;i<m;i++)
		if(m%i==0) break;
	if(i<m) return 0;
	else return 1;
}
/* 
拆成两个素数
*/
