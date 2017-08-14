/*************************************************************************
	> File Name: 2533:Longest Ordered Subsequence(LIS).cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月11日 星期五 20时24分02秒
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int dp[n+1];//记得+1 因为从1开始
        int len = 1, temp;
        cin >> dp[1];
        while(--n){
            cin >> temp;
            if(temp > dp[len]){
                dp[++len] = temp;
            }else{
                *lower_bound(dp+1,dp+len,temp) = temp;
            }
        }
        cout << len << endl;
    }
    return 0;
}
