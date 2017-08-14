/*L3-015. ��ӡ�ʳ������

ĳ����������������N֧������ӣ���Ŵ�1��N��
�����������ͳ�˫ѭ�����ƣ������������֮����˫����������һ����
����ս�գ�����Ѿ������䶨��
��ʱ��������ϯͻ�����룬ϣ�������ҳ�һ������������ӵġ�ʳ����������˵�������ľ��ʳ̶ȡ�
��ʳ������Ϊһ��1��N������{ T1 T2 ... TN }�����㣺���T1սʤ�����T2�����T2սʤ�����T3�����������T(N-1)սʤ�����TN�����TNսʤ�����T1��
������ϯ���������������ҳ���ʳ�������������ڶ�����ʳ�����������ҳ��ֵ�����С�ġ�

ע������{ a1 a2 ...aN }���ֵ�����С������{ b1 b2 ... bN }�����ҽ�����������K��1 <= K <= N�������㣺aK < bK�Ҷ�������С��K��������i��ai=bi��

�����ʽ��

�����һ�и���һ������N��2 <= N <= 20����Ϊ�����������
���N�У�ÿ��N���ַ���������NxN�����������
���е�i�е�j�е��ַ�Ϊ���i�������������j�ı��������
��W����ʾ���iսʤ���j����L����ʾ���i�������j����D����ʾ���Ӵ�ƽ����-����ʾ��Ч����i=jʱ�����������޶���ո�

�����ʽ��

����ĿҪ���ҵ���ʳ������T1 T2 ... TN������N�������������һ���ϣ����ּ���1���ո�ָ����е���β�����ж���ո�
�������ڡ�ʳ�������������No Solution����

��������1��
5
-LWDW
W-LDW
WW-LW
DWW-W
DDLW-
�������1��
1 3 5 4 2
��������2��
5
-WDDW
D-DWL
DD-DW
DDW-D
DDDD-
�������2��
No Solution
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int *a,n;
int flag=0;
void dfs(int num,int deep)
{
	if(flag==1) return;
	a[deep]=num;
	if(deep==n-1&&find(v[num].begin(),v[num].end(),a[0])!=v[num].end())
	{
		cout<<a[0]+1;
		for(int i=1;i<n;i++)
		{
			cout<<' '<<a[i]+1;
		}
		flag=1;
		return ;
	}
	for(int i=0;i<v[num].size();i++)
	{
		if(find(a,a+deep,v[num][i])==a+deep) 
		{
			dfs(v[num][i],deep+1);
		}
	}
	
}
int main()
{
	
	char c;	
	cin>>n;
	a=new int[n];
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c;
			if(c=='L') v[j].push_back(i);
			else if(c=='W') v[i].push_back(j);
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(int i=0;i<n;i++)
	{	for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]+1<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<v[0].size();i++)
	{
		a[0]=0;
		dfs(v[0][i],1);
	}
	if(flag==0) cout<<"No Solution";
	return 0;
}

