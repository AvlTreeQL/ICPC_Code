#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j=0,flag=0;;
	long long *a;
	cin>>n;
	a=new long long[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;a[i]<=0;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(find(a,a+n,abs(a[i]+a[j]))!=a+n&&a[j]<abs(a[i]+a[j]))
			{
				cout<<a[i]<<' '<<a[j]<<' '<<abs(a[i]+a[j])<<endl;
				flag=1;
			}
		}
	} 
	if(flag==0) cout<<"No Solution"<<endl;
	return 0;
}
/*
给出一个长度为N的无序数组，数组中的元素为整数，有正有负包括0，并互不相等。从中找出所有和 = 0的3个数的组合。如果没有这样的组合，输出No Solution。如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则按照第二小的数排序。
Input
第1行，1个数N，N为数组的长度(0 <= N <= 1000)
第2 - N + 1行：A[i]（-10^9 <= A[i] <= 10^9)
Output
如果没有符合条件的组合，输出No Solution。
如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则继续按照第二小的数排序。每行3个数，中间用空格分隔，并且这3个数按照从小到大的顺序排列。
Input示例
7
-3
-2
-1
0
1
2
3
Output示例
-3 0 3
-3 1 2
-2 -1 3
-2 0 2
-1 0 1
*/
