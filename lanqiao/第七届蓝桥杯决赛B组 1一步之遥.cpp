/*
һ��֮ң

�ӻ�����������С�������Լ�������X����ķϿ��
��ͣ��ƽֱ�ķ����Ĺ���ϡ�
������ǰ��������ť���ֱ�д�š�F���͡�B����

С��ͻȻ����������������ť���Կ��ƿ��ڹ����ǰ���ͺ��ˡ�
��F����ǰ��97�ס���B�����127�ס�
͸���谵�ĵƹ⣬С�������Լ�ǰ��1��Զ�����и����̽ͷ��
�������跨ʹ�ÿ�����ͣ������ͷ���·������л�����ȡͬ���Ԯ����
����ͨ����β���F��B���԰쵽��

���ϵĶ����Ѿ���̫�㣬��ɫ�ľ�ʾ����ĬĬ��˸...
ÿ�ν��� F �� B ������������һ����������
С���ɿ�ؼ��㣬����Ҫ���ٴβ��������ܰѿ�׼ȷ��ͣ��ǰ��1��Զ�ĵط���

����дΪ�˴��Ŀ�꣬������Ҫ�����Ĵ�����

ע�⣬��Ҫ�ύ����һ����������Ҫ��д�κ��޹����ݣ����磺����˵���ȣ�
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
