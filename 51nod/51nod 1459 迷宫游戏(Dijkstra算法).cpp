#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e9;
int v[510][510] = { 0 };
int sc[510];
bool visit[510];
int cost[510];
int ss[510];
int n, m, s, e;
void dijkstra() {
	for (int i = 0; i < n; i++) {
		cost[i] = v[s][i];
		ss[i] = sc[i] + sc[s];
		//		ss[i] = sc[i];  这样写，在输出时加上 ss[e]是错误的，因为 开始位置和结束位置可能一样
	}
	ss[s] -= sc[s];
	visit[s] = true;
	for (int i = 1; i < n; i++) {
		int min = maxn, index = -1, ssc = -1;
		for (int j = 0; j < n; j++) {
			if (!visit[j]) {
				if (cost[j] < min || cost[j] == min&&ss[j]>ssc) {
					index = j;
					min = cost[j];
					ssc = ss[j];
				}
			}
		}
		if (index != -1)visit[index] = true;
		else break;
		for (int j = 0; j < n; j++) {
			if (!visit[j]) {
				if (min + v[index][j] < cost[j]) {
					cost[j] = min + v[index][j];
					ss[j] = ssc + sc[j];
				}
				else if (min + v[index][j] == cost[j] && ssc + sc[j] > ss[j]) {
					ss[j] = ssc + sc[j];
				}
			}
		}
	}
}
int main() {
	//	freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j)v[i][j] = maxn;
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &sc[i]);
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v[a][b] = v[b][a] = c;
	}
	dijkstra();
	printf("%d %d\n", cost[e], ss[e]);
	return 0;
}