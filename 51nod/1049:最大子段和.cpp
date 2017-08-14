/*************************************************************************
	> File Name: 1049:最大子段和.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月13日 星期日 17时46分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n, temp;
    cin >> n;
    int len = 1;
    long long dp[n+1] = {0};
    cin >> dp[1];
    while(--n){
        cin >> temp;
        if(temp >= dp[len]) dp[++len] = temp;
        else *lower_bound(dp+1,dp+len,temp) = temp;
    }
    cout << len << endl;
    return 0;
}
