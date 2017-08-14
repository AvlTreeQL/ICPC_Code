#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=10,a=1,b,c,d,e=1;
	scanf("%d",&n);
	if(n%7==0)
	{
		printf("%d/n",n*n);
	}
	else
	{
		while(n/i!=0)
		{
			i=i*10;
			a=a+1;
		}
		while(b==7||e<=a)
		{
			c=pow(10,e);
			d=pow(10,e-1);
			b=n%c/d;
			e=e+1;
			if(b==7) 
			{
				printf("%d\n",n*n);
				break;
			}
		}
	
	}
	return 0;
}
/*问题描述
一个正整数,如果它能被7整除,或者它的十进制表示中某位数字为7,则称其为与7相关的数。现求所有小于等于n(n<100)的与7无关的正整数的平方和.
输入形式
输入为一行,正整数n,(n<100)。
输出形式
输出小于等于n的与7无关的正整数的平方和
样例输入
21
样例输出
2336  */