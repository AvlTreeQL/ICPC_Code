/*


标题：猜灯谜

    A 村的元宵节灯会上有一迷题：

        请猜谜 * 请猜谜 = 请边赏灯边猜
    
    小明想，一定是每个汉字代表一个数字，不同的汉字代表不同的数字。
    
    请你用计算机按小明的思路算一下，然后提交“请猜谜”三个字所代表的整数即可。

    请严格按照格式，通过浏览器提交答案。
    注意：只提交一个3位的整数，不要写其它附加内容，比如：说明性的文字。
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

