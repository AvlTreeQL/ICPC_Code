/*************************************************************************
	> File Name: 1006:最长公共子序列_LCS_DP.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月25日 星期五 11时52分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int dp[a.size() + 1][b.size() + 1], ans = 0;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
