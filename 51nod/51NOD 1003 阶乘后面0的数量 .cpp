/*
n的阶乘后面有多少个0？ 
6的阶乘 = 1*2*3*4*5*6 = 720，720后面有1个0。 
  
	Input一个数N(1 <= N <= 10^9)Output输出0的数量
	Sample Input
	5
	Sample Output
	1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long  n,sum=0,k=5;  
	cin>>n;  
	while(n>=k)
	{  
		sum+=n/k;  
		k*=5;  
	}
	cout<<sum<<endl;    

	return 0;
}
