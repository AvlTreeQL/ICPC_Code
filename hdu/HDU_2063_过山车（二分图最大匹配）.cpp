#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
vector<int> G[1010];
bool vis[1010];
int ans[1010];

bool dfs(int u) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (vis[v]) continue;
		vis[v] = true;
		if (!ans[v] || dfs(ans[v])) {
			ans[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	while (true) {
		int k;
		cin >> k;
		if (!k)break;
		int m, n;
		cin >> m >> n;
		
		int a, b;
		while (k--) {
			cin >> a >> b;
			G[a].push_back(b);
		}
		int sum = 0;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))sum++;
		}
		cout << sum << endl;
		for (int i = 0; i < 1010; i++) {
			G[i].clear();
		}
	}
}