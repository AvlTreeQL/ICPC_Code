/*************************************************************************
	> File Name: 008:求排列的逆序数_归并排序.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月24日 星期四 17时04分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int n;
long long res = 0;
int a[maxn];
int temp[maxn];
void msort(int a[],int s,int m,int e,int temp[]){
    int p1 = s, p2 = m+1, p = 0;
    while(p1 <= m && p2 <= e){
        if(a[p1] > a[p2]){
            temp[p++] = a[p1++]; 
        } else {
            temp[p++] = a[p2++]; 
        }
    }
    while(p1<=m) 
        temp[p++] = a[p1++]; 
    while(p2<=m) 
        temp[p++] = a[p2++];
    for(int i = 0; i < p; i++){
        a[s+i] = temp[i];
    }
}
long long count(int a[], int s, int m, int e){
    long long ans = 0;
    int p1 = s, p2 = m+1;
    while(p1 <= m && p2 <= e){
        if(a[p1] > a[p2]){
            ans += e - p2 + 1;
            p1++;
        }else{
            p2++;
        }
    }
    return ans;
}
void mergesort(int a[], int s, int e, int temp[]){
    if(s < e){
        int m = s + (e-s)/2;
        mergesort(a,s,m,temp);
        mergesort(a,m+1,e,temp);
        res += count(a,s,m,e);
        msort(a,s,m,e,temp);
    }
}
int main(){
  //  freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    mergesort(a,0,n-1,temp);
    cout << res << endl;
    return 0;
}
