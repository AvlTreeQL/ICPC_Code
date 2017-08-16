/*************************************************************************
	> File Name: K.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 17时13分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        int dp[26]={0},ans=0;
        for(int j = 0; j<str.size() ; j++) {
            if (!dp[str[j] - 'a']){
                ans++;
                dp[str[j] - 'a'] = 1;
            } 
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
