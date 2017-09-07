#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 1010;
int f[maxn], r[maxn];
int n, m, x, y;
bool vis[maxn];
map<int, int> re;
void init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		r[i] = 0;
		vis[i] = false;
		re[i] = -1;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int y = f[x];
	f[x] = find(f[x]);
	r[x] = (r[x] + r[y]) % 2;
	return f[x];
}
bool merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) {
		if (r[a] == r[b]) {
			return false;
		}
		else {
			return true;
		}
	} 
	f[pb] = pa;
	r[pb] = (r[a] + r[b] + 1) % 2;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> x >> y) {
		init(n);
		int a, b;
		bool flag = false;
		while (m--) {
			cin >> a >> b;
			if (!merge(a, b)) flag = true;
	//		merge(a, b);
	//		vis[a] = vis[b] = true;
		}
		
		int temp;
		while (x--) {
			cin >> temp;
			vis[f[temp]] = true;
			if (re[f[temp]] == -1) {								//re[] 保存好队员 与该队员所在集合头结点的关系, 所有好队员与他所在头结点关系(如果关系已经确定)相同
				re[f[temp]] = r[temp];
			}
			else {
				if (r[temp] != re[f[temp]]) {
					flag = true;
				}
			}
		}
		while (y--) {
			cin >> temp;
			vis[f[temp]] = true;
			if (re[f[temp]] == -1) {
				re[f[temp]] = !r[temp];								//re[] 保存好队员与该队员所在集合头结点的关系, 所有差队员与他所在头结点关系(如果关系已经确定)不同
			}
			else {
				if (r[temp] == re[f[temp]]) {
					flag = true;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i] == i&&!vis[f[i]]) {
				sum++;
			}
		}
		if (sum > 1 || flag) {										//如果有两个未确定关系的集合或者出现矛盾 则不能确定关系
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	
	return 0;
}
