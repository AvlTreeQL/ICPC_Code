#include<stdio.h>
int main()
{
	int a;
	int r(int m);
	scanf("%d",&a);
	printf("The wei shu is %d\n",r(a));
	
	return 0;
}
int r(int m)
{
	int n=0,i=0;
	while(m!=0)
	{
		n=n*10+m%10;
		m=m/10;
		i+=1;
	}
	
	return i;
}