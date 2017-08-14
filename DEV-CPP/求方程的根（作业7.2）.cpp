#include <stdio.h>
#include <math.h>
int main ( )
{
	float a,b,c,disc,p,q;
	scanf("%f%f%f",&a,&b,&c);
	if(a==0) printf("%.2f",-c/b);
	else
	{
		disc=b*b-4*a*c;	
		p=-b/(2*a);
		if (disc>0)
		{
			q=sqrt(disc)/(2*a);
			printf("%.2f %.2f",p+q,p-q);
		}
		else if(disc<0)
		{
			q=sqrt(-disc)/(2*a);
			printf("%.2f+%.2fi %.2f-%.2fi",p,q,p,q);		
		}
		else printf("%.2f",p);	 
	}
	return 0;
}