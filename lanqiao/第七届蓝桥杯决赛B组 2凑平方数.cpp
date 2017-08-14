/*

凑平方数

把0~9这10个数字，分成多个组，每个组恰好是一个平方数，这是能够办到的。
比如：0, 36, 5948721

再比如：
1098524736
1, 25, 6390784
0, 4, 289, 15376
等等...

注意，0可以作为独立的数字，但不能作为多位数字的开始。
分组时，必须用完所有的数字，不能重复，不能遗漏。

如果不计较小组内数据的先后顺序，请问有多少种不同的分组方案？

注意：需要提交的是一个整数，不要填写多余内容。
answer:300

*/
#include <bits/stdc++.h>
using namespace std;
int a[]={0,1,2,3,4,5,6,7,8,9};
long long b[10];
long long c[10];
set<string> k;
void dfs(int deep,int num)
{
	if(deep==10)
	{
		memcpy(c,b,sizeof(b));
		sort(c,c+num);
		stringstream ss;
		string s,temp;
		for(int i=0;i<num;i++)
		{
			ss<<c[i];
			ss>>temp;
			s+='.';
			s+=temp;
			ss.clear();
		}
//		cout<<s<<endl;
//		system("pause");
		k.insert(s);
		return ;
	}
	if(a[deep]==0)
	{
		b[num]=0;
		dfs(deep+1,num+1);
	}
	else
	{
		long long sum=0;
		for(int i=deep;i<10;i++)
		{
			sum=sum*10+a[i];
			double son=sqrt(sum);
			if(son==(long long)son)
			{
				b[num]=sum;
				dfs(i+1,num+1);
		
			}
		}
	}
}
int main()
{
    do
    {
    	memset(b,0,sizeof(b));
    	dfs(0,0);
    }while(next_permutation(a,a+10));
    cout<<k.size()<<endl;
    return 0;
}

