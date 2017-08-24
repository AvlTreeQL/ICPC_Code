/*************************************************************************
	> File Name: team10_1011.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月24日 星期四 16时04分20秒
 ************************************************************************/

#include<cstdio>  
#include<algorithm>  
#include<queue>  
#include<vector>  
#include<cstring>  
#include<functional>
using namespace std;
const int maxn = 100100;
const long long inf = 1e15;
typedef pair<long long, int> P;

struct edge {
	int to;
	long long cost;
};
int n, m;
long long ans;
long long dis1[maxn], disn[maxn], sumt[maxn];
void Dijkstra(int src, long long dis[], vector<edge> G[])
{
	priority_queue< P, vector<P>, greater<P> >que;
	dis[src] = 0, sumt[src] = 1;
	que.push(P(dis[src], src));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int u = p.second;
		long long d = p.first;
		if (d>dis[u]) continue;
		for (int i = 0; i<G[u].size(); i++) {
			edge e = G[u][i];
			if (e.cost + d<dis[e.to]) {
				sumt[e.to] = sumt[u];
				dis[e.to] = d + e.cost;
				que.push(P(dis[e.to], e.to));
			}
			else if (e.cost + d == dis[e.to]) {
				sumt[e.to] += sumt[u];
			}
		}
	}
}
void solve(vector<edge> G[])
{
	fill(dis1 + 1, dis1 + 1 + n, inf);
	fill(disn + 1, disn + 1 + n, inf);
	fill(sumt + 1, sumt + 1 + n, 0);
	Dijkstra(1, dis1, G);
	if (sumt[n] > 1) {
		ans = dis1[n];
		return;
	}

	Dijkstra(n, disn, G);

	ans = 1e15;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int v = G[i][j].to, d = G[i][j].cost;

			if (dis1[i] + d + disn[v] > dis1[n]) {
				ans = min(ans, (long long)(dis1[i] + d + disn[v]));
			}
		}

	}

}
int main()
{
	//  freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<edge> G[maxn];
		scanf("%d%d", &n, &m);
		int u, v;
		long long w;
		edge e;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%lld", &u, &v, &w);
			e.to = v, e.cost = w;
			G[u].push_back(e);
			e.to = u;
			G[v].push_back(e);
		}
		solve(G);
		printf("%lld\n", ans);

	}

	return 0;
}
