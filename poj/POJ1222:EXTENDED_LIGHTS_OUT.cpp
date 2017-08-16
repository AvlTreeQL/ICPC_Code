/*************************************************************************
	> File Name: POJ1222:EXTENDED_LIGHTS_OUT.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月01日 星期二 21时41分55秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void setbit(char &c,int j,int val){
    if(val){
        c|=(1<<j);// 1|0=1 0|0=0  不改变除第j位的其他位  第j位 1|1=1 0|1=1 把第j位改成1
    }else{
        c&=~(1<<j);// 1&1=1 0&1=0 不改变除第j位的其他位  第j位 1&0=0 0&0=0 把第j位改成0
    }
}
int getbit(char Switch,int i){
    return (Switch>>i)&1;
}
void flip(char &c,int i){
    c^=(1<<i);
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        char light[5];
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int temp;
                scanf("%d",&temp);
                setbit(light[i],j,temp);
            }
        }
        char nowlight[5],result[5];
        for(int n=0;n<64;n++){
            int Switch=n;
            memcpy(nowlight,light,sizeof(light));
            for(int i=0;i<5;i++){
                result[i]=Switch;
                for(int j=0;j<6;j++){
                    if(getbit(Switch,j)){
                        if(j>0) flip(nowlight[i],j-1);
                        flip(nowlight[i],j);
                        if(j<5) flip(nowlight[i],j+1);
                    }
                }
                if(i<4)nowlight[i+1]^=Switch;
                Switch=nowlight[i];
            }
            if(!nowlight[4]){
                cout<<"PUZZLE #"<<t<<endl;
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(getbit(result[i],j)){
                            cout<<1<<' ';
                        }
                        else{
                            cout<<0<<' ';
                        }
                    }
                    cout<<endl;
                }
                break;
            }
        }
    }
    return 0;
}
