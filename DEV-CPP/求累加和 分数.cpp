#include<stdio.h>
int main()
{
	float i=2.0,t=1.0,b=0,c;
	int n,a=0;
	scanf("%d",&n);
	while(a<n)
	{
		a=a+1;
		b=i/t+b;
		c=i;
		i=t+i;
		t=c;
	}
	printf("%.2f\n",b);
	return 0;
}


