/*

����һ��ʮ����������N��д�´�1��ʼ����N��������������������г�������1�ĸ�����


���磺n = 12��������5��1��1,10,12������3��1��11����2��1���ܹ�5��1��



Input
����N(1 <= N <= 10^9)

Output
�������1�ĸ���

Inputʾ��
12

Outputʾ��
5
*/
#include<bits/stdc++.h>
using namespace std;
long fun(int x)
{
	int sum=0;
	while(x)
	{
		if(x%10==1) sum++;
		x/=10;
	}
	return sum;
}
int main()
{
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum+=fun(i);
	}               
	cout<<sum<<endl;                                                                                                                                                                        
	return 0;
}
