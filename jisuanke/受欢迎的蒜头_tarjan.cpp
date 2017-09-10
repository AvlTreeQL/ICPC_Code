/*************************************************************************
	> File Name: 受欢迎的蒜头_tarjan.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月10日 星期日 21时57分18秒
蒜厂除了蒜头君还有很多小蒜头。

每只蒜头的梦想是成为最受欢迎的蒜头。有 N 只蒜头，有 M 对二元关系 (A,B)，告诉你蒜头 A 认为蒜头 B 是受欢迎的。如果 A 认为 B 是受欢迎的，B 认为 C 是受欢迎的，则 A 也认为 C 是受欢迎的。你的任务是计算被其余蒜头都认为是受欢迎的蒜头数量。

输入格式

第一行两个正整数 N 和 M，分别表示一共有 N 只小蒜头和 M 对二元关系 (1≤N≤10000,1≤M≤50000)。

接下来 M 行，每行两个整数 A 和 B，表示 A 认为 B 是受欢迎的 (1≤A,B≤N)。

输出格式

一行一个整数，表示答案。

样例输入

4 6
1 2
1 3
1 4
2 3
2 4
3 4
样例输出

1
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e4 + 10;
int dfn[maxn], low[maxn], _index, scc, belong[maxn], size[maxn], out[maxn];
bool in_stack[maxn];
stack<int> stk;
vector<vector<int> > G;
void tarjan(int u)
{
    dfn[u] = low[u] = ++_index;
    stk.push(u);
    in_stack[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scc++;
        int x;
        do {
            x = stk.top();
            belong[x] = scc;
            in_stack[x] = false;;
            stk.pop();
            size[scc]++;
        } while (x != u);
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    G.resize(n + 1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    scc = 0;
    _index = 0;
    memset(in_stack, false, sizeof(in_stack));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(size, 0, sizeof(size));
    memset(out, 0, sizeof(out));
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            if(belong[i] != belong[G[i][j]]) {
                out[belong[i]]++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= scc; i++) {
        if(!out[i]) {
            if(ans == 0) ans = size[i];
            else {
                ans = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

