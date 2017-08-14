/*

标题：神奇6位数

  有一个6位的正整数，它有个很神奇的性质：

  分别用2 3 4 5 6去乘它，得到的仍然是6位数，并且乘积中所包含的数字与这个6位数完全一样！只不过是它们的顺序重新排列了而已。

  请计算出这个6位数。

  这是一个整数，请通过浏览器提交答案，不要填写任何多余的内容（比如说明性的文字）
  answer: 142857
  */
#include<bits/stdc++.h>
using namespace std;
string check(int x)
{
	string s;
	stringstream ss;
	ss<<x;
	ss>>s;
	sort(s.begin(),s.end());
	return s;
}
int main()
{
	for(int i=100000;i<1000000;i++)
	{
		string t=check(i);
		if(2*i>=1000000||t!=check(2*i))
			continue;
		if(3*i>=1000000||t!=check(3*i))
			continue;
		if(4*i>=1000000||t!=check(4*i))
			continue;
		if(5*i>=1000000||t!=check(5*i))
			continue;
		if(6*i>=1000000||t!=check(6*i))
			continue;
		cout<<i<<endl;
		system("pause"); 
	}
	return 0;
}
