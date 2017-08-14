#include<stdio.h>
int main()
{
	int a,b,temp;
	scanf("%d%d",&a,&b);
	do
	{
		temp=a%b;
		a=b;
		b=temp;
		printf("%d %d %d\n",a,b,temp);
	} while(b);
	printf("%d\n",a);
	return 0;
} 




