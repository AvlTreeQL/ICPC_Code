#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,s;
	scanf("%lf%lf",&a,&b);
	c=sqrt(a*a+b*b);
	s=a*b/2;
	printf("%.2lf %.2lf",c,s);
	return 0;
}