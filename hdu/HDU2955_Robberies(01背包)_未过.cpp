#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int num;
	scanf("%d", &num);
	while (num--) {
		double sum;
		int W=0,N;
		scanf("%lf%d", &sum,&N);
		int w[110] = { 0 };
		double xx[110] = { 0 };
		double dp[1100] = { 0 };
		for (int i = 0; i < N; i++) {
			scanf("%d%lf", &w[i],&xx[i]);
			W += w[i];
		}
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = W; j >= w[i]; j--) {
				dp[j] = max(dp[j], dp[j - w[i]] * (1 - xx[i]));
			}
		}
		for (int i = W; i >= 0; i--)
		{
			if (dp[i] >= (1 - sum))
			{
				printf("%d\n", i);
				break;
			}
		}
	//	printf("%d\n", dp[W]);
	}
	

	return 0;
}
