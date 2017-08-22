/*************************************************************************
	> File Name: 1304:字符串的相似度_exkmp.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月21日 星期一 19时33分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void getNext(char T[],int len, int next[]){
    int a = 0, p = 0;
    next[0] = len;
    for(int i = 1; i < len; i++){
        if(i >= p || i + next[i - a] >= p){
            if(i >= p){
                p = i;
            }
            while(p < len && T[p] == T[p-i]){
                p++;
            }
            next[i] = p - i;
            a = i;
        } else {
            next[i] = next[i-a];
        }
    }
}
int main(){
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    char str[1000010];
    cin >> str;
    int len = strlen(str);
    int next[len];
    getNext(str,len,next);
    long long sum = 0;
    for(int i = 0; i < len; i++){
        sum += next[i];
    }
    cout << sum << endl;
    return 0;
}
