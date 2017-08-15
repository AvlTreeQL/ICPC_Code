/*************************************************************************
	> File Name: 2386:Lake_Countring_dfs.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 20时23分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int dir[][2] = { -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
char grap[110][110];
int n, m;
bool check(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if(grap[x][y] == 'W') return true;
    else return false;
}
void dfs(int x, int y)
{
    grap[x][y] = '.';
    for(int i = 0; i < 8; i++) {
        int a = x + dir[i][0], b = y + dir[i][1];
        if(check(a, b)) dfs(a, b);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grap[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grap[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
