/*

���÷�

���濼��һ���෴�����⡣
�ɲ������� 1~9 ����������Ź���
ʹ�ã�ÿ��ÿ��ÿ���Խ����ϵ����ֺͶ���������أ�


�ҹ��ż�����ͼ�����

2 9 4
7 5 3
6 1 8

����һ�����׻÷���ÿ��ÿ���Լ��Խ����ϵ�������Ӷ���ȡ�

��Ӧ����������
���磺
9 1 2
8 4 3
7 5 6

����������������е����׷��÷�����ͳ�Ƴ�һ���ж����֡�
��ת������ͬһ�֡�

���磺
9 1 2
8 4 3
7 5 6

7 8 9
5 4 1
6 3 2

2 1 9
3 4 8
6 5 7

�ȶ�����ͬһ�������

���ύ���׷��÷�һ�������֡�����һ����������Ҫ��д�κζ������ݡ�
answea: 3120

*/
#include<bits/stdc++.h>
using namespace std;
bool visit[10];
int sum=0;
int a[][3]={1,2,3,4,5,6,7,8,9};
void check()
{
	int s[3]={0,0,0},l[3]={0,0,0};
	set<int> k;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			s[i]+=a[i][j];
			l[i]+=a[j][i];
		}
		k.insert(s[i]);
		k.insert(l[i]);
	}
	int t=a[0][0]+a[1][1]+a[2][2];
	int p=a[0][2]+a[1][1]+a[2][0];
	k.insert(t);
	k.insert(p);
	if(k.size()==8) sum++;
}
void dfs(int a[],int x)
{
	if(x==9)
	{
		check();
		return ;
	}
	for(int i=1;i<10;i++)
	{
		if(!visit[i])
		{
			a[x]=i;
			visit[i]=true;
			dfs(a,x+1);
			visit[i]=false;
		}
	}
}
int main()
{
	dfs(*a,0);
	if(sum)cout<<sum/8<<endl;
	return 0;
}
