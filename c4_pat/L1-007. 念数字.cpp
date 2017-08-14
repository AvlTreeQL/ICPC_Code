#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};
	string n;
	cin>>n;
	if(n[0]=='-') n[0]='0'+10;
	for(int i=0;i<n.size();i++)
	{
		if(i!=n.size()-1) cout<<s[n[i]-'0']<<' ';
		else cout<<s[n[i]-'0'];
	}

	return 0;
} 
/*
L1-007. 念数字
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
翁恺
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。十个数字对应的拼音如下：

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
输入格式：

输入在一行中给出一个整数，如： 1234 。

提示：整数包括负数、零和正数。

输出格式：

在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 yi er san si。

输入样例：
-600
输出样例：
fu liu ling ling

*/
