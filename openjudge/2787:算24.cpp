/*************************************************************************
	> File Name: 2787:算24.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月13日 星期日 22时40分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double minn = 1e-6;
bool count(double a[], int n){
    if(n == 1){
        if(fabs(a[0] - 24) < minn) return true;
        else return false;
    } 
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            double b[n-1];
            int len = 0;
            for(int k = 0; k < n; k++){
                if(k != i && k != j){
                    b[len++] = a[k];
                }
            }

            b[len] = a[i] + a[j];
            if(count(b,len+1)){
                return true;
            
            }

            b[len] = a[i] - a[j];
            if(count(b,len+1)){
                return true;
            
            }
            
            b[len] = a[j] - a[i];
            if(count(b,len+1)){
                return true;
            }

            b[len] = a[i] * a[j];
            if(count(b,len+1)){
                return true;
            }

            if(fabs(a[j]) > minn){
                b[len] = a[i] / a[j];
                if(count(b,len+1)){
                    return true;
                }
            
            }
            if(fabs(a[i]) > minn){
                b[len] = a[j] / a[i];
                if(count(b,len+1)){
                    return true;
                }
            }
       }
    }
    return false;
}
int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    double a[5];
    while(cin >> a[0] >> a[1] >> a[2] >> a[3]){
        if(fabs(a[0]) < minn) break;
        if(count(a,4)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
