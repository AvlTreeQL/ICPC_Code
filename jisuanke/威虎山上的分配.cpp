/*
每年过年的时候，座山雕都会给兄弟们分银子，分银子之前，座山雕允许大伙儿发表意见，因为要是没法满足所有人的意见，
指不定谁要搞出什么大新闻。不过每个人在提意见的时候只能说：“我认为 A 分的银子应该比 B 多！”。
座山雕决定要找出一种分配方案，满足所有人的意见，同时使得所有人分得的银子总数最少，并且每个人分得的银子最少为 100100 两。

输入格式

第一行两个整数 n,m  (0<n≤10000,0<m≤20000)，表示总人数和总意见数；

以下 m 行，每行两个整数 a,b，之间用一个空格隔开，表示某个意见认为第 a 号小弟所分得的银两应该比第 b 号小弟多，所有小弟的编号由 1 开始。

输出格式

若无法找到合法方案，则输出Unhappy!(不包含引号)，否则输出一个数表示最少总银两数。

样例输入

3 2
1 2
2 3
样例输出

303
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
const int maxn = 10010;
int n, m;
vector<vector<int> > G;
int in[maxn] = { 0 };
long long sum = 0;
int base = 100;
int num = 0;
void topo() {
	queue<P> que;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			que.push(P(i,100));
		}
	}
	while (!que.empty()) {
		num++;
		P now = que.front();
		que.pop();
		sum += now.second;
		for (int i = 0; i < G[now.first].size(); i++) {
			in[G[now.first][i]]--;
			if (!in[G[now.first][i]]) {
				que.push(P(G[now.first][i],now.second+1));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	G.resize(n+1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		G[b].push_back(a);
		in[a]++;
	}
	topo();
	if (num < n) {//出现环
		cout << "Unhappy!" << endl;
		
	}
	else {
		cout << sum << endl;
	}
	return 0;
}