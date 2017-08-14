#include<stdio.h>
#include<stdlib.h>
long fun(long a[50],int n);
int main()
{
	int z,n[50],t[50],i,j;
	long a[50][100];
	scanf("%d",&z);
	for(i=0;i<z;i++)
	{
		scanf("%d%d",&n[i],&t[i]);
		for(j=0;j<n[i];j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<z;i++)
		printf("%d\n",fun(a[i],n[i])*t[i]);
	return 0;
}
int cmp(const void *a,const void *b)
{
	return *(long *)a>*(long *)b?1:-1;
}
long fun(long a[50],int n)
{
	qsort(a,n,sizeof(long),cmp);
	int i;
	long sum=0;
	for(i=0;i<n;i++)
	{
		if(i==0||i==1) sum+=a[i]*(n-1);
		else sum+=a[i]*(n-i);
	}
	return sum;
}
/*
2、设备组装
问题描述：
公司购进一个设备，但设备是以散件的形式到货的，工程师开始组装这个设备，各部件组装不分先后顺序，在各个部件上都标明该部件的组装的难度系数，并且当两个部件组装到一起后形成的一个新部件时，新部件的难度系数为组成这个部件的两个部件难度系数之和。工程师看到这么多的部件，他想用最快的时间将设备组装好，如果1个难度系数的组装时间为t，请你帮助工程师计算一下，组装好这个设备最快需要多少时间。
输入数据：
第一行为一个整数k，表示有k组测试数据。接下来是k组测试数据，其中每组测试数据占两行，第一行包括两个整数，第一个为n(0<n<50)，表示共有n各部件；第二个为t(0<n<10)，表示1个难度系数的组装时间。第二行为n个整数，表示n个部件的难度系数。
输出数据：
每组测试数据输出一个整数，表示组装好这个设备需要的最少时间。
输入样例：
2
4  2
8  5  3  4
5  1
1  2  2  3  5
输出样例：
78
29
*/