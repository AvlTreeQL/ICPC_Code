/*
标题：等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。

*/
#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	if(x==2||x==3)
		return true;
	if(x%6!=1&&x%6!=5)
		return false;
	for(int i=5;i*i<=x;i+=6)
	{
		if(x%i==0||x%(i+2)==0)
			return false;
	} 
	return true;
}
int main()
{
	int i,j,k;
	for(i=3;1;i++)
	{
		for(j=2;j<100000;j++)
		{
			int flag=0;
			for(k=j;k<j+i*10;k+=i)
			{
				if(!check(k))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<i<<endl;
				for(int p=0;p<10;p++)
				{
					cout<<j+p*i<<' ';
				}
				system("pause");
			}
		}
	}
	return 0;
}
