/*
���⣺��������

����Ħ˹��X���յ�һ�����ϣ�ȫ����Сд��ĸ��ɡ�
���������ṩ����һ�����ϣ���೤��Ϊ8�������б�
����Ħ˹���֣���Щ�����Ǳ����Һ���������ǰ�Ƿ������еġ�

�����дһ�����򣬴ӵ�һ�������������������������λ�á�Ҫ����������������п����ԡ�

���ݸ�ʽ��

�����һ�У�һ���ַ���s��ȫ����Сд��ĸ��ɣ�����С��1024*1024
������һ����һ������n,��ʾ������n�����룬1<=n<=1000
��������n���ַ���������Сд��ĸ��ɣ����ȶ�Ϊ8

Ҫ�������
һ������, ��ʾÿ�����������������s��ƥ��������ܺ͡�

���磺
�û����룺
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc

�����Ӧ�������
4

������Ϊ����һ������ƥ����3�Σ��ڶ�������ƥ����1�Σ�һ��4�Ρ�


��ԴԼ����
��ֵ�ڴ����� < 512M
CPU����  < 3000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�

*/


// ��Ŀ˵��ƥ�������ָ�ɹ�ƥ��Ĵ��� ������ ����ƥ��Ĵ��� 
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
