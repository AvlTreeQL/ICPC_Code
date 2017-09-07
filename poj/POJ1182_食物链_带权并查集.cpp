#include <iostream>
using namespace std;
int n, m;
int f[50010], r[50010];					// r[i] == 0，i和父节点同类； r[i] == 1, i吃父节点；r[i] == 2 ,i被父节点吃
void init(int n) {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		r[i] = 0;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int y = f[x];
	f[x] = find(f[x]);
	r[x] = (r[x] + r[y]) % 3;
	return f[x];
}
bool merge(int w, int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) {
		if ((r[a] - r[b] + 3) % 3 != w - 1)return false;
		else return true;
	}
	f[pa] = pb;
	r[pa] = (r[b] - r[a] + w - 1 + 3) % 3;// 想象 pa 连在 b 的后面， 加上 pa和b的阶级差
	//	r[pba] = (r[a] - r[b] + w - 1 + 3) % 3;
	//         0     1     1
	return true;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	//while (cin >> n >> m) {
	cin >> n >> m;
	init(n);
		int ans = 0, w, a, b;
		while (m--) {
			cin >> w >> a >> b;
			if (a>n||b>n||(w==2&&a==b)||!merge(w, a, b)) {
				ans++;
			}
		}
		cout << ans << endl;
//	}
	return 0;
}