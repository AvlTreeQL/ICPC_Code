/*************************************************************************
	> File Name: 2106:Boolean_Expressions_递归.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月17日 星期四 16时32分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
bool ex();
bool term();
bool factor();
bool ex()
{
    bool ret = term();
    while(true) {
        char c;
        while(true) {
            c = cin.peek();
            if(c == ' ') cin.get();
            else break;
        }
        if(c == '|') {
            cin.get();
            bool t = term();
            ret = ret || t;
        } else {
            break;
        }
    }
    return ret;
}
bool term()
{
    bool ret = factor();
    while(true) {
        char c;
        while(true) {
            c = cin.peek();
            if(c == ' ') cin.get();
            else break;
        }
        if(c == '&') {
            cin.get();
            bool t = factor();
            ret = ret && t;
        } else {
            break;
        }
    }
    return ret;
}
bool factor()
{
    char c;
    while(true) {
        c = cin.peek();
        if(c == ' ') cin.get();
        else break;
    }
    if(c == 'V') {
        cin.get();
        return true;
    } else if(c == 'F') {
        cin.get();
        return false;
    } else if(c == '!') {
        cin.get();
        bool t = term();
        return !t;
    } else if(c == '(') {
        cin.get();
        bool ret = ex();
        while(true) {
            c = cin.peek();
            if(c == ' ') cin.get();
            else break;
        }
        cin.get();
        return ret;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int t =0;
    while(cin.peek()!=-1){
        if(ex()) cout << "true" << endl;
        else cout << "false" << endl;
        char c = cin.peek();
        if(c==-1) break;
        t++;
        if(t==10) break;
    }
    return 0;
}
