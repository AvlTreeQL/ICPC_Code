/*
标题：密文搜索

福尔摩斯从X星收到一份资料，全部是小写字母组成。
他的助手提供了另一份资料：许多长度为8的密码列表。
福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。

请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。要考虑密码的所有排列可能性。

数据格式：

输入第一行：一个字符串s，全部由小写字母组成，长度小于1024*1024
紧接着一行是一个整数n,表示以下有n行密码，1<=n<=1000
紧接着是n行字符串，都是小写字母组成，长度都为8

要求输出：
一个整数, 表示每行密码的所有排列在s中匹配次数的总和。

例如：
用户输入：
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc

则程序应该输出：
4

这是因为：第一个密码匹配了3次，第二个密码匹配了1次，一共4次。


资源约定：
峰值内存消耗 < 512M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/


// 题目说的匹配次数是指成功匹配的次数 而不是 尝试匹配的次数 
#include<iostream>
#include<string>
#include<cstring>
#include<set> 
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip> 
#include<cstdio>
#include<map>
using namespace std;  
class node
{
public:
	map<char,int> k;
	node(){	}
	node(string s)
	{
		for(int i=0;i<s.size();i++)
		{
			k[s[i]]++;
		}
	}
};
map<char,int>::iterator it;
int main()  
{  
    string ss,tt;
    vector<node> v;
	int n;
    cin>>ss;
    for(int i=0;i<=ss.size()-8;i++)
    {
    	v.push_back(node(ss.substr(i,8)));
    }
    int sum=0;
    cin>>n;
    while(n--)
    {
    	cin>>tt;
    	node a(tt);
    	for(int i=0;i<v.size();i++)
    	{
    		int flag=0;
    		for(it=a.k.begin();it!=a.k.end();it++)
    		{
    			if(it->second!=v[i].k[it->first])
    			{
    				flag=1;
    				break;
    			}
    		}
    		if(!flag) sum++;
    	}
    }
    cout<<sum<<endl;
    return 0;  
}  
