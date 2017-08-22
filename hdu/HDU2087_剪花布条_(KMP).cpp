/*
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
Input
输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。
Output
输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就老老实实输出0，每个结果之间应换行。
Sample Input
abcde a3
aaaaaa  aa
#
Sample Output
0
3
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 1e3 + 10;
void getNext(string p, int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < p.length()) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int kmp(string S, string P, int next[]) {
	getNext(P, next);
	int i = 0, j = 0, cnt = 0;
	while (i < S.length()) {
		if (j == -1 || S[i] == P[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
		if (j == P.length()) {
			j = 0;
			cnt++;
		}
	}

	return cnt;
}
int main() {
//	freopen("input.txt", "r", stdin);
	while (true) {
		string a, b;
		cin >> a;
		if (a[0] == '#') break;
		cin >> b;
		int next[maxn];

		printf("%d\n", kmp(a, b, next));

	}
	return 0;
}