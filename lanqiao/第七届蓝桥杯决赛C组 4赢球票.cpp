/*
赢球票

某机构举办球票大奖赛。获奖选手有机会赢得若干张球票。

主持人拿出 N 张卡片（上面写着 1~N 的数字），打乱顺序，排成一个圆圈。
你可以从任意一张卡片开始顺时针数数: 1,2,3.....
如果数到的数字刚好和卡片上的数字相同，则把该卡片收入囊中，从下一个卡片重新数数。
直到再无法收获任何卡片，游戏结束。囊中卡片数字的和就是赢得球票的张数。

比如：
卡片排列是：1 2 3
我们从1号卡开始数，就把1号卡拿走。再从2号卡开始，但数的数字无法与卡片对上，
很快数字越来越大，不可能再拿走卡片了。因此这次我们只赢得了1张球票。

还不算太坏！如果我们开始就傻傻地从2或3号卡片数起，那就一张卡片都拿不到了。

如果运气好，卡片排列是 2 1 3
那我们可以顺利拿到所有的卡片！

本题的目标就是：已知顺时针卡片序列。
随便你从哪里开始数，求最多能赢多少张球票（就是收入囊中的卡片数字之和）

输入数据：
第一行一个整数N(N<100)，表示卡片数目
第二行 N 个整数，表示顺时针排列的卡片

输出数据：
一行，一个整数，表示最好情况下能赢得多少张球票

比如：
用户输入：
3
1 2 3

程序应该输出：
1

比如：
用户输入：
3
2 1 3

程序应该输出：
6


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/ 
#include<bits/stdc++.h>
using namespace std;
int check(vector<int> v,int s,int max)
{
	vector<int>::iterator it,lt;
	it=lt=v.begin()+s; 
	int h=1,ans=0;
	while(1)
	{
		if(!v.size()) break;
//		cout<<h<<endl;
		if(h==*it)
		{
			ans+=*it;
			int temp=*it
			it=v.erase(it);
			
			if(temp==max)
			{
				max=*max_element(v.begin(),v.end());
			}
			
			h=0;
			
		}
		else 
		{
			if(h>max)	break;
			it++;
		}
		h++;
		if(it==v.end())
		{
			it=v.begin();

		}
		
	}

	return ans;
	
} 
int main()
{
	int n,max=-100000,maxn=-1000000,temp;
	cin>>n;
	vector<int> v;
	
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		if(v[i]>max) max=v[i];
	}
	for(int i=0;i<n;i++)
	{
		temp=check(v,i,max);
		if(temp>maxn) maxn=temp;
	}
	cout<<maxn<<endl;
	return 0;
}
