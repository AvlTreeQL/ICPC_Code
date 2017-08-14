/*
标题：包子凑数

小明几乎每天早晨都会在一家包子铺吃早餐。他发现这家包子铺有N种蒸笼，其中第i种蒸笼恰好能放Ai个包子。每种蒸笼都有非常多笼，

可以认为是无限笼。

每当有顾客想买X个包子，卖包子的大叔就会迅速选出若干笼包子来，使得这若干笼中恰好一共有X个包子。

比如一共有3种蒸笼，分别能放3、4和5个包子。

当顾客想买11个包子时，大叔就会选2笼3个的再加1笼5个的（也可能选出1笼3个的再加2笼4个的）。

当然有时包子大叔无论如何也凑不出顾客想买的数量。比如一共有3种蒸笼，分别能放4、5和6个包子。

而顾客想买7个包子时，大叔就凑不出来了。

小明想知道一共有多少种数目是包子大叔凑不出来的。

输入
----
第一行包含一个整数N。(1 <= N <= 100)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100)  

输出
----
一个整数代表答案。如果凑不出的数目有无限多个，输出INF。

例如，
输入：
2  
4  
5   

程序应该输出：
6  

再例如，
输入：
2  
4  
6    

程序应该输出：
INF

样例解释：
对于样例1，凑不出的数目包括：1, 2, 3, 6, 7, 11。  
对于样例2，所有奇数都凑不出来，所以有无限多个。  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/
/*
#include<iostream>
#include<string>
#include<cstring>
#include<set> 
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip> 
#include<cstdio>
using namespace std;
vector<int> v;
bool flag;
void dfs(int n)
{
	if(n==0||flag==true)
	{
		flag=true;
		return ;
	}
	if(n<0)
		return ;
	for(int i=0;i<v.size();i++)
	{
		dfs(n-v[i]);
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	int flag1=0,flag2=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]%2==0) flag1=1;
		else flag2=1;
		if(flag2&&flag1)
			break;
	}
	if(flag1&&flag2==0)
	{
		cout<<"INF"<<endl;
		return 0;
	}
	else
	{
		int sum=0;
		for(int i=1;v[v.size()-1]*v[v.size()-2];i++)
		{
			flag=false;
			dfs(i);
			if(!flag)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

bool judge(int x,int y)
{
    int t;
    while(y>0)
    {
        t=x%y;
        x=y;
        y=t;
    }
    if(x==1)
        return true;
    return false;
}

int a[110],n;
bool dp[10010];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int  flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(judge(a[i],a[j]))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag!=1)
    {
        printf("INF\n");
        return 0;
    }
    dp[0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j+a[i]<10000; j++)
            if(dp[j])
                dp[j+a[i]]=1;
    }
    int ans=0;
    for(int i=0; i<10000; i++)
    {
        if(dp[i]!=1)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
