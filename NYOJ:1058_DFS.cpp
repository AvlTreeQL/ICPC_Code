/*************************************************************************
	> File Name: NYOJ:1058_DFS.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 19时41分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e8;
int a[20] = {0}, k, n;
bool b[20];
bool dfs(int x, int sum){
    if(x == n) return sum == k;
    
    b[x] = true;
    if(dfs(x+1,sum+a[x])) return true;
    
    b[x] = false;
    if(dfs(x+1,sum)) return true;
    
    return false;
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    while(cin >> n >> k){
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(dfs(0,0)){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                if(b[i]) cout << a[i] << " ";
            }
            cout << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
