/*
有这样一段程序，fun会对整数数组A进行求值，其中Floor表示向下取整：
fun(A)

    sum = 0

    for i = 1 to A.length

        for j = i+1 to A.length

            sum = sum + Floor((A[i]+A[j])/(A[i]*A[j])) 

    return sum




给出数组A，由你来计算fun(A)的结果。例如：A = {1, 4, 1}，fun(A) = [5/4] + [2/1] + [5/4] = 1 + 2 + 1 = 4。



Input
第1行：1个数N，表示数组A的长度(1 <= N <= 100000)。
第2 - N + 1行：每行1个数A[i]（1 <= A[i] <= 10^9)。

Output
输出fun(A)的计算结果。

Input示例
3
1 4 1

Output示例
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
