#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1e5;
int prime[maxn];
bool visit[maxn];//如果不是素数，为true
void check() {
	int t = 0;
	for (int i = 2; i < maxn; i++) {
		if (!visit[i]) {
			prime[t++] = i;
		}
		for (int j = 0; j < t&&i*prime[j] < maxn; j++) {
			visit[i*prime[j]] = true;
			if (i%prime[j] == 0) break;// i和prime[j] 是某个合数的两个因数，i>prime[j] ,所以这个合数已经被 小的因数（prime[j]）筛选过了
		}

	}
}
int main() {
//	freopen("input.txt", "r", stdin);
	int n, temp, num = 0;
	check();
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &temp);
		if (!visit[temp]) {
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}