/*************************************************************************
	> File Name: 1134:最长递增子序列_dp_n2.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月13日 星期日 17时51分51秒
    TLE TLE TLE TLE
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long dp[n], ans = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}
