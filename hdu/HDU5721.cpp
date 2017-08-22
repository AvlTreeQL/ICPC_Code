#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
class Node {
public:
	int first, second, id;
	Node(){ }
	Node(int x, int y,int z) {
		first = x;
		second = y;
		id = z;
	}
	bool operator < (const Node &b)const {
		return first < b.first;
	}
};
vector<Node > v;
int ans = 0;

int dis(Node a, Node b) {
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
bool cmp(Node &a, Node &b) {
	return a.second < b.second;
}
Node p1, p2;
int closeDis(int l, int r,int p) {
	int d = 1e20;
	if (l == r) {
		return d;
	}
	if (l + 1 == r) {
		int temp = dis(v[l], v[r]);
		if (p == 0 && temp < ans) {
				p1 = v[l];
				p2 = v[r];
				ans = tmp2;
			}
		}
		return tmp2;
		
	}
	int mid = (l + r) / 2;
	int a = closeDis(l, mid,p);
	int b = closeDis(mid + 1, r,p);
	d = min(a, b);
	vector<Node > vt;
	for (int i = l; i <= r; i++) {
		if (fabs(v[i].first - v[mid].first) <= d) {
			vt.push_back(v[i]);
		}
	}
	sort(vt.begin(), vt.end(),cmp);
	for (int i = 0; i < vt.size(); i++) {
		for (int j = i + 1; j < vt.size() && (vt[j].second - vt[i].second) < d; j++) {
			int temp = dis(vt[j], vt[i]);
			if (temp < d) {
				d = temp;
			}
		}
	}
	return d;
}
int main() {
	freopen("input.txt", "r", stdin);
	int num;
	scanf("%d", &num);
	while (num--) {
		int n;
		
		scanf("%d", &n);
		if (n == 0)break;
		int x, y;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			v.push_back(Node(x, y,i));
		}
		
		printf("%d\n", closeDis(0, n - 1,-1));
		v.clear();
	}
	

	return 0;
}
