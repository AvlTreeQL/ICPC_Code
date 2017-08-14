#include<stdio.h>
int main()
{
	struct date
	{
		int y;
		int m;
		int d;
	}p;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},sum=0,i;
	scanf("%d%d%d",&p.y,&p.m,&p.d);	
	if(p.y%4==0&&p.y%100!=0||p.y%400==0) a[1]=29;
	for(i=0;i<p.m-1;i++)
	{
		sum+=a[i];
	}
	sum+=p.d;
	printf("%d",sum);
	return 0;
}