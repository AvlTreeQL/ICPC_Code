#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	string s;
	cin>>s;
	a=count(&s[0],&s[s.size()],'G');
	a+=count(&s[0],&s[s.size()],'g');
	b=count(&s[0],&s[s.size()],'P');
	b+=count(&s[0],&s[s.size()],'p');
	c=count(&s[0],&s[s.size()],'L');
	c+=count(&s[0],&s[s.size()],'l');
	d=count(&s[0],&s[s.size()],'T');
	d+=count(&s[0],&s[s.size()],'t');
	while(!(a==0&&b==0&&c==0&&d==0))
	{
		if(a!=0) 
		{
			cout<<'G';
			a--;
		}
		if(b!=0) 
		{
			cout<<'P';
			b--;
		}
		if(c!=0) 
		{
			cout<<'L';
			c--;
		}
		if(d!=0) 
		{
			cout<<'T';
			d--;
		}
	}
	return 0;
}
/*
L1-023. 输出GPLT
时间限制
150 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“GPLTGPLT....”这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
GPLTGPLTGLTGLGLL
*/
