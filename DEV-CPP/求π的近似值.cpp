#include <stdio.h>
#include <math.h>
int main()
{
	int sign=1;
	double pi=0,n=1,term=1;
	while(fabs(term)>=1e-8)
	{ 
		pi=pi+term;
		n=n+2;
		sign=-sign;
		term=sign/n;
	}
	pi=pi*4;
	printf("pi=%10.8f\n",pi);
	return 0;
}
/* 公式 pi/4=1-1/3+1/5-1/7+......
fabs(term) 求浮点数x的绝对值 #include <math.h> */