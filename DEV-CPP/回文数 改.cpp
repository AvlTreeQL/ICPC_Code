#include<stdio.h>
int main()
{
	int m,i,k=0,a[20];
	scanf("%d",&m);
	while(m!=0)
	{
		a[k++]=m%10;
		m=m/10;
	}
	k--;
	for(i=0;i<k;i++,k--) 
		if(a[i]!=a[k]) break;
	if(i<k) 
		printf("1\n");	
	else
		printf("0\n");

	return 0;
}