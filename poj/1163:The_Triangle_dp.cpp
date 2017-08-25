/*************************************************************************
	> File Name: 1163:The_Triangle_dp.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月25日 星期五 10时04分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 1e9;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    vector<vector<int> > dp;
    dp.resize(101);
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> temp;
            dp[i].push_back(temp);
        }
    }
    for(int i = 1; i < n; i++){
        dp[i][0] += dp[i-1][0];
        dp[i][i] += dp[i-1][i-1];
    }
    for(int i = 2; i < n; i++){
        for(int j = 1; j < i; j++){
            dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    int ans = -inf;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}
