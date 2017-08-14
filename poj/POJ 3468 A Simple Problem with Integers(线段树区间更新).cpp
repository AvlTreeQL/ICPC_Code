#include <iostream>
#include <cstdio>
#define lson l, m, rt * 2
#define rson m+1, r, rt * 2 + 1
using namespace std;
const long long maxn = 1e5 + 10;
long long lazy[maxn<<2] = { 0 };
long long sum[maxn<<2] = { 0 };
void pushDown(long long rt, long long m) {
	lazy[rt * 2] += lazy[rt];
	lazy[rt * 2 + 1] += lazy[rt];
	sum[rt * 2] += lazy[rt] * (m - m / 2);
	sum[rt * 2 + 1] += lazy[rt] * (m / 2);
	lazy[rt] = 0;
}
void build(long long l, long long r, long long rt) {
	if (l == r) {
		scanf("%lld", &sum[rt]);
		return;
	}
	long long m = (l + r) / 2;
	build(lson);
	build(rson);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
long long query(long long L, long long R, long long l, long long r, long long rt) {
	if (L <= l&&r <= R) {
		return sum[rt];
	}
	if (lazy[rt]) pushDown(rt, r - l + 1);
	long long m = (l + r) / 2;
	long long ans = 0;
	if (L <= m) ans += query(L, R, lson);
	if (m < R) ans += query(L, R, rson);
	return ans;

}

void updata(long long L, long long R, long long val, long long l, long long r, long long rt) {
	if (L <= l&&r <= R) {
		lazy[rt] += val;
		sum[rt] += val*(r - l + 1);
		return;
	}
	if (lazy[rt]) pushDown(rt, r - l + 1);
	long long m = (l + r) / 2;
	if (L <= m)updata(L, R, val, lson);
	if (m < R)updata(L, R, val, rson);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
int main() {
//	freopen("input.txt", "r", stdin);
	long long n, num;
	scanf("%lld%lld", &n, &num);
	build(1, n, 1);
	while (num--) {
		char c='a';
		long long l, r, val;
		getchar();
		scanf("%c", &c);
		if (c == 'Q') {
			scanf("%lld%lld", &l, &r);
			printf("%lld\n", query(l, r, 1, n, 1));
		}
		else {
			scanf("%lld%lld%lld", &l, &r, &val);
			updata(l, r, val, 1, n, 1);
		}
	}
	return 0;
}