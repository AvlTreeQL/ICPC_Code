#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;
int n,a,b,flag;
bool visit[30][30]; 
int move[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
void dfs(int x,int y,int deep,string s)
{
	
	if(visit[x][y]==true||x<0||y<0||x>=b||y>=a||flag==1) return ;
	int i;
	s+=x+'A';
	s+=y+'1';
	if(deep==a*b)
	{
		cout<<s;
		flag=1;
		return ;
	}
	for(i=0;i<8;i++)
	{
		visit[x][y]=true;
		dfs(x+move[i][0],y+move[i][1],deep+1,s);
		visit[x][y]=false;
	}
}
int main()
{
	int i,j,k;
	cin>>n;
	k=n;
	while(n--)
	{
		string s;
		memset(visit,false,sizeof(visit));
		flag=0;
		cin>>a>>b;
		cout<<"Scenario #"<<k-n<<':'<<endl;
		for(j=0;j<b;j++)
		{
			for(i=0;i<a;i++)
			{								
				dfs(i,j,1,s);
				if(flag==1)
				{
					i=a,j=b;
					if(n)cout<<endl<<endl;
				}
			}
		}
		if(flag==0)
		{		
			cout<<"impossible"<<endl;
			if(n)cout<<endl;
		}
	}
	return 0;
}
