/*************************************************************************
	> File Name: text.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 16时33分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        if(x&1) cout << x / 2 + 2 << endl;
        else cout << x / 2 + 1 << endl; 
    }
    return 0;
}
