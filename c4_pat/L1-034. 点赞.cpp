/*
L1-034. ����

΢�����и������ޡ����ܣ������Ϊ��ϲ���Ĳ��ĵ���ޱ�ʾ֧�֡�
ÿƪ���Ķ���һЩ�̻������Եı�ǩ��������޵Ĳ��ĵ����ͣ�Ҳ��ӿ̻���������ԡ�
�����Ҫ����д������ͨ��ͳ��һ���˵��޵ļ�¼����������˵����ԡ�

�����ʽ��

�����ڵ�һ�и���һ��������N��<=1000�����Ǹ��û����޵Ĳ���������
���N�У�ÿ�и���һƪ������޵Ĳ��ĵ�������������ʽΪ��K F1 ... FK�������� 1<=K<=10��Fi��i=1, ..., K�������Ա�ǩ�ı�ţ�
���ǽ��������Ա�ǩ��1��1000��š����ּ��Կո�ָ���

�����ʽ��

ͳ�����б����޵Ĳ���������ֵ��Ǹ����Ա�ǩ����һ����������ı�źͳ��ִ��������ּ��1���ո�����в��У��������������Ǹ���

����������
4
3 889 233 2
5 100 3 233 2 73
4 3 73 889 2
2 233 123
���������
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
