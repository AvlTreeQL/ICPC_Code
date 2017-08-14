#include<stdio.h>
int main()
{
	int a;
	int r(int m);
	scanf("%d",&a);
	if(r(a)==1) printf("The number is wanshu");
	return 0;
}
int r(int m)
{
	int a=0,n,sum=0,i;
	n=m;
	for(i=1;i<m;i++)
		if(m%i==0)
			sum=sum+i;
	if(n==sum) a=1; 
	return a;
}