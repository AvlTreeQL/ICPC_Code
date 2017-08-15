/*************************************************************************
	> File Name: 1852:Ants.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 22时40分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T, l, n, temp;
    cin >> T;
    while(T--) {
        cin >> l >> n;
        int maxx = -1,minn = -1;
        for(int i = 0; i < n; i++){
            cin >> temp;
            maxx = max(maxx,max(temp,l-temp));
            minn = max(minn,min(temp,l-temp));
        }
        cout << minn << " " << maxx << endl; 
    }
    return 0;
}
