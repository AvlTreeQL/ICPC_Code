#include<stdio.h>
#include<string.h>
int c[30][30];
char fun(int n,int a[30][30],int b[30][30])
{
	
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	c[i][j]=0;
			for(k=0;k<n;k++)
				c[i][j]=c[i][j]+b[i][k]*a[k][j];
			
		}
}
int main()
{
	int n,m,a[30][30],b[30][30],i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]),b[i][j]=a[i][j];
	for(i=0;i<m-1;i++)
		fun(n,a,b),memcpy(b,c,sizeof(c));
	if(m!=0)	
		for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{
				printf("%d ",c[i][j]);
				
			}
			printf("\n");
		}
	else 
		for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{
				if(i==j) printf("1 ");
				else printf("0 ");
			}
			printf("\n");
		}
	return 0;
}
/*
��������
��������һ��N�׾���A�����A��M���ݣ�M�ǷǸ�������
�������磺
����A =
����1 2
����3 4
����A��2����
����7 10
����15 22
�����ʽ
������һ����һ��������N��M��1<=N<=30, 0<=M<=5������ʾ����A�Ľ�����Ҫ�������
����������N�У�ÿ��N������ֵ������10�ķǸ���������������A��ֵ
�����ʽ
���������N�У�ÿ��N����������ʾA��M��������Ӧ�ľ������ڵ���֮����һ���ո����
��������
2 2
1 2
3 4
�������
7 10
15 22
*/

