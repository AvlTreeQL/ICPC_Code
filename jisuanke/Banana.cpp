#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
using namespace std;
const int maxn = 1e4 + 10;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		vector<vector<int> > G;
		vector<vector<int> > S;
		int n, m;
		cin >> n >> m;
		G.resize(n + 1);
		S.resize(n + 1);
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			G[a].push_back(b);
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			S[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			set<int> V;
			for (int j = 0; j < G[i].size(); j++) {
				int v = G[i][j];
				for (int k = 0; k < S[v].size(); k++) {
					V.insert(S[v][k]);
				}
			}
			for (set<int>::iterator it = V.begin(); it != V.end(); it++) {
				cout << i << " " << *it << endl;
			}
			
		}
	}
	
	return 0;
}
