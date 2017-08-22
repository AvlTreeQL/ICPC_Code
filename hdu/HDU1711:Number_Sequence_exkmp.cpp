/*************************************************************************
	> File Name: HDU1711:Number_Sequence_exkmp.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月21日 星期一 23时11分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void getNext(string T, int next[]){
    int a = 0, p = 0;
    next[0] = T.size();
    for(int i = 1; i < T.size(); i++){
        if(i >= p || i + next[i-a] >= p){ 
            if(i >= p) p = i;
            while(p < T.size() && T[p] == T[p-i]){
                p++;
            }
            next[i] = p - i;
            a = i;
        } else {
            next[i] = next[i -a];
        }
    }
}
void getExtend(string S, string T, int extend[], int next[]){
    int a = 0, p = 0;
    getNext(T,next);
    for(int i = 0; i < S.size(); i++){
        if(i >= p || i + next[i-a] >= p){
            if(i >= p) p = i;
            while(p < S.size() && p-i < T.size()  && S[p] == S[p-i]) p++;
            extend[i] = p - i;
            a = i;
        } else {
            extend[i] = next[i - a];
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a_len,b_len;
        cin >> a_len >> b_len;
        int a[a_len],b[b_len];
        for(int i = 0; i < a_len; i++){
            cin >> a[i];
        }
        for(int i = 0; i < b_len; i++){
            cin >> b[i];
        }
        int 
    }
    return 0;
}
