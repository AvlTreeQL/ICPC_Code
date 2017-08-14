/*************************************************************************
	> File Name: 放苹果.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月08日 星期二 07时48分12秒
 ************************************************************************/

#include <iostream>
using namespace std;
int dp[100][100] = {0};
int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    for(int i = 0; i< 15; i++){
        for(int j = 0; j < 15; j++){
            if(i == 0 || j == 1){
                dp[i][j] = 1;
            }else if(i < j) {
                dp[i][j] = dp[i][i];
            }else {
                dp[i][j] = dp[i][j-1] + dp[i-j][j];
            }

        }
    }
    int i, k, t;
    cin >> t;
    while(t--){
        cin >> i >> k;
        cout << dp[i][k] << endl;
    }
    return 0;
}
