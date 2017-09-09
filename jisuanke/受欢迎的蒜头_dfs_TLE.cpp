/*************************************************************************
> File Name: 受欢迎的蒜头.cpp
> Author: heheql
> Mail: 374655767@qq.com
> Created Time: 2017年09月08日 星期五 11时26分20秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e4 + 10;
vector<vector<int> > G;
bool vis[maxn];
int sum = 0;
void dfs(int u) {
	vis[u] = true;
	sum++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!vis[v]) {
			dfs(v);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	G.resize(n + 1);
	int a, b;
	while (m--) {
		cin >> a >> b;
		G[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		memset(vis, false, sizeof(vis));
		dfs(i);
		if (sum == n) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
