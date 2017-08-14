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
		/*	int pa0=find(0),ans=1;  //查找0所在的集合
        for(i=1; i<n; i++)
            if(pa0==find(i))
                ans++;
        cout<<ans<<endl;*/
	}
	return 0; 
} 

/*
描述

严重急性呼吸综合征（SARS）是一种未知病因的非典型肺炎，在2003年3月中旬被确认为全球性威胁。为了尽量减少对他人的传播，最好的策略是将嫌疑人与他人分开。
在不传播病态大学（NSYSU），有很多学生组。同一组中的学生经常互相沟通，学生可以加入几个小组。为了防止可能的SARS传输，NSYSU收集所有学生组的成员列表，并在其标准操作过程（SOP）中制定以下规则。
一旦群组中的成员是可疑人员，群组中的所有成员都是可疑人员。
然而，他们发现，当学生被认定为嫌疑犯时，识别所有嫌疑犯并不容易。
 

输入

输入文件包含多种情况。每个测试用例以一个行中的两个整数n和m开始，其中n是学生的数量，m是组的数量。
您可以假设0 <n <= 30000和0 <= m <= 500。每个学生都使用0和n-1之间的唯一整数进行编号，最初学生0在所有情况下都被识别为可疑人员。
此行后面是组的m个成员列表，每个组一行。每行以一个整数k开始，它表示组中的成员数。按照成员数量，有k个整数表示该组中的学生。一行中的所有整数至少由一个空格分隔。
n = 0和m = 0的情况表示输入的结束，不需要处理。
 

输出

对于每种情况，输出一行中的可疑人数。
 

样品输入

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2

200 2
1 5
5 1 2 3 4 5
1 0

0 0空值
 

示例输出

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

