/*1085 背包问题
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题
在N件物品取出若干件放在容量为W的背包里，每件物品的体积为W1，W2……Wn（Wi为整数），与之相对应的价值为P1,P2……Pn（Pi为整数）。求背包能够容纳的最大价值。
Input
第1行，2个整数，N和W中间用空格隔开。N为物品的数量，W为背包的容量。(1 <= N <= 100，1 <= W <= 10000)
第2 - N + 1行，每行2个整数，Wi和Pi，分别是物品的体积和物品的价值。(1 <= Wi, Pi <= 10000)
Output
输出可以容纳的最大价值。
Input示例
3 6
2 5
3 8
4 9
Output示例
14

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,w,dp[101][10001]={0};
	cin>>n>>w;
	vector<pair<int,int> > v;
	v.push_back(make_pair(0,0));
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(j>=v[i].first)
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i].first]+v[i].second);
			}
			else 
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][w]<<endl;
	return 0;
}

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class node
{
public:
	int w;
	int p;
	node(int a,int b)
	{
		w=a;
		p=b;
	}	
};
int main()
{
	int N,W;
	int dp[101][101]={0};
	vector<node> a;
	cin>>N>>W;
	int p,q;
	a.push_back(node(0,0));
	for(int i=1;i<=N;i++)
	{
		cin>>p>>q;
		a.push_back(node(p,q));
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=W;j++)
		{
			if(j<a[i].w) dp[i][j]=dp[i-1][j];  
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w]+a[i].p);
		}
	cout<<dp[N][W]<<endl;
	return 0;
}
