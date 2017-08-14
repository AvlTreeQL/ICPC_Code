/*
在社交网络平台注册时，用户通常会输入自己的兴趣爱好，以便找到和自己兴趣相投的朋友。
有部分兴趣相同的人们就形成了“社交集群”。现请你编写程序，找出所有的集群。

输入格式：

输入的第一行给出正整数N（<=1000），即社交网络中的用户总数（则用户从1到N编号）。
随后N行，每行按下列格式列出每个人的兴趣爱好：

Ki: hi[1] hi[2] ... hi[Ki]

其中Ki（>0）是第i个人的兴趣的数量，hi[j]是第i个人的第j项兴趣的编号，编号范围为[1, 1000]内的整数。

输出格式：

首先在第一行输出整个网络中集群的数量，然后在第二行按非递增的顺序输出每个集群中用户的数量。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
输出样例：
3
4 3 1
*/

#include<bits/stdc++.h>
using namespace std;
int f[1010]={0},n;
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void cmb(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x<y) f[y]=x;
	else f[x]=y;
}
void init()
{
	for(int i=0;i<1010;i++)
	{
		f[i]=i;
	}
}
int cmp(const int x,const int y)
{
	if(x>y) return 1;
	else return 0;
}
int main()
{
	int c[1000]={0},sum=0,num[1010]={0};
	cin>>n;
	init();
	for(int i=0;i<n;i++)
	{
		int t,p;
		char u;
		cin>>t>>u>>c[i];
		for(int j=1;j<t;j++)
		{
			cin>>p;
			cmb(c[i],p);
		}
	}
	for(int i=0;i<n;i++)
	{
		num[find(c[i])]++;
	}
	for(int i=0;i<1010;i++)
	{
		if(num[i]) sum++;
	} 
	sort(num,num+1010,greater<int>());
	cout<<sum<<endl<<num[0];
	for(int i=1;i<sum;i++)
	{
		cout<<' '<<num[i];
	}

	return 0;
}
