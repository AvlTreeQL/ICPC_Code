/*
L2-019. ���Ĺ�ע

����΢�����и������Ĺ�ע����һ���û����Ĺ�ע���ˣ�������������û��Ĺ�ע�б��ϣ���ϵͳ�����������Ĺ�ע���˷����΢�������û���
������������һ��������̽������ĳ�˵Ĺ�ע�б����������û��ĵ���������ǳ��п��ܱ������Ĺ�ע���ˡ�

�����ʽ��

���������ڵ�һ�и���ĳ�û��Ĺ�ע�б���ʽ���£�
����N �û�1 �û�2 ���� �û�N
����N�ǲ�����5000����������ÿ�����û�i����i=1, ..., N���Ǳ����ע���û���ID��
�ǳ���Ϊ4λ�������ֺ�Ӣ����ĸ��ɵ��ַ�����������Կո�ָ���
֮��������û����޵���Ϣ��
���ȸ���һ��������10000��������M�����M�У�ÿ�и���һ��������޵��û�ID�ͶԸ��û��ĵ��޴�����������1000�����Կո�ָ���
ע�⣺�û�ID��һ���û���Ψһ��ݱ�ʶ����Ŀ��֤�ڹ�ע�б���û���ظ��û����ڵ�����Ϣ��Ҳû���ظ��û���

�����ʽ��

������Ϊ�����û����޴������������ƽ�������Ҳ������ע�б��ϵ��ˣ��ܿ����������Ĺ�ע���ˡ�
����������裬���㰴�û�ID��ĸ���������������������Ĺ�ע���ˣ�ÿ��1��ID�������ʵ��û���������ˣ��������Bing Mei You����

��������1��
10 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao
8
Magi 50
Pota 30
LLao 3
Ammy 48
Dave 15
GAO3 31
Zoro 1
Cath 60
�������1��
Ammy
Cath
Pota
��������2��
11 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao Pota
7
Magi 50
Pota 30
LLao 48
Ammy 3
Dave 15
GAO3 31
Zoro 29
�������2��
Bing Mei You
*/
#include<bits/stdc++.h>
#include<numeric>
using namespace std;
int main()
{
	string tt,s[10001];
	set<string> k2;
	set<string> ss;
	set<string>::iterator it;
	int n,n1,i,j,t,num[10001];
	double ave;
	cin>>n1;
	for(i=0;i<n1;i++)
	{
		cin>>tt;
		ss.insert(tt);
	}
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		cin>>num[i];
	} 
	ave=(double)accumulate(num,num+n,0)/n;
	for(i=0;i<n;i++)
	{
		if(num[i]>ave&&ss.find(s[i])==ss.end())
		{
			k2.insert(s[i]);
		}
	}
	for(it=k2.begin();it!=k2.end();it++)
	{
		cout<<*it<<endl;
	}
	if(k2.size()==0)
	{
		cout<<"Bing Mei You"<<endl;
	}
	return 0;
}
