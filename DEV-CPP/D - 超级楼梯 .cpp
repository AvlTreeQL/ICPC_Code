#include<stdio.h>
int main()
{
	long n,i,j,a[41],temp;
	a[0]=0,a[1]=1,a[2]=1,a[3]=2;
	scanf("%ld",&n);
	for(j=4;j<=40;j++)
	{
		a[j]=a[j-1]+a[j-2];
	}

	for(i=0;i<n;i++)
	{	
		scanf("%ld",&temp);
		printf("%ld\n",a[temp]);
	}
	return 0;
}
/*
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
Output
对于每个测试实例，请输出不同走法的数量
Sample Input
2
2
3
Sample Output
1
2
*/