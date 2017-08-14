#include<stdio.h>
int main()
{
	long i,a=0,n[200],b[200][200];
	void sort(long a[200],long n);
	long fun(long a);
	do
	{
		scanf("%ld",&n[a]);
		for(i=0;i<n[a];i++)
			scanf("%ld",&b[a][i]);
		a++;
	}while(n[a-1]!=0);
	for(i=0;i<a-1;i++)
	{
		sort(b[i],n[i]);
		printf("\n");
	}
	return 0;
}
void sort(long a[200],long n)
{
	long i,j,t;
	long fun(long a);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(fun(a[j])<fun(a[j+1]))
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	for(i=0;i<n-1;i++)
		printf("%ld ",a[i]);
	printf("%ld",a[i]);
}
long fun(long a)
{
	if(a>=0) return a;
	else return -a;
}
/*
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
Input
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。 
Output
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。
Sample Input
3 3 -4 2
4 0 1 2 -3
0
Sample Output
-4 3 2
-3 2 1 0
*/