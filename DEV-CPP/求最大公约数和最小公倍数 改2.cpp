#include <stdio.h>
int main()
{
	int m,n,i,a;
	scanf("%d%d",&m,&n);
	for(i=1;i<m||i<n;i++)
		if(m%i==0&&n%i==0) a=i;
	printf("%d %d",a,m*n/a);

	return 0;
}
//两个数的乘积除以他们的最大公约数是最小公倍数