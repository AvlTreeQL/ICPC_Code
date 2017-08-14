#include<stdio.h>
int main()
{
	int sum,i;
	for(i=10000;i<99999;i++)
	{
		sum=i%10*100000+i%10*10000+i%10*1000+i%10*100+i%10*10+i%10;
		if(sum==i*(i/10000))
			printf("%d %d",i,i/10000);
	}
	return 0;
} 
/*
	abcde
   *    a
   =eeeeee     
*/
