#include <stdio.h>
int main()
{
	int i,j;
	for (i=1;i<=9;i++)//控制每行
	{
		for (j=1;j<=9;j++)//控制每列
		{
			printf("%d*%d=%d\t",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}