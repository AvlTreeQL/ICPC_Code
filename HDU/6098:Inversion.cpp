/*************************************************************************
	> File Name: 6098:Inversion.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月11日 星期五 13时11分12秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main(){
  //  freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, temp;
        map<int,int,greater<int> > mp;
        map<int,int,greater<int> >::iterator it;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> temp;
            mp[temp] = i;
        }
        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second%2 != 0){
                cout << it->first;
                break;
            }
        }
        for(int i = 3; i <=n ;i++){
            for(it = mp.begin(); it != mp.end(); it++){
                if(it->second%i != 0){
                    cout << ' ' << it->first;
                    break;
                }
            } 
        }
        cout << endl;
    }
    return 0;
}
