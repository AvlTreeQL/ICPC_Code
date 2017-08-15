/*************************************************************************
	> File Name: text1.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 11时57分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e8 + 10;
int a[maxn] = {0};

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T,maxx=0;
    cin >> T;
    int b[T];
    for(int i = 0; i < T; i++){
        cin >> b[i];
        maxx = max(maxx,b[i]);
    }
    long sum = 0;
    a[1] = 1;
    int tt;
    for(int i = 1; i <= maxx; i++) {
        sum += a[i];
      //  if(i&1) tt = -1;
      //  else tt = 1;
        a[sum] = (3 + pow(-1,i)) / 2;
        a[sum + 1] = (3 - pow(-1,i)) / 2;
    }
    for(int i = 0; i < T; i++){
        cout << a[b[i]] << endl;
    }
    return 0;
}
