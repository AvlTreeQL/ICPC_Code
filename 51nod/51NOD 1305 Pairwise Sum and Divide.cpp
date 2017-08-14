/*
������һ�γ���fun�����������A������ֵ������Floor��ʾ����ȡ����
fun(A)

    sum = 0

    for i = 1 to A.length

        for j = i+1 to A.length

            sum = sum + Floor((A[i]+A[j])/(A[i]*A[j])) 

    return sum




��������A������������fun(A)�Ľ�������磺A = {1, 4, 1}��fun(A) = [5/4] + [2/1] + [5/4] = 1 + 2 + 1 = 4��



Input
��1�У�1����N����ʾ����A�ĳ���(1 <= N <= 100000)��
��2 - N + 1�У�ÿ��1����A[i]��1 <= A[i] <= 10^9)��

Output
���fun(A)�ļ�������

Inputʾ��
3
1 4 1

Outputʾ��
4

*/
#include<bits/stdc++.h>
using namespace std;
long long fun(vector<long long> a)
{
	long long sum=0;
	sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
	{
		if(a[i]>2) break; 
		for(int j=i+1;j<a.size();j++)
		{ 
			sum+=(a[i]+a[j])/(a[i]*a[j]);
		}
	}
	return sum;
}
int main()
{
	vector<long long> a;
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<fun(a)<<endl;
	return 0;
}
