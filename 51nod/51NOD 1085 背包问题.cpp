/*1085 ��������
��׼ʱ�����ƣ�1 �� �ռ����ƣ�131072 KB ��ֵ: 0 �Ѷȣ�������
��N����Ʒȡ�����ɼ���������ΪW�ı����ÿ����Ʒ�����ΪW1��W2����Wn��WiΪ����������֮���Ӧ�ļ�ֵΪP1,P2����Pn��PiΪ���������󱳰��ܹ����ɵ�����ֵ��
Input
��1�У�2��������N��W�м��ÿո������NΪ��Ʒ��������WΪ������������(1 <= N <= 100��1 <= W <= 10000)
��2 - N + 1�У�ÿ��2��������Wi��Pi���ֱ�����Ʒ���������Ʒ�ļ�ֵ��(1 <= Wi, Pi <= 10000)
Output
����������ɵ�����ֵ��
Inputʾ��
3 6
2 5
3 8
4 9
Outputʾ��
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
