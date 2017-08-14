#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	int i=0,sum=0,t;
	cin>>a;
	for(i=0;i<10;i++)
	{
		t=count(&a[0],&a[a.size()-1],char(i+'0'));
		if(t!=0) cout<<i<<':'<<t<<endl;
	}		
	return 0; 
} 
