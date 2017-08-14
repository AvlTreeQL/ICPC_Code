#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void fun1(long &a,long &b)
{
	long i;
	for(i=2;i<=sqrt(abs(a))||i<=sqrt(abs(b));i++)
	{
		while(a%i==0&&b%i==0)
			a/=i,b/=i;
	}
}
void fun(long a,long b,long &fz,long &fm)
{
	if(b!=fm)
	{
		a*=fm;
		fm*=b;
		fz*=b;
		fz+=a;
	}
	else
	{
		fz+=a;
	}
}

int main()
{
	long n,a,b,fz,fm,i;
	cin>>n;
	scanf("%ld/%ld",&fz,&fm);
	for(i=1;i<n;i++)
	{
		scanf("%ld/%ld",&a,&b);
		fun1(a,b);
		fun(a,b,fz,fm);	
		if(abs(fz)>1000||fz>1000)fun1(fz,fm);
	}
	for(i=2;i<=abs(fz)||i<=abs(fm);i++)
	{
		while(fz%i==0&&fm%i==0)
			fm/=i,fz/=i;
	}
	if(fz%fm==0) cout<<fz/fm<<endl;
	else if(abs(fz)>fm) cout<<fz/fm<<' '<<fz%fm<<'/'<<fm<<endl;
	else cout<<fz<<'/'<<fm<<endl;
	return 0;
}
/*
 L1-009. N个数求和
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数“分子/分母”的形式给出的，你输出的和也必须是有理数的形式。

输入格式：

输入第一行给出一个正整数N（<=100）。随后一行按格式“a1/b1 a2/b2 ...”给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：

输出上述数字和的最简形式 —— 即将结果写成“整数部分 分数部分”，其中分数部分写成“分子/分母”，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24
 */
