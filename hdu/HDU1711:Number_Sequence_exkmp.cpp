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
void getNext(int T[], int T_len,int next[]) {
    int a = 0, p = 0;
    next[0] = T_len;
    for (int i = 1; i < T_len; i++) {
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p) p = i;
            while (p < T_len && T[p] == T[p - i]) {
                p++;
            }
            next[i] = p - i;
            a = i;
        }
        else {
            next[i] = next[i - a];
        }
    }
}
void getExtend(int S[], int T[],int S_len, int T_len, int extend[], int next[]) {
    int a = 0, p = 0;
    getNext(T,T_len, next);
    for (int i = 0; i < S_len; i++) {
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p) p = i;
            while (p < S_len && p - i < T_len && S[p] == T[p - i]) p++;
            extend[i] = p - i;
            a = i;
        }
        else {
            extend[i] = next[i - a];
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int a_len, b_len;
        int a[1000010], b[10010];
        int extend[1000010], next[10010];
        cin >> a_len >> b_len;
        for (int i = 0; i < a_len; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < b_len; i++) {
            cin >> b[i];
        }
        getExtend(a, b, a_len, b_len, extend, next);
        int i;
        for (i = 0; i < a_len; i++) {
            if (extend[i] == b_len) {
                cout << i+1 << endl;
                break;
            }
        }
        if (i == a_len) cout << -1 << endl;
    }
    return 0;
}
