#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int f[30010], _size[30010], dis[30010];
void init(int n) {
	for (int i = 0; i < n; i++) {
		f[i] = i;
		_size[i] = 1;
		dis[i] = 0;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int y = f[x];
	f[x] = find(y);
	dis[x] += dis[y];
	return f[x];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		f[a] = b;
		dis[a] = _size[b];
		_size[b] += _size[a];
	}
}
int main() {
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	while (true) {
		cin >> n >> m;
		init(n);
		if (!n && !m) break;
		while (m--) {
			int num, father, temp;
			cin >> num;
			cin >> father;
			for (int i = 1; i < num; i++) {
				cin >> temp;
				merge(father, temp);
			}
		}
		cout << _size[find(0)] << endl;
	}
	return 0;
}