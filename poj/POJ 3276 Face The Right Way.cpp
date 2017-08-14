#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<numeric> 
#define MAX 65535
using namespace std;
int k[5010],t[5010];
int N;
int check(int n)
{
	int sum=0,i;
	memcpy(t,k,sizeof(int)*N);
	for(i=0;i+n<=N;i++)
	{
		if(t[i]==1)
		{ 
			for(int j=i;j<n+i;j++)
			{
				t[j]=t[j]==1?0:1;	
			}
			sum++;
		}
	}
	if(accumulate(t+N-n,t+N,0)) return -1;
	else return sum;
}
int main()
{
	int K,M;
	char c;
	cin>>N;
	M=N;
	for(int i=0;i<N;i++)
	{
		cin>>c;
		k[i]=c=='B'?1:0;
	}
	for(int i=1;i<=N;i++)
	{
		int num=check(i);
		if(num<M&&num>=0)
		{
			M=num;
			K=i;
		}
	}
	cout<<K<<' '<<M<<endl;
	return 0;
} 
//7 
//B B F B F B B
