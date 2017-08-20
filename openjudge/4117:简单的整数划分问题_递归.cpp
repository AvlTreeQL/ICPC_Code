/*************************************************************************
	> File Name: 4117:简单的整数划分问题_递归.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 22时17分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int sum = 0;
void fun(int x,int t){//按照放苹果的思路，t就是每个盘子最多能放的苹果数
    if(x == 0){
        sum++;
        return ;
    }
    int up = min(x,t);
    for(int i = up; i > 0; i--){
        fun(x-i,i);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        sum = 0;
        fun(n,1e9);
        cout << sum << endl;
    }
    return 0;
}
