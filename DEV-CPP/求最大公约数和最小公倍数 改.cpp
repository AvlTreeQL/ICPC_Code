#include<stdio.h>
int main()
{
	int m,n,a,b,temp;
	scanf("%d%d",&m,&n);
	if(m<n) 
	{
		temp=m;
		m=n;
		n=temp;
	}
	a=m;b=n;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	printf("gongyueshu:%d\n",a);
	printf("gongbeishu:%d\n",m*n/a);
	return 0;
}