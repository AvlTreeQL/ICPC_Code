/*
n�Ľ׳˺����ж��ٸ�0�� 
6�Ľ׳� = 1*2*3*4*5*6 = 720��720������1��0�� 
  
	Inputһ����N(1 <= N <= 10^9)Output���0������
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
