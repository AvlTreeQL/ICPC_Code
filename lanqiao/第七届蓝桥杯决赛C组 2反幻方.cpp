/*

反幻方

下面考虑一个相反的问题。
可不可以用 1~9 的数字填入九宫格。
使得：每行每列每个对角线上的数字和都互不相等呢？


我国古籍很早就记载着

2 9 4
7 5 3
6 1 8

这是一个三阶幻方。每行每列以及对角线上的数字相加都相等。

这应该能做到。
比如：
9 1 2
8 4 3
7 5 6

你的任务是搜索所有的三阶反幻方。并统计出一共有多少种。
旋转或镜像算同一种。

比如：
9 1 2
8 4 3
7 5 6

7 8 9
5 4 1
6 3 2

2 1 9
3 4 8
6 5 7

等都算作同一种情况。

请提交三阶反幻方一共多少种。这是一个整数，不要填写任何多余内容。
answea: 3120

*/
#include<bits/stdc++.h>
using namespace std;
bool visit[10];
int sum=0;
int a[][3]={1,2,3,4,5,6,7,8,9};
void check()
{
	int s[3]={0,0,0},l[3]={0,0,0};
	set<int> k;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			s[i]+=a[i][j];
			l[i]+=a[j][i];
		}
		k.insert(s[i]);
		k.insert(l[i]);
	}
	int t=a[0][0]+a[1][1]+a[2][2];
	int p=a[0][2]+a[1][1]+a[2][0];
	k.insert(t);
	k.insert(p);
	if(k.size()==8) sum++;
}
void dfs(int a[],int x)
{
	if(x==9)
	{
		check();
		return ;
	}
	for(int i=1;i<10;i++)
	{
		if(!visit[i])
		{
			a[x]=i;
			visit[i]=true;
			dfs(a,x+1);
			visit[i]=false;
		}
	}
}
int main()
{
	dfs(*a,0);
	if(sum)cout<<sum/8<<endl;
	return 0;
}
