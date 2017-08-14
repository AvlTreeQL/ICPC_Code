/*
一步之遥

从昏迷中醒来，小明发现自己被关在X星球的废矿车里。
矿车停在平直的废弃的轨道上。
他的面前是两个按钮，分别写着“F”和“B”。

小明突然记起来，这两个按钮可以控制矿车在轨道上前进和后退。
按F，会前进97米。按B会后退127米。
透过昏暗的灯光，小明看到自己前方1米远正好有个监控探头。
他必须设法使得矿车正好停在摄像头的下方，才有机会争取同伴的援助。
或许，通过多次操作F和B可以办到。

矿车上的动力已经不太足，黄色的警示灯在默默闪烁...
每次进行 F 或 B 操作都会消耗一定的能量。
小明飞快地计算，至少要多少次操作，才能把矿车准确地停在前方1米远的地方。

请填写为了达成目标，最少需要操作的次数。

注意，需要提交的是一个整数，不要填写任何无关内容（比如：解释说明等）
*/
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int x;
	int step;
	node(){}
	node(int a,int b)
	{
		x=a;
		step=b;
	}
};
map<int,bool> visit;
void bfs(int x)
{
	queue<node> q;
	q.push(node(x,0));
	visit[x]=true;
	node head;
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		if(head.x==1)
		{
			cout<<head.step<<endl;
			break;
		}
		if(!visit[head.x+97])
		{
			q.push(node(head.x+97,head.step+1));
			visit[head.x+97]=true;
		}
		if(!visit[head.x-127])
		{
			q.push(node(head.x-127,head.step+1));
			visit[head.x-127]=true;
		}
	}
}
int main()
{
	bfs(0);
	return 0;
}
