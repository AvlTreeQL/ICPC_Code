/*
Face The Right Way （POJ No. 3276）
N 头牛排成了一列。每头牛或者向前或者向后。为了让所有的牛都面向前方，农夫约翰买了
一台自动转向的机器。这个机器在购买时就必须设定一个数值 K，机器每操作一次恰好使 K
头连续的牛转向。请求出为了让所有的牛都能面向前方需要的最少的操作次数 M 和对应的
最小的 K。
输入
N = 7
BBFBFBB (F：面向前方，B：面向后方)
输出
K = 3
M = 3
（先反转1~3号的三头牛，然后再反转3~5号，最后反转5~7号）
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX_N 20
using namespace std;
// 输入
int N;
int dir[MAX_N]; // 牛的方向(0:F, 1:B)
int f[MAX_N]; // 区间[i,i+K-1]是否进行反转
// 固定K，求对应的最小操作回数
// 无解的话则返回-1
int calc(int K) 
{
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0; // f的和
	for (int i = 0; i + K <= N; i++)
	{
	// 计算区间[i,i+K-1]
		if ((dir[i] + sum) % 2 != 0) 
		{
			// 前端的牛面朝后方
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - K + 1 >= 0) 
		{
			sum -= f[i - K + 1];
		}
	}
	// 检查剩下的牛是否有面朝后方的情况
	for (int i = N - K + 1; i < N; i++) 
	{
		if ((dir[i] + sum) % 2 != 0) 
		{
			// 无解
			return -1;
		}
		if (i - K + 1 >= 0) 
		{
			sum -= f[i - K + 1];
		}
	}
	return res;
}
void solve() 
{
	int K = 1, M = N;
	for (int k = 1; k <= N; k++) 
	{
		int m = calc(k);
		if (m >= 0 && M > m) 
		{
			M = m;
			K = k;
		}
	}
	printf("%d %d\n", K, M);
}
int main()
{
	char c;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>c;
		dir[i]=c=='B'?1:0;
	}
	solve();
	return 0;
}
