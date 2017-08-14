/*************************************************************************
	> File Name: 1864:最大报销额.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月11日 星期五 21时25分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    double sum;
    int n;
    while(cin >> sum >> n){
        if(!n) break;
        double ans = -1;
        for(int i = 0; i < n; i++){
            int num;
            string str;;
            double temp, ss = 0;
            bool flag = false;
            cin >> num;
            while(num--){
                cin >> str;
                cin >> temp;
                ss += temp;
                if(temp > 600 || ss >1000){
                    flag = true;
                }
            }
            if(!flag && ans+ss<=sum) ans += ss;
        }
        cout << ans << endl;
    }
    return 0;
}
