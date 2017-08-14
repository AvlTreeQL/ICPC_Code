#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long i,amin=0,ans=0;
    cin>>n;
    for(i=2; i*i<=n; i++)
    {
        long long cnt=1;
        for(long long j=i; cnt*j<=n; j++)
        {
            cnt*=j;
            if(n%cnt==0)
            {
                if(ans<j-i+1)
                {
                    ans=j-i+1;
                    amin=i;
                }
            }
        }
    }
    if(amin==0)
    {
        ans=1;
        amin=n;
    }
    cout<<ans<<endl;
    for(i=amin; i<amin+ans; i++)
    {
        if(i>amin)
            cout<<"*";
        cout<<i;
    }
    cout<<endl;
    return 0;
}
/*
L1-006. 连续因子

一个正整数N的因子中可能存在若干连续的数字。
例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。
给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：

输入在一行中给出一个正整数N（1<N<231）。

输出格式：

首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，其中因子按递增顺序输出，1不算在内。

输入样例：
630
输出样例：
3
5*6*7
思路：需要分解因数
*/
