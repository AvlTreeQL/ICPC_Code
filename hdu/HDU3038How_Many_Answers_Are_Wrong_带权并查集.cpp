#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int f[maxn], dis[maxn]; //dis[a] 代表 f[a] 到 a 的距离 父节点一定比子节点小 f[a]< a
int n, m;
void init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		dis[i] = 0;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int y = f[x];
	f[x] = find(f[x]);
	dis[x] += dis[y];
	return f[x];
}
bool merge(int a, int b, int w) { //这里 a 一定小于 b
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) {
		if (dis[b] - dis[a] == w) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		f[pb] = pa;
		dis[pb] = dis[a] + w - dis[b];//dis[pb] 代表 f[pb] 到 pb 即 pa 到 pb的距离
		return true;
	}
	
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		init(n);
		int a, b, w;
		int ans = 0;
		while (m--) {
			cin >> a >> b >> w;
			if (!merge(a-1, b, w)) { // !!! a-1
				ans++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}