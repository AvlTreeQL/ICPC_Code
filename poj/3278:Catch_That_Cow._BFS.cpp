/*

农民约翰被告知一个逃亡的牛的位置，并想立即抓住她。他开始在一个点N（0≤N≤100000）一号线和牛是在点K（0≤K≤100000）在同一号线。农夫约翰有两种运输方式：步行和传送。
*行走：约翰可以从任何点x点x 1 x + 1在一分钟
*传送：约翰可以从任何点x在一分钟2点×X。
如果牛，不知道它的追求，根本不动，要多久农民约翰检索它？
输入
第1行：两个空间分离整数：n和k
输出
第1行：最少的时间，在几分钟内，农民约翰抓住逃犯。
样本输入
5 17
示例输出
四
提示
农民约翰到逃犯牛的最快方法是沿着以下路径：5-10-9-18-17移动，这需要4分钟。
*/
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define Max 100005
using namespace std;
bool visit[Max];

class node
{
public:
	int data;
	int step;
	node()
	{
		data=0;
		step=0;
	}
	node(int a,int b)
	{
		data=a;
		step=b;
	}
};

void BFS(node s,node e)
{
	
	queue<node> q;
	q.push(s);
	node head;
	
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		visit[head.data]=true;
		if(head.data==e.data)
		{
			cout<<head.step<<endl;
			return ;
		}
	
		if(head.data+1<Max&&!visit[head.data+1])
			q.push(node(head.data+1,head.step+1));

    	if(head.data-1>=0&&!visit[head.data-1])
			q.push(node(head.data-1,head.step+1));
    	
		if(head.data*2<Max&&!visit[head.data*2])
			q.push(node(head.data*2,head.step+1));
	}

}
int main()
{
	node s,e;
	while(~scanf("%d%d",&s.data,&e.data))
	{
		memset(visit,false,sizeof(visit));
		BFS(s,e);
	}
	return 0;
}