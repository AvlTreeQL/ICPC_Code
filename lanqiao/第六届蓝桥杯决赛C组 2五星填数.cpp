/*

标题：五星填数

如【图1.png】的五星图案节点填上数字：1~12，除去7和11。
要求每条直线上数字和相等。

如图就是恰当的填法。

请你利用计算机搜索所有可能的填法有多少种。
注意：旋转或镜像后相同的算同一种填法。

请提交表示方案数目的整数，不要填写任何其它内容。
	     0
	1  2  3  4
      5    6
        7
	8       9
*/
#include <bits/stdc++.h>
using namespace std; 
int a[10],num=0;
void check()
{
	int sum[15];
	sum[0]=a[1]+a[2]+a[3]+a[4];
	sum[1]=a[0]+a[2]+a[5]+a[8];
	sum[2]=a[0]+a[3]+a[6]+a[9];
	sum[3]=a[1]+a[5]+a[7]+a[9];
	sum[4]=a[4]+a[6]+a[7]+a[8];

	for(int i=1;i<5;i++)
	{
		if(sum[0]!=sum[i]) return ;
	}
	num++;

}
bool visit[10];

void dfs(int deep)  //看情况 剪枝 
{
	if(deep==10)
	{
		check();
		return ;
	}
	for(int i=1;i<=12;i++)
	{
		if(!visit[i])
		{
			a[deep]=i;
			visit[i]=true;
			dfs(deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	visit[7]=visit[11]=true;
	dfs(0);
	cout<<num/10<<endl;
	return 0;
}
