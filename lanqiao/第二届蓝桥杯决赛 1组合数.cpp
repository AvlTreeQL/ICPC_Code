/*


从4个人中选2个人参加活动，一共有6种选法。

从n个人中选m个人参加活动，一共有多少种选法？下面的函数实现了这个功能。

请仔细分析代码，填写缺少的部分(下划线部分)。

注意：请把填空的答案（仅填空处的答案，不包括题面）存入考生文件夹下对应题号的“解答.txt”中即可。
直接写在题面中不能得分。


// n 个元素中任取 m 个元素，有多少种取法
int f(int n, int m)
{
	if(m>n) return 0;
	if(m==0) _______________;

	return f(n-1,m-1) + _____________;
}

*/
#include<bits/stdc++.h>
using namespace std;
int f(int n, int m)
{
	if(m>n) return 0;
	if(m==0) return 1;

	return f(n-1,m-1) + f(n-1,m);
}
int main()
{
	cout<<f(4,2); 
	return 0;
}

