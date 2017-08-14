#include<stdio.h>
#include<math.h>
int main()
{
	int n,a[1000000],i,j;
	long sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum=sum+abs(a[i]-a[j]);
	printf("%ld",sum);
	return 0;
}
/*
题目描述
数轴上有N个点，任意两点连线得到n(n-1)条线段，试求线段的总长。
输入
第一行，一个整数N，表示点数。 接下来N行，每行一个整数X_i，表示点的坐标。
输出
一个整数，表示线段的总长。
样例输入
5
1
5
3
2
4
样例输出
40
提示
N  < =  10000  ,  0  < =  X_i  < =  1000000000
*/