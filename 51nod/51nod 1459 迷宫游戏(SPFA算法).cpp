/*
������һ���Թ�ǰ�����Թ������ɸ�������ɣ�ÿ�����䶼��һ���÷֣���һ�ν���������䣬��Ϳ��Եõ������������������˫���·������Щ���䣬��������Щ��·��һ�������ߵ�����һ��������ҪһЩʱ�䡣��Ϸ�涨����������յ㷿�䣬����ҪĿ���Ǵ���㾡�쵽���յ㣬��������ҪĿ���ǰ���£�ʹ����ĵ÷��ܺ;����ܴ������������ˣ��������䡢��·�������������յ��ȫ����Ϣ�����ܼ����ھ����뿪�Թ���ǰ���£�������÷��Ƕ���ô��
Input
��һ��4������n (<=500), m, start, end��n��ʾ����ĸ����������Ŵ�0��(n - 1)��m��ʾ��·��,������������֮�����ֻ��һ����·��start��end��ʾ�����յ㷿��ı�š�
�ڶ��а���n���ո�ָ���������(������600)����ʾ����ÿ��������ĵ÷֡�
�ٽ�����m�У�ÿ��3���ո�ָ�������x, y, z (0<z<=200)��ʾ��·,��ʾ�ӷ���x������y(˫��)�ĵ�·,ע�⣬���ֻ��һ����·������������, ����Ҫ��ʱ��Ϊz��
���뱣֤��start��end������һ��·����
Output
һ�У������ո�ָ�����������һ����ʾ��������Ҫ��ʱ�䣬�ڶ�����ʾ��������ʱ��ǰ���¿��Ի�õ����÷֡�
Inputʾ��
3 2 0 2
1 2 3
0 1 10
1 2 11
Outputʾ��
21 6

����˼�룺�Ի��ѵ�ʱ��Ϊ��һ����key����õĵ÷�Ϊ�ڶ�����key��
��SPFA�����·���㷨�ж��һ���÷ֵļ�¼��ͬʱ������Ĺؼ���˳����һ���ж��������ɣ�
�����ľ������SPFAģ���ˡ����������ע�͡�
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
bool vis[MAXN];//vis[i]=true��ʾ���ǵ�i�ڶ����� vis[i]=false��ʾ���ڶ�����
int dis[MAXN];
int sco[MAXN];
int cnt[MAXN];//ͳ�ƶ������Ӵ���
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
    vis[st]=true;//ע�⣺��������Ѳ�ͬ��vis[i]=true��ʾ���ǵ�i�ڶ����� vis[i]=false��ʾ���ڶ�����,
    cnt[st]++;   //���������������һ����Ƿ��ʹ���Ͳ����ٷ��ʵ���˼!!! 
    while(!q.empty())
    {
        now=q.front();
        q.pop_front();//��ͷԪ�س��ӣ������������
        vis[now]=false;//����û����䣡����spfa�������Ϊ�˺�����ݵ�ͼ�е�ĳ��������
        if(cnt[now]>n)//����һ��������һ������ĵ㲻�ڶ����У������������ӵĹ����������ѵĻ��ݲ��� 
        {
            return false; //������Ӵ������ޣ�˵���и���
        }
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            nex=edge[i].to;
            if(dis[nex]>dis[now]+edge[i].w)
            {
                dis[nex]=dis[now]+edge[i].w;
                sco[nex]=point[nex]+sco[now];
                if(!vis[nex]) //���㲻�ڶ���
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
