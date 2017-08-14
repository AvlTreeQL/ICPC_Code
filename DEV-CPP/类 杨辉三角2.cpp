#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			printf("   ");
		for(j=1;j<=i;j++)
			printf("%3d",j);
		for(j=i-1;j>0;j--)
			printf("%3d",j);
		printf("\n");		
	}
	return 0;
}
/*  ‰»În––£¨¥Ú”° 
                 1
              1  2  1
           1  2  3  2  1
        1  2  3  4  3  2  1
     1  2  3  4  5  4  3  2  1
  1  2  3  4  5  6  5  4  3  2  1
*/