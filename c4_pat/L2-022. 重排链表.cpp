/*
L2-022. 重排链表

给定一个单链表 L1→L2→...→Ln-1→Ln，请编写程序将链表重新排列为 Ln→L1→Ln-1→L2→...。例如：给定L为1→2→3→4→5→6，则输出应该为6→1→5→2→4→3。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址和结点总个数，即正整数N (<= 105)。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址；Data是该结点保存的数据，为不超过105的正整数；Next是下一结点的地址。题目保证给出的链表上至少有两个结点。

输出格式：

对每个测试用例，顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1

00 3
00 1 01
01 2 02
02 3 -1
03 3 00
00 1
 0 01
01 2
 0 02
02 0 -1
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int> key;
	map<string,string> next;
	map<string,string> last;
	string s,h,t;
	int n;
	cin>>s>>n;
	int pp=n;
	while(n--)
	{
		string h,t;
		int k;
		cin>>h>>k>>t;
		key[h]=k;
		next[h]=t;
		last[t]=h;
	}
	h=s;
	t="-1";
	cout<<last[t]<<' '<<key[last[t]]<<' ';
	t=last[t];
	for(int i=0;i<pp/2;h=next[h],t=last[t],i++)
	{
		cout<<h<<endl<<h<<' '<<key[h]<<' ';
		if(next[h]==t) break;
		cout<<last[t]<<endl<<last[t]<<' '<<key[last[t]]<<' ';
	}
	cout<<"-1";
	return 0;
}
