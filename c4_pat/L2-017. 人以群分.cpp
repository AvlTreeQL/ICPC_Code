/*
L2-017. ����Ⱥ��

�罻���������Ǹ�ÿ���˶�����һ������Ծ�ȡ�����ϣ���������ָ�����Ⱥ��Ϊ�����࣬�������ͣ�outgoing������Ծ�ȸߵģ��������ͣ�introverted������Ծ�ȵ͵ģ���
Ҫ��������Ⱥ�Ĺ�ģ�����ܽӽ��������ǵ��ܻ�Ծ�Ȳ�ྡ����������

�����ʽ��

�����һ�и���һ��������N��2 <= N <= 105����
���һ�и���N�����������ֱ���ÿ���˵Ļ�Ծ�ȣ�����Կո�ָ���
��Ŀ��֤��Щ�����Լ����ǵĺͶ����ᳬ��231��

�����ʽ��

�����и�ʽ�����

Outgoing #: N1
Introverted #: N2
Diff = N3
���� N1 ���������˵ĸ�����N2 ���������˵ĸ�����N3 ����Ⱥ���ܻ�Ծ��֮��ľ���ֵ��

��������1��
10
23 8 10 99 46 2333 46 1 666 555
�������1��
Outgoing #: 5
Introverted #: 5
Diff = 3611
��������2��
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
�������2��
Outgoing #: 7
Introverted #: 6
Diff = 9359

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	int n;
	cin>>n;
	while(n--)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int a=accumulate(v.begin(),v.begin()+v.size()/2,0);
	int b=accumulate(v.begin()+v.size()/2,v.end(),0);
	if(v.size()%2==0)
	{
		cout<<"Outgoing #: "<<v.size()/2<<endl;
		cout<<"Introverted #: "<<v.size()/2<<endl;
		cout<<"Diff = "<<abs(a-b)<<endl;
	}
	else
	{
		cout<<"Outgoing #: "<<v.size()/2+1<<endl;
		cout<<"Introverted #: "<<v.size()/2<<endl;
		cout<<"Diff = "<<abs(a-b)<<endl;
	}
	return 0;
}
