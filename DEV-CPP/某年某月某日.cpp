#include<stdio.h>
int main ()
{
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
	int y,m,d,sum=0,i;
	scanf("%d%d%d",&y,&m,&d);
	if(y%4==0&&y%100!=0||y%400==0) a[2]=29;
	for(i=1;i<m;i++)
		sum=sum+a[i];
	sum=sum+d;
	printf("%d\n",sum);

	return 0;
}