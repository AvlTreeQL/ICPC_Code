/*************************************************************************
	> File Name: 1011.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月08日 星期二 14时06分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >>k;
        int a[n] = {0};
        int maxs = -1;
    //    map<int,int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
      //      mp(a[i])++;
    //        maxs = max(maxs,a[i]);
        }
        sort(a, a+n);
        int num = 1;
        for(int i = n - 1; i > 0; i--){
            int temp = abs(a[i],a[i-1]);
            if(temp <= k) {
                num++;
            }else {
                break;
            }
        }
        cout << num << endl;
    }
    return 0;
}
