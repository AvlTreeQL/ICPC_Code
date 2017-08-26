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
vector<edge> G[maxn];
void dij(int src) {
	priority_queue<P, vector<P>, greater<P> > que;
	dis[src] = 0;
	que.push(P(dis[src], src));
	while (!que.empty()){
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
				que.push(P(dis[v], v));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T, N;
	cin >> T >> N;
	int a, b, w;
	while (T--) {
		cin >> a >> b >> w;
		G[a].push_back(edge(b, w));
		G[b].push_back(edge(a, w));
	}
	fill(dis, dis + N + 1, inf);
	dij(1);
	cout << dis[N] << endl;
	return 0;
}