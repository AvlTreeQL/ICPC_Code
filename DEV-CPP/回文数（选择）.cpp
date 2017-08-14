#include<stdio.h>
int main()
{
	int i,a,b,c,d,e;
	scanf("%d",&i);
	a=i/10000;
	b=i%10000/1000;
	c=i%1000/100;
	d=i%100/10;
	e=i%10;
	if(a==e && b==d) 
	{
		printf("YES\n");
	}
	else 
	{
		if(a==0||a>=10)
		{
			printf("error\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
	
/*问题描述
对于一个5位数，判断它是不是回文数。例如12321是回文数，个位与万位相同，十位与千位相同。
输入形式
输入一行，包括一个5位数。
输出形式
输出一行，若这个5位数是回文数，则输出YES，否则输出NO。若输入不是5位数，则输出error。
样例输入
12321
样例输出
       YES

 */