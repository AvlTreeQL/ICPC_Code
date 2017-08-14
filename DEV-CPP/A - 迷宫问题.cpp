#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int a;
    int b;
}x[101];
int cmp(const node& a,const node& b)
{
    if(a.b>b.b) return 0;
    else if(a.b==b.b)
    {
        if(a.a>b.a) return 0;
        else return 1;
    }else
    {
        return 1;
    }
}
int main()
{
    int n,i,t,ans;
    while(scanf("%d",&n),n)
    {
        ans=0;
        for(i=0;i<n;i++) scanf("%d%d",&x[i].a,&x[i].b);
        sort(x,x+n,cmp);
        t=-1;
        for(i=0;i<n;i++)
        {
            if(x[i].a>=t)
            {
                t=x[i].b;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}