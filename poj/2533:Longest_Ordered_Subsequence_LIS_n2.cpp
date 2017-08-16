/*************************************************************************
	> File Name: 2533:Longest_Ordered_Subsequence_LIS(n2).cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月13日 星期日 16时47分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e9;
int main(){
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int dp[n];
        int ans = -maxn;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(a[j] < a[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
