#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int maxn = 510;
const int inf = 1e9;
class edge {
public:
	int to;
	int cost;
	edge() {}
	edge(int a, int b) :to(a), cost(b) {}
};
int dis[maxn];
int cnt[maxn];
int n;
bool flag;
void spfa(vector<edge> G[], int src) {

	priority_queue<P, vector<P>, greater<P> > que;
	dis[src] = 0;
	cnt[src]++;
	que.push(P(dis[src], src));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int u = p.second;
		int d = p.first;
		if (d > dis[u]) continue;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].to;
			int w = G[u][i].cost;
			if (d + w < dis[v]) {
				dis[v] = d + w;
				cnt[v]++;
				if (cnt[v] > n) {
					flag = true;
					return;
				}
				que.push(P(dis[v], v));
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int m1, m2;
		vector<edge> G[maxn];
		cin >> n >> m1 >> m2;
		while (m1--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back(edge(v, w));
			G[v].push_back(edge(u, w));
		}
		while (m2--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back(edge(v, -1 * w));
		}
		flag = false;
		fill(dis, dis + n + 1, inf);
		memset(cnt, 0, sizeof(cnt));
		spfa(G, 1);
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}