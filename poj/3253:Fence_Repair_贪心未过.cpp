/*************************************************************************
	> File Name: 3253:Fence_Repair_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 20时34分24秒
 ************************************************************************/
/*
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    long sum = a[n-1]*(n-1);
    for(int i = 0; i < n - 1; i++){
        sum += (i+1)*a[i];
    }
    if(n > 1) cout << sum << endl;
    else cout << a[0] << endl;
    return 0;
}*/
