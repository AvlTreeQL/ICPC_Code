/*

标题：方格填数

在2行5列的格子中填入1到10的数字。
要求：
相邻的格子中的数，右边的大于左边的，下边的大于上边的。

如【图1.png】所示的2种，就是合格的填法。

请你计算一共有多少种可能的方案。

请提交该整数，不要填写任何多余的内容（例如：说明性文字）。

answer: 42

*/

#include<bits/stdc++.h>
using namespace std;
bool visit[10];
int s[2][5]={1,2,3,4,5,6,7,8,9,10};
int sum=0;
void check()
{
	if(s[0][0]>s[1][0]) return ;
	for(int i=1;i<5;i++)
	{
		if(s[0][i-1]>s[0][i]||s[1][i-1]>s[1][i]||s[0][i]>s[1][i])
			return;
	} 
	sum++;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
			cout<<s[i][j];
		cout<<endl;
	}
	cout<<endl;
}
void dfs(int s[],int deep)
{
	if(deep==10)
	{
		check();
		return ;
	}
	for(int i=0;i<10;i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			s[deep]=i;
			dfs(s,deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
//	dfs(*s,0);
	int *p=*s;
	do
	{
		check();
	}while(next_permutation(p,p+10));
	cout<<sum<<endl;
	return 0;
}
