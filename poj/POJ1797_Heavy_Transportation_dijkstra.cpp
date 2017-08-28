#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int maxn = 1e3 + 10;
const int inf = 1e9;
class edge {
public:
	int to;
	int cost;
	edge(){}
	edge(int a, int b) :to(a), cost(b) {}
};
int dis[maxn];
int n, m;
void dij(vector<edge> G[], int src) {
	priority_queue<P, vector<P>, less<P> > que;
	dis[src] = inf;
	que.push(P(dis[src], src));
	while (!que.empty()){
		P p = que.top();
		que.pop();
		int u = p.second;
		int d = p.first;
		if (d != dis[u]) continue;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].to;
			int w = G[u][i].cost;
			if (min(d,w) > dis[v]) {
				dis[v] = min(d, w);
				que.push(P(dis[v], v));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		vector<edge> G[maxn];
		int a, b, w;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			G[a].push_back(edge(b, w));
			G[b].push_back(edge(a, w));
		}
		fill(dis, dis + n + 1, -inf);
		dij(G, 1);
		cout << "Scenario #" << it + 1 << ":" << endl;
		cout << dis[n] << endl;
		if (it + 1 < t) cout << endl;
	}
	return 0;
}
