/*
你学过一笔画问题么？其实一笔画问题又叫欧拉回路，是指在画的过程中，笔不离开纸，且图中每条边仅画一次，而且可以回到起点的一条回路。

蒜头君打算考考你，给你一个图，问是否存在欧拉回路？

输入格式

第 1 行输入两个正整数，分别是节点数 N(1<N<1000) 和边数 M(1<M<100000)；

紧接着 M 行对应 M 条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（节点从 1 到 N 编号）。

输出格式

若存在欧拉回路则输出 11，否则输出 00。

样例输入

10 11
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 3
3 1
样例输出

1
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m;
int f[maxn],_size[maxn],in[maxn];
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
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	init(n);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
		in[a]++;
		in[b]++;
	}								//并查集貌似只能判断是否能构成 欧拉回路，或欧拉路，不能输出路径 ？？？？？
	if (_size[find(a)]==n) {		//判断是否为连通图（所有的点在一个集合里面）  这是无向图的判断方法 
		int i;
		for (i = 1; i <= n; i++) {
			if (in[i] & 1) {		//如果有度数为奇数的点，肯定不能构成欧拉回路
				cout << 0 << endl;	//这里如果统计 奇数度数 的点个数，  个数为二 则可以形成欧拉路，个数为0则可以形成欧拉回路
				break;				
			}
		}
		if (i > n) {
			cout << 1 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}