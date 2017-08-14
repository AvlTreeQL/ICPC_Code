#include<stdio.h>
int main()
{
	int a;
	int r(int m);
	scanf("%d",&a);
	if (r(a)==1) printf("The year is run nian\n");
	return 0;
}
int r(int m)
{
	int a=0;
	if((m%4==0&&m%100!=0)||m%400==0) a=1;
	return a;
}