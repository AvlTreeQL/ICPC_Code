/*************************************************************************
	> File Name: 01_复杂度1_最大子列和问题.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月02日 星期六 15时08分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sum = 0,ans = 0;
    while(n--){
        int temp;
        cin >> temp;
        if(sum < 0){
            sum = temp;
        }else{
            sum += temp;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
