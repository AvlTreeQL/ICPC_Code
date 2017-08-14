/*************************************************************************
	> File Name: 1049:最大子段和.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月13日 星期日 17时23分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long dp[n+1] = {0}, ans = -1;
    int temp;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        if(dp[i-1] + temp >= 0) dp[i] = dp[i-1] + temp;
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}
