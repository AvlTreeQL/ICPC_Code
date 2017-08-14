/*************************************************************************
	> File Name: 放苹果.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月08日 星期二 07时48分12秒
 ************************************************************************/

#include <iostream>
using namespace std;
int dp[100][100] = {0};
int dfs(int i, int k){
    if(i == 0 || k == 1){
        return 1;
    }
    if(dp[i][k]){
        return dp[i][k];
    }
    if(i < k) return dp[i][k] = dfs(i,i);
    else return dp[i][k] = dfs(i,k-1) + dfs(i-k,k);
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int i, k, t;
    cin >> t;
    while(t--){
        cin >> i >> k;
        cout << dfs(i,k) << endl;
    }
    return 0;
}
