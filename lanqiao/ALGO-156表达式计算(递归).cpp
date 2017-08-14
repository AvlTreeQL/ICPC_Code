/*************************************************************************
	> File Name: text.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月06日 星期日 22时18分54秒
 ************************************************************************/

#include <iostream>
using namespace std;
int factor();
int term();
int ex(){
    int ret = term();
    while(true){
        char c = cin.peek();
        if(c == '+'){
            cin.get();
            ret += term();
        }else if(c == '-'){
            cin.get();
            ret -= term();
        }else{
            break;
        }
    }
    return ret;
}
int term(){
    int ret = factor();
    while(true){
        char c = cin.peek();
        if(c == '*'){
            cin.get();
            ret *= factor();
        }else if(c == '/'){
            cin.get();
            ret /= factor();
        }else{
            break;
        }   
    }
    return ret;
}
int factor(){
    char c = cin.peek();
    int ret;
    if(c == '('){
        cin.get();
        ret = ex();
        cin.get();
    }else{
        cin >> ret;
    }
    return ret;
}
int main(){
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    cout << ex() <<endl;
	return 0;
}
