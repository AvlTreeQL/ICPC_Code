/*
标题：排列序数

   如果用a b c d这4个字母组成一个串，有4!=24种，如果把它们排个序，每个串都对应一个序号：
  abcd  0
  abdc  1
  acbd  2
  acdb  3
  adbc  4
  adcb  5
  bacd  6
  badc  7
  bcad  8
  bcda  9
  bdac  10
  bdca  11
  cabd  12
  cadb  13
  cbad  14
  cbda  15
  cdab  16
  cdba  17
  ...

    现在有不多于10个两两不同的小写字母，给出它们组成的串，你能求出该串在所有排列中的序号吗？

【输入格式】
一行，一个串。

【输出格式】
一行，一个整数，表示该串在其字母所有排列生成的串中的序号。注意：最小的序号是0。

例如：
输入：
bdca

程序应该输出：
11

再例如：
输入：
cedab

程序应该输出：
70

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
long long fun(int n)
{
	int i;
	long long sum=1;
	for(i=2;i<=n;i++)
		sum*=i;
	return sum;
}
int main()
{
	string s;
	cin>>s;
	long long sum=0;
	for(int i=0;i<s.size();i++)
	{
		int t=0;
		for(int j=i+1;j<s.size();j++)
		{
			if(s[j]<s[i]) t++;
		}
		sum+=t*fun(s.size()-i-1);
	}
	cout<<sum<<endl;
	return 0;
} 
