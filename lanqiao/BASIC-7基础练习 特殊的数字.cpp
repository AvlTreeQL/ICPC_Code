#include<stdio.h>
#include<math.h>
int main()
{
	int fun(int n);
	int i,j,k;
	for(i=100;i<=999;i++)
		if(fun(i)==1) printf("%d\n",i);
	return 0;
}
int fun(int n)
{	int sum=0,temp=n,temp2;
	while(n!=0)
	{ 
//		sum+=pow(n%10,3); 
		temp2=n%10;
		sum+=temp2*temp2*temp2;
		n/=10;
	}
	if(sum==temp) return 1;
	else return 0;
}
/*
问题描述
　　153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求所有满足这种条件的三位十进制数。
输出格式
　　按从小到大的顺序输出满足条件的三位十进制数，每个数占一行。
*/
