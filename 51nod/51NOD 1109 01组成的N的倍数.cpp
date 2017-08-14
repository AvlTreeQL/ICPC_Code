/*
1109 01组成的N的倍数
基准时间限制：1 秒 空间限制：131072 KB 分值: 40 难度：4级算法题 收藏  关注
给定一个自然数N，找出一个M，使得M > 0且M是N的倍数，并且M的10进制表示只包含0或1。求最小的M。
例如：N = 4，M = 100。
Input
输入1个数N。(1 <= N <= 10^6)
Output
输出符合条件的最小的M。
Input示例
4
Output示例
100
*/
#include<iostream>
#include<sstream>
using namespace std;
void change(string &s,int n)
{
	string bit="01";
	if(n==0)
	{
		s="";
		return ;
	}
	change(s,n/2);
	s+=bit[n%2];	
}

void fun(int n)
{
	long long sum;
	for(long long i=1;;i++)
	{
		string s;	
		change(s,i);
		stringstream ss(s);
		ss>>sum;
		if(sum%n==0) 
		{
			cout<<s<<endl;
			break;
		}
	}
	
}
int main()
{
	int n;
	cin>>n;
	fun(n);
	return 0;
}
