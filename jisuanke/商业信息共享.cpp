/*************************************************************************
	> File Name: 商业信息共享.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月11日 星期一 10时26分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1000;
int in[maxn], out[maxn], belong[maxn], dfn[maxn], low[maxn], scc, _index;
bool in_stack[maxn];
stack<int> stk;
vector<vector<int> > G;
void init()
{
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(belong, 0, sizeof(belong));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(in_stack, false, sizeof(in_stack));
    scc = 0;
    _index = 0;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++_index;
    stk.push(u);
    in_stack[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        ++scc;
        int x;
        do {
            x = stk.top();
            belong[x] = scc;
            in_stack[x] = false;
            stk.pop();
        } while(x != u);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    init();
    int n;
    cin >> n;
    G.resize(n+1);
    for(int i = 1; i <= n; i++) {
        int k;
        while(true) {
            cin >> k;
            if(!k) break;
            G[i].push_back(k);
        }

    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            int v = G[i][j];
            if(belong[i] != belong[v]) {
                out[belong[i]]++;
                in[belong[v]]++;
            }
        }
    }
    int a = 0, b = 0;
    for(int i = 1; i <= scc; i++) {
        if(!in[i]) a++;
        if(!out[i]) b++;
    }
    if(scc == 1) {
        cout << 1 << endl;
        cout << 0 << endl;
    } else {
        cout << a << endl;
        cout << max(a, b) << endl;
    }
    return 0;
}
