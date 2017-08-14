/*************************************************************************
	> File Name: a:全排列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月30日 星期日 20时36分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    char str[7];
    cin>>str;
    int len=strlen(str);
    do{
        cout<<str<<endl;
    }while(next_permutation(str,str+len));
}
