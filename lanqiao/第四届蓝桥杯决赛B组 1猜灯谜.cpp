/*


���⣺�µ���

    A ���Ԫ���ڵƻ�����һ���⣺

        ����� * ����� = ����͵Ʊ߲�
    
    С���룬һ����ÿ�����ִ���һ�����֣���ͬ�ĺ��ִ���ͬ�����֡�
    
    �����ü������С����˼·��һ�£�Ȼ���ύ������ա���������������������ɡ�

    ���ϸ��ո�ʽ��ͨ��������ύ�𰸡�
    ע�⣺ֻ�ύһ��3λ����������Ҫд�����������ݣ����磺˵���Ե����֡�
	answer: 897

#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=9;i>0;i--)
	{
		for(int j=9;j>=0;j--)
		{
			if(i==j) continue;
			for(int k=9;k>=0;k--)
			{
				if(j==k) continue;
				
				int a=i*100+j*10+k;
				long long b=a*a;
				if(b>=1000000) continue;
				string s;
				stringstream ss;
				ss<<b;
				ss>>s;
				if(s[0]==i+'0'&&s[1]==s[4]&&s[5]==j+'0')
				cout<<a<<' '<<a*a<<endl;
			}
			
		}
		
	}
	return 0;
} 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	for(int i=102;i<1000;i++) 
	{
		int sum=i*i;
		if(i*i<100000||i*i>999999) continue;
		string s1,s2;
		stringstream ss1,ss2;
		set<char> k;
		ss2<<sum;
		ss2>>s2;
		for(int j=0;j<6;j++)
		{
			k.insert(s2[j]);
		}
//		cout<<k.size()<<endl;
		if(k.size()!=5) continue;
		ss1<<i;
		ss1>>s1;
		if(s1[0]==s2[0]&&s2[1]==s2[4]&&s2[5]==s1[1])
		{
			cout<<i<<' '<<i*i<<endl<<endl;;
		}
		
	}
	return 0;
}

