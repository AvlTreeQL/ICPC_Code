/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。

*/
#include<bits/stdc++.h>
using namespace std;
bool visit[7][7];
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}},sum=0;
void dfs(int x,int y)
{
	if(visit[x][y])
		return ;
	visit[x][y]=true;
	visit[6-x][6-y]=true;
	if(x==0||y==0||x==6||y==6)//想象 剪刀剪到边缘就停止，在边缘剪纸没有意义 
	{
		sum++;
		visit[x][y]=false;
		visit[6-x][6-y]=false; //这里别忘了 重置 
		return ;
	}
	
	for(int i=0;i<4;i++)
	{
		dfs(x+dir[i][0],y+dir[i][1]);
	}
	visit[x][y]=false;
	visit[6-x][6-y]=false;
}
int main()
{
	dfs(3,3);
	cout<<sum/4<<endl;
	return 0;
}
