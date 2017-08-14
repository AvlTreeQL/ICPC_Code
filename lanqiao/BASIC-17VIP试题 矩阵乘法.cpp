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
问题描述
　　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
　　例如：
　　A =
　　1 2
　　3 4
　　A的2次幂
　　7 10
　　15 22
输入格式
　　第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
　　接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
输出格式
　　输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开
样例输入
2 2
1 2
3 4
样例输出
7 10
15 22
*/

