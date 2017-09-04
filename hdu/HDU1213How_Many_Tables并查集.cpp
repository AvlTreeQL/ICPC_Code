#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int f[1010];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		f[a] = b;
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		init(n);
		int a, b;
		while (m--) {
			cin >> a >> b;
			merge(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (find(i) == i) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}