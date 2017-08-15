/*************************************************************************
	> File Name: 区间调度问题_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月15日 星期二 23时19分51秒

问题描述：
有n项工作，每项工作分别在si开始，ti结束。对每项工作，你都可以选择参加或不参加，但选择了参加某项工作就必须至始至终参加全程参与，即参与工作的时间段不能有重叠(即使开始的时间和结束的时间重叠都不行)。
限制条件：
1<=n<=100000
1<=si<=ti<=1e9
样例：
输入
n=5
s={1,2,4,6,8}
T={3,5,7,9,10}
输出
3(选择工作1, 3, 5)

************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    pair<int,int> p[maxn];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].second;
    }
    for(int i = 0; i < n; i++){
        cin >> p[i].first;

    }
    sort(p,p+n);
    int end = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(p[i].second > end){
            ans++;
            end = p[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
