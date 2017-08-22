#include<stdio.h>
#include<iostream>
using namespace std;
#define M 400050
struct node{
    int l,r,cover;
}t[M];
void Init(int l,int r,int id){
    t[id].l=l;
    t[id].r=r;
    t[id].cover = 1;
    if(r-l<=1) return ;
    int mid=(l+r)>>1;
    Init(l,mid,id*2);
    Init(mid,r,id*2+1);
    return ;
}
void Update(int l,int r,int k,int id){
    if(t[id].l==l && t[id].r==r){
        t[id].cover=k;
        return ;
    }
    if(t[id].cover != 0){
        t[id * 2].cover=t[id].cover;
        t[id * 2 + 1].cover=t[id].cover;
        t[id].cover = 0;
    }
    int mid = (t[id].l + t[id].r) >> 1;
    if(r<=mid){
        Update(l,r,k,id*2);
    }
    else if(l>=mid){
        Update(l,r,k,id*2+1);
    }
    else {
        Update(l,mid,k,id*2);
        Update(mid,r,k,id*2+1);
    }
}
int Search(int l,int r, int id){
    if(t[id].cover>0){
        return t[id].cover*(r-l);
    }
    int mid=(t[id].r + t[id].l) >> 1;
    if(l>=mid){
        return Search(l,r,id*2+1);
    }
    else if(r<=mid){
        return Search(l,r,id*2);
    }
    else {
        return Search(l,mid,id*2)+Search(mid,r,id*2+1);
    }
}
int main(){
    int cas,i,j,count,n,m;
    count = 0;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        Init(0,n,1);
        while(m--){
            int l,r,key;
            scanf("%d%d%d",&l,&r,&key);
            Update(l-1,r,key,1);
        }
        int ans = Search(0, n, 1);
        printf("Case %d: The total value of the hook is %d.\n",++count,ans);
    }
    return 0;
}
