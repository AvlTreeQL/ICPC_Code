#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int f[maxn], dis[maxn]; //dis[a] ���� f[a] �� a �ľ��� ���ڵ�һ�����ӽڵ�С f[a]< a
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
bool merge(int a, int b, int w) { //���� a һ��С�� b
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
		dis[pb] = dis[a] + w - dis[b];//dis[pb] ���� f[pb] �� pb �� pa �� pb�ľ���
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