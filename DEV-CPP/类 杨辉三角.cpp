#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("%d",i);
		printf("\n");		
	}
	return 0;
}
/* ÊäÈënÐÐ£¬´òÓ¡ 
	 1
    2 2
   3 3 3
  4 4 4 4
 5 5 5 5 5
6 6 6 6 6 6
*/