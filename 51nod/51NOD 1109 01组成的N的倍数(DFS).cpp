/*
1109 01��ɵ�N�ı���
��׼ʱ�����ƣ�1 �� �ռ����ƣ�131072 KB ��ֵ: 40 �Ѷȣ�4���㷨�� �ղ�  ��ע
����һ����Ȼ��N���ҳ�һ��M��ʹ��M > 0��M��N�ı���������M��10���Ʊ�ʾֻ����0��1������С��M��
���磺N = 4��M = 100��
Input
����1����N��(1 <= N <= 10^6)
Output
���������������С��M��
Inputʾ��
4
Outputʾ��
100
*/
#include<iostream>
#include<sstream>
using namespace std;
bool flag;
unsigned long long MIN=10000000000000000009;
void DFS(unsigned long long x,int n)
{
	if(x>=10000000000000000000) return ;
	if(x%n==0&&x<MIN)
	{
		MIN=x;
		return ;
	}
	DFS(x*10,n);
	DFS(x*10+1,n);	
}
int main()
{
	int n;
	cin>>n;
	flag=false;
	DFS(1,n);
	cout<<MIN<<endl;
	return 0;
}
