/*
L1-034. 点赞

微博上有个“点赞”功能，你可以为你喜欢的博文点个赞表示支持。
每篇博文都有一些刻画其特性的标签，而你点赞的博文的类型，也间接刻画了你的特性。
本题就要求你写个程序，通过统计一个人点赞的纪录，分析这个人的特性。

输入格式：

输入在第一行给出一个正整数N（<=1000），是该用户点赞的博文数量。
随后N行，每行给出一篇被其点赞的博文的特性描述，格式为“K F1 ... FK”，其中 1<=K<=10，Fi（i=1, ..., K）是特性标签的编号，
我们将所有特性标签从1到1000编号。数字间以空格分隔。

输出格式：

统计所有被点赞的博文中最常出现的那个特性标签，在一行中输出它的编号和出现次数，数字间隔1个空格。如果有并列，则输出编号最大的那个。

输入样例：
4
3 889 233 2
5 100 3 233 2 73
4 3 73 889 2
2 233 123
输出样例：
233 3



#include<bits/stdc++.h>
using namespace std;
struct cmp
{
	bool operator()(const string &a,const string &b)
	{
		return a>b;
	}
};
int main()
{
    map<string,int> k;
    int n,t,max=0;
    string s1;
    set<string,cmp> s;
    set<string,cmp>::iterator it;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>t;
    	for(int j=0;j<t;j++)
    	{
    		cin>>s1;
    		k[s1]++;
    		s.insert(s1);
    	}
    }
    for(it=s.begin();it!=s.end();it++)
    {
    	if(k[*it]>max)
    	{
    		max=k[*it];
    		s1=*it;
    	}
    }
    cout<<s1<<' '<<max;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> k;
    int n,max=-1;
    string s1="0";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin>>t;
    	for(int j=0;j<t;j++)
    	{
			string s;
    		cin>>s;
    		k[s]++;
    		if(k[s]==max&&s>s1)
    		{
    			s1=s;
    		}
			else if(k[s]>max) 
    		{
    			max=k[s];
    			s1=s;
    		}
    		
    	}
    }
    cout<<s1<<' '<<max;
	return 0;
}
