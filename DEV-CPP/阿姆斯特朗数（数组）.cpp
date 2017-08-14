#include<stdio.h>
int main()
{
	int n;
	int r(int m);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(r(i)==1) printf("%d ",i);

	return 0;
}
int r(int m)
{
	int n,a,sum=0,i=0;
	a=m;
	while(m!=0)
	{
		n=m%10;
		m=m/10;
		sum=sum+n*n*n;
	}
	if(sum==a) i=1;
	return i;
}
/*
问题描述
阿姆斯特朗数：如果一个正整数等于其各个数字的立方和，则该数称为阿姆斯特朗数（亦称为自恋性数）。如407=43+03+73就是一个阿姆斯特朗数。试编程求n以内的所有阿姆斯特朗数。
输入形式
输入一行，只包括一下正整数n。
输出形式
输出一行，给出n以内的所有阿姆斯特朗数，包括n。各个数值以空格分隔。
样例输入
1000
样例输出
1 153 370 371 407
*/