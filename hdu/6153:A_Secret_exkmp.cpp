/*************************************************************************
	> File Name: 6153:A_Secret_exkmp.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月25日 星期五 13时26分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
void getNext(string T, long long next[])
{
    int a = 0, p = 0;
    next[0] = T.size();
    int i = 1;
    while(i < T.size()) {
        if(i >= p || i + next[i - a] >= p) {
            if(i >= p) {
                p = i;
            }
            while(p < T.size() && T[p] == T[p - i]) {
                p++;
            }
            next[i] = p - i;
            a = i;

        } else {
            next[i] = next[i - a];
        }
        i++;
    }
}
void exkmp(string S, string T, long long next[], long long extend[])
{
    int a = 0, p = 0;
    int i = 0;
    getNext(T,next);
    while(i < S.size()) {
        if(i >= p || i + next[i - a] >= p) {
            if(i >= p) {
                p = i;
            }
            while(p < S.size() && p - i < T.size() && S[p] == T[p - i]) {
                p++;
            }
            extend[i] = p - i;
            a = i;

        } else {
            extend[i] = next[i - a];
        }
        i++;
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string T, S;
        cin >> S >> T;
        reverse(S.begin(), S.end());
        reverse(T.begin(), T.end());
        long long next[T.size() + 1], extend[S.size() + 1];
        exkmp(S, T, next, extend);
        long long sum = 0;
        for(int i = 0; i < S.size(); i++) {
            sum += ((1 + extend[i]) * extend[i] / 2) % mod;
        }
        cout << sum%mod << endl;
    }
    return 0;
}
