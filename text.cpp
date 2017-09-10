/*************************************************************************
	> File Name: text.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月09日 星期六 23时21分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1,r, rt<<1|1
using namespace std;
const int maxn = 50010;
int sum[maxn << 2];
void build(int l, int r, int rt){
    if(r==l){
        cin >> sum[rt];
        return ;
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int s, int e, int l, int r, int rt){
    if(s<=l&&r<=e){
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ans = 0;
    if(l<=m) ans += query(s,e,lson);
    if(m<r) ans += query(s,e,rson);
    return ans;
}
void add(int i, int val, int l, int r, int rt){
    if(l==r){
        sum[rt] = val;
        return ;
    }
    int m = (l+r)>>1;
    if(i<=m) add(i,val,lson);
    else add(i,val,rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        build(1,n,1);
        string str;
        int a, b;
        while(cin >> str){
            if(str[0] == 'E') break;
            cin >> a >> b;
            if(str[0] == 'Q') cout << query(a,b,1,n,1) << endl;
            if(str[0] == 'A') add(a,b,1,n,1);
            else add(a,-b,1,n,1);
        }
    }
    return 0;
}
