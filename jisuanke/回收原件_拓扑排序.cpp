#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
const int maxn = 6010;
class node {
public:
	int x1, y1;
	int x2, y2;
	int num;
	bool operator<(const node& b) {
		if (x1< b.x1) {
			return true;
		}
		else {
			return false;
		}
	}
};
int n;
vector<int> G[maxn];
node p[maxn];
int in[maxn];
vector<int> path;
double dis(node a, node b) {
	double x1 = b.x1 - a.x1;
	double x2 = a.x2 - a.x1;
	double y2 = a.y2 - a.y1;
	if (fabs(x1 - x2) < 0.001) {
		return a.y1 + a.y2 - a.y1;
	}
	return a.y1 + y2*x1 / x2;
}
void topo() {
	queue<int> que;
	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int now = que.front();
		path.push_back(now);
		que.pop();
		for (int i = 0; i < G[now].size(); i++) {
			in[G[now][i]]--;
			if (!in[G[now][i]]) {
				que.push(G[now][i]);
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	memset(in, 0, sizeof(in));
	cin >> n;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		p[i].x1 = x1;
		p[i].x2 = x2;
		p[i].y1 = y1;
		p[i].y2 = y2;
		p[i].num = i;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i].x2 >= p[j].x1) {
				double temp = dis(p[i], p[j]);
				if (p[j].y1 > temp) {
					G[p[i].num].push_back(p[j].num);
					in[p[j].num]++;
				}
				else {
					G[p[j].num].push_back(p[i].num);
					in[p[i].num]++;
				}
			}
			else {
				break;
			}
		}
	}
	topo();
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] + 1 << " ";
	}
	return 0;
}