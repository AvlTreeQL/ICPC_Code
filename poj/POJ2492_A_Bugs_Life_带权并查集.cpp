/*************************************************************************
	> File Name: POJ2492_A_Bugs_Life_带权并查集.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月04日 星期一 13时02分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int f[2010], r[2010];// f[i] == 0  i和父节点同类， f[i] == 1 i和父节点异类
void init(int n){
    for(int i = 0; i <=n; i++){
        f[i] = i;
        r[i] = 0;
    }
}
int find(int x){
    if(f[x] == x){
        return x;
    } 
    int y = f[x];
    f[x] = find(y);
    if(r[x] == 0 && r[y] == 0){             //r[x] = !(r[x] == r[y])
        r[x] = 0;                           //r[x] = (r[x]+r[y]+1)&1
    } else if(r[x] == 0 && r[y] == 1){
        r[x] = 1;
    } else if(r[x] == 1 && r[y] == 0){
        r[x] = 1;
    } else if(r[x] == 1 && r[y] == 1){
        r[x] = 0;
    }
    return f[x];
}
bool merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb){
        if(r[a] == r[b]){
            return false;
        } else {
            return true;
        }
    } else {
        f[pa] = pb;
        if(r[a] == 0 && r[b] == 0){
            r[pa] = 1; 
        } else if(r[a] == 1 && r[b] == 0){
            r[pa] = 0;
        } else if(r[a] == 0 && r[b] == 1){
            r[pa] = 0;
        } else if(r[a] == 1 && r[b] == 1){
            r[pa] = 1;
        }
    }   
    return true;
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int n, m;
        cin >> n >> m;
        init(n);
        int a, b;
        bool flag = false;
        while(m--){
            cin >> a >> b;
            if(!merge(a, b)){
                flag = true;
            }
        }
        cout << "Scenario #" << i <<":" << endl;
        if(flag){
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }
        if(i != T) cout << endl;
    }
    return 0;
}
