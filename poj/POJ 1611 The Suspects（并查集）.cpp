#include<iostream>
#include<cstring>
using namespace std;
//int n,m,*f,*g;
int n,m,f[31000];
//,g[31000];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void inti(int *f)
{
	int i;
	for(i=0;i<n;i++)
	{
		f[i]=i;
	} 
} 
void unin(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x>y) f[x]=y;
	else f[y]=x;
/*	if(g[x] > g[y])
        f[y] = x;
    else
    {
        f[x] = y;
        if(g[x] == g[y])
            g[y]++;
    }
    */
}
int main()
{
	int i,j,p,q;
//	f=new int[n];
	while(1)
	{
	
		cin>>n>>m;
		if(n==0&&m==0) break;
//		f=new int[n];
//		g=new int[n];
		memset(f,0,sizeof(int)*n);
//		memset(g,0,sizeof(int)*n);
		inti(f);
		for(i=0;i<m;i++)
		{
			int t;
			cin>>t;
			cin>>p;
			for(j=0;j<t-1;j++)
			{
				cin>>q;
				unin(p,q);
			}	
		}
		int p=find(0),sum=1;
		for(i=1;i<n;i++)
		{
			if(find(i)==p)
				sum++;
		}
		cout<<sum<<endl;
		/*	int pa0=find(0),ans=1;  //����0���ڵļ���
        for(i=1; i<n; i++)
            if(pa0==find(i))
                ans++;
        cout<<ans<<endl;*/
	}
	return 0; 
} 

/*
����

���ؼ��Ժ����ۺ�����SARS����һ��δ֪����ķǵ��ͷ��ף���2003��3����Ѯ��ȷ��Ϊȫ������в��Ϊ�˾������ٶ����˵Ĵ�������õĲ����ǽ������������˷ֿ���
�ڲ�������̬��ѧ��NSYSU�����кܶ�ѧ���顣ͬһ���е�ѧ���������๵ͨ��ѧ�����Լ��뼸��С�顣Ϊ�˷�ֹ���ܵ�SARS���䣬NSYSU�ռ�����ѧ����ĳ�Ա�б��������׼�������̣�SOP�����ƶ����¹���
һ��Ⱥ���еĳ�Ա�ǿ�����Ա��Ⱥ���е����г�Ա���ǿ�����Ա��
Ȼ�������Ƿ��֣���ѧ�����϶�Ϊ���ɷ�ʱ��ʶ���������ɷ��������ס�
 

����

�����ļ��������������ÿ������������һ�����е���������n��m��ʼ������n��ѧ����������m�����������
�����Լ���0 <n <= 30000��0 <= m <= 500��ÿ��ѧ����ʹ��0��n-1֮���Ψһ�������б�ţ����ѧ��0����������¶���ʶ��Ϊ������Ա��
���к��������m����Ա�б�ÿ����һ�С�ÿ����һ������k��ʼ������ʾ���еĳ�Ա�������ճ�Ա��������k��������ʾ�����е�ѧ����һ���е���������������һ���ո�ָ���
n = 0��m = 0�������ʾ����Ľ���������Ҫ����
 

���

����ÿ����������һ���еĿ���������
 

��Ʒ����

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2

200 2
1 5
5 1 2 3 4 5
1 0

0 0��ֵ
 

ʾ�����

4
1
1
#include<iostream>
using namespace std;
int f[31000];
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
		f[i]=i;
}
int find(int n)
{
	if(f[n]==n) return n;
	else return f[n]=find(f[n]);
}
void cmb(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a>b) f[a]=b;
	else f[b]=a;
}
int main()
{
	int n,m,t,p,q;
	while(1)
	{
		
		cin>>n>>m;
//		f=new int[n];
		init(n);
		if(n==0&&m==0) break;
		for(int i=0;i<m;i++)
		{
			cin>>t;
			cin>>p;
			for(int j=1;j<t;j++)
			{
				cin>>q;
				cmb(p,q);
			}
			
		}
		int t1=find(0),sum=0;
		for(int i=0;i<n;i++)
		{
			if(find(i)==t1) sum++;
		}
		cout<<sum<<endl; 
	}
	return 0;
} 
*/

