#include<stdio.h>
int main()
{
	int m,n,h,l,i,j,t,k=0,max,min,a[10][10];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);		
		}
	for(i=0;i<m;i++)
	{
		max=a[i][0];
		for(j=1;j<n;j++)
		{
			if(a[i][j]>max) 
			{
				max=a[i][j];
				h=i;
				l=j;
			}
	
		}
		min=a[h][l];
		t=0;
		for(j=0;j<m;j++)
		{
			if(min>a[j][l]) 
			{
				t=1;
			}
		}
		if(t==0)
		{ 
			printf("%d %d %d ",h,l,a[h][l]);
			k++;
		}
	}
	if(k==0) printf("no");
	
	return 0;
}
/*
鞍点（书本作业6.8）
问题描述
找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点。
输入形式
第一行，输入两个正整数m和n，表示二维数组有m行n列。（1=<m,n<=10）
从第2到m+1行输入二维数组的各个元素，每行输入元素的个数为n个。
输出形式
输出一行，若有鞍点，则输出鞍点所处的行、列和鞍点值（各个数据间以空格分隔），若没有鞍点，则输出no。
样例输入
3 5
3 2 1 5 -1
1 5 8 6 1
5 6 7 7 9
样例输出
0 3 5
*/
