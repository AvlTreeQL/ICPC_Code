/*
1109 01��ɵ�N�ı���
��׼ʱ�����ƣ�1 �� �ռ����ƣ�131072 KB ��ֵ: 40 �Ѷȣ�4���㷨�� �ղ�  ��ע
����һ����Ȼ��N���ҳ�һ��M��ʹ��M > 0��M��N�ı���������M��10���Ʊ�ʾֻ����0��1������С��M��
���磺N = 4��M = 100��
Input
����1����N��(1 <= N <= 10^6)
Output
���������������С��M��
Inputʾ��
4
Outputʾ��
100
*/
#include<iostream>
#include<sstream>
using namespace std;
void change(string &s,int n)
{
	string bit="01";
	if(n==0)
	{
		s="";
		return ;
	}
	change(s,n/2);
	s+=bit[n%2];	
}

void fun(int n)
{
	long long sum;
	for(long long i=1;;i++)
	{
		string s;	
		change(s,i);
		stringstream ss(s);
		ss>>sum;
		if(sum%n==0) 
		{
			cout<<s<<endl;
			break;
		}
	}
	
}
int main()
{
	int n;
	cin>>n;
	fun(n);
	return 0;
}
