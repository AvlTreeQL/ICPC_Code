#include <stdio.h>
#include <stdlib.h>
struct time
{
	int y;
	int m;
	int d;
}a;
int main()
{
	int i,sum=0,t[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d%d%d",&a.y,&a.m,&a.d);
	if(a.y%4==0&&a.y%100!=0||a.y%400==0) t[1]=29;
	for(i=0;i<a.m-1;i++)
	{
		sum+=t[i];
	}
	sum+=a.d;
	printf("%d",sum);
	return 0;
}


/*	
问题描述
定义一个结构体变量（包括年、月、日）。输入某年某月某日，计算该日在本年中是第几天，注意闰年问题。
输入形式
输入一行，包括三个正整数，表示某年某月某日。
输出形式
输出一行，输出这一天是这一年的第几天。
样例输入
2013 3 5
样例输出
64
*/