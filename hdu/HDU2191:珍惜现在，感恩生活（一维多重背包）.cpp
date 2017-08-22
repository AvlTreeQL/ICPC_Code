/*
题目描述：
为了挽救灾区同胞的生命，心系灾区同胞的你准备自己采购一些粮食支援灾区，
现在假设你一共有资金n元，而市场有m种大米，
每种大米都是袋装产品，其价格不等，并且只能整袋购买。
请问：你用有限的资金最多能采购多少公斤粮食呢？
输入：
输入数据首先包含一个正整数C，表示有C组测试用例
，每组测试用例的第一行是两个整数n和m(1<=n<=100, 1<=m<=100),分别表示经费的金额和大米的种类，
然后是m行数据，每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的价格、每袋的重量以及对应种类大米的袋数。
输出：
对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例的输出占一行。
样例输入：
1
8 2
2 100 4
4 100 2
样例输出：
400
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int  C;
	scanf("%d", &C);
	while (C--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int p[110] = { 0 };
		int w[110] = { 0 };
		int num[110] = { 0 };
		int dp[1100] = { 0 };
		for (int i=1; i <= m; i++) {
			scanf("%d%d%d", &p[i], &w[i], &num[i]);
		}
		for (int i = 1; i <= m; i++) {//种类 物品种类  m是种类总数
			for (int k = 1; k <= num[i]; k++) {//k 每种物品的数量
				for (int j = n ; j >= p[i]; j--) {//金额  体积 n是总体积
						dp[j] = max(dp[j], dp[j - p[i]] + w[i]);
					}
			}
		}
		printf("%d\n", dp[n]);
	}
	

	return 0;
}