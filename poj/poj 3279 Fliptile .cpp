/*
Fliptile （POJ No.3279）
农夫约翰知道聪明的牛产奶多。于是为了提高牛的智商他准备了如下游戏。有一个 M×N的
格子，每个格子可以翻转正反面，它们一面是黑色，另一面是白色。黑色的格子翻转后就是
白色，白色的格子翻转过来则是黑色。游戏要做的就是把所有的格子都翻转成白色。不过因
为牛蹄很大，所以每次翻转一个格子时，与它上下左右相邻接的格子也会被翻转。因为翻格
子太麻烦了，所以牛都想通过尽可能少的次数把所有格子都翻成白色。现在给定了每个格子
的颜色，请求出用最小步数完成时每个格子翻转的次数。最小步数的解有多个时，输出字典
序最小的一组。解不存在的话，则输出 IMPOSSIBLE。
输入
M = 4
N = 4
每个格子的颜色如下(0表示白色，1表示黑色)
4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1
输出
0 0 0 0
1 0 0 1
1 0 0 1
0 0 0 0

1<=m,n<=15
*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX_N 20
#define MAX_M 20
// 邻接的格子的坐标
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};
// 输入
int M, N;
int tile[MAX_M][MAX_N];
int opt[MAX_M][MAX_N]; // 保存最优解
int flip[MAX_M][MAX_N]; // 保存中间结果
// 查询(x,y)的颜色
int get(int x, int y) 
{
	int c = tile[x][y];
	for (int d = 0; d < 5; d++) 
	{
		int x2 = x + dx[d], y2 = y + dy[d];
		if (0 <= x2 && x2 < M && 0 <= y2 && y2 < N) 
		{
			c += flip[x2][y2];
		}
	}
	return c % 2;
}
// 求出第1行确定情况下的最小操作次数
// 不存在解的话返回-1
int calc() 
{
// 求出从第2行开始的翻转方法
	for (int i = 1; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (get(i - 1, j) != 0) 
			{
// (i-1,j)是黑色的话，则必须翻转这个格子
				flip[i][j] = 1;
			}
		}
	}
// 判断最后一行是否全白
	for (int j = 0; j < N; j++) 
	{
		if (get(M - 1, j) != 0) 
		{
// 无解
			return -1;
		}
	}
// 统计翻转的次数
	int res = 0;
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			res += flip[i][j];
		}
	}
	return res;
}
void solve() 
{
	int res = -1;
	// 按照字典序尝试第一行的所有可能性
	for (int i = 0; i < 1 << N; i++) 
	{
		memset(flip, 0, sizeof(flip));
		for (int j = 0; j < N; j++) 
		{
			flip[0][N - j - 1] = i >> j & 1;
		}
		int num = calc();
		if (num >= 0 && (res < 0 || res > num)) 
		{
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}
	if (res < 0) 
	{
// 无解
		printf("IMPOSSIBLE\n");
	} 
	else 
	{
		for (int i = 0; i < M; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
			}
		}
	}
}
int main()  
{   
    while(cin>>M>>N)  
    {  
        for(int i=0; i<M; i++)  
            for(int j=0; j<N; j++)  
                cin>>tile[i][j];  
        solve();  
    }  
    return 0;  
}  
