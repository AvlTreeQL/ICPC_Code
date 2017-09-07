#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
int n;
int f[30], _size[30], in[30], out[30];
void init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		_size[i] = 1;
	}
}
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	int y = f[x];
	f[x] = find(f[x]);
	_size[x] += _size[y];
	return f[x];
}
void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa != pb) {
		f[pb] = pa;
		_size[pa] += _size[pb];
	}
}
int main() {
	//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		int m;
		map<int, int> mp;
		cin >> m;
		init(30);
		string str;
		for (int i = 0; i < m; i++) {
			cin >> str;
			merge(str[0] - 'a', str[str.size() - 1] - 'a');
			in[str[str.size() - 1] - 'a']++;
			out[str[0] - 'a']++;
			mp[str[str.size() - 1] - 'a']++;
			mp[str[0] - 'a']++;
		}
		int sum1 = 0, sum2 = 0;
		bool flag = false;
		if (_size[find(str[0] - 'a')] == mp.size()) {// mp.size()是输入的点数  判断是否联通  并查集可以判断 有向图是否为 连通图，不能判断是否为强连通图
			for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
				if (in[it->first] != out[it->first]) {
					if (in[it->first] == out[it->first] + 1) {
						sum1++;
					}
					else if (in[it->first] + 1 == out[it->first]) {
						sum2++;
					}
					else {
						flag = true;
						break;
					}
				}
			}
			if (flag || sum1>1 || sum2>1) cout << "The door cannot be opened." << endl;
			else cout << "Ordering is possible." << endl;
		}
		else {
			cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}