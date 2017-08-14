/*
天梯图书阅览室请你编写一个简单的图书借阅统计程序。
当读者借书时，管理员输入书号并按下S键，程序开始计时；当读者还书时，管理员输入书号并按下E键，程序结束计时。
书号为不超过1000的正整数。
当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。

注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，系统应能自动忽略这种无效纪录。
另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。

输入格式：

输入在第一行给出一个正整数N（<= 10），随后给出N天的纪录。
每天的纪录由若干次借阅操作组成，每次操作占一行，格式为：

书号（[1, 1000]内的整数） 键值（“S”或“E”） 发生时间（hh:mm，其中hh是[0,23]内的整数，mm是[0, 59]内整数）

每一天的纪录保证按时间递增的顺序给出。

输出格式：

对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。

输入样例：
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
输出样例：
2 196
0 0
1 60
*/
#include<bits/stdc++.h>
using namespace std;
int fun(int h1,int m1,int h2,int m2)
{
	int time=0;
	time+=(h1-h2)*60;
	time+=m1-m2;
	return time;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		map<string,int> h1,m1,h2,m2;
		char c,t;
		string ss;
		set<string> sm,st;
		set<string>::iterator it;
		long sum=0;
		double time=0;		
		while(1)
		{
			int h,m;
			cin>>ss>>c>>h>>t>>m;
			if(ss=="0") break;
			
			if(c=='S')
			{
				h1[ss]=h;
				m1[ss]=m;
				sm.insert(ss);
			}
			else if(c=='E'&&sm.find(ss)!=sm.end())
			{
				sum++;
				st.insert(ss);
				h2[ss]=h;
				m2[ss]=m;
			}
			
		}
		for(it=st.begin();it!=st.end();it++)
		{
			string ss=*it;
			
				time+=fun(h2[ss],m2[ss],h1[ss],m1[ss]);
			
		}
		if(sum>0)printf("%ld %.0lf\n",sum,time/sum);
		else cout<<0<<' '<<0<<endl;
		sm.clear(); 
	}
	return 0;
}
