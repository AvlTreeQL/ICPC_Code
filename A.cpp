/*************************************************************************
	> File Name: A.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 17时54分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    string str;
    int num = 0;
    while(cin >> str) {
        int a = 0, b = 0;
        for(int i = 0; i < str.size(); i++) {
            a = (a * 10 + str[i] - '0') % 73;
            b = (b * 10 + str[i] - '0') % 137;
        }
        if(a == 0 && b == 0) {
            cout << "Case #" << ++num << ": YES" << endl;
        } else {
            cout << "Case #" << ++num << ": NO" << endl;
        }
    }
    return 0;
}
