#include <stdio.h>
int main()
{
	int i,j;
	for (i=1;i<=9;i++)//����ÿ��
	{
		for (j=1;j<=9;j++)//����ÿ��
		{
			printf("%d*%d=%d\t",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}