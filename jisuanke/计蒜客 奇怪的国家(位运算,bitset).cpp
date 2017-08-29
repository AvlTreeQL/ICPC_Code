/*
有一个奇怪的国家，里面的国民对于事情的态度永远只有两面。当两个人遇到一起讨论一个事情的时候——两个持赞同观点的人遇到一起后会对这个事情都继续赞同；一个持赞同观点的人遇到一个持不赞同观点的人的时候，两人都会不再继续赞同；两个持不赞同观点的人遇到一起讨论后反而会对这个事情开始赞同。

输入格式

输入包括两行，每行包括 N(1≤N≤50) 个数字，分别表示两个人对于 NN 个事情对应的看法—0 表示不赞同、1 表示赞同。

输出格式

输出包括一行，包括 NN 个数字，表示两人相遇后，对于这 NN 件事情的最终看法。

样例输入

11100101
00101011
样例输出

00110001
*/
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#include<bitset>
using namespace std;
int main() {
//	freopen("intput.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	string aa, bb;
	cin >> aa >> bb;
	bitset<50> a(aa), b(bb);
	cout <<(~(a^b)).to_string().substr(50-aa.length(),aa.length()) << endl;
	return 0;
}
