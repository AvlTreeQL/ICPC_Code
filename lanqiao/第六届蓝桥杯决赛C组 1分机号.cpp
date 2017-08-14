/*

标题：分机号

X老板脾气古怪，他们公司的电话分机号都是3位数，老板规定，所有号码必须是降序排列，且不能有重复的数位。比如：

751,520,321 都满足要求，而，
766,918,201 就不符合要求。

现在请你计算一下，按照这样的规定，一共有多少个可用的3位分机号码？

请直接提交该数字，不要填写任何多余的内容。
answer:120
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int> v;
	int sum=0;
	for(int i=9;i>=2;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			for(int k=j-1;k>=0;k--)
			{
				v.insert(i*100+j*10+k);
				sum++;
				cout<<i*100+j*10+k<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<v.size()<<' '<<sum<<endl;
	return 0;
} 

