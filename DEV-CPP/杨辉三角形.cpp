#include<stdio.h>
int main()
{
	int a[20][20],n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i][1]=a[i][i]=1;	
	}
	for(i=3;i<=n;i++)
		for(j=2;j<=i-1;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			printf("%3c",' ');
		for(j=1;j<=i;j++)
		{	
			printf("%3d",a[i][j]);
			printf("   ");
		}
		printf("\n");
	}
	return 0;
}
/*��������
��ӡ����������ε�ǰn�С�
������ʽ
����һ��������n ( n <20 )��
�����ʽ
��������Ρ�
��������
5
�������
                    1
                  1   1
               1    2   1
             1    3   3   1
           1    4   6   4   1
*/