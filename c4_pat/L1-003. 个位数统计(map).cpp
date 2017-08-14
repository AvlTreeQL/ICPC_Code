#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string s;
	map<char,int> k;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		k[s[i]]++;
	}
	for(int i=0;i<10;i++)
	{
		if(k[i+'0']!=0)
		cout<<i<<':'<<k[i+'0']<<endl;
	}
	return 0;
}
