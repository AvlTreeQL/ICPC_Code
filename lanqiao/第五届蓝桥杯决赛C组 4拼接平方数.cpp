/*

标题：拼接平方数

    小明发现49很有趣，首先，它是个平方数。它可以拆分为4和9，拆分出来的部分也是平方数。169也有这个性质，我们权且称它们为：拼接平方数。

    100可拆分1 00，这有点勉强，我们规定，0 00 000 等都不算平方数。

    小明想：还有哪些数字是这样的呢？

    你的任务出现了：找到某个区间的所有拼接平方数。

【输入格式】
两个正整数  a b (a<b<10^6)

【输出格式】
若干行，每行一个正整数。表示所有的区间[a,b]中的拼接平方数

例如：
输入：
1 200

程序应该输出：
49
169

再例如：
输入：
169 10000

程序应该输出：
169
361
1225
1444
1681
3249
4225
4900
9025

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/
#include <bits/stdc++.h>  
using namespace std;  
  
set<string>S;  
string a;
long long shu1[10];  
void check(long long i)  
{  
    string s1,s2;
    s1=a.substr(0,i);
    s2=a.substr(i,a.size()-i);
    long long aa,bb;
    stringstream ss;
    ss<<s1;
    ss>>aa;
    ss.clear();
    ss<<s2;
    ss>>bb;
  	double son1=sqrt(aa),son2=sqrt(bb);
  	if(!son1||!son2) return ;
  	if(son1==(long long)son1&&son2==(long long)son2)
  	{
  		cout<<a<<endl;
  	}
}  
  
int main()  
{  
	long long n,m;
	cin>>n>>m;
	for(long long i=n;i<=m;i++)
	{
		double son=sqrt(i);
		if(son!=(long long)son) continue;		
		stringstream ss;
		ss<<i;
		ss>>a;
		for(long long j=1;j<a.size();j++)
			check(j);
	}

    return 0;  
} 

