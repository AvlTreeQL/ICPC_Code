/*
L2-024. ����
��һ�������ÿ���˶����Լ���СȦ�ӣ�������ͬʱ���ںܶ಻ͬ������Ȧ��������Ϊ���ѵ����Ѷ�����һ�����������Ҫ����ͳ��һ�£���һ�����������У������ж��ٸ������ཻ�Ĳ��䣿���Ҽ�������������Ƿ�����ͬһ�����䡣

�����ʽ��

�����ڵ�һ�и���һ��������N��<= 104��������֪СȦ�ӵĸ��������N�У�ÿ�а����и�ʽ����һ��СȦ������ˣ�

K P[1] P[2] ... P[K]

����K��СȦ�����������P[i]��i=1, .., K����СȦ����ÿ���˵ı�š����������˵ı�Ŵ�1��ʼ������ţ�����Ų��ᳬ��104��

֮��һ�и���һ���Ǹ�����Q��<= 104�����ǲ�ѯ���������Q�У�ÿ�и���һ�Ա���ѯ���˵ı�š�

�����ʽ��

������һ�������������������������Լ������ཻ�Ĳ���ĸ���������ÿһ�β�ѯ�������������ͬһ�����䣬����һ���������Y�������������N����

����������
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
���������
10 2
Y
N
*/
#include<bits/stdc++.h>
using namespace std;
int f[10010];
void init()
{
	for(int i=0;i<=10010;i++)
	{
		f[i]=i;
	}
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void cmb(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a<b) f[b]=a;
	else f[a]=b;
}
int sum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i) sum++;
	}
	return sum;
}
int main()
{
	int n;
	set<int> k;
	init();
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		int p;
		cin>>p;
		k.insert(p);
		while(--num)
		{
			int t;
			cin>>t;
			k.insert(t);
			cmb(p,t);
		}
	}
	cout<<k.size()<<' '<<sum(k.size())<<endl;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b)) cout<<'Y'<<endl;
		else cout<<'N'<<endl; 
	}
	return 0;
} 
