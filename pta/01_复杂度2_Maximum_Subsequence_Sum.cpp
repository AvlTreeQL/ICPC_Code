/*************************************************************************
	> File Name: 01_复杂度2_Maximum_Subsequence_Sum.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年09月02日 星期六 15时42分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sum = 0,ans = -1;
    int s = 0, e = 0, ss, ee;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(i == 0) ss = s = temp;
        if(sum < 0){
            sum = temp;
            s = temp;
            e = temp;
        }else{
            sum += temp;
            e = temp;
        }
        if(sum > ans){
            ans = sum;
            ss = s;
            ee = e;
        }
    }
    if(ans == -1) cout << 0 << " " << ss << " " << temp << endl;
    else cout << ans << " " << ss << " " << ee << endl;
    return 0;
}
