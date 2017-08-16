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
        while(s<n){
            int pos = lower_bound(a+s,a+n,a[s]+r)-a-1;
            ans++;
            s = upper_bound(a+pos,a+n,a[pos]+r)-a;
        }
        cout << ans << endl;
    }
    return 0;
}
