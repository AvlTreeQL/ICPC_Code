/*************************************************************************
	> File Name: POJ1182_食物链_带权并查集.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月04日 星期一 14时05分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int f[2010], r[2010];// r[i] == 0  i和父节点同类， r[i] == 1 i吃父节点 ，r[i] == 2 i被父节点吃
int n, m;
void init(int n)
{
    for(int i = 0; i <= n; i++) {
        f[i] = i;
        r[i] = 0;
    }
}
int find(int x)
{
    if(f[x] == x) {
        return x;
    }
    int y = f[x];
    f[x] = find(y);
    if(r[x] == 0 && r[y] == 0) {
        r[x] = 0;
    } else if(r[x] == 0 && r[y] == 1) {
        r[x] = 1;
    } else if(r[x] == 0 && r[y] == 2) {
        r[x] = 2;
    } else if(r[x] == 1 && r[y] == 0) {
        r[x] = 1;
    } else if(r[x] == 1 && r[y] == 1) {
        r[x] = 2;
    } else if(r[x] == 1 && r[y] == 2) {
        r[x] = 0;
    } else if(r[x] == 2 && r[y] == 0) {
        r[x] = 2;
    } else if(r[x] == 2 && r[y] == 1) {
        r[x] = 0;
    } else if(r[x] == 2 && r[y] == 2) {
        r[x] = 1;
    }
    return f[x];
}
bool merge(int w, int a, int b)
{
    if(a == b || a > n || b > n) return false;
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) {
        if(w == 1 && r[a] != r[b]) {
            return false;
        }
        if(w == 2) {
            if(r[a] == 0 && r[b] != 2) {
                return false;
            }
            if(r[a] == 1 && r[b] != 0) {
                return false;
            }
            if(r[a] == 2 && r[b] != 1) {
                return false;
            }
        }
        return true;
    }
    f[pb] = pa;
    r[pb] = (r[b] - r[a] + w + 4) % 3 ;
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    init(n);
    int w, a, b;
    int ans = 0;
    while(m--) {
        cin >> w >> a >> b;
        if(!merge(w, a, b)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
