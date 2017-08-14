/*************************************************************************
	> File Name: team_1009.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月03日 星期四 13时28分28秒
 ************************************************************************/

#include <iostream>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,num=0,temp;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp%2) num++;
        }
        if(num*2>n) cout<<2<<' '<<1<<endl;
        else cout<<2<<' '<<0<<endl;
    }
	return 0;
}
