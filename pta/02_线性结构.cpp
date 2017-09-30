#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
class node {
public:
	int data;
	int next;
	node() {}
	node(int a, int b) {
		data = a;
		next = b;
	}
};
int main() {
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int s, n, t;
	cin >> s >> n >> t;
	int a, b, c;
	map<int, node> mp;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		mp[a] = node(b, c);
	}
	int _index[100];
	int i = 0;
	while (s != -1) {
		_index[i++] = s;
		s = mp[s].next;
	}
	for (int i = 0; i + t - 1< n; i += t) {
		for (int j = i, k = i + t - 1; j < k; j++, k--) {
			swap(_index[j], _index[k]);
		}
	}
	for (i = 0; i < n - 1; i++) {
		cout <<setw(5)<<setfill('0')<< _index[i] << " " << mp[_index[i]].data << " " << _index[i + 1] << endl;
	}
	cout << setw(5) << setfill('0') << _index[n - 1] << " " << mp[_index[n - 1]].data << " " << -1 << endl;
	return 0;
}