/*
花椰菜君给了蒜头君 n 个单词，如果一个单词的最后一个字母和另一个单词的第一个字母相同，那么两个单词就可以连接在一起组成一个新的单词。
现在花椰菜君想要蒜头君计算一下，给定的 n 个单词是否可以全部连接在一起。

输入格式

第一行输入一个整数 n，代表一共有 n 个单词（1≤n≤100,000）。

接下来输入 n 行，每行输入一个单词。单词均由小写字母组成，每个单词长度不超过 2020。

输出格式

输出一行，如果所有的单词都可以连接在一起并且可以形成一个环，那么输出Euler loop；
如果所有单词都可以连接在一起，但是不会形成环，输出Euler path；如果所有单词不能连在一起，那么输出impossible。

样例输入

3
euler
ruby
jisuanke
样例输出

Euler path
*/
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
		if (!flag) {
			if (!sum1 && !sum2) cout << "Euler loop" << endl;
			else if (sum1 == 1 && sum2 == 1) cout << "Euler path" << endl;
			else cout << "impossible" << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}
	else {
		cout << "impossible" << endl;
	}
		
	
	return 0;
}