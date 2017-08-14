#include<stdio.h>
#include<math.h>
int main()
{
	float x;
	scanf("%f",&x);
	if(x<0)
		printf("%.2f",-x);
	else if(x>=4)
	{
		printf("%.2f",2*x+5);
	}
	else if(x>=0&&x<2)
	{
		printf("%.2f",sqrt(x+1));			
	}
	else printf("%.2f",pow((x+2),3));
	return 0;
}
