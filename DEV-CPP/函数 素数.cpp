#include <stdio.h>
int main()
{
	int a;
	int r(int m);
	scanf("%d",&a);
	printf("%d\n",r(a));
	return 0;
}
int r(int m)
{
	int a=0,i;
	for (i=2;i<m;i++)
		if(m%i==0) break;
	if(i<m) a=1;
	return a;
}