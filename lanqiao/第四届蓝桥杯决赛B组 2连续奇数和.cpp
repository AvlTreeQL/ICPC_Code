 /*
 
标题：连续奇数和

    小明看到一本书上写着：任何数字的立方都可以表示为连续奇数的和。

    比如：
 
2^3 = 8 = 3 + 5
3^3 = 27 = 7 + 9 + 11
4^3 = 64 = 1 + 3 + ... + 15

    虽然他没有想出怎么证明，但他想通过计算机进行验证。

    请你帮助小明写出 111 的立方之连续奇数和表示法的起始数字。如果有多个表示方案，选择起始数字小的方案。        

    请严格按照要求，通过浏览器提交答案。
    注意：只提交一个整数，不要写其它附加内容，比如：说明性的文字。


answer: 371
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n=111*111*111;
	for(long long i=1;1;i++)
	{
		long long sum=0;
		for(long long j=i;sum<n;j+=2)
		{
			sum+=j;
		}
		if(sum==n)
		{
			cout<<sum<<endl;
			sum=0;
			for(long long j=i;sum<n;j+=2)
			{
				sum+=j;
				cout<<j<<' ';
			}
			cout<<endl;
			system("pause");
		}
	}
	return 0;
} 
