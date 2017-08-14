/*
标题：填算式

    请看下面的算式：

    (ABCD - EFGH) * XY = 900

    每个字母代表一个0~9的数字，不同字母代表不同数字，首位不能为0。

    比如，(5012 - 4987) * 36 就是一个解。

    请找到另一个解，并提交该解中 ABCD 所代表的整数。

    请严格按照格式，通过浏览器提交答案。
    注意：只提交 ABCD 所代表的整数，不要写其它附加内容，比如：说明性的文字。
    
7153 6928 4
6048 5973 12
5012 4987 36

6048
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
#include<bits/stdc++.h>
using namespace std;
bool visit[10];
void check(int s[])
{
	int a=s[0]*1000+s[1]*100+s[2]*10+s[3];
	int b=s[4]*1000+s[5]*100+s[6]*10+s[7];
	int c=s[8]*10+s[9];
	if((a-b)*c==900)
	{
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
}
void dfs(int s[],int deep)
{
	if(deep==10)
	{
		check(s);
		return ;
	}
	for(int i=0;i<10;i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			s[deep]=i;
			dfs(s,deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	int s[10];
	dfs(s,0);
	return 0;
} 

