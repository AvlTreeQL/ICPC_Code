/*
���⣺ k������

����һ������ΪN�����У�A1, A2, ... AN���������һ��������������Ai, Ai+1, ... Aj(i <= j)֮����K�ı��������Ǿͳ��������[i, j]��K�����䡣  

��������������ܹ��ж��ٸ�K��������  

����
-----
��һ�а�����������N��K��(1 <= N, K <= 100000)  
����N��ÿ�а���һ������Ai��(1 <= Ai <= 100000)  

���
-----
���һ������������K���������Ŀ��  


���磬
���룺
5 2
1  
2  
3  
4  
5  

����Ӧ�������
6

��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 2000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

ע�⣺
main������Ҫ����0;
ֻʹ��ANSI C/ANSI C++ ��׼;
��Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
���������ĺ���������ȷ����Դ�ļ��� #include <xxx>
����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύ����ʱ��ע��ѡ�����������������ͺͱ��������͡�
*/
#include<iostream>
#include<string>
#include<cstring>
#include<set> 
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip> 
#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	vector<int> v;
	vector<int> sum;
	cin>>n>>k;
	v.resize(n);
	sum.resize(n);
	cin>>v[0];
	sum[0]=v[0];
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
		sum[i]=sum[i-1]+v[i];
	}
	int num=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if((sum[j]-sum[i]+v[i])%k==0)
			{
				num++;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
