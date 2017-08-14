/*
���⣺���Ӵ���

С������ÿ���糿������һ�Ұ����̳���͡���������Ұ�������N�����������е�i������ǡ���ܷ�Ai�����ӡ�ÿ���������зǳ�������

������Ϊ����������

ÿ���й˿�����X�����ӣ������ӵĴ���ͻ�Ѹ��ѡ����������������ʹ������������ǡ��һ����X�����ӡ�

����һ����3���������ֱ��ܷ�3��4��5�����ӡ�

���˿�����11������ʱ������ͻ�ѡ2��3�����ټ�1��5���ģ�Ҳ����ѡ��1��3�����ټ�2��4���ģ���

��Ȼ��ʱ���Ӵ����������Ҳ�ղ����˿����������������һ����3���������ֱ��ܷ�4��5��6�����ӡ�

���˿�����7������ʱ������ʹղ������ˡ�

С����֪��һ���ж�������Ŀ�ǰ��Ӵ���ղ������ġ�

����
----
��һ�а���һ������N��(1 <= N <= 100)
����N��ÿ�а���һ������Ai��(1 <= Ai <= 100)  

���
----
һ����������𰸡�����ղ�������Ŀ�����޶�������INF��

���磬
���룺
2  
4  
5   

����Ӧ�������
6  

�����磬
���룺
2  
4  
6    

����Ӧ�������
INF

�������ͣ�
��������1���ղ�������Ŀ������1, 2, 3, 6, 7, 11��  
��������2�������������ղ����������������޶����  

��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

ע�⣺
main������Ҫ����0;
ֻʹ��ANSI C/ANSI C++ ��׼;
��Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
���������ĺ���������ȷ����Դ�ļ��� #include <xxx>
����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύ����ʱ��ע��ѡ�����������������ͺͱ��������͡�

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
