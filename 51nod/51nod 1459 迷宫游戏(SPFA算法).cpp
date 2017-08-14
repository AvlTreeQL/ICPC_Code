/*
你来到一个迷宫前。该迷宫由若干个房间组成，每个房间都有一个得分，第一次进入这个房间，你就可以得到这个分数。还有若干双向道路连结这些房间，你沿着这些道路从一个房间走到另外一个房间需要一些时间。游戏规定了你的起点和终点房间，你首要目标是从起点尽快到达终点，在满足首要目标的前提下，使得你的得分总和尽可能大。现在问题来了，给定房间、道路、分数、起点和终点等全部信息，你能计算在尽快离开迷宫的前提下，你的最大得分是多少么？
Input
第一行4个整数n (<=500), m, start, end。n表示房间的个数，房间编号从0到(n - 1)，m表示道路数,任意两个房间之间最多只有一条道路，start和end表示起点和终点房间的编号。
第二行包含n个空格分隔的正整数(不超过600)，表示进入每个房间你的得分。
再接下来m行，每行3个空格分隔的整数x, y, z (0<z<=200)表示道路,表示从房间x到房间y(双向)的道路,注意，最多只有一条道路连结两个房间, 你需要的时间为z。
输入保证从start到end至少有一条路径。
Output
一行，两个空格分隔的整数，第一个表示你最少需要的时间，第二个表示你在最少时间前提下可以获得的最大得分。
Input示例
3 2 0 2
1 2 3
0 1 10
1 2 11
Output示例
21 6

解题思想：以花费的时间为第一排序key，获得的得分为第二排序key，
在SPFA求最短路的算法中多加一个得分的记录，同时按排序的关键字顺序多加一个判断条件即可，
其他的就是裸的SPFA模板了。具体见代码注释。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#include<cstdio>
#define LL long long
using namespace std;
const int MAXN=1000010;
const int INF=0x3f3f3f3f;
struct node{
    int to;
    int w;
    int next;
}edge[MAXN];
int point[MAXN];
int st,ed,n,m;
int tot=0;
int head[MAXN];
bool vis[MAXN];//vis[i]=true表示的是点i在队列中 vis[i]=false表示不在队列中
int dis[MAXN];
int sco[MAXN];
int cnt[MAXN];//统计顶点的入队次数
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    tot=0;
}
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
bool spfa(int st,int ed)
{
    deque<int>q;
    int now,nex,i;
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
        cnt[i]=0;
        dis[i]=INF;
        sco[i]=point[i];
    }
    dis[st]=0;
    sco[st]=point[st];
    q.push_back(st);
    vis[st]=true;//注意：这里跟广搜不同，vis[i]=true表示的是点i在队列中 vis[i]=false表示不在队列中,
    cnt[st]++;   //并不是像广搜那样一旦标记访问过后就不能再访问的意思!!! 
    while(!q.empty())
    {
        now=q.front();
        q.pop_front();//队头元素出队，并且消除标记
        vis[now]=false;//广搜没有这句！！！spfa用这句是为了后面回溯到图中的某个交叉点后
        if(cnt[now]>n)//向另一个方向（另一个方向的点不在队列中）搜索，这样子的广搜类似深搜的回溯操作 
        {
            return false; //超过入队次数上限，说明有负环
        }
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            nex=edge[i].to;
            if(dis[nex]>dis[now]+edge[i].w)
            {
                dis[nex]=dis[now]+edge[i].w;
                sco[nex]=point[nex]+sco[now];
                if(!vis[nex]) //顶点不在队内
                {
                    vis[nex]=true;
                    cnt[nex]++;
                    if(!q.empty()&&dis[nex]<dis[q.front()])
                    {
                        q.push_front(nex);
                    }
                    else
                    {
                        q.push_back(nex);
                    }
                }
            }
            else if(dis[nex]==dis[now]+edge[i].w&&sco[nex]<point[nex]+sco[now])
            {
                sco[nex]=point[nex]+sco[now];
                if(!vis[nex])
                {
                    cnt[nex]++;
                    vis[nex]=true;
                    if(!q.empty()&&dis[nex]<dis[q.front()])
                    {
                        q.push_front(nex);
                    }
                    else
                    {
                        q.push_back(nex);
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int i,u,v,w;
    //freopen("D:\p1459t5in.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&st,&ed)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&point[i]);
        }
        init();
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        spfa(st,ed);
        printf("%d %d\n",dis[ed],sco[ed]);
    }
    return 0;
}
