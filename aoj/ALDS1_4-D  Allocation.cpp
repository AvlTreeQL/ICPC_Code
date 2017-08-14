/*
n的物品 安装顺序 放入 k 辆卡车，每辆卡车的最大载重为 p;
每个物品的 重量分别为 wi
输入第一行两个数 n k
随后n行为 物品的重量
输出最小的载重p 
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
ll T[maxn];
int check(ll p) {
	int i = 0;
	for (int j = 0; j < k; j++) {
		ll s = 0;
		while (s + T[i] <= p) {
			s += T[i];
			i++;
			if (i == n)return n;
		}
	}
	return i;
}
int solve() {
	ll left = 0;
	ll right = 100000 * 10000;
	ll mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		int v = check(mid);
		if (v >= n)right = mid;
		else left = mid;
	}
	return right;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &T[i]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	}
	ll ans = solve();
	printf("%lld\n", ans);
	return 0;
}