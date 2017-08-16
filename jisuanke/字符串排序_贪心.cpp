/*************************************************************************
	> File Name: 字符串排序_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 15时10分34秒

给定 n 个字符串，将这 n 个字符串拼成一个长的字符串，并使之 字典序 最小。

例如，对于这三个字符串aba、ab、c，一共有如下 6 种拼接方式：

1
abaabc
2
abacab
3
ababac
4
abcaba
5
cabaab
6
cababa
显然，第一种拼接方式的字典序最小。你需要求出这个字典序最小的拼接方式。

输入
3
aba ab c

************************************************************************/

#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;
bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string str[n];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    sort(str,str+n,cmp);
    for(int i = 0; i < n; i++){
        cout << str[i];
    }
    return 0;
}
