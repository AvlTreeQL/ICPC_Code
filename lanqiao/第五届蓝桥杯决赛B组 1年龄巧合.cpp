/*

标题：年龄巧合

    小明和他的表弟一起去看电影，有人问他们的年龄。
	小明说：今年是我们的幸运年啊。
	我出生年份的四位数字加起来刚好是我的年龄。
	表弟的也是如此。已知今年是2014年，并且，小明说的年龄指的是周岁。

    请推断并填写出小明的出生年份。

    这是一个4位整数，请通过浏览器提交答案，不要填写任何多余的内容（比如，他表弟的出生年份，或是他们的年龄等等）
    
    answer:1988

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	for(int i=1900;i<2014;i++)
	{
		stringstream ss;
		string s;
		ss<<i;
		ss>>s;
		int age=s[0]+s[1]+s[2]+s[3]-4*'0';
		if(age==2014-i)
		{
			cout<<i<<' '<<age<<endl;
		}
	}
	return 0;
}
