/*
���罻����ƽ̨ע��ʱ���û�ͨ���������Լ�����Ȥ���ã��Ա��ҵ����Լ���Ȥ��Ͷ�����ѡ�
�в�����Ȥ��ͬ�����Ǿ��γ��ˡ��罻��Ⱥ�����������д�����ҳ����еļ�Ⱥ��

�����ʽ��

����ĵ�һ�и���������N��<=1000�������罻�����е��û����������û���1��N��ţ���
���N�У�ÿ�а����и�ʽ�г�ÿ���˵���Ȥ���ã�

Ki: hi[1] hi[2] ... hi[Ki]

����Ki��>0���ǵ�i���˵���Ȥ��������hi[j]�ǵ�i���˵ĵ�j����Ȥ�ı�ţ���ŷ�ΧΪ[1, 1000]�ڵ�������

�����ʽ��

�����ڵ�һ��������������м�Ⱥ��������Ȼ���ڵڶ��а��ǵ�����˳�����ÿ����Ⱥ���û������������ּ���1���ո�ָ�������β�����ж���ո�

����������
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
���������
3
4 3 1
*/

#include<bits/stdc++.h>
using namespace std;
int f[1010]={0},n;
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void cmb(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x<y) f[y]=x;
	else f[x]=y;
}
void init()
{
	for(int i=0;i<1010;i++)
	{
		f[i]=i;
	}
}
int cmp(const int x,const int y)
{
	if(x>y) return 1;
	else return 0;
}
int main()
{
	int c[1000]={0},sum=0,num[1010]={0};
	cin>>n;
	init();
	for(int i=0;i<n;i++)
	{
		int t,p;
		char u;
		cin>>t>>u>>c[i];
		for(int j=1;j<t;j++)
		{
			cin>>p;
			cmb(c[i],p);
		}
	}
	for(int i=0;i<n;i++)
	{
		num[find(c[i])]++;
	}
	for(int i=0;i<1010;i++)
	{
		if(num[i]) sum++;
	} 
	sort(num,num+1010,greater<int>());
	cout<<sum<<endl<<num[0];
	for(int i=1;i<sum;i++)
	{
		cout<<' '<<num[i];
	}

	return 0;
}
