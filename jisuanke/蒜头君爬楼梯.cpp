/*************************************************************************
	> File Name: 蒜头君爬楼梯.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月06日 星期日 23时33分17秒
蒜头君要爬一个有 n 个台阶的楼梯。蒜头君一步可以走 1 个台阶或 2 个台阶。现在蒜头君想请你帮忙算下，一共会有多少种不同的爬楼梯方法？

输入格式

输入一行，输入一个正整数n(1≤n≤70)，代表一共有 n 个台阶。

输出格式

输出一个整数，表示一共有多少种不同的爬楼梯方法。

样例输入

3
样例输出

3
 ************************************************************************/

#include <iostream>
using namespace std;
int dp[71]={0,1,2,3},n;
int dfs(int x){//从大到小　栈的形式 利用已知推未知
    if(x<0)return 0;
    if(dp[x]) return dp[x];
    int a=dfs(x-1);
    int b=dfs(x-2);
    dp[x]+=a+b;
    return dp[x];
}
int main(){
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<dfs(n)<<endl;
	return 0;
}
