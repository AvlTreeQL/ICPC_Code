/*************************************************************************
> File Name: POJ2236_Wireless_Nerwork_并查集.cpp
> Author: heheql
> Mail: 374655767@qq.com
> Created Time: 2017年09月03日 星期日 13时40分20秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> P;
int f[1010], _size[1010], dis[1010], vis[1010];
int n;
double dist(P a, P b) {
	double ans = sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
	return ans;
}
void init(int n) {
	for (int i = 1; i <= n; i++) {
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
int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int d;
	cin >> n >> d;
	init(n);
	vector<P> vec;
	vec.push_back(P(0, 0));
	for (int i = 0; i < n; i++) {
		P temp;
		cin >> temp.first >> temp.second;
		vec.push_back(temp);
	}
	char c;
	while (cin >> c) {
		if (c == 'O') {
			int a;
			cin >> a;
			vis[a] = true;
			for (int i = 1; i <= vec.size(); i++) {
				if (vis[i] && dist(vec[a], vec[i]) <= d) {
					merge(a, i);
				}
			}
		}
		else if (c == 'S') {
			int a, b;
			cin >> a >> b;
			a = find(a);
			b = find(b);
			if (a == b) {
				cout << "SUCCESS" << endl;
			}
			else {
				cout << "FAIL" << endl;
			}
		}
	}
	return 0;
}