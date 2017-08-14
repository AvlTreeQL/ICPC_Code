#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t,p[1000];
	int n,a[1000]={-1000},i,q=0;
	map<string,int> K;
	map<string,string> N;
	map<string,string> A;
	cin>>s>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;	
		cin>>K[t];
		cin>>N[t];
		A[N[t]]=t;
	}
	t=s;
	i=0;	
	while(t!="-1")
	{	
		if(count(a,a+i,abs(K[t]))!=0)
		{
			N[A[t]]=N[t];
			p[q++]=t;
		}
		a[i++]=abs(K[t]);
		t=N[t];
	}
	for(i=0;i<n-q;i++)
	{
		cout<<s<<' ';
		cout<<K[s]<<' ';
		cout<<N[s]<<endl;
		s=N[s];
	}  
	i=0;
	if(q!=0)cout<<p[i]<<' ';
	for(i=1;i<q;i++)
	{
		cout<<K[p[i-1]]<<' ';
		cout<<p[i]<<endl;
		cout<<p[i]<<' ';
	}
	if(q!=0)cout<<K[p[i-1]]<<" -1"<<endl;
	return 0;
}
/*/.......ww....e
00100 5
99999 -7 87654
23854 -15 00000
87654 1 -1
00000 10 99999
00100 21 23854
*/
