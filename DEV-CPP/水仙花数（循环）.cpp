#include<stdio.h>
#include<math.h>
int main()
{
	int a=100;
	int r(int i);
	while(a<=999)
	{
		if(r(a)==1)
		printf("%d ",a);
		a=a+1;
	}
	return 0;
}

int r(int i)
{
	int a=1,b,c,d,e=0,sum=0;
	while(a<=3)
	{
		b=pow(10,a);
		c=pow(10,a-1);
		a=a+1;
		d=i%b/c;
		sum=sum+d*d*d;
	}
	if(sum==i) e=1;

	return e;
}
/*问题描述
输出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。
输入形式
无。
输出形式
输出所有的水仙花数，各个数之间以空格分隔。
样例输入
无
样例输出
      153 370 371 407
*/