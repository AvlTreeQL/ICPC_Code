/*
ѧ��������ҵ�ļ򵥹������������ģ�ÿ���˵���ҵ�ᱻk��ͬѧ���󣬵õ�k���ɼ���
ϵͳ��Ҫȥ��һ����߷ֺ�һ����ͷ֣���ʣ�µķ���ȡƽ�����͵õ����ѧ�������ɼ���
�����Ҫ�����д�������ϵͳ�����ģ�顣

�����ʽ��

�����һ�и���3��������N��3< N <= 104��ѧ����������k��3<= k <= 10��ÿ����ҵ������������M��<= 20����Ҫ�����ѧ��������
���N�У�ÿ�и���һ����ҵ�õ���k������ɼ���������[0, 100]�ڣ�������Կո�ָ���

�����ʽ��

���ǵݼ�˳��������÷���ߵ�M���ɼ�������С�����3λ����������1���ո�����β�����ж���ո�

����������
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
���������
87.667 88.000 96.000
*/
#include<bits/stdc++.h>
using namespace std;
struct cmp
{
	bool operator()(const double&a,const double &b)
	{
		return a>b;
	}
};
int main()
{
	int n,k,m;
	vector<vector<int> > v;
	vector<double> s;
	cin>>n>>k>>m;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int t;
			cin>>t;
			v[i].push_back(t);
		}
		sort(v[i].begin(),v[i].end());
		s.push_back((double)accumulate(v[i].begin()+1,v[i].end()-1,0)/(k-2));
	}
	sort(s.begin(),s.end());
	vector<double>::iterator it=s.end()-m;
	cout<<fixed<<setprecision(3)<<*(it);
	while(--m)
	{
		it++;
		cout<<fixed<<setprecision(3)<<' '<<*(it);
	}
	return 0;
}
