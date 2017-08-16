/*************************************************************************
	> File Name: OpenJudge_2694:逆波兰表达式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月02日 星期三 13时43分19秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
double fun(){
    char str[30];
    cin>>str;
    if(str[0]=='*'){
        return fun()*fun();
    }else if(str[0]=='+'){
        return fun()+fun();
    }else if(str[0]=='-'){
        return fun()-fun();
    }else if(str[0]=='/'){
        return fun()/fun();
    }else {
        return atof(str);
    }
}
int main(){
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    printf("%f\n", fun());
    return 0;
}
