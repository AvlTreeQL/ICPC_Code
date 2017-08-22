/*************************************************************************
	> File Name: 4333:Revolving_Digits_exkmp.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月21日 星期一 21时32分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
void getNext(string T, int next[])//不是 拓展KMP的那种next[] ,这里next[i] 存的是 i之前的字符串的前缀  后缀 最长长度
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < T.size()){
        if(j == -1 || T[i] == T[j]){
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}
void getExtend(string T, int extend[])
{
    int a = 0, p = 0;
    extend[0] = T.size();
    for(int i = 1; i < T.size(); i++) {
        if(i >= p || i + extend[i - a] >= p) {
            if(i >= p) {
                p = i;
            }
            while(p < T.size() && T[p] == T[p - i]) {
                p++;
            }
            extend[i] = p - i;
            a = i;
        } else {
            extend[i] = extend[i - a];
        }
    }
}
int main()
{
 //   freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        string T;
        cin >> T;
        string TT = T + T;
        
        int next[T.size()];
        getNext(T,next);
        int cycle = T.size() - next[T.size()];//最小循环节
        int num = 1;
        if(T.size() % cycle == 0){
            num = T.size() / cycle;
        }

        int extend[TT.size()];
        getExtend(TT, extend);
        int a = 0, b = 0, c = 0;
        for(int j = 0; j < T.size(); j++) {
            if(extend[j] >= T.size()) a++;
            else if(TT[extend[j]] > TT[j + extend[j]]) b++;
            else if(TT[extend[j]] < TT[j + extend[j]]) c++;
        }
        cout << "Case " << i << ": " << b/num << ' ' << a/num << ' ' << c/num << endl;
    }
    return 0;
}
