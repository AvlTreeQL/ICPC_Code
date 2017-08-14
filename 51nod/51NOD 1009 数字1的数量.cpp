/*

给定一个十进制正整数N，写下从1开始，到N的所有正数，计算出其中出现所有1的个数。


例如：n = 12，包含了5个1。1,10,12共包含3个1，11包含2个1，总共5个1。



Input
输入N(1 <= N <= 10^9)

Output
输出包含1的个数

Input示例
12

Output示例
5
*/
#include<bits/stdc++.h>
using namespace std;
long fun(int x)
{
	int sum=0;
	while(x)
	{
		if(x%10==1) sum++;
		x/=10;
	}
	return sum;
}
int main()
{
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum+=fun(i);
	}               
	cout<<sum<<endl;                                                                                                                                                                        
	return 0;
}
