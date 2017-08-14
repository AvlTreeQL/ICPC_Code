#include<stdio.h>
int main()
{
	int n,a,max,min,sum;
	float ave,b;
	scanf("%d",&n);
	scanf("%d",&a);
	max=a;
	min=a;
	sum=a;
	for(int i=2;i<=n;i++)//这里 i<=n 不是 i<=5，错了这一个地方，竟然一个测试点都没过
	{
		scanf("%d",&a);
		sum=sum+a;
		if(a>max)
		{
			max=a;
		}
		else
		{
			if(a<min)
			min=a;
		}
	}
	b=sum;
	ave=b/n;
	
	printf("%d %d %.2f %d",max,min,ave,sum);
	return 0;
}
/*问题描述
有n（n不大于20）个整数存放在一个数组中，请编写程序求出数组中的所有元素最大值、最小值、平均值（保留小数点两位）及各元素之和。（各个数之间以空格分隔）。
输入形式
输入两行。
第一行输入整数n；
第二行输入n个数，各个数之间的空格分隔；
输出形式
输出一行，数组中的所有元素最大值、最小值、平均值及各元素之和。
样例输入
5
1 3 5 7 9
样例输出
9 1 5.00 25  */