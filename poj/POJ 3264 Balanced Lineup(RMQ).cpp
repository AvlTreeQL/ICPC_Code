#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int dp_max[50010][20] = { 0 };
int dp_min[50010][20] = { 0 };
int n, q;
void rmq() {
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
			dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &dp_max[i][0]);
		dp_min[i][0] = dp_max[i][0];
	}
	rmq();
	int l, r, k;
	while (q--) {
		scanf("%d%d", &l, &r);
		l--, r--;
		k = log(r - l + 1) / log(2);
		printf("%d\n", max(dp_max[l][k], dp_max[r-(1<<k)+1][k]) - min(dp_min[l][k], dp_min[r - (1 << k) + 1][k]));
	}
	

	return 0;
}