#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e4 + 10;
int dfn[maxn], low[maxn], _index, scc;
bool in_stack[maxn];
stack<int> stk;
vector<vector<int> > G;
void tarjan(int u) {
	dfn[u] = low[u] = ++_index;
	stk.push(u);
	in_stack[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		scc++;
		int x;
		do {
			x = stk.top();
			in_stack[x] = false;;
			stk.pop();
		} while (x != u);
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		G.resize(n + 1);
		int a, b;
		while (m--) {
			cin >> a >> b;
			G[a].push_back(b);
		}
		scc = 0;
		_index = 0;
		memset(in_stack, false, sizeof(in_stack));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) {
				tarjan(i);
			}
		}
		if (scc == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		G.clear();
	}
	return 0;
}
