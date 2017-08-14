#include<cstdio>
#include<iostream>
#include<algorithm>
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
using namespace std;
const int maxn = 250000 + 7;
const int mod = 1e9 + 7;
const int minn = -1e9;
int sum[8 * maxn];
int c[maxn];
int b[maxn];
int t = 1;
int n;
void build(int l, int r, int rt) {
	if (l == r) {
		if (r <= n)
		{
			scanf("%d", &c[t]);
			sum[rt] = c[t] - t;
			t++;
		}
		else {
			sum[rt] = minn;
		}
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	sum[rt] = max(sum[rt * 2], sum[rt * 2 + 1]);
}
int query(int s, int e, int l, int r, int rt) {
	if (s <= l&&r <= e) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = minn;
	if (s <= m)  ret = max(ret, query(s, e, lson));
	if (m < e)  ret = max(ret, query(s, e, rson));
	return ret;
}
void add(int i, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = val;
		return;
	}
	int m = (l + r) >> 1;
	if (i <= m) add(i, val, lson);
	else add(i, val, rson);
	sum[rt] = max(sum[rt * 2], sum[rt * 2 + 1]);
}
int main() {
	//    freopen("input.txt", "r", stdin);
	while (~scanf("%d", &n)) {
		//        build(1, 2 * n, 1);
		int temp;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);
			add(i, temp - i, 1, 2 * n, 1);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		sort(b, b + n);
		int x = 0;
		int ans = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			int temp = query(b[x++], i - 1, 1, 2 * n, 1);
			add(i, temp - i, 1, 2 * n, 1);
			ans = (ans + temp) % mod;
			//            ans += temp;
		}
		printf("%d\n", ans);

	}
	return 0;
}