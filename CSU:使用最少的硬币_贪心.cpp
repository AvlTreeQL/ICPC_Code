/*************************************************************************
	> File Name: CSU:使用最少的硬币_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 21时57分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int a[4], s;
    int v[4] = {5, 10, 20, 50};
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> s) {
        int ans = 0;
        int b[4] = {0};
        for(int i = 3; i >= 0; i--) {
            b[i] = min(s / v[i], a[i]);
            s -= b[i] * v[i];
            ans += b[i];
        }
        if(!s) cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
