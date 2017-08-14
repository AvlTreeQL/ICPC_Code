/*************************************************************************
	> File Name: 1003.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月06日 星期日 17时31分18秒
 ************************************************************************/

#include <iostream>
using namespace std;
const int maxn = 1e9;
int main(){
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        int a[n], b[n];
        int k[m], p[m];
        int maxhp = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            maxhp = max(a[i], maxhp);
        }
        for(int i = 0; i < m; i++){
            cin >> k[i] >> p[i];
        }
        int dp[1010][1010] = {0};
        for(int i = 0; i <= 10; i++){
            for(int j = 0; j <= maxhp; j++){
                dp[j][i] = maxn;
                for(int kk = 0; kk < m; kk++){
                    int temp =  p[kk] - i;
                    if(temp <= 0){
                        continue;
                    }
                    if(temp < j){
                        dp[j][i] = min(dp[j - temp][i] + k[kk], dp[j][i]);
                    }else {
                        dp[j][i] = min(dp[j][i], k[kk]);
                    }
                }
            }
        }
    }
	return 0;
}
