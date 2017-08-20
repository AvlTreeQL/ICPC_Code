/*************************************************************************
	> File Name: 3069:Sarumans_Army_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 16时31分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int r, n;
    while(cin >> r >> n){
        if(r==-1&&n==-1) break;
        for(int i = 0; i < n; i++){
            cin >>  a[i];
        }
        sort(a,a+n);
        int s = 0, ans = 0;
        while(s<n){                                   // upper_bound()      > val的第一个下标, 有多个val返回最后一个val的下标
            int pos = upper_bound(a+s,a+n,a[s]+r)-a-1;// upper_bound()-1    <=val的第一个下标
            ans++;                                    // lower_bound()      >=val的第一个下标，有多个val返回第一个val的下标
            s = upper_bound(a+pos,a+n,a[pos]+r)-a;    // lower_bound()-1    < val的第一个下标
        }
        cout << ans << endl;
    }
    return 0;
}
