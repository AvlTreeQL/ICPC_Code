/*************************************************************************
	> File Name: text.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月06日 星期日 22时18分54秒
 ************************************************************************/

#include <iostream>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int a[55]={0,1,1,1,1};//a[i]=a[i-1]+a[i-3]      a[i]代表老牛，b[i]代表小牛
    int f[55]={0,1,2,3,4};//b[i]=a[i-1]+b[i-1]=f[i-1]  f[i]=a[i]+b[i]=a[i]+f[i-1]
    for(int i=5;i<55;i++){
        a[i]=a[i-1]+a[i-3];
        f[i]=a[i]+f[i-1];
    }
    int n;mZ    int t=0;
    while(true){
        cin>>n;
        if(n==0)break;
        cout<<f[n]<<endl;
    }
	return 0;
}
