/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。  

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。  

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)  

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。  

59/12/31 
样例输入
----
02/03/04  

样例输出
----
2002-03-04  
2004-02-03  
2004-03-02  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

#include<iostream>
#include<string>
#include<cstring>
#include<set> 
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip> 
#include<cstdio>
using namespace std;
class node
{
public:
	int y;
	int m;
	int d;
	node(int a,int b,int c)
	{
		y=a;
		m=b;
		d=c;
	}
	bool operator <(const node &b) const
	{
		if(y==b.y)
		{
			if(m==b.m)
				return d<b.d;
			else
				return m<b.m;
		}
		else 
			return y<b.y;
	}
};
set<node> v;
set<node>::iterator it;
void fun(int y,int m,int d)
{
	if(y<60) y+=2000;
	else y+=1900;
	int mm[13];
	mm[1]=mm[3]=mm[5]=mm[7]=mm[8]=mm[10]=mm[12]=31;
	mm[4]=mm[6]=mm[9]=mm[11]=30;
	if(y%4==0&&y%100!=0||y%400==0)
		mm[2]=29;
	else mm[2]=28;
	if(m<=12&&m>=0&&d<=mm[m]&&d>=0)
		v.insert(node(y,m,d));
}
int main()
{
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	fun(a,b,c); //有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
	fun(c,a,b);
	fun(c,b,a);

	for(it=v.begin();it!=v.end();it++)
	{
		printf("%d-%02d-%02d\n",it->y,it->m,it->d);
	}
	return 0;
}   

