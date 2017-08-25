/*************************************************************************
	> File Name: 6181:Two_Paths_dijkstra_次短路.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月25日 星期五 20时25分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> Pair;
const int maxn = 100100;
const long long inf = 1e15;
class edge
{
public:
    int to, cost;
    edge() {}
    edge(int a, int w)
    {
        to = a;
        cost = w;
    }
};
int dis1[maxn], dis2[maxn], sumt[maxn];
void dij(vector<edge> G[], int src, int dis[])
{

    priority_queue<Pair, vector<Pair>, greater<Pair> > que;
    dis[src] = 0, sumt[src] = 1;
    que.push(Pair(dis[src], src));

    while(!que.empty()) {
        Pair u = que.top();
        que.pop();
        if(dis[u.second] < u.first) continue;
        for(int i = 0; i < G[u.second].size(); i++) {
            edge e = G[u.second][i];
            if(dis[e.to] > u.first + e.cost) {
                sumt[e.to] = sumt[u.second];
                dis[e.to] = u.first + e.cost;
                que.push(Pair(dis[e.to], e.to));
            } else if(dis[e.to] == u.first + e.cost) {
                sumt[e.to] += sumt[u.second];
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        vector<edge> G[maxn];
        int n, num;
        cin >> n >> num;
        int a, b, w;
        for(int i = 0; i < num; i++) {
            cin >> a >> b >> w;
            G[a].push_back(edge(b, w));
            G[b].push_back(edge(a, w));
        }
        long long ans = 0;
        fill(dis1, dis1 + n + 1, inf);
        fill(dis2, dis2 + n + 1, inf);
        memset(sumt, 0, sizeof(sumt));
        dij(G, 1, dis1);
        if(sumt[n] > 1) {
            ans = dis1[n];
            cout << ans << endl;
            continue;
        }
        dij(G, n, dis2);
        ans = inf;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < G[i].size(); j++) {
                edge e = G[i][j];
                if(dis1[i] + e.cost + dis2[e.to] > dis1[n]) {
                    ans = min(ans, (long long)(dis1[i] + e.cost + dis2[e.to]));
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}
