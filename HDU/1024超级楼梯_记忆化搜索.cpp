/*************************************************************************
	> File Name: 蒜头君爬楼梯.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月06日 星期日 23时33分17秒
 ************************************************************************/

#include <iostream>
using namespace std;
int dp[71]={0,0,1,2},n;
int dfs(int x){//从大到小　栈的形式
    if(x<0) return 0;
    if(dp[x]) return dp[x];
    int a=dfs(x-1);
    int b=dfs(x-2);
    dp[x]+=a+b;
    return dp[x];
}
int main(){
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dfs(n)<<endl;
    }
	return 0;
}
